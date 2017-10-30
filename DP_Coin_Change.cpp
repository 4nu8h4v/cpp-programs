//DP: Coin Change (https://www.hackerrank.com/challenges/ctci-coin-change)
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

long long memo[255][55];

long long make_change(const vector<int> &coins, int money, int index) {
    if(money == 0) return 1;
    if(money < 0) return  0;
    if(index == coins.size()) return 0;
    
    long long ans = 0;
    if(memo[money][index] == -1){
        ans = make_change(coins, money, index + 1);
        ans += make_change(coins, money - coins[index], index);
        return (memo[money][index] = ans);
    }
    else{
        return memo[money][index];
    }
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> coins(m);
    for(int coins_i = 0;coins_i < m;coins_i++){
        cin >> coins[coins_i];
    }

    memset(memo, -1, sizeof memo); 

    cout << make_change(coins, n, 0) << endl;
    return 0;
}
