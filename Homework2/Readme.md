# Homework 2 : Snakes and Ladders (Discrete Simulation Assignment)
## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)


## **Part 1 - Emperical Tests of Randomness**

### (a)
<pre>The out put of 5 random number generator (RNG) engines:
https://github.com/staticninja/IDS6938-SimulationTechniques/blob/master/Homework2/images/RNG%20Output.xlsx</pre>

<pre>Charts to analyse how uniform the random numbers are.</pre>
<br>

**Default Random Engine**

![](https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b45808c9/Homework2/images/Default.svg)
<br>

**Knuth-B Generator**

![](https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b45808c9/Homework2/images/Knuth.svg)
<br>

**Minimal Standard**

![](https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b45808c9/Homework2/images/MinStand.svg)
<br>

**Ranlux 48**

![](https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b45808c9/Homework2/images/Ranlux.svg)
<br>

**Mersene Twister 19937 generator (64 bit)**

![](https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b45808c9/Homework2/images/Twister.svg)
<br>



































<pre>Statistics to analyze RNG outputs</pre>

**Spearman's Rank Correlation Coefficient**

|	N = 1,000		|						|	Default		|	Knuth			|	MinStand		|	Ranlux			|	Twister			|
|	-------------	|	-------------	|	-------------	|	-------------	|	-------------	|	-------------	|	-------------	|
|	**Default**	|	Correlation Coefficient	|	1.000	|	.018	|	-.008	|	-.022	|	.003	|
|		|	Sig. (2-tailed)	|		|	.569	|	.802	|	.478	|	.932	|
|	**Knuth**	|	Correlation Coefficient	|	.018	|	1.000	|	-.013	|	-.026	|	.041	|
|		|	Sig. (2-tailed)	|	.569	|		|	.684	|	.420	|	.194	|
|	**MinStand**	|	Correlation Coefficient	|	-.008	|	-.013	|	1.000	|	-.048	|	-.002	|
|		|	Sig. (2-tailed)	|	.802	|	.684	|		|	.131	|	.940	|
|	**Ranlux**	|	Correlation Coefficient	|	-.022	|	-.026	|	-.048	|	1.000	|	-.001	|
|		|	Sig. (2-tailed)	|	.478	|	.420	|	.131	|		|	.980	|
|	**Twister**	|	Correlation Coefficient	|	.003	|	.041	|	-.002	|	-.001	|	1.000	|
|		|	Sig. (2-tailed)	|	.932	|	.194	|	.940	|	.980	|		|
<br>

**One-Sample Kolmogorov-Smirnov Test**

|		|		|	Default	|	Knuth	|	MinStand	|	Ranlux	|	Twister	|
|	-------------	|	-------------	|	-------------	|	-------------	|	-------------	|	-------------	|	-------------	|
|	N	|		|	1000	|	1000	|	1000	|	1000	|	1000	|
|	Normal Parameters*^	|	Mean	|	49.6066	|	49.9000	|	49.5167	|	50.2467	|	50.2999	|
|		|	Std. Deviation	|	29.04843	|	28.73751	|	28.85284	|	28.76031	|	27.64012	|
|	Most Extreme Differences	|	Absolute	|	.067	|	.068	|	.062	|	.061	|	.073	|
|		|	Positive	|	.067	|	.068	|	.060	|	.061	|	.059	|
|		|	Negative	|	-.066	|	-.068	|	-.062	|	-.058	|	-.073	|
|	Test Statistic	|		|	.067	|	.068	|	.062	|	.061	|	.073	|
|	Asymp. Sig. (2-tailed)	|		|	.000c	|	.000c	|	.000c	|	.000c	|	.000c	|
|	\*.Test distribution is Normal.	|		|		|		|		|		|		|
|	^.Calculated from data.	|		|		|		|		|		|		|
|	c.Lilliefors Sig. Correction.	|		|		|		|		|		|		|

### (b)

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
|	Normal Parametersa,b	|	Mean	|	50.0327	|	50.0298	|	3.9978	|	1.0043	|	.9998	|
|		|	Std. Deviation	|	28.86395	|	9.99737	|	1.99738	|	.99915	|	1.00365	|
|	Most Extreme Differences	|	Absolute	|	.058	|	.003	|	.128	|	.157	|	.160	|
|		|	Positive	|	.058	|	.003	|	.128	|	.133	|	.135	|
|		|	Negative	|	-.058	|	-.001	|	-.070	|	-.157	|	-.160	|
|	Test Statistic	|		|	.058	|	.003	|	.128	|	.157	|	.160	|
|	Asymp. Sig. (2-tailed)	|		|	.000c	|	.045c	|	.000c	|	.000c	|	.000c	|
|	a. Test distribution is Normal.	|		|		|		|		|		|		|
|	b. Calculated from data.	|		|		|		|		|		|		|
|	c. Lilliefors Significance Correction.	|		|		|		|		|		|		|


### (c)

### (d)

### (e)

### (f)

### Part 2 - Snakes and Ladders - Discrete Event Markov Chains and Monte Carlo Simulations

### Part 3 - Discrete Event Simulation - Queue Simulation

### Part 4 - Extra Features

### Part 5 - Final Report

### References
