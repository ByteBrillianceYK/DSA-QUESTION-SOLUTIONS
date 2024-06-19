//brute force approach:
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int occ=0;
            for(int j=0;j<n;j++){
                if(nums[i]==nums[j]) occ++;
            }
            if(occ==1)return nums[i];
        }
        return -1;
    }
};
