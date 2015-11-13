CC = gcc 
CFLAGS = -w 

INCLUDES = 
LDFLAGS = 
LIBS = 

TARGET = WaterTankSystem
C_SOURCES =  \
            WaterTankSystemrun.c  \
            Plant.c  \
            DigitalController.c  \
            WaterTank.c  \
            WaterTankSystem.c  \
            GasBurner.c 
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
