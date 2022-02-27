#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol634;

/*
Example 1:
Input: 3
Output: 2
Explanation: The original array is [1,2,3]. The two derangements are [2,3,1] and [3,1,2].
*/
tuple<int, int>
testFixture1()
{
  return make_tuple(3, 2);
}
tuple<int, int>
testFixture2()
{
  return make_tuple(4, 9);
}
void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::findDerangement(get<0>(f));
  cout << "result: " << to_string(result) << endl;
}
void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::findDerangement(get<0>(f));
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}