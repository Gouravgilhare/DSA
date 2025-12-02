class Solution {
  public:
  
    static bool comp(const vector<int>&a, const vector<int>&b){
        return a[1]<b[1];
    }
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n = start.size();
        vector<vector<int>>arr;
        
        for(int i = 0 ; i< n ; i++){
            arr.push_back({start[i],finish[i]});
        }
        
        
        sort(arr.begin(),arr.end(),comp);
        
        int count = 1;
        
        
        int j = 0;
        
        for(int i =1 ; i< n; i++){
            if(arr[j][1] < arr[i][0]){
                count++;
                j=i;
            }
        }
        
        
        return count;
    }
};