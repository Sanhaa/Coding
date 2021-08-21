// BOJ 15596 ���� N���� ��
// �Լ� ����
// a[i]<= 100��, n<3�鸸

#include <iostream>
#include <vector>

/* C++ */
//long long sum(std::vector<int>& a) {
//	long long ret = 0;
//	for (int aa:a) {
//		ret += aa;
//	}
//
//	return ret;
//}

/* C */
long long sum(int* a, int n) {
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i];
	}
	return ans;
}

int main() {
	int arr[10]  = { 1,2,3,4,5,6,7,8,9,10 };
	std::cout<<"sum: " << sum(arr, 10) << std::endl;

	return 0;
}