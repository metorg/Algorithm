#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    long long sum = 0;

    vector<long long> num;
    vector<char> oper;

    for (int i = 0; i < expression.size(); i++) {
        if ('0' <= expression[i] && expression[i] <= '9') {
            sum = (sum * 10) + (expression[i] - '0');
        }
        else {
            num.push_back(sum);
            oper.push_back(expression[i]);
            sum = 0;
        }
    }
    num.push_back(sum);

    vector<char> str= { '*','+','-' };


    do {
        vector<long long> c_num=num;
        vector<char> c_oper=oper;

        for (int i = 0; i < str.size(); i++) {
            for (int j = 0; j < c_num.size()-1;) {
                if (str[i] == c_oper[j]) {
                    long long tmp=0;
                    if (c_oper[j] == '-') {
                        tmp = c_num[j] - c_num[j + 1];
                    }
                    if (c_oper[j] == '+') {
                        tmp = c_num[j] + c_num[j + 1];
                    }
                    if (c_oper[j] == '*') {
                        tmp = c_num[j] * c_num[j + 1];
                    }
                    cout<<tmp<<'\n';
                    c_num.erase(c_num.begin() + j);
                    c_num.erase(c_num.begin() + j);
                    c_oper.erase(c_oper.begin() + j);
                    c_num.insert(c_num.begin() + j, tmp);
                }
                else {
                j++;
                 }

            }   
        }
        answer = max(answer, abs(c_num[0]));
    } while (next_permutation(str.begin(), str.end()));
    return answer;
}
