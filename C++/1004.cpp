#include<iostream>
#include<string>
using namespace std;
struct studentInfo {
	string name;
	string id;
	int score;
};

int main() {//ʱ�临�Ӷ�O(n)  �ռ临�Ӷ�O(1)
	int n;
	cin >> n;
	studentInfo minStudentInfo, maxStudentInfo;
	int minScore=100, maxScore=0;
	for (int i = 0; i < n; i++) {
		string tempName, tempId;
		int tempScore;
		cin >> tempName >> tempId >> tempScore;
		if (tempScore < minScore) {
			minStudentInfo.name = tempName;
			minStudentInfo.id = tempId;
			minStudentInfo.score = tempScore;
			minScore = tempScore;
		}
		if (maxScore < tempScore) {
			maxStudentInfo.name = tempName;
			maxStudentInfo.id = tempId;
			maxStudentInfo.score = tempScore;
			maxScore = tempScore;
		}
	}
	cout << maxStudentInfo.name << " " << maxStudentInfo.id << endl;
	cout << minStudentInfo.name << " " << minStudentInfo.id << endl;
	return 0;
}