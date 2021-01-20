#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include<set>

using namespace std;

int flag = 0;
vector<pair<int, int>> store;

void bfs(int x, int y, int d_x, int d_y) {
	queue<pair<int, int>> q;
	q.push({ x,y });

	int visite[101] = {};
	
	while (!q.empty()) {
		
		int xx = q.front().first;
		int yy = q.front().second;
		if ((abs(d_x - xx) + abs(d_y - yy)) <= 1000) {
			flag = 1;
			return;
		}
		q.pop();
		
		for (int i = 0;i < store.size();i++) {
			if (visite[i] == 1)continue;
			if ((abs(store[i].first - xx) + abs(store[i].second - yy)) <= 1000) {
				q.push({ store[i].first,store[i].second });
				visite[i] = 1;
			}
		}
	}
}


int main() {

	int n, m;
	int x, y;
	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> m;
		pair<int, int> house;
		flag = 0;
		cin >> x >> y;

		house.first = x;
		house.second = y;

		for (int j = 0;j < m;j++) {
			cin >> x >> y;
			store.push_back({ x,y });
		}

		cin >> x >> y;


		bfs(house.first, house.second, x, y);

		if (flag == 1)cout << "happy" << '\n';
		else cout << "sad" << '\n';
		store.clear();

	}

}