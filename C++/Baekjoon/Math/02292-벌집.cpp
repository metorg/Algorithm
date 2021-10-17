#include<iostream>

using namespace std;

int main() {
	int a;
	int b=1;
	int cnt = 1;
	cin>>a;
	for (int i = 0;; i++, cnt++) {
		b+= (i * 6);
		if (a <= b) {
			cout<<cnt;
			return 0;
		}
	}
}