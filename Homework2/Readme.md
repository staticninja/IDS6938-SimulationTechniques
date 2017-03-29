# Homework 2 : Snakes and Ladders (Discrete Simulation Assignment)
## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)

Using one of my extra days.

## **Part 1 - Emperical Tests of Randomness**

### (a)
<pre>The output of 5 random number generator (RNG) engines, using a uniform distribution for values between [0-100]:
<a href="https://github.com/staticninja/IDS6938-SimulationTechniques/blob/master/Homework2/images/RNG%20Output%20-%202.xlsx"> Excel File</a></pre>

#### Charts & Useful Statistics to analyse how uniform the random numbers are.
**Charts**

| &nbsp; | Mersene Twister 19937 (64 bit) - 1 | Mersene Twister 19937 (64 bit) - 2 | 
|----------|----------|----------|
|N = 250 | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/250MT1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/250MT2-Hist.svg" width="300px"> |
|N = 1,000 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/1kMT1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/1kMT2-Hist.svg" width="300px"> |
|N = 2,500 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/25MT1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/25MT2-Hist.svg" width="300px"> 

| &nbsp; | Default - 1 | Default - 2 | 
|----------|----------|----------|
|N = 250 | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/250Default1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/250Default2-Hist.svg" width="300px"> |
|N = 1,000 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/1kDefault1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/1kDefault2-Hist.svg" width="300px"> |
|N = 2,500 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/25Default1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/25Default2-Hist.svg" width="300px"> |

| &nbsp; | Knuth B - 1 | Knuth B - 2 | 
|----------|----------|----------|
|N = 250 | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/250Knuth1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/250Knuth2-Hist.svg" width="300px"> |
|N = 1,000 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/1kKnuth1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/1kKnuth2-Hist.svg" width="300px"> |
|N = 2,500 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/25Knuth1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/25Knuth2-Hist.svg" width="300px"> |

| &nbsp; | Ranlux 48 - 1 | Ranlux 48 - 2 | 
|----------|----------|----------|
|N = 250 | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/250Ranlux1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/250Ranlux2-Hist.svg" width="300px"> |
|N = 1,000 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/1kRanlux1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/1kRanlux2-Hist.svg" width="300px"> |
|N = 2,500 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/25Ranlux1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/25Ranlux2-Hist.svg" width="300px"> |

| &nbsp; | Sobol - 1 | Sobol - 2 | 
|----------|----------|----------|
|N = 250 | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/250Sobol1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/250Sobol2-Hist.svg" width="300px"> |
|N = 1,000 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/1kSobol1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/1kSobol2-Hist.svg" width="300px"> |
|N = 2,500 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/25Sobol1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/4ab775c7/Homework2/images/Histograms/25Sobol2-Hist.svg" width="300px"> |

<br>


**Statistics to analyze RNG outputs**
<pre>At this time I have not recieved any training on how to interpret or even correctly run these statistical analysis and feel that my attempt to "interpret" them would be unethical.</pre>
#### Chi-Square

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

#### Spearman's Rank Correlation

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
<br>

### (b)

<pre>When varying the number of values output from a RNG from 250, 1,000, and 2,500 the randomness seems to increase however, patterns start to emerge. Reference the Excel from (a).</pre>

### (c)
<pre>The output of the 5 different distributions in RNG can be found here:

<a href="https://github.com/staticninja/IDS6938-SimulationTechniques/blob/master/Homework2/images/DIST%20Output.xlsx">Excel File </a>

Mersene Twister 19937 (64 bit) was used as the fixed RNG for assessing distributions.
</pre>

#### Charts & Useful Statistics to analyse distributions.

**Charts**

| &nbsp; | Exponential - 1 | Exponential - 2 | 
|----------|----------|----------|
|N = 250 | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/250Exp1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/250Exp2-Hist.svg" width="300px"> |
|N = 1,000 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/1kExp1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/1kExp2-Hist.svg" width="300px"> |
|N = 2,500 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/25Exp1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/25Exp2-Hist.svg" width="300px"> |

| &nbsp; | Normal - 1 | Normal - 2 | 
|----------|----------|----------|
|N = 250 | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/250Normal1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/250Normal2-Hist.svg" width="300px"> |
|N = 1,000 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/1kNormal1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/1kNormal2-Hist.svg" width="300px"> |
|N = 2,500 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/25Normal1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/25Normal2-Hist.svg" width="300px"> |

| &nbsp; | Poisson - 1 | Poisson - 2 | 
|----------|----------|----------|
|N = 250 | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/250Poisson1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/250Poisson2-Hist.svg" width="300px"> |
|N = 1,000 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/1kPoisson1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/1kPoisson2-Hist.svg" width="300px"> |
|N = 2,500 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/25Poisson1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/25Poisson2-Hist.svg" width="300px"> |

| &nbsp; | Uniform - 1 | Uniform - 2 | 
|----------|----------|----------|
|N = 250 | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/250Uniform1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/250Uniform2-Hist.svg" width="300px"> |
|N = 1,000 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/1kUniform1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/1kUniform2-Hist.svg" width="300px"> |
|N = 2,500 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/25Uniform1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/25Uniform2-Hist.svg" width="300px"> |

| &nbsp; | Weibull - 1 | Weibull - 2 | 
|----------|----------|----------|
|N = 250 | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/250Weibull1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/250Weibull2-Hist.svg" width="300px"> |
|N = 1,000 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/1kWeibull1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/1kWeibull2-Hist.svg" width="300px"> |
|N = 2,500 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/25Weibull1-Hist.svg" width="300px"> |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/20c19320/Homework2/images/Histograms/25Weibull2-Hist.svg" width="300px"> |

<br>

**Statistics**
<pre>At this time I have not recieved any training on how to interpret or even correctly run these statistical analysis and feel that my attempt to "interpret" them would be unethical.</pre>
**Chi-Squared**

|	N = 1,000	|	Uniform1	|	Normal1	|	Poisson1	|	Exp1	|	Weibull1	|
|	-------------	|	-------------	|	-------------	|	-------------	|	-------------	|	-------------	|
|	**Chi-Square**	|	101.919(a)	|	2005.600(b)	|	13460.769(c)	|	17067.817(d)	|	16192.326(e)	|
|	**df**	|	99	|	99	|	99	|	99	|	99	|
|	**Asymp. Sig.**	|	.400	|	0.000	|	0.000	|	0.000	|	0.000	|

a. 0 cells (0.0%) have expected frequencies less than 5. The minimum expected cell frequency is 9.9.										
b. 0 cells (0.0%) have expected frequencies less than 5. The minimum expected cell frequency is 10.0.										
c. 0 cells (0.0%) have expected frequencies less than 5. The minimum expected cell frequency is 9.8.										
d. 100 cells (100.0%) have expected frequencies less than 5. The minimum expected cell frequency is 3.6.										
e. 100 cells (100.0%) have expected frequencies less than 5. The minimum expected cell frequency is 3.7.										

**Spearman's Rank Correlation**

|	N = 1,000	|		|	Uniform	|	Normal	|	Poisson	|	Exponental	|	Weibull	|
|	-------------	|	-------------	|	-------------	|	-------------	|	-------------	|	-------------	|	-------------	|
|	**Uniform**	|	Correlation Coefficient	|	1.000	|	-.014	|	.046	|	-.033	|	-.043	|
|		|	Sig. (1-tailed)	|		|	.329	|	.073	|	.150	|	.086	|
|		|	N	|	1000	|	1000	|	1000	|	1000	|	1000	|
|	**Normal**	|	Correlation Coefficient	|	-.014	|	1.000	|	-.042	|	.025	|	.028	|
|		|	Sig. (1-tailed)	|	.329	|		|	.090	|	.212	|	.192	|
|		|	N	|	1000	|	1000	|	1000	|	1000	|	1000	|
|	**Poisson**	|	Correlation Coefficient	|	.046	|	-.042	|	1.000	|	-.025	|	.051	|
|		|	Sig. (1-tailed)	|	.073	|	.090	|		|	.213	|	.053	|
|		|	N	|	1000	|	1000	|	1000	|	1000	|	1000	|
|	**Exponental**	|	Correlation Coefficient	|	-.033	|	.025	|	-.025	|	1.000	|	-.011	|
|		|	Sig. (1-tailed)	|	.150	|	.212	|	.213	|		|	.367	|
|		|	N	|	1000	|	1000	|	1000	|	1000	|	1000	|
|	**Weibull**	|	Correlation Coefficient	|	-.043	|	.028	|	.051	|	-.011	|	1.000	|
|		|	Sig. (1-tailed)	|	.086	|	.192	|	.053	|	.367	|		|
|		|	N	|	1000	|	1000	|	1000	|	1000	|	1000	|

### (d)

**Random Number Engines Unit Squares & Circles**

|&nbsp; | Default Random Engine | Kunth-B | Ranlux 48 | Mersene Twister 19937 (64-bit) | Sobel |
|----------|----------|----------|----------|----------|----------|
|n = 250 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/Default_250.svg" width="300px">|<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/Knuth_250.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/240ae4ce/Homework2/images/Ranlux_250.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/MT_250.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/bfca0581/Homework2/images/Sobol_250Scrub.svg" width="300px"> | 
| n = 1,000 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/Default_1k.svg" width="300px">|<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/Knuth_1k.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/Ranlux_1k.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/MT_1k.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/bfca0581/Homework2/images/Sobol_1kScrub.svg" width="300px"> |
| n = 2,500 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/Default_2.5k.svg" width="300px">|<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/Knuth_2.5k.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/Ranlux_2.5k.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/MT_2.5k.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/bfca0581/Homework2/images/Sobol_2.5kScrub.svg" width="300px"> |
| n = 1,000 |<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/ffb6544f/Homework2/images/Default_PoleScrub.svg" width="300px">|<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/Knuth_Pole.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/Ranlux_Pole.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/210d580a/Homework2/images/MT_Pole.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/bfca0581/Homework2/images/Sobol_poleScrub.svg" width="300px"> |

### (e)

**Distributions Unit Squares & Circles**

|&nbsp; | Uniform | Normal | Poisson | Exponent | Weibull|
|----------|----------|----------|----------|----------|----------|
|n = 250 | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b6c658a8/Homework2/images/Uniform_250.svg" width="300px">| <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b6c658a8/Homework2/images/Normal_250.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b6c658a8/Homework2/images/Poisson_250.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b6c658a8/Homework2/images/Exp_250.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b6c658a8/Homework2/images/Weibull_250.svg" width="300px"> | 
| n = 1,000 | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b6c658a8/Homework2/images/Uniform_1000.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b6c658a8/Homework2/images/Normal_1000.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b6c658a8/Homework2/images/Poisson_1000.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b6c658a8/Homework2/images/Exp_1000.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b6c658a8/Homework2/images/Weibull_1000.svg" width="300px"> |
| n = 2,500 | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b6c658a8/Homework2/images/Uniform_2500.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b6c658a8/Homework2/images/Normal_2500.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b6c658a8/Homework2/images/Poisson_2500.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b6c658a8/Homework2/images/Exp_2500.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b6c658a8/Homework2/images/Weibull_2500.svg" width="300px"> |
| n = 1,000  | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b6c658a8/Homework2/images/Uniform_Pole.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b6c658a8/Homework2/images/Normal_Pole.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b6c658a8/Homework2/images/Poisson_Pole.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b6c658a8/Homework2/images/Exp_Pole.svg" width="300px"> | <img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b6c658a8/Homework2/images/Weibull_Pole.svg" width="300px"> |

### (f)

<pre>
Unit circle representations can be found in their respective sections (d) & (e).
</pre>

## Part 2 - Snakes and Ladders - Discrete Event Markov Chains and Monte Carlo Simulations

### (a)

**Null State Transition Matrix**<br>
<pre>
Code to generate all but the last six rows of the Null State Transition Matrix:

<code>for (int i = 0; i &lt; TransitionMatrix.rows() - 6; i++)
    	{
    		TransitionMatrix(i, i + 1) = prob;
    		TransitionMatrix(i, i + 2) = prob;
    		TransitionMatrix(i, i + 3) = prob;
    		TransitionMatrix(i, i + 4) = prob;
    		TransitionMatrix(i, i + 5) = prob;
    		TransitionMatrix(i, i + 6) = prob;
    	}
  </code>
</pre>
<pre>I created a for loop to dynamically adjust the last 6 rows of the transition matrix so if the size variable was changed it would adjust accordingly:

<code>
    for (int j = 0; j &lt; TransitionMatrix.rows(); j++)
    	{
    		if (j == TransitionMatrix.rows() - 6)
    		{
    			TransitionMatrix(j, TransitionMatrix.rows() - 1) = prob * 2;
    			TransitionMatrix(j, TransitionMatrix.rows() - 2) = prob;
    			TransitionMatrix(j, TransitionMatrix.rows() - 3) = prob;
    			TransitionMatrix(j, TransitionMatrix.rows() - 4) = prob;
    			TransitionMatrix(j, TransitionMatrix.rows() - 5) = prob;
    		}
    		if (j == TransitionMatrix.rows() - 5)
    		{
    			TransitionMatrix(j, TransitionMatrix.rows() - 1) = prob * 3;
    			TransitionMatrix(j, TransitionMatrix.rows() - 2) = prob;
    			TransitionMatrix(j, TransitionMatrix.rows() - 3) = prob;
    			TransitionMatrix(j, TransitionMatrix.rows() - 4) = prob;
    		}
    		if (j == TransitionMatrix.rows() - 4)
    		{
    			TransitionMatrix(j, TransitionMatrix.rows() - 1) = prob * 4;
    			TransitionMatrix(j, TransitionMatrix.rows() - 2) = prob;
    			TransitionMatrix(j, TransitionMatrix.rows() - 3) = prob;
    		}
    		if (j == TransitionMatrix.rows() - 3)
    		{
    			TransitionMatrix(j, TransitionMatrix.rows() - 1) = prob * 5;
    			TransitionMatrix(j, TransitionMatrix.rows() - 2) = prob;
    		}
    		if (j == TransitionMatrix.rows() - 2)
    		{
    			TransitionMatrix(j, TransitionMatrix.rows() - 1) = prob * 6;
    		}
    		if (j == TransitionMatrix.rows() - 1)
    		{
    			TransitionMatrix(j, TransitionMatrix.rows() - 1) = prob * 6;
    		}
    	}
	</code>
	</pre>
	
### (b)
Simulate and analyze the results of the null state game.

#### DTMC

#### Monte Carlo

<pre>Transition Matrix: In a simulation of 500 games the modal number of moves is 28.
Snakes & Ladders: In a simulation of 500 gmaes the modal numer of muves is 18.
</pre>

### (c)
Simulate and analyze the results of Snakes and Ladders game.

#### DTMC

#### Monte Carlo

### (d)

## Part 3 - Discrete Event Simulation - Queue Simulation

### (a)

Setup MM1 queue scenario to match this example:
<img src="https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/b6c658a8/Homework2/images/queue.png">
<pre>
	   MM1_Queue    checkin;
	   checkin.set_file_names("ID_Check_log.txt", "ID_Check_wait.txt", "ID_Check_service.txt");
	   checkin.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   checkin.set_mu(53);
	   checkin.initialize();
	   checkin.set_seed(1, rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())

	   MM1_Queue    Security1;
	   Security1.set_file_names("Security1_log.txt", "Security1_wait.txt", "Security1_service.txt");
	   Security1.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   Security1.set_mu(20);
	   Security1.autogenerate_new_arrivals(false);
	   Security1.initialize();
	   Security1.set_seed(1, rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())

	   MM1_Queue    Security2;
	   Security2.set_file_names("Security2_log.txt", "Security2_wait.txt", "Security2_service.txt");
	   Security2.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   Security2.set_mu(20);
	   Security2.autogenerate_new_arrivals(false);
	   Security2.initialize();
	   Security2.set_seed(1, rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())

	   MM1_Queue    Security3;
	   Security3.set_file_names("Security3_log.txt", "Security3_wait.txt", "Security3_service.txt");
	   Security3.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   Security3.set_mu(20);
	   Security3.autogenerate_new_arrivals(false);
	   Security3.initialize();
	   Security3.set_seed(1, rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())

	   MM1_Queue    Boarding;
	   Boarding.set_file_names("Boarding_log.txt", "Boarding_wait.txt", "Boarding_service.txt");
	   Boarding.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   Boarding.set_mu(80);
	   Boarding.initialize();
	   Boarding.set_seed(1, rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())
	   </pre>
	   
### (b)

Add a check to the process
<pre>
 	   !checkin.is_within_error_range(0.002) ||
	   !Security1.is_within_error_range(0.002) ||
	   !Security2.is_within_error_range(0.002) ||
	   !Security3.is_within_error_range(0.002) </pre>
Process next event
<pre>
	   Customer cust  = checkin.process_next_event();    // =  TODO: process next event;
	   Customer cust2  = Security1.process_next_event();   // =  TODO: process next event;
	   Customer cust3  = Security2.process_next_event();   // =  TODO: process next event;
	   Customer cust4  = Security3.process_next_event();   // =  TODO: process next event;
	   Customer cust5 = Boarding.process_next_event();   // =  TODO: process next event;
</pre>
Add external arrival where indicatred
<pre>
				Security1.add_external_arrival();
				Security2.add_external_arrival();
				Security3.add_external_arrival();
				Boarding.add_external_arrival();
</pre>

### (c)
Calculate Expected Results
<pre>
      expected_server_utilization_ = lambda_/mu_;
      expected_idle_prob_ = 1 - expected_server_utilization_;
      expected_queue_length_ = (expected_server_utilization_*expected_server_utilization_)/(1-expected_server_utilization_);
      expected_number_customers_ = expected_server_utilization_/(1-expected_server_utilization_);
      expected_waiting_time_ = expected_server_utilization_/(mu_-lambda_);
      expected_response_time_ = 1/(mu_-lambda_);
      </pre>
	  
### (d)
### (e)
### Part 4 - Extra Features
 * (10 Points) Add 2D visualization to Anylogic for Part 3.
 * (10 Points) Add 3D visualization to Anylogic for Part3.
 <img src="https://github.com/staticninja/IDS6938-SimulationTechniques/blob/master/Homework2/images/AnyLogic%20Graphics.PNG">
 
### Part 5 - Final Report
<pre>
You're reading it.
</pre>

### References
<pre> None this time </pre>