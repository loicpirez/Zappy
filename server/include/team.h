/*
** team.h for team in /home/skanx/rendu/PSU_2016_zappy/server/include
** 
** Made by Lucas Michalski
** Login   <lucas.michalski@epitech.eu>
** 
** Started on  Thu Jun 29 16:18:27 2017 Lucas Michalski
** Last update Thu Jun 29 16:20:18 2017 Lucas Michalski
*/

#ifndef		TEAM_H_
# define	TEAM_H_

typedef struct	s_team
{
  int		current_nb_client;
  char		*name;
  struct s_team	*next;
}		t_team;

#endif		/* !TEAM_H_ */
