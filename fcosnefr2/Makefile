# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/26 13:34:03 by jaguillo          #+#    #+#              #
#    Updated: 2015/03/11 15:46:43 by fcosnefr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

H_DIR = h/
C_DIR = srcs/
O_DIR = o/
LIBFT = libft/

FLAGS = -Wall -Wextra -Werror -O2
LINKS = -I$(H_DIR) -I$(LIBFT)
DEBUG = 0

C_FILES = $(shell ls -1 $(C_DIR) | grep "\.c")

O_FILES = $(addprefix $(O_DIR),$(C_FILES:.c=.o))

all:
	@(if [ "$(DEBUG)" -eq "1" ]; then \
			make -C $(LIBFT) debug; else \
			make -C $(LIBFT); fi \
		|| (echo "\033[0;31m$(LIBFT)\033[0;0m" && exit 1)) \
	| grep -v "Nothing to be done" || echo "" > /dev/null
	@if [ "$(DEBUG)" -eq "1" ]; then \
		make -j4 _debug $(NAME); else \
		make -j4 $(NAME); fi

$(NAME): $(O_FILES)
	$(eval FT_O = $(shell find $(LIBFT) -type f -print | grep "\.o"))
	@ar rcs $@ $(O_FILES) $(FT_O) && printf "\033[0;32m" || printf "\033[0;31m"
	@printf "%-24s\033[1;30m<<--\033[0;0m\n" "$@"

$(O_DIR)%.o: $(C_DIR)%.c
	@mkdir $(O_DIR) 2> /dev/null || echo "" > /dev/null
	@gcc $(FLAGS) $(LINKS) -o $@ -c $< \
	&& printf "\033[0;0m%-24s\033[1;30m-->>	\033[0;32m$@\033[0;0m\n" "$<" \
	|| (printf "\033[0;0m%-24s\033[1;30m-->>	\033[0;31m$@\033[0;0m\n" "$<" \
		&& exit 1)

clean:
	@rm $(O_FILES) 2> /dev/null || echo "" > /dev/null
	@rmdir -p $(O_DIR) 2> /dev/null || echo "" > /dev/null
	@make -C $(LIBFT) clean

fclean: clean
	@rm $(NAME) 2> /dev/null || echo "" > /dev/null
	@make -C $(LIBFT) fclean

debug: _debug all

rebug: fclean debug

test: all
	@mkdir -p $(O_DIR)
	@gcc printf_test.c -L. -I. -lftprintf -o $(O_DIR)test_ftprintf
	@./$(O_DIR)test_ftprintf > $(O_DIR)a.diff
	@./$(O_DIR)test_ftprintf 2 > $(O_DIR)b.diff
	@diff -ayt -W 160 -- $(O_DIR)a.diff $(O_DIR)b.diff

_debug:
	$(eval FLAGS = -Wall -Wextra -g)
	$(eval DEBUG = 1)

re: fclean all

.PHONY: all clean fclean debug rebug _debug test re
