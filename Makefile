CC = gcc
NAME = main
LIBD = ./includes/foundation/
LIBF = libfoundation.a
SRCS := $(wildcard ./src/*.c)
OBJS := $(patsubst %.c, %.o, $(SRCS))
CFLAGS = -Wall -Werror -Wextra -I$(LIBD)
LDFLAGS = -L$(LIBD) -lfoundation

all: $(LIBF) $(NAME)

$(LIBF):
	@$(MAKE) -C $(LIBD)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBD) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBD) fclean

re: fclean all
