#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	getline(cin,str);
	int i = str.size() - 1;//���������±�ָ�����ֳ���������
	int j = i;
	while (i >= 0) {
		while (i >= 0 && str[i] != ' ')
			i--;
		cout << str.substr(i + 1, j - i);
		if(i>=0)
			cout<< " ";
		i--;
		j = i;
	}
	cout << endl;
	return 0;
}