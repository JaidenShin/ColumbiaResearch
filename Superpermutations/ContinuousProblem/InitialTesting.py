# initial testing on the length of an optimal superpermutation of length n

import numpy as np
import math
import matplotlib.pyplot as plt

# recursion/dynamic programming approach to find the probability that various lengths l work as superpermutations
probs = [[0 for l in range(1000)] for n in range(20)]


# base case: if L = 0, P = 0
probs[1][1] = 1
for l in range(1, 1000):
  probs[1][l] = 1
for n in range(2,20):
  for l in range(1,1000):
    if n <= l:
      probs[n][l] = (1/n) * probs[n-1][l-1] + ((n-1)/(n)) * probs[n][l-1]


n = 2
for l in range(2,50):
  print(probs[n][l])

# if the probability that a length l string has a supermermutation of length n is less than 1 - (1/n!),
# there is no superpermutaiton
def findBound(n):
  for l in range(1,1000):
    if math.factorial(n)*(1-probs[n][l]) < 1:
      return l


Ns = []
bounds = []

# plotting the bounds as a function of n

for n in range(2,17):
  Ns.append(n)
  bounds.append(findBound(n))
  print("n == ", n, " bound == ", findBound(n))


plt.plot(np.log(Ns), np.log(bounds))
slope = (np.log(bounds[-1]) - np.log(bounds[3])) / (np.log(Ns[-1]) - np.log(Ns[3]))
print(slope)


n = 19
Ls = list(range(1000))
plt.plot(Ls, probs[n])

#plt.plot(Ls, np.log(np.divide(1, probs[n]) - 1))

L = 10
ns = list(range(0,20))
probVals = np.zeros(20)
for n in ns:
  probVals[n] = probs[n][L]
plt.plot(ns, probVals)


