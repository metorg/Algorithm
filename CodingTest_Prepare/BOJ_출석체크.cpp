#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int visit[5003];
unordered_map<int, int> sleep_people;
unordered_map<int, int> check_people;
int N, K, Q, M;

int num;
int start, finish;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K >> Q >> M;
	
	for (int i = 0; i < K; i++) {
		cin >> num;
		sleep_people[num] = 1;
	}
	for (int j = 0; j < Q; j++) {
		cin >> num;
		check_people[num] = 1;
	}
	for (int s = 3; s <= N+2; s++) {
		if (check_people[s] == 1 && sleep_people[s] != 1) {
			visit[s] = 1;
		}
		if (visit[s] != 0) {
			for (int t = s; t <= N+2; t += s) {
				if (sleep_people[t] != 1) {
					visit[t] = 1;
				}
			}
		}
		visit[s] += visit[s - 1];

	}
	
	for (int k = 0; k < M; k++) {
		cin >> start >> finish;
		cout << (finish-start+1)-(visit[finish]-visit[start-1]) << '\n';
		
	}
}
