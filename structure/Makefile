obj=link_list_main.o link_list_creat.o link_list_insert.o link_list_delete.o link_list_print.o

LINK_LIST:$(obj)
	 gcc -g $(obj) -o LINK_LIST

link_list_main.o:link_list_main.c link_list_creat.c link_list_print.c link_list_insert.c link_list_delete.c struct.h

link_list_print.o:link_list_print.c struct.h

link_list_insert.o:link_list_insert.c struct.h

link_list_creat.o:link_list_creat.c struct.h

link_list_delete.o:link_list_delete.c struct.h

.PHONY:clean
clean:
	rm $(obj)

