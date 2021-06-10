#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int k=0;
    int cnt;
    queue<pair<int,int>> q;
    for (int i = 0;i < progresses.size();i++) {
        q.push(pair<int, int>(progresses[i], speeds[i]));

    }
    while (1) {
        if (q.size() == 0)break;
        cnt = 0;
        for (k;;k++) {
           
            if (q.front().first + (q.front().second * k) >= 100)break;
        }
        
        while (1) {
            if (q.size() == 0)break;
            if (q.front().first + (q.front().second *k) >= 100) {
                q.pop();
                cnt++;
            }
            else {
                break;
            }
        }
        answer.push_back(cnt);
    }
  
    return answer;
}
