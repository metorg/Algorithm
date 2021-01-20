#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include<set>

using namespace std;

int board[64][64];
int num;
char n;
string answer;


void dfs(int x,int y,int size){
	
	if (size == 0)return;
	
	bool onlyone = true ,onlyzero = true;

	for (int i = x;i < x+size;i++) {
		for (int j = y;j < y+size;j++) {
			if (board[i][j] != 0)onlyzero = false;
			if (board[i][j] != 1)onlyone = false;
		}
	}
	if (onlyone == true) {
		answer += '1';
		return;
	}
	if (onlyzero == true) {	
		answer += '0';
		return;
	}

	size = size / 2;
	answer += "(";
	dfs(x, y, size);
	dfs(x, y + size, size);
	dfs(x + size, y, size);
	dfs(x + size, y + size, size);
	answer += ")";
	
}
int main()
{
	cin >> num;
	for (int i = 0;i < num;i++) {
		for (int j = 0;j < num;j++) {
			cin >> n;
			board[i][j] = n - '0';
		}
	}
	
	dfs(0, 0, num);

	cout << answer;
	
}