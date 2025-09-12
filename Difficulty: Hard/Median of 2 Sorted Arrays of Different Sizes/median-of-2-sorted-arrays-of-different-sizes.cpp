class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        // code here
        double mean = 0;
       for(int i = 0 ; i<b.size(); i++)
        a.push_back(b[i]);
        
        sort(a.begin(), a.end());
        
        int n = a.size();
        
        if(n%2 == 1){
            return a[n/2];
        }
        
        return (a[n/2 -1] + a[n/2])/2.0;
    }
};