#include "CppUnitTest.h"
#include ".../include/PiecewiseLinearApproximation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GeometryTests
{
    TEST_CLASS(PiecewiseLinearTests)
    {
    public:
        TEST_METHOD(Constructor_VectorPoints_CreatesApproximation)
        {
            std::vector<Point> points = {{0.0, 0.0}, {1.0, 1.0}, {2.0, 0.0}};
            PiecewiseLinearApproximation approx(points);
            
            Assert::AreEqual(3ull, approx.getPoints().size());
            Assert::AreEqual(2ull, approx.getSegments().size());
        }

        TEST_METHOD(Constructor_InitializerList_CreatesApproximation)
        {
            PiecewiseLinearApproximation approx({{0.0, 0.0}, {1.0, 1.0}, {2.0, 0.0}});
            
            Assert::AreEqual(3ull, approx.getPoints().size());
        }

        TEST_METHOD(AddPoint_ValidPoint_UpdatesApproximation)
        {
            PiecewiseLinearApproximation approx({{0.0, 0.0}, {2.0, 2.0}});
            approx.addPoint({1.0, 1.0});
            
            Assert::AreEqual(3ull, approx.getPoints().size());
            Assert::AreEqual(1.0, approx.getPoints()[1].x);
        }

        TEST_METHOD(GetY_ValidX_ReturnsCorrectY)
        {
            PiecewiseLinearApproximation approx({{0.0, 0.0}, {1.0, 1.0}, {2.0, 0.0}});
            
            Assert::AreEqual(0.5, approx.getY(0.5));
            Assert::AreEqual(1.0, approx.getY(1.0));
            Assert::AreEqual(0.5, approx.getY(1.5));
        }

        TEST_METHOD(ReadPointsFromStream_ValidInput_ReturnsPoints)
        {
            std::istringstream input("0.0 1.0\n2.0 3.0\n4.0 5.0");
            auto points = PiecewiseLinearApproximation::readPointsFromStream(input);
            
            Assert::AreEqual(3ull, points.size());
            Assert::AreEqual(2.0, points[1].x);
        }
    };
}