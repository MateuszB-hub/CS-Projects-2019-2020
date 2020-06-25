#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	const double PI = 3.14159;
	const double g = 64.348118;

	double angleRadians = 0.0;
	double angleDegrees = 0.0;
	double initialVelocity = 0.0;
	double velocityX;
	double velocityY;
	double time = 0.0;
	double maxheight;
	double height = 0.0;
	double range = 0.0;
	double x = 0.0;	

	cout << "Mateusz Bieda" << endl;
	cout << "September 12, 2019" << endl;

	cout << "Height of the volcano cone(ft): ";
	cin >> height;

	cout << "Velocity (ft/sec): ";
	cin >> initialVelocity;

	cout << "Angle(degrees): ";
	cin >> angleDegrees;

	angleRadians = angleDegrees * (PI/180);

	velocityX = cos(angleRadians) * initialVelocity;
	velocityY = sin(angleRadians) * initialVelocity;

	maxheight = height + pow(velocityY, 2.0)/g;

	x = pow(velocityY, 2.0) + g * height;
	time= (velocityY + sqrt(x))/(1.0/2.0 *g);

	cout << "Rock time of flight: " << time << endl ;

	cout << "Max height: " << maxheight << endl;

	range = velocityX * (velocityY + sqrt(x))/ (1.0/2.0 * g);

	cout << "Range: " << range << endl ;


}
