#include <bits/stdc++.h>

using namespace std;

struct{
    int z;
    int x;
    int y;
}typedef Board;

int M,N,H;
int arr[100][100][100];
int dirX[] = {-1, 0, 1, 0, 0,  0};
int dirY[] = {0, -1, 0, 1, 0,  0};
int dirZ[] = {0,  0, 0, 0, 1, -1};
int day=0;
queue<Board> q;

//교훈 !! : q.size()를 그대로 쓰지말자 ㄹㅇ 개된다.
// -> q.size()는 pop 할 때마다 계속 변한다 망각하지말자!!
bool all_rippen(){
    for(int h=0; h<H; h++){
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    if(arr[h][i][j] == 0){
                         return false;
                    }   
                }
            }
        }
    return true;
}

void bfs(){
    

    while(!q.empty()){
        int q_size = q.size();
        //for day check
        //이 for문을 들어가기 전에 멈추도록 하는 게 없기때문에 갈 곳이 없더라도 1번 더 돈다.    
        for(int qs=0; qs<q_size; qs++){
            Board tmp = q.front();
            q.pop();
            for(int i=0; i<6; i++){
                //struct는 x,y,z순인데 push는 h,x,y순서로 함..;  -> struct구조를 바꿔줌
                int nx = tmp.x + dirX[i];
                int ny = tmp.y + dirY[i];
                int nz = tmp.z + dirZ[i];

                //이부분 틀렸음 맨날 이차원만 하다보니..헷갈림
                if(nx <0 || nx>N-1 || ny<0 || ny>M-1 || nz<0 || nz>H-1) continue;
                if(arr[nz][nx][ny] == -1 || arr[nz][nx][ny] ==1) continue;
                arr[nz][nx][ny] = 1;
                q.push({nz,nx,ny});
            }
        }//같이 시작해야하는 좌표들이 q_size에 들어간다.
        //마지막 turn에 모두가 1이 되고 나면 q 에 push 된다. -> 마지막 turn 이 끝나서 day1 증가 -> 근데 이미 push 된게 있어서 한번 더 돈다.
        day++;
    }

    if(all_rippen())
        cout <<day-1<<endl;
    else
        cout << -1 <<endl; 
}



void solve(){
    bfs();
}

void input(){
    cin >> M >> N >> H;

    for(int h=0; h<H; h++)
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++){
                cin >> arr[h][i][j];
                //insert rippen tomato into quqeue in davance
                if(arr[h][i][j]==1) q.push({h,i,j});
            }
        
    
}

int main(){

    input();
    solve();

    return 0;
}