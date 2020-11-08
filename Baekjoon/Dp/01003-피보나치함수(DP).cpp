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

int Fibonacci[40] = { 0,1, };

int main() {
	int n, num;
	cin >> n;
	for (int i = 2; i <= 40; i++)
		Fibonacci[i] = Fibonacci[i - 1] + Fibonacci[i - 2];

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 0) {
			cout << 1 << ' ' << 0 << '\n';
		}
		else if (num == 1) {
			cout << 0 << ' ' << 1 << '\n';
		}
		else
			cout << Fibonacci[num - 1] << ' ' << Fibonacci[num] << '\n';
	}
}