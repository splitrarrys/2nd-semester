#include "CppUnitTest.h"
#include "../../GeometryLib/include/RegularShape.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Mock класс для тестирования абстрактного RegularShape
class MockShape : public RegularShape {
public:
    double calculateSurfaceArea() const override { return 10.0; }
    double calculateVolume() const override { return 20.0; }
    std::string toString() const override { return "MockShape"; }
};

namespace GeometryTests
{
    TEST_CLASS(RegularShapeTests)
    {
    public:
        
        TEST_METHOD(CalculateSurfaceArea_ReturnsCorrectValue)
        {
            // Arrange
            MockShape shape;
            
            // Act & Assert
            Assert::AreEqual(10.0, shape.calculateSurfaceArea());
        }

        TEST_METHOD(CalculateVolume_ReturnsCorrectValue)
        {
            // Arrange
            MockShape shape;
            
            // Act & Assert
            Assert::AreEqual(20.0, shape.calculateVolume());
        }

        TEST_METHOD(ToString_ReturnsCorrectString)
        {
            // Arrange
            MockShape shape;
            
            // Act & Assert
            Assert::AreEqual(std::string("MockShape"), shape.toString());
        }

        TEST_METHOD(ReadFromInput_ThrowsNotImplemented)
        {
            // Arrange
            std::istringstream input("test");
            
            // Act & Assert
            auto func = [&input]() { RegularShape::readFromInput(input); };
            Assert::ExpectException<std::runtime_error>(func);
        }
    };
}