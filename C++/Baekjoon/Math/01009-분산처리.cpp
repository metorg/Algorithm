#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include<cmath>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,num, num2,result;
	
	cin >> n;	
	for (int i = 0; i < n; i++) {
		cin >> num >> num2;
		
		result = 0;
		num2 = num2 % 4;
		
		if (num2 == 0)num2 = 4;
		result=pow(num, num2);
		
		if (result % 10 == 0)cout << 10<<'\n';
		else cout << result % 10 << '\n';
	}

}

