/*
There are N cars, numbered from 0 to N-1. Each of them has
some of the M possible optional features, numbered from 0 to
M-1, for example: voice control, keyless entry, sunroof, blind spot
detection, etc. The features of a car are described as a string of
M characters, where the K-th character being '1' denotes that that thhe
car has the K-th possible feature and '0' denotes that it does not.
Two cars are similar if their descriptions differ by at most one
feature. For example: "01101" and "01001" are similar, because
they differ only by feature number 2. On the other hand, "01101 
and "1110" are not similar, because they differ in feature
numbers 0,3 and 4.
Each car from the following set is similar to "011": "011", "111",
"001", "010". Notice that cars "011" and "011" are similar as their
set of features is exactly the same.
We want to suggest to potential customers alternative cars to
the one under consideration. In order to do that,for each
individual car, calculate the number of other cars to which it is
similar (differ from it by at most one feature).

Write a function:
vector<int> solution(vector<string> &cars);
that, given an array cars consisting of N strings, returns an array
of integers denoting, for every car in cars, the number of other
similar cars.

Examples:
1. Given cars = ["100", "110", "010", "011", "100"], the answer
should be [2, 3, 2, 1, 2]. Car number 0 ("100") is similar to car
number 1 ("110") and also to car number 4 ("100").
2. Given cars = ["0011", "0111", "0111", "0110", "0000"], the
answer should be [2, 3, 2, 2, O]. Notice that car number 4 ("0000")
is not similar to any other car. All of the other cars have at least
two features, while car number 4 has none.
Write an efficient algorithm for the following assumptions:
+ N is an integer within the range [1..10,000];
+ M is an integer within the range [1..15];
+ all strings in the array cars are of length M and
consist only of the characters '0' and '1'

*/
// you can use includes, for example:
// #include <algorithm>
#include <bits/stdc++.h>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<string> &cars) {
    // Implement your solution here
    // 判断向量是否相似
    // 如果逐个判断 复杂度 15*O(N^2)
    // 可以用 unordered_map<string, int> 快速查找是否存在
    const int N = cars.size();
    const int M = cars[0].size();
    vector<int> ans(N, 0);
    unordered_map<string, int> cnt;
    for (auto& c: cars) {
        cnt[c] ++;
    }
    for (int i=0; i<N; i++) {
        ans[i] += cnt[cars[i]] - 1;
        // 对每个car，进行变换
        for (int j=0; j<M; j++) {
            string tmp(cars[i]);
            if (tmp[j]=='0')tmp[j]='1';
            else tmp[j]='0';
            if (cnt.find(tmp)!=cnt.end())ans[i]+=cnt[tmp];
        }
    }
    for (auto& a: ans)cout<<a<<" ";
    cout<<endl;
    return ans;
}