int size = 101;  
Eigen::MatrixXf TransitionMatrix(size, size);
Eigen::VectorXf v(size);

unsigned int ROLLS = 0; //TODO
double prob = 1.0/6.0;  //TODO

void SetTransitionMatrix()
{
	TransitionMatrix.setZero();
	for (int i = 0; i < TransitionMatrix.rows() - 6; i++)
	{
		TransitionMatrix(i, i + 1) = prob;
		TransitionMatrix(i, i + 2) = prob;
		TransitionMatrix(i, i + 3) = prob;
		TransitionMatrix(i, i + 4) = prob;
		TransitionMatrix(i, i + 5) = prob;
		TransitionMatrix(i, i + 6) = prob;

		for (int j = TransitionMatrix.rows()-6; j < TransitionMatrix.rows(); j++)
		{
			if (j>=TransitionMatrix.rows())
			{
				exit;
			}
			else {
				if (j == TransitionMatrix.rows() - 6)
				{
					TransitionMatrix(j, j + 1) = prob;
					TransitionMatrix(j, j + 2) = prob;
					TransitionMatrix(j, j + 3) = prob;
					TransitionMatrix(j, j + 4) = prob;
					TransitionMatrix(j, j + 5) = prob * 2;
				}
				if (j == TransitionMatrix.rows() - 5)
				{
					TransitionMatrix(j, j + 1) = prob;
					TransitionMatrix(j, j + 2) = prob;
					TransitionMatrix(j, j + 3) = prob;
					TransitionMatrix(j, j + 4) = prob*3;
				}
				if (j == TransitionMatrix.rows() - 4)
				{
					TransitionMatrix(j, j + 1) = prob;
					TransitionMatrix(j, j + 2) = prob;
					TransitionMatrix(j, j + 3) = prob*4;
				}
				if (j == TransitionMatrix.rows() - 3)
				{
					TransitionMatrix(j, j + 1) = prob;
					TransitionMatrix(j, j + 2) = prob*5;
				}
				if (j == TransitionMatrix.rows() - 2)
				{
					TransitionMatrix(j, j + 1) = prob*6;
				}
				if (j == TransitionMatrix.rows() -1)
				{
					TransitionMatrix(j, j) = prob * 6;
				}
			}
		}
	}


	//TODO
}