#ifndef SNAKE_HH_
# define SNAKE_HH_

#include <vector>
#include "Game.hpp"

class	Snake : public IGame
{
  struct	int2
  {
    int		xy[2];
  };
  enum Status		*state;
  int			*keyPressed;
  char			**map;
  int			size;
  int2			food;
  std::vector<int2>	snake;
  ArcadeKey::key	direction;

public:
  Snake(enum Status*, int*, char**);
  virtual ~Snake();
  void	*play();
  void	*iplay();
  int	up();
  int	down();
  int	left();
  int	right();
  int	move();
  void	newFood();
};

#endif
