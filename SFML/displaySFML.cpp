#include "DisplaySFML.hh"

SFML::SFML(enum Status *s, int *k, int *g, char **new_map)
{
  state = s;
  keyPressed = k;
  gameSelection = g;
  map = new_map;
  window.create(sf::VideoMode(WIDTH * 30, HEIGHT * 30), "SFML works!");
  font.loadFromFile("./SFML/arial.ttf");
  event.key.code = sf::Keyboard::Up;

  texture[ArcadeTile::DEFAULT].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(360, 120, 29, 29));

  texture[ArcadeTile::WALL].loadFromFile("./SFML/texture/pokemon_crystal_sprites_2.png", sf::IntRect(400, 700, 30, 30));

  texture[ArcadeTile::FOOD].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(102, 125, 20, 22));

  texture[ArcadeTile::FOOD1].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(255, 154, 4, 4));

  texture[ArcadeTile::FOOD2].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(30, 125, 20, 22));

  texture[ArcadeTile::FOOD3].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(10, 10, 29, 29));

  texture[ArcadeTile::FOOD4].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(10, 10, 29, 29));

  texture[ArcadeTile::FOOD5].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(10, 10, 29, 29));

  texture[ArcadeTile::POWERUP].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(10, 10, 29, 29));

  texture[ArcadeTile::POWERUP1].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(10, 10, 29, 29));

  texture[ArcadeTile::POWERUP2].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(10, 10, 29, 29));

  texture[ArcadeTile::POWERUP3].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(10, 10, 29, 29));

  texture[ArcadeTile::POWERUP4].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(10, 10, 29, 29));

  texture[ArcadeTile::POWERUP5].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(10, 10, 29, 29));

  texture[ArcadeTile::ENEMY].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(10, 10, 29, 29));

  texture[ArcadeTile::ENEMY_SHOT].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(10, 10, 29, 29));

  texture[ArcadeTile::ENEMY1].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(77, 174, 22, 22));

  texture[ArcadeTile::ENEMY_SHOT1].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(10, 10, 29, 29));

  texture[ArcadeTile::ENEMY2].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(77, 222, 22, 22));

  texture[ArcadeTile::ENEMY_SHOT2].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(10, 10, 29, 29));

  texture[ArcadeTile::ENEMY3].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(268, 222, 22, 22));

  texture[ArcadeTile::ENEMY_SHOT3].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(10, 10, 29, 29));

  texture[ArcadeTile::ENEMY4].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(77, 246, 22, 22));

  texture[ArcadeTile::ENEMY_SHOT4].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(10, 10, 29, 29));

  texture[ArcadeTile::ENEMY5].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(10, 10, 29, 29));

  texture[ArcadeTile::ENEMY_SHOT5].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(10, 10, 29, 29));

  texture[ArcadeTile::PLAYER].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(292, 174, 20, 29));

  texture[ArcadeTile::PLAYER_SHOT].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(10, 10, 29, 29));

  texture[ArcadeTile::PLAYER_TAIL].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(201, 11, 4, 4));

  texture[ArcadeTile::PLAYER_BODY].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(222, 7, 8, 8));

  texture[ArcadeTile::PLAYER_HEAD].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(245, 6, 12, 12));

  texture[ArcadeTile::LAST].loadFromFile("./SFML/texture/sam_gfx.png", sf::IntRect(10, 10, 29, 29));

  tex_backGround[1].loadFromFile("./SFML/texture/16c2nux.png", sf::IntRect(7, 8, 226, 250));
}

SFML::~SFML()
{
}

void	*SFML::display()
{
  while (*keyPressed != ArcadeKey::ESCAPE && window.isOpen())
    {
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    {
	      *keyPressed = ArcadeKey::ESCAPE;
	      window.close();
	    }
	  else if (event.type == sf::Event::KeyPressed)
	    {
	      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
		  *keyPressed = ArcadeKey::ESCAPE;
		  window.close();
		}
	      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		*keyPressed = ArcadeKey::RETURN;
	      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		*keyPressed = ArcadeKey::UP;
	      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		*keyPressed = ArcadeKey::DOWN;
	      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		*keyPressed = ArcadeKey::LEFT;
	      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		*keyPressed = ArcadeKey::RIGHT;
	      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
		  *keyPressed = ArcadeKey::NUM2;
		  window.close();
		}
	      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
		  *keyPressed = ArcadeKey::NUM3;
		  window.close();
		}
	      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		*keyPressed = ArcadeKey::NUM4;
	      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
		*keyPressed = ArcadeKey::NUM5;
	      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
		*keyPressed = ArcadeKey::NUM8;
	      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
		*keyPressed = ArcadeKey::NUM9;
	    }
	}
      window.clear();
      if (*state == 0)
  	displayMenu();
      else
      	displayGame();
      window.display();
    }
  return (NULL);
}

void	SFML::displayMenu()
{
  text.setFont(font);
  text.setCharacterSize(24);
  text.setString(*gameSelection == 0 ? "> Snake\n  Pac-Man" : "  Snake\n> Pac-Man");
  window.draw(text);
}

void	SFML::displayGame()
{
  background.setTexture(tex_backGround[*gameSelection], true);
  background.setPosition(sf::Vector2f(15, 15));
  background.setScale(sf::Vector2f(2.4, 2.7));
  window.draw(background);
  for (int x = 0, y = 0; x < WIDTH; ++x)
    {
      for (y = 0; y < HEIGHT; ++y)
	{
	  for (int i = 0, j = ArcadeTile::LAST; i < j; ++i)
	    if (i == map[y][x])
	      {
		smap[y][x].setTexture(texture[i], true);
		sf::Vector2u su = texture[i].getSize();
		smap[y][x].setPosition(x * 30.0 + 15, y * 30.0 + 15);
		smap[y][x].setOrigin(su.x / 2, su.y / 2);
		if (i == ArcadeTile::PLAYER)
		  {
		    if (*keyPressed == ArcadeKey::UP)
		      smap[y][x].setRotation(270);
		    else if (*keyPressed == ArcadeKey::DOWN)
		      smap[y][x].setRotation(90);
		    else if (*keyPressed == ArcadeKey::LEFT)
		      smap[y][x].setRotation(180);
		    else
		      smap[y][x].setRotation(0);
		  }
	      }
	  if ((*gameSelection == 1 && map[y][x] != ArcadeTile::WALL) || *gameSelection == 0)
	    window.draw(smap[y][x]);
	}
    }
}

extern "C" IDisplay	*newIDisplay(enum Status *s, int *k, int *g, char **new_map)
{
  return (new SFML(s, k, g, new_map));
}

extern "C" void		deleteIDisplay(IDisplay *i)
{
  delete (reinterpret_cast<SFML*>(i));
}
