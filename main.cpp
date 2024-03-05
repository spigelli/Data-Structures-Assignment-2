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

  suite.addTest("Push front", []() {
    List<int>* list = new List<int>();
    list->push_front(101);
    list->push_front(202);
    list->push_front(303);
    cout << "List after push_front: ";
    list->pretty_print();
    cout << endl;
    if (list->front() != 303) {
      throw std::runtime_error("Push front failed");
    }
    int index_of_101 = list->find(101);
    if (index_of_101 != 2) {
      throw std::runtime_error(
        "Expected 2, got " + std::to_string(index_of_101)
      );
    }
    delete list;
  });

  suite.addTest("Push back", []() {
    List<int>* list = new List<int>();
    list->push_back(101);
    list->push_back(202);
    list->push_back(303);
    cout << "List after push_back: ";
    list->pretty_print();
    cout << endl;
    if (list->back() != 303) {
      throw std::runtime_error("Push back failed");
    }
    int index_of_101 = list->find(101);
    if (index_of_101 != 0) {
      throw std::runtime_error(
        "Expected 0, got " + std::to_string(index_of_101)
      );
    }
    delete list;
  });

  suite.addTest("Pop front", []() {
    List<int>* list = create_int_list();
    cout << "List before pop_front: ";
    list->pretty_print();
    list->pop_front();
    cout << "List after pop_front: ";
    list->pretty_print();
    cout << endl;
    int list_front = list->front();
    if (list_front != 18) {
      throw std::runtime_error(
        "Expected 18, got " + std::to_string(list_front)
      );
    }
    delete list;
  });

  suite.addTest("Pop back", []() {
    List<int>* list = create_int_list();
    cout << "List before pop_back: ";
    list->pretty_print();
    list->pop_back();
    cout << "List after pop_back: ";
    list->pretty_print();
    cout << endl;
    int list_back = list->back();
    if (list_back != 4) {
      throw std::runtime_error(
        "Expected 4, got " + std::to_string(list_back)
      );
    }
    delete list;
  });

  suite.addTest("Empty", []() {
    List<int>* list = new List<int>();
    if (!list->empty()) {
      throw std::runtime_error("List should be empty");
    }
    list->push_front(101);
    if (list->empty()) {
      throw std::runtime_error("List should not be empty");
    }
    delete list;
  });

  suite.addTest("Insert", []() {
    List<int>* list = create_int_list();
    cout << "List before insert: ";
    list->pretty_print();
    list->insert(3, 99);
    cout << "List after insert: ";
    list->pretty_print();
    cout << endl;
    int index_of_99 = list->find(99);
    if (index_of_99 != 3) {
      throw std::runtime_error(
        "Expected 3, got " + std::to_string(index_of_99)
      );
    }
    delete list;
  });

  suite.addTest("Remove", []() {
    List<int>* list = create_int_list();
    cout << "List before remove: ";
    list->pretty_print();
    list->remove(3);
    cout << "List after remove: ";
    list->pretty_print();
    cout << endl;
    int index_of_12 = list->find(12);
    if (index_of_12 != 3) {
      throw std::runtime_error(
        "Expected 3, got " + std::to_string(index_of_12)
      );
    }
    delete list;
  });

  suite.addTest("Find", []() {
    List<int>* list = create_int_list();
    int index_of_12 = list->find(12);
    if (index_of_12 != 4) {
      throw std::runtime_error(
        "Expected 5, got " + std::to_string(index_of_12)
      );
    }
    int index_of_99 = list->find(99);
    if (index_of_99 != 10) {
      throw std::runtime_error(
        "Expected 10, got " + std::to_string(index_of_99)
      );
    }
    delete list;
  });

  suite.run();
}

int main() {
  // test_testing();
  test_list();
  return 0;
}
