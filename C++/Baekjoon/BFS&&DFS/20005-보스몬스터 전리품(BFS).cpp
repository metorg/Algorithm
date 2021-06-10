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
int n, m, k;

int visit[1000][1000];
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,-1,1 };
vector<int> demage;
vector<pair<pair<int, int>, char>> user;
vector<pair<char, int>> user2;
char board[1001][1001];
int bfs(int i, int j) {
    int cnt = 0;
    queue<pair<pair<int, int>, int>> q;
    q.push({ {i,j},cnt });
    visit[i][j] = 1;
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int k = q.front().second;
        q.pop();
        for (int i = 0;i < 4;i++) {
            int c_x = x + xx[i];
            int c_y = y + yy[i];
            if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= m || board[c_x][c_y] == 'X' || visit[c_x][c_y] == 1)continue;
            if (board[c_x][c_y] == 'B') {
                return (k + 1);
            }
            q.push({ {c_x,c_y},k + 1 });
            visit[c_x][c_y] = 1;
        }
    }

}
int main() {
    cin >> n >> m >> k;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> board[i][j];
            if ('a' <= board[i][j] && board[i][j] <= 'z') {
                user.push_back({ { i,j }, board[i][j] });
            }

        }
    }
    char u;
    int dem;
    int boss;
    for (int i = 0;i < k;i++) {
        cin >> u >> dem;
        demage.push_back(dem);
    }
    cin >> boss;
    for (int i = 0;i < user.size();i++) {
        user2.push_back({ user[i].second,bfs(user[i].first.first, user[i].first.second) });
        memset(visit, 0, sizeof(visit));
    }
    sort(user2.begin(), user2.end());
    int saveuser = 0;
    while (1) {
        if (boss <= 0)break;
        for (int i = 0;i < user2.size();i++) {
            user2[i].second -= 1;
            if (user2[i].second == 0) {
                saveuser++;
            }
            if (user2[i].second <= 0) {
                boss -= demage[i];
            }
        }
    }
    cout << saveuser;
}