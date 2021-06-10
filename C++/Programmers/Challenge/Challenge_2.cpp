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

int solution(vector<int> a) {
    int answer = 0;

    return answer;
}
int main() {
    vector<int> a = { -16,27,65,-2,58,-92,-71,-68,-61,-33 };
    solution(a);
}


int arr[1001][1001];//¹®Á¦ 2¹ø
vector<int> solution(int n) {


    vector<int> answer;
    int x = -1, y = -1;
    int num = 1;
    int size = 0;
    for (int i = 1;i <= n;i++) {
        size += i;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (i % 3 == 0) {
                x++;
                y++;
            }
            else if (i % 3 == 1) {
                y--;
            }
            else if (i % 3 == 2) {
                x--;
            }
            arr[x][y] = num++;
        }
    }
    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; --j) {
            answer.push_back(arr[i][j]);
        }
    }
    return answer;
}