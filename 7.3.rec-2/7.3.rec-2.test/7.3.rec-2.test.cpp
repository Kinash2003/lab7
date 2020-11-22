#include "pch.h"
#include "CppUnitTest.h"
#include "../7.3.rec-2/7.3.rec-2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My73rec2test
{
	TEST_CLASS(My73rec2test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t = 0;
			const int rowCount = 4;
			const int colCount = 4;

			int** a = new int* [rowCount];
			for (int i = 0; i < colCount; i++)
				a[i] = new int[colCount];

			for (int i = 0; i < rowCount; i++)
				for (int j = 0; j < colCount; j++)
					a[i][j] = 0;

			t = IsMaxInRowN(a, rowCount, colCount, 0, 0);
			Assert::AreEqual(t, 0);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
