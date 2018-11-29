#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int fget_word(FILE *fp, char *word);
int is_whitespace(char *word[int cnt]);

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
	
	
	printf("Input a word you want to find: ");
	scanf("%s", word);
	
	while (fget_word(fp, word) != 0)
	{
		printf("%s\n", word);
	}
	
	
	fclose(fp);
	
	return 0;
}

int fget_word(FILE *fp, char *word) {
	
	int cnt;
	char c;
	
	while ( (c=fgetc(fp)) != EOF )
	{
		if (is_whitespace(word) == 0)
			break;
	}
	if (c == EOF)
		return 0;
	
	cnt = 0;
	word[cnt++] = c;
	word[cnt] = '\0';
	
	while ( (word[cnt]=fgetc(fp)) != EOF) {
		if ( is_whitespace(word[cnt]) == 1 ) 
		{
			word[cnt] = '\0';
			break;
		}
		cnt++;
	}
	
	return cnt;	
}
