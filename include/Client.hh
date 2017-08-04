//
// ia.hh for zappy in /home/vallae_h/Epitech/TEK2/CPP/PSU_2016_zappy/include
// 
// Made by vallae_h
// Login   <vallae_h@epitech.net>
// 
// Started on  Wed Jun 28 18:14:02 2017 vallae_h
// Last update Sat Jul  1 16:49:36 2017 vallae_h
//

#ifndef		IA_HH_
#define		IA_HH_

#include	<string>
#include	<iostream>

class		Client
{
private:
  int		port;
  std::string	team;
  std::string	machine;
  int		client_nb;
  
public:

  int		socket;
  int		x;
  int		y;

  Client();
  ~Client();

  void		setPort(int);
  void		setTeam(std::string);
  void		setMachine(std::string);

  int		getPort();
  std::string&	getTeam();
  std::string&	getMachine();
};

int		is_number(char *);

void	        parsing_client(int, char **, Client *);
void		print_help();
void		print_error(std::string, int);
void		server_connection(Client *);

#endif
