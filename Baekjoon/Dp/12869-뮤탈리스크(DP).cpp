#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<memory.h>
#include<unordered_map>
using namespace std;
int n;
vector<int> scv;
int rotation[61][61][61];


int search(int a, int b, int c) {
	if (!a && !b && !c) {
		return 0;
	}
	//int &answer = rotation[a][b][c];//참조형 변수 rotation[a][b][c] 는 rotation의 별명과 같다.

	if (rotation[a][b][c] != -1) {
		return rotation[a][b][c];
	}
	rotation[a][b][c] = 2e9;

	rotation[a][b][c] = min(rotation[a][b][c], search(max(0, a - 9), max(0, b - 3), max(0, c - 1)) + 1);
	rotation[a][b][c] = min(rotation[a][b][c], search(max(0, a - 9), max(0, b - 1), max(0, c - 3)) + 1);
	rotation[a][b][c] = min(rotation[a][b][c], search(max(0, a - 3), max(0, b - 9), max(0, c - 1)) + 1);
	rotation[a][b][c] = min(rotation[a][b][c], search(max(0, a - 3), max(0, b - 1), max(0, c - 9)) + 1);
	rotation[a][b][c] = min(rotation[a][b][c], search(max(0, a - 1), max(0, b - 9), max(0, c - 3)) + 1);
	rotation[a][b][c] = min(rotation[a][b][c], search(max(0, a - 1), max(0, b - 3), max(0, c - 9)) + 1);

	return rotation[a][b][c];

}
int main() {
	cin >> n;
	int num;
	int sum = 0;
	int scv[3] = { 0,0,0 };
	int ans;
	for (int i = 0; i < n; ++i)
		cin >> scv[i];


	memset(rotation, -1, sizeof(rotation));
	ans = search(scv[0], scv[1], scv[2]);

	cout << ans << "\n";
}