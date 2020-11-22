#include "pch.h"
#include "CppUnitTest.h"
#include "../7.2.rec/7.2.rec.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My72rectest
{
	TEST_CLASS(My72rectest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			
			int t = 1;
			int k = 2;
			const int rowCount = 5;
			const int colCount = 5;

			int** p = new int* [rowCount];
			for (int i = 0; i < colCount; i++)
				p[i] = new int[colCount];

			for (int i = 0; i < rowCount; i++)
				for (int j = 0; j < colCount; j++)
					p[i][j] = 0;


			t = (p, rowCount, colCount, 0, 0);
			Assert::AreEqual(t, 9);

			for (int i = 0; i < rowCount; i++)
				delete[] p[i];
			delete[] p;




		}
	};
}
