#ifndef ARCADE_HH_
# define ARCADE_HH_

#include "Display.hpp"
#include "Game.hpp"

class		Arcade
{
public:
  enum Status	state;
  int		keyPressed;
  pthread_t	display_thr;
  std::string	lib_str;
  std::string	libs[LLAST];
  int		graphicLib;
  Menu		*menu;
  IGame		*igame;
  IDisplay	*idisplay;
  char		**map;

public:
  Arcade(char *str);
  ~Arcade();
  int		mainLoop();
  int		launchGame();
  void		displayInit();
  void		*displayLauncher();
};

#endif
