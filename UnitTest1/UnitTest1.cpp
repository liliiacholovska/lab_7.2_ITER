#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.2(1)/lab_7.2(1).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestCreate)
		{
			int n = 3;
			int Low = 7, High = 65;
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
				a[i] = new int[n];

			Create(a, n, Low, High);

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High);

			for (int i = 0; i < n; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestSort)
		{
			int n = 3;
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
				a[i] = new int[n];

			a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
			a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;
			a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;

			Sort(a, n);

			Assert::AreEqual(7, a[0][2]);
			Assert::AreEqual(5, a[1][1]);
			Assert::AreEqual(3, a[2][0]);

			for (int i = 0; i < n; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}