// tests the validity of a potential construction for supermutations of size n^2 - 2n + 4

#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>

int N = 8;
int Nfact; 
vi perm = vector<int>(N);

int factorial(int n) {
  if (n == 0) return 1;
  return n * factorial(n-1);
}

void setup() {
  Nfact = factorial(N);
  for (int i = 0; i < N; i++) {
    perm[i] = i+1;
  }
}

bool check(vi& perm, vector<string> superPerm) {
    int index = 0;
    for (int i = 0; i < superPerm.size() && index < N; i++) {
        if (superPerm[i][0] - 48 == perm[index]) {
            index++;
        }
    }
    return index == N;
}

void print(vector<string> vec) {
  for (string s : vec) {
    cout << s << " ";
  }
  cout << "\n";
}

void print(vector<int> vec) {
  for (int s : vec) {
    cout << s << " ";
  }
  cout << "\n";
}

int checkString(vector<string> superPerm) {
    int numNotPresent = 0;
    for (int i = 0; i < Nfact; i++) {
        if (!check(perm, superPerm)) {
            print(perm);
            numNotPresent++;
        }
        next_permutation(perm.begin(), perm.end());
    }
    return numNotPresent;
}

int main() {
  setup();
  // constructing the string
  vector<string> vecCon = vector<string>();
  for (int i = 1; i <= N; i++) {
    vecCon.push_back(to_string(i));
  }
  for (int i = 2; i < N; i++) {
    vecCon.push_back(to_string(i));
  }
  vecCon.push_back("1");
  vecCon.push_back(to_string(N));
  for (int k = 1; k <= N-4; k++) {
    for (int i = 2; i <= N-k-1; i++) {
      vecCon.push_back(to_string(i));
    }
    vecCon.push_back("1");
    vecCon.push_back(to_string(N-k));
    for (int i = N; i >= N-k+1; i--) {
      vecCon.push_back(to_string(i));
    }
  }
  vecCon.push_back(to_string(231));

  cout << checkString(vecCon) << "\n";
}