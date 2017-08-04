//
// protocol.hh for zappy in /home/vallae_h/Epitech/TEK2/CPP/PSU_2016_zappy/include
// 
// Made by vallae_h
// Login   <vallae_h@epitech.net>
// 
// Started on  Fri Jun 30 13:17:28 2017 vallae_h
// Last update Fri Jun 30 18:35:57 2017 vallae_h
//

#ifndef		PROTOCOL_H_
#define		PROTOCOL_H_

#include "socket.hh"

class Protocol
{
    Socket& sock_;

    std::string name_;
    int num_;

    unsigned int w_;
    unsigned int h_;

public:

    Protocol(Socket& sock, const char* name);
    ~Protocol() = default;

    char *look();
    char *inventory();

    int connect_nbr();

    void fork();
    bool eject();
    void forward();
    void right();
    void left();
    void broadcast();
    void takeObject();
    void setObject();
    void incantation();
};

#endif
