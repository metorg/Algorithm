#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<stack>
#include<stdio.h>

using namespace std;

int main() {
	
	int a;
	int num;
	int cnt = 0;
	int sum = 0;
	int tmp = 0;
	int cnt2 = 0;
	cin >> a;
	for (int i = 0;i < a;i++) {
		cin >> num;
		
		cnt2 += num / 2;
		
		
		sum += num;
	}
	tmp = (sum / 3);
	if (sum % 3 == 0) {
		if (tmp <= cnt2) {
			cout << "YES";
		}
		else
			cout << "NO";
	}
	else
		cout << "NO";
}