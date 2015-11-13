CC = gcc 
CFLAGS = -w -D___ALTSIM___ 

INCLUDES = 
LDFLAGS = 
LIBS = 

TARGET = Train1
C_SOURCES =  \
            Train1sim.c  \
            datatypes.c \
            Train1.c  \
            Simulation.c
RM = rm -f

.PHONY: all clean cleanall

all: $(TARGET)

$(TARGET): $(C_SOURCES) Makefile
	$(CC) $(CFLAGS) $(INCLUDES) $(C_SOURCES) $(LDFLAGS) libmxml.a $(LIBS) -o $(TARGET)

clean:
	$(RM) *.o

cleanall:
	$(RM) *.o
	$(RM) $(TARGET)
	$(RM) $(TARGET).exe
