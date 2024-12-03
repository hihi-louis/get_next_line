NAME = GNL
NAME_BN = GNL_BN 

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRCS = get_next_line.c \
		get_next_line_utils.c	\
		main.c
		
SRCS_BN = get_next_line_bonus.c	\
		get_next_line_utils_bonus.c	\
		main.c
			
OBJ = $(SRCS:.c=.o)

OBJ_BN = $(SRCS_BN:.c=.o)

all: $(NAME)

bonus:	.bonus

.bonus:	$(OBJ_BN)
	$(CC)	$(CFLAGS)	$(OBJ_BN)	-o	$(NAME_BN)

$(NAME):	$(OBJ)
	$(CC)	$(CFLAGS)	$(OBJ)	-o	$(NAME)

%.o:	%.c
	$(CC)	$(CFLAGS)	-c	$<	-o	$@

clean:
	rm	-f	$(OBJ)	$(OBJ_BN)	.bonus

fclean:	clean
	rm	-f	$(NAME)	$(NAME_BN)

re:    fclean    all

.PHONY:    all    clean    fclean    re    bonus
