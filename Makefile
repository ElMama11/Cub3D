NAME = cube
GCCF = gcc -Wall -Werror -Wextra -g3
GREEN       = \033[32m
RED         = \033[31m
DEFAULT     = \033[37m
PATHOBJ = obj/
PATHSRC = src/
INCLUDE_PATH=include/
DEP = Makefile src/$(INCLUDE_PATH)/cube.h
SRC =   main.c	\
		init.c
LIBFT = libft/libft.a
MLX = -Lmlx_linux -lmlx_Linux -L /usr/lib -Imlx_linux -lXext -lX11 -lm -lz
HEAD = -I ./src/$(INCLUDE_PATH)/ -I /usr/include
OBJ = $(patsubst %.c,$(PATHOBJ)/%.o,$(SRC))
ECHO = echo

all: $(NAME)

libft:
	@make -C libft/

$(PATHOBJ):
	@mkdir -p $(PATHOBJ)

$(NAME): $(PATHOBJ) $(addprefix $(PATHSRC)/,$(SRC)) $(OBJ)
	@$(ECHO) "\r$(GREEN) The .o from $(NAME) are compiled.$(DEFAULT)"
	@$(GCCF) $(OBJ) $(MLX) -o $(NAME)
	@$(ECHO) "$(GREEN)$(NAME)$(DEFAULT) created."

$(PATHOBJ)/%.o: $(PATHSRC)/%.c $(DEP)
	@$(ECHO) "\r$(GREEN) Compiling $<                 \c\033[K"
	@$(GCCF) $(HEAD) -Imlx_linux -c $< -o $@

clean:
	@$(ECHO) "All $(RED).o$(DEFAULT) are now deleted for $(NAME)."
	@rm -rf $(PATHOBJ)

fclean: clean
	@$(ECHO) "$(RED)$(NAME)$(DEFAULT) is now deleted."
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libft