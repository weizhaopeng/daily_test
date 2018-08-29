#include <stdio.h>
#include <string.h>

typedef struct {
    char ch;
	    int  num;
		} string;


		int main(int argc, char **argv) {
		    char str[100];
			    string str_buffer;
				    int cur_len = 1;
					    char ch_temp = '\0';
						    
							    str_buffer.ch = '\0';
								    str_buffer.num = 0;
									    
										    scanf("%s", str);
											    for (int i = 0; i < strlen(str)-1; i++) {
												        if (str[i+1] == str[i]) {
														            cur_len++;
																	            ch_temp = str[i];
																				        }
																						        else {
																								            if (cur_len > str_buffer.num || (cur_len == str_buffer.num && ch_temp < str_buffer.ch)) {
																											                str_buffer.ch = ch_temp;
																															                str_buffer.num = cur_len;
																																			            }
																																						ch_temp ='\0';
																																						cur_len = 0;
																																						        }
																																								    }
																																									    for(int i = 0; i < str_buffer.num; i++) {
																																										        printf("%c", str_buffer.ch);
																																												    }
																																													    return 0;
																																														}
