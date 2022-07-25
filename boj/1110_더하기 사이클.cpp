#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int N;
	cin >> N;

    int cnt=1;
    int ans=N;

	while(1){

        int oper1 = ans/10;
        int oper2 = ans%10;

        ans = oper1 + oper2;
        int tmp =  ans >=10 ? ans%10 : ans;

        ans = oper2*10 + tmp;

       if(ans == N) break;

      cnt +=1;
	}

	cout << cnt;

	return 0;
}
