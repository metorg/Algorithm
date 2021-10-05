#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<memory.h>

using namespace std;

stack<char> s;
int answer = 0;
string str;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(')s.push(str[i]);
		else {
			s.pop();
			if (str[i - 1] == '(')answer += s.size();
			else answer += 1;
		}
	}
	cout << answer;
}