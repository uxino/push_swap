SRCS = push_swap.c rules/rules.c rules/rules1.c rules/rules2.c \
	rules/rules3.c sorting.c max_arguman.c utils.c utils2.c utils3.c
OBJS = $(SRCS:.c=.o)
CC = @gcc

LFLAGS = ./libft/libft.a
AFLAGS =  -Wall -Wextra -Werror
RM = @rm -rf
NAME = push_swap

all : $(LFLAGS) $(NAME)
 
$(LFLAGS):
	@make -C ./Libft
	@make bonus -C ./Libft

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LFLAGS) $(AFLAGS) -o $(NAME)

fclean : clean
	@make fclean -C ./Libft
	@$(RM) $(NAME)

clean :
	@make clean -C ./Libft
	@$(RM) $(OBJS)

re : fclean all

.PHONY : all fclean clean re