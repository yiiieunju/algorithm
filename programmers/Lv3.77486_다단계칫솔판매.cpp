#include <bits/stdc++.h>

using namespace std;


vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    vector<vector<string>> graph;
    graph.push_back("center");
    
    for(int i=0; i<enroll.size(); i++){
        for(auto ref: referral){
            if(ref !="-")
            graph[i].push_back(ref);
            graph[i].push_back(enroll[i]);
        }
    }

    for(int i=0; graph.size(); i++){
        cout << enroll[i]<<endl;
        for(int j=0; j<graph[i].size(); j++){
            cout << graph[i][j]<<" ";
        }
    }

    return answer;
}

int main(){

    vector<string> enroll = {"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"};
    vector<string> referral = {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"};
    vector<string> seller = {"young", "john", "tod", "emily", "mary"};
    vector<int> amount = {12, 4, 2, 5, 10};


    return 0;
}