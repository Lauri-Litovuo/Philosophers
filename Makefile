NAME = philo
BNAME = .philo_b


S = srcs/
O = objs/
I = incl/
B = bonus/
BO = bonus_objs/

all: $(NAME)

#bonus: $(BNAME)


.PHONY: all clean fclean re bonus

CC = cc
CFLAGS += -Wall -Wextra -Werror -pthread -I$I
LDFLAGS += 

######################
##		MANDATORY 	##
######################

SRC = \
		$Smain.c

OBJ = $(SRC:$S%=$O%.o)

$O:
	@mkdir -p $@
	@echo "Making obj dir and files.."

$(OBJ): | $O

$O%.o: $S%
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "Project ready for use."

######################
##		BONUS		##
######################

#SRC_B = \

#OBJ_B = $(SRC_B:$B%=$(BO)%.o)

# $(BO):
#	@mkdir -p $@
#	@echo "Making obj dir and files.."

#$(OBJ_B): | $(BO)

#$(BO)%.o: $B%
#	@$(CC) $(CFLAGS) -c $< -o $@

#$(BNAME): $(OBJ_B)
#	@$(CC) $(CFLAGS) $^ -o $@
#	@cp -f .pipex_b pipex 
#	@echo "Bonus ready for use."

######################
##		DEBUG		##
######################

DEBUG_NAME = debug.out

debug: $(DEBUG_NAME)

DEBUG_FLAGS = -g -fsanitize=address,undefined,integer

$(DEBUG_NAME): $(OBJ) $(LIBFT)
	@$(CC) $(DEBUG_FLAGS) $(CFLAGS) $^ -o $@
	@echo "Debug ready for use."

cleandebug: fclean
	@rm -f $(DEBUG_NAME)
	@echo "debug.out removed"

#LIBFT

$(LIBFT): $L
	@make -C $L

cleanobj:
	@rm -f $(wildcard $(OBJ))

cleanobjdir: cleanobj
	@rm -rf $O

#cleanbonus:
#	@rm -f $(wildcard $(OBJ_B))

#cleanobjbdir: cleanbonus
#	@rm -rf $(BO)


clean: cleanobjdir cleanlibft cleanobjbdir
	@echo "Cleaning object files and libft"

#fclean: clean cleanbonus
#	@rm -f $(NAME) $(BNAME)
#	@echo "Project file removed"

re: fclean all