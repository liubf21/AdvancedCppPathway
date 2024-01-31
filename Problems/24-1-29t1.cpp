/*
There is an array A consisting of Nintegers. Divide them into
three non-empty groups. In each group we calculate the
difference between the largest and smallest integer. Our goal is
to make the maximum of these differences as small as possible
For example, given A = [11, 5, 3, 12, 6, 8, 1, 7, 4], we can divide the
elements into three groups:
[3, 1, 4] - the difference between elements is 3;
[5, 6, 8, 7] - the difference is also 3;
[11, 12] - the difference is 1.
The maximum difference equals 3, which is the minimum
possible result.
Write a function:
int solution(vector<int> &A);
that, given an array A, returns the minimum possible result as
explained above.

Examples:
1. For A = [11, 5, 3, 12, 6, 1, 7, 4], the function should return 3,
as explained above.
2. For A = [10,14,12, 1000,11, 15,13, 1], the function should
return 5. The elements of A should be divided into three groups
as follows:
+ [1];
+ [10,14,12,11,15,13];
+ [1000]
3. For A = [4, 5,7,10,10,10,12, 12, 12, the function should return
The elements of A could be divided into these three groups:
+ [4,5];
+ [7];
+ [10,10,12,12, 12]
4. For A = [5, 10, 10, 5, 5], the function should return 0. The first
group may contain all elements with value 5; the second and the
third groups may each contain one element with value 10.

Write an efficient algorithm for the following assumptions
Nis an integer within the range [3..100,000];
each element of array A is an integer within the
range [0..1,000,000,000].

*/
// you can use includes, for example:
#include <bits/stdc++.h>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    int N = A.size();
    // 先排序，题目目的是将所有数分入3个桶中，使桶内差距尽可能小
    sort(A.begin(), A.end());
    auto e = unique(A.begin(), A.end());
    N = e-A.begin();
    // for (auto& a: A) cout<<a<<" ";
    // cout<<"---"<<endl;

    // 双指针：
    int i=1, j=N-2;
    int ans = 0;
    if (i<j)ans= A[j]-A[i];
    while (i<j) {
        // cout<<i<<" "<<j<<"ans"<<ans<<" ";
        // 判断是否要将i指向的数放入左边的桶，j指向的数放入右边的
        bool mv1 = false, mv2 = false;
        int tmp1 = max(A[i]-A[0], max(A[N-1]-A[j+1], A[j]-A[i+1]));
        int tmp2 = max(A[i-1]-A[0], max(A[N-1]-A[j], A[j-1]-A[i]));
        if (tmp1<=ans && tmp1<=tmp2) {
            ans = tmp1;
            i++;
            mv1 = true;
        }else if (tmp2<=ans && tmp2<=tmp1) {
            ans = tmp2;
            j--;
            mv2 = true;
        }
        if (!mv1 && !mv2) break;
        // cout<<tmp1<<" "<<tmp2<<endl;
    }

    // // 求出相邻数的差
    // vector<int> diffs;
    // for (auto it = A.begin()+1; it != A.end(); it++) {
    //     int diff = *it - *(it-1);
    //     // cout<<diff<<" ";
    //     diffs.push_back(diff);
    // }
    // // cout<<"---"<<endl;
    // // 从中间去掉两个数，使其分为3部分，且3部分各自求和，要这3个和的最大值最小
    // // 从最大的两个数划分未必正确
    // // 得到前缀和数组S，S[i]表示i前面的和， S[i]-S[0],S[j]-S[i+1],S[N]-S[j+1]
    // vector<int> S(N+1, 0);
    // for (int i=1; i<=N; i++) {
    //     S[i] = S[i-1] + diffs[i-1];
    // }
    // int ans = 1<<30;
    // for (int i=0; i<N; i++) {
    //     for (int j=i+1; j<N; j++) {
    //         int tmp=0;
    //         // cout<<"i,j"<<i<<" "<<j<<":"<<S[i]-S[0]<<" "<<S[j]-S[i+1]<<" "<<S[N]-S[j+1]<<endl;
    //         tmp = max(tmp, S[i]-S[0]);
    //         tmp = max(tmp, S[j]-S[i+1]);
    //         tmp = max(tmp, S[N]-S[j+1]);
    //         ans = min(ans, tmp);
    //     }
    // }

    return ans;
}
