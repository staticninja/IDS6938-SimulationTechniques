// Agent.cpp: implementation of the SIMAgent class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Behavior.h"
#include "Agent.h"
#include <random>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

//Construct static variables
//Their real values are set in static function SIMAgent::InitValues()
vector<SIMAgent*> SIMAgent::agents;
bool SIMAgent::debug = false;
float SIMAgent::radius = 20.0;
float SIMAgent::Mass = 1.0;
float SIMAgent::Inertia = 1.0;
float SIMAgent::MaxVelocity = 20.0;
float SIMAgent::MaxForce = 10.0;
float SIMAgent::MaxTorque = 40.0;
float SIMAgent::MaxAngVel = 10.0;
float SIMAgent::Kv0 = 1.0;
float SIMAgent::Kp1 = 1.0;
float SIMAgent::Kv1 = 1.0;
float SIMAgent::KArrival = 1.0;
float SIMAgent::KDeparture = 1.0;
float SIMAgent::KNoise = 1.0;
float SIMAgent::KWander = 1.0;
float SIMAgent::KAvoid = 1.0;
float SIMAgent::TAvoid = 1.0;
float SIMAgent::RNeighborhood = 1.0;
float SIMAgent::KSeparate = 1.0;
float SIMAgent::KAlign = 1.0;
float SIMAgent::KCohesion = 1.0;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
////////////////////////////////////////////////////////////////////// 
vec2 SIMAgent::WorldToLocal(vec2 &w)
{
	vec2 l;
	float s = sin(state[1]);
	float c = cos(state[1]);
	l[0] = c * w[0] + s * w[1];
	l[1] = -s * w[0] + c * w[1];
	return l;
}

vec2 SIMAgent::LocalToWorld(vec2 &l)
{
	vec2 w;
	float s = sin(state[1]);
	float c = cos(state[1]);
	w[0] = c * l[0] - s * l[1];
	w[1] = s * l[0] + c * l[1];
	return w;
}

void SIMAgent::SetVTheta(vec2 &V)
{
	vd = V.Length();
	if (vd < 0.0001) {
		thetad = 0.0;
	}
	else {
		if (abs(V[0]) < 0.0001) {
			if (V[1] > 0)
				thetad = M_PI / 2.0;
			else
				thetad = M_PI / -2.0;
		}
		else
			thetad = atan2(V[1], V[0]);
	}

	ClampAngle(thetad);
}

SIMAgent::SIMAgent()
{
}

SIMAgent::~SIMAgent()
{
}

void SIMAgent::Display()
{
	glPushMatrix();
	glTranslatef(GPos[0], rootHeight[frameNum], GPos[1]);
	if (showLeader && this == SIMAgent::agents[0]) {
		float red[] = { 1.0, 0.0, 0.0 };
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red);
		glPushMatrix();
		glTranslatef(0.0, 100.0, 0.0);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glutSolidCone(10.0, 20.0, 24, 24);
		glPopMatrix();
	}

	float specular[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 50);

	if (SIMAgent::debug) {
		glutSolidSphere(10.0, 24, 24);
		glDisable(GL_LIGHTING);
		glPushMatrix();
		glColor3f(1.0, 0.0, 0.0);
		glRotatef(-state[1] / M_PI * 180.0, 0.0, 1.0, 0.0);
		glLineWidth(3.0);
		glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, 0.0); glVertex3f(12 + state[2], 0.0, 0.0);
		glEnd();
		glPopMatrix();
		glPushMatrix();
		glColor3f(0.0, 1.0, 0.0);
		glRotatef(-thetad / M_PI * 180.0, 0.0, 1.0, 0.0);
		glLineWidth(3.0);
		glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, 0.0); glVertex3f(12 + vd, 0.0, 0.0);
		glEnd();
		glPopMatrix();
		glLineWidth(1.0);
		glEnable(GL_LIGHTING);
	}
	else {
		glRotatef(90.0f - state[1] * Rad2Deg, 0.0, 1.0, 0.0);
		//glutSolidSphere(6.0f, 12, 12);
		glCallList(AgentDisplay::listNames + frameNum);
	}
	glPopMatrix();
}

void SIMAgent::ClearAgents() {
	for (unsigned int i = 0; i < agents.size(); i++)
		delete SIMAgent::agents[i];
	SIMAgent::agents.clear();
}

SIMAgent::SIMAgent(float* color, CEnvironment* env) {
	memcpy(this->color, color, sizeof(float) * 3);
	dimState = 4;
	dimInput = 2;
	frameNum = rand() % totalFrames;
	this->env = env;
	float angle = float(rand() % 360) / 180.0 * M_PI;
	vWander[0] = cos(angle) * SIMAgent::KWander;
	vWander[1] = sin(angle) * SIMAgent::KWander;
	angle = float(rand() % 360) / 180.0 * M_PI;
	v0[0] = cos(angle) * SIMAgent::MaxVelocity / 2.0;
	v0[1] = sin(angle) * SIMAgent::MaxVelocity / 2.0;
	SIMAgent::agents.push_back(this);
}

void SIMAgent::SetInitState(float pos[], float angle)
{
	int i;
	GPos[0] = pos[0];
	GPos[1] = pos[1];
	for (i = 0; i < dimState; i++) {
		state[i] = 0.0;
	}
	for (i = 0; i < dimInput; i++)
		input[i] = 0.0;
	state[1] = angle;
}

void SIMAgent::Sense(int type)
{
	showLeader = (type == LEADER);
	goal = env->goal;
	switch (type) {
	case SEEK: Seek(); break;
	case FLEE: Flee(); break;
	case ARRIVAL: Arrival(); break;
	case DEPARTURE: Departure(); break;
	case WANDER: Wander(); break;
	case AVOID: Avoid(); break;
	case SEPARATION: Separation(); break;
	case ALIGNMENT: Alignment(); break;
	case COHESION: Cohesion(); break;
	case FLOCKING: Flocking(); break;
	case LEADER: Leader(); break;
	}
}

void SIMAgent::Act(float deltaT)
{
	int dframe;
	this->deltaT = deltaT;
	FindDeriv();
	UpdateState();
	if (abs(state[2]) < 0.001)
		dframe = 0;
	else {
		dframe = int(state[2] / SIMAgent::MaxVelocity * 2 + 1);
	}
	frameNum += dframe;
	if (frameNum >= totalFrames) {
		frameNum = frameNum - totalFrames;
	}
}

void SIMAgent::SetV0()
{
	v0 = env->goal - GPos;
	v0 = v0.Normalize() * SIMAgent::MaxVelocity / 2;
}

/*
Sets the intial Values
*/
void SIMAgent::InitValues()
{
	/*********************************************
	// TODO: Add code here
	Set initial value for control and behavior settings
	You need to find out appropriate values for:
	SIMAgent::Kv0, SIMAgent::Kp1, SIMAgent::Kv1, SIMAgent::KArrival, SIMAgent::KDeparture,
	SIMAgent::KNoise, SIMAgent::KWander, SIMAgent::KAvoid, SIMAgent::TAvoid, SIMAgent::RNeighborhood,
	SIMAgent::KSeparate, SIMAgent::KAlign, SIMAgent::KCohesion.
	*********************************************/
	Kv0 = 8.0;
	Kp1 = 150.0;
	Kv1 = 32.0;
	KArrival = 0.03;
	KDeparture = 15.0;
	KNoise = 10.0;
	KWander = 8.0;
	KAvoid = 100.0;
	TAvoid = 20.0;
	RNeighborhood = 800.0;
	KSeparate = 100.0;
	KAlign = 20.0;
	KCohesion = 0.05;
}

/*
* You should apply the control rules given desired velocity vd and desired orientation thetad.
* Velocity control: input[0] = f = m * Kv0 * (vd - v)
* Heading control: input[1] = tau = I * ( -Kv1 * thetaDot - Kp1 * theta + Kp1 * thetad)
* This function sets input[0] and input[1] appropriately after being called.
*/
void SIMAgent::Control()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	Truncate(vd, -SIMAgent::MaxVelocity, SIMAgent::MaxVelocity);
	input[0] = SIMAgent::Mass * SIMAgent::Kv0 * (vd - state[2]);
	Truncate(input[0], -SIMAgent::MaxForce, SIMAgent::MaxForce);

	double dangle = AngleDiff(state[1], thetad);
	input[1] = SIMAgent::Inertia * (Kp1 * dangle - Kv1 * state[3]);
	Truncate(input[1], -SIMAgent::MaxTorque, SIMAgent::MaxTorque);
	}

/*
*	Compute derivative vector given input and state vectors
*  This function sets derive vector to appropriate values after being called
*/
void SIMAgent::FindDeriv()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	deriv[0] = state[0];// x - start position
	deriv[1] = state[3];//first derivative = velocity
	deriv[2] = input[0] / Mass;//second derivative = acceleration. Force = Mass * Acceleration. Acceleration = Force/Mass.
	deriv[3] = input[1] / Inertia;//third derivative = Jerk?

	//The derivatives below did not work! They were gleaned from the homework writeup.
	//deriv[2] = state[2]; //deriv[2] is the velocity of th eagent in local body coordinates.
	//deriv[3] = state[3]; // deriv[3] is the angular velocity of the agent in world coordinates.
	//deriv[0] = input[0] / Mass; //deriv[0] is the force in local body cooridnates divided by the mass.
	//deriv[1] = input[1] / Inertia; //deriv[1] is the torque in local body coordinates divided by the inertia.
}

/*
*	Update the state vector given derivative vector
*  Compute global position and store it in GPos
*  Perform validation check to make sure all values are within MAX values
*/
void SIMAgent::UpdateState()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	for (int i = 0; i < dimState; i++) {
		state[i] += deriv[i] * deltaT;
	}
	state[0] = 0.0;

	ClampAngle(state[1]);
	Truncate(state[2], -SIMAgent::MaxVelocity, SIMAgent::MaxVelocity);

	vec2 GVelocity;
	GVelocity[0] = state[2] * cos(state[1]);
	GVelocity[1] = state[2] * sin(state[1]);
	GPos += GVelocity;

	Truncate(GPos[0], -1.0 * env->groundSize, env->groundSize);
	Truncate(GPos[1], -1.0 * env->groundSize, env->groundSize);

	Truncate(state[3], -SIMAgent::MaxAngVel, SIMAgent::MaxAngVel);
}

/*
*	Seek behavior
*  Global goal position is in goal
*  Agent's global position is in GPos
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Seek()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	vec2 tmp;
	vec2 Vd = goal - GPos;
	thetad = atan2(Vd[1], Vd[0]);
	thetad += M_PI;
	vd = MaxVelocity;
	tmp = vec2(cos(thetad) * vd, sin(thetad) * vd);
	return tmp;
}

/*
*	Flee behavior
*  Global goal position is in goal
*  Agent's global position is in GPos
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Flee()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	vec2 tmp;
	vec2 Vd = goal - GPos;
	thetad = atan2(Vd[1], Vd[0]);
	vd = MaxVelocity;
	tmp = vec2(cos(thetad)* vd, sin(thetad)* vd);
	return tmp;
}

/*
*	Arrival behavior
*  Global goal position is in goal
*  Agent's global position is in GPos
*  Arrival setting is in SIMAgent::KArrival
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Arrival()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	vec2 tmp;
	vec2 Vd = goal - GPos;
	double dist = Vd.Length();
	vd = Vd.Length() * KArrival;
	thetad = atan2(Vd[1], Vd[0]);
	thetad += M_PI;
	double vn = MaxVelocity * (vd / radius);
	if (dist > 0)
	{
		return vec2(cos(thetad)*vd, sin(thetad)*vd);
	}
	return vec2(cos(thetad)*vn, sin(thetad)*vn);
}
/*
*	Departure behavior
*  Global goal position is in goal
*  Agent's global position is in GPos
*  Departure setting is in KDeparture
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Departure()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	vec2 tmp;
	vec2 Vd = goal - GPos;
	double dist = Vd.Length();
	vd = Vd.Length() * KDeparture;
	thetad = atan2(Vd[1], Vd[0]);
	
	double vn = MaxVelocity * (vd / radius);
	if (dist > 0)
	{
		return vec2(cos(thetad)*vd, sin(thetad)*vd);
	}
	return vec2(cos(thetad)*vn, sin(thetad)*vn);
}

/*
*  Wander behavior
*  VWander is in vWander
*  V0(nominal velocity) is in v0
*  Wander setting is in KWander
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Wander()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	vec2 tmp;
	float angle = float(rand() % 360) / 180.0 * M_PI; //taken from SimAgent::SimAgent
	vec2 Vd = goal - GPos;
	vd = Vd.Length() * KWander;
	thetad = angle;
	tmp = vec2(vd*cos(thetad)*KNoise, vd*sin(thetad)*KNoise)*KWander;
	return tmp;
}

/*
*	Avoid behavior
*  Obstacles are in env->obstacles
*  Number of obstacles is env->obstaclesNum
*  env->obstacles[i][0] and env->obstacles[i][1] are the global position of the ith obstacle
*  env->obstacles[i][2] is the radius of the ith obstacle
*  Agent bounding sphere radius is in SIMAgent::radius
*  Avoidance settings are in SIMAgent::TAvoid and SIMAgent::KAvoid
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Avoid()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	vec2 tmp;
	vec2 c = vec2 (0,0);
	for (int i = 0; i < env->obstaclesNum; i++)
	{
		vec2 gpos_diff_obsticle = vec2 (env->obstacles[i][0]-GPos[0], env->obstacles[i][1]-GPos[1]); //differnece in agent loation to objects in global coordinates
		vec2 local_diff_obsticle = WorldToLocal(gpos_diff_obsticle);

		if (abs(local_diff_obsticle[0] > abs(TAvoid)))
		{
			;
		}
	}
	return tmp;
}

/*
*	Separation behavior
*  SIMAgent::agents[i] gives the pointer to the ith agent in the environment
*  Separation settings are in SIMAgent::RNeighborhood and SIMAgent::KSeperate
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Separation()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	vec2 tmp;
	vec2 sum = vec2(0, 0);
	for (int i = 0; i < agents.size(); i++) //loop to evaluate the all the agents positions
	{
		vec2 dist = agents[i]->GPos - GPos; //determine the distance from self to another in vector form
		if (dist[0] == 0 && dist[1] == 0) //if the for loop boid is self
		{
			continue;
		}

		double neighbor = sqrt(dist[0] * dist[0] + dist[1] * dist[1]);
		//distance between two points = squrt (x2-x1)^2 + (y2-y1)^2. dist = vector subtraction of 1 & 2.
		
		if (neighbor < RNeighborhood)
		{
			sum[0] += (dist[0] / abs(dist[0])) * KSeparate;
			sum[1] += (dist[1] / abs(dist[1])) * KSeparate;
		}
	}
	vec2 NewV = sum;
	vd = sqrt(NewV[0] * NewV[0] + NewV[1] * NewV[1]);
	thetad = atan2(NewV[1], NewV[0]);
	tmp = vec2(cos(thetad)*vd, sin(thetad)*vd);
	return tmp;
}

/*
*	Alignment behavior
*  SIMAgent::agents[i] gives the pointer to the ith agent in the environment
*  Alignment settings are in SIMAgent::RNeighborhood and SIMAgent::KAlign
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Alignment()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	vec2 tmp;
	vec2 sum = vec2 (0,0);
	int num_agents = 0; //tracking the number of BOIDS in the simulation
	for (int i = 0; i < agents.size(); i++) //loop to evaluate the all the agents positions
	{
		vec2 dist = agents[i]->GPos - GPos; //determine the distance from self to another in vector form
		int d = sqrt(dist[0] * dist[0] + dist[1] * dist[1]);
		if ((d > 0) && (d < KAlign)) //distance between two points = squrt (x2-x1)^2 + (y2-y1)^2. dist = vector subtraction of 1 & 2.
		{
			sum += agents[i]->GPos; //add together
			num_agents++; //count the number of boids checked
			
		}
		if (num_agents > 0)
		{
			vec2 mean = sum / num_agents; //average velocity of all boids in neighborhood
			mean.Normalize();
			double mag = sqrt(mean[0] * mean[0] + mean[1] * mean[1]);
			if (mag > MaxVelocity)
			{
				mean[0] / mag;
				mean[1] / mag;
				tmp = mean;
			}
		}
		else
		{
			tmp = vec2(0, 0);
		}
	}
	return tmp;
}

/*
*	Cohesion behavior
*  SIMAgent::agents[i] gives the pointer to the ith agent in the environment
*  Cohesion settings are in SIMAgent::RNeighborhood and SIMAgent::KCohesion
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Cohesion()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	vec2 tmp;
	vec2 sum = vec2(0, 0);
	int num_agents = 0; //tracking the number of BOIDS in the simulation
	for (int i = 0; i < agents.size(); i++) //loop to evaluate the all the agents positions
	{
		vec2 dist = agents[i]->GPos - GPos; //determine the distance from self to another in vector form

		double neighbor = sqrt(dist[0] * dist[0] + dist[1] * dist[1]);
		//distance between two points = squrt (x2-x1)^2 + (y2-y1)^2. dist = vector subtraction of 1 & 2.

		if (neighbor < RNeighborhood)
		{
			sum[0] = sum[0] + agents[i]->GPos[0]; //IDK
			sum[1] = sum[1] + agents[i]->GPos[1]; //IDK
			num_agents++;
		}
	}
	vec2 NewV = sum/num_agents;
	vec2 cohesion = KCohesion*(NewV - GPos);
	vd = sqrt(cohesion[0]*cohesion[0]+cohesion[1]*cohesion[1]);
	thetad = atan2(cohesion[1], cohesion[0]);
	tmp = vec2(cos(thetad)*vd, sin(thetad)*vd);
	return tmp;
}

/*
*	Flocking behavior
*  Utilize the Separation, Cohesion and Alignment behaviors to determine the desired velocity vector
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Flocking()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	vec2 tmp;
	vec2 separation = Separation();
	vec2 alignment = Alignment();
	vec2 cohesion = Cohesion();
	return tmp;
}

/*
*	Flocking behavior
*  Utilize the Separation, Arrival behaviors to determine the desired velocity vector
*  You need to find the leader, who is always the first agent in SIMAgent::agents
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Leader()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	vec2 tmp;

	return tmp;
}