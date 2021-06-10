#include <string>
#include <vector>

using namespace std;
int len(string s) {
    if (s.length() == 4 || s.length() == 6) {
        return 1;
    }
    else return 0;
}
bool solution(string s) {
    bool answer = true;
    int cnt = 0;
    int t = len(s);
    if (t == 1) {
        for (int i = 0; i < s.length(); i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                cnt++;
            }
        }
        if (cnt == s.length()) answer = true;
        else answer = false;
    }
    else answer = false;
    return answer;
}