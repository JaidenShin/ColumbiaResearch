// a potential idea to use Markov Chains to find the optimal superpermutation length: begin at an arbitrary string in the
// space of all working supermerutations, and with transition probabilities that favor shortening the string and heavily 
// penalize lengthening it, settle around a near-optimal string after a sufficiently long time.


#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>

int N = 4;
string superPerm = "1234123412341234";
double beta = 1;
int T = 1;
int Nfact;
vi perm = vi(N);

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

bool check(vi &perm, string superPerm) {
  int index = 0;
  for (int i = 0; i < superPerm.length() && index < N; i++) {
    if (superPerm[i] - 48 == perm[index]) {
      index++;
    }
  }
  return index == N;
}

int checkString(string superPerm) {
  int numNotPresent = 0;
  for (int i = 0; i < Nfact; i++) {
    if (!check(perm, superPerm)) {
      numNotPresent++;
    }
    next_permutation(perm.begin(), perm.end());
  }
  return numNotPresent;
}

int main() {
  setup();
  for (int t = 0; t < T; t++) {
    cout << "t == " << t << "\n";
    int len = superPerm.length();
    string newStr;
    double totalProb = 0;
    // adding character: one possible state transition
    for (int j = 1; j <= N; j++) {
      newStr = to_string(j) + superPerm;
      totalProb += pow(M_E, (-1) * beta * (len + 1));
    }
    for (int i = 1; i < len; i++) {
      for (int j = 1; j <= N; j++) {
        if (j != superPerm[i - 1] - 48 && j != superPerm[i + 1] - 48) {
          newStr = superPerm.substr(0, i) + to_string(j) +
                   superPerm.substr(i, len - i);
          totalProb += pow(M_E, (-1) * beta * (len + 1));
        }
      }
    }
    for (int j = 1; j <= N; j++) {
      newStr = superPerm + to_string(j);
      totalProb += pow(M_E, (-1) * beta * (len + 1));
      // removing character: the second possible state transition
      newStr = superPerm.substr(1, len - 1);
      if (checkString(newStr) == 0) {
        totalProb += pow(M_E, (-1) * beta * (len - 1));
      }
      for (int i = 1; i < len - 1; i++) {
        newStr = superPerm.substr(0, i) + superPerm.substr(i + 1, N - i - 1);
        if (checkString(newStr) == 0) {
          totalProb += pow(M_E, (-1) * beta * (len - 1));
        }
      }
      newStr = superPerm.substr(0, len - 1);
      if (checkString(newStr) == 0) {
        totalProb += pow(M_E, (-1) * beta * (len - 1));
      }
      // switching adjacent characters: the third possible state transition
      newStr = superPerm.substr(1, 1) + superPerm.substr(0, 1) +
               superPerm.substr(2, len - 2);
      if (checkString(newStr) == 0) {
        totalProb += pow(M_E, (-1) * beta * len);
      }
      for (int i = 1; i < len - 2; i++) {
        newStr = superPerm.substr(0, i) + superPerm.substr(i + 1, 1) +
                 superPerm.substr(i, 1) + superPerm.substr(i + 2, len - i - 2);
        if (checkString(newStr) == 0) {
          totalProb += pow(M_E, (-1) * beta * len);
        }
      }
      newStr = superPerm.substr(0, len - 2) + superPerm.substr(len - 1, 1) +
               superPerm.substr(len - 2, 1);
      if (checkString(newStr) == 0) {
        totalProb += pow(M_E, (-1) * beta * len);
      }
    }

    double rnd = ((double) rand() / (RAND_MAX));
    cout << "rnd: " << rnd << "\n";
    
    // repeating the same thing, but figuring out the cost 
    
    double p;
    // adding character
    for (int j = 1; j <= N; j++) {
      newStr = to_string(j) + superPerm;
      p = pow(M_E, (-1) * beta * (len + 1));
      cout << "p: " << p << "\n";
      if (rnd <= p) {
        superPerm = newStr;
        continue;
      }
      rnd -= p;
      cout << "rnd: " << rnd << "\n";
    }
    for (int i = 1; i < len; i++) {
      for (int j = 1; j <= N; j++) {
        if (j != superPerm[i - 1] - 48 && j != superPerm[i + 1] - 48) {
          newStr = superPerm.substr(0, i) + to_string(j) +
                   superPerm.substr(i, len - i);
          p = pow(M_E, (-1) * beta * (len + 1));
          cout << "p: " << p << "\n";
          if (rnd <= p) {
            superPerm = newStr;
            continue;
          }
          rnd -= p;
          cout << "rnd: " << rnd << "\n";
        }
      }
    }
    for (int j = 1; j <= N; j++) {
      newStr = superPerm + to_string(j);
      p = pow(M_E, (-1) * beta * (len + 1));
      cout << "p: " << p << "\n";
      if (rnd <= p) {
        superPerm = newStr;
        continue;
      }
      rnd -= p;
      cout << "rnd: " << rnd << "\n";
    }
    // removing character
    newStr = superPerm.substr(1, len - 1);
    if (checkString(newStr) == 0) {
      p = pow(M_E, (-1) * beta * (len - 1));
      cout << "p: " << p << "\n";
      if (rnd <= p) {
        superPerm = newStr;
        continue;
      }
      rnd -= p;
      cout << "rnd: " << rnd << "\n";
    }
    for (int i = 1; i < len - 1; i++) {
      newStr = superPerm.substr(0, i) + superPerm.substr(i + 1, N - i - 1);
      if (checkString(newStr) == 0) {
        p = pow(M_E, (-1) * beta * (len - 1));
        cout << "p: " << p << "\n";
        if (rnd <= p) {
          superPerm = newStr;
          continue;
        }
        rnd -= p;
        cout << "rnd: " << rnd << "\n";
      }
    }
    newStr = superPerm.substr(0, len - 1);
    if (checkString(newStr) == 0) {
      p = pow(M_E, (-1) * beta * (len - 1));
      cout << "p: " << p << "\n";
      if (rnd <= p) {
        superPerm = newStr;
        continue;
      }
      rnd -= p;
      cout << "rnd: " << rnd << "\n";
    }
    // switching adjacent characters
    newStr = superPerm.substr(1, 1) + superPerm.substr(0, 1) +
             superPerm.substr(2, len - 2);
    if (checkString(newStr) == 0) {
      p = pow(M_E, (-1) * beta * len);
      cout << "p: " << p << "\n";
      if (rnd <= p) {
        superPerm = newStr;
        continue;
      }
      rnd -= p;
      cout << "rnd: " << rnd << "\n";
    }
    for (int i = 1; i < len - 2; i++) {
      newStr = superPerm.substr(0, i) + superPerm.substr(i + 1, 1) +
               superPerm.substr(i, 1) + superPerm.substr(i + 2, len - i - 2);
      if (checkString(newStr) == 0) {
        p = pow(M_E, (-1) * beta * len);
        cout << "p: " << p << "\n";
        if (rnd <= p) {
          superPerm = newStr;
          continue;
        }
        rnd -= p;
        cout << "rnd: " << rnd << "\n";
      }
    }
    newStr = superPerm.substr(0, len - 2) + superPerm.substr(len - 1, 1) +
             superPerm.substr(len - 2, 1);
    if (checkString(newStr) == 0) {
      p = pow(M_E, (-1) * beta * len);
      cout << "p: " << p << "\n";
      if (rnd <= p) {
        superPerm = newStr;
        continue;
      }
      rnd -= p;
      cout << "rnd: " << rnd << "\n";
    }
  }

  cout << superPerm << "\n";
}