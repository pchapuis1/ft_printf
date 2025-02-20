SRCS		= ft_printf.c \
			  	ft_atoi_base.c \
				ft_puthexa.c \
				ft_put.c \

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= cc

RM 			= rm -f

CFLAGS		= -Wall -Wextra -Werror

AR			= ar rc

HEADERS		= ft_printf.h

%.o:		%.c ${HEADERS} Makefile
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: 	${OBJS} ${HEADERS} Makefile
			${AR} ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
