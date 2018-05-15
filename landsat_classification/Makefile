ELF = bin/main.elf

LIBS_PATH=../libs

INC+= -I.
INC+= -I$(LIBS_PATH)

LIBS+= $(LIBS_PATH)/libs_nn.a
LIBS+= $(LIBS_PATH)/libs_dataset.a
LIBS+= $(LIBS_PATH)/libs_common.a

CC = g++
LD = g++
OBJCOPY = objcopy
OBJDUMP = objdump
SIZE = size

# DEGUBFLAGS = -g -pg

CFLAGS = $(DEGUBFLAGS) -O2 -Os -s -Wall -Wextra -pedantic -std=c++11 $(INC)

LDFLAGS = $(DEGUBFLAGS) -lm -lpthread -pthread -std=c++11 -lglut -lGL -lGLU -lX11 -lSOIL -ljsoncpp -L/usr/local/cuda/lib64 -lcuda -lcudart


SRCS+= $(shell find -name '*.cpp')
OBJS = $(SRCS:.cpp=.o)

all: $(ELF)
	$(SIZE) $(ELF)

$(ELF): $(LIBS) $(OBJS)
	$(LD) -o $@ $(OBJS) $(OBJS_CUDA) $(LIBS) $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm $(OBJS) -rf
	rm $(ELF) -rf
