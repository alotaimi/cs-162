CC=g++
exe_file=a.out

$(exe_file): test_linked_list.cpp linked_list.o node.o
	$(CC) test_linked_list.cpp linked_list.o node.o -o $(exe_file)

linked_list.o: linked_list.cpp linked_list.h
	$(CC) -c linked_list.cpp
node.o: node.cpp node.h
	$(CC) -c node.cpp

clean: 
	rm -f *.o $(exe_file)