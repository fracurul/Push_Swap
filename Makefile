# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 18:17:19 by fracurul          #+#    #+#              #
#    Updated: 2024/05/02 13:45:58 by fracurul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################################
#                LIB NAME               #
#########################################

PUSH_SWAP = push_swap
CHECKER = checker
LIBFT = libft/libft.a
SRC_LIBFT = libft/

#########################################
#              COMPILATOR               #
#########################################

CC = gcc

#########################################
#           COMPILATOR FLAGS            #
#########################################

FLAGS = -Wall -Wextra -Werror -g

#########################################
#           LIB FUNCTIONS               #
#########################################

SRC = swap_movements.c rotate_movements.c reverse_rotate_movements.c push_movements.c \
push_swap.c parsing.c parsing_utils.c node_utils.c stack_utils.c stack_utils2.c \
algorithm.c algorithm_utils.c algorithm_utils2.c algorithm_utils3.c \

#########################################
#               OBJECTS                 #
#########################################

OBJ = $(SRC:.c=.o)

OBJBONUS = $(SRCBONUS:.c=.o)

#########################################
#            CLEAN FUNCTION             #
#########################################

CLEAN = rm -rf

#########################################
#              COMPILE ALL              #
#########################################

all: $(PUSH_SWAP)

#########################################
#          COMPILE PUSH_SWAP            #
#########################################

$(PUSH_SWAP) : $(OBJ)
	@echo "#########################################"
	@echo "#         Compiling Push_swap..         #"
	@echo "#########################################"
	@$(MAKE) -C $(SRC_LIBFT)
	@$(CC) $(FLAGS) $(OBJ) -o $(PUSH_SWAP) -L ./libft -lft

#########################################
#             COMPILE BONUS             #
#########################################

bonus : $(OBJBONUS) $(OBJ)
	@echo "#########################################"
	@echo "#      Compiling BONUS Push_swap..      #"
	@echo "#########################################"
	@$(CC) $(FLAGS) $(OBJBONUS) $(OBJ) -o $(CHECKER) -L ./libft -lft

#########################################
#           COMPILE .c to .o            #
#########################################

%.o: %.c
	@$(CC) -I ./ $(FLAGS) -c -o $@ $<



#########################################
#              DELETE .o                #
#########################################

clean:
	@$(MAKE) clean -C $(SRC_LIBFT)
	@$(CLEAN) $(OBJ) $(OBJBONUS)
	@echo "files deleted"

#########################################
#              DELETE ALL               #
#########################################
fclean : clean
	@$(MAKE) fclean -C $(SRC_LIBFT)
	@$(CLEAN) $(PUSH_SWAP) $(CHECKER)
	@echo "program deleted"

#########################################
#         DELETE ALL & REMAKE           #
#########################################

re: fclean all

.PHONY: all bonus re clean fclean