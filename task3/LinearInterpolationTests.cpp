#include "CppUnitTest.h"
#include "../include/LinearInterpolation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GeometryTests
{
    TEST_CLASS(LinearInterpolationTests)
    {
    public:
        TEST_METHOD(TestGetY_ValidX)
        {
            LinearInterpolation func{{0,0}, {2,4}};
            Assert::AreEqual(2.0, func.getY(1.0));
        }
        
        TEST_METHOD(TestAddPoint_ValidPoint)
        {
            LinearInterpolation func{{0,0}, {2,2}};
            func.addPoint({1,1});
            Assert::AreEqual(3ull, func.getPoints().size());
        }
        
        TEST_METHOD(TestShiftOperator)
        {
            LinearInterpolation func{{1,1}, {3,3}};
            auto shifted = func << 1.0;
            Assert::AreEqual(0.0, shifted.getPoints()[0].x);
        }
        
        TEST_METHOD(TestToString)
        {
            LinearInterpolation func{{0,0}, {1,1}};
            std::string str = func.toString();
            Assert::IsTrue(str.find("LinearInterpolation") != std::string::npos);
        }
    };
}