// Title: My Calendar II  
// Difficulty: Hard  

// Problem:  
// You are implementing a calendar system for a single person. 
// One person can book a time interval only if that booking does not cause triple bookings. 
// A triple booking happens when a time interval is covered by three or more events.

// Implement the MyCalendarTwo class:

// - MyCalendarTwo() Initializes the calendar object.
// - bool book(int start, int end): Returns true if the event [start, end) can be added to the calendar without causing a triple booking. Otherwise, returns false and does not add the event.

// Function Signature (C++):  
// class MyCalendarTwo {
// public:
//     MyCalendarTwo();
//     bool book(int start, int end);
// };

// Constraints:
// - 0 <= start < end <= 10⁹  
// - At most 1000 calls to book will be made.  

// Example 1:  
// Input:  
// ["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]  
// [[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]  
// Output:  
// [null, true, true, true, false, true, true]  

// Explanation:  
// MyCalendarTwo myCalendar = new MyCalendarTwo();  
// myCalendar.book(10, 20); // returns true  
// myCalendar.book(50, 60); // returns true  
// myCalendar.book(10, 40); // returns true  
// myCalendar.book(5, 15);  // returns false, triple booking would occur in [10,15]  
// myCalendar.book(5, 10);  // returns true  
// myCalendar.book(25, 55); // returns true  

// Hint:  
// - You can use two lists: one to store all the single bookings, and another to store overlaps (i.e., double bookings).
// - Before adding a new booking, check if it overlaps with any double booking. If it does, return false.

class MyCalendarTwo {
    private:
        vector<pair<int,int>>events;
        vector<pair<int,int>>doubleBooking;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        

        //chcek doubleBooking
        for(auto p : doubleBooking){
            if(startTime < p.second && endTime > p.first)
            {
                return false;
            }
        }

        for(auto p : events){
            if(startTime < p.second && endTime > p.first)
            {
                    doubleBooking.push_back({ max(startTime,p.first),min(endTime, p.second)});
            }
            
        }

        events.push_back({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */
