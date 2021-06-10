#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

int visit[201] = { 0 };
void dfs(int target, vector<vector<int>>computers) {
    visit[target] = 1;
    for (int i = 0;i < computers.size();i++) {
        if ((!visit[i]) && (computers[target][i] == 1)) {
            dfs(i, computers);
        }
    }

}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0;i < computers.size();i++) {
        if (!visit[i]) {
            dfs(i, computers);

            answer++;
        }
    }
    cout << answer;
    return answer;
}