# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 08:33:53 by marcsilv          #+#    #+#              #
#    Updated: 2024/12/28 08:46:05 by marcsilv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	philo_bonus

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror
RM					=	rm -f

INC					=	inc						/
SRC_DIR				=	src						/
OBJ_DIR				=	obj						/

SRC					=

SRCS				=	$(addprefix $(SRC_DIR), $(SRC))

OBJ					=	$(patsubst $(OBJ_DIR)%.c, $(SRC_DIR)%.c, $(SRCS))

all: 					$(NAME)

$(NAME):				$(OBJ)
						@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)%.o:			$(SRC_DIR)%.c
						@mkdir -p $(OBJ_DIR)
						@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean:
						@$(RM) -r $(OBJ_DIR)

fclean:					clean
						@$(RM) $(NAME)

re:						fclean all

.PHONY:					all clean fclean re
