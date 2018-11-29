#include <stdio.h>
#include <stdlib.h>

#include "keyword.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	
	FILE *fp;
	char filename[100];
	char word[100];
	
	printf("Input a file name: ");
	scanf("%s", filename);
	
	fp = fopen(filename, "r");
	
	if (fp == NULL)
	{
		printf("ERROR. Different name, please.");
		return -1;		//0으로 해도 되나 0으로 끝나는 것과는 다른 결과를 의미하므로 -1 사용. 
	}
	

	
	while (fget_word(fp, word) != 0)
	{
		count_word(word);
	}
	
	print_word();
	
	fclose(fp);
	
	return 0;
}

int fget_word(FILE *fp, char *word) {
	
	int cnt;
	char c;
	
	while ( (c=fgetc(fp)) != EOF )
	{
		if (is_whitespace(c) == 0) //유의미한 문자이면 나감 
			break;
	}
	if (c == EOF) //최초 읽은 문자가 마지막일 때 
		return 0;
	
	//본격적으로 단어를 한 글자씩 읽음 
	cnt = 0;
	word[cnt++] = c;
	word[cnt] = '\0';
	
	while ( (word[cnt]=fgetc(fp)) != EOF) {
		if ( is_whitespace(word[cnt]) == 1 ) //공백문자면 받은거 취소하고 나감 
		{
			word[cnt] = '\0';
			break;
		}
		cnt++;
	}
	
	return cnt;	
}

int is_whitespace(char c) {

	if (c == ' ' ||
		c == '\t' ||
		c == '\n' ||
		c == '\r' ||
		c == '(' ||
		c == ')' ) 
	return 1; //공백 글자다.
	
	return 0; //유의미한 글자다.	
}

