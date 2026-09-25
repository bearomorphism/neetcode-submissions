class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : pq_(nums.begin(), nums.end()), k_(k) {
        while (pq_.size() > k) {
            pq_.pop();
        }
    }
    
    int add(int val) {
        pq_.push(val);
        if (pq_.size() > k_) {
            pq_.pop();
        }
        return pq_.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq_;
    int k_;
};
