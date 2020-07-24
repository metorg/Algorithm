#include <string>
#include <vector>
#include<queue>
#include<iostream>
#include<algorithm>


using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int cnt = 0;
    
    vector<pair<int, int>>q;
    vector<pair<int, int>>temp;
    for (int i = 0;i < priorities.size();i++) {//pair 함수를 이용하여 위치값과 벨류값을 새벡터안에 넣는다
        q.push_back(pair<int, int>(i, priorities[i]));
    }
    
        for (int i = 0;i < q.size();i++) {
            if (temp.size() == priorities.size())break;
            cnt = 0;
            for (int j = i + 1;j < q.size();j++) {//맨처음 원소와 그이외 원소를 비교해본후 뒤에 원소가 크면 벡터 뒤에 추가
                if (q[i].second < q[j].second) {
                    q.push_back(pair<int, int>(q[i].first,q[i].second));
                    cnt++;
                    break;
                }
            }
            if (cnt == 0) {//작으면 정답 벡터안의 추가한다
                temp.push_back(pair<int, int>(q[i].first, q[i].second));
            }
        }
        q.empty();
      
        for (int i = 0;i < temp.size();i++) {
            if (temp[i].first == location) {
                answer= i;
                break;
            }
      }
        temp.empty();
        if (answer == priorities.size()) {
            return 0;
        }
        else {
            return answer+1;
        }
}
