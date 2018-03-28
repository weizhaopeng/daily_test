#include "fun_in_struct.h"

int main(int argc, char **argv)
{
	/*
	data_store_object *obj;
	char 			  *word;

	word = "nihao";
	obj	 = calloc(1, sizeof(data_store_object));
	obj->word  = word;
	obj->count = 24;

	obj->word_print  = WordPrint;
	obj->count_print = CountPrint;

	obj->word_print(obj->word);
	printf("%d\n",obj->count_print(obj->count));
	return 0;
	*/

	/*
	data_store_object obj = {
		.word  = "nihao",
		.count = 12,
		.word_print  = WordPrint,
		.count_print = CountPrint
	};

	obj.word_print(obj.word);
	printf("%d\n",obj.count_print(obj.count));
	return 0;
	*/

	/*
	data_store_object obj = {
		word  : "nihao",
		count : 33,
		word_print  : WordPrint,
		count_print : CountPrint
	};

	obj.word_print(obj.word);
	printf("%d\n",obj.count_print(obj.count));
	return 0;
	*/

	data_store_object *obj = {
		->word  = "nihao",
		->count = 34,
		->word_print  = WordPrint,
		->count_print = CountPrint
	};

	obj->word_print(obj->word);
	printf("%d\n",obj->count_print(obj->count));
	return 0;

}

