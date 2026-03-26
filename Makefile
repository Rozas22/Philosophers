NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
SRC_DIR = src
INC_DIR = Include
OBJ_DIR = obj
SRC_FILES = main.c check_args.c init.c monitor.c philo_routine.c \
			start_dinner.c utils.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)
$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "$(GREEN)Philo compilado con éxito$(RESET)"
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

clean:
		@rm -rf $(OBJ_DIR)
		@echo "Objetos eliminados."

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re