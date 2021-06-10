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

int visit[27];
vector<int> num;

int main() {
	int n;
	int tmp = 1;
	cin >> n;
	string d;
	for (int i = 0;i < n;i++) {
		cin >> d;
		for (int j = 0;j < d.length();j++) {
			tmp = 1;
			for (int k = j + 1; k < d.length();k++) {
				tmp *= 10;
			}
			visit[d[j] - 'A'] += tmp;
		}

	}
	for (int i = 0;i < 26;i++) {
		if (visit[i] != 0) {
			num.push_back(visit[i]);
		}
	}
	sort(num.begin(), num.end(), greater<int>());

	int cnt = 9;
	int sum = 0;
	for (int i = 0;i < num.size();i++) {
		sum = sum + num[i] * cnt;
		cnt--;
	}
	cout << sum;
}