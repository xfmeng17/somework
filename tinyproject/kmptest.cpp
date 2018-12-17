#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

const int R = 256;

using namespace std;

int main() {
  string pattern = "ababac";
  int** dfa = new int*[R];
  for (int i = 0; i < R; i++) {
    dfa[i] = new int[pattern.length()];
  }
  dfa[pattern[0]][0] = 1;
  for (int x = 0, j = 1; j < pattern.length(); j++) {
      for (int c = 0; c < R; c++) {
          dfa[c][j] = dfa[c][x];
      }
      dfa[pattern[j]][j] = j + 1;
      printf("bef x = %d\n", x);
      printf("pat = %c\n", pattern[j]);
      x = dfa[pattern[j]][x];
      printf("aft x = %d\n", x);
  }
  printf("end = %d\n", dfa['c'][pattern.length() - 1]);
  return 0;
}