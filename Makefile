<<<<<<< HEAD
CFLAGS = -Wall -Wextra -Werror
CCFLAGS = -Wall -Wextra -Wshadow -Wno-unused-parameter

all: bin/main

obj/src/main/test2.o: test/test2.c
	gcc -c $(CCFLAGS) -o $@ $< -lm

obj/src/main/glavnuy_test2.o: test/glavnuy_test2.c
	gcc -c $(CCFLAGS) -o $@ $< -lm

test2: obj/src/main/test2.o obj/src/main/glavnuy_test2.o
	gcc $(LDLAGS) -o $@ $^ -lm -o bin/test_2 

obj/src/main/test1.o: test/test1.c
	gcc -c $(CCFLAGS) -o $@ $< -lm

obj/src/main/glavnuy_test.o: test/glavnuy_test.c
	gcc -c $(CCFLAGS) -o $@ $< -lm

test: obj/src/main/test1.o obj/src/main/glavnuy_test.o
	gcc $(LDLAGS) -o $@ $^ -lm -o bin/tests 

bin/main: obj/src/main/main.o obj/src/libmake/libmake.a
	gcc $(CFLAGS) -o $@ $^ -lm

obj/src/main/main.o: src/main/main.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/libmake/libmake.a: obj/src/libmake/functions.o 
	ar rcs $@ $^

obj/src/libmake/functions.o: src/libmake/functions.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm


.PHONY: clean

clean:
	rm obj/src/libmake/*.a obj/src/libmake/*.o bin/main
||||||| empty tree
=======
CC = gcc

APP_NAME = geometry
LIB_NAME = libgeo
TEST_NAME = test

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I src -MP -MMD
LDFLAGS =
LDLIBS =

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test

APP_PATH = $(BIN_DIR)/$(APP_NAME)
TEST_PATH = $(BIN_DIR)/$(TEST_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a

SRC_EXT = c

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

TEST_SOURCES = $(shell find $(TEST_DIR) -name '*.$(SRC_EXT)')
TEST_OBJECTS = $(TEST_SOURCES:$(TEST_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(TEST_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d) $(TEST_OBJECTS:.o=.d)



.PHONY: test clean
all: $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS) -lm

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -I thirdparty $< -o $@ -lm












test: $(TEST_PATH)

-include $(DEPS)

$(TEST_PATH): $(TEST_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) -I thirdparty $^ -o $@ $(LDFLAGS) $(LDLIBS) -lm

clean:
	$(RM) $(APP_PATH) $(TEST_PATH) $(LIB_PATH)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;
>>>>>>> 3ca4c74cf3db42485d963a5c7f016bc53c140ec2
