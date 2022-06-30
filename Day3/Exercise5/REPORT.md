# Taylor Approximation:

- In this case, 32 bit and 64 bit versions perform practically the same.
- Once again, like in the previous day's exercise, the ratio of times are reported: t\_r = (t\_exp/exp)
- This is to account for significant fluctuation in laptop's CPU performance due to boosting.

## 32 bit:
- [-10:+10]: t\_r = 0.174; err = 65878.4; exec\_time = 0.08 us
- [-0.5:+0.5]: t\_r = 0.166; err = 2.22336e-09; exec\_time = 0.10 us

## 64 bit:
- [-10:+10]: t\_r = 0.245; err = 65878.4; exec\_time = 0.07 us
- [-0.5:+0.5]: t\_r = 0.318; err = 2.22336e-09; exec\_time = 0.06 us

### Notes:

- The execution time RATIO becomes worse in the case of 64 bit, while it improves in the case of 32 bit as we decrease the interval to [-0.5:+0.5].
- However, the actual execution time follows the opposite trend. In the case of 32 bit, it is increased when we decrease the interval, and in the case of 64 bit it is increased when we increase the interval.
- The gaps aren't significant enough to make serious comments about the execution time behaviour, therefore. The variability due to laptop CPU performance is too high.
- For both 32 and 64 bit, we notice a HUGE decrease in error as we reduce the interval from ~65K to ~10^-9.
- This is in line with our expectations and shows the good predictability of Taylor approximation in neighbourhoods around 0.
