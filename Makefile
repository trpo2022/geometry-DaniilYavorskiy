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
