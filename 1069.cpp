#include<iostream>
#include<map>
#include<queue>
#include<string>
using namespace std;

int main() {
	int M, N, S;
	cin >> M >> N >> S;
	map<string, int> m;//��map���ж����µ��Ƿ��֮ǰ���ظ�
	queue<string> q;//�ö������洢���ʵ�����
	int count = 0;
	for (int i = 1; i <= M; i++) {
		string temp;
		cin >> temp;
		if (i == S) {
			m[temp] = 0;
			q.push(temp);
		}
		else if (i > S) {
			count++;
			if (m.count(temp) == 0 && count == N) {
				m[temp] = 0;
				q.push(temp);
				count = 0;
			}
			else if (m.count(temp) > 0)
				count--;
		}
	}
	if (m.size() == 0)
		cout << "Keep going..." << endl;
	else {
		while (!q.empty()) {
			cout << q.front() << endl;
			q.pop();
		}
	}
	return 0;
}