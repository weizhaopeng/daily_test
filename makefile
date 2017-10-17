
shixian:shixian.o sort.o
	gcc sort.o shixian.o -o shixian

shixian.o:shixian.c head_file.h
	gcc -c shixian.c

sort.o:sort.c head_file.h
	gcc -c sort.c 

clean:
	rm shixian.o sort.o 

