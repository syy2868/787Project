CC = gcc 
CFLAGS = -w -D___ALTSIM___ 

INCLUDES = 
LDFLAGS = 
LIBS = 

TARGET = detection
C_SOURCES =  \
            detectionsim.c  \
            datatypes.c \
            detection.c  \
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
