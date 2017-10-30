//Recursion: Davis' Staircase (https://www.hackerrank.com/challenges/ctci-recursive-staircase)
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long int memo[40];

long int ways(int h){
    if(h >= 0 && h <=1) return 1;
    if(h < 0) return 0;
    if(memo[h] == -1){
        long int ans = 0;
        ans += ways(h-1) + ways(h-2) + ways(h-3);
        return (memo[h] = ans);
    }
    else{
        return memo[h];
    }
}

int main() {   
    int s;
    cin>>s;
    vector<int> height(s,0);
    for(auto &h : height){
        cin>>h;
    }
    
    memset(memo, -1, sizeof memo);
    
    for(auto h : height){
        cout<<ways(h)<<"\n";
    }
    
    return 0;
}