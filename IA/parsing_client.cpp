//
// parsing_client.cpp for zappy in /home/vallae_h/Epitech/TEK2/CPP/PSU_2016_zappy/IA
// 
// Made by vallae_h
// Login   <vallae_h@epitech.net>
// 
// Started on  Wed Jun 28 20:18:45 2017 vallae_h
// Last update Wed Jun 28 21:20:04 2017 vallae_h
//

#include	<string.h>
#include	<stdlib.h>
#include	"../include/Client.hh"

void		check_infos(Client *client_infos)
{
  if (client_infos->getPort() == -1 || client_infos->getTeam() == "")
    print_error("Port or TeamName", 1);
  if (client_infos->getMachine() == "")
    client_infos->setMachine("localhost");
}

void		parsing_client(int ac, char **av, Client *client_infos)
{
  if (ac % 2 == 0 || ac < 5 || ac > 7)
    print_error("Wrong number of arguments", 1);
  for (int i = 1; i < ac; i++)
    {
      if (strcmp(av[i], "-p") == 0)
	{
	  i++;
	  if (is_number(av[i]) == 0 && client_infos->getPort() == -1)
	    client_infos->setPort(atoi(av[i]));
	  else
	    print_error("multiple definition of Port or Port have to be a number", 1);
	}
      else if (strcmp(av[i], "-n") == 0)
	{
	  i++;
	  if (client_infos->getTeam() == "")
	    client_infos->setTeam(av[i]);
	  else
	    print_error("multiple definition of Team name", 1);
	}
      else if (strcmp(av[i], "-h") == 0 && ac == 7)
	{
	  i++;
	  if (client_infos->getMachine() == "")
	    client_infos->setMachine(av[i]);
	  else
	    print_error("multiple definition of Machine", 1);
	}
      else
	print_error("Unknown argument !", 1);
    }
  check_infos(client_infos);
}
