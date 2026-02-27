class Solution {
  public:
  
    
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n <=1) return 0;
        
        if (arr[0] == 0) return -1;
        
        int jump = 1 ;
        int choice = arr[0];
        int maxJump = arr[0];
        
        for(int i = 1; i< n ; i++){
            
            
            if(i == n-1) return jump; 
            
            maxJump = max (maxJump, arr[i]+ i );
            
            if(choice == i  ) {
                choice = maxJump;
                jump++;
                
                if(i>= maxJump)return -1;
            }
            
        }
        
        // if(choice >= n-1) return jump;
        
        return -1;
        
    }
};
