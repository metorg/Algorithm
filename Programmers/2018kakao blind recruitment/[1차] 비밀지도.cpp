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

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {

    string d;

    vector<string> answer;
    for (int i = 0;i < n;i++) {
        d = "";

        for (int j = 0;j < n;j++) {
            if (arr1[i] % 2 == 1 || arr2[i] % 2 == 1) {
                d += '#';
            }
            else {
                d += " ";
            }
            arr1[i] = arr1[i] / 2;
            arr2[i] = arr2[i] / 2;
        }
        reverse(d.begin(), d.end());
        answer.push_back(d);
    }
    return answer;
}


int main() {
    int n = 5;
    vector<int>ar1 = { 9,20,28,18,11 };
    vector<int>ar2 = { 30,1,21,17,28 };
    solution(n, ar1, ar2);

}