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

int n;
int num;
deque<pair<int,int>> dq;
vector<int> answer;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> num;
		dq.push_back({ i,num });
	}
	while (1) {
		
		int cnt = dq.front().second;
		answer.push_back(dq.front().first);
		dq.pop_front();
		if (dq.empty())break;

		if (cnt > 0) {
			for (int i = 1; i < cnt; i++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			for (int i = 0; i < abs(cnt); i++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ' ';
	}
}