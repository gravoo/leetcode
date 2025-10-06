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
    void print_me()
    {
        auto tmp = this;
        while (tmp != nullptr)
        {
            std::cout << "[" << tmp->val << "]";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
    std::string get_string()
    {
        auto tmp = this;
        std::string result;
        while (tmp != nullptr)
        {
            result += std::string("[") + std::to_string(tmp->val) + std::string("]");
            tmp = tmp->next;
        }
        return result;
    }
};

ListNode* generate_list_node(std::uint64_t number)
{
    ListNode* head = nullptr;
    if (number == 0)
    {
        head = new ListNode(0);
    }
    else
    {
        ListNode* tmp = nullptr;
        auto divisor = 10;
        while (number > 0)
        {
            auto digit = number % divisor;
            number /= divisor;
            if (head == nullptr)
            {
                head = new ListNode(digit);
                tmp = head;
            }
            else
            {
                tmp->next = new ListNode(digit);
                tmp = tmp->next;
            }
        }
    }
    return head;
}

ListNode* generate_list_node_from_string(std::string number)
{
    ListNode* head = nullptr;
    if (number.size() == 3)
    {
        head = new ListNode(number[1] - '0');
    }
    else
    {
        ListNode* tmp = nullptr;
        for (auto i : number)
        {
            if (std::isdigit(i))
            {
                if (head == nullptr)
                {
                    head = new ListNode(i - '0');
                    tmp = head;
                }
                else
                {
                    tmp->next = new ListNode(i - '0');
                    tmp = tmp->next;
                }
            }
        }
    }
    return head;
}

std::uint64_t get_number_from_nodes(ListNode* node)
{
    std::uint64_t number = 0;
    std::uint64_t multiplier = 1;
    while (node != nullptr)
    {
        number += node->val * multiplier;
        node = node->next;
        multiplier *= 10;
    }
    return number;
}

class Solution
{
   private:
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        auto num_1 = get_number_from_nodes(l1);
        auto num_2 = get_number_from_nodes(l2);
        auto num_result = num_1 + num_2;
        return generate_list_node(num_result);
    }
};