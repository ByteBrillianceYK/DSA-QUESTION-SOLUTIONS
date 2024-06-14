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
