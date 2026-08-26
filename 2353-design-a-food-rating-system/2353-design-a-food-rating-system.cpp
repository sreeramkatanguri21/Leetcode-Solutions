class Compare {
    public:
        bool operator()(auto& a, auto& b) {
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }
};
class FoodRatings {
public:
    unordered_map<string, pair<int, string>> foodName;
    unordered_map<string, priority_queue<pair<int,string>, vector<pair<int,string>>, Compare>> mpp;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();

        for(int i=0; i<n; i++) {
            foodName[foods[i]] = {ratings[i], cuisines[i]};
            mpp[cuisines[i]].push({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        foodName[food] = {newRating, foodName[food].second};
        mpp[foodName[food].second].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
        
        while(!mpp[cuisine].empty()) {
            auto [rating, food] = mpp[cuisine].top();
            if(foodName[food].first == rating) {
                return food;
            }
            else mpp[cuisine].pop();
        }

        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */