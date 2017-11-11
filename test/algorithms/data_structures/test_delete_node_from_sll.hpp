#ifndef TEST_DELETE_NODE_FROM_SLL_HPP_
#define TEST_DELETE_NODE_FROM_SLL_HPP_

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>

#include "types/singly_linked_list_nodes.hpp"
#include "algorithms/data_structures/delete_node_from_sll.hpp"

BOOST_AUTO_TEST_CASE(test_dnfsll_delete_head_one_elem)
{
    NodeSLL<int>* sll = new NodeSLL<int>(10);
    DeleteNodeFromSLL(sll);

    std::vector<int> expectedValues = {0};
    BOOST_CHECK(expectedValues == ValuesInSLL(&sll));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(test_dnfsll_delete_head)
{
    NodeSLL<int>* sll = CreateSLL<int>({10, 9, 8, 7});

    DeleteNodeFromSLL(sll);

    std::vector<int> expectedValues = {9, 8, 7};
    BOOST_CHECK(expectedValues == ValuesInSLL(&sll));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(test_dnfsll_delete_middle)
{
    NodeSLL<int>* sll = CreateSLL<int>({10, 9, 8, 7});

    NodeSLL<int>* toDelete = sll;
    while(toDelete != nullptr && toDelete->value != 9)
    {
        toDelete = toDelete->next;
    }

    DeleteNodeFromSLL(toDelete);

    std::vector<int> expectedValues = {10, 8, 7};
    BOOST_CHECK(expectedValues == ValuesInSLL(&sll));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(test_dnfsll_delete_last)
{
    NodeSLL<int>* sll = CreateSLL<int>({10, 9, 8, 7});

    NodeSLL<int>* toDelete = sll;
    while(toDelete != nullptr && toDelete->value != 7)
    {
        toDelete = toDelete->next;
    }

    DeleteNodeFromSLL(toDelete);

    std::vector<int> expectedValues = {10, 9, 8, 0};
    BOOST_CHECK(expectedValues == ValuesInSLL(&sll));
    DeleteSLL(&sll);
}

#endif /* TEST_DELETE_NODE_FROM_SLL_HPP_ */