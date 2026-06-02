// 

#include<bits/stdc++.h>
using namespace std;

long long ncr(int n,int r){
    if(r>n) return 0;
    long long res=1;
    r=min(r,n-r);
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
}


int main(){
    int N,r,c;
    cin>>N>>r>>c;
    cout<<ncr(r-1,c-1)<<endl;
    for(int i=0;i<N;i++){
        cout<<ncr(N-1,i);
    }
    cout<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            cout<<ncr(i,j);
        }
        cout<<endl;
    }

    return 0;
}
