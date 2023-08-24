CC = gcc
NAME = main
LIBD = ./includes/foundation/
LIBF = libfoundation.a
SRCS := $(wildcard ./src/*.c)
OBJS := $(patsubst %.c, %.o, $(SRCS))
CFLAGS = -Wall -Werror -Wextra -I$(LIBD)
LDFLAGS = -L$(LIBD) -lfoundation
DEBUG_FLAGS = -g -v

all: $(LIBF) $(NAME)

$(LIBF):
	@$(MAKE) -C $(LIBD)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

debug: CFLAGS += $(DEBUG_FLAGS)
debug: clean $(NAME)

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBD) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBD) fclean

re: fclean all
