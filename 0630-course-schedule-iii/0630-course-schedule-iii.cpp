class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();

        sort(courses.begin(),courses.end(),[](const auto&a, const auto&b){
            return a[1]<b[1];
        });


        int time= 0;
        priority_queue<int>maxHeap;
        // maxHeap.push(duration);

        for(int i = 0 ; i< n ; i++)
        {   
        int duration = courses[i][0];
        int last = courses[i][1];
            
            time += duration;
                maxHeap.push(duration);

            if(time >last){

                time -= maxHeap.top();
                maxHeap.pop();
            }


        }

        return maxHeap.size();
    }
};