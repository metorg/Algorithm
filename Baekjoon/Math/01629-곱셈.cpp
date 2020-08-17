#include<string>
#include <vector>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

long long a, b, c;

long long bigC(long long a, long long b, long long c) {
	//종료조건
	if (b == 0)return 1;
	long long answer = bigC(a, b / 2, c);//big(logb)
	answer = (answer) * (answer) % c;
	if (b % 2 == 1) return answer * a % c;
	return answer;
}
int main() {
	long long sum, sum2;
	cin >> a >> b >> c;
	cout << bigC(a, b, c);

}