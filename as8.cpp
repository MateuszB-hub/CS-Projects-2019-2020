/* Mateusz Bieda
 */


#include  <iostream>
#include <cmath>
#include <fstream>

using namespace std;

// prototype for student given
// functions
void fish();
double mysteryX (double);
double mysteryY (double);
void mystery();
void archimedean( );

//provided
void genPlotScript( string);

// Global named constant
const double PI = 3.14159;

int main() {
	// this is used to select the case from
	// the switch statement
	char selection = ' ';
	// using a true loop to automatically run
	// the menu
	while (true){
		cout << "Parametric Equation Plotter" << endl;
		cout << "---------------------------" << endl;
		cout << "F/f - Fish Curve " << endl;
		cout << "A/a - Archimedean " << endl;
		cout << "M/m - Mystery " << endl;
		cout << "Q/q - Quit " << endl;
		cout << "Selection ";

		cin >> selection;
		// selection being used for user input as
		// defined before
		switch ( selection) {
			case 'F':
			case 'f':
				fish();
				genPlotScript( "fish" );
				system("gnuplot fish_plot.me");
				break;

			case 'A':
			case 'a':
				archimedean();
				genPlotScript ( "archimedean" );
				system("gunplot archimedean_plot.me");
				break;

			case 'm':
			case 'M':
				cout << "Mystery Equation Plotter" << endl;
				mystery();
				genPlotScript( "mystery");
				system("gnuplot mystery_plot.me");
				break;

			case 'q':
			case 'Q':
				cout << "Exiting ... " << endl;
				exit(0);

			default:
				cout << "Error - try again" << endl;
		}
	}
}

	// function algorithim here along with function documentation
	

	void fish( ) {
		
		// algoritihm for fish includes the following
		// ofstream output
		// declared variables for calculations, all double
		// except for strings
		// If a value is entered and is not a numeral
		// there is a error message diplayed and reprompts
		// the user
		// after that we open the output file
		// and we check and make sure that the file opens
		// a for loop is created 
		// as well as another loop inside 
		// we calculate variabels x and y inside there 
		// give the calculated values of x and y
		// outputting them to the ofstream file
		// and close and return
		double x = 0.0;
 		double y = 0.0;
		double size = 0.0;
		double t = 0.0;
		double count   = 0.0;
		double rotation = 0.0, plotoffset = 0.0;
		string fileName;
		ofstream oFile;
		cout << "Fish Curve Plotter" << endl;

		cout << "Enter size: ";
		cin >> size;
	
		while (cin.fail() == true) {
			cin.clear();
			cin.ignore(40, '\n');
			cout << "Illegal Value -- Try Again" << endl;
			cout << "Enter size";
			cin >> size;
		}
		
		cout << "Enter rotation: ";
		cin >> rotation;
		while(cin.fail() == true) {
			cin.clear();
			cin.ignore(40, '\n');
			cout <<"Illegal Value - Try Again" << endl;
			cout << "Enter rotation: ";
			cin >> rotation;
		}

		cout << "Enter plot off set: ";
		cin >> plotoffset;
	
		while(cin.fail() == true) {
			cin.clear();
			cin.ignore(40, '\n');
			cout << "Illegal Value - Try Again" << endl;
			cout << "Entetr plot off set: ";
			cin >> plotoffset;
		}

		
		cout << "Enter spiral count: ";		
		cin >> count;

		while (cin.fail() == true) {
			cin.clear();
			cin.ignore(40, '\n');
			cout << "Illegal Value -- Try Again" << endl;
			cout << "Enter sprial count";
			cin >> count;
		
		}
		// here we have completed the input of all 
		// the values and go onto using them in 
		// the equations
		oFile.open("fish.txt");

		while(oFile.is_open() !=true) {
			// checking on file to see if opened
			// if not a error message is read out
			cout << "There was an error opening the file" << endl;
			exit(0);
		}
		// for loop used on calculations of x and y
		for (double b = 0; b < count; b ++) {
			for (double t = 0; t <= 10*PI; t+= 0.1) {
				x = size * (cos(t) + 2.0 * rotation * cos(t / 2.0));
				y = size * sin(t);
				oFile << x << " " <<  y << endl;
			}
			size *= plotoffset;
		}
		// closing file
		oFile.close();
		return;
		// my code here
	}	
	
	void archimedean( ) {
		
		//define variables
		double x = 0.0;
		double y = 0.0;
		double size = 0.0;
		double t = 0.0;
		double count = 0.0;
		string fileName;
		ofstream oFile;
		
		// output calculation name to user
		cout << "Archimedean Plotter" << endl;

		cout << "Enter size: ";
		cin >> size;
		while (cin.fail() == true) {
			cin.clear();
			cin.ignore(40, '\n');
			cout << "Illegal Value -- Try Again" << endl;
			cout << "Enter size: ";
			cin >> size;
		
		}
	
		cout << "Enter spiral count "; 
		cin >> count;
		while (  cin.fail() == true) {
			cin.clear();
			cin.ignore(40, '\n');
			cout << "Illegal Value -- Try Again" << endl;
			cout << "Enter spiral count " << endl;
			cin >> count;
		
		}
		// all values have been inputted so we 
		// move onto calculating and putting calcualted 
		// values into a output file
		oFile.open ( "archimedean.txt" );

		while ( oFile.is_open() != true) {
			cout << "There was an error opening the file" << endl;
			exit(0);
		}
		for (double t = 0; t < count*2*PI; t+= 0.1) {

		x = size*t*cos(t+size);
		y = size*t*sin(t+size);
		oFile << x << " " << y << endl;
		}
		oFile.close();
		return;

		// code here
	}

	void mystery() {
		// here we define the variables
		ofstream oFile;
		// open our file
		oFile.open("mystery.txt");
		while(oFile.is_open() != true) {
			// check to make sure it opened if not 
			// a error is read out to user
			cout << "There was an error opening the file" << endl;
			exit(0);
		}
		// once past that we move onto the calculations
		// using a for loop, as well as calling the 
		// functions AND values to a file
		for (double t = -8.0; t <= 8.0 ; t += 0.001) {
			mysteryX(t);
			mysteryY(t);
			oFile << mysteryX(t) << " " << mysteryY(t) << endl;
		}
		//closing file and returning
		oFile.close();

		return;



		// code here
	}

	double mysteryX(double t) {
		// defining variable for |t| 
		// as well as x
		// and calculation
		double vt = abs(t), x = 0.0;

		x = (vt/t)*(0.3 * vt+0.2*abs(vt-1.0)+2.2*abs(vt-2.0)-2.7*abs(vt-3)-3*abs(vt-5)+3*abs(vt-7)+5*sin((PI/4)*(abs(vt-3)-abs(vt-4)+1))+(5/4)*pow((abs(vt-4.0)-abs(vt-5.0)-1.0),3.0)-5.3*cos(((PI/2.0)+asin(47.0/53.0))*(((abs(vt-7.0)-abs(vt-8.0)-1.0)/2.0)))+2.8);
		return x;
		// code here
	}

	double mysteryY(double t) {
		// we define the variables y, |t|
		// as well as caculating y
		double vt = abs(t) , y = 0.0;
		
		y = (3.0/2.0)*abs(vt-1.0)-(3.0/2.0)*abs(vt-2.0)-(29.0/4.0)*abs(vt-4.0)+(29.0/4.0)*abs(vt-5.0)+(7.0/16.0)*pow((abs(vt-2.0)-abs(vt-3.0)-1.0),4.0)+4.5*sin((PI/4.0)*(abs(vt-3.0)-abs(vt-4.0)-1.0))-((3.0*sqrt(2.0))/5.0)*pow(abs(abs(vt-5.0)-abs(vt-7.0)), (5.0/2.0))+6.4*sin(((PI/2.0)+asin(47.0/53.0))*(((abs(vt-7.0)-abs(vt-8.0)+1.0)/2.0))+asin(56.0/64.0))+4.95;
	       return y;	

		// code here
	}

	/* genPlotScript
	 * Creates a gnuplot script to plot the specified file.
	 * argument
	 * 	str - contains the file name of the text file to be plotted.
	 *
	 * return
	 *    none
	 */
	void genPlotScript ( string str)
	{
		string first = "set the terminal png size 640, 480 font \"Helvectica,8\" \nset output ";
		string second = " using 1:2 with lines notitle\n";

		ofstream oFile;
		oFile.open (str+"_plot.me" );
		if (oFile.is_open() ){
			oFile << first;
			oFile << '\"' << str+".png" << '\"' << endl;
			oFile << "plot " << '\"' << str+ ".txt" << '\"';
			oFile << second;
			oFile.close();
		}
	}
