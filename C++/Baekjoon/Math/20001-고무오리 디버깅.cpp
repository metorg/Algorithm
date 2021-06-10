#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<string>
#include<memory.h>
#include<unordered_map>
using namespace std;
int main() {
	int cnt = 0;
	string a;
	getline(cin, a);

	while (1) {
		getline(cin, a);
		if (a == "고무오리 디버깅 끝") {
			if (cnt == 0) {
				cout << "고무오리야 사랑해";
			}
			else {
				cout << "힝구";
			}
			return 0;
		}
		if (a == "문제") {
			cnt++;
		}
		else if (a == "고무오리") {
			if (cnt == 0) {
				cnt += 2;
			}
			else
				cnt -= 1;
		}

	}
}
