#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include <stack>
#include<stdio.h>
#include<string.h>
#include<cstdio>
#include<set>

using namespace std;

stack<char> v;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a;
	cin >> a;
	int cnt = 0;
	for (int i = 0;i < a.length();i++) {
		
		if ('A' <= a[i] && a[i] <= 'Z')cout << a[i];
		else if (a[i] == '(') {
			v.push('(');
		}
		else if (a[i] == ')') {
			while (v.size() && v.top() != '(') {
				cout << v.top();
				v.pop();
			}
			if (v.size()) v.pop();
		}

		else {

			if (a[i] == '+' || a[i] == '-') {

				while (!v.empty()) {
					if (v.top() == '(') {
						break;
					}
					cout << v.top();
					v.pop();
				}

			}
			else if (a[i] == '*' || a[i] == '/') {
				while (v.size()) {
					if (v.top() == '*' || v.top() == '/') {
						cout << v.top();
						v.pop();
					}
					else break;
				}
			}
			v.push(a[i]);


		}
	}
	while (!v.empty()) {
		cout << v.top();
		v.pop();
	}
}


