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
int answer2 = 2e9;
void dfs(string name, int cnt, int change, int r) {
    if (r < 0) r = name.length() - 1;
    if (r > name.length()) r = 0;
    if (name[r] != 'A') {
        change--;
        name[r] = 'A';
    }
    if (change == 0) {
        answer2 = min(answer2, cnt);
        return;
    }
    if (cnt > name.length() - 1)return;
    dfs(name, cnt + 1, change, r + 1);
    dfs(name, cnt + 1, change, r - 1);
}
int solution(string name) {
    int answer = 0;
    int change = 0;

    for (int i = 0;i < name.length();i++) {
        if (name[i] != 'A')change++;
        int cnt = ('Z' - name[i]) + 1;
        int cnt2 = name[i] - 'A';
        int mcnt = min(cnt, cnt2);
        answer += mcnt;
    }

    dfs(name, 0, change, 0);
    return answer + answer2;
}
