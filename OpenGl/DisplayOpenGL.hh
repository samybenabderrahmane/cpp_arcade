#ifndef DISPLAYOPENGL_HH_
# define DISPLAYOPENGL_HH_

#include "Display.hpp"
#include "Menu.hh"

class   Camera
{
  double angle;
  double y;
  double angle2;
  double y2;

public:
  Camera();
  double getX();
  double getY();
  double getZ();
  void moveRight();
  void moveLeft();
  void moveUp();
  void moveDown();
};

class	OpenGL : public IDisplay
{
  enum Status	*state;
  int		*keyPressed;
  int		*gameSelection;
  char		**map;
  SDL_Event event;
  Camera cam;
  int displayListId;

  double radius;
  double maximumHeight;
  double x;
  double y;
  double z;
  int direction;
  GLfloat color[ArcadeTile::LAST][3];

public:
  OpenGL(enum Status *, int *, int *, char **);
  ~OpenGL();
  void	*display();
  void	displayMenu();
  void	displayGame();
  int   my_putstr_opengl(int, int, const char *, void *);
  int	main_opengl(int argc, char* argv[]);
  static void	special3(int, int, int);
  int   init_sdl_values();
  void	init_light();
  void	drawMap();
  void	drawSnake();
};

#endif
