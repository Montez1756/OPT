SRC := $(wildcard *.c)
C := gcc
TARGET := OPT.exe

$(TARGET) : $(SRC)
	$(C) -o $@ $^

clean:
	rm -rf $(TARGET)