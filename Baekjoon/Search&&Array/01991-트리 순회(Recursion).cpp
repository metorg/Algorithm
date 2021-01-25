#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include<stdio.h>
#include<string.h>
#include<set>

using namespace std;

int n;
vector < vector<char>> v(27);
char a, b, c;

void Print(char ch,int flag) {
	if (ch == '.')return;
	if (flag == 1) {// 전위 순회
		cout << ch;
		Print(v[ch-'A'][0],1);
		Print(v[ch - 'A'][1], 1);
	}
	else if (flag == 2) {// 중위 순회
		Print(v[ch - 'A'][0], 2);
		cout << ch;
		Print(v[ch - 'A'][1], 2);
	}
	else if (flag == 3) {//후위 순회
		Print(v[ch - 'A'][0], 3);
		Print(v[ch - 'A'][1], 3);
		cout << ch;
	}
	
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> a >> b >> c;
		v[a - 'A'].push_back(b);
		v[a - 'A'].push_back(c);
	}

	for (int i = 1;i <= 3;i++) {
		Print('A', i);
		cout << '\n';
	}	
}