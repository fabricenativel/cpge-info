# Exercice 4
1. 
Grâce à l'inégalité proposée : $0 \leq e - S_n \leq \dfrac{1}{n.n!}$

Par endadrement, on obtient $u_n$ tend e lorsque n tend vers l'infini.


2. $P_n : n \in N, u_n = n! (e - S_n)$

Par récurrence :

- $P_0$ est trivial,

- $P_n \Rightarrow P_{n+1} ?$.

$u_{n+1} = (n+1) u_n - 1$ par hypothése $P_n$

$u_{n+1} = (n+1) n! (e-S_n) - 1$

$u_{n+1} = (n+1)! (e-S_n) - 1$ comme $S_{n+1} = S_n + \dfrac{1}{(n+1)!}$

$u_{n+1} = (n+1)! (e-S_{n+1} + \dfrac{1}{(n+1)!} ) -1$ par simplification

$u_{n+1} = (n+1)! (e-S_{n+1})$

3. 
$0 \leq e - S_n \leq \dfrac{1}{n.n!} \Rightarrow 0 \leq \dfrac{u_n}{n!} \leq \dfrac{1}{n.n!} \Rightarrow 0 \leq u_n  \leq 1/n$. La limite de u est 0 lorsque n tend vers l'infini.

4. 
```c
#include<stdio.h>
#include <stdbool.h>
#include <math.h>

int main(){
  double u = M_E - 1;
  printf(" %f ", M_E);
  int n = 0;
  while (n<26){
    printf("u(%d) = %f \n",n, u);
    n = n+1;
    u = (n) * u - 1;
  }
  return 0;
} 
```

5-6.
```
u(0) = 1.718282 
u(1) = 0.718282 
u(2) = 0.436564 
u(3) = 0.309691 
u(4) = 0.238764 
u(5) = 0.193819 
u(6) = 0.162916 
u(7) = 0.140415 
u(8) = 0.123323 
u(9) = 0.109911 
u(10) = 0.099112 
u(11) = 0.090234 
u(12) = 0.082808 
u(13) = 0.076506 
u(14) = 0.071080 
u(15) = 0.066203 
u(16) = 0.059248 
u(17) = 0.007213 
u(18) = -0.870163 
u(19) = -17.533092 
u(20) = -351.661841 
u(21) = -7385.898658 
u(22) = -162490.770476 
u(23) = -3737288.720950 
u(24) = -89694930.302806 
u(25) = -2242373258.570158 
```
La norme ieee-754 définit double sur  64 bits stockés dans l’ordre signe/exposant/mantisse. Les réels sont approchés et les erreurs sont cumulées, tout peut arriver!


