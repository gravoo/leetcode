
#include <cassert>
#include <cstdint>
#include <two_sums.hpp>

void verify_single_list_generator(std::uint64_t value)
{
    std::cout << "TEST verify_single_list_generator\n";
    ListNode* l1 = generate_list_node(value);
    auto actual = get_number_from_nodes(l1);
    assert(actual == value);
    delete l1;
}
void verify_list_generator(int value)
{
    std::cout << "TEST verify_list_generator\n";
    ListNode* l1;
    for (int i = 0; i < value; i++)
    {
        l1 = generate_list_node(i);
        auto actual = get_number_from_nodes(l1);
        assert(actual == i);
        delete l1;
    }
}
void verify_sum(int value)
{
    std::cout << "TEST verify_sum\n";
    Solution sol;
    for (int i = 0; i < value; i++)
    {
        auto l1_int = i;
        auto l2_int = i;
        ListNode* l1 = generate_list_node(l1_int);
        ListNode* l2 = generate_list_node(l2_int);
        ListNode* l3 = sol.addTwoNumbers(l1, l2);
        auto actual = get_number_from_nodes(l3);
        assert(actual == l1_int + l2_int);
        delete l1;
        delete l2;
        delete l3;
    }
}
int main()
{
    std::cout << "TEST STARTED\n";
    verify_list_generator(1000);
    verify_sum(1000);
    std::cout << "TEST ENDED\n";
}