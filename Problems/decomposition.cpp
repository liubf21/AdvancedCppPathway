/*
A decomposition of a positive integer Nis a set of unique possitive integers whose sum is equal to N

A decomposition is add if it contains only odd integers. The length of adecomposition is the number of integers comprising it. An odd
decomposition of N is maxima/if there is no other odd decommposition of N with a greater length. 

For example, N = 11 has two odd decompositions:
11 = 1 + 3 + 7
= 11
The first one has length 3 (and is maximal) and the second has length 1

Note that an integer can have more that one maximal odd deccomposition. For example, N = 8 has two maximal odd decompositions
8 = 1 + 7
= 3 + 5

Write a function:
vector<int> solution(int N);
that, given a positive integer N, returns an array R, which contains a maaximal odd decomposition of N. The numbers in array R should
appear in ascending order. If N does not have any odd decompositionss, array R should be empty. If there is more than one correct answer
the function may return any of them
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> decomposition(int remain, set<int> &decom);

vector<int> solution(int N) {
    auto decom = set<int>();
    return decomposition(N, decom);
}

vector<int> decomposition(int remain, set<int> &decom) {
    if (remain == 0) {
        vector<int> answer;
        for (auto it = decom.begin(); it != decom.end(); it++) {
            answer.push_back(*it);
        }
        return answer;
    }
    for (int i = 1; i <= remain; i+=2) { // i is odd
        if (decom.find(i) == decom.end()) { // i is not in decom
            decom.insert(i);
            vector<int> answer = decomposition(remain - i, decom);
            if (answer.size() != 0) {
                return answer;
            }
            decom.erase(i);
        }
    }
    return vector<int>();
}

int main() {
    int N;
    // cin >> N;
    N = 20;
    vector<int> answer = solution(N);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}