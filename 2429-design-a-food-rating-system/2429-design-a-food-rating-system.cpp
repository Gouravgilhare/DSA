class FoodRatings {
public:  // Store food -> {cuisine, rating}
    unordered_map<string, pair<string, int>> foodInfo;
    // Store cuisine -> set of (rating, food) with custom comparator
    unordered_map<string, set<pair<int, string>>> cuisineFoods;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            string f = foods[i];
            string c = cuisines[i];
            int r = ratings[i];
            foodInfo[f] = {c, r};
            cuisineFoods[c].insert({-r, f}); // negative rating for max-heap like behavior
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = foodInfo[food];
        // remove old entry
        cuisineFoods[cuisine].erase({-oldRating, food});
        // insert new one
        cuisineFoods[cuisine].insert({-newRating, food});
        // update map
        foodInfo[food].second = newRating;
    }
    
    string highestRated(string cuisine) {
        // first element in set is the best food
        return cuisineFoods[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */