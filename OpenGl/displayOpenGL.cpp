#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "sdlglutils.h"
#include "DisplayOpenGL.hh"
# define UNUSED __attribute__((unused))

GLfloat BLANC[] = {1, 1, 1};
GLfloat ROUGE[] = {1, 0, 0};
GLfloat NOIR[] = {0, 0, 0};
GLfloat GRIS[] = {0.5, 0.5, 0.5};
GLfloat GRIS_FONCE[] = {0.75, 0.75, 0.75};

float spot_a = 12;
float spot_b = 8;
float spot_c = 14;
float a = 10;
float b = -3;
float c = 10;
int d = 0;
float POS_Y = 0;
int bool_food = 0;

OpenGL::OpenGL(enum Status *s, int *k, int *g, char **new_map)
{
  state = s;
  keyPressed = k;
  gameSelection = g;
  map = new_map;

  color[ArcadeTile::DEFAULT][0] = 1;
  color[ArcadeTile::DEFAULT][1] = 1;
  color[ArcadeTile::DEFAULT][2] = 1;

  color[ArcadeTile::WALL][0] = 0.07843137;
  color[ArcadeTile::WALL][1] = 0.07843137;
  color[ArcadeTile::WALL][2] = 0.549019;

  color[ArcadeTile::FOOD][0] = 1;
  color[ArcadeTile::FOOD][1] = 0.25;
  color[ArcadeTile::FOOD][2] = 0;

  color[ArcadeTile::FOOD1][0] = 1;
  color[ArcadeTile::FOOD1][1] = 1;
  color[ArcadeTile::FOOD1][2] = 1;

  color[ArcadeTile::FOOD2][0] = 1;
  color[ArcadeTile::FOOD2][1] = 1;
  color[ArcadeTile::FOOD2][2] = 1;

  color[ArcadeTile::FOOD3][0] = 1;
  color[ArcadeTile::FOOD3][1] = 1;
  color[ArcadeTile::FOOD3][2] = 1;

  color[ArcadeTile::FOOD4][0] = 1;
  color[ArcadeTile::FOOD4][1] = 1;
  color[ArcadeTile::FOOD4][2] = 1;

  color[ArcadeTile::FOOD5][0] = 1;
  color[ArcadeTile::FOOD5][1] = 1;
  color[ArcadeTile::FOOD5][2] = 1;


  color[ArcadeTile::POWERUP][0] = 1;
  color[ArcadeTile::POWERUP][1] = 1;
  color[ArcadeTile::POWERUP][2] = 1;

  color[ArcadeTile::POWERUP1][0] = 1;
  color[ArcadeTile::POWERUP1][1] = 1;

  color[ArcadeTile::POWERUP2][0] = 1;
  color[ArcadeTile::POWERUP1][2] = 1;
  color[ArcadeTile::POWERUP2][1] = 1;
  color[ArcadeTile::POWERUP2][2] = 1;

  color[ArcadeTile::POWERUP3][0] = 1;
  color[ArcadeTile::POWERUP3][1] = 1;
  color[ArcadeTile::POWERUP3][2] = 1;


  color[ArcadeTile::POWERUP4][0] = 1;
  color[ArcadeTile::POWERUP4][1] = 1;
  color[ArcadeTile::POWERUP4][2] = 1;

  color[ArcadeTile::POWERUP5][0] = 1;
  color[ArcadeTile::POWERUP5][1] = 1;
  color[ArcadeTile::POWERUP5][2] = 1;


  color[ArcadeTile::ENEMY][0] = 1;
  color[ArcadeTile::ENEMY][1] = 1;
  color[ArcadeTile::ENEMY][2] = 1;

  color[ArcadeTile::ENEMY_SHOT][0] = 1;
  color[ArcadeTile::ENEMY_SHOT][1] = 1;
  color[ArcadeTile::ENEMY_SHOT][2] = 1;

  color[ArcadeTile::ENEMY1][0] = 1;
  color[ArcadeTile::ENEMY1][1] = 0.59607843;
  color[ArcadeTile::ENEMY1][2] = 0.6;

  color[ArcadeTile::ENEMY_SHOT1][0] = 1;
  color[ArcadeTile::ENEMY_SHOT1][1] = 1;
  color[ArcadeTile::ENEMY_SHOT1][2] = 1;

  color[ArcadeTile::ENEMY2][0] = 0.4;
  color[ArcadeTile::ENEMY2][1] = 1;
  color[ArcadeTile::ENEMY2][2] = 0.9999999;

  color[ArcadeTile::ENEMY_SHOT2][0] = 1;
  color[ArcadeTile::ENEMY_SHOT2][1] = 1;
  color[ArcadeTile::ENEMY_SHOT2][2] = 1;

  color[ArcadeTile::ENEMY3][0] = 0.98039216;
  color[ArcadeTile::ENEMY3][1] = 0.61176471;
  color[ArcadeTile::ENEMY3][2] = 0;

  color[ArcadeTile::ENEMY_SHOT3][0] = 1;
  color[ArcadeTile::ENEMY_SHOT3][1] = 1;
  color[ArcadeTile::ENEMY_SHOT3][2] = 1;

  color[ArcadeTile::ENEMY4][0] = 0.93725490;
  color[ArcadeTile::ENEMY4][1] = 0.02745098;
  color[ArcadeTile::ENEMY4][2] = 0.02745098;

  color[ArcadeTile::ENEMY_SHOT4][0] = 1;
  color[ArcadeTile::ENEMY_SHOT4][1] = 1;
  color[ArcadeTile::ENEMY_SHOT4][2] = 1;

  color[ArcadeTile::ENEMY5][0] = 1;
  color[ArcadeTile::ENEMY5][1] = 1;
  color[ArcadeTile::ENEMY5][2] = 1;

  color[ArcadeTile::ENEMY_SHOT5][0] = 1;
  color[ArcadeTile::ENEMY_SHOT5][1] = 1;
  color[ArcadeTile::ENEMY_SHOT5][2] = 1;

  color[ArcadeTile::PLAYER][0] = 1;
  color[ArcadeTile::PLAYER][1] = 0.933333;
  color[ArcadeTile::PLAYER][2] = 0;

  color[ArcadeTile::PLAYER_SHOT][0] = 1;
  color[ArcadeTile::PLAYER_SHOT][1] = 1;
  color[ArcadeTile::PLAYER_SHOT][2] = 1;

  color[ArcadeTile::PLAYER_TAIL][0] = 0.33333333;
  color[ArcadeTile::PLAYER_TAIL][1] = 0.14509804;
  color[ArcadeTile::PLAYER_TAIL][2] = 0.50980392 ;

  color[ArcadeTile::PLAYER_BODY][0] = 0.33333333;
  color[ArcadeTile::PLAYER_BODY][1] = 0.14509804;
  color[ArcadeTile::PLAYER_BODY][2] = 0.50980392;

  color[ArcadeTile::PLAYER_HEAD][0] = 0.99215686;
  color[ArcadeTile::PLAYER_HEAD][1] = 0.72549020;
  color[ArcadeTile::PLAYER_HEAD][2] = 0.15294118;

  color[ArcadeTile::LAST][0] = 1;
  color[ArcadeTile::LAST][1] = 1;
  color[ArcadeTile::LAST][2] = 1;
}


OpenGL::~OpenGL() {}



void	*OpenGL::display()
{
  SDL_Event event;

  main_opengl(0, NULL);
  SDL_Init(SDL_INIT_VIDEO);
  atexit(SDL_Quit);
  SDL_WM_SetCaption("ARCADE ", NULL);
  SDL_SetVideoMode(WIDTH * 30, HEIGHT * 30, 32, SDL_OPENGL);
  glMatrixMode( GL_PROJECTION );
  //  glLoadIdentity();
  gluPerspective(70,(double)600/600,1,600);
  init_light();

  while (*keyPressed != ArcadeKey::ESCAPE)
    {

      glClear( GL_COLOR_BUFFER_BIT );
      while (SDL_PollEvent(&event))
  	{
  	if (event.key.keysym.sym == SDLK_DOWN)
  	  {
  	    *keyPressed = ArcadeKey::DOWN;
  	  }
  	else if (event.key.keysym.sym == SDLK_UP)
  	  {
  	    *keyPressed = ArcadeKey::UP;
  	  }
  	else if (event.key.keysym.sym == SDLK_LEFT)
  	  {
  	    *keyPressed = ArcadeKey::LEFT;
  	  }
  	else if (event.key.keysym.sym == SDLK_RIGHT)
  	  {
  	    *keyPressed = ArcadeKey::RIGHT;
  	  }
  	else if (event.key.keysym.sym == SDLK_ESCAPE)
  	  {
  	    *keyPressed = ArcadeKey::ESCAPE;
  	  }
  	else if (event.key.keysym.sym == SDLK_RETURN)
  	  {
  	    *keyPressed = ArcadeKey::RETURN;
  	  }
  	else if (event.key.keysym.sym == SDLK_2)
  	  {
  	    *keyPressed = ArcadeKey::NUM2;
  	  }
  	else if (event.key.keysym.sym == SDLK_3)
  	  {
  	    *keyPressed = ArcadeKey::NUM3;
  	  }
  	else if (event.key.keysym.sym == SDLK_4)
  	  {
  	    *keyPressed = ArcadeKey::NUM4;
  	  }
  	else if (event.key.keysym.sym == SDLK_5)
  	  {
  	    *keyPressed = ArcadeKey::NUM5;
  	  }
  	else if (event.key.keysym.sym == SDLK_8)
  	  {
  	    *keyPressed = ArcadeKey::NUM8;
  	  }
  	else if (event.key.keysym.sym == SDLK_9)
  	  {
  	    *keyPressed = ArcadeKey::NUM9;
  	  }
  	else if (event.key.keysym.sym == SDLK_z)
  	  {
	    cam.moveUp();
	  }
  	else if (event.key.keysym.sym == SDLK_s)
  	  {
	    cam.moveDown();
	  }
  	else if (event.key.keysym.sym == SDLK_a)
  	  {
	    cam.moveLeft();
	  }
  	else if (event.key.keysym.sym == SDLK_e)
  	  {
	    cam.moveRight();
	  }


	else if (event.key.keysym.sym == SDLK_w)
  	  {
	    a--;
	  }
	else if (event.key.keysym.sym == SDLK_x)
  	  {
	    a++;
	  }
	else if (event.key.keysym.sym == SDLK_c)
  	  {
	    b = b - 2;
	  }
	else if (event.key.keysym.sym == SDLK_v)
  	  {
	    b = b + 2;
	  }
	else if (event.key.keysym.sym == SDLK_b)
  	  {
	    c--;
	  }
	else if (event.key.keysym.sym == SDLK_n)
  	  {
	    c++;
	  }
	else if (event.key.keysym.sym == SDLK_l)
  	  {
	    d--;
	  }
	else if (event.key.keysym.sym == SDLK_m)
  	  {
	    d++;
	  }
	}
bool_food = 0;
bool_food = 1;
      if (*state == 0)
  	{
	  displayMenu();
	}
      else
  	{
          displayGame();
  	}
      glFlush();
      SDL_GL_SwapBuffers();
    }
exit (0);
  return (NULL);
}

void	OpenGL::displayMenu()
{
  glDisable(GL_DEPTH_TEST);
  glMatrixMode( GL_PROJECTION );
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0,1000,0,1000);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  my_putstr_opengl(40, 950, *gameSelection == 0 ? "> Snake" : "  Snake", GLUT_BITMAP_TIMES_ROMAN_24);
  my_putstr_opengl(40, 850, *gameSelection == 1 ? "> Pacman" : "  Pacman", GLUT_BITMAP_TIMES_ROMAN_24);

  glMatrixMode( GL_PROJECTION );
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
  glEnable (GL_LIGHTING);
  glEnable (GL_DEPTH_TEST);
}

void	OpenGL::displayGame()
{
  glMatrixMode( GL_MODELVIEW );
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();


  for (int x = 0, y = 0; x < WIDTH; ++x)
    {
      for (y = 0; y < HEIGHT; ++y)
  	{
  	  if (map[y][x] == ArcadeTile::PLAYER_HEAD ||
  	      map[y][x] == ArcadeTile::PLAYER)
  	    gluLookAt(cam.getX(), cam.getY(), 30, a, b, y, 0.0, 1.0, 0.0);
  	}
    }
  GLfloat light_position[] = {spot_a, spot_b, spot_c, 1};
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glMatrixMode( GL_MODELVIEW );

  drawMap();

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, NOIR);
  drawSnake();
  glFlush();
  SDL_GL_SwapBuffers();
}

void	OpenGL::init_light()
{
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);
}

void	OpenGL::drawMap()
{

  glPushMatrix();
  if (*gameSelection == 0)
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, GRIS);
  else
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, NOIR);
  glBegin(GL_QUADS);
  glNormal3d(0, 1, 0);
  for (int z = 0;  z< HEIGHT - 1; z++)
    {
      for (int x = 0; x < WIDTH - 1; x++)
  	{
	  glPushMatrix();
	  glTexCoord2d(0,x);
	  glVertex3d(x, 0, z);
	  glTexCoord2d(0,0);
	  glVertex3d(x+1, 0, z);
	  glTexCoord2d(x,0);
	  glVertex3d(x+1, 0, z+1);
	  glTexCoord2d(x,x);
	  glVertex3d(x, 0, z+1);
	  glPopMatrix();
    	}
    }
    glEnd();
  glPopMatrix();
  glFlush();
}

void	OpenGL::drawSnake()
{
  for (int x = 0, y  = 0; x < WIDTH; ++x)
    {
      for (y = 0; y < WIDTH; ++y)
  	{
	  for (int i = 0, j = ArcadeTile::LAST; i < j; ++i)
	    if (map[y][x] == i && i != ArcadeTile::DEFAULT)
	      {
		glPushMatrix();
		if (*gameSelection == 0 && map[y][x] == ArcadeTile::WALL)
		  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, BLANC);
		else
		  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color[i]);
		glTranslated(0.5 + x, 0.5, 0.5 + y);
		if (map[y][x] == ArcadeTile::FOOD1)
		  glutSolidSphere(0.2, 30, 30);

		else if (map[y][x] == ArcadeTile::FOOD1 ||
			 map[y][x] == ArcadeTile::FOOD2 ||
			 map[y][x] == ArcadeTile::FOOD3 ||
			 map[y][x] == ArcadeTile::FOOD4)
       {
         glutSolidSphere(0.4, 30, 30);
       }

		else if (map[y][x] == ArcadeTile::PLAYER)
		  glutSolidSphere(0.5, 30, 30);
		else if (map[y][x] == ArcadeTile::PLAYER_HEAD)
		  glutSolidCube(1);

		else if (map[y][x] == ArcadeTile::PLAYER_BODY)
		  glutSolidCube(1);
		else if (map[y][x] == ArcadeTile::PLAYER_TAIL)
		  glutSolidCube(1);


		else if (map[y][x] == ArcadeTile::FOOD)
		  glutSolidSphere(0.5, 90, 90);
		else if (map[y][x] == ArcadeTile::ENEMY1 ||
			 map[y][x] == ArcadeTile::ENEMY2 ||
			 map[y][x] == ArcadeTile::ENEMY3 ||
			 map[y][x] == ArcadeTile::ENEMY4)
		  glutSolidSphere(0.5, 30, 30);


		else
		  glutSolidCube(1.0);
		glPopMatrix();
		glFlush();
	      }
    	}
    }
}


int     OpenGL::my_putstr_opengl(int x, int y, const char *str, void *font)
{
  int   i;

  glColor3f(5.5, 5.5, 5.5);
  glRasterPos2i(x, y);
  i = 0;
  while (str[i] != '\0')
    {
      glutBitmapCharacter(font, str[i]);
      i = i + 1;
    }
  return (0);
}

int	OpenGL::main_opengl(int argc, char* argv[])
{
  glutInit(&argc, argv);
  return 0;
}

extern "C" IDisplay	*newIDisplay(enum Status *s, int *k, int *g, char **new_map)
{
  return (new OpenGL(s, k, g, new_map));
}
