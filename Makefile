# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 20:05:04 by Degef             #+#    #+#              #
#    Updated: 2023/03/23 19:07:58 by mkiflema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
B_Name	= checker

M_SRCS	= $(wildcard mandatory/*.c)
			
B_SRCS	= $(wildcard bonus/*.c)

FLAGS	= -Wall -Wextra -Werror
CC		= cc
RM		= rm -f 

M_OBJS	= $(M_SRCS:.c=.o)
B_OBJS	= $(B_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(M_OBJS)
	cd ./libft && make
	$(CC) $(FLAGS) $(M_OBJS) ./libft/libft.a -o $(NAME)
	

bonus: $(B_OBJS)
	cd ./libft && make
	$(CC) $(FLAGS) $(B_OBJS) ./libft/libft.a -o $(B_Name)
	
clean: 
	cd ./libft && make clean
	$(RM) $(M_OBJS) $(B_OBJS) 

fclean: clean
	cd ./libft && make fclean
	$(RM) $(NAME) $(B_Name)
	
re: fclean all
