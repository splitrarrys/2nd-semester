#include "CppUnitTest.h"
#include ".../include/Segment.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GeometryTests
{
    TEST_CLASS(SegmentTests)
    {
    public:
        TEST_METHOD(Constructor_ValidPoints_CreatesSegment)
        {
            Point p1(0.0, 0.0);
            Point p2(1.0, 1.0);
            
            Segment segment(p1, p2);
            
            Assert::AreEqual(0.0, segment.getStart().x);
            Assert::AreEqual(1.0, segment.getEnd().x);
        }

        TEST_METHOD(Constructor_InvalidPoints_ThrowsException)
        {
            Point p1(1.0, 0.0);
            Point p2(0.0, 1.0);
            
            auto func = [&]() { Segment segment(p1, p2); };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(GetY_ValidX_ReturnsCorrectY)
        {
            Segment segment(Point(0.0, 0.0), Point(2.0, 4.0));
            
            Assert::AreEqual(0.0, segment.getY(0.0));
            Assert::AreEqual(2.0, segment.getY(1.0));
            Assert::AreEqual(4.0, segment.getY(2.0));
        }

        TEST_METHOD(ShiftLeftOperator_ValidShift_ReturnsShiftedSegment)
        {
            Segment segment(Point(1.0, 2.0), Point(3.0, 4.0));
            Segment shifted = segment << 1.0;
            
            Assert::AreEqual(0.0, shifted.getStart().x);
            Assert::AreEqual(2.0, shifted.getEnd().x);
        }

        TEST_METHOD(ReadFromStream_ValidInput_CreatesSegment)
        {
            std::istringstream input("0.0 1.0 2.0 3.0");
            Segment segment = Segment::readFromStream(input);
            
            Assert::AreEqual(0.0, segment.getStart().x);
            Assert::AreEqual(2.0, segment.getEnd().x);
        }
    };
}#include "CppUnitTest.h"
#include "../include/Segment.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GeometryTests
{
    TEST_CLASS(SegmentTests)
    {
    public:
        TEST_METHOD(Constructor_ValidPoints_CreatesSegment)
        {
            Point p1(0.0, 0.0);
            Point p2(1.0, 1.0);
            
            Segment segment(p1, p2);
            
            Assert::AreEqual(0.0, segment.getStart().x);
            Assert::AreEqual(1.0, segment.getEnd().x);
        }

        TEST_METHOD(Constructor_InvalidPoints_ThrowsException)
        {
            Point p1(1.0, 0.0);
            Point p2(0.0, 1.0);
            
            auto func = [&]() { Segment segment(p1, p2); };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(GetY_ValidX_ReturnsCorrectY)
        {
            Segment segment(Point(0.0, 0.0), Point(2.0, 4.0));
            
            Assert::AreEqual(0.0, segment.getY(0.0));
            Assert::AreEqual(2.0, segment.getY(1.0));
            Assert::AreEqual(4.0, segment.getY(2.0));
        }

        TEST_METHOD(ShiftLeftOperator_ValidShift_ReturnsShiftedSegment)
        {
            Segment segment(Point(1.0, 2.0), Point(3.0, 4.0));
            Segment shifted = segment << 1.0;
            
            Assert::AreEqual(0.0, shifted.getStart().x);
            Assert::AreEqual(2.0, shifted.getEnd().x);
        }

        TEST_METHOD(ReadFromStream_ValidInput_CreatesSegment)
        {
            std::istringstream input("0.0 1.0 2.0 3.0");
            Segment segment = Segment::readFromStream(input);
            
            Assert::AreEqual(0.0, segment.getStart().x);
            Assert::AreEqual(2.0, segment.getEnd().x);
        }
    };
}