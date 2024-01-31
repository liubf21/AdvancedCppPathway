// you can use includes, for example:
// #include <algorithm>
#include <bits/stdc++.h>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// Helper function to get the numeric value of rank
int getRankValue(const string &rank) {
    if (isdigit(rank[0])) {
        if (rank.size() > 1 && isdigit(rank[1])) {
            return 10;  // Handling "10"
        }
        return rank[0] - '0';
    } else {
        if (rank[0] == 'J') return 11;
        if (rank[0] == 'Q') return 12;
        if (rank[0] == 'K') return 13;
        if (rank[0] == 'A') return 14;
    }
    return 0;
}

// Helper function to extract rank from a card string
string extractRank(const string &card) {
    if (isdigit(card[0]) && card.size() > 2) {
        return card.substr(0, 2);  // For "10"
    }
    return card.substr(0, 1);
}

// Helper function to check for five in a row
std::vector<string> isFiveInARow(const map<int, vector<string>>& rankMap) {
    auto ans = std::vector<string>();
    for (auto it = rankMap.begin(); it != rankMap.end(); ++it) {
        int consecutive = 1;
        auto nextIt = it;
        std::vector<string> sequence = {it->second[0]}; // Start the sequence with the first card

        while (nextIt != rankMap.end() && (++nextIt) != rankMap.end() && nextIt->first == it->first + consecutive) {
            consecutive++;
            sequence.push_back(nextIt->second[0]);

            if (consecutive == 5) {
                ans = sequence;
            }
        }
    }
    return ans;
}

Results solution(vector<string> &cards) {
    // Implement your solution here
    Results result;
    // cout<<"res:"<<result.set_name<<endl;

    map<int, vector<string>> rankMap; // Map of ranks to cards
    map<char, vector<string>> suitMap; // Map of suits to cards
    for (const string &card : cards) {
        string rankStr = extractRank(card);
        int rankValue = getRankValue(rankStr);
        rankMap[rankValue].push_back(card);
        suitMap[card.back()].push_back(card);
    }

    // Check for the strongest set: a triple and a pair
    for (const auto& r : rankMap) {
        if (r.second.size() >= 3) {
            for (const auto& r2 : rankMap) {
                if (r2.second.size() >= 2 && r.first != r2.first) {
                    result.set_name = "a triple and a pair";
                    result.selected_cards = {r.second[0], r.second[1], r.second[2], r2.second[0], r2.second[1]};
                }
            }
        }
    }

    // Check for suit
    if (result.set_name.empty())
    for (const auto& s : suitMap) {
        if (s.second.size() >= 5) {
            result.set_name = "suit";
            result.selected_cards = {s.second.begin(), s.second.begin() + 5};
        }
    }

    // Check for five in a row
    if (result.set_name.empty()) {
        auto res = isFiveInARow(rankMap);
        if (!res.empty()) {
            result.set_name = "five in a row";
            result.selected_cards = res;
        }
    }

    // Check for triple
    if (result.set_name.empty())
    for (const auto& r : rankMap) {
        if (r.second.size() >= 3) {
            return {"triple", {r.second.begin(), r.second.begin() + 3}};
        result.set_name = "triple";
        result.selected_cards = {};
        }
    }

    // Check for pair
    if (result.set_name.empty())
    for (const auto& r : rankMap) {
        if (r.second.size() >= 2) {
            result.set_name = "pair";
            result.selected_cards = {r.second[0], r.second[1]};
        }
    }

    // Single card (highest rank)
    if (result.set_name.empty()) {
        auto highestRankCard = *max_element(cards.begin(), cards.end(), [](const string& a, const string& b) { return getRankValue(extractRank(a)) < getRankValue(extractRank(b)); });
        result.set_name = "single card";
        result.selected_cards = {highestRankCard};
    }

    // cout<<"res2:"<<result.set_name<<endl;
    // for (auto& c: result.selected_cards) cout<<c<<" ";
    // cout<<endl;

    return result;
}
