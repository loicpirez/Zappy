//
// Player.hh for zappy in /home/vallae_h/Epitech/TEK2/CPP/PSU_2016_zappy/include
// 
// Made by vallae_h
// Login   <vallae_h@epitech.net>
// 
// Started on  Sat Jul  1 17:47:56 2017 vallae_h
// Last update Sat Jul  1 19:25:58 2017 vallae_h
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

#include	"protocol.hh"

class		Player : public protocol
{
public:

  unsigned int _life;
  unsigned int _xSize;
  unsigned int _ySize;
  unsigned int	client_nb;
  std::string	team;
  
  Player();
  ~Player();
  
};

#endif /* ! PLAYER_HH_ */
