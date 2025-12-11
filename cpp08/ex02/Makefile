CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = a.out
all: $(NAME)
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
