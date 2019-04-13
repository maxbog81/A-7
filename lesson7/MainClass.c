#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>


int main() {
	//setlocale(LC_ALL, "Rus");
	setlocale(LC_ALL, "en_US.UTF-8");


	printf("привет");
	printf("\n");
	system("pause");
	return 0;
}