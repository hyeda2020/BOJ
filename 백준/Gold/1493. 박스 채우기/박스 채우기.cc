#include <iostream>
using namespace std;

int Length, Width, Height;
int N;
int Cubes[20];
int Answer;

void Divide(int length, int width, int height, int idx)
{
	if (length == 0 || width == 0 || height == 0)
	{
		return;
	}

	int cubeSize;
	for (int i = idx; i >= 0; i--)
	{
		if (!Cubes[i])
		{
			continue;
		}

		cubeSize = 1 << i;
		if (length < cubeSize || width < cubeSize || height < cubeSize)
		{
			continue;
		}

		Cubes[i]--;
		Answer++;
		
		/* 
		박스는 큐브를 하나 넣어줄 때마다 큐브를 뺀 3개의 공간으로 분할한 후,
		같은 작업을 재귀적으로 수행 
		*/
		Divide(length - cubeSize, width, cubeSize, i);
		Divide(cubeSize, width - cubeSize, cubeSize, i);
		Divide(length, width, height - cubeSize, i);
		return;
	}

	Answer = -1;
}

int main()
{
	cin >> Length >> Width >> Height;
	cin >> N;

	int A, B;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		Cubes[A] = B;
	}

	Divide(Length, Width, Height, N - 1);
	cout << Answer << '\n';
	return 0;
}