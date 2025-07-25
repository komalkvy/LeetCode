class Solution {
public:
    Solution(const vector<int>& nums) : nums(nums), arr(nums), seed(random_device{}()) {}

    vector<int> reset() {
		arr = nums;
		return arr;
	}

    vector<int> shuffle() {
        for (int i = size(arr) - 1; i > 0; --i) {
            auto idx = uniform_int_distribution<int>(0, i)(seed);
            swap(arr[i], arr[idx]);
        }
        return arr;
    }
private:
    vector<int> arr, nums;
    default_random_engine seed;
};