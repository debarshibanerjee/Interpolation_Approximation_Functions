### Taylor Approximation:

- The approximation goes really wrong for values diverging from 0. It performs best in the immediate neighbourhood of 0.
- These divergences are particularly clear in the logscale plot.
- It works best for |x| < 1, beyond that limit it explodes. But on the negative axis, it performs worse than for 0 < x < 1
- The approximation will improve somewhat for higher degrees of the polynomial, as we can see that 7th order does a better job than 5th order.
- However, the divergence will still be quite high.


### Pade Approximation:

- When x < -5 and x > +5, it becomes worse and worse in the approximation.
- It works very well for x in the range [-5:+5]
- Compared to Taylor, it performs worse where the strong exponential divergence occurs as Pade doesn't capture that behaviour.

