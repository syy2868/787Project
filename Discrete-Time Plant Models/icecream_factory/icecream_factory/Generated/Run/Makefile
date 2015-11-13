CC = gcc 
CFLAGS = -w 

INCLUDES = 
LDFLAGS = 
LIBS = 

TARGET = icecream_factory
C_SOURCES =  \
            icecream_factoryrun.c  \
            TRDC.c  \
            icecream_factory.c  \
            Controller.c  \
            carousel_belt.c  \
            detection.c  \
            Plant.c  \
            diverter.c 
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
