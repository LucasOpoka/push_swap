# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 12:09:14 by lopoka            #+#    #+#              #
#    Updated: 2024/06/17 17:18:36 by lopoka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

B_NAME = checker

SRCS =	sources/push_swap.c \
		sources/validate_av.c \
		sources/push_to_a.c \
		sources/push_to_b.c \
		sources/sort_three.c \
		sources/min_to_top.c \
		sources/stack_min_max_bl_lb.c \
		sources/move_cases.c \
		sources/perform_moves.c \
		sources/push_moves.c \
		sources/swap_moves.c \
		sources/rotate_moves.c \
		sources/rev_rotate_moves.c \
		sources/free_close.c \
		sources/swap_atoi.c \
		sources/min_max.c \
		sources/is_stack_sorted.c \
		sources/add_cmnd.c \
		sources/init_stacks.c \
		sources/check_dups.c \
				
B_SRCS = sources/validate_av.c \
		 sources/stack_min_max_bl_lb.c \
		 sources/push_moves.c \
		 sources/swap_moves.c \
		 sources/rotate_moves.c \
		 sources/rev_rotate_moves.c \
		 sources/free_close.c \
		 sources/swap_atoi.c \
		 sources/add_cmnd.c \
		 sources/init_stacks.c \
		 sources/check_dups.c \
		 sources/checker.c \

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

bonus : .bonus

.mandatory : ${OFILES}
	${MAKE} -C ${LIBFT}
	${CC} -o ${NAME} ${CFLAGS} ${OFILES} ${LIBFT}/libft.a
	@touch .mandatory

.bonus : ${B_OFILES}
	${MAKE} -C ${LIBFT}
	${CC} -o ${B_NAME} ${CFLAGS} ${B_OFILES} ${LIBFT}/libft.a
	@touch .bonus

%.o: %.c
	${CC} ${CFLAGS} ${DEPSFLAGS} -c -o $@ $<

-include ${DEPS}

clean :
	rm -f ${OFILES} ${DEPS} ${B_OFILES} ${B_DEPS}
	${MAKE} -C ${LIBFT} clean
	@rm -rf .mandatory .bonus	

fclean :
	rm -f ${NAME} ${B_NAME} ${OFILES} ${DEPS} ${B_OFILES} ${B_DEPS}
	${MAKE} -C ${LIBFT} fclean
	@rm -rf .mandatory .bonus

re : fclean all

redeps:
	touch ${DEPS}
	make
	${MAKE} -C ${LIBFT} redeps

.PHONY: all clean fclean re redeps libft
