class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int currPenalty = 0;
        for(int i =0 ; i< n ; i++){
            if(customers[i]== 'Y'){
                currPenalty++;
            }
        }


        int minPenalty = currPenalty;
        int earliestHour = 0;

        for(int i =0 ; i< n ; i++){
            char ch = customers[i];

            if(ch == 'Y') currPenalty--;
            else currPenalty++;

            if(currPenalty < minPenalty){
                earliestHour = i+1;
                minPenalty = currPenalty;
            }
        }
    
    
        return earliestHour;
    }
};