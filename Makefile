NAME	=	push_swap
NAME_BONUS	=	checker

LIB_DIR	=	libft/
LIBFT	=	$(LIB_DIR)libft.a

INCLUDES=	includes/
HEADER	=	includes/push_swap.h
HEADER_BONUS=	includes/checker_bonus.h

DIR		=	src/
FILES	=	push_swap.c check_num.c\
			list.c list_functions.c swap_functions.c\
			sort.c sort_utils.c count_moves.c\
			choose_move.c
SRCS	=	$(addprefix $(DIR), $(FILES))

BONUS_DIR	=	bonus/
FILES_B	=	check_num_bonus.c checker_bonus.c checker_int_bonus.c\
			list_functions_bonus.c swap_functions_bonus.c

SRCS_BONUS	=	$(addprefix $(BONUS_DIR), $(FILES_B))

OBJS	=	$(SRCS:%.c=%.o)
OBJS_BONUS	=	$(SRCS_BONUS:%.c=%.o)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -r

.PHONY	:	all clean fclean re libft bonus

all		:	libft $(NAME)

bonus	:	
			@make NAME="$(NAME_BONUS)" \
			OBJ="$(OBJS_BONUS)" \
			HEADER="$(HEADER_BONUS)" all
#			DIR="$(BONUS_DIR)" \
#			SRCS="$(SRCS_BONUS)" \

$(NAME)	:	$(OBJS)
			$(CC) $(OBJS) $(LIBFT) -o $@

$(DIR)%.o	:	$(DIR).c $(LIBFT) $(HEADER)
			$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

libft	:
			make -C $(LIB_DIR)

clean	:
			rm -f $(OBJS) $(OBJS_B)
			make -C $(LIB_DIR) clean
	
fclean	:	clean
			rm -f $(NAME) $(NAME_BONUS)
			make -C $(LIB_DIR) fclean

re		:	fclean all