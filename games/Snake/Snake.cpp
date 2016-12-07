#include <stdlib.h>
#include <iostream>
#include <bitset>
#include <iostream>
#include <ostream>
#include <fstream>
#include "Snake.hh"
#include "Protocol.hpp"

# define write_log(x) std::ofstream("log", std::fstream::app) << x << std::endl

Snake::Snake(enum Status *s, int *k, char **m)
{
  int	xhead = WIDTH / 2 - 2, yhead = HEIGHT / 2;
  int2	pos;
  int	x = 0, y = 0;

  state = s;
  keyPressed = k;
  map = m;
  while (x < WIDTH)
    {
      y = 0;
      while (y < HEIGHT)
	{
	  if (x == 0 || x == WIDTH - 1 || y == 0 || y == HEIGHT - 1)
	    map[y][x] = ArcadeTile::WALL;
	  y = y + 1;
	}
      x = x + 1;
    }
  size = 4;
  *keyPressed = ArcadeKey::LEFT;
  while (xhead < WIDTH / 2 + 2)
    {
      pos.xy[0] = xhead;
      pos.xy[1] = yhead;
      map[yhead][xhead] = xhead == WIDTH / 2 - 2 ? ArcadeTile::PLAYER_HEAD :
	ArcadeTile::PLAYER_BODY;
      snake.push_back(pos);
      xhead += 1;
    }
  newFood();
  write_log("///////////////////////CONSTRUCTOR DU SNAKE/////////////////////////////");
}

Snake::~Snake()
{
  int	x = 0, y = 0;

  *state = MENU;
  while (x < WIDTH)
    {
      y = 0;
      while (y < HEIGHT)
	{
	  map[y][x] = ArcadeTile::DEFAULT;
	  y = y + 1;
	}
      x = x + 1;
    }
}

void	*Snake::iplay()
{
  while (size < ((WIDTH - 1) * (HEIGHT - 1)) && *keyPressed != ArcadeKey::ESCAPE && *keyPressed != ArcadeKey::NUM9 && *keyPressed != ArcadeKey::NUM8 && *keyPressed != ArcadeKey::NUM5 && *keyPressed != ArcadeKey::NUM4)
    {
      if (move() == 1)
      	return (NULL);
      usleep(150000);
    }
  return (NULL);
}

void	Snake::newFood()
{
  write_log("__Snake::newFood()__");
  int	xfood = rand() % WIDTH;
  int	yfood = rand() % HEIGHT;

  while (map[yfood][xfood] != 0)
    {
      xfood = rand() % WIDTH;
      yfood = rand() % HEIGHT;
    }
  map[yfood][xfood] = ArcadeTile::FOOD;
}

int	Snake::up()
{
  int2	pos;

  pos.xy[0] = snake[0].xy[0];
  pos.xy[1] = snake[0].xy[1] - 1;
  if (map[pos.xy[1]][pos.xy[0]] == ArcadeTile::FOOD)
    {
      size += 1;
      newFood();
    }
  else if (map[pos.xy[1]][pos.xy[0]] == ArcadeTile::WALL || map[pos.xy[1]][pos.xy[0]] == ArcadeTile::PLAYER_BODY)
    return (1);
  else
    {
      map[snake[size - 1].xy[1]][snake[size - 1].xy[0]] = ArcadeTile::DEFAULT;
      map[snake[size - 2].xy[1]][snake[size - 2].xy[0]] = ArcadeTile::PLAYER_TAIL;
      snake.pop_back();
    }
  snake.insert(snake.begin(), pos);
  map[snake[0].xy[1]][snake[0].xy[0]] = ArcadeTile::PLAYER_HEAD;
  map[snake[1].xy[1]][snake[1].xy[0]] = ArcadeTile::PLAYER_BODY;
  return (0);
}

int	Snake::down()
{
  int2	pos;

  pos.xy[0] = snake[0].xy[0];
  pos.xy[1] = snake[0].xy[1] + 1;
  if (map[pos.xy[1]][pos.xy[0]] == ArcadeTile::FOOD)
    {
      size += 1;
      newFood();
    }
  else if (map[pos.xy[1]][pos.xy[0]] == ArcadeTile::WALL || map[pos.xy[1]][pos.xy[0]] == ArcadeTile::PLAYER_BODY)
    return (1);
  else
    {
      map[snake[size - 1].xy[1]][snake[size - 1].xy[0]] = ArcadeTile::DEFAULT;
      map[snake[size - 2].xy[1]][snake[size - 2].xy[0]] = ArcadeTile::PLAYER_TAIL;
      snake.pop_back();
    }
  snake.insert(snake.begin(), pos);
  map[snake[0].xy[1]][snake[0].xy[0]] = ArcadeTile::PLAYER_HEAD;
  map[snake[1].xy[1]][snake[1].xy[0]] = ArcadeTile::PLAYER_BODY;
  return (0);
}

int	Snake::left()
{
  int2	pos;

  pos.xy[0] = snake[0].xy[0] - 1;
  pos.xy[1] = snake[0].xy[1];
  if (map[pos.xy[1]][pos.xy[0]] == ArcadeTile::FOOD)
    {
      size += 1;
      newFood();
    }
  else if (map[pos.xy[1]][pos.xy[0]] == ArcadeTile::WALL || map[pos.xy[1]][pos.xy[0]] == ArcadeTile::PLAYER_BODY)
    return (1);
  else
    {
      map[snake[size - 1].xy[1]][snake[size - 1].xy[0]] = ArcadeTile::DEFAULT;
      map[snake[size - 2].xy[1]][snake[size - 2].xy[0]] = ArcadeTile::PLAYER_TAIL;
      snake.pop_back();
    }
  snake.insert(snake.begin(), pos);
  map[snake[0].xy[1]][snake[0].xy[0]] = ArcadeTile::PLAYER_HEAD;
  map[snake[1].xy[1]][snake[1].xy[0]] = ArcadeTile::PLAYER_BODY;
  return (0);
}

int	Snake::right()
{
  int2	pos;

  pos.xy[0] = snake[0].xy[0] + 1;
  pos.xy[1] = snake[0].xy[1];
  if (map[pos.xy[1]][pos.xy[0]] == ArcadeTile::FOOD)
    {
      size += 1;
      newFood();
    }
  else if (map[pos.xy[1]][pos.xy[0]] == ArcadeTile::WALL || map[pos.xy[1]][pos.xy[0]] == ArcadeTile::PLAYER_BODY)
    return (1);
  else
    {
      map[snake[size - 1].xy[1]][snake[size - 1].xy[0]] = ArcadeTile::DEFAULT;
      map[snake[size - 2].xy[1]][snake[size - 2].xy[0]] = ArcadeTile::PLAYER_TAIL;
      snake.pop_back();
    }
  snake.insert(snake.begin(), pos);
  map[snake[0].xy[1]][snake[0].xy[0]] = ArcadeTile::PLAYER_HEAD;
  map[snake[1].xy[1]][snake[1].xy[0]] = ArcadeTile::PLAYER_BODY;
  return (0);
}

int	Snake::move()
{
  int	i = 0;

  if (*keyPressed == ArcadeKey::UP)
    i = up();
  else if (*keyPressed == ArcadeKey::DOWN)
    i = down();
  else if (*keyPressed == ArcadeKey::LEFT)
    i = left();
  else if (*keyPressed == ArcadeKey::RIGHT)
    i = right();
  return (i);
}

extern "C" IGame	*newIGame(enum Status *s, int *k, char **new_map)
{
  return (new Snake(s, k, new_map));
}

extern "C" void		deleteIGame(IGame *i)
{
  delete (reinterpret_cast<Snake*>(i));
}

void	*Snake::play()
{
  uint16_t	output = 0;
  std::string		input;

  while (42)
    {
      write_log("\n__boucle_principale\n  {\n   " <<
	       "_snake = (" << snake[0].xy[0] << ","<< snake[0].xy[1] << ")\n  }");
      input = "";
      for (char c = 1; c != '\n' && c != 0;)
	{
	  read(0, &c, 1);
	  write_log("__boucle_read():valeur:c(" << (int)c << ")");
	  input.push_back(c);
	}
      ((char*)(&output))[0] = input[0];
      ((char*)(&output))[1] = input[1];
      std::ofstream fcmd("Cmd.dmp", std::fstream::app); fcmd.write(input.c_str(), input.size()); fcmd << std::endl; fcmd.close();
      write_log("__valeur:input(" << input << ")");
      if (output == (uint16_t)arcade::CommandType::GET_MAP)
	{
	  write_log("__GET_MAP");
	  uint16_t	*array = new uint16_t[3 + WIDTH * HEIGHT];
	  array[0] = output;
	  array[1] = WIDTH;
	  array[2] = HEIGHT;
	  for (int x = 0, y = 0; x < WIDTH; ++x)
	    {
	      for(y = 0; y < HEIGHT; ++y)
		{
		  if (map[y][x] == ArcadeTile::DEFAULT ||
		      map[y][x] == ArcadeTile::PLAYER ||
		      map[y][x] == ArcadeTile::PLAYER_HEAD)
		    {
		      write_log("__valeur:xy (" << x << "," << y << ")");
		      array[3 + x + y*WIDTH] = (uint16_t)arcade::TileType::EMPTY;
		    }
		  else if (map[y][x] == ArcadeTile::PLAYER_BODY ||
			   map[y][x] == ArcadeTile::PLAYER_TAIL)
		    {
		      write_log("__valeur:xy (" << x << "," << y << ")");
		      array[3 + x + y*WIDTH] = (uint16_t)arcade::TileType::MY_SHOOT;
		    }
		  else if (map[y][x] == ArcadeTile::ENEMY ||
			   map[y][x] == ArcadeTile::ENEMY1 ||
			   map[y][x] == ArcadeTile::ENEMY2 ||
			   map[y][x] == ArcadeTile::ENEMY3 ||
			   map[y][x] == ArcadeTile::ENEMY4)
		    {
		      write_log("__valeur:xy (" << x << "," << y << ")");
		      array[3 + x + y*WIDTH] = (uint16_t)arcade::TileType::EVIL_DUDE;
		    }
		  else if (map[y][x] == ArcadeTile::WALL)
		    {
		      write_log("__valeur:xy (" << x << "," << y << ")");
		      array[3 + x + y*WIDTH] = (uint16_t)arcade::TileType::BLOCK;
		    }
		  else if (map[y][x] == ArcadeTile::FOOD ||
			   map[y][x] == ArcadeTile::FOOD1 ||
			   map[y][x] == ArcadeTile::FOOD2)
		    {
		      write_log("__valeur:xy (" << x << "," << y << ")");
		      array[3 + x + y*WIDTH] = (uint16_t)arcade::TileType::POWERUP;
		    }
		  else
		    {
		      write_log("__valeur:xy (" << x << "," << y << ")");
		      array[3 + x + y*WIDTH] = (uint16_t)arcade::TileType::OTHER;
		    }
		}
	    }
	  static int i;
	  std::ofstream(i++ == 0 ? "GET_MAP.dmp" : "GET_MAP_POST.dmp", std::fstream::trunc).write((char*)array, (3 + WIDTH*HEIGHT)*2);
	  write(1, (uint16_t*)array, (3 + WIDTH*HEIGHT)*2);
	  delete [] array;
	  write_log("GET_MAP__");
	}
      else if (output == (uint16_t)arcade::CommandType::WHERE_AM_I)
	{
	  write_log("__WHERE_AM_I");
	  uint16_t	*array = new uint16_t[8];
	  array[0] = output;
	  array[1] = 1;
	  for (int x = 0, y = 0; x < WIDTH; ++x)
	    {
	      for (y = 0; y < HEIGHT; ++y)
		{
		  if (map[y][x] == ArcadeTile::PLAYER ||
		      map[y][x] == ArcadeTile::PLAYER_HEAD)
		    {
		      array[2] = x;
		      array[3] = y;
		    }
		}
	    }
	  std::ofstream("WHERE_AM_I.dmp", std::fstream::trunc).write((char*)array, 8);
	  write(1, (uint16_t*)array, 8);
	  delete [] array;
	  write_log("WHERE_AM_I__");
	}
      else if (output == (uint16_t)arcade::CommandType::PLAY)
	{
	  write_log("__PLAY");
	  if (move() == -1)
	    return (NULL);
	  write_log("PLAY__");
	}
      else
        write_log("__unknow");
    }
  write_log("__leaving");
  return (NULL);
}

#include <string.h>

extern "C" void		Play(void)
{
  enum Status		state = GAME;
  int			keyPressed = ArcadeKey::LEFT;
  char			**map;
  Snake			*snake;

  map = new char*[HEIGHT];
  for (int i = HEIGHT, j = 0; j < i; ++j)
    {
      map[j] = new char[WIDTH];
      memset(map[j], 0, WIDTH);
    }
  snake = new Snake(&state, &keyPressed, map);
  snake->play();
  delete snake;
}
