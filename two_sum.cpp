


// 2. Optimized solution with time compleixty O(nlogn):
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i1,i2;
        vector<int> temp=nums;
        int n=nums.size();
        int left=0, right=n-1;
        sort(temp.begin(), temp.end());
        // [3,3]
        while(left<right){
            int sum=temp[left]+temp[right];
            if(sum<target){
                left++;
            }   
            if(sum>target){
                right--;
            }
            else{
                i1=-1,i2=-1;
                for(int i=0;i<n;i++){
                    if(nums[i]==temp[left] && i1==-1){
                        i1=i;
                    }
                    else if(nums[i]==temp[right] && i2==-1){
                        i2=i;
                    }
                }
                break;
            }
        }
        return {i1, i2};
    }   
};
