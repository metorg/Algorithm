#include <string>
#include <iostream>

using namespace std;

int main(void) {

    string s;
    cin >> s;

    int len = s.length();
    bool correct;

    for (int i = 0; i < len; i++) {
        correct = true;
        for (int j = i; j < len; j++) {
            if (s[j] != s[len - 1 - (j - i)]) {
                correct = false;
                break;
            }
        }
        if (correct) {
            cout << len + i;
            break;
        }
    }
}
