#include "pch.h"
#include "CppUnitTest.h"
#include "../лаба 7.3.2/лаба 7.3.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace юніттест732
{
	TEST_CLASS(юніттест732)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int colCount = 3;
			int rowCount = 6;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];
			Create(a, rowCount, colCount, 1, 1, 0, 0);
			Sort(a, rowCount, colCount, 0, 0);
			Assert::AreEqual(a[1][1], 1);
		}
	};
}
