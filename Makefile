NAME = push_swap
BONUS = checker

SRCS_DIR = src
BONUS_DIR = bonus
INCLUDE_DIR = gnl
LIBFT_DIR = libft

SRCS = $(SRCS_DIR)/push_swap.c \
	   $(SRCS_DIR)/algorithm/cost.c \
	   $(SRCS_DIR)/algorithm/move.c \
	   $(SRCS_DIR)/algorithm/position.c \
	   $(SRCS_DIR)/algorithm/sort.c \
	   $(SRCS_DIR)/algorithm/turk_algorithm.c \
	   $(SRCS_DIR)/algorithm/utils.c \
	   $(SRCS_DIR)/operations/push.c \
	   $(SRCS_DIR)/operations/reverse_rotate.c \
	   $(SRCS_DIR)/operations/rotate.c \
	   $(SRCS_DIR)/operations/swap.c \
	   $(SRCS_DIR)/stack/get_stack.c \
	   $(SRCS_DIR)/stack/index_stack.c \
	   $(SRCS_DIR)/stack/stack_utils.c \
	   $(SRCS_DIR)/validation/input_validation.c \
	   $(SRCS_DIR)/validation/parse_args.c \
	   $(SRCS_DIR)/validation/parse_str.c


BONUS_SRCS = $(BONUS_DIR)/checker_bonus.c \
			 $(INCLUDE_DIR)/get_next_line.c \
			 $(INCLUDE_DIR)/get_next_line_utils.c \
			 $(SRCS_DIR)/algorithm/cost.c \
			 $(SRCS_DIR)/algorithm/move.c \
			 $(SRCS_DIR)/algorithm/position.c \
			 $(SRCS_DIR)/algorithm/sort.c \
			 $(SRCS_DIR)/algorithm/turk_algorithm.c \
			 $(SRCS_DIR)/algorithm/utils.c \
			 $(SRCS_DIR)/operations/push.c \
			 $(SRCS_DIR)/operations/reverse_rotate.c \
			 $(SRCS_DIR)/operations/rotate.c \
			 $(SRCS_DIR)/operations/swap.c \
			 $(SRCS_DIR)/stack/get_stack.c \
			 $(SRCS_DIR)/stack/index_stack.c \
			 $(SRCS_DIR)/stack/stack_utils.c \
			 $(SRCS_DIR)/validation/input_validation.c \
			 $(SRCS_DIR)/validation/parse_args.c \
			 $(SRCS_DIR)/validation/parse_str.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR)

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus