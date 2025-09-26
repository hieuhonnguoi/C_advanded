# Trình biên dịch
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Các file nguồn và đối tượng
SRCS = main.c sensors.c actuators.c buttons.c watering_logic.c
OBJS = $(SRCS:.c=.o)

# Tên chương trình
TARGET = spws

# Rule mặc định: build chương trình
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Rule biên dịch từng file .c thành .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Xoá file build
clean:
	rm -f $(OBJS) $(TARGET)
