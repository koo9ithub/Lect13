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
		return -1;		//0���� �ص� �ǳ� 0���� ������ �Ͱ��� �ٸ� ����� �ǹ��ϹǷ� -1 ���. 
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
		if (is_whitespace(c) == 0) //���ǹ��� �����̸� ���� 
			break;
	}
	if (c == EOF) //���� ���� ���ڰ� �������� �� 
		return 0;
	
	//���������� �ܾ �� ���ھ� ���� 
	cnt = 0;
	word[cnt++] = c;
	word[cnt] = '\0';
	
	while ( (word[cnt]=fgetc(fp)) != EOF) {
		if ( is_whitespace(word[cnt]) == 1 ) //���鹮�ڸ� ������ ����ϰ� ���� 
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
	return 1; //���� ���ڴ�.
	
	return 0; //���ǹ��� ���ڴ�.	
}

