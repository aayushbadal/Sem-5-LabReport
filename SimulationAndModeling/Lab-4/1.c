//Lab-4 Implementation of testing of uniformity of random numbers using chi-square test.
/*
Algorithm:
    1. Fix the number of intervals 'n' of equal length in [0,1]
    2. Compute E = N/n, where E is expected number in each interval, N is total sample size
    3. Compute the observed Oi in the interval for i=1,2,...
    4. Compute chi-square = SUM((Oi-Ei)^2)/Ei for i = 1 to n
    Where Oi is the observed number in the ith class.
          Ei is the expected number in the ith class
          n is the number of classes
    5. Determine the critical value Chi-square(t) from the chi-square table for the specified alpha and n-1 degree of freedom 
    6. If chi+squate > chi-square table the nnumbers are uniformily distributed else not.
*/