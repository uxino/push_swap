SRCS = push_swap.c rules/rules.c rules/rules1.c rules/rules2.c \
	rules/rules3.c sorting.c max_arguman.c utils.c
OBJS = $(SRCS:.c=.o)
CC = @gcc

LFLAGS = ./libft/libft.a
AFLAGS =  -Wall -Wextra -Werror
RM = @rm -rf
NAME = push_swap

all : $(LFLAGS) $(NAME)
 
$(LFLAGS):
	@make -C ./libft
	@make bonus -C ./libft

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LFLAGS) $(AFLAGS) -o $(NAME)

fclean : clean
	@make fclean -C ./libft
	@$(RM) $(NAME)

clean :
	@make clean -C ./libft
	@$(RM) $(OBJS)

re : fclean all

.PHONY : all fclean clean re