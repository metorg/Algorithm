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
#define MAX 1010
#define INF 987654321

using namespace std;
vector<int> num;
int main() {
	int n, m;
	int weight = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		num.push_back(m);
	}
	sort(num.begin(), num.end());
	for (int i = 0; i < num.size(); i++) {
		if (weight < num[i])break;
		weight += num[i];
	}
	cout << weight;
}

