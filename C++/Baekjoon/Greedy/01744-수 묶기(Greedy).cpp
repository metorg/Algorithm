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
vector<int> mnum;

int main() {
	int n, m;
	int msum = 0;
	int sum = 0;
	int zero = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		if (m < 0) {
			mnum.push_back(m);
		}
		else if (m == 0) {
			zero++;
		}
		else {
			num.push_back(m);
		}
	}
	sort(mnum.begin(), mnum.end());
	sort(num.begin(), num.end());
	for (int i = 0; i < mnum.size(); i++) {
		if (msum != 0) {
			sum += msum * mnum[i];
			msum = 0;
		}
		else
			msum += mnum[i];
	}
	if (msum != 0 && zero != 0) {
		msum = 0;
	}
	else {
		sum += msum;
		msum = 0;
	}
	for (int i = num.size() - 1; i >= 0; i--) {
		if (num[i] > 1) {
			if (msum != 0) {
				sum += msum * num[i];
				msum = 0;
			}
			else
				msum += num[i];
		}
		else {
			if (msum != 0) {
				sum += msum;
				sum += num[i];
				msum = 0;
			}
			else {
				sum += num[i];
			}
		}
	}
	if (msum != 0) {
		sum += msum;
	}
	cout << sum;
}