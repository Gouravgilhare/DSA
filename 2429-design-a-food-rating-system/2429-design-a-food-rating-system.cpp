class FoodRatings {
public:

    unordered_map<string, set<pair<int,string>>>cuisinesRating;
    unordered_map<string,int>foodRating;
    unordered_map<string,string>foodTocuisines;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0 ; i < foods.size(); i++){
            cuisinesRating[cuisines[i]].insert({-ratings[i], foods[i]});
            foodRating[foods[i]]=ratings[i];
            foodTocuisines[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        auto &cuisine = foodTocuisines[food];
        int oldRating = foodRating[food];
       cuisinesRating[cuisine].erase({-oldRating,food});
        cuisinesRating[cuisine].insert({-newRating,food});

        foodRating[food]=newRating;
        
    }
    
    string highestRated(string cuisine) {
        return (*cuisinesRating[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */