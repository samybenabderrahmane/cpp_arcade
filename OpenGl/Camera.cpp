#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>
#include "sdlglutils.h"
#include "DisplayOpenGL.hh"

Camera::Camera()
{
  this->angle = 0;
  this->angle2 = 0.04;
  this->y = 24;
  this->y2 = 0.2;
}

double  Camera::getX()
{
  return (10 * cos(angle));
}

double  Camera::getY()
{
  return (y);
}

double  Camera::getZ()
{
  return (10 * sin(angle));
}

void    Camera::moveRight()
{
  angle += angle2;
}

void    Camera::moveLeft()
{
  angle -= angle2;
}
void    Camera::moveUp()
{
  y += y2;
}
void    Camera::moveDown()
{
  if (y > y2)
    y -= y2;
}
