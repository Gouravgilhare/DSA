    #include<bits/stdc++.h>
    using namespace std;
    typedef long long       ll;
    typedef vector<int>     vi;
    typedef vector<ll>      vll;
    typedef vector<vi>      vvi;
    typedef vector<vll>      vvll;
    typedef pair<int,int>   pii;
    typedef pair<ll,ll>     pll;
    typedef vector<pii>     vpii;
    typedef vector<string>     vstr;
    typedef vector<pll>     vpll;
    
    
    
    int main()
    {
        int n = 5;
        vector<int> process(n,0);
        int waitingTime = 0; 
         int ans=0;
        for(int i=  0; i<n ; i++)
            process[i] = abs(rand()%90+10);
        
        sort(process.begin(), process.end());
        cout<<process[0]<<" ";
        for(int i = 1; i<n; i++){
            cout<<process[i-1]<<" ";
            
            waitingTime += process[i-1];
            ans += waitingTime;
        }


        cout<<"\nAns = "<<(long) ans/n;   
    
    return 0;
    }