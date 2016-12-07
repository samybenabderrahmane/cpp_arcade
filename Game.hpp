#ifndef IGAME_HPP_
# define IGAME_HPP_

#include "Menu.hh"

class IGame
{
public:
  virtual void	*play() = 0;
  virtual void	*iplay() = 0;
};

#endif /* !DISPLAY_HPP_  */
