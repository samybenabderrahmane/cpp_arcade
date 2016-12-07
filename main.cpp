#include <stdlib.h>
#include <time.h>
#include "Arcade.hh"

int		main(int ac, char **av)
{
  Arcade	*arcade;

  if (ac == 2)
    {
      arcade = new Arcade(av[1]);
      srand(time(NULL));
      arcade->mainLoop();
      delete arcade;
    }
  return 0;
}
