#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

vector<string> split(string& str, char del) {
    vector<string> result;
    stringstream ss(str);
    string temp;

    bool isFirst = true;
    while (getline(ss, temp, del)) {
        if (isFirst && str[0] != '<') {
            isFirst = false;
            continue;
        }
        result.push_back(temp);
    }

    return result;
}