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

int a,b,c;
int dp[21][21][21];

int Recursion(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return  Recursion(20, 20, 20);
	else if (a < b && b < c)
	{
		if (dp[a][b][c] != 0) return dp[a][b][c];
		else return dp[a][b][c] =  Recursion(a, b, c - 1) +  Recursion(a, b - 1, c - 1) -  Recursion(a, b - 1, c);
	}
	else
	{
		if (dp[a][b][c] != 0) return dp[a][b][c];
		else return dp[a][b][c] =  Recursion(a - 1, b, c) +  Recursion(a - 1, b - 1, c) +  Recursion(a - 1, b, c - 1) -  Recursion(a - 1, b - 1, c - 1);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);


	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)break;
		cout << " w(" << a << ", " << b << ", " << c << ") = " << Recursion(a, b, c) << '\n';

	}

}
