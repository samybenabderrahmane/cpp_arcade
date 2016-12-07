#ifndef DISPLAYNCURSES_HH_
# define DISPLAYNCURSES_HH_

#include <curses.h>
#include <ncurses.h>
#include "Display.hpp"
#include "Menu.hh"

class	NCurses : public IDisplay
{
  enum Status	*state;
  int		*keyPressed;
  int		*gameSelection;
  char		**map;

public:
  NCurses(enum Status *, int *, int *, char **map);
  virtual ~NCurses();
  void	*display();
  void	displayMenu();
  void	displayGame(WINDOW *);
  void	*keyEvent(void *);
};

#endif
