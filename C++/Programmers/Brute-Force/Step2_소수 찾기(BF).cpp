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
const int MAX = 10000000;
int prime[MAX + 1] = { true, true };
int visit[8];
int visit2[MAX];
vector<int> num;
int cnt = 0;
void eratos() {
	for (int i = 2; i <= MAX; i++)
	{
		if (!prime[i]) {
			for (int j = i * 2; j <= MAX; j += i) {
				prime[j] = true;
			}
		}
	}
}
void dfs(int sum, int t, string numbers) {
	if (prime[sum] == 0 && sum != 0 && visit2[sum] == 0) {
		visit2[sum] = 1;
		cnt++;
	}
	if (t == numbers.size())return;
	for (int i = 0; i < numbers.length(); i++) {
		if (!visit[i]) {
			visit[i] = 1;
			dfs(sum * 10 + numbers[i] - '0', t + 1, numbers);
			visit[i] = 0;
		}

	}
}
int solution(string numbers) {
	int answer = 0;
	eratos();
	dfs(0, 0, numbers);
	answer = cnt;

	return answer;
}