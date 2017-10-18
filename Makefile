
shixian:shixian.o sort.o
	gcc sort.o shixian.o -o shixian

shixian.o:shixian.c head_file.h
sort.o:sort.c head_file.h
.PHONY:clean
clean:
	-rm shixian.o sort.o 

