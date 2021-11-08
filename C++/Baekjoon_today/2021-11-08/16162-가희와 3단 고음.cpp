#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N, A, D;
int num;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> A >> D;
	
	int cnt = 0;
	int sum = -1;
	
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == A&&cnt==0) {
			cnt = 1;
			sum = num;
		}
		
		if (sum!=-1&&sum + D == num) {
			cnt++;
			sum += D;
		}
	}
	cout << cnt;

}