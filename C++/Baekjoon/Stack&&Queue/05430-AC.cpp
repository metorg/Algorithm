#include <string>
#include <vector>
#include<queue>
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	deque<int> dq;
	int num;
	int flag = 1;
	int num2;
	int num3;
	int br = 0;
	int sum = 0;
	string a;
	string d;


	cin >> num;
	for (int i = 0;i < num;i++) {
		a = { NULL };
		d = { NULL };
		cin >> a;
		cin >> num2;
		cin >> d;
		for (int j = 0;j < d.size();j++) {
			if ('0' <= d[j] && d[j] <= '9') {
				sum = sum + d[j] - '0';
				if ('0' <= d[j + 1] && d[j + 1] <= '9') {
					sum *= 10;
				}
				else {
					dq.push_back(sum);
					sum = 0;
				}
			}

		}
		for (int j = 0;j < a.size();j++) {
			if (a[j] == 'R') {
				flag = -flag;
			}
			else if (a[j] == 'D') {
				if (dq.empty() == 1) {
					cout << "error";
					br++;
					break;

				}
				if (flag > 0) {
					dq.pop_front();
				}
				else if (flag < 0) {
					dq.pop_back();
				}
			}
		}
		if (br == 1) {
		}
		else {
			cout << '[';
			if (flag == -1) {
				while (!dq.empty()) {
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty()) {
						cout << ',';
					}
				}
			}
			else {
				while (!dq.empty()) {
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty()) {
						cout << ',';
					}
				}
			}
			cout << ']';
		}

		cout << '\n';
		dq.clear();
		flag = 1;
		br = 0;
	}

}