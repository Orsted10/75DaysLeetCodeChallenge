class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // 1️⃣  Sort the array – now any twins will be standing next to each other
        sort(nums.begin(), nums.end());          // O(n log n)

        // 2️⃣  Walk through the sorted array and shout if we see a pair
        int n = nums.size();                     // length, just for fun
        for (int i = 0; i < n - 1; ++i) {        // stop before the last element
            if (nums[i] == nums[i + 1]) {        // twin found!
                return true;                     // early exit, save the CPU
            }
        }
        // 3️⃣  Made it to the end → everybody’s unique
        return false;
    }
};