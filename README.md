# ColumbiaResearch

This is the code relevant to our year-long (September 2022 to May 2023) internship at Columbia University under the guidance of Professor Ivan Corwin. 
Our research was in the field of Probability Theory, and we focused on three main problems. We used simulations to verify results/numerical constants and motivate conjectures in conjunction with our mathematical work. Code is mainly in Python using matplotlib and C++.
## Last Passage Percolation (LPP):

Last Passage Percolation concerns particles traversing an $m \times m$ grid via an up-right path. Each edge is assigned an i.i.d. Gumbel random variable that dictates when the particle can cross over the edge. The Gumbel distrubtion has a Cumulative Distribution Function of $F(x;\mu,\beta) = e^{-e^{-(x-\mu)/\beta}}$. We considered the standard Gumbel with $\mu = 0$ and $\beta = 1$. 

The *last passage time* is defined to be the maximum amount of passage time from $(0,0)$ to $(m,m)$ via the recursion $$T_{a,b} = \max(T_{a-1,b} + U_{a,b}, T_{a,b-1} + V_{a,b}),$$ where $U$ and $V$ are families of Gumbel random variables for the horizontal and vertical edges, respectively.

When the last passage time for a grid with Gumbel edge weights is, it converges to the Tracy-Widom Distribution with dyson index $\beta = 2$ as follows: 
$$\lim_{m\to\infty} \mathbb{P}\left(\frac{T_{m,m}-C\cdot m}{\sigma \cdot m^{1/3}} \leq r \right) = F_{\text{GUE}}(r).$$
We numerically verified that these two distributions do converge and that $C$ and $\sigma$ values are as expected.

It is also possible to replace the Gumbel variable at each edge with $N$ i.i.d. variables governed by an unbounded distribution that is not heavy-tailed. The waiting time at each edge is then defined to be the maximum of the $N$ random variables. We then considered when this last passage time would approach the last passage time for the Gumbel model, as $m,N \to \infty$ under some relation. 

If we set $N = m^\alpha$, convergence is dependent on $\alpha > \alpha_c$, where $\alpha_c$ is some constant. We ran simulations to bound the value of $\alpha_c$. 
