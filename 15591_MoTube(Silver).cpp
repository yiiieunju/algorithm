#include <bits/stdc++.h>

using namespace std;

int N, Q;
vector<pair<int,int> > v[5001];
bool visited[5001] = {false,};

int bfs(int k, int point){

    fill(visited, visited+N+1, false);
    int cnt=0;

    visited[point] = true;
    queue<int> q;
    q.push(point);

    while(!q.empty()){
        int top = q.front();
        q.pop();

        for(int i=0; i< v[top].size(); i++){
            int next = v[top][i].first;

            if(visited[next]) continue;
            int next_val = v[top][i].second;

            if(next_val >= k){
                cnt++;
                q.push(next);
                visited[next] = true;
            }
        }
    }

    return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> N >> Q;

	for(int i=0; i<N-1; i++){
        int p,q,r;
        cin >>p >>q>>r;

        pair<int,int> p1 = {p,r}; //2 1 3
        v[q].push_back(p1);

        pair<int,int> p2 = {q,r}; // 2 3
        v[p].push_back(p2);
	}

	for(int i=0; i<Q; i++){
        int k, point;
        cin >> k >>point;
        //k에서 v까지 가중 치 중 가장 작은 값 찾기
        cout << bfs(k,point) <<'\n';

	}

	return 0;
}
