CPPC = g++
CC = gcc
INCLUDES_DIRECTORY = includes

CPPFLAGS = -I$(INCLUDES_DIRECTORY) -Werror -Wall -std=c++23 -MMD -MP
CFLAGS   = -I$(INCLUDES_DIRECTORY) -Werror -Wall -MMD -MP 
LDFLAGS = -lm -lwiringPi -lsqlite3

CPP_SOURCES := $(shell find src -name '*.cpp')
C_SOURCES   := $(shell find src -name '*.c'   )

OBJS := $(CPP_SOURCES:%.cpp=build/%.o) $(C_SOURCES:%.c=build/%.o)
DEPS := $(OBJS:.o=.d)

all: bin/executable

bin/executable: $(OBJS)
	@mkdir -p bin
	$(CPPC) $^ -o $@ $(LDFLAGS)

build/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CPPC) $(CPPFLAGS) -c $< -o $@

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build bin

-include $(DEPS)

.PHONY: all clean