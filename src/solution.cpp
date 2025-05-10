#include "solution.h"
#include <string>
#include <iostream>

using namespace std;

Solution::Solution()
{
}

void Solution::Process()
{
    string input = "(((((((234))))))x(()()()()())))22)(x))";
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '(') {
            stack_.push_back(i);
        } else if (input[i] == ')') {
            if (stack_.empty()) {
                rightSkip_.insert(i);
                continue;
            }
            if (input[stack_.back()] == '(') {
                stack_.pop_back();
                continue;
            } else {
                rightSkip_.insert(i);
            }
        }
    }

    leftSkip_ = unordered_set<int>(stack_.begin(), stack_.end()); // unordered_set是个匿名变量，为右值，会调用unordered_set的转移赋值函数

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '(') {
            if (leftSkip_.find(i) != leftSkip_.end()) {
                continue;
            }
        } else if (input[i] == ')') {
            if (rightSkip_.find(i) != rightSkip_.end()) {
                continue;
            }
        }
        cout << input[i];
    }
    cout << endl;
}
