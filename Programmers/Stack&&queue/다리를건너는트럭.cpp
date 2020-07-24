#include <string>
#include <vector>
#include<queue>
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    int cnt = 0;
    int size = 0;
    int brk = 0;
    int i;
    
    queue<pair<int, int>> q;
    for (i = 0;;i++) {
        if (i != 0) {//ó���� �����ϰ� ����
            if (q.front().first == i) {//q �ȿ��� pair(����ð���,Ʈ���� ����)�� ����
                sum -= q.front().second;//��� �ð��� i�� ������ ���� �ٸ��� ������ Ʈ���� �߷������� Ʈ���� ���Ը� ���� �˽�Ų��
                q.pop();
                brk++;
            }
        }
        if (size < truck_weights.size()) {
            sum += truck_weights[size];
            if (sum <= weight) {//����ð��� ����ð�+�ٸ��� �� �ð��� �־��ش�
                q.push(pair<int, int>(bridge_length+i, truck_weights[size++]));
            }
            else {
                sum -= truck_weights[size];
            }
        }
        if (brk == truck_weights.size())break;
        
    }
    answer = i+1;
    return answer;
}
