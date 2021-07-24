BUILD_DIR=../build
CC=/usr/bin/gcc
CC_FLAGS=-m32 -c
LD=/usr/bin/ld
RM=rm -f -r

src = $(wildcard *.c)
obj = $(src:.c=.o)

object = $(addprefix $(BUILD_DIR)/,$(obj))

all: $(obj)

%.o: %.c
	$(CC) -m32 -o $(addprefix $(BUILD_DIR)/, $@) -c $^

clean:
	${RM} *.o

