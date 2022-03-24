// 10828: 
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MAX_INT 100000

int stack[10000] = {0,};
int idx = 0;

void Push(int x) {
	stack[idx] = x;
	idx++;
}
void pop() {
	stack[idx-1] = 0;
	idx--;
}
int Size() {
	return idx;
}
int Empty() {
	if (idx == 0) return 1;
	else return 0;
}
int Top(){
	if (Empty()) return -1;
	return stack[idx - 1];
}

void whichCMD(char str[]) {
	char* cmd[2] = {};
	int i=0;

	char* ptr = strtok(str, " ");
	while (ptr != NULL) {
		cmd[i++] = ptr;
		ptr = strtok(NULL, " ");
	}

	if (strcmp(cmd[0], "push") == 0) Push(atoi(cmd[1]));
	else if (strcmp(cmd[0], "top") == 0)  cout << Top()<<endl; 
	else if (strcmp(cmd[0], "size") == 0) cout <<Size() <<endl;
	else if (strcmp(cmd[0], "empty") == 0) cout << Empty() <<endl;
	// pop: top을 pop하고 top을 출력 -> pop()은 pop기능만, 출력은 top()이용
	else if (strcmp(cmd[0], "pop") == 0) { 
		int t = 0;
		if ((t = Top()) != -1) {
			pop();
		}
		cout << t << endl;

	}

}

int main() {
	int N = 0;
	int x = 0;
	cin >> N;
	// clear 랑 ignore 차이?
	cin.clear();
	cin.ignore();

	string cmd = "";
	char* buf = new char[MAX_INT + 6];
	while (N--) {

		cin >> cmd;
		if (cmd == "push") {
			cin >> x;
			Push(x);
		}
		else if (cmd == "top")  cout << Top() << endl;
		else if (cmd == "size") cout << Size() << endl;
		else if (cmd == "empty") cout << Empty() << endl;
		// pop: top을 pop하고 top을 출력 -> pop()은 pop기능만, 출력은 top()이용
		else if (cmd == "pop") {
			int t = 0;
			if ((t = Top()) != -1) {
				pop();
			}
			cout << t << endl;
		}
	}

}
