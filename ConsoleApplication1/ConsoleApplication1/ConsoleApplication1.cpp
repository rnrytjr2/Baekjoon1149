// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
struct RGB
{
	int R = 0;
	int G = 0;
	int B = 0;
};
RGB datas[1000];
RGB DP[1000];
void RGBStreat(int count);
int length, minvalue = 1000000000;
int main()
{
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		cin >> datas[i].R >> datas[i].G >> datas[i].B;
	}
	RGBStreat(0);
	if (DP[length - 1].R > DP[length - 1].G)
	{
		if (DP[length - 1].G > DP[length - 1].B)
		{
			cout << DP[length - 1].B;
		}
		else
		{
			cout << DP[length - 1].G;
		}
	}
	else
	{
		if (DP[length - 1].R > DP[length - 1].B)
		{
			cout << DP[length - 1].B;
		}
		else
		{
			cout << DP[length - 1].R;
		}
	}
}
//1번 집의 색은 2번 집의 색과 같지 않아야 한다.
//N번 집의 색은 N - 1번 집의 색과 같지 않아야 한다.
//i(2 ≤ i ≤ N - 1)번 집의 색은 i - 1번, i + 1번 집의 색과 같지 않아야 한다.
//3개............
void RGBStreat(int count)
{
	if (count < length)
	{

		if (DP[count - 1].G > DP[count - 1].B)
		{
			DP[count].R += DP[count - 1].B + datas[count].R;
		}
		else
		{
			DP[count].R += DP[count - 1].G + datas[count].R;
		}

		if (DP[count - 1].R > DP[count - 1].B)
		{
			DP[count].G += DP[count - 1].B + datas[count].G;
		}
		else
		{
			DP[count].G += DP[count - 1].R + datas[count].G;
		}

		if (DP[count - 1].G > DP[count - 1].R)
		{
			DP[count].B += DP[count - 1].R + datas[count].B;
		}
		else
		{
			DP[count].B += DP[count - 1].G + datas[count].B;
		}
		RGBStreat(count + 1);
	}
}