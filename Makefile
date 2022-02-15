NAME	=	push_swap
BONUS	=	checker

LIB_DIR	=	libft/
LIBFT	=	$(LIB_DIR)libft.a

HEADER	=	push_swap.h
HEADER_BONUS	=	checker.h

SRCS	=	push_swap.c check_num.c\
			list.c list_functions.c swap_functions.c\
			sort.c sort_utils.c count_moves.c\
			choose_move.c

SRCS_B	=	checker_bonus.c checker_int_bonus.c check_num_bonusc\
			list_functions_bonus.c swap_functions_bonus.c\

OBJS	=	$(SRCS:.c=.o)
OBJS_B	=	$(SRCS_B:.c=.o)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -r

.PHONY	:	all clean fclean re libft bonus

all		:	libft $(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
			$(CC) $(OBJS) $(LIBFT) -o $@

%.o		:	%.c $(LIBFT)
			@$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

libft	:
			@make -C $(LIB_DIR) bonus

#bonus	:	libft $(BONUS)

bonus   :	$(OBJ_B) $(HEADER_BONUS)
	@make NAME="$(NAME) $(BONUS)" OBJ="$(OBJ) $(OBJ_B)" HEADER="$(HEADER) $(HEADER_BONUS)" all

$(BONUS):	$(OBJS_B) $(HEADER)
			$(CC) $(OBJS_B) $(LIBFT) -o $@
clean	:
			rm -f $(OBJS) $(OBJS_B)
			make -C $(LIB_DIR) clean
	
fclean	:	clean
			rm -f $(NAME) $(BONUS)
			make -C $(LIB_DIR) fclean

re		:	fclean all