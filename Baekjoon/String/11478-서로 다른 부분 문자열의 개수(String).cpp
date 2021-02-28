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
#include<set>
using namespace std;

set<string> s;
int main() {

	ios::sync_with_stdio(0);
	string d;
	cin >> d;
	string r = "";
	for (int i = 0;i < d.length();i++) {
		r = "";
		for (int j = i;j < d.length();j++) {
			r += d[j];
			s.insert(r);
		}
	}

	cout << s.size();

}