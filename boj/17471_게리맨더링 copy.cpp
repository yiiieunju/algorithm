#include <bits/stdc++.h>

using namespace std;

int N=0;
int person[11]= {0,}; //인구 수를 저장하는 배열
bool connected[11][11]= {false,}; //구역이 서로 연결된건지 여부
bool selected[11] = {false,};
bool visited[11]={false,};
int minNum = 0xffffff;

void init(){

    cin >> N;

    for(int i=1; i<=N; i++)
        cin >> person[i];

    for(int i=1; i<=N; i++){
        int cnt; cin >> cnt;
        for(int j=1; j<=cnt;j++){
            int k; cin >> k;
            connected[i][k]=true;
            connected[k][i]=true;
        }
    }
}

void calculate(){
    int Anum=0, Bnum=0;
    for(int i=1; i<=N; i++){
        if(selected[i] == true) Anum+=person[i];
        else Bnum+=person[i];
    }

    int diff = Anum-Bnum >0 ? Anum-Bnum : Bnum-Anum;
    minNum = min(minNum, diff);
}

bool isConnected(vector<int> district, bool part){

    fill(visited,visited+N+1, false);


    queue<int> q;
    q.push(district[0]);
    visited[district[0]]=true;
    int cnt = 1;
    
    while(!q.empty()){
        int point = q.front();
        q.pop();

        for(int i=1;i<=N; i++){
            //1. 현재 구역과 탐색하려는 구역이 연결되어있는 지
            //2. 탐색하려는 구역이 같은 지역구인지
            //3. 아직 방문하지않은 구역이 있는 지
            if(visited[i] == true) continue;
            if(connected[point][i] && selected[i]==part){
                q.push(i);
                visited[i] = true;
                cnt++;
            }
        }
    }

    if(cnt!=district.size()) return false;

    return true;
}

bool check(){
    // 선거구일 수 있는 조건 체크
    // 1. 각 구역의 인구수가 1개 이상
    // 2. 각 구역의 인구들이 모두 이어져 있는 지
    vector<int> A, B;
    for(int i=1; i<=N; i++){
        if(selected[i]) A.push_back(i);
        else B.push_back(i);
    }
    
    if(A.size()==0 || B.size()==0) return false;
    if(!isConnected(A, true)) return false;
    if(!isConnected(B, false)) return false;

    return true;

}

void sequence(int index, int cnt){
    if(cnt >=1){
        if(check() == true){    // 연결되어있다면
            calculate();    // 각 지역구의 개수 차이 구하기
        }
    }

    for(int i=index; i<=N; i++){
        if(selected[i]==true) continue;
        selected[i] = true;

        sequence(i, cnt+1);
        selected[i] = false;
        
    }   
}

void solution(){

    sequence(1,0);

    if(minNum!=0xffffff)
        cout << minNum <<endl;
    else 
        cout << -1 <<endl;

}

int main(){

    init();

    solution();
    
    //조합 구현하기
    //1. 선거구역에 포함된 구역의 개수가 1개 이상인지
    //2. 선거구에 포함된 구역들끼리 모두 연결되어있는 지


    //bfs 조건 체크
    //1. 현재 구역과 탐색하려는 구역이 연결되어 있는 구역인지
    //2. 탐색하려는 구역이 현재 구역에 맞는 놈인지
    //3. 방문하지 않은 구역인지
    
    
    return 0;
}