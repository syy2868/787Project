CC = gcc 
CFLAGS = -w 

INCLUDES = 
LDFLAGS = 
LIBS = 

TARGET = Train_Gate
C_SOURCES =  \
            Train_Gaterun.c  \
            Controller.c  \
            Train2.c  \
            Train1.c  \
            Timer.c  \
            Plant.c  \
            Gate.c  \
            Train_Gate.c 
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
