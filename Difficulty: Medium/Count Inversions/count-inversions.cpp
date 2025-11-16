class Solution {
  public:
  
    int merge(vector<int>&arr, int start , int mid, int end){
        vector<int>temp;
        int cnt = 0;
        int i = start, j = mid+1;
        
        while(i<=mid && j<= end){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }else{
                temp.push_back(arr[j]);
                j++;
                cnt += (mid-i)+1;
            }
        }
        
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=end){
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int idx = 0;idx<temp.size(); idx++){
             arr[start +idx] = temp[idx];
        }
        
        return cnt;
    }
  
    int mergeSort(vector<int>&arr, int start, int end){
        if(start<end){
            int mid = start + (end-start)/2;
            
            int startInvert = mergeSort(arr, start, mid);
            int endInvert = mergeSort(arr, mid+1, end);
            int current = merge(arr,start, mid, end);
            
            return startInvert + endInvert + current;
        }
        
        return 0;
    
    }
  
    int inversionCount(vector<int> &arr) {
        // Code Here
        int s =0, end = arr.size()-1;
        
    return mergeSort(arr,s,end);
    }
};