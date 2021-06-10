#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	std::sort(participant.begin(), participant.end());
	std::sort(completion.begin(), completion.end());
	for (int i = 0;i < participant.size();i++) {
		//cout << participant[i];
	}
	for (int i = 0;i < completion.size();i++) {
		//cout << completion[i];
	}
	int num = 0;

	for (int i = 0, j = 0;i < participant.size();j++, i++) {
		if (i == participant.size() - 1)
			return participant[i];
		if (participant[i] != completion[i]) {
			return participant[i];
		}
	}


}