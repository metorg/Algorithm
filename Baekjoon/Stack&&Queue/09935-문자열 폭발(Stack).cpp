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
			for (int j = 0;j < b.length();j++) {//b�� ���̸�ŭ ���ÿ��� ���� ���ο� d�� ����
				if (s.empty())break;
				d += s.top();
				s.pop();
			}

			for (int j = d.length() - 1;j >= 0;j--) {// d�� ���̸�ŭ ������ 
				if (d[j] == b[cnt])cnt++;
				else {
					cnt = 0;
					if (d[j] == b[cnt])cnt++;
				}
			}

			for (int j = d.length() - 1;j >= 0;j--) s.push(d[j]);//���ÿ��� ���� d�� ������ �ٽ� stack�� �߰�


		}
	}
	string answer;
	while (!s.empty()) {
		answer += s.top();
		s.pop();
	}
	reverse(answer.begin(), answer.end());//���ÿ��� ���ö��� �Ųٷ� �����⶧���� �������� ���ش�

	if (!answer.empty()) cout << answer;
	else cout << "FRULA";


}