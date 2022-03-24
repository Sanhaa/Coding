// S 1260 화학물질2
#include <iostream>
using namespace std;

#define MAX_M 25 // 최대 행렬 개수
#define MAX_N 110 // 입력 이차원 배열의 가로 세로

#define INF 987654321
const char sharp = '#';

int mmin(int a, int b) { return a < b ? a : b; }

int main() {

	int tc = 0;  cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int N = 0; cin >> N; // <= 100 , 이차원 배열의 가로 세로 길이

		// N*N 입력
		int arr[MAX_N][MAX_N] = { 0, };
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++) 
				cin >> arr[i][j];

		int Matrix[MAX_M][MAX_M] = { 0, };
		int d[MAX_M] = { 0, }; // 행렬 개수 
		pair<int, int> RC[MAX_M]; // 행렬의 row column 저장


		// N*N 에서 행렬 추출하기
		int row = 0, col = 0;
		int M = 0; // matrix 개수
		int ii = 0, jj = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				col = 0; row = 0;
				// 0 or -1 skip
				if (arr[i][j] == 0) continue;

				ii = i; jj = j; // 원래의 idx 백업

				while (arr[ii][jj] > 0) {
					while (arr[ii][jj] > 0) { 
						arr[ii][jj++] = 0; // 이미 확인한 곳임을 표시
						if(ii == i) col++;  // 처음 돌 때만 col 세기
					}
					jj = j;
					ii++;  row++;
				}
				RC[++M] = make_pair(row, col);
				//cout << M << " th row col : " << row << " " << col << endl;
			}
		}

		// 행 값 중에 unique 한거 찾기 -> 이게 너무 짜증...
		for (int i = 1; i <= M; i++) {
			int unique = 1;
			for (int j = 1; j <= M; j++) {
				if (RC[i].first == RC[j].second) unique = 0;
			}
			if (unique == 1) {
				d[0] = RC[i].first; break;
			}
		}

		/* 행렬의 순서 정하기 */
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= M; j++) {
				if (RC[j].first == d[i-1]) {// 이 값을 행으로 가지는 것
					d[i] = RC[j].second; break;
				}
			}
		}

		// MCM	
		for (int r = 2; r <= M; r++) {
			for (int i = 1; i <= M - r + 1; i++) {
				int j = i + r - 1;
				Matrix[i][j] = INF;
				for (int k = i; k < j; k++) {
					Matrix[i][j] = mmin(Matrix[i][j], Matrix[i][k] + Matrix[k + 1][j] + d[i - 1] * d[k] * d[j]);
				}
			} 
		} 

		cout << sharp << t << " " << Matrix[1][M] << endl;
	}

	return 0;
}
