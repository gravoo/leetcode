#include <iostream>

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void print_me() {
        auto tmp = this;
        while(tmp != nullptr){
            std::cout<<"["<<tmp->val<<"]";
            tmp = tmp->next;
        }
        std::cout<<std::endl;
    }
};
 
class Solution {
private:
    int get_number_from_nodes(ListNode* node) {
        int number = 0;
        int multiplier = 1;
        while(node != nullptr){
            number += node->val*multiplier;
            node = node->next;
            multiplier *=10; 
        }
        return number;     
    }
    ListNode* generate_list_node(int number)
    {
        ListNode *head = nullptr;
        if(number == 0){
            head = new ListNode(0);
        }
        else{
            ListNode *tmp = nullptr;
            while(number > 0){
                int digit = number % 10;
                number /= 10;
                if(head == nullptr){
                    head = new ListNode(digit);
                    tmp = head;      
                }
                else{
                    tmp->next = new ListNode(digit);
                    tmp = tmp->next; 
                }
            }
        }
        return head;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto num_1 = get_number_from_nodes(l1);
        auto num_2 = get_number_from_nodes(l2);
        auto num_result = num_1 + num_2;
        auto result = generate_list_node(num_result);
        result->print_me();
        return nullptr;
    }
};

int main() {
    Solution sol;
    ListNode l1(1);
    ListNode l2(2, &l1);
    ListNode l3(3, &l2);
    sol.addTwoNumbers(&l3, &l1);
    return 0;
}