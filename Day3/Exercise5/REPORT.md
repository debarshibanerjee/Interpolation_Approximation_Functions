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

# Pade Approximation:

- In this case, the 32 bit and 64 bit versions take approximately the same total execution time. The caveats mentioned earlier about measuring the absolute time still apply, of course.
- The 32 bit version shows slightly increased accuracy over the 64 bit implementations.
- We once again compare the ratio of time to the time that the default 'exp()' function takes, not the other custom functions.

## 32 bit:
- [-10:+10]: t\_r = 0.667; err = 6.51399e-17; exec\_time = 0.097 us
- [-0.5:+0.5]: t\_r = 0.208; err = 2.10655e-17; exec\_time = 0.094 us

## 64 bit:
- [-10:+10]: t\_r = 1.994; err = 1.41668e-16; exec\_time = 0.098 us
- [-0.5:+0.5]: t\_r = 2.369; err = 1.94301e-17; exec\_time = 0.068 us

### Notes:

- My custom implementation - 'custom\_exp()' in src/exp.c, is on average faster than the default exp() for 32 bit. It is slower for 64 bit, however.
- The 32 bit version shows accuracy on the order of 10^-17 for both the ranges [-10:+10] and [-0.5:+0.5].
- The 64 bit version shows accuracy on the order of 10^-16 for [-10:+10] and 10^-17 for [-0.5:+0.5].
- Overall, one can conclude that especially for the 32 bit version, the Pade approximation delivers significant benefits both in terms of time and accuracy.

# Final Comments:

- The most accurate method to calculate exp(x) is the Pade approximation that we implement.
- It is hard to make a comment on the fastest method due to the variability arising from the usage of 32 and 64 bit versions.
- However, if we simply look at the improvement with respect to the native exponential function, the Taylor approximation appears faster on average, although for a range [-0.5:+0.5] the Pade approximation is almost equally competitive.
