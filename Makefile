LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftpushswap.a

SRCS =  main.c \
		sources/checker_params.c \
		sources/pile_calc.c \
		sources/pile_calc2.c \
		sources/pile_calc3.c \
		sources/pile_operation.c \
		sources/pile_operation2.c \
		sources/pile.c \
		sources/utils_solve_more_five.c \
		sources/utils.c \
		sources/utils2.c \

HEADER = includes/pile.h

LIBFT = libft/libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

INCLUDES = -I./includes

OBJS = $(SRCS:%.c=%.o) 

all : make_libft $(NAME)

make_libft : 
	$(MAKE) -C ./libft

${LIBFT} : make_libft

%.o : %.c ${HEADER}
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) ${LIBFT}
	cp ${LIBFT} $(NAME)
	ar -rcs $(NAME) $(OBJS)

bonus : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all

PHONY : all make_libft bonus clean fclean re