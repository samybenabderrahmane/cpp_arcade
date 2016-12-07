SRC	=	Snake.cpp	\

CXXFLAGS=	-W -Wall -Wextra -Werror -fPIC -c -I../../ -I./ -g3 -std=gnu++11

LXXFLAGS=	-shared

NAME	=	../../libsnake.so

OBJ	=	$(SRC:.cpp=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		g++ $(OBJ) -o $(NAME) $(LXXFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	re fclean clean all
