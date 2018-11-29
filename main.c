#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char filename[100];
	
	FILE *fp;
	
	printf("Input a file name: ");
	scanf("%s", filename);
	
	fp = fopen(filename, "r");
	
	if (fp == NULL)
	{
		printf("ERROR. Different name, please.");
		return -1;		//0으로 해도 되나 0으로 끝나는 것과는 다른 결과를 의미하므로 -1 사용. 
	}

	
	
	printf("%c\n", fgetc(fp));
	
	fclose(fp);
	
	 
	
	return 0;
}
