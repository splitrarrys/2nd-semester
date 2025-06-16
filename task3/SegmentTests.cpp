#include "CppUnitTest.h"
#include "../../GeometryLib/include/Point.h"
#include "../../GeometryLib/include/Segment.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GeometryTests
{
    TEST_CLASS(SegmentTests)
    {
    public:
        
        TEST_METHOD(Constructor_ValidPoints_CreatesSegment)
        {
            // Arrange
            Point p1(0.0, 0.0);
            Point p2(1.0, 1.0);
            
            // Act
            Segment segment(p1, p2);
            
            // Assert
            Assert::AreEqual(0.0, segment.getStart().x);
            Assert::AreEqual(0.0, segment.getStart().y);
            Assert::AreEqual(1.0, segment.getEnd().x);
            Assert::AreEqual(1.0, segment.getEnd().y);
        }

        TEST_METHOD(GetY_ValidX_ReturnsCorrectY)
        {
            // Arrange
            Segment segment(Point(0.0, 0.0), Point(2.0, 4.0));
            
            // Act & Assert
            Assert::AreEqual(0.0, segment.getY(0.0));
            Assert::AreEqual(2.0, segment.getY(1.0));
            Assert::AreEqual(4.0, segment.getY(2.0));
        }

        TEST_METHOD(GetY_XOutsideSegment_ThrowsException)
        {
            // Arrange
            Segment segment(Point(1.0, 1.0), Point(2.0, 2.0));
            
            // Act & Assert
            auto func = [&segment]() { segment.getY(0.5); };
            Assert::ExpectException<std::out_of_range>(func);
            
            auto func2 = [&segment]() { segment.getY(3.0); };
            Assert::ExpectException<std::out_of_range>(func2);
        }

        TEST_METHOD(ShiftLeftOperator_ValidShift_ReturnsShiftedSegment)
        {
            // Arrange
            Segment segment(Point(1.0, 2.0), Point(3.0, 4.0));
            
            // Act
            Segment shifted = segment << 1.0;
            
            // Assert
            Assert::AreEqual(0.0, shifted.getStart().x);
            Assert::AreEqual(2.0, shifted.getStart().y);
            Assert::AreEqual(2.0, shifted.getEnd().x);
            Assert::AreEqual(4.0, shifted.getEnd().y);
        }

        TEST_METHOD(ReadFromStream_ValidInput_CreatesSegment)
        {
            // Arrange
            std::istringstream input("0.0 1.0 2.0 3.0");
            
            // Act
            Segment segment = Segment::readFromStream(input);
            
            // Assert
            Assert::AreEqual(0.0, segment.getStart().x);
            Assert::AreEqual(1.0, segment.getStart().y);
            Assert::AreEqual(2.0, segment.getEnd().x);
            Assert::AreEqual(3.0, segment.getEnd().y);
        }

        TEST_METHOD(InvalidSegment_ThrowsException)
        {
            // Arrange & Act & Assert
            auto func = []() { Segment segment(Point(2.0, 0.0), Point(1.0, 1.0)); };
            Assert::ExpectException<std::invalid_argument>(func);
        }
    };
}