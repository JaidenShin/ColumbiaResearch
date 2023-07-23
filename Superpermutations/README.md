# README

Given an integer $n$, strings may be constructed with each character being a number from $1$ to $n$ inclusive. The basis of the 
superpermutation problem is to find the minimal-length string that contains all $n!$ permutations of $1$ through $n$ in the string. 
There are two possible interpretations.

### Contiguous Version:

This is a fairly well known version of the problem, much of the existing work consolidated [here](https://www.gregegan.net/SCIENCE/Superpermutations/Superpermutations.html).

In this version, for a permutation to "appear" in a string, it needs to appear as a continguous block. For example, the permutation $12345$ exists in the string 
5431234524. 
