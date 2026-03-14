class Solution {
  public:
    
    int merge(vector<int>&arr, int p, int q, int r ){

    vector<int> temp;
    int left = p;
    int right = q + 1;

    int cnt = 0;

    while(left <= q && right <= r){

        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            cnt += (q - left + 1);
            right++;
        }
    }

    while(left <= q){
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= r){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = 0; i < temp.size(); i++){
        arr[p + i] = temp[i];
    }

    return cnt;
}
    
    int mergeSort(vector<int>&arr, int p, int r ){
    
        int cnt =0;
        if(p<r){
            int q = (p+r)/2;
            cnt += mergeSort(arr,p,q);
            cnt += mergeSort(arr,q+1,r);
            cnt += merge(arr,p,q,r);
        }
        
        
        return cnt;
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n =arr.size();
        
        int cnt = 0 ; 
        
    return   mergeSort(arr, 0 , n-1);
        // return cnt;
    }
};