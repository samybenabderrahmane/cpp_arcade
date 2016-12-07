SRC	=	main.cpp	\
		arcade.cpp	\
		menu.cpp	\

CXXFLAGS=	-W -Wall -Wextra -Werror -I./ -g3

LXXFLAGS=	-lpthread -ldl

NAME	=	arcade

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
