#pragma once
#define _USE_MATH_DEFINES //Pi and Sqrt

#include <cmath> // Pi and Sqrt
#include <math.h> // Floor
#include <iostream> // cout and cin


/***************************************************
* Angle Class
* Stores an angle in radians as an attribute, contains
* methods to change the angle between radians and
* degrees, display it in degrees, and normalizes it.
****************************************************/
class Angle
{
public:
	double angleRadians;

public:
	// default constructor
	Angle() : angleRadians(0.0) {};

	// non-default constructor
	Angle(double angleDegrees);           // takes in degrees and changes it to radians before storing it in angleRadians

	// copy constructor
	Angle(const Angle& rhs);

	// assignment operator
	Angle& operator = (const Angle& rhs)
	{
		this->angleRadians = rhs.angleRadians;
		return *this;
	}

	// negative operator -- not working yet
	Angle operator-()
	{
		return normalize(this->angleRadians + M_PI);
	}

	// equals operator
	bool operator == (const Angle& rhs) const
	{
		return angleRadians == rhs.angleRadians;
	}

	// not equals operator
	bool operator != (const Angle& rhs) const
	{
		return angleRadians != rhs.angleRadians;
	}

	// prefix increment ++x
	Angle& operator++()
	{
		angleRadians += .0174533;
		// return new value
		return *this;
	}

	// postfix incrment x++
	Angle operator++(int postfix)
	{
		Angle newAngle(*this);
		angleRadians += .0174533;
		// return old value
		return newAngle;
	}

	// prefix decrement --x
	Angle& operator--()
	{
		angleRadians -= .0174533;
		// return new value
		return *this;
	}

	// postfix decrement x--
	Angle operator--(int postfix)
	{
		Angle newAngle(*this);
		angleRadians -= .0174533;
		// return old value
		return newAngle;
	}

	// return an angle in degrees
	double getDegrees() const;

	// return an angle in radians
	double getRadians() const;

	// update the angleRadians attribute
	void setDegrees(double newAngle);
	void setRadians(double newAngle);

	// display the angle in degrees
	void display() const;

private:
	// change angle from radians to degrees
	double convertToDegrees(double radians) const;

	// change the angle from degrees to radians
	double convertToRadians(double degrees) const;

	// formula to make sure the angle is always 
	// between 0 and 2Pi
	double normalize(double angle) const;

};


std::ostream& operator << (std::ostream& out, const Angle& rhs);
std::istream& operator >> (std::istream& in, Angle& rhs);