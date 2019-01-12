#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    if (x <= 9) {
        return true;
    }
    // solution 1
    /*
    vector<int> nums;
    while (x != 0) {
        int num = x % 10;
        nums.push_back(num);
        x /= 10;
    }
    for (int i = 0; i <= nums.size() / 2; ++i) {
        if (nums[i] != nums[nums.size() - i - 1]) {
            return false;
        }
    }
    return true;*/

    // solution 2
    int temp = 0,
        origin = x;
    while (x != 0) {
        temp = temp * 10 + (x % 10);
        x /= 10;
    }
    if (temp == origin) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int a = 121;
    cout << isPalindrome(a) << endl;
    int b = 12345;
    cout << isPalindrome(b) << endl;
    int c = -121;
    cout << isPalindrome(c) << endl;
}