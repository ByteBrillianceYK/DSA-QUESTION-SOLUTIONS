//Question Link:https: //leetcode.com/problems/merge-sorted-array/
// 1.Brute Force Approach

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(m+n);
        int left=0,right=0;
        int index=0;
        while(m>left && n>right){
            if(nums1[left]<=nums2[right]){
                nums3[index]=nums1[left];
                index++,left++;
            }else{
                nums3[index]=nums2[right];
                index++,right++;
            }
        }
        while(right<n){
            nums3[index]=nums2[right];
            right++;
            index++;
        }
        while(left<m){
            nums3[index]=nums1[left];
            left++,index++;
        }
        nums1=nums3;

        
    }
};

// 2. Optimal Approach:
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left=m-1,right=0;
        while(left>=0 && right<n){
            if(nums1[left]>nums2[right]){
                swap(nums1[left],nums2[right]);
                left--,right++;
            }else{
                break;
            }
        }
      
        for(int i=0;i<n;i++){
            nums1[m+i]=nums2[i];
        }

        sort(nums1.begin(), nums1.end());
    }
};
