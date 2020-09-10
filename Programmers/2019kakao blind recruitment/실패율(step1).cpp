#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<algorithm>
#include<string.h>
#include<string>
#include<stdio.h>
#include<stack>
#include<memory.h>

using namespace std;
bool compare(const pair<double, int>& a, const pair<double, int>& b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}//first 와 second  둘다 다루고싶으면 compare함수 적극활용
vector<int> solution(int N, vector<int> stages) {
    vector<pair<double, int>> answer;
    vector<int>last_answer;
    double cnt = stages.size();
    double count = 0;
    for (int j = 1;j <= N;j++) {
        count = 0;
        for (int i = 0;i < stages.size();i++) {
            if (j == stages[i]) {
                count++;
            }

        }
        if (count == 0) {//0인경우는 나눠질때 예외처리가 생김
            answer.push_back({ 0,j });
        }
        else {
            answer.push_back({ (count / cnt),j });
        }
        cnt = cnt - count;
    }

    sort(answer.begin(), answer.end(), compare);
    for (int i = 0;i < answer.size();i++) {
        last_answer.push_back(answer[i].second);
    }
    return last_answer;
}

int main() {
    int N = 5;//예제들
    vector<int>stages = { 2,1,2,6,2,4,3,3 };
    int N = 4;
    vector<int>stages = { 4,4,4,4,4 };
    solution(N, stages);



}