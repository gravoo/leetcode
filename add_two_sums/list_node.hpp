#pragma once
#include <string>
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    ~ListNode()
    {
        if (next != nullptr)
        {
            delete next;
        }
    }
    std::string get_string()
    {
        auto tmp = this;
        std::string result;
        if (tmp != nullptr)
        {
            result += std::string("[");
        }
        while (tmp != nullptr)
        {
            result += std::to_string(tmp->val);
            tmp = tmp->next;
            if (tmp != nullptr)
            {
                result += std::string(",");
            }
        }
        if (!result.empty())
        {
            result += std::string("]");
        }
        return result;
    }
};