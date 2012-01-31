# First target is default target, if you just type:  make

cache: main.o cache.o queue.o list.o queue_interface.o check_direct.o check_k_way.o
	gcc -o cache main.o cache.o queue.o list.o queue_interface.o check_k_way.o check_direct.o
main.o: main.c 
	gcc -c main.c 
cache.o: cache.c
	gcc -c cache.c
check_direct.o: check_direct.c
	gcc -c check_direct.c
check_k_way.o: check_k_way.c
	gcc -c check_k_way.c
list.o: list.c
	gcc -c list.c
queue.o: queue.c
	gcc -c queue.c
queue_interface.o: queue_interface.c
	gcc -c queue_interface.c
clean: 
	rm main.o cache.o list.o queue.o queue_interface.o cache

# 'make' will view $v as variable and try to expand it.
# By typing $$, make will reduce it to a single '$' and pass it to the shell.
# The shell will view $dir as a variable and expand it.
dist:
	dir=`basename $$PWD`; cd ..; tar cvf $$dir.tar ./$$dir; gzip $$dir.tar
	dir=`basename $$PWD`; ls -l ../$$dir.tar.gz
