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
		return -1;		//0���� �ص� �ǳ� 0���� ������ �Ͱ��� �ٸ� ����� �ǹ��ϹǷ� -1 ���. 
	}

	
	
	printf("%c\n", fgetc(fp));
	
	fclose(fp);
	
	 
	
	return 0;
}
