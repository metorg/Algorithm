#include <iostream>
#include <vector>
#include <queue>

//key point: 방문처리 신경쓸 것
using namespace std;

typedef struct {
	int x;
	int y;
	int time;
}info;

int board[101][101];
int visit[101][101];
int n, m;
int answer;
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,-1,1 };
vector<pair<int, int>> v;

void reset(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			visit[i][j]=0;
		}
	}
}

int bfs(int x,int y) {

	queue<info> q;
	q.push({x,y,0});
		
	while (!q.empty()) {
			
			int x = q.front().x;
			int y = q.front().y;
			int time = q.front().time;
			q.pop();
		
			for (int i = 0; i < 4; i++) {
				
				int c_x = x + xx[i];
				int c_y = y + yy[i];
				
				if(board[c_x][c_y]==2)return 0;
				if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= n||time+1==m||visit[c_x][c_y])continue;
				
				visit[c_x][c_y]=1;
				q.push({ c_x,c_y,time + 1 });
			}
		}
		
		return 1;
}

int main() {

	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {
			cin >> board[i][j];

			if (board[i][j] == 1) {
				v.push_back({ i,j });
				answer++;
			}
		}
	}
	for(int i=0;i<v.size();i++){
		
		visit[v[i].first][v[i].second]=1;
		answer-=bfs(v[i].first,v[i].second);
		if(answer==0)break;
		reset();
		
	}

	cout << answer;

	return 0;
}
