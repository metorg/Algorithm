
#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<memory.h>
#include<unordered_map>

using namespace std;

int n, m;
int k, k2;
vector<int> mi;
vector<int> pl;
int mmax = 0;

int main() {
	int last = 0;
	int num;
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> num;
		if (mmax < abs(num)) {
			mmax = abs(num);
		}
		if (num < 0) {
			mi.push_back(abs(num));
		}
		else if (num > 0) {
			pl.push_back(num);
		}
	}
	k = mi.size() % m;
	sort(mi.begin(), mi.end());

	if (k != 0) {
		if (mi[k - 1] == mmax) last += mi[k - 1];
		else last += mi[k - 1] * 2;
	}

	k2 = pl.size() % m;
	sort(pl.begin(), pl.end());

	if (k2 != 0) {
		if (pl[k2 - 1] == mmax)last += pl[k2 - 1];
		else last += pl[k2 - 1] * 2;
	}


	for (int i = k - 1 + m;i < mi.size();i += m) {
		if (mi[i] == mmax)last += mi[i];
		else last += mi[i] * 2;
	}
	for (int i = k2 - 1 + m;i < pl.size();i += m) {
		if (pl[i] == mmax)last += pl[i];
		else last += pl[i] * 2;
	}
	cout << last;

}
/*���� �� �Ÿ��� ���ƿ��� �ʴ� ���� ���� ȿ������ ����̹Ƿ� ���� ��Ÿ��� ���� �����ϰ�
  ������ å���� ������ ����� å���� ������ �и��� �� ������ �̿��Ͽ� �����Ÿ����� �����Ÿ���
  ������ �Ͽ���. ���,������ ������ �ִ� ��� ���� �ִ� å���� ���� ���� �������� ���ϰ�
  �������� �ε����� �Ÿ��� ���� �Ÿ��� �������� �� �Ÿ����� �ִ�� ��� ���� �ִ� å���� ����ŭ �ε���
  �̵��� �Ͽ� �� ���� �����ִ� �������� ���־���. �׷��� �װ��� max���� ������ *2�� �����ִ� �������
  �����Ͽ���.*/