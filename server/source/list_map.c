/*
** list_map.c for list_map in /home/skanx/rendu/PSU_2016_zappy/server/source
**
** Made by Lucas Michalski
** Login   <lucas.michalski@epitech.eu>
**
** Started on  Fri Jun 30 18:48:36 2017 Lucas Michalski
** Last update Sun Jul  2 20:06:49 2017 Lucas Michalski
*/

#include	"my_server.h"
#include	"map.h"

t_list_p	*remove_player_from_map(t_list_p *players, t_list *p)
{
  t_list_p	*curs;
  t_list_p	*curs2;

  if (players->p == p)
    {
      if (players->next == NULL)
	{
	  free(players);
	  return (NULL);
	}
      curs = players;
      players = players->next;
      free(curs);
      return (players);
    }
  curs = players;
  while (curs->next->p != p)
    curs = curs->next;
  curs2 = curs->next->next;
  free(curs->next);
  curs->next = curs2;
  return (players);
}

t_list_p	*add_player_to_map(t_list_p *players, t_list *p)
{
  t_list_p	*curs;
  t_list_p	*new;

  if (players == NULL)
    {
      if ((players = malloc(sizeof(t_list_p))) == NULL)
	throw_error("Malloc failed");
      players->next = NULL;
      players->p = p;
      return (players);
    }
  curs = players;
  while (curs != NULL)
    curs = curs->next;
  if ((new = malloc(sizeof(t_list_p))) == NULL)
    throw_error("Malloc failed");
  new->next = NULL;
  new->p = p;
  curs->next = new;
  return (players);
}
