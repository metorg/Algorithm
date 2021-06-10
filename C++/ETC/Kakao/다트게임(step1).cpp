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
int solution(string dartResult) {
    int sum = 0;
    int msum = 0;
    int k = 0;
    for (int i = 0;i < dartResult.size();i++) {
        //cout << sum <<' '<<msum<<' '<<k<< '\n';
        if ('0' <= dartResult[i] && dartResult[i] <= '9') {
            if (i != 0 && '0' <= dartResult[i - 1] && dartResult[i - 1] <= '9') {
                sum = (sum * 10) + dartResult[i] - '0';
            }
            else {
                sum = dartResult[i] - '0';
            }
        }
        else {
            if (dartResult[i] == '*') {
                sum = sum * 2;
                if ('0' <= dartResult[i + 1] && dartResult[i + 1] <= '9') {
                    msum -= k;
                    k = k * 2;
                    msum += k;
                    if (k == 0) {
                        k = sum;
                    }
                    msum += sum;
                    k = sum;
                    sum = 0;
                }
                else if (dartResult[i] == '*' && i == dartResult.size() - 1) {
                    msum -= k;
                    k = k * 2;
                    msum += k;

                }
            }
            else if (dartResult[i] == '#') {
                sum = -sum;
                if ('0' <= dartResult[i + 1] && dartResult[i + 1] <= '9') {
                    k = sum;
                    msum += sum;
                    sum = 0;
                }

            }
            else if (dartResult[i] == 'D') {
                sum = sum * sum;
                if ('0' <= dartResult[i + 1] && dartResult[i + 1] <= '9') {
                    k = sum;
                    msum += sum;
                    sum = 0;
                }
            }
            else if (dartResult[i] == 'S') {
                sum = sum * 1;
                if ('0' <= dartResult[i + 1] && dartResult[i + 1] <= '9') {
                    k = sum;
                    msum += sum;
                    sum = 0;
                }
            }
            else if (dartResult[i] == 'T') {
                sum = sum * sum * sum;
                if ('0' <= dartResult[i + 1] && dartResult[i + 1] <= '9') {
                    k = sum;
                    msum += sum;
                    sum = 0;
                }
            }

        }
    }
    msum += sum;

    cout << msum;
    return msum;
}