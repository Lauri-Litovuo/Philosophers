NAME = philo


S = srcs/
O = objs/
I = incl/

all: $(NAME)

#bonus: $(BNAME)


.PHONY: all clean fclean re

CC = cc
CFLAGS += -Wall -Wextra -Werror -pthread -I$I
LDFLAGS += 

######################
##		MANDATORY 	##
######################

SRC = \
		$Smain.c \
		$Serrors.c \
		$Scheck_and_alloc_input.c \

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


cleanobj:
	@rm -f $(wildcard $(OBJ))

cleanobjdir: cleanobj
	@rm -rf $O


clean: cleanobjdir
	@echo "Cleaning object files"

fclean: clean 
	@rm -f $(NAME)
	@echo "Project file removed"

re: fclean all