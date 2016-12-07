#ifndef MENU_HH_
# define MENU_HH_

#define NB_GAMES	2
#define HEIGHT		24
#define WIDTH		24

#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include "ArcadeKey.hh"
#include "ArcadeTiles.hh"

enum Status
  {
    MENU,
    GAME
  };

enum graphic_lib
  {
    LDEFAULT,
    LNCURSES,
    LSFML,
    LOPENGL,
    LLAST
  };

class	Menu
{
  enum Status	*state;

public:
  int	*keyPressed;
  int	gameSelection;

  Menu(int *, enum Status *);
  ~Menu();
  void	setPressed(int *);
  int	getSelection() const;
  void	keyAction();
  void	menuLoop();
};

#endif
