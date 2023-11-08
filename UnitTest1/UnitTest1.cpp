#include "CppUnitTest.h"
#include "../Lab7.3.rek/pr7.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestSumOfRowsWithoutNegatives)
		{
			int matrix[MAX_SIZE][MAX_SIZE] = {
				{1, 2, 3},
				{4, 5, 6},
				{7, -8, 9}
			};
			int n = 3;

			int result = sumOfRowsWithoutNegatives(matrix, n, 0, 0);

			Assert::AreEqual(21, result); 
		}

		TEST_METHOD(TestFindMinOfParallelDiagonalSums)
		{
			int matrix[MAX_SIZE][MAX_SIZE] = {
				{1, 2, 3},
				{4, 5, 6},
				{7, -8, 9}
			};
			int n = 3;

			int result = findMinOfParallelDiagonalSums(matrix, n, 1, 0, matrix[0][0]);

			Assert::AreEqual(3, result); 
		}
	};
}
