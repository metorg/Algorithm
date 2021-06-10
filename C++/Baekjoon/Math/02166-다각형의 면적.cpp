#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<memory.h>
#include<unordered_map>
#include<set>
#include<bitset>

using namespace std;

int vertex;
double x, y;
double sum = 0;
double answer = 0;

vector<pair<double, double>> v;

void area(int a, int b, int c) {

	sum = 0;
	sum = (v[a].first * v[b].second) + (v[b].first * v[c].second) + (v[c].first * v[a].second);
	sum -= (v[b].first * v[a].second) + (v[c].first * v[b].second) + (v[a].first * v[c].second);
	answer += sum;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> vertex;
	for (int i = 0;i < vertex;i++) {
		cin >> x >> y;
		v.push_back({ x,y });
	}

	for (int i = 1;i < v.size() - 1;i++) {
		area(0, i, i + 1);
	}

	answer = answer * 0.5;
	printf("%.1lf", abs(answer));
}
