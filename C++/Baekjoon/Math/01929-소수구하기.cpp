#include <iostream>
#include <vector> 
using namespace std;
const int MAX = 1000000;
bool prime[MAX + 1] = { true, true };
vector<int> primes;
int n;
int m;
int cnt = 0;
void eratos() {
	for (int i = 2; i <= m; i++)
	{
		if (!prime[i])
		{
			if (i >= n && i <= m) {
				primes.push_back(i);
			}
			for (int j = i * 2; j <= m; j += i) {//이부분이 핵심
				prime[j] = true;
			}
		}
	}
}
int main() {
	cin >> n >> m;
	eratos();
	for (int i = 0;i < primes.size();i++) {
		cout << primes[i] << '\n';
	}
}