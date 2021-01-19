#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include<set>

using namespace std;

int n;
int arr[2200][2200];
int one = 0, zero = 0, mone = 0;

void DFS(int x, int y, int size) {
	if (size == 0) return;
	bool onlyone = true, onlyzero = true, onlymone = true;

	for (int i = x;i < x + size;i++) {
		for (int j = y;j < y + size;j++)
		{
			if (arr[i][j] != 0)onlyzero = false;
			if (arr[i][j] != 1)onlyone = false;
			if (arr[i][j] != -1)onlymone = false;
		}
	}
	if (onlyzero == true)
	{
		zero++;
		return;
	}
	if (onlyone == true)
	{
		one++;
		return;
	}
	if (onlymone == true)
	{
		mone++;
		return;
	}

	size = size / 3;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			DFS(x + (i * size), y + (j * size), size);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
		}
	}
	DFS(0, 0, n);
	cout << mone << '\n' << zero << '\n' << one;
}