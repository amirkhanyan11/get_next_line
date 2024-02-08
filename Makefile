
EXEC = get_next_line.out

ROOT = ./
SRCSPATH = ./srcs/
OBJSPATH = ./objs/
DEPPATH = ./dependencies/
INCPATH = ./includes/

SRCS = $(wildcard $(SRCSPATH)*.c)
OBJS = $(patsubst $(SRCSPATH)%.c,$(OBJSPATH)%.o,$(SRCS))
DEPS = $(patsubst $(OBJSPATH)%.o,$(DEPPATH)%.d,$(OBJS))
MAIN = ./main/main.c


CC = cc
DEPFLAGS = -MP -MD
CFLAGS = -Wall -Wextra -Werror $(foreach H,$(INCPATH),-I$(H))

GITCLONE = git clone
TRIPOULLE = git@github.com:Tripouille/printfTester.git
SANTA = git@github.com:paulo-santana/ft_printf_tester.git


all : $(EXEC)

$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) $(MAIN) $< -o $@


$(OBJSPATH)%.o : $(SRCSPATH)%.c
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@
	mv $(OBJSPATH)*.d $(DEPPATH)

gt :
	$(GITCLONE) $(TRIPOULLE) ./tripoulle
	$(GITCLONE) $(SANTA) ./santa

dt :
	rm -rf ./tripoulle ./santa

ut : dt gt


clean :
	rm -f $(OBJS) $(DEPS)

fclean : clean
	rm -f $(EXEC) $(SHARED)

re : fclean all

.PHONY : all clean fclean re gt dt ut

-include $(DEPS)
