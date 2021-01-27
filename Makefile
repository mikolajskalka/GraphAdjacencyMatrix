CC = g++
CFLAGS = -Werror -Wall
DIR = `basename $(CURDIR)`

all: main
	./main

main: main.o
	$(CC) $(CFLAGS) main.o -o main

main.o: main.cpp RandomBinaryTree.h
	$(CC) $(CFLAGS) -c  main.cpp

# singlelist.o: singlelist.cpp singlelist.h
# 	$(CC) $(CFLAGS) -c singlelist.cpp

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )

zip: clean
	( cd ../; zip -r $(DIR).zip $(DIR) )


clean:
	rm -f *.o main