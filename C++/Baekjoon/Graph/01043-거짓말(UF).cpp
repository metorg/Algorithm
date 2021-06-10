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

int parent[51];
int n, m, real_people_num,num;
int party_people_num;
vector<int> party_people[51];
vector<int> real_people;

int find(int a) {
	if (parent[a] == a)return a;
	return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	parent[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	cin >> real_people_num;

	for (int i = 1;i <= n;i++)parent[i] = i;
	
	for (int i = 0;i < real_people_num;i++) {
		cin >> num;
		real_people.push_back(num);
	}

	int prev;

	for (int i = 0;i < m;i++) {
		cin >> party_people_num;
		for (int j = 0;j < party_people_num;j++) {
			if (j > 0) {//파티마다 같은 숫자가 있으면 모두 같은파티로 보고 묶어버린다.
				prev = num;
				cin >> num;
				Union(prev, num);
			}
			else cin >> num;
			
			party_people[i].push_back(num);
		}
	}
	
	int answer = m;

	for (int i = 0;i < m;i++) {
		int flag = 0;
		
		for (int j = 0;j < party_people[i].size();j++) {
			if (flag)break;
			
			for (int k = 0;k < real_people.size();k++) {
				if (find(party_people[i][j]) == find(real_people[k])) {
					flag = 1;
					break;
				}
			}
		}
		if (flag) answer--;

	}
	cout << answer;

}