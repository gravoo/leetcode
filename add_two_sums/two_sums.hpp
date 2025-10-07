#include <cstdint>
#include <iostream>

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

class Solution
{
   private:
    int add_with_carry(int a, int b)
    {
        if (a + b >= 10)
        {
            return (a + b) % 10;
        }
        return a + b;
    }
    bool set_carry_flag(int a, int b)
    {
        if (a + b >= 10)
        {
            return true;
        }
        return false;
    }
    ListNode* add(ListNode* l1, ListNode* l2)
    {
        auto sum = 0;
        sum = add_with_carry(sum, l1->val);
        auto carry_flag = set_carry_flag(sum, l2->val);
        sum = add_with_carry(sum, l2->val);
        auto sum_list_head = new ListNode(sum);
        ListNode* sum_list_ptr = sum_list_head;

        if (l1->next == nullptr && l2->next == nullptr && carry_flag)
        {
            sum_list_ptr->next = new ListNode(1);
            sum_list_ptr = sum_list_ptr->next;
        }
        while (l1->next != nullptr || l2->next != nullptr)
        {
            auto has_next = false;
            auto sum = 0;
            if (l1->next != nullptr)
            {
                l1 = l1->next;
                sum = add_with_carry(sum, l1->val);
                has_next = true;
            }
            if (l2->next != nullptr)
            {
                l2 = l2->next;
                sum = add_with_carry(sum, l2->val);
                has_next = true;
            }
            if (has_next)
            {
                sum_list_ptr->next = new ListNode(sum);
                sum_list_ptr = sum_list_ptr->next;
            }
        }
        return sum_list_head;
    }

   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { return add(l1, l2); }
};