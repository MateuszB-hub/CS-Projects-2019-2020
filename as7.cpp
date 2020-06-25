#include <iostream>
#include <fstream>

using namespace std;


		
int main(int argc,char *  argv[]) {



	cout << "Mateusz Bieda"<< endl;
	cout << "This takes in values from a specified file, and reading";
	cout << "in strings, ints, and char prints out shapes with certain sizes";
	cout << " and characters."<< endl;

	cout << endl;
	// declare variables
	ifstream inFile;
	ofstream oFile;
	string fileName;
	string labelType;
	int size = 0;
	char character;
	int column = 0;
	int row = 0;
	int a = 0, b = 0, c = 2, d = 0, e =1, f= 0, p =0;
	// see if the filename is on the command line
	if ( argc > 1) {
		fileName = argv[1];
		inFile.open( fileName);
	}
	// test to see if inFile opened
	if(inFile.is_open() == false) {
		if (argc > 1){
			cout << "File: \"" << fileName << "\" did not open"
				<< endl;
		}
		// if it successfully opened we run this
		do {
			cout << "Enter an input file: ";
			cin >> fileName;

			//try and open it
			inFile.open(fileName);

			// check to see if it worked
			if (inFile.is_open() == false)
				cout << "File \"" << fileName << "\" did not open"
					<< endl;
		}while( !inFile.is_open());

	}
		cout << "Input File: \"" << fileName << "\" opened correctly" << endl;

		do {
			// reads in data string, int and symbol
			inFile >> labelType >> size >> character;
		
			if (labelType == "upArrow") {

				fileName = labelType + "_" + to_string(size) + ".txt";
				cout << "Shape Created: " << fileName << endl;

				oFile.open(fileName);
				 // prints up arrow
		
				oFile << "Symbol: " << labelType << " " << "Size: " << size
				<< " " <<  "Character: " << character << endl;
				// if there is a odd number is goes even
				// and a message is given out
				if( size % 2 !=0) {
				       oFile << "Note: Up Arrow must have an even size." <<
				       "  ";
			
			       	       size++;

				oFile << "Shapes created with size: " << size << endl;
				}
					
			// header number count
				for (int i = 1, column = 1; i <=size; i++) {
				
					oFile << column;
					column++;
				if (column > 9) {
					column = 0;
				}
		       	}
			while (c+2 <= size){
				if ( e != 0 ) {
					oFile << " ";
				}
				if ( b == (size -c ) /2)
				{
					while(d<c)
					{
					oFile << character;
					d = d + 1;
					}
					d = 0;

					}
				if ( b != 0 && b % size == 0)
				{ 
					oFile << endl;
					b = 0;
					c = c +2;
				}
				e = e +1;
				b = b + 1;
			}

			c = 0;
			while (c < size -2)
			{
				if (e != 0 )
				{
					oFile << " ";
				}
				if ( b == (size - 2) / 2)
				{
					while ( d <2)
					{
						oFile << character;
					
						d = d +1;
					}
					d =0;
				}
				if ( b != 0 && b % size == 0)
				{
					oFile << endl;
					
					b =0 ;
				

					c = c +2;
				}

				e = e +1;
				
				b = b+1;
			}
		

				oFile.close();
		       	}
		
			 if (labelType == "rightArrow"){
				
				fileName = labelType + "_" + to_string(size) +".txt";
				cout << "Shape Created: " << fileName << endl;

				oFile.open(fileName);

		
				oFile << "Symbol: " << labelType << " " << "Size: " << size
				<< " " << "Character: " << character << endl;
				// if there is a odd number this will make it easier
				// as well as give a message of a new even number
				if(size %2 != 0) {
					oFile << "Note: Up Arrow must have an even size." <<	"  ";
					size++;
					oFile << "Shapes created with size: " << size << endl;
				}

				// numbered columns
				for ( int i = 1, column = 1; i <= size; i++) {
			
					oFile << column;
					column++;
				
					if (column > 9 ) { 
					column = 0;
				}
		       	}
			do{
				if (b !=0)
				{ 
					oFile << " ";
				}
				if (e == size/ 2)
				{
					do{
						oFile << character;
						d = d +1;
					}while ( d < e) ;
					d =0;
				}
				if (f == size) 
				{
					oFile << endl;
					e = e +1;
					f = 0;
				}
				f= f+1;
				b  = b +1;
			}while ( e <= (size/2) -1);
			e = e-1;
			
			do { 
			oFile << a;

			int  w = 0;	
			w=w +1;
			if(w == size)
			{
				oFile << endl;
				w = 0;
				
				p = p+1;
			}
			}while( p < 2);
			do
			{
				int h = 0;
				if(h !=0)
				{
					oFile << " ";
				}
				int s = 0;
				if (s == size){
					oFile << endl;
					e = e -1;
					s = 0;
				}
			}while (e > 0);
			oFile.close();
			}
			// this brings in the zero shape type 
			 if (labelType == "zero") {
				
				fileName = labelType + "_" + to_string(size) + ".txt.";
			
				cout << "Shape Created: " << fileName << endl;

				oFile.open(fileName);
				// this creates the header specifying shape size and character
			
				oFile << "Symbol: " << labelType  << "Size: " << size
				<< "Character: " << character << endl;
				// this creates the column numbers
			
				for ( int i = 1, column = 1; i <= size ; i++) {
				
					oFile << column;
					column++;
				
					if(column > 9) {
					column = 0;
				}
			}
				
			
				// creates the square and diagonal line
			for ( int i = 0; i < size; i ++)
			{
				for ( int j = 0; j < size; j++) 
				{
					if ( i == 0 || i == size - 1 || j == 0 || j == size - 1
						       	||  i == size || i + j == size - 1)
					       oFile << character;
					else
					oFile  << " ";
				}
			oFile << endl;
				
			
			
			oFile.close();
			
			}
		}
			 // creates output file
			if (( inFile.eof() == false) && (inFile.fail() == false)) {
			}
				else{
					if(inFile.eof()) {
						// at the end this is presented to tell
						// the user the program is done
				inFile.close();
				cout << "Finished processing input file" << endl;
				cout << "25 Shapes Created" << endl;
				return 0;
			}
				}
	
		}while (inFile.eof() == false);			

}
