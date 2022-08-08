#include <vector>
#include <iostream>
using namespace std;

vector<int> nums2;
bool selected[50];
vector<int> prime;
int answer = 0;

bool isprime(vector<int> v){
    int sum=0;
    for(auto a:v) sum+=a;
    
    for(int i=2; i<sum; i++){
        if(sum%i==0) return false;
    }
    return true;
}

void dfs(int index, int cnt){   
    if(cnt == 3){
        if(isprime(prime)){
            answer+=1;
            // for(auto a:prime)
            //     cout <<a <<" ";
        } 
        return;
    } 
    
    for(int i=index; i<nums2.size(); i++){
        
        if(selected[i]) continue;
        
        selected[i] = true;
        prime.push_back(nums2[i]);
        dfs(i, cnt+1);

        prime.pop_back();
        selected[i] = false; 
    }
    
    
}

int solution(vector<int> nums) {
    
    nums2.resize(nums.size());
    copy(nums.begin(), nums.end(), nums2.begin());
    fill(selected, selected+50, false);
    dfs(0,0);
    

    return answer;
}