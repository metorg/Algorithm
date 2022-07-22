#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int number[10][10] = { {0,4,3,3,4,3,2,3,1,2},{4,0,5,3,2,5,6,1,5,4},{3,5,0,2,5,4,3,4,2,3},{3,3,2,0,3,2,3,2,2,1},{4,2,5,3,0,3,4,3,3,2},{3,5,4,2,3,0,1,4,2,1},{2,6,3,3,4,1,0,5,1,2},{3,1,4,2,3,4,5,0,4,3},{1,5,2,2,3,2,1,4,0,1},{2,4,3,1,2,1,2,3,1,0}};
int X, N, K, P;
int answer = 0;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> X >> N >> K >> P;
	
	for (int i = 1; i <= X; i++) {
		int cnt = 0;
		int c_i = i;
		int from = P, to = i;
		
		for (int j = 0; j < N; j++) {
			cnt += number[from%10][to%10];
			from /= 10;
			to /= 10;
		}		
		if (cnt <= K)answer++;
	}
	
	cout << answer-1;

}
