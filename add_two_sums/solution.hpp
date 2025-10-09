#pragma once
#include <list_node.hpp>
#include <string>
class Solution
{
   private:
    void push_back_to_list(int val)
    {
        if (sum_list_head == nullptr)
        {
            sum_list_head = new ListNode(val);
            sum_list_tail = sum_list_head;
        }
        else
        {
            sum_list_tail->next = new ListNode(val);
            sum_list_tail = sum_list_tail->next;
        }
    }
    ListNode* add(ListNode* l1, ListNode* l2)
    {
        auto sum = 0;
        auto carry = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            if (l1 != nullptr)
            {
                sum = (sum + l1->val + carry);
                l1 = l1->next;
                carry = 0;
            }
            if (l2 != nullptr)
            {
                sum = (sum + l2->val + carry);
                l2 = l2->next;
                carry = 0;
            }
            if (sum >= 10)
            {
                sum %= 10;
                carry = 1;
            }
            push_back_to_list(sum);
            sum = 0;
        }
        if (carry)
        {
            push_back_to_list(carry);
        }
        return sum_list_head;
    }
    ListNode* sum_list_head = nullptr;
    ListNode* sum_list_tail = nullptr;

   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { return add(l1, l2); }
};