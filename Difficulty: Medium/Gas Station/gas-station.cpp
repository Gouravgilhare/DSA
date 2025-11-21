class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        stack<int>st;
        int n = gas.size();
        int totalGas = 0 , minGas = 0;
        
        for(int val : gas)
            totalGas += val;
        for(int val : cost)
            minGas += val;
            
        
        if(totalGas < minGas)return -1;
        
        int start =0 , currGas = 0;
        
        for(int i = 0 ; i< n ; i++){
            currGas += gas[i]-cost[i];
            
            if(currGas < 0 ){
                currGas = 0;
                start= i+1;
            }
        }
        
        return start;
    
    }

    
};