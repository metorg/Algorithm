#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<memory.h>
#include<unordered_map>

using namespace std;

int n;
int arr[128][128];
int zero = 0;
int one = 0;

void DFS(int x, int y,int size) {
	if (size == 1) {
		if (arr[x][y] == 1)one++;
		else zero++;
		return;
	}
	bool OnlyZero, OnlyOne;
	OnlyZero = OnlyOne = true;
	for (int i = x;i < x + size;i++) {
		for (int j = y;j < y + size;j++)
		{
			if (arr[i][j] == 0)OnlyOne = false;
			if (arr[i][j] == 1)OnlyZero = false;
		}
	}
	if (OnlyZero == true)
	{
		zero++;
		return;
	}
	if (OnlyOne == true)
	{
		one++;
		return;
	}
	DFS(x, y, size / 2);
	DFS(x, y+size/2, size / 2);
	DFS(x+size/2, y, size / 2);
	DFS(x+size/2, y+size/2, size / 2);
}
int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
		}
	}
	DFS(0, 0, n);
	cout << zero << '\n' << one;
}