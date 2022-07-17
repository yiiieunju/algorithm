#include <bits/stdc++.h>

using namespace std;

int visited[11][30]={0,}; // visited[b][a] = true b,b+1 -> a

int ans=123456789;
int N, M, H;


bool start_game(){
    for(int i=1; i<=N; i++){
        int curr_line = i;
        for(int j=1; j<=H; j++){
            if(visited[curr_line][j]==1) curr_line = curr_line+1;
            else if(visited[curr_line-1][j]==1) curr_line=curr_line-1;
        }

        if(curr_line!=i) return false;
    }
    return true;
}

void connect_line(int idx, int cnt){ //cnt 라인의 개수
    if(cnt >=4) return;

    if(start_game() == true){
        ans = min(ans,cnt);
        return;
    }

    for(int i=idx; i<=H; i++){ //가로선 마다 모든 세로선인 경우 연결
        for(int j=1; j<N; j++){
            if(visited[j][i]==1) continue;
            if(visited[j-1][i]==1) continue;
            if(visited[j+1][i]==1) continue;

            visited[j][i]=1;
            connect_line(i, cnt+1); //가로선 하나 추가하고 이 세로선일때~ 이세로선일때(세로선마다 탐색)
            visited[j][i]=0;
        }
    }
}

void solve(){
    //세로선마다 다음 세로선과 이어져있지 않은 가로선을
    //모두 한번씩 연결시켜본다.
    connect_line(1,0);

    if(ans==123456789) ans = -1;
    cout << ans;

}

void temp(){

    map<string, int> m;

    m.insert({"alice",1});

    if(m.find("alice")!=m.end())
            cout <<"find";


    for(auto iter=m.begin(); iter!=m.end(); iter++){
        cout <<iter->second<<endl;

    }
return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	temp();

	//input
//	cin >> N >>M>>H;
//
//	for(int i=0; i<M; i++){
//        int a, b; cin >> a >> b;
//        visited[b][a] = 1;
//	}
//
//	solve();

	return 0;
}
