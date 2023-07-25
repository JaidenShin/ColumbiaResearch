# ColumbiaResearch

This is the code relevant to our year-long (September 2022 to May 2023) internship at Columbia University under the guidance of Professor Ivan Corwin. 
Our research was in the field of Probability Theory, and we focused on three main problems. We used simulations to verify results/numerical constants and motivate conjectures in conjunction with our mathematical work. Code is mainly in Python using matplotlib and C++.
## Last Passage Percolation (LPP):

Last Passage Percolation concerns particles traversing an $m \times m$ grid via an up-right path. Each edge is assigned an i.i.d. Gumbel random variable that dictates when the particle can cross over the edge. The Gumbel distrubtion has a Cumulative Distribution Function of $F(x;\mu,\beta) = e^{-e^{-(x-\mu)/\beta}}$. We considered the standard Gumbel with $\mu = 0$ and $\beta = 1$. 

The *last passage time* is defined to be the maximum amount of passage time from $(0,0)$ to $(m,m)$ via the recursion $$T_{m,n} = \max(T_{m-1,n} + U_{m,n}, T_{m,n-1} + V_{m,n}),$$ where $U$ and $V$ are families of Gumbel random variables for the horizontal and vertical edges, respectively.

When the last passage time for a grid with Gumbel edge weights is , it converges to the Tracy-Widom Distribution with dyson index $\beta = 2$ as follows: 
$$\lim_{n\to\infty} \mathbb{P}\left(\frac{T_{n,n}-C\cdot n}{\sigma \cdot n^{1/3}} \leq r \right) = F_{text{GUE}}(r).$$
