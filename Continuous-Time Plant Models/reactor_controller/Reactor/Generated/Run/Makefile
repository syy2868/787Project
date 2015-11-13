CC = gcc 
CFLAGS = -w 

INCLUDES = 
LDFLAGS = 
LIBS = 

TARGET = reactor
C_SOURCES =  \
            reactorrun.c  \
            ytimer1.c  \
            controller.c  \
            reactor.c  \
            ytimer2.c  \
            plant.c 
RM = rm -f

.PHONY: all clean cleanall

all: $(TARGET)

$(TARGET): $(C_SOURCES) Makefile
	$(CC) $(CFLAGS) $(INCLUDES) $(C_SOURCES) $(LDFLAGS) $(LIBS) -o $(TARGET)

clean:
	$(RM) *.o

cleanall:
	$(RM) *.o
	$(RM) $(TARGET)
	$(RM) $(TARGET).exe
