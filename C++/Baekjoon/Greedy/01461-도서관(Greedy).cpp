
#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<memory.h>
#include<unordered_map>

using namespace std;

int n, m;
int k, k2;
vector<int> mi;
vector<int> pl;
int mmax = 0;

int main() {
	int last = 0;
	int num;
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> num;
		if (mmax < abs(num)) {
			mmax = abs(num);
		}
		if (num < 0) {
			mi.push_back(abs(num));
		}
		else if (num > 0) {
			pl.push_back(num);
		}
	}
	k = mi.size() % m;
	sort(mi.begin(), mi.end());

	if (k != 0) {
		if (mi[k - 1] == mmax) last += mi[k - 1];
		else last += mi[k - 1] * 2;
	}

	k2 = pl.size() % m;
	sort(pl.begin(), pl.end());

	if (k2 != 0) {
		if (pl[k2 - 1] == mmax)last += pl[k2 - 1];
		else last += pl[k2 - 1] * 2;
	}


	for (int i = k - 1 + m;i < mi.size();i += m) {
		if (mi[i] == mmax)last += mi[i];
		else last += mi[i] * 2;
	}
	for (int i = k2 - 1 + m;i < pl.size();i += m) {
		if (pl[i] == mmax)last += pl[i];
		else last += pl[i] * 2;
	}
	cout << last;

}
/*가장 먼 거리는 돌아오지 않는 것이 가장 효율적인 방법이므로 가장 긴거리의 값을 저장하고
  음수의 책들의 갯수와 양수의 책들의 갯수를 분리한 후 정렬을 이용하여 적은거리부터 많은거리고
  정렬을 하였다. 양수,음수의 갯수를 최대 들고 갈수 있는 책들의 수로 각각 나머지를 구하고
  나머지의 인덱스의 거리를 최종 거리의 더해준후 그 거리부터 최대로 들고 갈수 있는 책들의 수만큼 인덱스
  이동을 하여 그 값을 더해주는 형식으로 해주었다. 그러나 그값이 max값과 같으면 *2를 안해주는 방식으로
  구현하여다.*/