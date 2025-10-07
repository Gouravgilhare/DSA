class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int>result(n,1);
        list<int>drydays;
        unordered_map<int,int>filledLakes;

        for(int i = 0 ; i< n ; i++){
            int lake = rains[i];

            if(lake == 0) {
                drydays.push_back(i);
                result[i]= 1;
            }else{
                if(filledLakes.find(lake) != filledLakes.end()){
                    int lastFilled = filledLakes[lake];
                    bool dry = false;

                    for(auto it  = drydays.begin(); it!= drydays.end() ; it++){
                        if(*it > lastFilled){
                            result[*it] = lake;
                            drydays.erase(it);
                            dry = true;
                            break;
                        }

                    }

                    if(!dry){
                        return {};
                    }
                }

                  filledLakes[lake] = i;
                result[i] = -1; // raining day
            }

        }
        return result;

    }
};