#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	int sum=0;

	cin >>N >>K;

	int arr[N];
	for(int i=0; i<N; i++)
        cin >>arr[i];

	for(int i=N-1; i>=0; i--){
        sum+= K/arr[i]; //ū ������ �ִ� �� �� ��� ���� �� ��
        K=K%arr[i]; // ū������ ����� ǥ���� ������ �ݾ�
	}

	cout << sum;


	return 0;
}
