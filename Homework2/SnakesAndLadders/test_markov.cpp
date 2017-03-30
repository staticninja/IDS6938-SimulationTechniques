#include <iostream>
#include <functional>   
#include <numeric> 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <Eigen\dense>

#include "markov.h"
#include "TransitionMatrix.h"

int main(){

	SetTransitionMatrix();

	SetBoardMatrix();

	//Output Vector
	v.setZero();
	v(0) = 1.0;

	// Print Results to File
	std::ofstream myfile;
	myfile.open("markov_results.txt");
	
		// TODO add Markov vector - Matrix multiplication
for (int i = 0; i < ROLLS; i++)
	{
		//v = v.transpose() * TransitionMatrix; //formula from piazza and Dr. Kider. 
		v = v.transpose() * BoardMatrix; //formula to multiply for Snakes and Ladders

		for (int j = 0; j < size; j++)
		{
			std::cout << v(j) << ",";
			myfile << v(j) << ",";
		}

		std::cout << std::endl;
		myfile << std::endl;
	}
	myfile.close();


  return 1;
}