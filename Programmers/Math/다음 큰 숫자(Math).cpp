#include <string>
#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

int solution(int n) {

    int cnt = bitset<20>(n).count();

    //bitset<>.count()는 이진수에 1의 갯수를 체크해준다
    while (1) if (cnt == bitset<20>(++n).count())break;

    return n;
}