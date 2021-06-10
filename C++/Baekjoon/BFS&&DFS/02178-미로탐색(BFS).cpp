#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int N, M;
char miro[101][101];
int visit[101][101];
int xx[4] = { 0, 0 ,-1 ,1 };
int yy[4] = { -1, 1, 0, 0 };

void bfs() {

    int a = 0;
    int b = 0;
    int cnt = 1;
    int x_c;
    int y_c;

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));    //첫째pair 위치, 둘째pair 움직인거리


    while (!q.empty()) {

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == M - 1 && y == N - 1)
            return;

        for (int i = 0;i < 4;i++) {
            x_c = x;
            y_c = y;
            x_c = x_c + xx[i];
            y_c = y_c + yy[i];
            if (x_c < 0 || y_c < 0 || x_c >= N || y_c >= M || visit[x_c][y_c] != -1 || miro[x_c][y_c] == '0') {
                continue;

            }
            else {
                q.push(make_pair(x_c, y_c));

                visit[x_c][y_c] = visit[x][y] + 1;
            }
        }
    }
}


int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> miro[i];
    }
    memset(visit, -1, sizeof(visit));
    bfs();

    cout << visit[N - 1][M - 1];

}

