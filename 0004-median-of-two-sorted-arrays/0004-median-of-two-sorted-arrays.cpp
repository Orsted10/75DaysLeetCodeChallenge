class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Make sure 'a' is the shorter array – less binary‑search, more meme time.
        vector<int>& a = (nums1.size() <= nums2.size()) ? nums1 : nums2;
        vector<int>& b = (nums1.size() >  nums2.size()) ? nums1 : nums2;

        int m = a.size();          // tiny array length
        int n = b.size();          // huuuuge array length
        int half = (m + n + 1) / 2; // how many elements must sit on the LEFT side

        int lo = 0, hi = m;        // search range inside the tiny array

        while (lo <= hi) {
            int i = (lo + hi) / 2;        // how many we take from 'a'
            int j = half - i;             // the rest we need from 'b'

            // Grab edge values – use INT_MIN/MAX as bouncers when we hit the ends
            int aLeft  = (i == 0)      ? INT_MIN : a[i-1];
            int aRight = (i == m)      ? INT_MAX : a[i];
            int bLeft  = (j == 0)      ? INT_MIN : b[j-1];
            int bRight = (j == n)      ? INT_MAX : b[j];

            // If the partition is “just right”, we’ve found the median
            if (aLeft <= bRight && bLeft <= aRight) {
                if ((m + n) % 2)               // odd total → middle element
                    return max(aLeft, bLeft);
                // even total → average of the two middle elements
                return (max(aLeft, bLeft) + min(aRight, bRight)) / 2.0;
            }
            // Too many from 'a' → shrink left side
            if (aLeft > bRight)
                hi = i - 1;
            // Too few from 'a' → grow right side
            else
                lo = i + 1;
        }
        return 0.0; // keeps the compiler happy; we never actually get here
    }
};