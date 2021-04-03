#include "Swerve/SwerveMath.h"
#include <stdexcept>


SwerveMath::SwerveMath(double m_length, double m_width)
{
	if(m_length == 0.0 || m_width == 0.0)
		throw std::invalid_argument("Width and Length cannot be zero");

	LENGTH = m_length;
	WIDTH = m_width;
	R = sqrt((LENGTH*LENGTH) + (WIDTH*WIDTH));
}

double** SwerveMath::Calculate(double x, double y, double z, double angle)
{
	if(angle != -999.0)
	{
		angle = angle * PI / 180;
		double temp = x * cos(angle) + y * sin(angle);
		y = -x * sin(angle) + y * cos(angle);
		x = temp;
	}

    y *= -1;

    double a = x - z * (LENGTH / R);
    double b = x + z * (LENGTH / R);
    double c = y - z * (WIDTH / R);
    double d = y + z * (WIDTH / R);

    double wSpeed3 = sqrt ((a * a) + (d * d));
    double wSpeed2 = sqrt ((a * a) + (c * c));
    double wSpeed4 = sqrt ((b * b) + (d * d));
    double wSpeed1 = sqrt ((b * b) + (c * c));

    double wAngle3 = atan2 (a, d) / PI;
    double wAngle2 = atan2 (a, c) / PI;
    double wAngle4 = atan2 (b, d) / PI;
    double wAngle1 = atan2 (b, c) / PI;
	//normalizes speeds so they're within the ranges of -1 to 1
	double maxSpeed = wSpeed1;
	if(wSpeed2 > maxSpeed) maxSpeed = wSpeed2;
	if(wSpeed3 > maxSpeed) maxSpeed = wSpeed3;
	if(wSpeed4 > maxSpeed) maxSpeed = wSpeed4;

	if(maxSpeed > 1)
	{
		wSpeed1/=maxSpeed;
		wSpeed2/=maxSpeed;
		wSpeed3/=maxSpeed;
		wSpeed4/=maxSpeed;
	}

	wAngle1 = (wAngle1) /.87;
	wAngle2 = (wAngle2) /.87;
	wAngle3 = (wAngle3) / .87;
	wAngle4 = (wAngle4) / .87;

	

	double temp[4][2] =	{	{wSpeed2, wAngle2},
							{wSpeed1, wAngle1},
							{wSpeed4, wAngle4},
							{wSpeed3, wAngle3}
						};
	double** output = CopyArray(temp);

	frc::SmartDashboard::PutNumber("wAngle1", wAngle1);
	frc::SmartDashboard::PutNumber("wAngle2", wAngle2);
	frc::SmartDashboard::PutNumber("wAngle3", wAngle3);
	frc::SmartDashboard::PutNumber("wAngle4", wAngle4);

	return output;
}

double** SwerveMath::CopyArray(double array[][2])
{
	double** output = new double*[4];
	for(int i = 0; i < 4; i++)
	{
		output[i] = new double[2];
		for(int k = 0; k < 2; k++)
		{
			output[i][k] = array[i][k];
		}
	}

	return output;
}