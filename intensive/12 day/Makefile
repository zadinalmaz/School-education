GCCC = gcc -c -std=c11 -Wall -Werror -Wextra
GCC = gcc -std=c11 -Wall -Werror -Wextra

all: print_module 

rebuild: clean print_module 

print_module.o: print_module.c
	$(GCCC) print_module.c -o print_module.o

print_module: print_module.o main_module_entry_point.o
	$(GCC) print_module.o main_module_entry_point.o -o ../build/Quest_1

main_module_entry_point.o: main_module_entry_point.c
	$(GCCC) main_module_entry_point.c -o main_module_entry_point.o


clean: cleanlibs cleanbuild

cleanlibs:
	rm -rf *.o

cleanbuild:
	rm -rf ../build/*
	rm -rf *.so
	rm -rf *.a
