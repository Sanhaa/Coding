/*
2021-04-20
J 1695 단지번호붙이기
BFS (원래는 flood fill)
*/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 26

int main() {
	//freopen("input.txt", "r", stdin);

	int N = 0; cin >> N;
	int map[MAX_N][MAX_N] = { 0, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c;
			scanf(" %c", &c);

			if (c == '0') map[i][j] = 0;
			else map[i][j] = 1;
		}
	}

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << map[i][j];
	//	}
	//	cout << endl;
	//}

	// 단지 찾기
	int G = 0; // 단지 개수
	int groups[MAX_N] = { 0, }; // groups[G]: 해당 단지 집의 수

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (map[i][j] == 0) continue;

			// 집이 있으면
			queue<pair<int, int>> q;
			q.push(make_pair(i, j));

			int g = 0; // 이 단지의 집 수
			while (!q.empty()) {

				pair<int, int> cur = q.front(); q.pop(); // i j 순서
				if (map[cur.first][cur.second] == 0) continue; // 방문
				else  map[cur.first][cur.second] = 0;

				g++;
				// 상
				if (cur.first - 1 >= 0 && map[cur.first - 1][cur.second] != 0) {
					q.push(make_pair(cur.first - 1, cur.second));
					//map[cur.first - 1][cur.second] = 0;
				}
				// 하
				if (cur.first + 1 < N && map[cur.first + 1][cur.second] != 0) {
					q.push(make_pair(cur.first + 1, cur.second));
					//map[cur.first + 1][cur.second] = 0;
				}
				// 좌
				if (cur.second - 1 >= 0 && map[cur.first][cur.second - 1] != 0) {
					q.push(make_pair(cur.first, cur.second - 1));
					//map[cur.first][cur.second - 1] = 0;
				}
				// 우
				if (cur.second + 1 < N && map[cur.first][cur.second + 1] != 0) {
					q.push(make_pair(cur.first, cur.second + 1));
					//map[cur.first][cur.second + 1] = 0;
				}
			}

			groups[G++] = g;
			//cout << G - 1 << ":  " << g << endl;
		}
	}
	cout << G << endl;
	sort(groups, groups + G);
	for (int i = 0; i < G; i++) {
		cout << groups[i] << endl;
	}
	return 0;
}
