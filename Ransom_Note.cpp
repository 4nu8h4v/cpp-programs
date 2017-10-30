//Hash Tables: Ransom Note (https://www.hackerrank.com/challenges/ctci-ransom-note)
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    int m;
    int n;
    cin >> m >> n;
    
    unordered_map<string,int> magazineMap, noteMap;
    
    for(int i=0; i<m; ++i){
        string word;
        cin>>word;
        magazineMap[word]++;     
    }
    
    for(int i=0; i<n; ++i){
        string word;
        cin>>word;
        noteMap[word]++;     
    }
    
    bool flag = true;
    for(auto p : noteMap){
        if(magazineMap[p.first] < p.second){
            flag = false;
            break;
        }
    }
    
    flag ? puts("Yes") : puts("No");
    return 0;
}