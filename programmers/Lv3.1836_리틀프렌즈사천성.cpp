#include <bits/stdc++.h>

using namespace std;

int dirX[4] = {-1,0,1,0};
int dirY[4] = {0,-1,0,1};
int N,M;
int pairCnt;

struct{
    int x;
    int y;
    int dir; //0:왼쪽,1:위,2:오른쪽,3:아래
    int cnt;
}typedef Point;

struct{
    int x;
    int y;
}typedef Pair;

bool bfs(int x, int y, int targetX, int targetY, vector<string> &board){
    queue<Point> q;
    q.push({x,y,-1,0});
    
    while(!q.empty()){
        Point tmp = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            //di이 -1이 아닐 때 역방향이라면 continue
            if(tmp.dir!=-1 && abs(tmp.dir-i)==2) continue;

            int nx = tmp.x + dirX[i];
            int ny = tmp.y + dirY[i];
            int ncnt = (tmp.dir==i || tmp.dir==-1) ? tmp.cnt : tmp.cnt+1;
             
            if(nx <0 ||nx>M-1 || ny<0 ||ny>N-1) continue;
            if(ncnt >1) continue;
            if(board[nx][ny]=='*') continue;

            if(board[nx][ny] =='.') q.push({nx,ny,i,ncnt});
            else if(nx==targetX && ny==targetY) return true;
        }
    }
    return false;
}


string turn(vector<vector<Pair>> p, vector<string> &board){

    string ans="";

    bool possibled_turn = true;
    while(possibled_turn){
        possibled_turn = false;
        for(int i=0; i<p.size(); i++){  
            if(p[i].size()>1){
                if(bfs(p[i][0].x, p[i][0].y, p[i][1].x, p[i][1].y, board)){
                    board[p[i][0].x][p[i][0].y]=board[p[i][1].x][p[i][1].y]='.';
                    p[i].clear();
                    pairCnt-=2;
                    ans += char(i+'A');
                    possibled_turn=true;
                    break;
                }
            }
        }
    }
    
    if(pairCnt == 0) return ans;
    else return "IMPOSSIBLE";
}


string solution(int m, int n, vector<string> board) {
    string answer = "";
    vector<vector<Pair> > p(26,vector<Pair>());

    M=m; N=n;
    pairCnt=0;

    for(int i=0; i<board.size(); i++){
         for(int j=0; j<board[i].size(); j++){
            if(!isalpha(board[i][j])) continue;
            p[board[i][j]-'A'].push_back({i,j});
            pairCnt+=1;
         }
    }

    return answer = turn(p,board);
}

int main(){

    // int m=3;
    // int n=3;
    
    // vector<string> board = {"DBA",
    //                         "C*A",
    //                         "CDB"};

    // int m=2;
    // int n=4;
    // M=m; N=n;
    // vector<string> board = {"NRYN",
    //                         "ARYA"};

    int m=5;
    int n=5;
    vector<string> board = { "FGHEI",
                             "BAB..", 
                             "D.C*.", 
                             "CA..I",
                             "DFHGE" };
    //  answer : ABCDFHGIE

// ABCDFGHIE  g h i
    cout << solution(m,n,board);
    return 0;
}

//https://countrysides.tistory.com/79