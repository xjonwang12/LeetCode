class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int med=arr[(arr.size()-1)/2];
        int left=0, right=arr.size()-1, counter=0;
        vector<int> nums;
        while(left<=right && counter<k) {
            if(abs(arr[left]-med) > abs(arr[right]-med)) nums.push_back(arr[left++]);
            else nums.push_back(arr[right--]);
            counter++;
        }
        return nums;
    }
};