// Checks a string to see if all N! permutations (for a given N) can be found in the string

#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>

int N = 9;
int Nfact;
string str = "12345678123456712345617234516723415762314765231"; // tested string
string strN;
int prevSize = 39; 
int tryNum = 5;
vi perm = vector<int>(N);

int factorial(int n) {
  if (n == 0)
    return 1;
  return n * factorial(n - 1);
}

void setup() {
  strN = to_string(N);
  Nfact = factorial(N);
  for (int i = 0; i < N; i++) {
    perm[i] = i + 1;
  }
}

bool checkPerm(vi &perm, string superPerm) { // check string for a specific permutation
  int index = 0;
  for (int i = 0; i < superPerm.length() && index < N; i++) {
    if (superPerm[i] - 48 == perm[index]) {
      index++;
    }
  }
  return index == N;
}

void print(vi &vec) {
  for (int v : vec) {
    cout << v << " ";
  }
  cout << "\n";
}

int checkString(string superPerm) { // check string for all permutations
  int numNotPresent = 0;
  for (int i = 0; i < Nfact; i++) {
    if (!checkPerm(perm, superPerm)) {
      numNotPresent++;
    }
    next_permutation(perm.begin(), perm.end());
  }
  return numNotPresent;
}

int main() {
  setup();
  string superPerm = "1234567891  234567819  234567189  234561798  234516987  "
                     "234159876  231498765  231";
  cout << checkString(superPerm) << "\n";
}