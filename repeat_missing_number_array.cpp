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

//2. Optimized Approach using simple Maths:
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long n=A.size();
    long long sum=0, n_sum, sqr_sum=0, sqr_sum_n;
    
    for(int i=0;i<n;i++){
        sum+=A[i];
        sqr_sum+=(long long)A[i]* (long long)A[i];
    }
    
    n_sum=(n*(n+1))/2;
    sqr_sum_n=(n*(n+1)*((2*n)+1))/6;
    
    long long r, m;
    long long r_minus_m=sum-n_sum;
    long long r_sqr_minus_m_sqr=sqr_sum-sqr_sum_n;
    
    long long r_plus_m = r_sqr_minus_m_sqr / r_minus_m;
    long long repeat=(r_minus_m+r_plus_m)/2;
    long long missing=repeat-(r_minus_m);
        
    
    return {(int)repeat,(int)missing};
}

