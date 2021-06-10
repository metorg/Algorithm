#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include<stdio.h>
#include<string.h>
#include<set>

using namespace std;

int n, m;
int a, b, c, d;
int board[1025][1025];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n>>m;
	
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cin >> board[i][j];
			board[i][j] += board[i][j - 1]+board[i-1][j]-board[i-1][j-1];
		}		
	}

	for (int i = 0;i < m;i++) {
		cin >> a >> b >> c >> d;
		
		cout<<board[c][d] - board[c][b-1] - board[a-1][d] + board[a-1][b-1]<<'\n';
	}
}