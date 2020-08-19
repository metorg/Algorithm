#include<string>
#include <vector>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<math.h>

using namespace std;

bool isPrimeNumber(int x) {//에라토스테네스의 체 중요!!!
	int end = (int)sqrt(x);
	for (int i = 2;i <= end;i++) {
		if (x % i == 0)return false;
	}
	return true;

}
int main()
{
	int a;
	vector<int> v;
	cin >> a;
	for (int i = 2;i <= a;i++) {
		if (isPrimeNumber(i) == 1) {
			v.push_back(i);
		}
	}
	int cnt = 0;
	int sum = 0;
	for (int i = 0;i < v.size();i++) {
		sum = 0;
		if (v[i] == a) {
			cnt++;
			break;
		}
		else if (v[i] > a)break;

		sum += v[i];
		for (int j = i + 1;j < v.size();j++) {
			sum += v[j];
			if (sum > a)break;
			else if (sum == a) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
}