SRC := $(wildcard *.c)
OBJS := $(SRC:.c=.o)
C := gcc
TARGET := OPT.dll

$(TARGET) : $(OBJS)
	$(C) -shared -o $@ $^ -Wl,--out-implib,libmessage.a
*.o : *.c
	$(C) -v -c -DBUILD_DLL $< -o $@
clean:
	rm -rf $(TARGET) $(OBJS)
