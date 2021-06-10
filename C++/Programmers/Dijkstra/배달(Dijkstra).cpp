#include <string>
#include <vector>
#include<queue>

#define INF 1e9

using namespace std;


int dist[51];

vector<vector<pair<int, int>>> v(51);

void dijkstra() {
    
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,1 });
    dist[1] = 0;

    while (!pq.empty()) {

        int wt = -pq.top().first;
        int start = pq.top().second;
        pq.pop();
        
        if(dist[start]<wt)continue;
        
        for (int i = 0; i < v[start].size(); i++) {
            int n_wt = v[start][i].second;
            int n_start = v[start][i].first;
            if (dist[n_start] > n_wt + wt) {
                dist[n_start] = n_wt + wt;
                pq.push({ -dist[n_start],n_start });
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for (int i = 1; i <= N; i++) dist[i] = INF;

    for (int i = 0; i < road.size(); i++) {
        v[road[i][0]].push_back({ road[i][1],road[i][2] });
        v[road[i][1]].push_back({ road[i][0],road[i][2] });
    }
    dijkstra();
    
    for (int i = 1; i <= N; i++) if (dist[i] <= K)answer++;
    
    return answer;
}