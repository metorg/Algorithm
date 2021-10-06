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

stack<char> s;
string str;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> str;
	int sum = 0;
	int tmp = 1;
	for (int i = 0; i < str.length(); i++) {
		if (str[0] == ')' || str[0] == ']')break;	

		if (str[i] == '(') {
			s.push(str[i]);
			tmp *= 2;
		}
		else if (str[i] == '[') {
			s.push(str[i]);
			tmp *= 3;
		}
		if (s.empty()) {
			sum = 0;
			break;
		}
		else if (str[i] == ')') {
			if (s.top() == '(') {
				if (str[i - 1] == '(') {
					sum += tmp;
					tmp /= 2;
					
				}
				else {
					tmp /= 2;
				}
				s.pop();
			}
		}
		else if (str[i] == ']') {
			if (s.top() == '[') {
				if (str[i - 1] == '[') {
					sum += tmp;
					tmp /= 3;

				}
				else {
					tmp /= 3;
				}
				s.pop();
			}
		}
	}
	if (s.empty())cout << sum;
	else cout << 0;
	
	
}