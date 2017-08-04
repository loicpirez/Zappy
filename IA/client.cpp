//
// AI.cpp for zappy in /home/vallae_h/Epitech/TEK2/CPP/PSU_2016_zappy/IA
// 
// Made by vallae_h
// Login   <vallae_h@epitech.net>
// 
// Started on  Wed Jun 28 19:00:01 2017 vallae_h
// Last update Wed Jun 28 21:11:10 2017 vallae_h
//

#include	"../include/Client.hh"

Client::Client()
{
  this->port = -1;
  this->team = "";
  this->machine = "";
}

Client::~Client(){}

// Set

void		Client::setPort(int port)
{
  this->port = port;
}

void		Client::setTeam(std::string team)
{
  this->team = team;
}

void		Client::setMachine(std::string machine)
{
  this->machine = machine;
}


// Get

int		Client::getPort()
{
  return (this->port);
}

std::string&	Client::getTeam()
{
  return (this->team);
}

std::string&	Client::getMachine()
{
  return (this->machine);
}
