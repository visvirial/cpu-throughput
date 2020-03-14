CFLAGS  = -ggdb -W -Wall -O0 -std=gnu99
LDFLAGS = 
LDLIBS  = 

TARGET = cpu-throughput
OBJS = $(TARGET).o

.PHONY: all clean

all: $(TARGET)

clean:
	$(RM) $(TARGET) *.o

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

