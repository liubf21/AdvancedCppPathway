// you can use includes, for example:
// #include <algorithm>
#include<bits/stdc++.h>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// 将日期字符串转换为可比较的格式（YYYYMMDD）
int convertDateToComparable(std::string date) {
    std::map<std::string, std::string> monthMap = {
        {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"},
        {"Apr", "04"}, {"May", "05"}, {"Jun", "06"},
        {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"},
        {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
    };

    std::string day = date.substr(0, 2);
    std::string month = monthMap[date.substr(3, 3)];
    std::string year = date.substr(7, 4);

    return std::stoi(year + month + day);
}

std::string solution(std::string &S) {
    std::istringstream iss(S);
    std::string line;
    int earliestDateInt = INT32_MAX;
    std::string earliestDateStr = "";
    int64_t maxSize = 14LL * (1LL << 20);  // 14 * 2^20 bytes

    while (getline(iss, line)) {
        std::string owner = line.substr(0, 6);
        owner.erase(owner.find_last_not_of(" ") + 1);  // Trim owner name
        std::string perm = line.substr(7, 3);
        std::string sizeStr = line.substr(23, 10);
        std::string dateStr = line.substr(11, 11);

        // cout<<perm<<" "<<owner<<" "<<sizeStr<<" "<<dateStr<<endl;
        sizeStr.erase(sizeStr.find_last_not_of(" ") + 1);
        int64_t size = std::stoll(sizeStr);

        // Check criteria
        if (perm[2] == 'x' && owner.find("admin") != std::string::npos && size < maxSize) {
            // cout<<"s:"<<size<<" "<<maxSize<<endl;
            int dateInt = convertDateToComparable(dateStr);
            if (dateInt < earliestDateInt) {
                earliestDateInt = dateInt;
                earliestDateStr = dateStr;
            }
        }
    }

    return earliestDateStr.empty() ? "NO FILES" : earliestDateStr;
} 
