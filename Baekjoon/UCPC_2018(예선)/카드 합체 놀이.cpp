#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

long long solution(int num, int num2, priority_queue<long long, vector<long long>, greater<long long>> card) {
	long long answer = 0;
	long long a, b;
	for (int i = 0;i < num2;i++) {
		a = card.top();
		card.pop();
		b = card.top();
		card.pop();
		card.push(a + b);
		card.push(a + b);
	}
	while (!card.empty()) {
		answer += card.top();
		card.pop();
	}


	return answer;
}
int main() {
	int num, num2, num3;
	priority_queue<long long, vector<long long>, greater<long long>> card;
	cin >> num >> num2;
	for (int i = 0;i < num;i++) {
		cin >> num3;
		card.push(num3);
	}
	cout << solution(num, num2, card);
}