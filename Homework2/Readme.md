# Homework 2 : Snakes and Ladders (Discrete Simulation Assignment)
## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)


## **Part 1 - Emperical Tests of Randomness**

### (a)
<pre>The out put of 5 random number generator (RNG) engines:
https://github.com/staticninja/IDS6938-SimulationTechniques/blob/master/Homework2/images/RNG%20Output.xlsx</pre>

<pre>Charts to analyse how uniform the random numbers are.</pre>
<br>

|&nbsp; | Default Random Engine | Kunth-B | Ranlux 48 | Mersene Twister 19937 (64-bit) | Sobel |
|----------|----------|----------|----------|----------|----------|
|n = 250 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/Default_250.svg" width="300px">|<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/Knuth_250.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/240ae4ce/Homework2/images/Ranlux_250.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/MT_250.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/bfca0581/Homework2/images/Sobol_250Scrub.svg" width="300px"> | 
| n = 1,000 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/Default_1k.svg" width="300px">|<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/Knuth_1k.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/Ranlux_1k.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/MT_1k.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/bfca0581/Homework2/images/Sobol_1kScrub.svg" width="300px"> |
| n = 2,500 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/Default_2.5k.svg" width="300px">|<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/Knuth_2.5k.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/Ranlux_2.5k.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/MT_2.5k.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/bfca0581/Homework2/images/Sobol_2.5kScrub.svg" width="300px"> |
| n = 1,000 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/ffb6544f/Homework2/images/Default_PoleScrub.svg" width="300px">|<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/Knuth_Pole.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/Ranlux_Pole.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/MT_Pole.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/bfca0581/Homework2/images/Sobol_poleScrub.svg" width="300px"> |
<br>

<pre>Statistics to analyze RNG outputs</pre>

**Chi-Square**

|	N = 1,000	|	Mersene Twister 19937 (64 bit)	|	Default Random	|	Knuth-B	|	Ranlux 48	|	Sobol	|
|	----------	|	----------	|	----------	|	----------	|	----------	|	----------	|
|	**Chi-Square**	|	112.027(a)	|	116.256(b)	|	106.698(c)	|	105.927(d)	|	16.465(e)	|
|	**df**	|	99	|	99	|	99	|	99	|	99	|
|	**Asymp. Sig.**	|	.175	|	.113	|	.281	|	.299	|	1.000	|

a. 0 cells (0.0%) have expected frequencies less than 5. The minimum expected cell frequency is 9.9.										
b. 0 cells (0.0%) have expected frequencies less than 5. The minimum expected cell frequency is 10.0.										
c. 0 cells (0.0%) have expected frequencies less than 5. The minimum expected cell frequency is 9.9.										
d. 0 cells (0.0%) have expected frequencies less than 5. The minimum expected cell frequency is 9.9.										
e. 0 cells (0.0%) have expected frequencies less than 5. The minimum expected cell frequency is 9.9.										

<br>

**Spearman's Rank Correlation**

|	N = 1,000	|		|	Mersene Twister 19937 (64 bit)	|	Default Random	|	Knuth-B	|	Ranlux 48	|	Sobol	|
|	----------	|	----------	|	----------	|	----------	|	----------	|	----------	|	----------	|
|	**Mersene Twister 19937 (64 bit)**	|	Correlation Coefficient	|	1.000	|	.058*	|	.041	|	.003	|	.031	|
|		|	Sig. (1-tailed)	|		|	.032	|	.099	|	.464	|	.164	|
|		|	N	|	1000	|	1000	|	1000	|	1000	|	1000	|
|	**Default Random**	|	Correlation Coefficient	|	.058*	|	1.000	|	-.006	|	.000	|	-.016	|
|		|	Sig. (1-tailed)	|	.032	|		|	.429	|	.498	|	.308	|
|		|	N	|	1000	|	1000	|	1000	|	1000	|	1000	|
|	**Knuth-B**	|	Correlation Coefficient	|	.041	|	-.006	|	1.000	|	-.017	|	.025	|
|		|	Sig. (1-tailed)	|	.099	|	.429	|		|	.295	|	.215	|
|		|	N	|	1000	|	1000	|	1000	|	1000	|	1000	|
|	**Ranlux 48**	|	Correlation Coefficient	|	.003	|	.000	|	-.017	|	1.000	|	.035	|
|		|	Sig. (1-tailed)	|	.464	|	.498	|	.295	|		|	.136	|
|		|	N	|	1000	|	1000	|	1000	|	1000	|	1000	|
|	**Sobol**	|	Correlation Coefficient	|	.031	|	-.016	|	.025	|	.035	|	1.000	|
|		|	Sig. (1-tailed)	|	.164	|	.308	|	.215	|	.136	|		|
|		|	N	|	1000	|	1000	|	1000	|	1000	|	1000	|

*. Correlation is significant at the 0.05 level (1-tailed).													


### (b)

When changing the number of values output from a RNG from 10, 100, and 1000 the randomness seems to increase from 10 to 100 and then patterns start to emerge once you reach 1000.

### (c)

<pre>Charts to analyse the different distributions.</pre>
<br>

**Uniform**
![](https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/98f87e9c/Homework2/images/Uniform.svg)

**Normal**
![](https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/98f87e9c/Homework2/images/Normal.svg)

**Poisson**
![](https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/98f87e9c/Homework2/images/Poisson.svg)

**Exponent**
![](https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/98f87e9c/Homework2/images/Exponental.svg)

**Weibull**
![](https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/98f87e9c/Homework2/images/Weibull.svg)
<br>

<pre>Statistics to analyze distribution outputs</pre>

**Spearman's Rank Correlation Coefficient**

|	N = 100,000	|		|	Uniform	|	Normal	|	Poisson	|	Exponent	|	Weibull	|
|	-------------	|	-------------	|	-------------	|	-------------	|	-------------	|	-------------	|	-------------	|
|	**Uniform**	|	Correlation Coefficient	|	1.000	|	.001	|	-.002	|	-.005	|	-.005	|
|		|	Sig. (2-tailed)	|		|	.760	|	.567	|	.106	|	.098	|
|	**Normal**	|	Correlation Coefficient	|	.001	|	1.000	|	.001	|	-.002	|	.004	|
|		|	Sig. (2-tailed)	|	.760	|		|	.668	|	.444	|	.170	|
|	**Poisson**	|	Correlation Coefficient	|	-.002	|	.001	|	1.000	|	.005	|	.002	|
|		|	Sig. (2-tailed)	|	.567	|	.668	|		|	.098	|	.534	|
|	**Exponent**	|	Correlation Coefficient	|	-.005	|	-.002	|	.005	|	1.000	|	-.001	|
|		|	Sig. (2-tailed)	|	.106	|	.444	|	.098	|		|	.774	|
|	**Weibull**	|	Correlation Coefficient	|	-.005	|	.004	|	.002	|	-.001	|	1.000	|
|		|	Sig. (2-tailed)	|	.098	|	.170	|	.534	|	.774	|		|

<br>

**One-Sample Kolmogorov-Smirnov Test**

|		|		|	Uniform	|	Normal	|	Poisson	|	Exponent	|	Weibull	|
|	-------------	|	-------------	|	-------------	|	-------------	|	-------------	|	-------------	|	-------------	|
|	N	|		|	100000	|	100000	|	100000	|	100000	|	100000	|
|	Normal Parameters a,b	|	Mean	|	50.0327	|	50.0298	|	3.9978	|	1.0043	|	.9998	|
|		|	Std. Deviation	|	28.86395	|	9.99737	|	1.99738	|	.99915	|	1.00365	|
|	Most Extreme Differences	|	Absolute	|	.058	|	.003	|	.128	|	.157	|	.160	|
|		|	Positive	|	.058	|	.003	|	.128	|	.133	|	.135	|
|		|	Negative	|	-.058	|	-.001	|	-.070	|	-.157	|	-.160	|
|	Test Statistic	|		|	.058	|	.003	|	.128	|	.157	|	.160	|
|	Asymp. Sig. (2-tailed)	|		|	.000c	|	.045c	|	.000c	|	.000c	|	.000c	|
|	a. Test distribution is Normal.	|		|		|		|		|		|		|
|	b. Calculated from data.	|		|		|		|		|		|		|
|	c. Lilliefors Significance Correction.	|		|		|		|		|		|		|


### (d)

### (e)

### (f)

### Part 2 - Snakes and Ladders - Discrete Event Markov Chains and Monte Carlo Simulations

### Part 3 - Discrete Event Simulation - Queue Simulation

### Part 4 - Extra Features

### Part 5 - Final Report

### References
