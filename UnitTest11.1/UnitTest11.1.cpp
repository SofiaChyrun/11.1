#include "pch.h"
#include "CppUnitTest.h"
#include "../ChyrunSofialab11.1/ChyrunSofialab11.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest111
{
	TEST_CLASS(UnitTest111)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			t = Suma(3,6);
			Assert::AreEqual(t, 9);
		}
	};
}
