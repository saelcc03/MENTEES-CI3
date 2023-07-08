//B. Burning Midnight Oil
//https://codeforces.com/problemset/problem/165/B
#include<bits/stdc++.h>
using namespace std;

int f(int v,int k){
    if(v==0)return 0;
    return v+f(v/k,k);
}
int main(){
    int n, k; 
    cin>>n>>k;
    
    int lo=0;
    int hi=(int)1e9;
    while (lo<hi){
        int mi=lo+(hi-lo)/2;

        if(f(mi,k)>=n)hi=mi;
        
        else lo=mi+1;
    }

    cout<<lo;
        
    
    return 0;
}
