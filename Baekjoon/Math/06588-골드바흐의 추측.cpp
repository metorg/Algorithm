#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>

using namespace std;
int n;
bool prime[1000001] = { true,true };
vector<int> primes;
void eratos() {
	for (int i = 2;i <= n; i++)
	{
		if (!prime[i])
		{
			primes.push_back(i);
			for (int j = i * 2; j <= n; j += i) {
				prime[j] = true;
			}
		}
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int sum = 0;
	int min = 0;
	int num = 0, num2 = 0;
	n = 1000000;
	eratos();


	while (1) {
		int cnt = 0;
		cin >> n;
		if (n == 0)break;
		for (int i = 0;primes[i] <= n / 2;i++) {
			if (!prime[primes[i]] && !prime[n - primes[i]]) {
				cout << n << " = " << primes[i] << " + " << n - primes[i] << '\n';
				cnt++;
				break;
			}
		}
		if (cnt == 0)cout << "Goldbach's conjecture is wrong." << '\n';
	}
}