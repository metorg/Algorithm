#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include<cstring>
#include<stack>
#include<string.h>
#include<stdio.h>

using namespace std;
	
int visit_count[100001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int num;
	int start, finish;

	vector < pair<int, int>> people;
	priority_queue<pair<int,int>,vector<pair<int, int>>,greater<pair<int,int>>> using_seats;
	priority_queue<int, vector<int>, greater<int>> remaining_seats;
	
	int cnt = 0;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> start >> finish;
		people.push_back({ start,finish });
	}

	sort(people.begin(), people.end());

	for (int i = 0; i < people.size(); i++) {
		if (using_seats.empty()|| using_seats.top().first >= people[i].first) {
			
			if (!remaining_seats.empty()) {
				using_seats.push({ people[i].second,remaining_seats.top() });
				visit_count[remaining_seats.top()]++;
				remaining_seats.pop();
			}
			
			else {
				cnt++;
				visit_count[cnt]++;
				using_seats.push({ people[i].second,cnt });
			}
		}
		else {
			
			while (1) {//새로들어오는 사람 입실 시간 보다 사용중인 퇴실시간이 더 짧은 사람들의 좌석 번호를를 넣어둔다
				if (using_seats.top().first >= people[i].first||using_seats.empty())break;
				remaining_seats.push(using_seats.top().second);
				using_seats.pop();
			}
			
			using_seats.push({ people[i].second,remaining_seats.top() });
			visit_count[remaining_seats.top()]++;
			remaining_seats.pop();
		}
	}
	cout << cnt << '\n';
	
	for (int i = 1; i <= cnt; i++) {
		cout<<visit_count[i]<<' ';
	}
}