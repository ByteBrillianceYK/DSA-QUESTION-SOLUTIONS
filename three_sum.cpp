// problem link:https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target=0;
        vector<vector<int>> answer;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1, k=n-1;
            while(j<k){
                long long sum=nums[i];
                sum+=nums[j];
                sum+=nums[k];
                if(sum==target){
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    answer.push_back(temp);
                    j++,k--;
                    while(nums[j]==nums[j-1] && j<k) j++;
                    while(nums[k]==nums[k+1] && j<k) k--;
                }else if(sum<target)j++;
                else k--;
            }
            
        }
        return answer;
    }
};
