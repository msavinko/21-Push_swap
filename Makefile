NAME_PS	=	push_swap
NAME_PSB	=	checker

LIB_DIR	=	libft/
LIBFT	=	$(LIB_DIR)libft.a

INCLUDES_PS=	includes/
HEADER_PS	=	includes/push_swap.h
HEADER_PSB=	includes/checker_bonus.h

DIR_PS		=	src/
FILES_PS	=	push_swap.c check_num.c list.c list_functions.c\
				swap_functions.c sort.c sort_utils.c count_moves.c\
				choose_move.c median.c
SRCS_PS	=	$(addprefix $(DIR_PS), $(FILES_PS))

DIR_PSB=	bonus/
FILES_PSB	=	check_num_bonus.c checker_bonus.c checker_int_bonus.c\
				list_functions_bonus.c swap_functions_bonus.c
SRCS_PSB=	$(addprefix $(DIR_PSB), $(FILES_PSB))

OBJS_PS	=	$(SRCS_PS:%.c=%.o)
OBJS_PSB	=	$(SRCS_PSB:%.c=%.o)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

.PHONY	:	all clean fclean re libft bonus

all		:	libft $(NAME_PS)

libft	:
			@make -C $(LIB_DIR)

bonus	:	
			@make NAME_PS="$(NAME_PSB)" \
			OBJS_PS="$(OBJS_PSB)" \
			HEADER_PS="$(HEADER_PSB)" all

$(NAME_PS)	:	$(OBJS_PS)
			$(CC) $(OBJS_PS) $(LIBFT) -o $@

%.o	:	%.c $(LIBFT) $(HEADER_PS)
			$(CC) $(CFLAGS) -I $(INCLUDES_PS) -c $< -o $@

clean	:
			$(RM) $(OBJS_PS) $(OBJS_PSB)
			make -C $(LIB_DIR) clean
	
fclean	:	clean
			$(RM) $(NAME_PS) $(NAME_PSB)
			make -C $(LIB_DIR) fclean

re		:	fclean all