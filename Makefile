NOC			= \033[0m
BOLD		= \033[1m
UNDERLINE	= \033[4m
BLACK		= \033[1;30m
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
WHITE		= \033[1;37m

LIBFT_PATH	= libraries/libft
LIBFT		= $(LIBFT_PATH)/libft.a

SOURCE_FILES =

PATH_SOURCES = sources
SOURCES_MS	 = $(addprefix $(PATH_SOURCES)/, $(SOURCE_FILES))
OBJ_SOURCES  = $(SOURCES_MS:.c=.o)

HEADER		= $(PATH_SOURCES)/minishell.h
NAME		= minishell

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g3
RM			= rm -rf

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(LIBFT_PATH)

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJ_SOURCES) $(HEADER)
			$(CC) $(CFLAGS) $(OBJ_SOURCES) $(LIBFT) -o $(NAME)

$(LIBFT):
			$(MAKE) -C $(LIBFT_PATH)
			$(MAKE) -C $(LIBFT_PATH) bonus

clean:
			$(MAKE) -C $(LIBFT_PATH) clean
			$(RM) $(OBJ_SOURCES)

fclean:		clean
			$(MAKE) -C $(LIBFT_PATH) fclean
			$(RM) $(NAME)

re:			clean fclean all

.PHONY:		all clean fclean re .c.o
