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

int n, m,c_m;
vector<int> v;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n>>m;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}
	c_m = m-1;

	cout << "<";
	while (v.size()!=1) {
		cout << v[c_m] << ", ";
		v.erase(v.begin() + c_m);
		c_m= (c_m+m-1) % v.size();	
	}
	cout << v[0]<<">";
}