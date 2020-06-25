#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main () {
	
	char x = 0.0;
	double a = 0.0;
	double surfaceArea = 0.0;
	double volume = 0.0;
	double height = 0.0;
	double surfacetoVolumeRatio = 0.0;


	//retrun 0; to exit //

	cout << "Mateusz Bieda" << endl;

	cout << "September 22, 2019" << endl;	
	
	cout << "    ************************* " << endl;

	cout << "    * Slate Rock and Gravel * " << endl;

	cout << "    * Rock Volume Calculator* " << endl;

	cout << "    ************************* " << endl;

	cout << " (p/P) - Pentagonal Pyramid"             << endl;

	cout << " (b/B) - Pentagonal Bipyramid"           << endl;

	cout << " (d/D) - Gyroelongated Square Dipyramid" << endl;

	cout << " (g/G) - Gyrobifastigium"                << endl;

	cout << " (e/E) - Elongated Pentagonal Pyramid"   << endl;

	cout << " (q/Q) - Quit"                           << endl;

	char userInput;
	
	double edgeLength = 0.0;

	cout << "Your Selection: " ;

	cin >> userInput;

	switch (userInput) {
	
		case 'p':
		case 'P':
		
			cout << "Pentagonal Pyramid Calculator" << endl;
	
			cout << "Valid Range for Edge Length 2.00 --> 500.00" << endl;
	
			cout << "You entered p/P, now enter the edge length: " << endl;

			cin >> edgeLength; 
		
			if ((edgeLength >  2.00) && (edgeLength <  500.00 )){
			
				cout << "Run the evaluation for the chosen rock" << endl;
				
				cout << "Calculations for Pentagonal Pyramind" << endl;
				
				surfaceArea  = (sqrt(25.00+10.00* sqrt(5.00))/ 4.00+5.00 * sqrt(3.00)/4.00)* pow(edgeLength, 2.0);
			
				cout << fixed <<  setprecision(2) <<  "Surface Area: " << surfaceArea << endl;
				
				volume = (5.00 + sqrt(5.00)) / (24.00/ pow(edgeLength, 3.00));
				
				cout << fixed << setprecision(2) <<  "Volume: " << volume << endl;

				height = sqrt((5 - sqrt(5)) / 10) * edgeLength;
				 
				cout << fixed << setprecision(2) <<  "Height :" << height << endl; 

				surfacetoVolumeRatio = surfaceArea/volume;

				cout << fixed << setprecision(2) <<  "Surface to Volume Ratio: " << surfacetoVolumeRatio << endl;

				cout << "Thank you for choosing Slate Rock and Gravel for your gravel needs" << endl;

			}			
			else {
				
				cout << "Error- edge length out of range" << endl;

				cout << "Thank you for choosing Slate Rock and Gravel for your gravel needs" << endl;

	}
			break;
	

	        case 'b':
		case 'B':

			cout << "Your entered b/B, now enter the edge length: " << endl;

			cin >> edgeLength;

			if ((edgeLength > 1.00) && (edgeLength <  750 )){

				cout << "Run the evaluation for the chosen rock" << endl;
	
				cout << "Calculations for Pentagonal Bipyramid" << endl;
	
				cout << "Edge Length: " << edgeLength << endl;

				surfaceArea = 5 * sqrt(3) / 2 * pow(edgeLength,2);

				cout << fixed << setprecision(2) << "Surface Area: " << surfaceArea << endl;

				volume = (5 + sqrt(5)) / 12 * pow(edgeLength,3);

				cout << fixed << setprecision(2) <<  "Volume: " << volume << endl;

				height = 2 * sqrt((5 - sqrt(5) / 10)) * pow(edgeLength, 3);

				cout << fixed << setprecision(2) <<  "Height: " << height << endl;

				surfacetoVolumeRatio = surfaceArea/volume;

				cout << fixed << setprecision(2) <<  "Surface to Volume Ratio: " << surfacetoVolumeRatio << endl;

				cout << "Thank you for choosing Slate Rock and Gravel for your gravel needs" << endl;
	}		
			else {
				cout << "Error - edge length out or range" << endl;

				cout << "Thank you for choosing Slate Rock and Gravel for your gravel needs" << endl;
	}
			break;

		case 'd':
		case 'D':
				
			cout << "Your entered d/D, now enter the edge length: " << endl;

			cin >> edgeLength;

			if ((edgeLength > 7.00) && (edgeLength < 1502.00)) {

				cout << "Run the evaluation for the chosen rock" << endl;
	
				cout << "Calculations for Gyrolongated Sqaure Dipyramid" << endl;
	
				cout << "Edge Length: " << edgeLength << endl;

				surfaceArea = 4 * sqrt(3) * pow(edgeLength, 2);

				cout << fixed << setprecision(2) <<  "Surface Area: " << surfaceArea << endl;

				volume = (sqrt(2) + sqrt(4 + 3 * sqrt(2))) / 3 * pow(edgeLength, 3);

				cout << fixed << setprecision(2) <<  "Volume: " << volume << endl;

				height = (sqrt(1 - 1 / (2 + sqrt(2))) + 2 / sqrt(2)) * edgeLength;

				cout << fixed << setprecision(2) <<  "Height: " << height << endl;

				surfacetoVolumeRatio = surfaceArea/volume;

				cout << fixed << setprecision(2) <<  "Surface to Volume Ratio: " << surfacetoVolumeRatio << endl;

				cout << "Thank you for choosing Slate Rock and Gravel for your gravel needs" << endl;

	}		
			else {
				cout << "Error - edge length out of range" << endl;

				cout << "Thank you for choosing Slate Rock and Gravel for your gravel needs" << endl;
	}
			break;
	
		case 'g':
		case 'G':

			cout << "Your entered g/G, now entetr the edge length: " << endl;

			cin >> edgeLength;
			
			if ((edgeLength > 0.0) && (edgeLength < 1740.00)) {
				
				cout << "Run the evaluation for the chosen rock" << endl;
	
				cout << "Calculations for a Gyrobifastigium" << endl;
	
				cout << "Edge Length: " << edgeLength << endl;

				surfaceArea = (4 + sqrt(3)) * pow(edgeLength, 2);

				cout << fixed << setprecision(2) <<  "Surface Area: " << surfaceArea << endl;

				volume = sqrt(3) / 2 * pow(edgeLength, 3);

				cout << fixed << setprecision(2) << "Volume: " << volume << endl;

				height = sqrt(3) * edgeLength;

				cout << fixed << setprecision(2) <<  "Height: " << height << endl;

				surfacetoVolumeRatio = surfaceArea/volume;

				cout << "Surface to Volume Ratio: " << surfacetoVolumeRatio << endl;

				cout << "Thank you for choosing Slate Rock and Gravel for your gravel needs" << endl;
			}
			else {
				cout << "Error - edge length out of range" << endl;

				cout << "Thank you for choosing Slate Rock and Gravel for your gravel needs" << endl;
			}
			break;
	
		case 'e':
		case 'E':

			cout << "Your entered e/E, now enter the edge length: " << endl;

			cin >> edgeLength;

			if ((edgeLength > 0.52) && (edgeLength < 2751.00)) {

				cout << "Run the evaluation for the chosen rock" << endl;
	
				cout << "Elongated Pentagonal Pramid" << endl;
	
				cout << "Edge Length: " << edgeLength << endl;

				surfaceArea = (sqrt(25 + 10 * sqrt(5)) / 4 + 5 * sqrt(3) / 4 + 5) * pow(edgeLength,2);

				cout << fixed << setprecision(2) <<  "Surface Area: " << surfaceArea << endl;

				volume = ((5 + sqrt(5)) / 24 + sqrt(25 + 10 * sqrt(5)) / 4 ) * pow(edgeLength,3);

				cout << fixed << setprecision(2) <<  "Volume: " << volume << endl;

				height = (sqrt(5 - sqrt(5) / 10) + 1 ) * edgeLength;

				cout << fixed << setprecision(2) <<  "Height: " << height << endl;

				surfacetoVolumeRatio = surfaceArea/volume;

				cout << fixed << setprecision(2) <<  "Surface to Volume Ratio: " << surfacetoVolumeRatio << endl;

				cout << "Thank you for choosing Slate Rock and Gravel for your gravel needs" << endl;

			}
			else {
				cout << "Error - edge length out of range" << endl;

				cout << "Thank you for choosing Slate Rock and Gravel for your gravel needs" << endl;
			}
			break;

		case 'q': 
		case 'Q':

			cout << "Quitting" << endl;

			break;
		
		default:

			cout << "Invalid Entry" << endl;

			break;

	}		
		
}
