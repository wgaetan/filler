PHONY = all clean fclean re

NAME = wgaetan.filler

# **************************************************************************** #
#          PATH                                                                #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
LIBFT_PATH = ./libft/

# **************************************************************************** #
#           SRCS                                                               #
# **************************************************************************** #

LIB_NAME = libft.a

SRC_NAME = board_parsing.c find_best_answer.c get_data.c get_filler.c heat.c\
		   is_placeable.c main.c math.c piece_parsing.c player_id_parsing.c\
		   send_answer.c\

INC_NAME = filler.h

# **************************************************************************** #
#           VAR                                                                #
# **************************************************************************** #

OBJ_NAME= $(SRC_NAME:.c=.o)

INC = $(addprefix $(INC_PATH), $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
LIB = $(addprefix $(LIBFT_PATH), $(LIB_NAME))

# **************************************************************************** #
#           FLAG                         						               #
# **************************************************************************** #

ifndef FLAG
    FLAGS = -Wall -Wextra -Werror
endif

# **************************************************************************** #
#           REGLES                                                             #
# **************************************************************************** #

all : makelib $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ) $(INC) $(LIB)
	@printf "Compiling $(NAME)..."
	@gcc $(FLAGS) -o $@ $(OBJ) $(LIB)
	@printf "\033[32m[OK]\033[0m\n"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH) 2> /dev/null

makelib:
	@make -C libft/

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@gcc $(FLAGS) -I $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all
