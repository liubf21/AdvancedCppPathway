/*
An array A consisting of N integers is given. A pair of integers (P, Q)
, such that0<P<N,is called a slice of array A. A slice is
called alternating if the signs of its consecutive elements
alternate. More precisely, slice (P, Q) is alternating if
+ A[P] ≥ 0, A[P+1] ≤ 0, A[P+2] ≥ 0, and so on, up to
A[Q], or
+ A[P] ≤ 0, A[P+1] ≥ 0, A[P+2] ≤ 0, and sb on, up to
A[Q].
Note that 0 is treated as both positive and negative.
Write a function:
int solution(vector<int> &A);
that, given an array A consisting of N integers,returns the size of
the largest alternating slice in A.

Write an efficient algorithm for the following assumptions:
N is an integerwithin the range [1..100,000];
each element of array A is an integer within the
range [-1,000,000,000..1,000,000,000].

ex:
[1,0,0,0,5,-4,3,0,2,1,-1,0,2,-1,0,2,-3,4,-5]

*/

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    // 动态规划，dp[i]存以A[i]为结尾的最长满足题意的子串长度 
    // 对0的特殊处理，需要存连续0的个数
    const int N = A.size();
    vector<int> dp(N, 1);
    vector<int> zero(N, 0); // zero[i]表示i往前有几个连续的0
    if (A[0]==0) zero[0]=1;

    for (int i=1; i<N; i++) {
        // 对0需要特殊判断
        if (A[i]==0) {
            zero[i]=zero[i-1]+1;
            dp[i]=dp[i-1]+1;
        }else{
            if (zero[i-1]>0) { //前一个是0
                if (zero[i-1]==i) {
                    dp[i]=dp[i-1]+1;
                }
                else if (zero[i-1]%2==1 && A[i]*A[i-1-zero[i-1]]>0) {
                    dp[i]=dp[i-1]+1;
                }
                else if (zero[i-1]%2==0 && A[i]*A[i-1-zero[i-1]]<0) {
                    dp[i]=dp[i-1]+1;
                }else{
                    dp[i]=zero[i-1]+1;
                }
            }else{
                if (A[i]*A[i-1]<0) {
                    dp[i]=dp[i-1]+1;
                }
            }
        }
    }
    int ans=1;
    // for (int i=0; i<N; i++)cout<<i<<" "<<dp[i]<<" "<<zero[i]<<"; ";
    for (auto& d: dp) {
        ans = max(ans, d);
    }
    return ans;
}
