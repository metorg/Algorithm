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
using namespace std;
const int MAX = 2000000;
bool prime[MAX + 1] = { true, true };
int n;
void eratos() {
	for (int i = 2;i <= MAX; i++)
	{
		if (!prime[i]) {
			for (int j = i * 2; j <= MAX; j += i) {
				prime[j] = true;
			}
		}
	}
}
int main() {
	cin >> n;
	eratos();
	int c_p;
	for (int i = n;i <= MAX;i++) {
		if (prime[i] == 0) {
			c_p = i;
			int sum = 0;
			while (c_p) {
				sum = (sum * 10) + (c_p % 10);
				c_p /= 10;
			}
			if (sum == i) {
				cout << i;
				return 0;
			}
		}
	}
}