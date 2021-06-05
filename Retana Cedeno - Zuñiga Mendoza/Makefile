# LPATH tells the linker where to find libraries
LPATH = -L/usr/openwin/lib -L/home/cs433/Fall00/Mesa-3.2.1/lib

# IPATH tells the compiler where to look for include files.
IPATH = -I/home/cs433/Fall00/Mesa-3.2.1/include

# GLLIBS are the GLUT and OpenGL (or Mesa) libraries needed by the linker.
GLLIBS = -lglut -lGLU -lGL

# XLIBS are the X libraries needed by the linker because GLUT and OpenGL
#       call X routines.
XLIBS = -lXi -lX11 -lXext

# MISCLIBS are miscellaneous libs that are needed by the linker.
# -lm denotes the math library.
MISCLIBS = -lm

LIBS = $(LPATH) $(GLLIBS) $(XLIBS) $(MISCLIBS)

CC=gcc
FILE=Proyecto1

&(FILE): $(FILE).c
	$(CC) $(FILE).c -o $(FILE) $(LIBS) -w
