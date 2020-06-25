#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

int main( int argc, char * argv[]) {
	// decalre variables //
	ifstream inFile;
	ofstream oFile;
	string fileName;
	int recordAllFiles = 0;
	double edgeLength = 0.0;
	int requestedRecords;
	double number = 0.0;
	string firstName;
	string lastName;
	string rockType;
	double quantity;

	cout << "Mateusz Bieda" << endl;
	cout << "Program that takes in information from a special";
	cout << " selected file, and outputs it dependent on the users choice" << endl;
	//Header
	cout << "----------------------------------------------------" << endl;
	cout << "Welcome to Slate Rock and Gravel Delivery Calculator" << endl;
	cout << "----------------------------------------------------" << endl;


	// checks to see if filename is on the command line //
	if (argc > 1 ) {
		fileName = argv[1];
		inFile.open (fileName) ;
	}

	// checks to see if file is open //
	if (inFile.is_open() == false) {


		if ( argc > 1 ) {
			cout << "File: \"" << fileName << "\" did not open"
				<< endl;
		}
		// loops until the file is opened //
		do { 
			//propmts user //
			cout << "Enter the INPUT filename: ";
			cin >> fileName;

			//attempts to open the file
			inFile.open (fileName);

			//a test to see if it worked
			if (inFile.is_open() == false)
				cout << "File: \"" << fileName << "\" did not open"
					<< endl;
		}	while( !inFile.is_open());
	}
	cout << "The input file: \"" << fileName << "\" opened correctly" << endl;

	if (argc > 2) {
		fileName = argv[2];
		oFile.open( fileName);
	}

	// this will check and see if the out file is open
	if (oFile.is_open() == false ) {
		if ( argc > 2){
			cout << "Output File: \"" << fileName << "\" did not open"
				<< endl;
		}
		//loop until a file is succesfully opened
		do {
		//prompts user
		cout << "Enter the output filename: ";
		cin >> fileName;

		//attemps to open file 
		oFile.open (fileName);

		//check to see if open works
		if ( oFile.is_open() == false)
			cout << "Output File: \"" << fileName << "\" did not open"
				<< endl;
		}while (!oFile.is_open());
	}
	//print a message for the user to tell them their file opened
	cout << "Output file: \"" << fileName << "\" opened correctly" << endl;

	if (inFile.is_open() == true){
		cout << "Would you like to process all the records in the file? ";
		char recordInput;	 
		cout << "(y/n) ";
		cin >> recordInput;
		switch (recordInput) {
			case 'n':
			case 'N':
				cout << "Enter number of records to process: ";
				cin >> recordAllFiles;
				cout << "Maximum requested record count of " << recordAllFiles << " reached " << endl;
		}
		// here to check how many records of info are to be taken in
	if((inFile.eof() == false) && (requestedRecords != recordAllFiles)) {
		if (inFile.is_open() == true){
			// tells in what order and what exactly to output
			
		inFile >> firstName >> lastName >> rockType >> edgeLength >> quantity;
		}		
	
	
	// Defining variables for calculations 
	char x = 0.0;
	double a = 0.0;
	double surfaceArea = 0.0;
	double volume = 0.0;
	double height = 0.0;
	double surfacetoVolumeRatio = 0.0;
		if (rockType == "PentagonalPyramid" ) {
			cout << "----------------------------------------" << endl;
			cout <<" Pentagonal Pyramid Calculator" << endl;
			cout << "Valid Range for Edge Length 2.00 --> 500.00" << endl;
			cout << "----------------------------------------" << endl;

			cin >> edgeLength;
			// specifiec edge lengths for calculations
			if ((edgeLength > 2.00) && (edgeLength < 500.00)) {
				cout << "--------------------------------------" << endl;
				cout << "Calculations for a Pentagonal Pyramid" ;
				cout << "Edge Length: " << edgeLength;
				cout << "--------------------------------------" << endl;
				surfaceArea = (sqrt(25.00 + 10.00 * sqrt(5.00))/ 4.00 + 5.00 * sqrt (3.00)/4.00) * pow(edgeLength, 2.0);
				cout << fixed << setprecision(2) << "Surface Area: "
					<< surfaceArea << endl;
				volume = (5.00 + sqrt(5.00)) / (24.00/ pow(edgeLength, 3.00));
				cout << fixed << setprecision(2) << "Volume: " << volume << endl;
				height = sqrt((5 - sqrt(5))/ 10) * edgeLength;
				cout << fixed << setprecision(2) << "Height: " << height << endl;
				surfacetoVolumeRatio = surfaceArea/volume;
				cout << fixed << setprecision(2) << "Surface Area to Volume";
				cout << "Ratio: " << surfacetoVolumeRatio << endl;
			}
			else
			{	
				// statement to give an error message if the edge length
				// out of range
				if ((edgeLength < 2.00) && (edgeLength > 500.00)) {
					cout << "----------------------------------------------------------";
					cout << "-------------------" << endl;
					cout << "Error - Pentagonal Pyramid Calculator edge length is" ;
					cout << "out of range" << endl;
					cout << "Edge Length Specified: "<< edgeLength <<  " Valid Range is between";
				        cout << " 2.00 and 500.00" << endl;
					cout <<  "---------------------------------------------------------";
					cout << "-------------------" << endl;
					}
			}	
			if (rockType == "Gyrobifastigium" ) {
				cout << "--------------------------------------" << endl;
				cout << "Gyrobifastigium Calculator" << endl;
				cout << "Valid Range for Edge Length between 0.00 and 1740.00";
				cout << "-----------------------------------" << endl;
				cin >> edgeLength;
				if ((edgeLength >0.00)  && ( edgeLength <1740.00)) {
				cout << fixed << setprecision(2) << "Edge Length: " << edgeLength << endl;
				surfaceArea = (4+sqrt(3)) * pow(edgeLength, 2);
				cout << fixed << setprecision(2) <<  "Surface Area: " << surfaceArea << endl;
				volume = sqrt(3) / 2 * pow(edgeLength,3);
				cout << fixed << setprecision <<  "Volume: " << volume << endl;
				height = sqrt(3) * edgeLength;
				cout << fixed << setprecision(2) << "Height: " << height << endl;	
				surfacetoVolumeRatio = surfaceArea/volume;
				cout << fixed << setprecision(2) << "Surface To Volume Ratio: " << surfacetoVolumeRatio << endl;
				}
				else 
				{
				if ((edgeLength < 0.00) && (edgeLength > 1740.00)) {
					cout << "--------------------------------------------" << endl;
					cout << "Error Gyrobifastigium edge length is out of range" << endl;
					cout << "Edge Length Specified: "<< edgeLength << " Valid range is between";
					cout << "0.00 and 1740.00" << endl;
					cout << "--------------------------------------------";

				}
			}
		}
		}
	cout << "Maximum requested records count of " << recordAllFiles << " reached " << endl;	
	}
	}	
	
	// reads data from file
	do {
		//value to read
		inFile >> number;
		// tests to see if end of file is set
		if (inFile.eof() == false)
		
		oFile << number << endl;

		else
			//EOF error message
			cout << "End of file reached" << endl;
		//loop to EOF
	}while (inFile.eof() == false) ;
	// close files before exit;
	oFile.close();
	inFile.close();
	}

