#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(),phone_book.end());
    for(int i=0;i<phone_book.size()-1;i++){
     if(phone_book[i+1].substr(0,phone_book[i].length())==phone_book[i])
        return false;
    }
    return answer;
}
//사전 순 정렬후 접두어만 찾기위해 현 단어를 다음 단어에 접두어에 대조하는 방법

