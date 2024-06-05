Question Link:https://leetcode.com/problems/sort-colors/description/

// 1.brute force approach
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_position=0;
        
        for(int i=0,n=nums.size();i<n;i++){
            if(nums[i]==0){
                int temp=nums[zero_position];
                nums[zero_position]=nums[i];
                nums[i]=temp;
                zero_position++;
            }
        }
        for(int i=zero_position,n=nums.size();i<n;i++){
            if(nums[i]==1){
                int temp=nums[zero_position];
                nums[zero_position]=nums[i];
                nums[i]=temp;
                zero_position++;
            }
        }
        for(int i=zero_position,n=nums.size();i<n;i++){
            if(nums[i]==2){
                int temp=nums[zero_position];
                nums[zero_position]=nums[i];
                nums[i]=temp;
                zero_position++;
            }
        }
    }
};

// 2.Optimized Approach using Dutch Algo
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;

        while(mid<=high){
                if(nums[mid]==0){
                    swap(nums[low],nums[mid]);
                    low++;
                    mid++;
                }else if(nums[mid]==1){
                    mid++;
                }else if(nums[mid]==2){
                    swap(nums[high],nums[mid]);
                    high--;
                }               
        }
        
    }
};
