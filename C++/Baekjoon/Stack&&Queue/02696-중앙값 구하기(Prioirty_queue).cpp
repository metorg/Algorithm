#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include<cstring>
#include<stack>
#include<string.h>
#include<stdio.h>

using namespace std;
	

int visit_count[100001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int total_case;
	int case_num;
	int num;

	cin >> total_case;
	for (int i = 0; i < total_case; i++) {
		cin >> case_num;
		priority_queue<int, vector<int>, less<int>> pq;
		priority_queue<int, vector<int>, greater<int>> pq2;
		vector<int> answer;
		cin >> num;
		pq.push(num);
		answer.push_back(num);
		for (int j = 1; j < case_num; j++) {
			cin >> num;
			if (pq.size() < pq2.size()) {
				if (num > pq2.top()) {
					pq.push(pq2.top());
					pq2.pop();
					pq2.push(num);
				}
				else {
					pq.push(num);
				}
			}
			else {
				if (num < pq.top()) {
					pq2.push(pq.top());
					pq.pop();
					pq.push(num);
				}
				else {
					pq2.push(num);
				}
			}
			if (j % 2 == 0) {
				if (pq2.size() > pq.size())	answer.push_back(pq2.top());
				else answer.push_back(pq.top());
			}			
		}
		cout << answer.size() << '\n';
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << ' ';
		}
		cout << '\n';
	}
}