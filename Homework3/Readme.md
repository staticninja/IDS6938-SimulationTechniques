# Homework 3 : Agent based Simulation Assignment 

## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)

[University of Central Florida](http://www.ist.ucf.edu/grad/)
This is the framework for homework #3. 

The assignment is due: **Monday, April  24 at 11:59PM (EST)**

## Using 1 free exention day given by the instructor + last 2 from sylabus.

### Part 1: Behaviors

**(a) - 10 points** : Compute derivative vector given input and state vectors. Implement the function *SIMAgent::FindDeriv()*. This function sets derive vector to appropriate values after being called.

You will need to set deriv[0], deriv[1], deriv[2], deriv[3]. Compute derivative vector given input and state vectors. This function sets derive vector to appropriate values after being called. 
<pre>
deriv[0] = state[0]; // velocity of the agent in local body coordinates
deriv[1] = state[3]; //angular velcotiy of the agent in world coordinates
deriv[2] = input[0] / Mass; //force in local body coordinates divided by mass
deriv[3] = input[1] / Inertia; //torque in local body coordinates divided by the inertia
</pre>


You also must implement *SIMAgent::InitValues()*: Try to figure out appropriate values for control and behavior settings. You need to find out appropriate values for: 
<pre>
SIMAgent::Kv0 = 10
SIMAgent::Kp1 = 400
SIMAgent::Kv1 = 32
SIMAgent::KArrival = 0.05 
SIMAgent::KDeparture = 15
SIMAgent::KNoise = 10
SIMAgent::KWander = 8
SIMAgent::KAvoid = 80
SIMAgent::TAvoid = 5
SIMAgent::RNeighborhood = 100
SIMAgent::KSeparate = 200
SIMAgent::KAlign 20
SIMAgent::KCohesion 0.05
</pre>

***
**(b) - 20 points**: In this part of the assignment you will need to implement 6 types of individual behaviors and 5 types of group behaviors. Create the following behaviors through appropriate computation of V<sub> d</sub>  and θ<sub>d</sub>  commands:
* Seek
```cpp
vec2 tmp;
vec2 Vd = goal - GPos;
thetad = atan2(Vd[1], Vd[0]);
vd = MaxVelocity;
tmp = vec2(cos(thetad) * vd, sin(thetad) * vd);
return tmp;
```
    
* Flee
```cpp
	vec2 tmp;
	vec2 Vd = goal - GPos;
	thetad = atan2(Vd[1], Vd[0]);
	thetad += M_PI;
	vd = MaxVelocity;
	tmp = vec2(cos(thetad)* vd, sin(thetad)* vd);
	return tmp;
```

* Arrival
```cpp
	vec2 tmp;
	vec2 Vd = goal - GPos; //find difference vector
	double dist = Vd.Length(); //determin the length of the difference
	vd = Vd.Length() * KArrival;
	thetad = atan2(Vd[1], Vd[0]);
	double close = (vd / radius) * KArrival;
	if (dist > 0)
	{
		tmp = vec2(cos(thetad)*vd, sin(thetad)*vd);
		return tmp;
	}
	tmp = vec2(cos(thetad)*close, sin(thetad)*close);
	return tmp;
```
    
* Departure
```cpp
	vec2 tmp;
	vec2 Vd = goal - GPos;
	double dist = Vd.Length();
	vd = Vd.Length() * KDeparture;
	Vd.Normalize();
	Truncate(vd, 0, MaxVelocity);
	thetad = atan2(Vd[1], Vd[0]);
	thetad += M_PI;
	double vn = MaxVelocity * (vd / radius);
	if (dist > radius)
	{
		return vec2(cos(thetad)*vd, sin(thetad)*vd);
	}
	return vec2(cos(thetad)*vn, sin(thetad)*vn);
```
    
* Wander
```cpp
	vec2 tmp;
	float angle = float(rand() % 360) / 180.0 * M_PI; //taken from SimAgent::SimAgent
	vec2 Vd = goal - GPos;
	vd = Vd.Length() * KWander;
	thetad = angle;
	tmp = vec2(vd*cos(thetad)*KNoise, vd*sin(thetad)*KNoise)*KWander;
	return tmp;
```

* Obstacle Avoidance
```cpp
	vec2 tmp;
	vec2 sight1; //vector to monitor the farthest distance
	vec2 sight2; //vector to monitor closer
	vec2 obj;
	tmp = goal - GPos; //where the agent is trying to go
	thetad = atan2(tmp[1], tmp[0]);
	vd = MaxVelocity; //base max velocity as it is in seek
	sight1 = GPos + v0.Normalize() * KAvoid;//longer sight range
	sight2 = GPos + v0.Normalize() * KAvoid * 0.5;//shorter sight range
	for (int i = 0; i < env->obstaclesNum; i++)
	{
		obj[0] = env->obstacles[i][0]; //object x coord
		obj[1] = env->obstacles[i][1]; //object y coord
		float Dsight1 = (obj - sight1).Length(); //distance from sight1 and the object
		float Dsight2 = (obj - sight2).Length(); //distance from sight2 and the object
		float r = env->obstacles[i][2]; //radius of the object
		if (Dsight1 <= r + KAvoid || Dsight2 <= r + KAvoid) //if distance from sight1 or sight2 and the object is less then the object radius + Kavoid
		{
			thetad = thetad + TAvoid;
			tmp = vec2(cos(thetad) * vd, sin(thetad) * vd);
		}
	}
	tmp = vec2(cos(thetad) * vd, sin(thetad) * vd);
	return tmp;
```

***
**(c) - 20 points**: Implement the functions for the following group behaviors: 
* Seperation
```cpp
vec2 tmp;
	vec2 sum = vec2(0, 0);
	vec2 Vdiff = vec2(0, 0);
	int count = 0; //tracking the number of BOIDS in the simulation
	for (int i = 0; i < agents.size(); i++) //loop to evaluate the all the agents positions
	{
		Vdiff = GPos - agents[i]->GPos; //determine the distance from self to another in vector form
		double dist = Vdiff.Length(); //the distance between the two vectors (i.e. how far from me to agents[i])
		if ((dist < RNeighborhood) && (dist > 0)) //is the agent in RNeighborhood and with a distance greater than zero.
		{
			sum += Vdiff; //formule on webcourses Sum(nEN) (goal-position)/|(goal-position) * constant
			count++;
		}
	}
	if (count > 0)
	{
		tmp = sum.Normalize(); //this is the second half of the Sum(nEN) formule.
		vd = tmp.Length() * KSeparate; //magnitude * constant
		thetad = atan2(tmp[1], tmp[0]);
		thetad += M_PI; //reverse the direction of the angle to move away.
		tmp = vec2(cos(thetad)*vd, sin(thetad)*vd);
	}
	return tmp;
```
    
* Cohesion 
```cpp
//basically the same thing as alignment with a modification to use location
	vec2 tmp;
	vec2 sum = vec2(0, 0);
	int count = 0; //tracking the number of BOIDS in the simulation
	for (int i = 0; i < agents.size(); i++) //loop to evaluate the all the agents positions
	{
		vec2 Vdiff = GPos - agents[i]->GPos; //determine the distance from self to another in vector form
		double dist = Vdiff.Length();
		//distance between two points = squrt (x2-x1)^2 + (y2-y1)^2. dist = vector subtraction of 1 & 2.
		if ((dist < RNeighborhood*2) && (dist > 0))
		{
			sum += Vdiff;
			count++;
		}
	}
	if (count > 0)
	{
		vec2 mean = (sum /count);
		thetad = atan2(mean[1], mean[0]);
		vd = mean.Length() * KCohesion;
		tmp = vec2(cos(thetad)*vd, sin(thetad)*vd);
		return tmp;
```

* Alignment 
```cpp
	vec2 tmp;
	vec2 sum = vec2(0, 0);
	vec2 Vd = vec2(0, 0);
	int count = 0; //tracking the number of BOIDS in the simulation
	for (int i = 0; i < agents.size(); i++) //loop to evaluate the all the agents positions
	{
		vec2 vel = agents[i]->GPos - GPos; //determine the difference in velocity from the goal (agents[i]) and self (GPos)
		if ((vel.Length() < RNeighborhood)) //distance between two points = squrt (x2-x1)^2 + (y2-y1)^2. dist = vector subtraction of 1 & 2.
		{
			sum += agents[i]->v0.Normalize(); //add normalized velocity
			count++; //count the number of boids checked
		}
	}
	Vd = goal - GPos + sum; //Target velocity minus own-current velocity plus the sum of all other agents total normalized velocity.
	thetad = atan2(Vd[1], Vd[0]);
	vd = Vd.Length() * KAlign;
	Truncate(vd, 0, MaxVelocity);
	tmp = vec2(cos(thetad)*vd, sin(thetad)*vd);
	return tmp;
```

* Flocking
```cpp
	//derived from webcourses
	vec2 tmp;
	vec2 sep = Separation();
	vec2 align = Alignment();
	vec2 coh = Cohesion();
	vec2 vflock = sep * KSeparate + align * KAlign + coh * KCohesion;
	tmp = vflock;
	return tmp;
```

* Leader Following
```cpp
	vec2 tmp;
	if (this == SIMAgent::agents[0]) // taken from framwork code from the display function
	{
		vec2 Lpos = SIMAgent::agents[0]->GPos;
		vec2 seek = Seek();
	}
	else
	{
		//derived from webcourses
		goal = agents[0]->GPos;
		vec2 separation = Separation();
		vec2 arrival = Arrival();
		return tmp;
```

# Part 2 - Simulating a simple pedestrian flow
***
**(a) - 0 points**: Follow the Anylogic example for the [Subway Entrance example](https://help.anylogic.com/index.jsp?topic=/com.xj.anylogic.help/html/_PL/tutorial/Subway_Entrance.html). Create the appropriate [boundaries and walls](https://help.anylogic.com/index.jsp?topic=/com.xj.anylogic.help/html/markup/Wall.html), and the display ther pedestrian density map, [statistics](https://help.anylogic.com/index.jsp?nav=/4_1_5), [2D and 3D animations](https://help.anylogic.com/index.jsp?topic=/com.xj.anylogic.help/html/_PL/reference/Animation.html).

![](https://github.com/staticninja/IDS6938-SimulationTechniques/blob/master/Homework3/images/Subway.mp4.gif)


***
**(b) - 20 points**: Create a maze. Generate the pdm, stats, and animations like before. Vary [parameters in your agents](https://help.anylogic.com/index.jsp?topic=/com.xj.anylogic.help/html/_PL/reference/Attributes.html) to give them different behaviors and show the pedistrians change how they navigate the maze.

* **Maze - Default Settings**

![](https://github.com/staticninja/IDS6938-SimulationTechniques/blob/master/Homework3/images/Maze%20Default.gif)


* **Maze - Increased Right Turn Errors**

![](https://github.com/staticninja/IDS6938-SimulationTechniques/blob/master/Homework3/images/Maze%20RT%20Error.gif)

***
**(c) - 30 points**: Model and analyze a building (or floor/outdoor space/stadium) on campus. (There is help on piazza how to find rough building plans - we expect something plausible). Create a senario: evacuation, daily office routine, special event, normal egress.... etc., and model and design your own experiment to determine if the building design suits the needs of its users. Start with photographs of your site, describe your site, describe your senario and hypothesis. Then use an agent-based pedistrian simulation to visualize your experiment's results.

* **Photographs of Building Interior**<br>
Photos are labeled from where they were taken=.

	* Front Door 1<br>
![](https://github.com/staticninja/IDS6938-SimulationTechniques/blob/master/Homework3/images/frontdoor1.PNG)
	* Front Door 2<br>
![](https://github.com/staticninja/IDS6938-SimulationTechniques/blob/master/Homework3/images/frontdoor2.PNG)
	* Side Door 1<br>
![](https://github.com/staticninja/IDS6938-SimulationTechniques/blob/master/Homework3/images/sidedoor1.PNG)
	* Side Door 2<br>
![](https://github.com/staticninja/IDS6938-SimulationTechniques/blob/master/Homework3/images/sidedoor2.PNG)
	* Big Classroom<br>
![](https://github.com/staticninja/IDS6938-SimulationTechniques/blob/master/Homework3/images/bigclassroom.PNG)
	* Back Door 1<br>
![](https://github.com/staticninja/IDS6938-SimulationTechniques/blob/master/Homework3/images/backdoor1.PNG)
	* Back Door 2<br>
![](https://github.com/staticninja/IDS6938-SimulationTechniques/blob/master/Homework3/images/backdoor2.PNG)

* **Description of Site**

<p>
The selected site is the University of Central Florida's Psychology department building. It is located at 4111 Pictor Ln. Orlando Florida 32816. It is a 10 year old building with 3 accessable floors. The first floor of the building has 6 primary access points: two front doors, two side doors, and two back doors (identified above).
</p>

* **Description of Scenario & Hpotheses**
```

```
* **Psychology Building - Normal Use**

![](https://github.com/staticninja/IDS6938-SimulationTechniques/blob/master/Homework3/images/Psych%20Nomral.gif)


* **Psychology Building - Fire Alarm Activation**

![](https://github.com/staticninja/IDS6938-SimulationTechniques/blob/master/Homework3/images/Psych%20w%20Alarm.gif)


# References
### In order of importance:
<ol>
<li>Shiffman, D. (2012). The nature of code. <a href="http://natureofcode.com/">http://natureofcode.com/</a>
<li>Bevilacqua, F. (2013). Understanding steering behaviors: Collision avoidance. Gamedevelopment.tutsplus.com <a href="https://gamedevelopment.tutsplus.com/tutorials/understanding-steering-behaviors-collision-avoidance--gamedev-7777">https://gamedevelopment.tutsplus.com/tutorials/understanding-steering-behaviors-collision-avoidance--gamedev-7777</a>
<li>Pemmaraju, V. (2013). 3 Simple rules of flocking behaviors: Alignment, cohesion, and separation. Tuts+. <a href="https://gamedevelopment.tutsplus.com/tutorials/3-simple-rules-of-flocking-behaviors-alignment-cohesion-and-separation--gamedev-3444">https://gamedevelopment.tutsplus.com/tutorials/3-simple-rules-of-flocking-behaviors-alignment-cohesion-and-separation--gamedev-3444</a>
<li>Reynolds, C. (2001). Boids - Background and update. Red3d. <a href="http://www.red3d.com/cwr/boids/">http://www.red3d.com/cwr/boids/</a>
</ol>




