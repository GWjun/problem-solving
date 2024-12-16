#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 현재 수가 리스트에서 마지막 값보다 크다면, 그 수를 리스트 끝에 추가합니다.
 * 현재 수가 리스트 중간 어딘가에 들어갈 수 있다면, 이진 탐색을 통해 그 위치를 찾고 해당 자리를 대체합니다.
 * 대체하는 이유는 더 작은 값으로 바꿀수록 이후 수들과 더 긴 증가 부분 수열을 만들 가능성이 있기 때문입니다.
 */
int lis(vector<int>& arr) {
    vector<int> lisSeq;

    /**
     * for lds
     * reverse(arr.begin(), arr.end());
     */

    for (int i = 0; i < arr.size(); i++) {
        auto pos = lower_bound(lisSeq.begin(), lisSeq.end(), arr[i]);
        if (pos == lisSeq.end()) {
            lisSeq.push_back(arr[i]);
        }
        else {
            *pos = arr[i];
        }
    }

    return lisSeq.size();
}

int main() {
    vector<int> arr = { 10, 20, 10, 30, 20, 50 };
    cout << "LIS 길이: " << lis(arr) << endl;
    return 0;
}
