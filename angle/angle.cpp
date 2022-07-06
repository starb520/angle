#include "angle.h"

using namespace std;

/***************************************************
* Angle Class
* Stores an angle in radians as an attribute, contains
* methods to change the angle between radians and
* degrees, display it in degrees, and normalizes it.
****************************************************/


Angle::Angle(double angleDegrees)
{
	setDegrees(angleDegrees);
}

Angle::Angle(const Angle& rhs) : angleRadians(rhs.angleRadians)
{

}


// Public
/***************************************************
* Changes an angle from radians to degrees and
* returns it.
****************************************************/
double Angle::getDegrees() const
{
	return convertToDegrees(angleRadians);
}


/***************************************************
* Returns an angle in radians.
****************************************************/
double Angle::getRadians() const
{
	return angleRadians;
}


/***************************************************
* Calls function to convert an angle in degrees to
* radians, then normalizes the angle.
****************************************************/
void Angle::setDegrees(double newAngle)
{
	this->angleRadians = normalize(convertToRadians(newAngle));
}


/***************************************************
* Updates the angleRadians attribute of this class to
* the normalized angle in radians.
****************************************************/
void Angle::setRadians(double newAngle)
{
	this->angleRadians = normalize(newAngle);
}


/***************************************************
* Displays an angle in degrees.
****************************************************/
void Angle::display() const
{
	cout << "\tThe current angle is " << getDegrees()
		<< " degree(s) " << endl;
}


// Private
/***************************************************
* Changes an angle from radians to degrees.
****************************************************/
double Angle::convertToDegrees(double radians) const
{
	return (radians / (2.00 * M_PI)) * 360.00;
}


/***************************************************
* Changes an angle from degrees to radians.
****************************************************/
double Angle::convertToRadians(double degrees) const
{
	return (degrees / 360.00) * (2.00 * M_PI);
}


/***************************************************
* Normalizes an angle, makes sure the angle in
* radians is between 0 and Pi.
****************************************************/
double Angle::normalize(double angle) const
{
	// an if statement could be used, but it might more costly than 
	// just performing the math every time
	return angle - floor(angle / (2.00 * M_PI)) * (2.00 * M_PI);
}

///****************************************
// * Practice using the insertion operator-- angle class
// * -- Have to be outside of the class
// *****************************************/
ostream& operator << (ostream& out, const Angle& rhs)
{
   out << rhs.getRadians() << endl;
	return out;
}


/**** ************************************
* Practice using the extraction operator-- angle class
* -- Have to be outside of the class
*****************************************/
istream& operator >> (istream& in, Angle& rhs)
{
	in >> rhs.angleRadians;                                 // only works if the attribute is public, is there a way to use friend?
	return in;
}
