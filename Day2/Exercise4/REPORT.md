I have implemented both 32 bit and 64 bit versions.

The magic number for the 64 bit version was taken from Wikipedia.

The outputs are summarized below, but you can see the full versions in 'NR\*.dat' files.

We report the ratio of times obtained (t_r = Q_rsqrt()/invsqrt()) since there is large fluctuation in the laptop's frequency.

### 32 bit:
- NR0: t_r = 0.199; err = 0.0222795

- NR1: t_r = 0.406; err = 0.000885839

- NR2: t_r = 0.468; err = 1.65778e-06


### 64 bit:
- NR0: t_r = 0.552; err = 0.0222871

- NR1: t_r = 0.662; err = 0.00088643

- NR2: t_r = 0.819; err = 1.66273e-06


### Notes:
- Overall, we can clearly see a slowdown as we add the Newton Raphson iterations, as we would expect.
- The 32 bit magic number is more 'settled' in academic discourse according to Wikipedia, and we can see slightly better accuracy, as well as better speedup for the 32 bit versions than the 64 bit version.
- In the code 'src/sqrt.c', the 32 bit version is kept commented at the beginning of the relevant function - 'Q_rsqrt'
