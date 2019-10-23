INCLUDE:=-I../include -I../model -I../api
LIBS:=-L../build -lkubernetes -lpthread -lssl -lz

all:
	gcc main.c $(INCLUDE) $(LIBS) -o main
clean:
	rm main
