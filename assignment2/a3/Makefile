CC		=	gcc 
RM		= rm -rf 

#LIBS = -lsocket -lnsl

PROGS = tserver tclient xcmd

all: $(PROGS)

tserver:  tserver.o
	$(CC)  -o tserver tserver.c $(LIBS)
tclient:  tclient.o
	$(CC)  -o tclient tclient.c $(LIBS)
xcmd:  xcmd.o
	$(CC)  -o xcmd xcmd.c $(LIBS)
clean:;
	$(RM) $(PROGS) *.o core 
