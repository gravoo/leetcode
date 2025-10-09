#pragma once
#include <list_node.hpp>
#include <solution.hpp>
#include <string>
ListNode* generate_list_node_from_string(std::string number)
{
    ListNode* head = nullptr;
    if (number.size() < 3)
    {
        head = new ListNode();
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
std::string add_two_strings(std::string s1, std::string s2)
{
    ListNode* l1 = generate_list_node_from_string(s1);
    ListNode* l2 = generate_list_node_from_string(s2);
    Solution adder;
    auto l3 = adder.addTwoNumbers(l1, l2);
    auto result = l3->get_string();
    delete l3;
    delete l2;
    delete l1;
    return result;
}