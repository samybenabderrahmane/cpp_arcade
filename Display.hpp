#ifndef DISPLAY_HPP_
# define DISPLAY_HPP_

#include "Menu.hh"

class IDisplay
{
protected:
  enum Status	*state;
  int		*keyPressed;
  int		*gameSelection;
  char		**map;
public:
  virtual void	*display() = 0;
};

#endif /* !DISPLAY_HPP_  */
