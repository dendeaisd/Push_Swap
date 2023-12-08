# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 01:57:09 by fvoicu            #+#    #+#              #
#    Updated: 2023/12/04 14:32:11 by fvoicu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap
B_NAME	:= checker
CFLAGS	:= -g -Wall -Wextra -Werror -fsanitize=address
SAN_LDFLAGS = -L../LeakSanitizer -llsan -lc++ -Wno-gnu-include-next -I ../LeakSanitize

LIB		:= ./Lib

HEAD	:= -I ./include 
SRCS	:= $(wildcard src/*.c) \
			$(wildcard src/sort/*.c) \
			$(wildcard src/sort/optimizatons/post_sort/*.c) \
			$(wildcard src/stack/*.c) \
			$(wildcard src/stack/operations/*.c)
BSRC	:= $(wildcard src/bonus/*.c) \
			$(wildcard src/bonus/operations/*.c)

OBJ		:= ${SRCS:.c=.o}
BOBJ	:= ${BSRC:.c=.o}

GREEN		:= \033[0;32m
CYAN		:= \033[38;5;6m

UP			:= \033[A
CUT			:= \033[K
BEGIN		:= \033[0G
MAGENTA		:= \033[0;95m

all: LIB $(NAME)

%.o: %.c
	@printf "$(UP)$(BEGIN)$(CUT)Compiling: $<...\n$(BEGIN)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(UP)$(BEGIN)$(CUT)$(GREEN)Push_swap compiled succesfully!✅\n"
	
$(NAME): LIB $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB)/lib.a -o $(NAME)

LIB:
	@if [ ! -d ${LIB} ]; then \
		git clone https://github.com/dendeaisd/Lib.git ${LIB}; \
	fi
	@make --directory=Lib/
	@printf "\n"

bonus: LIB $(BOBJ)
	@$(CC) $(CFLAGS) $(filter-out src/sort/main.o, $(OBJ)) $(BOBJ) $(LIB)/lib.a -o $(B_NAME)
	
clean:
	@rm -rf $(OBJ)
	@rm -rf $(BOBJ)
	@printf "\n$(UP)$(BEGIN)$(CUT)$(CYAN)Objects removed successfully🧽\n"
	
fclean: clean
	@make fclean --directory=${LIB}
	@rm -rf $(LIB)
	@rm -rf $(NAME)
	@rm -rf $(B_NAME)
	@printf "\n"
	@printf "$(UP)$(BEGIN)$(CUT)$(CYAN)Push_swap removed successfully🚽✨\n"
	
re: clean all bonus

.PHONY: all LIB clean fclean re