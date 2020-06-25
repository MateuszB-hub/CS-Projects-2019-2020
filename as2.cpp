/*Mateusz Bieda 
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double g= 64.348118;
	double height;
	int initialVelocity;
	double time;

	double x=0.0;
	double finalVelocity=0.0;
	
	cout << "Mateusz Bieda" << endl;
	

	cout << "Welcome to the Bedrock Volacano Drop" << endl;
	cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
	cout << "Distance from the volcano rim to the lava (ft):  " ; 
	
	cin >> height;
	
	cout << "Intial velocity(ft/sec):  " ;
	
	cin >> initialVelocity;

	x = pow(initialVelocity,2.0);

	finalVelocity = sqrt(x+g*height);

	cout << "Final Velocity:  " << finalVelocity << " feet/second" <<  endl; 

	time= (finalVelocity-initialVelocity)/(1.0/2.0 *g);

	cout << "Time to the ground:  " << time << " seconds" << endl;
	cout << "Thank you for playing." << endl;

}
