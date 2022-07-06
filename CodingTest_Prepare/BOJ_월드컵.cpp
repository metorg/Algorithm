#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

int team1[15] = { 0,0,0,0,0,1,1,1,1,2,2,2,3,3,4 };
int team2[15] = { 1,2,3,4,5,2,3,4,5,3,4,5,4,5,5 };
int match[6][3], result[6][3],answer[4];

void dfs(int group, int round) {
	
    if (answer[group])return;//이미 맞는 케이스일 경우 return
	if (round == 15) {//전체 케이스가 맞는지 확인 
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				if (match[i][j] != result[i][j])return;
			}
		}
		answer[group] = 1;
		return;
	}
    
    //team1 승 team2 패
	result[team1[round]][0]++;
	result[team2[round]][2]++;
	dfs(group, round + 1);
	result[team1[round]][0]--;
	result[team2[round]][2]--;
    //team1 team2 무승부
	result[team1[round]][1]++;
	result[team2[round]][1]++;
	dfs(group, round + 1);
	result[team1[round]][1]--;
	result[team2[round]][1]--;
    //team1 패 team2 승
	result[team1[round]][2]++;
	result[team2[round]][0]++;
	dfs(group, round + 1);
	result[team1[round]][2]--;
	result[team2[round]][0]--;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for (int r = 0; r < 4; r++) {

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> match[i][j];
			}
		}
		dfs(r, 0);
	}
	
	for (int i = 0; i < 4; i++) {
		cout << answer[i] << ' ';
	}
}
