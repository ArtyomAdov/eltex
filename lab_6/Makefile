CC = gcc

COMPILE_FLAGS = -Wall -Werror -std=gnu99 -O0

SOURCE_PATH = src

BUILD_PATH = build

BINARY_PATH = bin

EXTENSION_FILE_C_CODE = .c

EXTENSION_FILE_OBJECT = .o

BINARY_KEY_START = key

SOURCES = $(shell find $(SOURCE_PATH)/ -name '*$(EXTENSION_FILE_C_CODE)')

OBJECTS = $(SOURCES:$(SOURCE_PATH)/%$(EXTENSION_FILE_C_CODE)=$(BUILD_PATH)/%$(EXTENSION_FILE_OBJECT))

.PHONY: clean all make_path run

all: make_path $(BINARY_PATH)/$(BINARY_KEY_START)

$(BINARY_PATH)/$(BINARY_KEY_START): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(BINARY_PATH)/$(BINARY_KEY_START)

$(BUILD_PATH)/%$(EXTENSION_FILE_OBJECT): $(SOURCE_PATH)/%$(EXTENSION_FILE_C_CODE)
	$(CC) $(COMPILE_FLAGS) $< -c -o $@

make_path:
	mkdir $(BUILD_PATH) -p
	mkdir $(BINARY_PATH) -p

clean:
	-rm -rf $(BUILD_PATH) $(BINARY_PATH)

run:
	./$(BINARY_PATH)/$(BINARY_KEY_START)