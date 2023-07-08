//Coins And Triangle
//https://www.codechef.com/problems/TRICOIN
#include<bits/stdc++.h>
using namespace std;
#define int long long 

int bs(int val, int lo, int hi){
    if(lo==hi){
        if(lo*(lo+1)/2==val)return lo;
        return lo-1;
    }
    int mi=lo+(hi-lo)/2;
    if(mi*(mi+1)/2>=val){
        return bs(val, lo, mi);
    }
    return bs(val, mi+1, hi);
}
 

int32_t main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<bs(n, 0,44721)<<endl;
        
    }
}

