class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
       int n = arr1.size(), m = arr2.size(),l = arr3.size();
       
       vector<int> ans;
       int i = 0, j = 0, k = 0;
       
       while(i<n && j< m && k< l){
           if(arr1[i] == arr2[j] && arr2[j] == arr3[k]){
               
               ans.push_back(arr1[i]);
               
               int val = arr1[i];
               
               
               while(i< n && arr1[i] == val)i++;
               while(j<m && arr2[j] == val)j++;
               while(k < l && arr3[k] == val)k++;
               
           }
           else if(arr1[i] < arr2[j] ) i++;
           else if(arr2[j] < arr3[k])j++;
           else k++;
           
       }
       
       return ans;
      
       
       
        
        
        // vector<int>ans;
        // for(auto it = mp.begin(); it!=mp.end(); it++){
        //     if(it->second == 3){
        //         ans.push_back(it->first);
        //     }
        // }
        
        // return ans;
        
        
    }
};