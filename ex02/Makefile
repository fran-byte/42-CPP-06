# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/12 13:52:01 by frromero          #+#    #+#              #
#    Updated: 2025/12/21 17:22:53 by frromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = realType
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
INCLUDES = -I .

SRC =	main.cpp Base.cpp Identify.cpp
		
OBJ = $(SRC:.cpp=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "$(NAME) created."

clean:
	@rm -f $(OBJ)
	@echo "Object files deleted."

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted."

re: fclean all

.PHONY: all clean fclean re