#include "SwerveMath.h"
#include <stdexcept>

SwerveMath::SwerveMath(double m_length, double m_width)
{
	if(m_length == 0.0 || m_width == 0.0)
		throw std::invalid_argument("Width and Length cannot be zero");

	LENGTH = m_length;
	WIDTH = m_width;
	R = sqrt((LENGTH*LENGTH) + (WIDTH*WIDTH));
}

double** SwerveMath::Calculate(double x1, double y1, double x2, double angle)
{
	R = sqrt((LENGTH*LENGTH)+(WIDTH*WIDTH));
	if(angle != -999.0)
	{
		angle = angle * PI / 180;
		double temp = x1 * cos(angle) + y1 * sin(angle);
		y1 = -x1 * sin(angle) + y1 * cos(angle);
		x1 = temp;
	}

	//x=strafe
	//y=fwd
	//z=rotate

	
    double a = x1 - x2 * (LENGTH / R);
    double b = x1 + x2 * (LENGTH / R);
    double c = y1 - x2 * (WIDTH / R);
    double d = y1 + x2 * (WIDTH / R);

    double wSpeed1 = sqrt((a * a) + (d * d));
    double wSpeed2 = sqrt((a * a) + (c * c));
    double wSpeed3 = sqrt ((b * b) + (d * d));
    double wSpeed4 = sqrt ((b * b) + (c * c));

    double wAngle1 = atan2 (a, d) / M_PI;
    double wAngle2 = atan2 (a, c) / M_PI;
    double wAngle3 = atan2 (b, d) / M_PI;
    double wAngle4 = atan2 (b, c) / M_PI;

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

	//Normalizes angles so they are within -1 to 1
	wAngle1 = wAngle1 / 360.0;
	wAngle2 = wAngle2 / 360.0;
	wAngle3 = wAngle3 / 360.0;
	wAngle4 = wAngle4 / 360.0;

	double temp[4][2] =	{	{wSpeed2, wAngle2},
							{wSpeed1, wAngle1},
							{wSpeed4, wAngle4},
							{wSpeed3, wAngle3}
						};
	double** output = CopyArray(temp);
	frc::SmartDashboard::PutNumber("wAngle1",temp[0][1]);
	frc::SmartDashboard::PutNumber("wAngle2",temp[1][1]);
	frc::SmartDashboard::PutNumber("wAngle3",temp[2][1]);
	frc::SmartDashboard::PutNumber("wAngle4",temp[3][1]);

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