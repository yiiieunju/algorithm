#include <bits/stdc++.h>

using namespace std;

struct Info{
    int x, y;
    long long val;

};

info tmp;
int x[2001], y[2001], parent[2001];


int find(int p){
    if (parent[p] == p) return p;
    return parent[p] = find(parent[p]);
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> N>>C;

    cout <<minDist <<endl;



	for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;

        v.push_back({x,y});
	}

	//dfs
	for(int i=0; i<N; i++){
        visited[v[i].first][v[i].second] = true;
        dfs(v[i], 0, 0);
    }
    cout <<minDist <<endl;

    cout <<q.size()<<endl;

    while(!q.empty()){
        cout <<q.front().first <<" " <<q.front().second<<endl;
        q.pop();
    }
	return 0;
}
