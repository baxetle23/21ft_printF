LIBFT 			= ./libft/libft.a

NAME 			= libftprintf.a

HEADER			= ./includes/printf.h

DIR_S			= src

SOURCE			=	ft_printf.c parsing.c display.c\
					display_decimal.c display_decimal_p_w.c display_decimal_p.c\
					display_hexa.c display_hexa_p.c\
					display_pointer.c display_pointer_p.c\
					display_string.c\
					get_size.c utilits.c\

SRCS			= $(addprefix $(DIR_S)/,$(SOURCE))
OBJS			= $(SRCS:.c=.o)
%.o:			%.c ${HEADER}
				$(CC) $(CFLAGS) -c -o $@ $<
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Werror -Wextra
INCLUDES		= ./includes/printf.h

$(NAME):		$(OBJS) $(HEADER)
				$(MAKE) -C ./libft
				cp libft/libft.a ./$(NAME)
				ar rcs $(NAME) $(OBJS)

all:			$(NAME)
clean:
				$(MAKE) clean -C ./libft	
				$(RM) $(OBJS)		

fclean:			clean
				$(MAKE) fclean -C ./libft
				$(RM) $(NAME)
				
re:				fclean all
test:			all
.PHONY:			all clean fclean re
