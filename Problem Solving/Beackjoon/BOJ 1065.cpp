// BOJ 1065 �Ѽ�

#include <iostream>

using namespace std;

bool is_hannum(int n) {
	if (n == 1000) return false;

	// ���� ���� Ư¡: (���� �� ���� ��)������ ���� ���� == ����� * 2
	if ((n / 100) % 10 + (n % 10) == ((n / 10) % 10)*2) return true;
	else return false;
}

int main() {
	int N = 0; cin >> N;
	int ans = 0;

	if (N < 100) ans = N;
	else { // N�� ���ڸ���
		ans = 99; // ���ڸ� ���� ��� �Ѽ�
		for (int i = 100; i <= N; i++) {
			if (is_hannum(i)) ans++;
		}
	}

	cout << ans << endl;

	return 0;
}