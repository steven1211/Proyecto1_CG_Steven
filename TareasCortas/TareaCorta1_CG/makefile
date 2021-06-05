OBJECTS=mesa_example.o
OUTPUT=mesa_example
CC=gcc

CFLAGS = -g -Wall
LDLIBS= -lglut -lGLU -lGL -lm -lXext
LDFLAGS=-L/usr/local/lib 

$(OUTPUT): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(OBJECTS) $(LDFLAGS) $(LDLIBS)

$(OBJECTS): mesa_example.h

clean:
	rm -f *.o
	rm -f mesa_example
