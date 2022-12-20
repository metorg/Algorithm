#include<bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<long long, long long>> hallway[100007];
int room[100007];
long long dist[100007][10];
long long answer=-1;
long long num1, num2;
long long val;


void dijkstra() {
    priority_queue<pair<long long,pair<long long,long long>>> pq;
    pq.push({ 0, { 0,1} });

    while (!pq.empty()) {
        long long val = -pq.top().first;
        long long prev = pq.top().second.first;
        long long cur = pq.top().second.second;
        pq.pop();
				
				if(cur==N){
					answer=val;
					return;
				}
        for (int i = 0; i < hallway[cur].size(); i++) {
            long long next_cur = hallway[cur][i].first;
            long long next_val = hallway[cur][i].second;
            
					
					  if(next_cur==prev)continue;
          	if ((cur!=1)&&prev % room[cur] != next_cur % room[cur])continue;
            
            if (dist[next_cur][cur%room[next_cur]] <= next_val + val)continue;
            dist[next_cur][cur%room[next_cur]] = next_val + val;
            pq.push({ -dist[next_cur][cur%room[next_cur]],{cur%room[next_cur],next_cur}});
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (long long i = 1; i <= N; i++) {
        cin >> room[i];
    }

    for (long long i = 0; i < M; i++) {
        cin >> num1 >> num2 >> val;
        hallway[num1].push_back({num2, val});
        hallway[num2].push_back({num1, val});
    }

    memset(dist,0x3f,sizeof(dist));
    dist[1][0] = 0;
    dijkstra();
    cout<<answer;
}
