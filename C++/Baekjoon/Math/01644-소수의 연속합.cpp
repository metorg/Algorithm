#include <iostream>
#include <vector> 
using namespace std;
const int MAX = 4000000;
bool prime[MAX + 1] = { true, true };
vector<int> primes;
int n;
int cnt = 0;
void eratos() {
	for (int i = 2; i <= n; i++)
	{
		if (!prime[i])
		{
			if (i == n && i != 2) {
				cnt++;
			}
			primes.push_back(i);
			for (int j = i * 2; j <= n; j += i) {//이부분이 핵심
				prime[j] = true;
			}
		}
	}
}
int main() {
	cin >> n;

	eratos();

	int res = 0;
	int left = 0, right = 0;
	int subSum = 0;
	while (right < primes.size()) {
		if (subSum >= n) subSum -= primes[left++];
		else if (right > n) break; else subSum += primes[right++];
		if (subSum == n) cnt++;
	}
	cout << cnt; return 0;
}

