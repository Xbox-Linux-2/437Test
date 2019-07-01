TOPDIR := $(shell /bin/pwd)

CC = gcc
CFLAGS = -lncurses
TARGET = $(TOPDIR)/437Test.out

OBJS = $(TOPDIR)/main.obj
.PRECIOUS: %.obj

all: $(TARGET) objclean
	@echo "\n$(TARGET) created"

%.out: $(OBJS)
	@echo "[ LD ] $@"
	@$(CC) $(CFLAGS) -o '$@' $^

%.obj: %.c
	@echo "[ CC ] $@"
	@$(CC) $(CFLAGS) -c -o '$@' '$<'

clean:
	@rm -f $(TARGET)

objclean:
	@rm -f $(OBJS)