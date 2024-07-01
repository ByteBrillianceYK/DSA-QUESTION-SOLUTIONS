class Solution {
  public:
//brute force approach:
    // Function returns the second
    // largest elements
    // int secondLargestElement(int arr1[], int n){
    //     vector<int> arr;
    //     for(int i=0;i<n;i++){
    //         arr.push_back(arr1[i]);
    //     }
    //     sort(arr.begin(), arr.end());
    //     int largest=arr[n-1];
    //     int secondLargest;
    //     int i=n-2;
    //     bool flag=false;
    //     while(largest==arr[i]){
    //         i--;
    //         if(i<0){
    //             flag=true;
    //             break;
    //         }  
    //     }
    //     secondLargest=arr[i];
    //     if(flag) return -1;
    //     else return secondLargest;
    // }

//optial code:
    int secondLargestElement(int arr[], int n){
        int largest=arr[0];
        int sLargest=-1;
        for(int i=1;i<n;i++){
            if(arr[i]>largest){
                sLargest=largest;
                largest=arr[i];
            }else if(arr[i]<largest && arr[i]>sLargest){
                sLargest=arr[i];
            }
        }
        return sLargest;
        
    }
    int print2largest(int arr[], int n) {
        // code here
        secondLargestElement(arr, n);
    }
};
