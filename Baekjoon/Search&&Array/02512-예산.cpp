#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
/*ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);*/
using namespace std;
vector<int> s;

int main() {
	int n;
	int num2;
	int size;
	int msum = 0;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> num2;
		msum += num2;
		s.push_back(num2);

	}
	cin >> size;
	sort(s.begin(), s.end());
	int sum = size / n;
	int nsum = 0;
	int cnt = 0;
	int max = sum;
	if (msum <= size) {
		cout << s[s.size() - 1];
		return 0;
	}
	else {
		for (int i = 0;i < n - 1;i++) {
			if (s[i] <= sum) {
				cnt++;
				nsum += s[i];
				size -= s[i];
				sum = size / (n - i - 1);
				if (max < sum)
					max = sum;
			}
		}

	}
	cout << max;

}