#include <string>
#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

int solution(int n) {

    int cnt = bitset<20>(n).count();

    //bitset<>.count()�� �������� 1�� ������ üũ���ش�
    while (1) if (cnt == bitset<20>(++n).count())break;

    return n;
}