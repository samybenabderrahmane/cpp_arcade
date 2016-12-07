SRC	=	displayOpenGL.cpp	\
		sdlglutils.cpp		\
		Camera.cpp		\

CXXFLAGS=	 -fPIC -c -I../ -I./ -g3

LXXFLAGS=	-shared

GLUTLFLAGS=	-lglut -lGLU -lGL -lX11 -lm -lSDL -lSDL_image -I.

NAME	=	../libopengl.so

OBJ	=	$(SRC:.cpp=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		g++ $(OBJ) -o $(NAME) $(LXXFLAGS) $(GLUTLFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	re fclean clean all
