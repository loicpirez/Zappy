#include <cerrno>
#include <sys/socket.h>
#include <system_error>
#include <unistd.h>
#include <utility>
#include <iostream>
#include "../include/socket.hh"

AddrIter::AddrIter(const ::addrinfo* init): x { init }
{
}

AddrIter& AddrIter::operator++()
{
    x = x->ai_next;
    return *this;
}

AddrIter AddrIter::operator++(int)
{
    AddrIter tmp(*this);
    operator++();
    return tmp;
}

AddrIter::reference AddrIter::operator*() const
{
    return *x;
}

bool operator==(const AddrIter& lhs, const AddrIter& rhs)
{
    return lhs.x == rhs.x;
}

bool operator!=(const AddrIter& lhs, const AddrIter& rhs)
{
    return !(lhs == rhs);
}

AddrInfo::AddrInfo(const std::string& machine, int port,
                   const ::addrinfo* hints)
{
    int status { ::getaddrinfo(machine.c_str(),
                               std::to_string(port).c_str(),
                               hints,
                               &info) };

    if (status != 0)
    {
        throw std::runtime_error { ::gai_strerror(status) };
    }
}

AddrInfo::~AddrInfo()
{
    if (info != nullptr)
    {
        ::freeaddrinfo(info);
    }
}

AddrInfo::AddrInfo(AddrInfo&& other)
    : info { std::exchange(other.info, nullptr) }
{
}

AddrInfo& AddrInfo::operator=(AddrInfo&& other)
{
    if (this == &other)
    {
        return *this;
    }

    if (info != nullptr)
    {
        ::freeaddrinfo(info);
    }

    info = std::exchange(other.info, nullptr);
    return *this;
}

AddrIter AddrInfo::begin() const
{
    return { info };
}

AddrIter AddrInfo::end() const
{
    return {};
}

Socket::Socket(int domain, int type, int protocol)
    : fd { ::socket(domain, type, protocol) }
{
    if (fd == -1)
    {
        throw std::system_error (errno, std::generic_category());
    }
}

Socket::~Socket()
{
    if (fd != -1)
    {
        static_cast<void> (::close(fd));
    }
}

Socket::Socket(Socket&& other)
    : fd { std::exchange(other.fd, -1) }
{
}

Socket& Socket::operator=(Socket&& other)
{
    if (this == &other)
    {
        return *this;
    }

    if (fd != -1)
    {
        static_cast<void> (::close(fd));
    }

    fd = std::exchange(other.fd, -1);
    return *this;
}

bool Socket::connect(const ::sockaddr* address, ::socklen_t len)
{
    return ::connect(fd, address, len) != -1;
}

std::size_t Socket::read(void* buf, std::size_t n)
{
    ::ssize_t status { ::recv(fd, buf, n, 0) };

    if (status == -1)
    {
        throw std::system_error (errno, std::generic_category());
    }
    return static_cast<std::size_t> (status);
}

std::size_t Socket::write(const void* buf, std::size_t n)
{
    ::ssize_t status { ::send(fd, buf, n, 0) };

    if (status == -1)
    {
        throw std::system_error (errno, std::generic_category());
    }

    return static_cast<std::size_t> (status);
}

Socket connector(const std::string& machine, int port)
{
    ::addrinfo hints {{}, AF_UNSPEC, SOCK_STREAM, {}, {}, {}, {}, {}};
    AddrInfo info (machine, port, &hints);

    for (const auto& x: info)
    {
        Socket sock(x.ai_family, x.ai_socktype, x.ai_protocol);

        if (sock.connect(x.ai_addr, x.ai_addrlen))
        {
            return sock;
        }
    }

    throw std::runtime_error { "Cannot connect to any host" };
}
