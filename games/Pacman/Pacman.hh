#ifndef PACMAN_HH_
# define PACMAN_HH_

#include <vector>
#include "Game.hpp"

class	Pacman : public IGame
{
  enum Status		*state;
  int			*keyPressed;
  char			**map;
  int			size;
  int			pac[2];
  int			enemy1[2];
  int			enemy2[2];
  int			enemy3[2];
  int			enemy4[2];
  bool			eat;
  int			gMove;
  ArcadeKey::key	dir1;
  ArcadeKey::key	dir2;
  ArcadeKey::key	dir3;
  ArcadeKey::key	dir4;
  char			old1;
  char			old2;
  char			old3;
  char			old4;

public:
  Pacman(enum Status*, int*, char**);
  virtual ~Pacman();
  void	*play() {return NULL;}
  void	*iplay();
  int	up();
  int	down();
  int	left();
  int	right();
  int	move();
  int	moveGhost();
};

#endif
