#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define N 4
#define Q int
#define T int
//Богатов Максим

//1.	Написать функции, которые считывают матрицу смежности из файла и выводят её на экран.
//2.	Написать рекурсивную функцию обхода графа в глубину.
//3.	Написать функцию обхода графа в ширину.

//const int N=4;
const char* filename = "D:\\TEMP\\data.txt";
const int MaxInt = 20000000;
int used[N];
int checkVertex[N];

void dfs(int v, int W[N][N])

{
	int i;
	used[v] = 1;
	printf("Вершина %d посещенена\n", v);

	for (i = 1; i <= N; i++)

		if (W[v][i] && !used[i]) dfs(i,W);

}

Q Que[N];

int M = -1;

int start = 0;
int finish = 0;

void push(T i)
{
	if (M < N)
	{
		M++;
		Que[finish] = i;
		finish++;
	}
	else
		printf("Stack overflow");
}

T pop()
{
	if (M != -1)
	{
		T a = Que[start];
		start++;
		M--;
		return a;
	}
	else
		printf("Stack is empty");
}


void bfs(int v, int W[N][N]) 
{
	for (int i = 1; i <= N; i++) {
		
			for (int n = 1; n < N; n++) {
				if (W[n][i] && !checkVertex[v]) {					
					push(v);
					checkVertex[v] = 1;
					v++;
				}
			}
		
	}

	while (M != -1)
		printf("Вершина %d посещенена\n", pop());

}

int load(int W[N][N])
{
	FILE* file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Can't open file");
		exit(1);
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			int a;
			fscanf(file, "%d", &a);
			if (a == 0)
				W[i][j] = MaxInt;
			else
				W[i][j] = a;
		}
	fclose(file);
	return 0;
}

void printMatrix(int W[N][N])
{
	printf("%s", "      ");
	for (int i = 0; i < N; i++)
		printf("%c(%d) ", 65 + i, i);
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		printf("%c(%d)", 65 + i, i);
		for (int j = 0; j < N; j++)
			printf("%5d", (W[i][j] == MaxInt) ? 0 : W[i][j]);
		printf("\n");
	}
}


int main() {
	//setlocale(LC_ALL, "Rus");
	setlocale(LC_ALL, "en_US.UTF-8");
	int W[N][N];    
	load(W);

	printMatrix(W);
	printf("\n");
	dfs(1,W);
	Q c;
	printf("\n");
	bfs(1,W);
	printf("\n");
	system("pause");
	return 0;
}