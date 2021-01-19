#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include<set>

using namespace std;

int n, num,cnt;
string wear, kind;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> num;
		cnt = 1;	
		unordered_map<string,int> map;
		for (int j = 0;j < num;j++) {
			cin >> wear >> kind;

			if (map.find(kind) == map.end())map.insert({ kind,1 });
			else map[kind]++;		
		}
		for (auto i : map)
		{
			cnt *= (i.second + 1);
		}
		cnt -= 1;
		cout << cnt << '\n';
	}
}