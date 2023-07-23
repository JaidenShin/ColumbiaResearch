// a potential idea to construct a tree of all permutations, and move down the tree 
// as permutations were constructed in the string.

#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>

int N = 6;
int Nfact;
vi perm = vector<int>(N);
string superperm = "1234561234516234152631452361";
vector<vector<int>> permList;
vi currentIndices;

int factorial(int n) {
  if (n == 0)
    return 1;
  return n * factorial(n - 1);
}

void setup() {
  Nfact = factorial(N);
  for (int i = 0; i < N; i++) {
    perm[i] = i + 1;
  }
}

void print(vector<string> vec) {
  cout << "[" << vec[0];
  for (int i = 1; i < vec.size(); i++) {
    cout << ", " << vec[i];
  }
  cout << "]"
       << "\n";
}

void print(vector<int> vec) {
  cout << "[" << vec[0];
  for (int i = 1; i < vec.size(); i++) {
    cout << ", " << vec[i];
  }
  cout << "]"
       << "\n";
}

int main() {
  setup();
  permList = vector<vector<int>>(Nfact);
  currentIndices = vector<int>(Nfact);
  for (int i = 0; i < Nfact; i++) {
    permList[i] = vector<int>(N);
    for (int j = 0; j < N; j++) {
      permList[i][j] = perm[j];
    }
    next_permutation(perm.begin(), perm.end());
    currentIndices[i] = -1;
  }
  bool done = false;
  vi count(N);
  int superPermLength = 0;
  vector<string> superPerm;
  while (!done) {
    done = true;
    for (int i = 0; i < N; i++) {
      count[i] = 0;
    }
    for (int i = 0; i < Nfact; i++) {
      if (currentIndices[i] < N - 1) {
        done = false;
        count[permList[i][currentIndices[i] + 1] - 1]++;
      }
    }
    if (done)
      break;
    cout << "------- i == " << superPermLength << " -------\n";
    cout << "Count: ";
    print(count);

    int maxNum = superperm[superPermLength] - 48;

    int realMax = 0;
    for (int i = 0; i < N; i++) {
      realMax = max(realMax, count[i]);
    }
    cout << realMax << "\n";

    if (count[maxNum - 1] != realMax) {
      cout << "NOT MAX................\n";
      cout << "chosen num == " << maxNum << "\n";
    }
        superPerm.push_back(to_string(maxNum));
    for (int i = 0; i < Nfact; i++) {
      if (currentIndices[i] < N - 1) {
        if (permList[i][currentIndices[i] + 1] == maxNum) {
          currentIndices[i]++;
        }
      }
    }

    cout << "count[i] == " << count[maxNum - 1] << "\n";
    superPermLength++;
  }
  cout << "-----------------------------------\n";
  cout << superPermLength << "\n";
  cout << "super permutation: ";
  print(superPerm);
}