#ifndef INCLUDED_SOCKET_HH
#define INCLUDED_SOCKET_HH

#include <netdb.h>

class AddrIter
{
public:

    using difference_type = std::ptrdiff_t;
    using value_type = const ::addrinfo;
    using pointer = value_type*;
    using reference = value_type&;
    using iterator_category = std::forward_iterator_tag;

    AddrIter(pointer init = nullptr);
    ~AddrIter() = default;

    AddrIter(const AddrIter&) = default;
    AddrIter(AddrIter&&) = default;

    AddrIter& operator=(const AddrIter&) = default;
    AddrIter& operator=(AddrIter&&) = default;

    AddrIter& operator++();
    AddrIter operator++(int);

    reference operator*() const;

    friend bool operator==(const AddrIter&, const AddrIter&);
    friend bool operator!=(const AddrIter&, const AddrIter&);

private:

    pointer x;
};

class AddrInfo
{
    ::addrinfo* info;

public:

    AddrInfo(const std::string& machine, int port,
             const ::addrinfo* hints = nullptr);
    ~AddrInfo();

    AddrInfo(const AddrInfo&) = delete;
    AddrInfo(AddrInfo&&);

    AddrInfo& operator=(const AddrInfo&) = delete;
    AddrInfo& operator=(AddrInfo&&);

    AddrIter begin() const;
    AddrIter end() const;
};

class Socket
{
    int fd;

public:

    Socket(int domain, int type, int protocol);
    ~Socket();

    Socket(const Socket&) = delete;
    Socket(Socket&&);

    Socket& operator=(const Socket&) = delete;
    Socket& operator=(Socket&&);

    bool connect(const ::sockaddr* address, ::socklen_t len);
    std::size_t read(void* buf, std::size_t n);
    std::size_t write(const void* buf, std::size_t n);
};

Socket connector(const std::string& machine, int port);

#endif
