CC		=	gcc 
RM		= rm -rf 

#LIBS = -lsocket -lnsl

PROGS = panserver panclient audclient 

all: $(PROGS)

panserver:  panserver.o
	$(CC)  -o panserver panserver.c $(LIBS)
panclient:  panclient.o
	$(CC)  -o panclient panclient.c $(LIBS)
audclient:  audclient.o
	$(CC)  -o audclient audclient.c $(LIBS)
clean:;
	$(RM) $(PROGS) *.o core 
