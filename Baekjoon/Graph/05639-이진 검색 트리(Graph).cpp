#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include<stdio.h>
#include<string.h>
#include<cstdio>
#include<set>

using namespace std;

int n,m;
vector<pair<int, int>> tree(1000002);

void printOrder(int start) {

	if (start == 0)return;
	printOrder(tree[start].first);
	printOrder(tree[start].second);
	cout << start<<'\n';
}
	
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	while (cin>>m) {
		int cur = n;
		while (1) {
			if (m > cur) {
				if (tree[cur].second != 0)cur = tree[cur].second;
				else {
					tree[cur].second = m;
					break;
				}
			}
			else {
				if (tree[cur].first != 0)cur = tree[cur].first;
				else {
					tree[cur].first = m;
					break;
				}
			}
		}
	}
	
	printOrder(n);
	return 0;
}