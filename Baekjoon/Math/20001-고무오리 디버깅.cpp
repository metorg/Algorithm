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
		if (a == "������ ����� ��") {
			if (cnt == 0) {
				cout << "�������� �����";
			}
			else {
				cout << "����";
			}
			return 0;
		}
		if (a == "����") {
			cnt++;
		}
		else if (a == "������") {
			if (cnt == 0) {
				cnt += 2;
			}
			else
				cnt -= 1;
		}

	}
}
