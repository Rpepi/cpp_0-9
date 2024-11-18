# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 13:46:01 by rpepi             #+#    #+#              #
#    Updated: 2024/11/18 13:48:10 by rpepi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):
	clang++ -Wall -Wextra -Werror -std=c++98 main.cpp -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re
