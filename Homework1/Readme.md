#Homework 1 : The Jello Cube (Continuous Simulation Assignment)
## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)


###<strong>Part 1:</strong>
<p><strong>Step (a)</strong><br>
<pre>y(x) = e<sup>x/2</sup> * sin(5x)</pre></p>
<p><strong>Step (b)</strong><br>
Function to return <i>df</i>
<pre>double df(double x, double y)
{
	return y - (1.0 / 2.0)*exp(x / 2.0)*sin(5.0 * x) + 5 * exp(x / 2.0)*cos(5.0 * x);
}
</pre>
Function to return <i>Exact</i>
<pre>
double exact(double x)
{
	return exp(x / 2.0)*sin(5.0 * x);
}
</pre></p>
<p><strong>Step (c)</strong></p>
Graph of RK1, RK2, RK4, and the Exact Solutions

|      RK1      |      RK2      |      RK4      |     Exact     |
| ------------- | ------------- | ------------- | ------------- |
|   0           |   0           |   0           |   0           |
|   0.5         |   0.509036927	|	0.50401476	|	0.504006212	|
|   0.98608828	|	0.941891755	|	0.929983374	|	0.929969261	|
|	1.336761843	|	1.178280127	|	1.158938591	|	1.158923832	|
|	1.453584287	|	1.136380907	|	1.110627992	|	1.110618385	|
|	1.28927035	|	0.798159298	|	0.768452619	|	0.768453444	|
|	0.86543033	|	0.220768035	|	0.190477469	|	0.190492086	|
|	0.274273713	|  -0.470402004	|  -0.49781389	|  -0.497785095	|
|  -0.3378573	|  -1.107144704	|  -1.129056656	|  -1.129016654	|
|  -0.80275305	|  -1.517667616	|  -1.533117725	|  -1.533072395	|
|  -0.97167155	|  -1.570878628	|  -1.581041974	|  -1.580998849	|
|  -0.75594882	|  -1.214747006	|  -1.222913458	|  -1.222879899	|
|  -0.15624769	|  -0.498141061	|  -0.509147006	|  -0.509128232	|
|	0.728356107	|	0.431273571	|	0.412068581	|	0.41207112	|
|	1.715934898	|	1.355046339	|	1.323019094	|	1.323008542	|
|	2.580464313	|	2.033306318	|	1.985762151	|	1.985745966	|
|	3.106136933	|	2.264888984	|	2.20186874	|	2.201857271	|
|	3.144749623	|	1.943723238	|	1.868173695	|	1.868177859	|
|	2.661568066	|	1.0964239	|	1.013619327	|	1.013647908	|
|	1.756533063	|  -0.110661518	|  -0.1943762	|  -0.194318978	|
|	0.65270348	|  -1.399996434	|  -1.478886739	|  -1.4788027	|
|  -0.34850248	|  -2.443310353	|  -2.513966496	|  -2.513863572	|
|  -0.93711886	|  -2.941602204	|  -3.004245902	|  -3.004136603	|
|  -0.87397615	|  -2.70594543	|  -2.764948334	|  -2.764846851	|
|  -0.0599466	|  -1.71816828	|  -1.781566264	|  -1.781484825	|
|	1.423979884	|  -0.153514693	|  -0.231540836	|  -0.231486167	|
|	3.319281279	|	1.644605198	|	1.54168834	|	1.541717508	|
|	5.238969258	|	3.236248676	|	3.100524943	|	3.100538568	|
|	6.755270333	|	4.189210793	|	4.01709566	|	4.017110916	|
|	7.507190201	|	4.192252154	|	3.985526889	|	3.985564681	|
|	7.302089591	|	3.148785464	|	2.914307734	|	2.914387906	|
|	6.184236647	|	1.224605964	|	0.972629052	|	0.972765385	|
|	4.449044884	|  -1.167577779	|  -1.426190757	|  -1.425994463	|
|	2.593589867	|  -3.449436793	|  -3.706500293	|  -3.706251919	|
|	1.209577795	|  -5.009923054	|  -5.262921367	|  -5.262639293	|
|	0.840552721	|  -5.360649903	|  -5.614631006	|  -5.614340022	|
|	1.836719894	|  -4.275713547	|  -4.543483006	|  -4.543208093	|
|	4.244893938	|  -1.877962749	|  -2.178355567	|  -2.178114923	|
|	7.765893459	|	1.356347703	|	1.001862248	|	1.002063203	|
|	11.797567	|	4.68431418	|	4.255978576	|	4.256150562	|
|	15.56128357	|	7.261608412	|	6.745634215	|	6.745803673	|
|	18.28779237	|	8.351461123	|	7.743070647	|	7.743275262	|
|	19.42038688	|	7.527669226	|	6.8319912	|	6.832272103	|
|	18.78438686	|	4.818214028	|	4.048561713	|	4.048954056	|
|	16.67534928	|	0.745902688	|  -0.080407378	|  -0.079883186	|
|	13.83454839	|  -3.755363171	|  -4.622839038	|  -4.62218308	|
|	11.30627052	|  -7.53999892	|  -8.441122943	|  -8.440356708	|
|	10.20162853	|  -9.526142511	|  -10.46629701	|  -10.4654587	|
|	11.42050818	|  -8.98343453	|  -9.983215155	|  -9.982350011	|
|	15.3995765	|  -5.75964435	|  -6.853708459	|  -6.852856091	|
|	21.95465336	|  -0.38078175	|  -1.613192731	|  -1.612374396	|
|	30.26839856	|	6.014645055	|	4.597706732	|	4.598497604	|
|	39.04184528	|	11.90757696	|	10.26608596	|	10.26688721	|
|	46.78766159	|	15.75373022	|	13.86098924	|	13.86186593	|
|	52.20384861	|	16.38289019	|	14.22958423	|	14.23061724	|
|	54.53922906	|	13.34297777	|	10.93668465	|	10.93795441	|
|	53.8548974	|	7.093621803	|	4.453381201	|	4.454949997	|
|	51.10278291	|  -1.016917323	|  -3.870136268	|  -3.868238693	|
|	47.98174569	|  -9.00825224	|  -12.06319514	|  -12.06097868	|
|	46.58531604	|  -14.71564969	|  -17.98179125	|  -17.97930254	|
|	48.91085718	|  -16.33276767	|  -19.84783646	|  -19.84514567	|
|	56.34331178	|  -12.91820728	|  -16.74997531	|  -16.74715483	|
|	69.24521405	|  -4.730353493	|  -8.971708122	|  -8.968807967	|
|	86.770879	|	6.71462731	|	1.956659048	|	1.959633321	|
|	106.976805	|	18.90583913	|	13.52479088	|	13.52789171	|
|	127.2308958	|	28.88713582	|	22.79198022	|	22.79531867	|
|	144.845701	|	33.9802905	|	27.1065171	|	27.11024922	|
|	157.7947748	|	32.51209943	|	24.82557044	|	24.82987139	|
|	165.3348427	|	24.35679009	|	15.84845493	|	15.85348654	|
|	168.3623304	|	11.13329012	|	1.804998656	|	1.810878113	|
|	169.3838706	|  -4.030216515	|  -14.18624083	|  -14.17946262	|
|	172.0681429	|  -17.14871549	|  -28.17228344	|  -28.16462716	|
|	180.4518537	|  -24.32396089	|  -36.30581142	|  -36.29735499	|
|	197.9702842	|  -22.76449392	|  -35.85664997	|  -35.84749611	|
|	226.5464061	|  -11.62486987	|  -26.03915079	|  -26.02938275	|
|	265.9819834	|	7.573163658	|  -8.420983343	|  -8.410618979	|
|	313.8412016	|	31.09105003	|	13.23698217	|	13.24802651	|
|	365.909382	|	53.7164146	|	33.72789984	|	33.73982544	|
|	417.1685434	|	69.96783884	|	47.60073669	|	47.61385252	|
|	463.0911121	|	75.49676734	|	50.551947	|	50.56663391	|
|	500.9495217	|	68.3428104	|	40.66514418	|	40.68180013	|
|	530.8035916	|	49.70067888	|	19.16044889	|	19.17942782	|
|	555.8758684	|	23.94803368	|  -9.592897427	|  -9.571337455	|
|	582.1538542	|  -2.150655369	|  -38.88141649	|  -38.85714093	|
|	617.2422193	|  -20.94381739	|  -61.14646828	|  -61.11945935	|
|	668.6856376	|  -25.78002003	|  -69.86074193	|  -69.83105503	|
|	742.143842	|  -12.83269433	|  -61.33393679	|  -61.30162694	|
|	839.8791755	|	17.61878775	|  -35.97067969	|  -35.93571326	|
|	959.984196	|	60.84206991	|	1.404009713	|	1.441837177	|
|	1096.629577	|	108.4273937	|	42.33439851	|	42.37551737	|
|	1241.37688	|	150.1023432	|	76.55081616	|	76.59589429	|
|	1385.328763	|	176.2233273	|	94.44915487	|	94.49905918	|
|	1521.647688	|	180.3673069	|	89.65808285	|	89.71379662	|
|	1647.829303	|	161.3606021	|	61.03567726	|	61.09819136	|
|	1767.116099	|	124.1582495	|	13.51631062	|	13.58651544	|
|	1888.596144	|	79.22459545	|  -42.53333378	|  -42.45472598	|
|	2025.825999	|	40.4187988	|  -93.43846738	|  -93.35094466	|
|	2194.184043	|	21.77807556	|  -125.4239703	|  -125.3271744	|
|	2407.512568	|	33.91946812	|  -128.1856199	|  -128.0792336	|
|	2674.851039	|	80.95594681	|  -97.93441991	|  -97.81800842	|
|	2998.124017	|	158.7831645	|  -39.0670402	|  -38.93988091	|
|				|				|				|

![](https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/929c25f0/Homework1/images/PartC.svg)

<p><strong>Step (d)</strong></p>
Graph of error percentages of RK1, RK2, & RK4
![](https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/a8f5d986/Homework1/images/PartD.svg)

<p><strong>Step (e)</strong></p>
Graph of varying step size and error

Step	|	0.5	|	0.5 Error	|	1.0	|	1.0 Error	|	2.0	|	2.0 Error	|	Exact
------------- 	|	------------- 	|	------------- 	|	------------- 	|	------------- 	|	------------- 	|	------------- 	|	------------- 
0.00	|	0.00	|	0.00	|	0.00	|	0.00	|	0.00	|	0.00	|	0.00
0.50	|	0.76	|	0.01	|		|		|		|		|	0.77
1.00	|	-1.62	|	-0.02	|	-3.18	|	-1.01	|		|		|	-1.58
1.50	|	1.99	|	0.00	|		|		|		|		|	1.99
2.00	|	-1.56	|	-0.05	|	-6.04	|	-3.09	|	18.54	|	-13.54	|	-1.48
2.50	|	-0.29	|	-0.24	|		|		|		|		|	-0.23
3.00	|	2.81	|	0.04	|	-5.35	|	2.83	|		|		|	2.91
3.50	|	-5.89	|	-0.05	|		|		|		|		|	-5.61
4.00	|	6.53	|	0.03	|	-11.12	|	2.65	|	47.20	|	6.00	|	6.75
4.50	|	-5.28	|	-0.14	|		|		|		|		|	-4.62
5.00	|	-2.46	|	-0.53	|	-56.93	|	-34.31	|		|		|	-1.61
5.50	|	9.54	|	0.13	|		|		|		|		|	10.94
6.00	|	-22.55	|	-0.14	|	-188.39	|	-8.49	|	570.16	|	-29.73	|	-19.85
6.50	|	19.15	|	0.16	|		|		|		|		|	22.80
7.00	|	-21.21	|	-0.50	|	-469.35	|	-32.10	|		|		|	-14.18
7.50	|	-19.24	|	-1.29	|		|		|		|		|	-8.41
8.00	|	22.95	|	0.44	|	-1139.89	|	29.02	|	3507.78	|	85.22	|	40.68
8.50	|	-100.56	|	-0.44	|		|		|		|		|	-69.83
9.00	|	28.82	|	0.62	|	-3075.56	|	41.15	|		|		|	76.60
9.50	|	-124.67	|	-1.94	|		|		|		|		|	-42.45
10.00	|	-172.09	|	-3.42	|	-8675.56	|	-221.79	|	24987.81	|	-642.70	|	-38.94

![](https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/0afd7dfa/Homework1/images/V5.svg)

![](https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/0afd7dfa/Homework1/images/V1.svg)

![](https://cdn.rawgit.com/staticninja/IDS6938-SimulationTechniques/0afd7dfa/Homework1/images/V2.svg)

<p><strong>Step (f)</strong></p>
Analyze your results:
(1) Describe how varying the integration method changes the accuracy.
<pre>Differences in Euler vs. Midpoint vs. RK4 are evident. When using Euler integration the accuracy begins to suffer rapidly and the cube shatters. Midpoint integration appears to be slower than RK4 but as reliable. RK4 is more accurate and the cube retains its structure. </pre>
(2) What happens as you increase the x value to the accuracy.
<pre>Answer</pre>
(3) How does varying the step size effect the accuracy.
<pre>Answer</pre>
(4) Which method is the most accurate and why (in particular explain what is taken to account in the solution)
<pre>RK4 is the most accurate as it includes Euler's method and RK</pre>
###Part 2
<pre>Part 2 can be found in the .cpp files.</pre>
###Part 3
<p>What is the effect of the K<sub>s</sub> and K<sub>d</sub> parameters on the jello?</p>
<pre>K<sub>s</sub> represents spring stiffness constant and K<sub>d</sub> is the damping constant. Stiffness is the propensity of the connected particles to retain their original form, lowering the K<sub>s</sub> value allows for more deformation. Damping is how rapidly the spring will return to its original position. </pre>
<p>What are the benefits and the drawbacks of the collision system used here? What different ways in which it could be improved?</p>
<pre>Our collision system uses displacement to the interloping object to return it to the viable surface. A "better" solution would be to solve for the instant of contact with the surface and and rewind the simulation to the time of the collision.</pre>
<p>What are some example systems you could model with Mass-spring simulation. Explain how you would construct the model.</p>
<pre>Simulating hair can also be done using mass-spring simulations. To construct the model you would use a function to create the object of the hair and then at predetermined length "segment" the hair and apply springs at those points to create natural hair moments.</pre>
<p>How would you model and simulate water (in terms of a continuous simulation)?</p>
<pre>There are multiple ways of simulating water. Video games of yesteryear used animated 2D sprites and moving texture objects. Simulating water, in a system that isn't designed to evaluate the water, could be modeled in a polygon textured plane with multiple points of flexation that would be controlled via a mass-spring system.</pre>
###Part 4
<pre>This Readme.md is Part 4</pre>

| Working Jello Cube  | Ks Jello Breaks | Kd Jello Breaks |
| ------------- | ------------- | -------------|
| ![](images/Jello_Final.gif?raw=true)  | ![](images/Ks_Collapse.gif?raw=true) | ![](images/Kd_Shatter.gif?raw=true) |