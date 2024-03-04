#include "list.h"
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

int main() {
  test_testing();
  return 0;
}
