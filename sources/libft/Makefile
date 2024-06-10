# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 13:52:43 by lopoka            #+#    #+#              #
#    Updated: 2024/06/03 13:43:25 by lucas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strncpy.c \
	   ft_strlcpy.c \
	   ft_strcat.c \
	   ft_strlcat.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_strstr.c \
	   ft_atoi.c \
	   ft_atof.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_split_sub.c \
	   ft_free_split.c \
	   ft_itoa.c \
	   ft_ctoa.c \
	   ft_lxtoa.c \
	   ft_ptoa.c \
	   ft_utoa.c \
	   ft_uxtoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_lstnew.c \
	   ft_lstadd_front.c \
	   ft_lstsize.c \
	   ft_lstlast.c \
	   ft_lstadd_back.c \
	   ft_lstdelone.c \
	   ft_lstclear.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_printf.c \
	   ft_printf_fd.c \
	   ft_prnt_c.c \
	   ft_prnt_s.c \
	   ft_prnt_p.c \
	   ft_prnt_d.c \
	   ft_prnt_u.c \
	   ft_prnt_lx.c \
	   ft_prnt_ux.c \
	   ft_realloc.c \
	   ft_printf_realloc.c \
	   ft_prnt_add.c \
	   ft_rm_char.c \
	   ft_free_split_null.c \
	  
CC = cc

CFLAGS += -Wall -Wextra -Werror

DEPSFLAGS += -MMD -MP

NAME = libft.a

CRLIB = ar rcs

OFILES = ${SRCS:.c=.o}

DEPS = $(SRCS:.c=.d)

${NAME} : ${OFILES}
	${CRLIB} ${NAME} ${OFILES}

all : ${NAME}

%.o : %.c libft.h
	${CC} ${CFLAGS} ${DEPSFLAGS} -c -o $@ $<

clean :
	rm -f ${OFILES} ${DEPS}

fclean :
	rm -f ${NAME} ${OFILES} ${DEPS}

re : fclean all

-include ${DEPS}

redeps :
	touch ${DEPS}
	make

.PHONY : all clean fclean re redeps
