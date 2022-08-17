#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct {
	int a;
	int b;
	int c;
}info;

int visit[201][201][201];
vector<int> answer;
int a, b, c;

void bfs() {
	
	queue<info> q;
	q.push({ 0,0,c });
	visit[0][0][c] = 1;

	while (!q.empty()) {
		
		int c_a = q.front().a;
		int c_b = q.front().b;
		int c_c = q.front().c;
		q.pop();
		if (c_a == 0 ) {
			answer.push_back(c_c);
		}

		//case1 a에서 나눠줄때
		if (c_a != 0) {
			if (c_a < b - (c_b)) {
				if (!visit[0][c_b + c_a][c_c]) {
					q.push({ 0,c_b + c_a,c_c });
					visit[0][c_b + c_a][c_c] = 1;
				}
				
			}
			else {
				if (!visit[c_a - (b - c_b)][b][c_c]) {
					q.push({ c_a - (b - c_b),b,c_c });
					visit[c_a - (b - c_b)][b][c_c] = 1;
				}
			}
			if (c_a < c - (c_c)) {
				if (!visit[0][c_b][c_c+c_a]) {
					q.push({ 0,c_b,c_c+c_a });
					visit[0][c_b][c_c+c_a] = 1;
				}

			}
			else {
				if (!visit[c_a - (c - c_c)][c_b][c]) {
					q.push({ c_a - (c - c_c),c_b,c });
					visit[c_a - (c - c_c)][c_b][c] = 1;
				}
			}
		}
    //case2 b에서 나눠줄때
		if (c_b != 0) {
			if (c_b < a - (c_a)) {
				if (!visit[c_b+c_a][0][c_c]) {
					q.push({ c_b + c_a,0,c_c });
					visit[c_b + c_a][0][c_c] = 1;
				}

			}
			else {
				if (!visit[a][c_b - (a - c_a)][c_c]) {
					q.push({a,c_b - (a - c_a),c_c });
					visit[a][c_b - (a - c_a)][c_c] = 1;
				}
			}
			if (c_b < c - (c_c)) {
				if (!visit[c_a][0][c_c + c_b]) {
					q.push({ c_a ,0,c_c + c_b });
					visit[c_a][0][c_c + c_b] = 1;
				}

			}
			else {
				if (!visit[c_a][c_b - (c - c_c)][c]) {
					q.push({ c_a, c_b - (c - c_c),c });
					visit[c_a][c_b - (c - c_c)][c] = 1;
				}
			}
		}
    //case3 c에서 나눠줄때
		if(c_c!=0) {
			if (c_c < a - (c_a)) {
				if (!visit[c_c + c_a][c_b][0]) {
					q.push({ c_c + c_a,c_b,0 });
					visit[c_c + c_a][c_b][0] = 1;
				}
			}
			else {
				if (!visit[a][c_b][c_c-(a-c_a)]) {
					q.push({ a,c_b,c_c-(a-c_a)});
					visit[a][c_b][c_c - (a - c_a)] = 1;
				}
			}
			if (c_c < b - (c_b)) {
				if (!visit[c_a][c_c + c_b][0]) {
					q.push({ c_a ,c_c + c_b,0 });
					visit[c_a][c_c + c_b][0] = 1;
				}

			}
			else {
				if (!visit[c_a][b][c_c - (b - c_b)]) {
					q.push({ c_a,b,c_c-(b-c_b) });
					visit[c_a][b][c_c - (b - c_b)] = 1;
				}
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b >> c;
	
	bfs();

	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ' ';
	}
	

}
