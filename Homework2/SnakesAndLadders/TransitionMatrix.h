int size = 101;  
Eigen::MatrixXf TransitionMatrix(size, size);
Eigen::MatrixXf BoardMatrix(size, size);
Eigen::VectorXf v(size);

unsigned int ROLLS = 80; //TODO
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
	}
	/* Created a for loop to generate the last 6 rows of the matrix dynamically, thereby allowing for varied board sizes!!!...
	tooke me a while to get it *sad face* */
	for (int j = 0; j < TransitionMatrix.rows(); j++)
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
}

void SetBoardMatrix()
{
	BoardMatrix.setZero();
	BoardMatrix = TransitionMatrix;

	for (int i = 0; i < BoardMatrix.rows(); i++)
	{
		if (BoardMatrix(i, 3) > 0)
		{
			BoardMatrix(i, 19) = BoardMatrix(i, 19) + BoardMatrix(i, 3);
			BoardMatrix(i, 3) = 0;
		}
		if (BoardMatrix(i, 15) > 0)
		{
			BoardMatrix(i, 37) = BoardMatrix(i, 37) + BoardMatrix(i, 15);
			BoardMatrix(i, 15) = 0;
		}
		if (BoardMatrix(i, 22) > 0)
		{
			BoardMatrix(i, 42) = BoardMatrix(i, 42) + BoardMatrix(i, 22);
			BoardMatrix(i, 22) = 0;
		}
		if (BoardMatrix(i, 25) > 0)
		{
			BoardMatrix(i, 64) = BoardMatrix(i, 64) + BoardMatrix(i, 25);
			BoardMatrix(i, 25) = 0;
		}
		if (BoardMatrix(i, 41) > 0)
		{
			BoardMatrix(i, 73) = BoardMatrix(i, 73) + BoardMatrix(i, 41);
			BoardMatrix(i, 41) = 0;
		}
		if (BoardMatrix(i, 53) > 0)
		{
			BoardMatrix(i, 74) = BoardMatrix(i, 74) + BoardMatrix(i, 53);
			BoardMatrix(i, 53) = 0;
		}
		if (BoardMatrix(i, 63) > 0)
		{
			BoardMatrix(i, 86) = BoardMatrix(i, 86) + BoardMatrix(i, 63);
			BoardMatrix(i, 63) = 0;
		}
		if (BoardMatrix(i, 76) > 0)
		{
			BoardMatrix(i, 91) = BoardMatrix(i, 91) + BoardMatrix(i, 76);
			BoardMatrix(i, 76) = 0;
		}
		if (BoardMatrix(i, 84) > 0)
		{
			BoardMatrix(i, 98) = BoardMatrix(i, 98) + BoardMatrix(i, 84);
			BoardMatrix(i, 84) = 0;
		}
		if (BoardMatrix(i, 11) > 0)
		{
			BoardMatrix(i, 7) = BoardMatrix(i, 7) + BoardMatrix(i, 11);
			BoardMatrix(i, 11) = 0;
		}
		if (BoardMatrix(i, 18) > 0)
		{
			BoardMatrix(i, 13) = BoardMatrix(i, 13) + BoardMatrix(i, 18);
			BoardMatrix(i, 18) = 0;
		}
		if (BoardMatrix(i, 28) > 0)
		{
			BoardMatrix(i, 12) = BoardMatrix(i, 12) + BoardMatrix(i, 28);
			BoardMatrix(i, 28) = 0;
		}
		if (BoardMatrix(i, 36) > 0)
		{
			BoardMatrix(i, 34) = BoardMatrix(i, 34) + BoardMatrix(i, 36);
			BoardMatrix(i, 36) = 0;
		}
		if (BoardMatrix(i, 77) > 0)
		{
			BoardMatrix(i, 16) = BoardMatrix(i, 16) + BoardMatrix(i, 77);
			BoardMatrix(i, 77) = 0;
		}
		if (BoardMatrix(i, 47) > 0)
		{
			BoardMatrix(i, 26) = BoardMatrix(i, 26) + BoardMatrix(i, 47);
			BoardMatrix(i, 47) = 0;
		}
		if (BoardMatrix(i, 83) > 0)
		{
			BoardMatrix(i, 39) = BoardMatrix(i, 39) + BoardMatrix(i, 83);
			BoardMatrix(i, 83) = 0;
		}
		if (BoardMatrix(i, 92) > 0)
		{
			BoardMatrix(i, 75) = BoardMatrix(i, 75) + BoardMatrix(i, 92);
			BoardMatrix(i, 92) = 0;
		}
		if (BoardMatrix(i, 99) > 0)
		{
			BoardMatrix(i, 70) = BoardMatrix(i, 70) + BoardMatrix(i, 99);
			BoardMatrix(i, 99) = 0;
		}
	}
}