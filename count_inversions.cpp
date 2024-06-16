// Link:https://www.naukri.com/code360/problems/count-inversions_615?leftPanelTabValue=SUBMISSION
// 1. Brute Force Apporach:
#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    // Write your code here
    long long pair=0;
    for(int i=0;i<n;i++){
        int ptr=i+1;
        while(ptr<n){
            if(arr[i]>arr[ptr]) {
                pair++;
            }
            ptr++;
        }      
    }

    return pair;
}

//2. Optimized Approach using merge sort:
#include <bits/stdc++.h>

long long pairs=0;
void merge(long long *arr, int low, int mid, int high){
    vector < long long > temp;
    int left=low, right=mid+1;
    while((left<=mid) && (right<=high)){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            pairs+=(mid-left+1);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

void mSort(long long *arr, int low, int high){
    if(low==high) return;
    int mid=(low+high)/2;
    mSort(arr, low, mid);
    mSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}



long long getInversions(long long *arr, int n){
    // Write your code here
    mSort(arr, 0, n-1);
    return pairs;
}
