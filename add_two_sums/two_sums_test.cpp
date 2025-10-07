
#include <cassert>
#include <cstdint>
#include <two_sums.hpp>

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
void test_node_generator(std::string str)
{
    ListNode* l1 = generate_list_node_from_string(str);
    auto actual = l1->get_string();
    std::cout << "Expected: " << str << " actual: " << actual << std::endl;
    assert(str == actual);
    delete l1;
}
void add_two_strings(std::string s1, std::string s2, std::string expected)
{
    ListNode* l1 = generate_list_node_from_string(s1);
    ListNode* l2 = generate_list_node_from_string(s2);
    Solution adder;
    auto l3 = adder.addTwoNumbers(l1, l2);
    auto actual = l3->get_string();
    std::cout << "Expected: " << expected << " actual: " << actual << std::endl;
    assert(expected == actual);
    delete l3;
    delete l2;
    delete l1;
}
void add_two_one_element_strings(std::string s1, std::string s2, std::string expected)
{
    add_two_strings(s1, s2, expected);
}
void add_two_strings_with_no_carry(std::string s1, std::string s2, std::string expected)
{
    add_two_strings(s1, s2, expected);
}
void add_two_strings_with_carry(std::string s1, std::string s2, std::string expected)
{
    add_two_strings(s1, s2, expected);
}
int main()
{
    std::cout << "START TEST\n";
    test_node_generator("[0]");
    test_node_generator("[5]");
    test_node_generator("[1,5]");
    test_node_generator("[1,5,2]");
    add_two_one_element_strings("[1]", "[1]", "[2]");
    add_two_one_element_strings("[3]", "[4]", "[7]");
    add_two_one_element_strings("[3]", "[4]", "[7]");
    add_two_strings_with_no_carry("[0, 1]", "[4]", "[4,1]");
    add_two_strings_with_no_carry("[1]", "[4,1]", "[5,1]");
    add_two_strings_with_no_carry("[0,1,1]", "[0,1,1]", "[0,2,2]");
    add_two_strings_with_no_carry("[0,1,1,1]", "[0,1,1,1]", "[0,2,2,2]");
    add_two_strings_with_no_carry("[0,1,1,1,1]", "[0,1,1,1,1]", "[0,2,2,2,2]");
    add_two_strings_with_no_carry("[0,1,1,1,1]", "[0,1,1]", "[0,2,2,1,1]");
    add_two_strings_with_carry("[9]", "[1]", "[0,1]");
    add_two_strings_with_carry("[9]", "[9]", "[8,1]");
    add_two_strings_with_carry("[1,1]", "[9]", "[0,2]");
    std::cout << "END TEST\n";
}