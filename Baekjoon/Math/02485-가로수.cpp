#include<string>
#include <vector>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
int a;
int b;
int sum = 0;
vector<int> v;
int main() {
	int d = 0;
	cin >> a;
	for (int i = 0;i < a;i++) {
		cin >> b;
		if (i > 0) {
			v.push_back(abs(b - d));
		}
		d = b;
	}
	sort(v.begin(), v.end());
	int min = v[0];
	for (int i = 0;i < v.size();i++) {
		if (v[i] % min == 0) {
			sum += ((v[i] / min) - 1);
		}
		else {
			min -= 1;
			sum = 0;
			i = -1;
		}
	}
	cout << sum;
}
