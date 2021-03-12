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
#include<string>

using namespace std;

int n;
long long start, last;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> start >> last;
		long long answer = 0;
		long long cnt = 0;
		long long value = last - start;
		
		while (cnt * cnt <= value)cnt++;
		
		cnt--;
		answer =  (cnt*2) - 1;
		answer += ceil((double)(value-(cnt*cnt)) / (double)cnt);
		
		cout << answer << '\n';
	}


}