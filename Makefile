# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 10:00:18 by nseon             #+#    #+#              #
#    Updated: 2025/01/23 13:38:11 by nseon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	push_swap

# ---------------FILES--------------- #

MAKE_DIR	=	.make/

SRC_DIR		=	src/

OBJ			=	$(patsubst %.c, $(MAKE_DIR)%.o, $(SRC))

DEP			=	$(patsubst %.c, $(MAKE_DIR)%.d, $(SRC))

# ---------------MAIN---------------- #

SRC			=	push_swap.c

# ---------------MOVES--------------- #

SRC			+=	$(addprefix $(MOVES_DIR), $(MOVES_SRC))

MOVES_DIR	=	moves/

MOVES_SRC	=	push_moves.c\
				reverse_rotate_moves.c\
				rotate_moves.c\
				shift_utils.c\
				swap_moves.c\

# -------------SORTING--------------- #

SRC			+=	$(addprefix $(SORT_DIR), $(SORT_SRC))

SORT_DIR	=	sorting/

SORT_SRC	=	presort.c\
				sort.c

# -----------LIBS / INCLUDES--------- #

LIB_DIR 	=	lib/
LIB_PATH	=	Libft/libft.a
LIB_PATH	:=	$(addprefix $(LIB_DIR), $(LIB_PATH))
LIB			=	$(patsubst lib%.a, %, $(notdir $(LIB_PATH)))

INC_DIR 	=	includes/
INCLUDES	=	$(INC_DIR)\
				$(addsuffix $(INC_DIR), $(dir $(LIB_PATH)))

# --------------CONFIGS-------------- #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	-MMD -MP $(addprefix -I, $(INCLUDES))

LDFLAGS		+=	$(addprefix -L, $(dir $(LIB_PATH)))
LDLIBS		+=	$(addprefix -l, $(LIB))

# --------------TARGETS-------------- #

.PHONY: all
all: $(NAME)

$(NAME): $(LIB_PATH) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@

$(MAKE_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(LIB_PATH): force
	$(MAKE) -C $(@D)

.PHONY: norminette
norminette:
	norminette $(LIB_DIR) $(INC_DIR) $(SRC_DIR)

.PHONY: clean
clean:
	-for lib in $(dir $(LIB_PATH)); do $(MAKE) -s -C $$lib $@; done
	rm -rf $(MAKE_DIR)

.PHONY: fclean
fclean:
	-for lib in $(dir $(LIB_PATH)); do $(MAKE) -s -C $$lib $@; done
	rm -rf $(NAME) $(MAKE_DIR)

.PHONY: re
re: fclean
	$(MAKE)

.PHONY: force
force:

-include $(DEP)

.DEFAULT_GOAL := all
