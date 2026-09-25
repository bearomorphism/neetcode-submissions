class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend());

        double time = 0;
        int ret = 0;
        for (auto [pos, sp] : cars) {
            double newTime = static_cast<double>(target - pos) / sp;
            if (newTime > time) {
                ret++;
                time = newTime;
            }
        }

        return ret;
    }
};
