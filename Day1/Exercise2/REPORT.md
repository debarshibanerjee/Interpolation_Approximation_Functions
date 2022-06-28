### nmax vs error and execution time:
- As we increase nmax from 100 to 10000 (100, 500, 1000, 2000, 5000, 10000) we see a slight increase in execution time.
- Correspondingly, we also see the error reduce as we increase nmax.
- From the graph of error vs nmax (in logscale along error axis), we see the smoothening of the curve, and we can see that reaching very high levels of accuracy (say, 10^-10) would take a very large amount of nmax.
- Going from nmax = 2'000 to 10'000 changes accuracy only by 1 order of magnitude.

### Linear Interpolation:
- It depends on the performance vs accuracy trade-off.
- If we want very high performance and are satisfied with moderate accuracy, we should be satisfied with a reasonable nmax.
- However, if we want to reach very high degrees of accuracy, that is, if our application requires such high degrees of accuracy, then we will need to increase nmax very much, and linear interpolation will be worth the effort simply because we need the increased accuracy.
- This answer is motivated by the graph as it shows a significant smoothening of the reduction in error as we increase nmax, and further increases are unlikely to bear much higher accuracy very easily.
