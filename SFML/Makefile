SRC	=	displaySFML.cpp	\

CXXFLAGS=	-W -Wall -Wextra -Werror -fPIC -c -I../ -I./ -I./SFML/incs_sfml -g3

LXXFLAGS=	-L ./SFML/libs_sfml -lpthread -shared -lsfml-graphics -lsfml-window \
		-lcsfml-graphics -lcsfml-window -lsfml-system

NAME	=	../libsfml.so

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
