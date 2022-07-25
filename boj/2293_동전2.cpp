#include <bits/stdc++.h>

using namespace std;

int value[101];
int dp[10001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int K;

    cin >> N >>K;

	for(int i=1; i<=N; i++){
        cin >>value[i];
	}

	//최솟값을 찾아야하므로 큰값으로 세팅해주기
    for(int i=1; i<=K; i++)
        dp[i]=2e9;

	//dp..
	dp[0]=0;

	for(int i=1; i<=N; i++){
        for(int j=value[i]; j<=K;j++){
            dp[j] = min(dp[j],dp[j-value[i]] + 1);
        }
	}

    if(dp[K]==2e9) cout << -1<<endl;
    else cout << dp[K]<<endl;


	return 0;
}


//지역변수는 stack 영역에 할당되고 전역변수는 data 영역에 할당됩니다.(https://www.geeksforgeeks.org/...)

//문제에서 주어지는 메모리 제한이 512MB라고 할 때 대략 int 1.2억개 정도의 배열을 잡을 수 있고 실제로 BOJ에 int a[10000000]; 배열을 전역에 잡든 지역에 잡든 제출해보면 잘 됩니다.

//그러면 "지역 변수로 배열의 최대 크기를 할당하는게 25만정도"라는 말이 어디서 나온거냐면, 기본적으로 운영체제는 성능 상의 이유로 stack 영역에서 메모리 제한을 걸어버립니다. 별도의 설정을 하지 않는다면 윈도우에서는 1MB, 리눅스에서는 8MB 이런식으로요. 그래서 윈도우 Visual Studio에서 int a[100][10000];을 지역변수로 잡아서 실행해보면 stack 영역의 메모리 제한을 넘겨서 런타임 에러가 발생합니다. 반면 전역변수로 설정하면 data 영역에 할당되기 때문에 문제의 메모리 제한을 지키는 한 정상적으로 실행됩니다.
