NAME				=	philo

CC					=	gcc
CFLAGS				=	-Wall -Werror -Wextra
RM					=	rm -f

INC					=	inc/
SRC_DIR				=	src/
OBJ_DIR				=	obj/

SRC					=	data_init.c \
						handle_threads_mutexes.c \
						monitor.c \
						parse_input.c \
						philo.c \
						print_status.c \
						protect_vars.c \
						sim_start.c \
						utils.c

SRCS				=	$(addprefix $(SRC_DIR), $(SRC))

OBJ 				= 	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))


all: 					$(NAME)

$(NAME): 				$(OBJ)
						@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o:			$(SRC_DIR)%.c 
						@mkdir -p $(@D)
						@$(CC) $(CFLAGS) -c $< -o $@

clean:
						@$(RM) -r $(OBJ_DIR)

fclean: 				clean
						@$(RM) $(NAME)
						@$(RM) src/a.out

re: 					fclean all

.PHONY: 				all clean fclean re 

