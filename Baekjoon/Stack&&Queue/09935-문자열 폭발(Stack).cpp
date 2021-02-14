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

int main() {
	ios::sync_with_stdio(false);
	
	stack<char> s;
	string a,b;
	int cnt = 0;
	
	cin >> a>>b;

	for (int i = 0;i < a.length();i++) {
		if (a[i] == b[cnt])cnt++;		
		else {
			cnt = 0;
			if (a[i] == b[cnt])cnt++;
		}

		s.push(a[i]);
		
		if (cnt == b.length()) {
			for (int j = 0;j < b.length();j++) {
				s.pop();
				cnt = 0;
			}

			string d;
			for (int j = 0;j < b.length();j++) {//b의 길이만큼 스택에서 빼서 새로운 d의 저장
				if (s.empty())break;
				d += s.top();
				s.pop();
			}

			for (int j = d.length() - 1;j >= 0;j--) {// d의 길이만큼 재조사 
				if (d[j] == b[cnt])cnt++;
				else {
					cnt = 0;
					if (d[j] == b[cnt])cnt++;
				}
			}

			for (int j = d.length() - 1;j >= 0;j--) s.push(d[j]);//스택에서 빼낸 d의 값들을 다시 stack에 추가


		}
	}
	string answer;
	while (!s.empty()) {
		answer += s.top();
		s.pop();
	}
	reverse(answer.begin(), answer.end());//스택에서 나올때는 거꾸로 나오기때문에 리버스를 해준다

	if (!answer.empty()) cout << answer;
	else cout << "FRULA";


}