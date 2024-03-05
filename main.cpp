// #include "list.h"
// #include "node.h"
#include "list.cpp"
#include "test.h"
#include <iostream>
using namespace std;

void test_testing() {
  TestSuite suite("Testing suite tester");
  // Anonymous function that will never throw
  suite.addTest("Test that always passes", []() {});
  // Anonymous function that will always throw
  suite.addTest("Test that always fails", []() { throw std::runtime_error("This test always fails"); });
  suite.run();
}

// void test_node() {
//   TestSuite suite = TestSuite("Node");

//   suite.addTest("Node constructor", []() {
//     Node<int> node = Node<int>(1, nullptr);
//   });

//   suite.addTest("Node constructed with next", []() {
//     Node<int>* next = new Node<int>(1, nullptr);
//     Node<int>* node = new Node<int>(2, next);

//     if (node->getNext() != next) {
//       delete next;
//       delete node;
//       throw std::runtime_error("Node next is not the same as the one passed to the constructor");
//     }

//     delete next;
//     delete node;
//   });

//   suite.addTest("Node data setter", []() {
//     Node<int> node = Node<int>(1, nullptr);
//     node.setData(2);
//     if (node.getData() != 2) {
//       throw std::runtime_error("Node data setter is not working");
//     }
//   });

//   suite.run();
// }

List<int>* create_int_list() {
  int arr[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  List<int>* list = new List<int>();
  for (int new_item : arr) {
    list->push_front(new_item);
  }
  return list;
}

void test_list() {
  TestSuite suite = TestSuite("List");

  suite.addTest("List constructor", []() {
    List<int>* list = create_int_list();
    cout << "List created: ";
    list->pretty_print();
    cout << endl;
    delete list;
  });
}

int main() {
  // test_testing();
  // test_node();
  return 0;
}
