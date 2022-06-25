#include<vector>
#include<queue>

using namespace std;

int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,-1,1 };
int visit[101][101];
int board[101][101];
int n, m;

typedef struct {
    int x;
    int y;
    int dist;
}info;

int bfs() {
    
    queue<info> q;
    q.push({ 0,0,1 });
    visit[0][0] = 1;
    
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int dist = q.front().dist;
        q.pop();
        
        if (x == n - 1 && y == m - 1) {
            return dist;
        }

        for (int i = 0; i < 4; i++) {            
            int c_x = x + xx[i];
            int c_y = y + yy[i];
            if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= m || !board[c_x][c_y] || visit[c_x][c_y])continue;
            q.push({ c_x,c_y,dist + 1 });
            visit[c_x][c_y] = 1;
        }
    }
    return -1;
}
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            board[i][j] = maps[i][j];
        }
    }
    answer = bfs();
    return answer;
}
