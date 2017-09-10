#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int N;
	cin >> N;
	int temp = (int)sqrt(N);
	int m, n;
	if (temp*temp == N) {
		m = n = temp;
	}else {
		m = temp + 1;
		n = temp;
	}
	int* a = new int[N];
	for (int i = 0; i < N; i++)
		cin >> a[i];
	sort(a, a + N,cmp);

	int** twoArray = new int*[m];
	for (int i = 0; i < m; i++)
		twoArray[i] = new int[n];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			twoArray[i][j] = 0;
	//cout << m << " " << n << endl;
	int i=0, j=0, k=0;
	twoArray[i][j] = a[k++];//����Ϊ���Ժ�ֵ�����Ƚ���һ��Ԫ�ظ�ֵ
	while (k<N) {     //��Ҫ��ֵN��
		while (j + 1<n && !twoArray[i][j + 1])    
			twoArray[i][++j] = a[k++];//�����ң����С�ڱ߽�ֵ����û�и�ֵ������ֵ
		while (i + 1<m && !twoArray[i + 1][j])    
			twoArray[++i][j] = a[k++];//�����£����С�ڱ߽�ֵ����û�и�ֵ������ֵ
		while (i - 1 >= 0 && !twoArray[i - 1][j])   
			twoArray[--i][j] = a[k++];//���������С�ڱ߽�ֵ����û�и�ֵ������ֵ
		while (j - 1 >= 0 && !twoArray[i][j - 1])   
			twoArray[i][--j] = a[k++];//�����ϣ����С�ڱ߽�ֵ����û�и�ֵ������ֵ
	}//����ΪʲôҪ��++j����Ϊ�����j++�����µ�ʱ��j��Ҫ��һ������˺����ķ���

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << twoArray[i][j];
			if(j!=n-1)
				cout<< " ";
		}
		cout << endl;
	}
	return 0;
}