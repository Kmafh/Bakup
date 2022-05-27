NAME =  libftpush.a

TARGET =	push_swap

DIR_SRC = push_src/

DIR_LIB = include/

DIR_OBJS = obj/

SRCS	=	ft_stack.c ft_game.c

MAIN	= 	main.c

OBJS	=	${SRCS:.c=.o}

CC = gcc 
	
C = -c 

CFLAGS = -Wall -Wextra -Werror

AR = ar 

ARFLGS = crs

RM = rm

LIBF = libft/

NORMINETTE = norminette .

all: $(NAME)




$(NAME): 
	@make -C $(LIBF)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@mkdir obj
	@cp $(DIR_SRC)* .
	@$(CC) $(C) $(SRCS) 
	@$(AR) $(ARFLGS) $(NAME) $(OBJS)
	@rm *.c
	@mv *.o $(DIR_OBJS)
	@$(CC) $(CFLAGS) $(DIR_SRC)$(MAIN) $(NAME) -o $(TARGET)
	@echo Compiled push_swap finish OK!!
	

.PHONY: clean fclean re
clean:
	@$(RM) -r obj/
	@make fclean -C $(LIBF)
	@echo Delete completed successfully! *.o

fclean: clean
	@rm libftpush.a push_swap
	@make clean -C $(LIBF)
	
	@echo Delete completed successfully! *.a
 
re: fclean all

norm:
	@$(NORMINETTE) $(SRCS)