#include <iostream>

using namespace std;

// you dont cross junction point of the lines to produce more region than the less
// every nth cut you try to touch n-1 lines thus, n new regions (n-1 lines create n regions, touching n-1 lines means spliting n regions, hence n new regions)
// so nth cut means total, n (pieces) + n-1 + n-2 + 1 (the last when there is no cut)
int main()
{

  long long n = 0;

  while (true)
  {
      cin >> n;

      if (n < 0)
      {
          break;
      }

      cout << ((n * (n + 1)) / 2) + 1 << endl;
  }

  return 0;
}
