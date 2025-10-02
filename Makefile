NAME       = philo

CC         = cc
CFLAGS     = -Wall -Wextra -Werror

INC		= -I ./includes/

SRC_PATH = sources/
OBJ_PATH = objects/

SRC_FILES = main.c parse.c

SRCS = $(addprefix $(SRC_PATH) $(SRC))
OBJS = $(addprefix $(OBJ_PATH),$(SRC_FILES:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	$(MAKE)
	rm -f $(OBJS)

fclean: clean
	$(MAKE)
	rm -f $(NAME) lf

re: fclean all