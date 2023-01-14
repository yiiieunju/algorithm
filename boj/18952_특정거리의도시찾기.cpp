#include <bits/stdc++.h>

#define INF 0xffffff

using namespace std;

int main(){
    
    int N, M, K, X; //노드 개수, 간선 개수, 최단거리, 출발노드
    cin >> N >> M >> K >> X;

    vector<vector<int>> v(N+1,vector<int>());
    vector<int> dist(N+1,INF); //dp 거리, 초기거리 0

    for(int i=0; i<M; i++){
        int start, end; cin >> start >> end;
        v[start].push_back(end);
    }

    //bfs start from X
    queue<int> q;
    q.push(X);
    dist[X] = 0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i=0; i<v[curr].size(); i++){
            int next = v[curr][i];
            // ekdlrtmxmfk
            if(dist[next]==INF){
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }

    vector<int> res;
    for(int i=1; i<N+1; i++){
        if(dist[i]==K) res.push_back(i);
    }

    //결과 출력
    if(res.size()>0){
        for(auto re : res) cout << re <<"\n";
    }
    else cout << -1;

    return 0;
}