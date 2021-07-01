NAME		= libasm.a

TEST_NAME	= test

HEADER		= libasm.h

SRCS_DIR	= functions

SRCS_FUNC	= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

SRCS		= $(addprefix $(SRCS_DIR)/, $(SRCS_FUNC))

OBJS		= $(SRCS:.s=.o)

NASM		= nasm

FLAGS		= -f macho64

%.o: 		%.s $(HEADER)
			$(NASM) $(FLAGS) $< -o $@

RM			= rm -f

all:		$(NAME)

$(NAME):	$(OBJS) 
			ar rc $(NAME) $(OBJS) $(HEADER)
			gcc -Wall -Wextra -Werror main.c $(NAME) -o $(TEST_NAME)
		
clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)
			$(RM) $(TEST_NAME)

re: 		fclean all

.PHONY:		all clean fclean re bonus