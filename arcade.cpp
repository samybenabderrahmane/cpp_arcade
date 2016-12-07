#include <dlfcn.h>
#include <string.h>
#include "Arcade.hh"

static void     *display_helper(void *arg)
{
  return (((IDisplay*)arg)->display());
}

static void	*displayLaucherHelper(void *arg)
{
  return (((Arcade*)arg)->displayLauncher());
}

Arcade::Arcade(char *str)
{
  keyPressed = ArcadeKey::DEFAULT;
  state = MENU;
  menu = new Menu(&keyPressed, &state);
  map = new char*[HEIGHT];
  for (int i = HEIGHT, j = 0; j < i; ++j)
    {
      map[j] = new char[WIDTH];
    }
  lib_str = str;
  libs[0] = "";
  libs[1] = "./libncurses.so";
  libs[2] = "./libsfml.so";
  libs[3] = "./libopengl.so";
  graphicLib = LDEFAULT;
  for (int i = LDEFAULT, j = LLAST; i < j; ++i)
    if (lib_str == libs[i])
      graphicLib = i;
}

Arcade::~Arcade()
{
  pthread_join(display_thr, NULL);
}

int	Arcade::mainLoop()
{
  displayInit();
  while(keyPressed != ArcadeKey::ESCAPE)
    {
      menu->menuLoop();
      if (keyPressed != ArcadeKey::ESCAPE)
	launchGame();
      if (keyPressed == ArcadeKey::NUM9)
	{
	  state = MENU;
	  keyPressed = ArcadeKey::DEFAULT;
	}
      else if (keyPressed == ArcadeKey::NUM8)
	{
	  keyPressed = ArcadeKey::DEFAULT;
	  state = GAME;
	}
      else if (keyPressed == ArcadeKey::NUM4)
	{
	  keyPressed = ArcadeKey::DEFAULT;
	  menu->gameSelection = menu->gameSelection == 1 ? 0 : 1;
	  state = GAME;
	}
      else if (keyPressed == ArcadeKey::NUM5)
	{
	  keyPressed = ArcadeKey::DEFAULT;
	  menu->gameSelection = menu->gameSelection == 1 ? 0 : 1;
	  state = GAME;
	}
    }
  return (0);
}

int	Arcade::launchGame()
{
  IGame		*(*newIGame)(enum Status*, int*, char **);
  void		(*deleteIGame)(IGame *);
  void		*handle;
  char *str2;

  handle = dlopen(menu->gameSelection == 0 ? "./libsnake.so" : "./libpacman.so", RTLD_NOW 
		  );
  if ((str2 = dlerror()) != NULL)
    std::cout << str2<< std::endl;
  newIGame = reinterpret_cast<IGame *(*)(enum Status*, int*, char **)>(dlsym(handle, "newIGame"));
  if ((str2 = dlerror()) != NULL)
    std::cout << str2<< std::endl;
  igame = newIGame(&state, &keyPressed, map);
  igame->iplay();
  deleteIGame = reinterpret_cast<void (*)(IGame*)>(dlsym(handle, "deleteIGame"));
  if ((str2 = dlerror()) != NULL)
    std::cout << str2<< std::endl;
  deleteIGame(igame);
  dlclose(handle);
  return (0);
}

void	Arcade::displayInit()
{
  pthread_create(&display_thr, NULL, displayLaucherHelper, this);
}

void	*Arcade::displayLauncher()
{
  IDisplay	*(*newIDisplay)(enum Status*, int*, int*, char **);
  void		*handle;
  char *str2;
  pthread_t thr;

  while (keyPressed != ArcadeKey::ESCAPE)
    {
      handle = dlopen(lib_str.c_str(), RTLD_NOW
		      );
      if ((str2 = dlerror()) != NULL)
	std::cout << str2<< std::endl;
      newIDisplay = reinterpret_cast<IDisplay *(*)(enum Status*, int*, int*, char **)>(dlsym(handle, "newIDisplay"));
      if ((str2 = dlerror()) != NULL)
	std::cout << str2<< std::endl;
      idisplay = newIDisplay(&state, &keyPressed, &menu->gameSelection, map);
      pthread_create(&thr, NULL, display_helper, idisplay);
      pthread_join(thr, NULL);
      if (keyPressed == ArcadeKey::NUM2)
	{
	  if (graphicLib == LNCURSES)
	    graphicLib = LOPENGL;
	  else
	    --graphicLib;
	  keyPressed = ArcadeKey::DEFAULT;
	}
      else if (keyPressed == ArcadeKey::NUM3)
	{
	  if (graphicLib == LOPENGL)
	    graphicLib = LNCURSES;
	  else
	    ++graphicLib;
	  keyPressed = ArcadeKey::DEFAULT;
	}
      if ((str2 = dlerror()) != NULL)
	std::cout << str2<< std::endl;
      dlclose(handle);
      lib_str = libs[graphicLib];
    }
  return (NULL);
}
