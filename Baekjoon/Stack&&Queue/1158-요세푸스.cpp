#include <string>
#include <vector>
#include<queue>
#include<iostream>
#include<algorithm>


using namespace std;

int main() {
	queue<int> q;
	int cnt = 0;
	int num, num2;
	int temp;
	int ccnt = 0;
	cin >> num >> num2;
	for (int i = 1;i <= num;i++) {
		q.push(i);
	}
	cout << "<";
	while (!q.empty()) {
		cnt++;
		if (cnt == num2 && ccnt != num - 1) {
			cout << q.front() << ", ";
			q.pop();
			cnt = 0;
			ccnt++;

		}
		else if (ccnt == num - 1) {
			cout << q.front();
			q.pop();

		}


		else {
			temp = q.front();
			q.pop();
			q.push(temp);

		}
	}
	cout << ">";
}