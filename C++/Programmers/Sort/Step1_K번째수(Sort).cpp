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

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> d;
    for (int i = 0; i < commands.size(); i++) {
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++) {
            d.push_back(array[j]);
        }
        sort(d.begin(), d.end());
        answer.push_back(d[commands[i][2] - 1]);
        d.clear();
    }
    return answer;
}