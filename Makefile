NAME	=	push_swap

LIB_DIR	=	libft/
LIBFT	=	$(LIB_DIR)libft.a

HEADER	=	push_swap.h

SRCS	=	push_swap.c ft_check.c\
			ft_pslist.c ft_ps_functions.c\
			ft_ps_sort.c ft_ps_utils.c

OBJS	=	$(SRCS:.c=.o)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -r

.PHONY	:	all clean fclean re libft

all		:	libft $(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
			$(CC) $(OBJS) $(LIBFT) -o $@

%.o		:	%.c $(LIBFT)
			@$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

libft:
			make -C $(LIB_DIR) bonus

clean	:
			rm -f $(OBJS)
			make -C $(LIB_DIR) clean
	
fclean	:	clean
			rm -f $(NAME)
			make -C $(LIB_DIR) fclean

re		:	fclean all