#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<memory.h>
#include<unordered_map>
using namespace std;

vector<int> lost;
vector<int> reserve;
int visit[31];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for (int i = 0; i < reserve.size(); i++) {
        visit[reserve[i]]++;
    }
    for (int i = 0; i < lost.size(); i++) {
        if (visit[lost[i]] > 0) {
            visit[lost[i]]--;
            lost[i] = -1;
        }
    }
    for (int i = 0; i < lost.size(); i++) {
        if (lost[i] == -1)continue;
        if (visit[lost[i] - 1] > 0) {
            visit[lost[i] - 1]--;
            continue;
        }
        if (visit[lost[i] + 1] > 0) {
            visit[lost[i] + 1]--;
            continue;
        }
        answer--;
    }
    cout << answer;
    return answer;
}
