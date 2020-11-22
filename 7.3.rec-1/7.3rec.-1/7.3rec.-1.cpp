#include "pch.h"
#include "CppUnitTest.h"
#include "../7.3.rec-1/7.3.rec-1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My73rec1
{
	TEST_CLASS(My73rec1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t = 0;
			const int rowCount = 3;
			const int colCount = 3;

			int** a = new int* [rowCount];
			for (int i = 0; i < colCount; i++)
				a[i] = new int[colCount];

			for (int i = 0; i < rowCount; i++)
				for (int j = 0; j < colCount; j++)
					a[i][j] = 0;


			t = IsMinInColK(a, rowCount, colCount);
			Assert::AreEqual(t, 3);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
