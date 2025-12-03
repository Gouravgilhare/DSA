class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n =courses.size();

        sort(courses.begin(),courses.end(), [](const auto&a, const auto &b){
            return a[1] < b[1];
        });

        priority_queue<int>maxHeap;
        int curr = 0;
        for(auto c : courses){
            int duration = c[0];
            int lastDay= c[1];

            curr += duration;
            maxHeap.push(duration);

            if(curr > lastDay)
            {
                curr -= maxHeap.top();
                maxHeap.pop();
            }

        }


        return maxHeap.size();


    }
};