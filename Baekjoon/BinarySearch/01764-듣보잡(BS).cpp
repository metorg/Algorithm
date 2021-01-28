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

int n, m;
vector<string> v;
vector<string> answer;
string str;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> str;
		v.push_back(str);
	}
	
	sort(v.begin(), v.end());

	for (int i = 0;i < m;i++) {
		cin >> str;
		if (binary_search(v.begin(), v.end(), str)) answer.push_back(str);
		//binary_search 시간복잡도 (logN)
	}

	cout << answer.size() << '\n';
	for (int i = 0;i < answer.size();i++) {
		cout << answer[i] << '\n';
	}

}