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


	int A;
	cin >> A;

	for (int i = 1;i <= A;i++) {
		if (30 % (i + 1) == 0) {
			cout << i << '\n';
		}
	}
}
