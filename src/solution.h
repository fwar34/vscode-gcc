#pragma once
#include <unordered_set>
#include <deque>

class Solution
{
public:
    Solution();
    void Process();

private:
    std::unordered_set<int> leftSkip_;
    std::unordered_set<int> rightSkip_;
    std::deque<int> stack_;
};