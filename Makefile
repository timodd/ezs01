CFLAGS += -W -Wall -Wextra -std=c11

all:	demos

demos:	processmodel.c queue.c process.c

clean:
	$(RM) demos *.o
