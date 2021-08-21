// BOJ 4673 ���� �ѹ�
// �Լ�, ����, ����
// ���� loop�� 1~10000 �߿� self_num �ƴѰ� ��󳻱�

#include <iostream>

using namespace std;

const int mmax = 10001;

int digit_sum(int n) {
	int ret = 0;
	while (n) {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main() {
	bool is_selfn[mmax] = { false, };
	for (int st = 1; st < mmax; st++) {
		int dn = st + digit_sum(st); // next dn

		while (dn < mmax) {
			if (is_selfn[dn]) break; // �̹� dn�� self num�̸� ���� ��굵 ������ ���̶� �Ǵ�
			is_selfn[dn] = true;
			dn = dn + digit_sum(dn); // next dn
		}
	}

	// print out
	for (int i = 1; i < mmax; i++) {
		if (!is_selfn[i]) cout << i << endl;
	}

	return 0;
}

 //�ʹ� ��ư� �����߳� ? �ٸ� ȿ���� ����� ������