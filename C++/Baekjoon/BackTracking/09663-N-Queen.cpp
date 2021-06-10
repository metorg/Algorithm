#include<string>
#include <vector>
#include<queue>
#include<iostream>
#include<algorithm>

using namespace std;

int col[16];
int cnt = 0;
int N;
int check(int depth) {
    for (int j = 0;j < depth;j++) {
        if (col[depth] == col[j] || abs(col[depth] - col[j]) == depth - j) {//대각선일 경우에는 절대값을 통하여 양방향을 파악할수 있다
            return 0;
        }
    }
    return 1;
}
void queen(int depth) {
    if (depth == N) {
        cnt++;
    }
    else {
        for (int j = 0;j < N;j++) {
            col[depth] = j;
            if (check(depth) == 1) {
                queen(depth + 1);
            }
        }
    }
}
int main() {
    cin >> N;
    queen(0);
    cout << cnt;
}