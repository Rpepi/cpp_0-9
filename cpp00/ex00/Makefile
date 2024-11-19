# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 15:06:11 by pepi              #+#    #+#              #
#    Updated: 2024/10/31 15:06:12 by pepi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom du programme
NAME = megaphone

# Flags de compilation
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Fichiers
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

# Règle par défaut
all: $(NAME)

# Compilation du programme
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

# Compilation des fichiers .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean des fichiers .o et de l'exécutable
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

.PHONY: all clean fclean re
