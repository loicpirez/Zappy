/*
** teams.c for teams in /home/skanx/rendu/PSU_2016_zappy/server/source
**
** Made by Lucas Michalski
** Login   <lucas.michalski@epitech.eu>
**
** Started on  Thu Jun 29 16:33:27 2017 Lucas Michalski
** Last update Sun Jul  2 02:29:27 2017 Lucas Michalski
*/

#include	"my_server.h"

int		check_team_name(t_server *s, char *name)
{
  t_team	*team;

  team = s->teams;
  while (team != NULL)
    {
      if (strncmp(team->name, name, strlen(team->name)) == 0)
	return (0);
      team = team->next;
    }
  return (-1);
}

void		set_nb_client_to_team(t_server *s)
{
  t_team	*curs;

  curs = s->teams;
  while (curs != NULL)
    {
      curs->current_nb_client = s->number_max;
      curs = curs->next;
    }
}

int		get_remaining_client(t_server *s, char *name)
{
  t_team	*curs;

  curs = s->teams;
  while (curs != NULL)
    {
      if (strcmp(curs->name, name) == 0)
	{
	  curs->current_nb_client -= 1;
	  return (curs->current_nb_client);
	}
      curs = curs->next;
    }
  return (-1);
}

void		malloc_team(t_server *s, char *name)
{
  t_team	*new;
  t_team	*curs;

  if (s->teams == NULL)
    {
      if ((s->teams = malloc(sizeof(t_team))) == NULL)
	throw_error("malloc failed");
      s->teams->name = name;
      s->teams->current_nb_client = s->number_max;
      s->teams->next = NULL;
      return ;
    }
  curs = s->teams;
  while (curs->next != NULL)
    {
      if (strcmp(curs->name, name) == 0)
	throw_error("Two team can't have the same name");
      curs = curs->next;
    }
  if ((new = malloc(sizeof(t_team))) == NULL)
    throw_error("Malloc failed");
  new->name = name;
  new->current_nb_client = s->number_max;
  new->next = NULL;
  curs->next = new;
}
