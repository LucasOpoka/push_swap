# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 12:09:14 by lopoka            #+#    #+#              #
#    Updated: 2024/06/13 16:33:32 by lopoka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	sources/push_swap.c \
		sources/validate_av.c \
		sources/circ_arr_utils.c \
		sources/ft_sorted.c \
		sources/ft_move_to_b.c \
		sources/ft_sort_three.c \
		sources/ft_move_to_a.c \
		sources/ft_min_to_top.c \
		sources/push_moves.c \
		sources/swap_moves.c \
		sources/rotate_moves.c \
		sources/rev_rotate_moves.c \



B_SRCS = sources/push_swap.c \
		 sources/validate_av.c \
		 sources/circ_arr_utils.c \
		 sources/moves.c \
		 sources/ft_sorted.c \
		 sources/ft_move_to_b.c \
		 sources/ft_sort_three.c \
		 sources/ft_move_to_a.c \
		 sources/ft_min_to_top.c \
		 sources/push_moves.c \
		 sources/swap_moves.c \
		 sources/rotate_moves.c \
		 sources/rev_rotate_moves.c \

CC = cc

CFLAGS = -Wall -Wextra -Werror -I ./sources/libft

DEPSFLAGS += -MMD -MP

OFILES = ${SRCS:.c=.o}

B_OFILES = ${B_SRCS:.c=.o}

DEPS = ${SRCS:.c=.d}

B_DEPS = ${B_SRCS:.c=.d}

LIBFT = ./sources/libft

all : mandatory

mandatory : .mandatory

.mandatory : ${OFILES}
	${MAKE} -C ${LIBFT}
	${CC} -o ${NAME} ${CFLAGS} ${OFILES} ${LIBFT}/libft.a
	@touch .mandatory
	@rm -f .bonus

bonus : .bonus

.bonus : ${B_OFILES}
	${MAKE} -C ${LIBFT}
	${CC} -o ${NAME} ${CFLAGS} ${B_OFILES} ${LIBFT}/libft.a
	@touch .bonus
	@rm -f .mandatory

%.o: %.c
	${CC} ${CFLAGS} ${DEPSFLAGS} -c -o $@ $<

-include ${DEPS}

clean :
	rm -f ${OFILES} ${DEPS} ${B_OFILES} ${B_DEPS}
	${MAKE} -C ${LIBFT} clean
	@rm -f .bonus .mandatory	

fclean :
	rm -f ${NAME} ${OFILES} ${DEPS} ${B_OFILES} ${B_DEPS}
	${MAKE} -C ${LIBFT} fclean
	@rm -f .bonus .mandatory

re : fclean all

redeps:
	touch ${DEPS}
	make
	${MAKE} -C ${LIBFT} redeps

.PHONY: all clean fclean re redeps libft
