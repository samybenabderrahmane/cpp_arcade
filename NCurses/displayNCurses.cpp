#include "DisplayNCurses.hh"

static void     *keyEvent_helper(void *arg)
{
  return (((NCurses *)arg)->keyEvent(NULL));
}

NCurses::NCurses(enum Status *s, int *k, int *g, char **new_map)
{
  state = s;
  keyPressed = k;
  gameSelection = g;
  map = new_map;
}

NCurses::~NCurses() {}

void	*NCurses::display()
{
  initscr();
  curs_set(0);
  raw();
  keypad(stdscr, TRUE);
  noecho();

  pthread_t	key_thr;
  WINDOW	*win = subwin(stdscr, HEIGHT + 2, WIDTH*2  + 2, 0, 0);

  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLUE);
  init_pair(3, COLOR_BLUE, COLOR_RED);
  init_pair(4, COLOR_BLUE, COLOR_YELLOW);
  init_pair(5, COLOR_BLUE, COLOR_GREEN);
  init_pair(6, COLOR_YELLOW, COLOR_BLACK);
  init_pair(7, COLOR_GREEN, COLOR_BLACK);
  init_pair(8, COLOR_GREEN, COLOR_YELLOW);
  init_pair(9, COLOR_GREEN, COLOR_CYAN);
  init_pair(10, COLOR_GREEN, COLOR_MAGENTA);
  init_pair(11, COLOR_GREEN, COLOR_GREEN);

  pthread_create(&key_thr, NULL, keyEvent_helper, this);
  while (*keyPressed != ArcadeKey::ESCAPE &&
	 *keyPressed != ArcadeKey::NUM2 &&
	 *keyPressed != ArcadeKey::NUM3)
    {
      if (*state == 0)
  	displayMenu();
      else
      	displayGame(win);
      refresh();
      usleep(100000);
    }
  pthread_join(key_thr, NULL);
  endwin();
  std::cout << "leaving ncurses" << std::endl;
  return (NULL);
}

void	NCurses::displayMenu()
{
  clear();
  attron(COLOR_PAIR(1));
  mvprintw(0, 0, "%s%s", (*gameSelection == 0 ? "> " : "  "), "Snake");
  mvprintw(1, 0, "%s%s", (*gameSelection == 1 ? "> " : "  "), "Pac-Man");
  attroff(COLOR_PAIR(1));
}

void	NCurses::displayGame(WINDOW *win)
{
  int   x = 0, y = 0;
  int   posx = 1;

  clear();
  getparyx(win, y, x);
  while (x < WIDTH)
    {
      y = 0;
      while (y < HEIGHT)
	{
	  if (map[y][x] == ArcadeTile::DEFAULT)
	    {
	      attron(COLOR_PAIR(1));
	      mvprintw(y + 1, posx, " ");
	      mvprintw(y + 1, posx + 1, " ");
	      attroff(COLOR_PAIR(1));
	    }
	  else if (map[y][x] == ArcadeTile::WALL)
	    {
	      attron(COLOR_PAIR(2));
	      mvprintw(y + 1, posx, " ");
	      mvprintw(y + 1, posx + 1, " ");
	      attroff(COLOR_PAIR(2));
	    }
	  else if (map[y][x] == ArcadeTile::PLAYER_HEAD)
	    {
	      attron(COLOR_PAIR(3));
	      mvprintw(y + 1, posx, " ");
	      mvprintw(y + 1, posx + 1, " ");
	      attroff(COLOR_PAIR(3));
	    }
	  else if (map[y][x] == ArcadeTile::PLAYER)
	    {
	      attron(COLOR_PAIR(4));
	      mvprintw(y + 1, posx, " ");
	      mvprintw(y + 1, posx + 1, " ");
	      attroff(COLOR_PAIR(4));
	    }
	  else if (map[y][x] == ArcadeTile::FOOD)
	    {
	      attron(COLOR_PAIR(5));
	      mvprintw(y + 1, posx, " ");
	      mvprintw(y + 1, posx + 1, " ");
	      attroff(COLOR_PAIR(5));
	    }
	  else if (map[y][x] == ArcadeTile::FOOD1)
	    {
	      attron(COLOR_PAIR(6));
	      mvprintw(y + 1, posx, "*");
	      mvprintw(y + 1, posx + 1, " ");
	      attroff(COLOR_PAIR(6));
	    }
	  else if (map[y][x] == ArcadeTile::FOOD2)
	    {
	      attron(COLOR_PAIR(7));
	      mvprintw(y + 1, posx, "@");
	      mvprintw(y + 1, posx + 1, " ");
	      attroff(COLOR_PAIR(7));
	    }
	  else if (map[y][x] == ArcadeTile::PLAYER_BODY)
	    {
	      attron(COLOR_PAIR(8));
	      mvprintw(y + 1, posx, " ");
	      mvprintw(y + 1, posx + 1, " ");
	      attroff(COLOR_PAIR(8));
	    }
	  else if (map[y][x] == ArcadeTile::ENEMY1)
	    {
	      attron(COLOR_PAIR(3));
	      mvprintw(y + 1, posx, " ");
	      mvprintw(y + 1, posx + 1, " ");
	      attroff(COLOR_PAIR(3));
	    }
	  else if (map[y][x] == ArcadeTile::ENEMY2)
	    {
	      attron(COLOR_PAIR(9));
	      mvprintw(y + 1, posx, " ");
	      mvprintw(y + 1, posx + 1, " ");
	      attroff(COLOR_PAIR(9));
	    }
	  else if (map[y][x] == ArcadeTile::ENEMY3)
	    {
	      attron(COLOR_PAIR(10));
	      mvprintw(y + 1, posx, " ");
	      mvprintw(y + 1, posx + 1, " ");
	      attroff(COLOR_PAIR(10));
	    }
	  else if (map[y][x] == ArcadeTile::ENEMY4)
	    {
	      attron(COLOR_PAIR(11));
	      mvprintw(y + 1, posx, " ");
	      mvprintw(y + 1, posx + 1, " ");
	      attroff(COLOR_PAIR(11));
	    }
	  y = y + 1;
	}
      x = x + 1;
      posx = posx + 2;
    }
}

void	*NCurses::keyEvent(void *arg)
{
  (void)arg;
  int key;
  while(*keyPressed != ArcadeKey::ESCAPE)
    {
      key = getch();
      if (key == KEY_UP)
	*keyPressed = ArcadeKey::UP;
      else if (key == KEY_DOWN)
	*keyPressed = ArcadeKey::DOWN;
      else if (key == KEY_LEFT)
	*keyPressed = ArcadeKey::LEFT;
      else if (key == KEY_RIGHT)
	*keyPressed = ArcadeKey::RIGHT;
      else if (key == 27)
	{
	  *keyPressed = ArcadeKey::ESCAPE;
	  return (NULL);
	}
      else if (key == 10)
	*keyPressed = ArcadeKey::RETURN;
      else if (key == 50)
	{
	  *keyPressed = ArcadeKey::NUM2;
	  return (NULL);
	}
      else if (key == 51)
	{
	  *keyPressed = ArcadeKey::NUM3;
	  return (NULL);
	}
      else if (key == 52)
	*keyPressed = ArcadeKey::NUM4;
      else if (key == 53)
	*keyPressed = ArcadeKey::NUM5;
      else if (key == 56)
	*keyPressed = ArcadeKey::NUM8;
      else if (key == 57)
	*keyPressed = ArcadeKey::NUM9;
    }
    usleep(3000);
  return (NULL);
}

extern "C" IDisplay	*newIDisplay(enum Status *s, int *k, int *g, char **new_map)
{
  return (new NCurses(s, k, g, new_map));
}

extern "C" void		deleteIDisplay(IDisplay *i)
{
  delete (reinterpret_cast<NCurses*>(i));
}
