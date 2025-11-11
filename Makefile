CC = clang
CFLAGS = -Wall -Werror -g

OUT_DIR = build
OUT = $(OUT_DIR)/bin

SRC_DIR = src
SRCS = $(wildcard $(SRC_DIR)/*.c) 
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OUT_DIR)/%.o, $(SRCS)) 

all: prepare link

run: prepare link
	./$(OUT)

prepare: 
	@mkdir -p $(OUT_DIR)

# Compile to object files
$(OUT_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Produce executable from object files
link: $(OBJS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS)

clean:
	rm -rf $(OBJS) $(OUT_DIR)
