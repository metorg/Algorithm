#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
	long long sum;
	int index1;
	int index2;
}info;

int n,num;
vector<info> c_sum;
vector<long long> v;
long long answer = 1e9;

bool cmp(const info& p1, const info& p2) {
	return p1.sum < p2.sum;	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			c_sum.push_back({ v[i] + v[j],i,j });
		}
	}
	sort(c_sum.begin(), c_sum.end(),cmp);

	for (int i = 0; i < c_sum.size()-1; i++) {
		for (int j = i+1; j < c_sum.size() ; j++) {
			if (c_sum[i].index1 != c_sum[j].index1 && c_sum[i].index1 != c_sum[j].index2 && c_sum[i].index2 != c_sum[j].index1 && c_sum[i].index2 != c_sum[j].index2) {
				answer = min(answer, c_sum[j].sum - c_sum[i].sum);
				break;
			}
		}
	}

	cout << answer;
	
}
