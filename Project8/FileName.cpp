#pragma warning(disable:4996)
#define_CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

//무슨일을 하는 함수인지 실행해보고 주석작성
void clear_input_buffer(void)
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
	{
		;
	}
}

int main(void)
{
	char str1[100];
	char str2[100];
	char copy[100];
	char sentence[200];
	char temp[200];

	char* pos;
	char ch;

	char* p_str1 = str1;
	char* p_str2 = str2;
	char* p_copy = copy;
	char* p_sentence = sentence;
	char* p_temp = temp;

	printf("Enter first string(no spaces)");
	scanf_s("%99s", p_str1);

	printf("Enter second string(no spaces)");
	scanf_s("%99s", p_str2);

	printf("\n---Printed strings(using puts)---\n");
	puts(p_str1);
	puts(p_str2);

	//---------------------------------------------------
	//무슨일을 하는 부분인지 작성
	printf("\n---strlen practice---\n");
	printf("Length of str1:%zu\n", strlen(p_str1));
	printf("Length of str2:%zu\n", strlen(p_str2));
	//---------------------------------------------------

	//왜 여기에 이 함수를 넣었는지 작성
	clear_input_buffer();

	printf("\nEnter one sentence(can include spaces):");
	fgets(p_sentence, sizeof(sentence), stdin);
	printf("\nYou entered(sentence)=");
	puts(p_sentence);
	//----------------------------------------

	//무슨일을 하는 부분인지 작성
	printf("\n---Practice#1:???????---\n");
	strcpy(p_copy, p_str1);
	printf("copy=");
	puts(p_copy);
	//----------------------------------------

	//----------------------------------------
	//무슨일을 하는 부분인지 작성
	printf("\n---Practice #2:?????????---\n");
	if (strlen(p_str1) + strlen(p_str2) < sizeof(str1)) {
		strcat(p_str1, p_str2);
		printf("Afer concatenation,str1 =");
		puts(p_str1);
	}

	else {
		printf("str1 buffer is too small; cannot perform strcat\n");
	}
	//-----------------------------------------------

	//----------------------------------------------
	//무슨일을 하는 부분인지 작성
	printf("\n---Practice#3:??????????---\n");
	{
		int cmp = strcmp(p_str1, p_str2);
		if (cmp == 0) {
			printf("str1 and str2are equal.\n");
		}
		else if (cmp < 0) {
			printf("IN lexicographical order,str1 comes before str2.\n");
		}
		else {
			printf("IN lexicographical order,str1 comes after str2.\n")
		}
	}
	//---------------------------------------------

	//---------------------------------------------
	//무슨일을 하는 부분인지 작성
	printf("\n---Practice#3:??????????---\n");
	printf("\nEnter a character to search for:");
	scanf("%c", &ch);
	pos = strchr(p_str1, ch);
	ifpos = strchr(p_str, ch);
}