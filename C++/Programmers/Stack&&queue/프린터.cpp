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
    for (int i = 0;i < priorities.size();i++) {//pair �Լ��� �̿��Ͽ� ��ġ���� �������� �����;ȿ� �ִ´�
        q.push_back(pair<int, int>(i, priorities[i]));
    }
    
        for (int i = 0;i < q.size();i++) {
            if (temp.size() == priorities.size())break;
            cnt = 0;
            for (int j = i + 1;j < q.size();j++) {//��ó�� ���ҿ� ���̿� ���Ҹ� ���غ��� �ڿ� ���Ұ� ũ�� ���� �ڿ� �߰�
                if (q[i].second < q[j].second) {
                    q.push_back(pair<int, int>(q[i].first,q[i].second));
                    cnt++;
                    break;
                }
            }
            if (cnt == 0) {//������ ���� ���;��� �߰��Ѵ�
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
