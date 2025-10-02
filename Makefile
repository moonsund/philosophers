NAME       = philo

CC         = cc
CFLAGS     = -Wall -Wextra -Werror -pthread

INC        = -Iincludes

SRC_PATH = sources
OBJ_PATH = objects

SRC_FILES = main.c parse.c

SRCS = $(addprefix $(SRC_PATH)/,$(SRC_FILES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SRC_FILES:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all