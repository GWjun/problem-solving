#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * KMP 알고리즘을 위한 LPS(Longest Prefix Suffix) 배열 생성 함수
 * ABABCABAB
 * 001201234
 */
vector<int> Fail(string& patt) {
    int m = patt.size();
    vector<int> fail(m); // 길이 저장?

    for (int i = 1, j = 0; i < m; i++) {
        // 불일치 시 j(접두사)를 줄임
        while (j > 0 && patt[i] != patt[j])
            j = fail[j - 1];

        if (patt[i] == patt[j])
            fail[i] = ++j;
    }

    return fail;
}

// KMP 알고리즘 구현
vector<int> KMP(string& str, string& patt) {
    int n = str.size();
    int m = patt.size();

    vector<int> fail = Fail(patt);
    vector<int> pos;

    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && str[i] != patt[j])
            j = fail[j - 1];

        if (str[i] == patt[j]) {
            if (j == m - 1) {
                pos.push_back(i - m + 1);
                j = fail[j];
            }
            else j++;
        }
    }
    return pos;
}

int main() {
    string str = "ABABDABACDABABCABAB";
    string patt = "ABABCABAB";

    cout << "텍스트: " << str << endl;
    cout << "패턴: " << patt << endl;
    auto pos = KMP(str, patt);

    for (auto& p : pos) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}
