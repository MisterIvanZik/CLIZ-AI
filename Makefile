# *********************************************************************************************************** #
#                                                                                                             #
#                                                               :::::::::: ::::::::   :::::::: :::::::::::    #
#    Makefile                                                  :+:       :+:    :+: :+:    :+:    :+:         #
#                                                             +:+       +:+        +:+           +:+          #
#    By: ivan <ivan@myges.fr>                                +#++:++#  +#++:++#++ :#:           +#+           #
#                                                           +#+              +#+ +#+   +#+#    +#+            #
#    Created: 2024/10/24 22:24:06 by ivan                  #+#       #+#    #+# #+#    #+#    #+#             #
#    Updated: 2024/10/24 22:24:06 by ivan                 ########## ########   ######## ###########          #
#                                                                                                             #
# *********************************************************************************************************** #

CC	=	gcc

SRC	=	./sources/main.c		\
		./sources/GUI/gui.c		\
		./sources/GUI/animation.c	\
		./sources/GUI/destroy.c		\
		./sources/GUI/init.c	\
		./sources/GUI/sign_up_page.c	\
		./sources/GUI/chatbot_page.c	\
		./sources/GUI/events.c	\
		./lib/my_strlen.c	\

OBJ	=	$(SRC:.c=.o)

CSFML_FLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CFLAGS  =	-Wall -Wextra

CPPFLAGS	=	-I includes/

BIN_NAME	=	cliz_ai

all:	$(OBJ)
	$(CC) -o $(BIN_NAME) $(OBJ) $(CSFML_FLAGS) $(CFLAGS) -lm -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(BIN_NAME)

re: fclean all

.PHONY: clean fclean re
