CC = gcc 
DEBUG = -O

CFLAGS = $(DEBUG) 

LIBS =  -lXm -lXt -lX11  -lm

TARGETS= drcf xwdraw pydraw

all: $(TARGETS)

drcf: drcf.o
	$(CC) $(CFLAGS) -o $@ $@.o $(LIBS)
xwdraw: xwdraw.o
	$(CC) $(CFLAGS) -o $@ $@.o $(LIBS)
pydraw:
	python3 -O -c 'import pydraw'
	mv __pycache__/pydraw.cpython-34.pyo pydraw.pyo

clean:
	rm -f *.o *~* *.a  *pyo
	rm -f $(TARGETS)

