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
#include<set>
using namespace std;

stack<int> s;
string str;
set<string> answer;
vector<pair<int, int>> bracket;
int visit[11];
int visit2[201];


void print() {
	string tmp = "";
	for (int i = 0; i < str.length(); i++) {
		if (visit2[i])continue;
		tmp += str[i];
	}
	answer.insert(tmp);
}

void backtracking(int depth) {
	
	for (int i = depth; i < bracket.size(); i++) {

		if (visit[i])continue;
		visit[i] = 1;
		visit2[bracket[i].first]=1;
		visit2[bracket[i].second]=1;
		print();
		backtracking(i);
		visit[i] = 0;
		visit2[bracket[i].first] = 0;
		visit2[bracket[i].second] = 0;
	}
	
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(')s.push(i);
		else if (str[i] == ')') {
			bracket.push_back({ s.top(),i });
			s.pop();
		}
	}
	
	backtracking(0);
	for (auto i : answer) cout << i << '\n';
	
}