#include <string>
#include <vector>
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include<stack>
#include<memory.h>
#include<unordered_map>
#include<set>
#include<bitset>

using namespace std;

int arr[1000][1000];

vector<int> solution(int n) {

    vector<int> answer;
    int x = -1, y = 0;
    int num = 1;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i % 3 == 0) {
                x++;
            }
            else if (i % 3 == 1) {
                y++;
            }
            else if (i % 3 == 2) {
                x--;
                y--;
            }
            arr[x][y] = num++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            answer.push_back(arr[i][j]);
        }
    }
    return answer;
}