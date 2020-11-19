TAR=minishell
OBJ=myshell.o prompt.o
CC:=gcc

$(TAR):$(OBJ)
	$(CC) $^ -o $@
%.o:%.c
	$(CC) -c $^ -o $@
#%.o:%.c 
#	$(CC) -c %.c -o %.o
#main.o:main.c
#	$(CC) -c main.c -o main.o
#sum.o:sum.c
#	$(CC) -c sum.c -o sum.o
.PHONY:
clears:
	rm -fr $(OBJ)
clearall:
	rm -fr $(OBJ) $(TAR)
