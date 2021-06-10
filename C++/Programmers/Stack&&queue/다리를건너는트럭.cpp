#include <string>
#include <vector>
#include<queue>
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    int cnt = 0;
    int size = 0;
    int brk = 0;
    int i;
    
    queue<pair<int, int>> q;
    for (i = 0;;i++) {
        if (i != 0) {//처음만 제외하고 적용
            if (q.front().first == i) {//q 안에는 pair(경과시간과,트럭의 무게)가 들어간다
                sum -= q.front().second;//경과 시간과 i가 같을시 현재 다리를 지나는 트럭총 중량값에서 트럭의 무게를 빼고 팝시킨다
                q.pop();
                brk++;
            }
        }
        if (size < truck_weights.size()) {
            sum += truck_weights[size];
            if (sum <= weight) {//경과시간은 경과시간+다리의 들어간 시간을 넣어준다
                q.push(pair<int, int>(bridge_length+i, truck_weights[size++]));
            }
            else {
                sum -= truck_weights[size];
            }
        }
        if (brk == truck_weights.size())break;
        
    }
    answer = i+1;
    return answer;
}
