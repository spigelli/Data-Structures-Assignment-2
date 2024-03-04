// #include "list.h"
#include "node.cpp"
#include "test.h"
#include <iostream>

void test_testing() {
  TestSuite suite("Testing suite tester");
  // Anonymous function that will never throw
  suite.addTest("Test that always passes", []() {});
  // Anonymous function that will always throw
  suite.addTest("Test that always fails", []() { throw std::runtime_error("This test always fails"); });
  suite.run();
}

void test_node() {
  TestSuite suite = TestSuite("Node");

  suite.addTest("Node constructor", []() {
    Node<int> node = Node<int>(1, nullptr);
  });

  suite.addTest("Node constructed with next", []() {
    Node<int>* next = new Node<int>(1, nullptr);
    Node<int>* node = new Node<int>(2, next);

    if (node->getNext() != next) {
      delete next;
      delete node;
      throw std::runtime_error("Node next is not the same as the one passed to the constructor");
    }

    delete next;
    delete node;
  });

  suite.addTest("Node data setter", []() {
    Node<int> node = Node<int>(1, nullptr);
    node.setData(2);
    if (node.getData() != 2) {
      throw std::runtime_error("Node data setter is not working");
    }
  });

  suite.run();
}

int main() {
  // test_testing();
  test_node();
  return 0;
}
