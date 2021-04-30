#include "catch2/catch2.hpp"
#include "GTpressa.h"

//Testing GTinitPressa
TEST_CASE("parameters values respect constrains", "[GTpressa]"){

    double l1 = 100;
    double l2 = 100;
    double l3 = 100;
    double distance = 180;
    double angle = 0.3;
    double height = 30;
    double width = 10;

    GTdevicePressa* dev = GTinitPressa(l1, l2, l3, distance, angle, height, width);
     REQUIRE(dev != NULL);
     REQUIRE(dev->l1 == l1);
     REQUIRE(dev->l2 == l2);
     REQUIRE(dev->l3 == l3);
     REQUIRE(dev->distance == distance);
     REQUIRE(dev->angle == angle);
     REQUIRE(dev->height == height);
     REQUIRE(dev->width == width);

    GTDeleteDevice(dev);

}

TEST_CASE("Parameters do not respect constrains", "[GTpressa]"){  

    GTdevicePressa* dev1 = GTinitPressa(100, 100, 100, 180, 0.1, 30, 10);
    REQUIRE(dev1 == NULL);
    GTDeleteDevice(dev1);

    GTdevicePressa* dev2 = GTinitPressa(100, 100, 100, 180, 0.1, 30, 100);
    REQUIRE(dev2 == NULL);
    GTDeleteDevice(dev2);

    GTdevicePressa* dev3 = GTinitPressa(100, 100, 100, 300, 0.1, 30, 10);
    REQUIRE(dev3 == NULL);
    GTDeleteDevice(dev3);

}

//Testing GTCheckParam
TEST_CASE("Device not initialized", "[GTpressa]"){
    REQUIRE(GTCheckParam(NULL) == 7);
}

TEST_CASE("Measures do not respect parameters constrains", "[GTpressa]"){
    GTdevicePressa* dev = GTinitPressa(100, 100, 100, 180, 0.4, 30, 10);
    REQUIRE(GTCheckParam(dev) == 0);

    dev->l1 = 0;
    REQUIRE(GTCheckParam(dev) == 1);
    dev->l1 = 100;

    dev->angle = 0;
    REQUIRE(GTCheckParam(dev) == 2);
    dev->angle = 0.4;

    dev->distance = 400;
    REQUIRE(GTCheckParam(dev) == 4);
    dev->distance = 180;

    dev->height = 100;
    REQUIRE(GTCheckParam(dev) == 6);
    dev->height = 30;

    
    GTDeleteDevice(dev);


}

//Testing Set functions
TEST_CASE("Testing GTSet functions with acceptable and not acceptable parameters", "[GTpressa]"){
    
    GTdevicePressa* dev = GTinitPressa(100, 100, 100, 180, 0.4, 30, 10);
    REQUIRE(GTSetL1(NULL, 100) == 2);
    REQUIRE(GTSetWidth(NULL, 15) == 2);
    REQUIRE(GTSetL3(dev, 150) == 0);
    REQUIRE(GTSetDistance(dev, 300) == 1);
    REQUIRE(GTSetWidth(dev, 30) == 1);
    REQUIRE(GTSetL2(dev, 50) == 0);
    REQUIRE(GTSetAngle(dev, 0) == 1);

}