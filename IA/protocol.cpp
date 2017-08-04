//
// Protocol.cpp for zappy in /home/vallae_h/Epitech/TEK2/CPP/PSU_2016_zappy/IA
// 
// Made by vallae_h
// Login   <vallae_h@epitech.net>
// 
// Started on  Fri Jun 30 14:24:57 2017 vallae_h
// Last update Sun Jul  2 00:25:01 2017 vallae_h
//

#include <array>
#include <cstring>
#include <iostream>
#include <memory>
#include <stdexcept>
#include "../include/socket.hh"
#include "../include/protocol.hh"

/*

char		*Protocol::Look(Socket *so) //modifier plus tard
{
  char		*buff;

  if (!(buff = (char *)malloc(sizeof(char) * 4000)))
    print_error("Malloc failed", 1);
  write(1, "--> Look\n", 9);
  so->write("Look\n", 5);
  so->read(buff, 4096);
  return (buff);
}

char		*Protocol::Inventory(Socket *so) // modifier plus tard
{
  char		*buff;

  if (!(buff = (char *)malloc(sizeof(char) * 4000)))
    print_error("Malloc failed", 1);
  write(1, "--> Inventory\n", 14);
  so->write("Inventory\n", 10);
  so->read(buff, 4096);
  return (buff);
}
*/

static inline std::string read(Socket& sock, std::size_t n)
{
    auto data = std::make_unique<char[]>(n);
    auto rawp = data.get();

    size_t len { sock.read(rawp, n) };

    return std::string (rawp, len);
}

static inline void write(Socket& sock, const char* s)
{
    std::size_t n { std::strlen(s) };

    if (sock.write(s, n) != n)
    {
        throw std::runtime_error { "" };
    }
}

static void write(Socket& sock, const std::string& s)
{
    if (sock.write(s.data(), s.size()) != s.size())
    {
        throw std::runtime_error { "" };
    }
}

Protocol::Protocol(Socket& sock, const char* name)
    : sock_ { sock }, name_ { name }
{
    if (read(sock, 4096) != "WELCOME\n")
    {
        throw std::runtime_error { "" };
    }

    write(sock, std::string(name) + "\n");

    std::string packet { read(sock, 4096) };
    num_ = std::stoi(packet);

    std::size_t part0;

    num_ = std::stoi(packet, &part0);

    std::size_t part1;

    /*int w = std::stoi(packet.c_str() + part0, &part1);

    if (w < 0)
    {
        throw std::out_of_range { "stoi" };
    }

    std::size_t part2;

    int h = std::stoi(packet.c_str() + part0 + part1, &part2);

    if (h < 0)
    {
        throw std::out_of_range { "stoi" };
    }

    if (packet[part0 + part1 + part2] != '\n')
    {
        throw std::runtime_error { "Bad format" };
    }

    w_ = w;
    h_ = h;*/
}

void Protocol::fork()
{
    write(sock_, "Fork\n");

    if (read(sock_, 4096) != "ok\n")
    {
        throw std::runtime_error ("Wrong return for Fork");
    }
}

int Protocol::connect_nbr()
{
    write(sock_, "Connect_nbr\n");

    int n { std::stoi(read(sock_, 4096)) };

    if (n < 0)
    {
        throw std::out_of_range { "stoi" };
    }

    return n;
}

bool Protocol::eject()
{
    std::cout << "--> Eject" << std::endl;
    write(sock_, "Eject\n");
    std::string s { read(sock_, 4096) };

    if (s == "ok\n")
    {
        return true;
    }
    else if (s == "ko\n")
    {
        return false;
    }
    else
    {
        throw std::runtime_error ("Wrong return for Eject");
    }
}

void Protocol::forward()
{
    write(sock_, "Forward\n");

    if (read(sock_, 4096) != "ok")
    {
        throw std::runtime_error ("Wrong return for Forward");
    }
}

void Protocol::left()
{
    write(sock_, "Left\n");

    if (read(sock_, 4096) != "ok\n")
    {
        throw std::runtime_error ("Wrong return for Left");
    }
}

void Protocol::right()
{
    write(sock_, "Right\n");

    if (read(sock_, 4096) != "ok\n")
    {
        throw std::runtime_error ("Wrong return for Right");
    }
}
