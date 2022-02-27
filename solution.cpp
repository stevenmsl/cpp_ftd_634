#include "solution.h"
#include "util.h"
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>

using namespace sol634;
using namespace std;

/* takeaways
   - assume dp[n] records the number of derangements
     by permutating n integers
   - look at the possible derangements when n = 2
     - 21
   - when n = 3
     - since 21 is already a derangement, swapping
       3 with 1, or 2 will generate new derangements
     - 21[3] -> [3]12
     - 21[3] -> 2[3]1
     - for each derangement, we can generate another
       (3-1) new derangements as 3 can swap with numbers
       that are different from it.
     - dp[2] = (3-1)*dp[1] (don't forget it's 0-based)
   - we are overlooking a very important scenario if we
     stop here
   - when n = 4
     - we know dp[3] = (4-1) * dp[2] by the same reasoning
       above
     - but we can also generate new derangements by swapping
       4 with arrangements that only have one number remains
       in the same position (if there are more than 2 numbers
       remain in the same position we can't generate new
       derangements by swapping):
       1xx[4] -> [4]xx1
       x2x[4] -> x[4]x2
       xx3[4] -> xx[4]3
     - xx is actually one of the derangements counted in dp[1],
       and by swapping 4 with the that one number remains in
       the same position we can do (4-1) swaps as shown above
     - so dp[3] = (4-1) * dp[3-1] + (4-1) * dp[3-2]

*/
int Solution::findDerangement(int n)
{
  if (n == 1)
    return 0;

  /* use one-based or it's very easy to make mistake */
  auto dp = vector<long long>(n + 1, 0);
  /*edge cases when n = 1 and 2  */
  dp[1] = 0, dp[2] = 1;

  for (int i = 3; i <= n; i++)
    dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);

  auto result = (int)(dp[n] % 1000000007);
  return result;
}