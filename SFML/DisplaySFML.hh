#ifndef DISPLAYSFML_HH_
# define DISPLAYSFML_HH_

#include "Graphics.hpp"
#include "Display.hpp"
#include "Menu.hh"

class	SFML : public IDisplay
{
  enum Status	*state;
  int		*keyPressed;
  int		*gameSelection;
  char		**map;


  sf::RenderWindow window;
  sf::Event event;
  sf::Font font;
  sf::Text text;
  sf::Sprite smap[HEIGHT][WIDTH];
  sf::Sprite background;
  sf::Texture texture[ArcadeTile::LAST];
  sf::Texture tex_backGround[2];

public:
  SFML(enum Status *, int *, int *, char **);
  virtual ~SFML();
  void	*display();
  void	displayMenu();
  void	displayGame();
};

#endif
