#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<memory.h>
#include<unordered_map>
#include<set>
#include<bitset>
#include<string>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		string d;
		stack<char> s;
		bool answer = false;
		getline(cin, d);
		if (d == ".")break;
		for (int i = 0;i < d.length();i++) {
			if (d[i] == '(') {
				s.push(')');
			}
			else if (d[i] == '[') {
				s.push(']');
			}
			else if (d[i] == ')' || d[i] == ']') {
				if (s.empty() || d[i] != s.top()) {
					answer = true;
					break;
				}
				s.pop();
			}
		}
		if (answer || !s.empty()) cout << "no\n";
		else cout << "yes\n";

	}

}