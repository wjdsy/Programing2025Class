#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

// 무슨일을 하는 함수인지 실행해보고 주석작성
void clear_input_buffer(void)
{
	// [함수 역할]: 이 함수는 키보드 입력 후 입력 버퍼에 남아있는 찌꺼기 문자(주로 '\n')를
	// 모두 읽어 들여 버린다. 다음 입력 함수(예: fgets)가 정상적으로 작동하도록 버퍼를 정리
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

	// 포인터 변수에 각 배열의 첫 번째 주소를 할당한다.
	char* p_str1 = str1;
	char* p_str2 = str2;
	char* p_copy = copy;
	char* p_sentence = sentence;
	char* p_temp = temp;

	printf("Enter first string(no spaces)");
	scanf_s("%99s", p_str1, (unsigned int)sizeof(str1));

	printf("Enter second string(no spaces)");
    scanf_s("%99s", p_str2, (unsigned int)sizeof(str2));

	printf("\n---Printed strings(using puts)---\n");
	puts(p_str1);
	puts(p_str2);

	//---------------------------------------------------
	// 무슨일을 하는 부분인지 작성
	printf("\n---strlen practice---\n");
	// [기능]: strlen 함수를 사용하여 각 문자열(str1, str2)의 **널 문자(\0)를 제외한** 길이를 계산하고 출력
	printf("Length of str1:%zu\n", strlen(p_str1));
	printf("Length of str2:%zu\n", strlen(p_str2));
	//---------------------------------------------------

	// 왜 여기에 이 함수를 넣었는지 작성
	clear_input_buffer();
	// [이유]: 위의 scanf_s 호출은 문자열만 읽고, 사용자가 입력한 개행 문자('\n')를 
	// 입력 버퍼에 남겨둔다. 바로 다음에 호출되는 fgets가 이 잔여 '\n'을 읽어 입력을 건너뛰는 것을 방지하기 위해 버퍼를 비운다

	printf("\nEnter one sentence(can include spaces):");
	fgets(p_sentence, sizeof(sentence), stdin);
	printf("\nYou entered(sentence)=");
	puts(p_sentence);
	//----------------------------------------

	// 무슨일을 하는 부분인지 작성
	printf("\n---Practice#1:문자열 복사 (strcpy)---\n");
	// [기능]: strcpy 함수를 사용하여 p_str1이 가리키는 문자열 전체를 p_copy 배열로 복사
	strcpy(p_copy, p_str1);
	printf("copy=");
	puts(p_copy);
	//----------------------------------------

	//----------------------------------------
	// 무슨일을 하는 부분인지 작성
	printf("\n---Practice #2:문자열 결합 (strcat)---\n");
	// [기능]: strcat을 수행하기 전에, str1에 str2를 붙였을 때 str1의 버퍼(100바이트)를 초과하지 않는지 확인
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
	// 무슨일을 하는 부분인지 작성
	printf("\n---Practice#3:문자열 비교 (strcmp)---\n");
	// [기능]: strcmp 함수를 사용하여 현재 str1과 str2를 사전 순서(lexicographical order)로 비교
	{
		int cmp = strcmp(p_str1, p_str2);
		if (cmp == 0) {
			printf("str1 and str2are equal.\n");
		}
		else if (cmp < 0) {
			printf("IN lexicographical order,str1 comes before str2.\n");
		}
		else {
			printf("IN lexicographical order,str1 comes after str2.\n");
		}
	}
	//---------------------------------------------

	//---------------------------------------------
	// 무슨일을 하는 부분인지 작성
	printf("\n---Practice#4: 문자 검색 (strchr)---\n");
	printf("\nEnter a character to search for:");
	// ' %c'는 남아있는 공백 문자나 개행 문자를 무시하고 실제 문자 하나를 입력
	scanf(" %c", &ch);

	// [기능]: strchr 함수를 사용하여 str1 문자열 내에서 문자 ch가 처음 나타나는 위치의 포인터를 찾는다.
	pos = strchr(p_str1, ch);

	if (pos != NULL) {
		// 포인터 뺄셈 (pos - p_str1)을 통해 str1의 시작 주소로부터 문자가 위치한 인덱스(거리)를 계산
		printf("'%c' is at index %ld (0-based) in str1.\n", ch, (long)(pos - p_str1));
	}
	else {
		printf("'%c' is not found in str1.\n");
	}
	//------------------------------------------------
	// 무슨일을 하는 부분인지 작성
	printf("\n---Practice#5:부분 문자열 검색 (strstr)---\n");
	// [기능]: strstr 함수를 사용하여 sentence 문자열 내에서 str2 문자열(부분 문자열)이 처음 나타나는 위치의 포인터를 찾는다.
	pos = strstr(p_sentence, p_str2);
	if (pos != NULL) {
		printf("Found\"%s\"inside sentence.\n", p_str2);
		// 찾은 위치(pos)부터 문장의 끝까지 나머지 문자열을 출력
		printf("Substring starting from the found position:");
		puts(pos);
	}
	else {
		printf("Could not find \"%s\"in sentence.\n", p_str2);
	}
	//--------------------------------------------------

	//------------------------------------------------------
	// 무슨일을 하는 부분인지 작성
	printf("\n---Practice#6:문자열 분리 (strtok)---\n");
	printf("\n---strtok practice:split sentence by spaces---\n");
	//왜 이 실습에서는 temp에 문자열을 복사하는가?
		// [이유]: strtok 함수는 문자열을 분리하는 과정에서 구분자(' ') 위치에 널 문자('\0')를 넣어 **원본 문자열(sentence)을 훼손**하기
		// 때문에 원본을 보존하기 위해 p_temp에 복사본을 만들어 분리 작업을 수행
	strcpy(p_temp, p_sentence);

	// [기능]: strtok 함수를 사용하여 p_temp를 공백(" ")을 기준으로 토큰(단어)으로 분리
	char* token = strtok(p_temp, " ");
	int i = 1;
	while (token != NULL) {
		printf("Token%d:", i++);
		puts(token);
		// [수정] 다음 토큰을 얻을 때는 NULL을 첫 번째 인수로 사용하고, 구분자도 " "로 지정
		token = strtok(NULL, " ");
	}
	//------------------------------------------------------
	printf("\nProgram finished.\n");
	return 0;
}