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

int visit[1000];//¹®Á¦ 1¹ø
 vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for (int i = 0;i < numbers.size();i++) {
        for (int j = i + 1;j < numbers.size();j++) {
            if (!visit[numbers[i] + numbers[j]]) {
                answer.push_back(numbers[i] + numbers[j]);
                visit[numbers[i] + numbers[j]] = 1;
            }
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}
int main() {
    vector<int> a = { 2,1,3,4,1 };
    solution(a);
}