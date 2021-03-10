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

int total_num, num;
int pick_num;
deque<int> dq;
vector<char> answer;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int cnt = 0;

	cin >> total_num >> pick_num;
	for (int i = 1;i <= total_num; i++) dq.push_back(i);
	
	for (int i = 0;i < pick_num;i++) {
		cin >> num;
		
		int idx;
		
		for (int j = 0;j < dq.size();j++) if (dq[j] == num) idx = j;
		
		if (idx < dq.size()- idx) {//ã������ �ϴ� ���� back�ʿ� �� ������ back�� �ִ� ���Ҹ� ���� front�� ������ ���
			while (1) {
				if (dq.front() == num) {
					dq.pop_front();
					break;
				}
				else {
					dq.push_back(dq.front());
					dq.pop_front();
					cnt++;
				}
			}
		}
		
		else {//ã������ �ϴ� ���� front�ʿ� �� ������ front�� �ִ� ���Ҹ� ���� back�� ������ ���
			while (1) {
				if (dq.front() == num) {
					dq.pop_front();
					break;
				}
				else {
					dq.push_front(dq.back());
					dq.pop_back();
					cnt++;
				}
			}
		}
	}

	cout << cnt;


}