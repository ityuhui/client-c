INCLUDE:=-I../include -I../model -I../api
LIBS:=-L../build -lkubernetes -lpthread -lssl -lz
CFLAGS:=-g

all:
	gcc main.c $(CFLAGS) $(INCLUDE) $(LIBS) -o main
clean:
	rm main
