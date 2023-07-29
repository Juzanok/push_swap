# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 04:38:03 by jkarosas          #+#    #+#              #
#    Updated: 2022/03/17 23:53:00 by jkarosas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
NAME_BONUS		=	checker

PRNTF			=	ft_printf/libftprintf.a
LIBFT			=	libft/libft.a

SRCS			=	srcs/push_swap.c \
					srcs/move_rules.c \
					srcs/move.c \
					srcs/stack_get.c \
					srcs/sort.c \
					srcs/sort_utils.c \
					srcs/sort_big.c \
					srcs/smart_rotate.c \
					srcs/sort_big_utils.c 
OBJS			=	${SRCS:.c=.o}

SRCS_BONUS		=	srcs_bonus/checker.c \
					srcs_bonus/do_moves.c \
					srcs_bonus/get_stack.c \
					srcs_bonus/move_rules.c \
					srcs_bonus/move.c
OBJS_BONUS		=	${SRCS_BONUS:.c=.o}

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
INC				=	-I ./includes -I ./libft -I ./ft_printf
RM				=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS) $(OBJS_BONUS)
			make -s -C libft
			make -s -C ft_printf
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(PRNTF)
			$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS) $(LIBFT) $(PRNTF)

.c.o:
			${CC} ${CFLAGS} $(INC) -c $< -o ${<:.c=.o}

clean:
			make clean -s -C libft
			make clean -s -C ft_printf
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			make fclean -s -C libft
			make fclean -s -C ft_printf
			${RM} $(NAME) $(NAME_BONUS)

re:			fclean all

.PHONY:		all clean fclean re