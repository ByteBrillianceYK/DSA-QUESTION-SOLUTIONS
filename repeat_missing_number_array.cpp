// https://www.interviewbit.com/problems/repeat-and-missing-number-array/
// 1. Brute Force Approach:
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> sorted_A=A;
    sort(sorted_A.begin(),sorted_A.end());
    int size=sorted_A.size();
    int repeated=-1;
    int missing=-1;
    
    for(int i=0;i<size-1;i++){
        if(sorted_A[i]==sorted_A[i+1]){
            repeated=sorted_A[i];
        }
        
        if(sorted_A[i]+1<sorted_A[i+1]){
            missing=(sorted_A[i]+1);
        }
    }
    
      if(sorted_A[0]!=1){
        missing=1;
    }else if(sorted_A.back()!=size){
        missing=size;
    }      
    
    return {repeated,missing};
}

