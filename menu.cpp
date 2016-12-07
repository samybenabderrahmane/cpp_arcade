#include "Menu.hh"

Menu::Menu(int *pressed, enum Status *st)
{
  state = st;
  gameSelection = 0;
  keyPressed = pressed;
}

Menu::~Menu() {}

void	Menu::setPressed(int *pressed)
{
  keyPressed = pressed;
}

int	Menu::getSelection() const
{
  return (gameSelection);
}

void	Menu::keyAction()
{
  if (*keyPressed == ArcadeKey::UP && gameSelection > 0)
    gameSelection -= 1;
  else if (*keyPressed == ArcadeKey::DOWN && gameSelection < (NB_GAMES - 1))
    gameSelection += 1;
}

void	Menu::menuLoop()
{
  while (*state == MENU && *keyPressed != ArcadeKey::RETURN && *keyPressed != ArcadeKey::ESCAPE)
    {
      keyAction();
      usleep(100000);
    }
  *state = GAME;
}
