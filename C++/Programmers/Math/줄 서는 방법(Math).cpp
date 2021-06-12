#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int cnt = 0;
int visit[21];
vector<int> answer;

void recycle(long long sum, int n, long long k, int t) {
	
	int num = ceil((double)k / sum);

	cnt = 1;
	for (int i = 1; i <= t; i++) {
		if (visit[i] == 1) continue;
		if (cnt == num) {
			answer.push_back(i);
			visit[i] = 1;
			break;
		}
		cnt++;
	}
    
	if (answer.size() == t)return;

	else {
		long long nxt_k = k % sum;
		if (nxt_k == 0) nxt_k = sum;
		if (n == 0) return;
		recycle(sum / n, n - 1, nxt_k, t);
	}
	return;
}

vector<int> solution(int n, long long k) {
	long long sum = 1;

	for (int i = 1; i < n; i++) {
		sum *= i;
	}
	recycle(sum, n-1, k, n);
	
	return answer;
}