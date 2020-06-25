
/*Name Mateusz Bieda
Description: This assignment is supposed to get us to learn and use file inputs, and 
create out going files, creating the files and storing info in them.
In addition using the enum function with rand and more. Also utilizing 
the ifstream and ofstream to close and open both of them

Input:The user must give a file for the program then give a output file name to later store all the 
information into, then once the file to take information from has been entered, and
when a destination file is set and made, we then are asking the user to take in 
the whole file or only parts of it 
if y is entered the whole input file is processed
if n is entered then teh question of how many inputs are desired is entered
once that is done the program begins processing and we move onto the output as the user does
not put any more commands or inputs to the program from there.

Output: once the program input is completed the program moves onto taking in the first and
last names from the file and sorting it through, by a first name title basis, if the 
character does not have a managerial prefix it is given a regular randomized droid type
with a randomized droid suffix

All the informaiton will be sorted neartly with a 4 digit space number system starting
at 0001 from the first person read in from a file, the first then last coming, with the name
of the droid class, that can be admin, maintenance, protocol, or astromech
This is all repeated until the end of the requested amount is reached

then there is a final tally of all droids, for both the y and n options
before the program itself ends there is a goodbye message given to teh user

after the program is completed using cat [outfile name.txt] you can view your organization and more

The Algorithim:
Define variables and enums, 
Prompt user for file name
Prompt for output file name
Ask if the whole input file is to be processed
If yes do all, if no do amount that is requested in the prompt after n is entered
The n prompt CAN ONLY take in positive numbers ABOVE 0
Then open infile and open outfile
oricess all data using first and last name with unique expressions in while loops
for y and n 
n will have a counter 
y has a eof check
in each one there is the same check for managerial names and more if there is not
a managerial prefix.
using rand to have a random selection of three droid classes than aren't administrative
once that is done there is a message that will be given for each respective y or n case
and the program closes the files iput and output, and program ends
*/

#include <cstdlib> //rand()
#include <ctime> //time(NULL)
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{


	// DECLARING ENUMS AND VARIABLES
	enum DROID_TYPES { ADMINISTRATIVE, MAINTENANCE, PROTOCOL, ASTROMECH  };
	enum ADMINISTRATIVE_TYPES { ET_74, XA_540, a3D_4X};
	enum MAINTENANCE_TYPES { F1_DX, EB_89, CB_2B, SA_45};
	enum PROTOCOL_TYPES {C3PO, L80, SA_5, RA_7 };
	enum ASTROMECH_TYPES { M4_Y6, BB_8, D3_S5, R2_D2};
	
	int maintCount = 0;
	int adminCount = 0;
	int protoCount = 0;
	int astroCount = 0;
	string droidType;
	string modelNo;
	int counter = 0;
	int recordAllFiles = 0;
	
	string administrative;
	string first, last;
	string inputFile, outputFile;
	ifstream infile;
	ofstream outfile;
	int droidChance;
	int droidChance2;
	
/*
TEST FIELD FOR CODE, MAY BE USED IN FUTURE IN CURRENT PROGRAM OR BE A DISCARDED IDEA

string droidMaint = "maintanence";
    string droidAstro = "astro";
    string droidProto = "proto";
    string droidAdmin = "Admin";
    int droidValues = rand() % 4 + 1;
    for ( int k = 0; k <= 16 ; k++)
    {
        droidValues = rand() % 4 + 1;

    if (droidValues == 1)
    {
        cout << droidMaint << endl;
        cout << droidValues << endl;
        
    }
     if(droidValues == 2)
    {
        cout << droidAstro << endl;
        cout << droidValues << endl;
        
    }
     if(droidValues == 3)
    {
        cout << droidProto << endl;
        cout << droidValues << endl;
        
    }
     if(droidValues == 4)
    {
        cout << droidAdmin << endl;
        cout << droidValues << endl;
        
    }
    }
USING THIS IDEA TO CHANGE BETWEEN NON-MANAGERIAL OPTIONS

*/
	///////////////////////////////////////
	//You may need to loop this portion if
	//input file does not exist
	while(infile.is_open() == false) {
	//read in input file name
	cout << "Enter file name to process: ";
	cin >> inputFile;
	//open input file stream
	infile.open(inputFile.c_str());
		
		if(infile.is_open() == false)
		{
			cout << "File " << inputFile << " did not open." << endl;
		}
	//////////////////////////////////////
	}
	
	//prompt for output file name
	cout << "Enter an output file: ";
	cin >> outputFile;
	srand(time(0));
	// USED SRAND TO set seed and use on rand for random droid class selection
	if (infile.is_open() == true){// checking if the file really opened
		cout << "Would you like to process all the records in the file? ";
		// user input for reading the whole input file, or a limited amount if n is chosen
		char recordInput;	 
		cout << "(y/n) ";
		cin >> recordInput;
		switch (recordInput) {
			case 'n':
			case 'N':
				cout << "Enter number of records to process: ";
				cin >> recordAllFiles;
				cout << endl;
				// the condition makes sure the input is only a positive # above 0
				while(cin.fail() || recordAllFiles < 1)
				{
					cin.clear();
					cin.ignore(200, '\n');

					cout << "XXXXXXXXXX Error-non numeric or negative value, try again" << endl;
					cout << endl;
					
					cout << "Enter number of records to process: ";
					cin >> recordAllFiles;
					cout << endl;
				}
				cout << "Maximum requested record count of " << recordAllFiles << " reached " << endl;
				cout <<  endl;
				// message that is given to the user that isnt inside of the out going file
				cout << "Thank you for using Rebel Alliance ";
				cout << "Computational Support" << endl;
				cout << "May the Force be with you!" << endl;
				cout << "    	    x				" << endl;
				cout << "      x    xxx    x		" << endl;
				cout << "     x    x x x    x		" << endl;
				cout << "    x      xxx      x		" << endl;
				cout << "   xx       x       xx		" << endl;
				cout << "  xxx      xxx      xxx	" << endl;
				cout << "  xxxx     xxx     xxxx	" << endl;
				cout << "  xxxxx    xxx   xxxxx		" << endl;
				cout << "   xxxxxxxxxxxxxxxxxxx		" << endl;
				cout << "    xxxxxxxxxxxxxxxxx		" << endl;
				cout << "     xxxxxxxxxxxxxxx		" << endl;
				cout << "       xxxxxxxxxxx			" << endl;
				outfile.open(outputFile.c_str());
    				outfile << "Number	First Name     Last Name     Droid Type      Model" << endl;
    			outfile << setw(60) << setfill('-') << "" << endl;
				while(counter != recordAllFiles)// specifically for the n case so that
				// the loop continues until the proper amount is reached
	    		{
					
					// takes in the names to check with the conditions
		    		infile>>first>>last;
    				
				//Droid Names
				//Admirals
				if(first == "Admiral" || first == "Captain" || first == "Commander" || first == "Darth" || first == "Emperor" || first == "Queen")
				{
					// if the first name works out this is given with a random
					// given suffix to the droid class
					droidType="administrative";
					adminCount++;
					droidChance=rand()%3+1;
					if(droidChance==1)
					{
						modelNo="ET_74";
					}
					
					if(droidChance==2)         
                    {
                        modelNo="XA_540";
                    }
					
					if(droidChance==3)         
                    {
                        modelNo="a3D_4X";
                    }	
				}
				else if( first != "Admiral" || first != "Captain" || first != "Commander" || first != "Darth" || first != "Emperor" || first != "Queen")
					{
						// if the first name doesnt work out this is given with a random
					// given suffix to the droid classes below that have a values assinged to the
					// proper classes
						droidChance2 = rand() % 3+1;
						if(droidChance2 == 1) {
							maintCount++;
					droidType="maintenance";
					// sets the string to use when being formatted in the file
					droidChance=rand()%4;
					//Droid Model
					if(droidChance==1)
					{
						modelNo="F1_DX";
                    }
                        
                    if(droidChance==2)
                    {       
                    modelNo="EB_89";
                    }
                    
                    if(droidChance==3)
                    {       
                    modelNo="CB_2B";
                    }
					
                    if(droidChance==4)
                    {
                    modelNo="SA_45";
                    }
							}

						else if(droidChance2 == 2){
							protoCount++;
							// also incrementing so the value is increasing for everytime it is landed on
                        droidType="protocol";
									

					droidChance=rand()% 4 + 1;
					//Droid Model
                    if(droidChance==1)
                    {
                    modelNo="C3PO";
                    }
					
                    if(droidChance==2)
                	{
                	modelNo="L80";
                    }
					
                    if(droidChance==3)
                    {
                    modelNo="SA_5";
                    }
					
                    if(droidChance==4)
                    {
                    modelNo="RA_7";
                    }
							}

						else if(droidChance2 == 3){
							
							astroCount++;
                            droidType="astromerch";
										// the same thing as before increase the amount it
										// was chosen through incrementation
										// and assign the string to astromech  
						//Droid Model
						droidChance=rand() % 4 + 1;
                        
						if(droidChance==1)
						{
                    	modelNo="M4_Y6";
                        }
					
                        if(droidChance==2)
                        {
                        modelNo="BB_8";
                        }
					
                        if(droidChance==3)
                        {
                        modelNo="D3_S5";
                        }
					
                        if(droidChance==4)
                        {
                        modelNo="R2_D2";
                        }
							}

					}


				/*

				THESE ARE DISCARDED IDEAS 
				THAT DID NOT WORK OUT

				droidChance=rand() % 4;
				
				//Maintence
				
				  if(droidChance==1 && first != "Admiral" || first != "Captain" || first != "Commander" || first != "Darth" || first != "Emperor" || first != "Queen" )
				{
					
				}
				//Protocol
				

			 else if(droidChance==2 && first != "Admiral" || first != "Captain" || first != "Commander" || first != "Darth" || first != "Emperor" || first != "Queen" )
                {
					cout << droidChance << "proto" << endl;
							
                }
				
				//Astromerch
			 else if(droidChance == 3 && first != "Admiral" || first != "Captain" || first != "Commander" || first != "Darth" || first != "Emperor" || first != "Queen" )
                    {
						
                    }
					*/
								counter++; // INCREASING THE COUNTER WITH each name being read in
								// this below sets the format properly
								outfile << setfill('0') << setw(4) << right << counter;
				outfile << setfill(' ') << "    ";
				outfile << left << setw(15) << first;
				outfile << left << setw(14) << last;
				outfile << left << setw(16) << droidType;
				outfile << left << modelNo << '\n';
			if(counter == recordAllFiles){
				// this is so the end message is not repeated 
				// but instead when the user set amount is reached then 
				// it will be put into the file
				outfile << endl;


				outfile << "**********************" << endl;
				outfile << "Assigned Droid Count" << endl;
				outfile << "**********************" << endl;
				outfile << "Astromech:       " << astroCount << endl;
				outfile << "Maintenance:     " << maintCount << endl;
				outfile << "Protocol:        " << protoCount << endl;
				outfile << "Administrative:  " << adminCount << endl;
				outfile << endl;
				
				outfile << "Total Droids Required     " << counter  << endl;
				
			}
	    		} 
				// closing both files since we do not want to leave them open
				infile.close();
				outfile.close();
				return 0 ;
			break;
// the y case will read in all and the while loop checks for the end of file
			case 'Y':
    		case 'y':
    		{
	    		cout<<"End of File detected, 182 records read"<<endl;
	    		cout<<endl;
	    		cout << "Thank you for using Rebel Alliance ";
				cout << "Computational Support" << endl;
				cout << "May the Force be with you!" << endl;
				cout << "    	    x				" << endl;
				cout << "      x    xxx    x		" << endl;
				cout << "     x    x x x    x		" << endl;
				cout << "    x      xxx      x		" << endl;
				cout << "   xx       x       xx		" << endl;
				cout << "  xxx      xxx      xxx	" << endl;
				cout << "  xxxx     xxx     xxxx	" << endl;
				cout << "  xxxxx    xxx   xxxxx		" << endl;
				cout << "   xxxxxxxxxxxxxxxxxxx		" << endl;
				cout << "    xxxxxxxxxxxxxxxxx		" << endl;
				cout << "     xxxxxxxxxxxxxxx		" << endl;
				cout << "       xxxxxxxxxxx			" << endl;
		    	//Out.txt data
				outfile.open(outputFile.c_str());
    				
	    			outfile << "Number	First Name     Last Name     Droid Type      Model" << endl;
    			outfile << setw(60) << setfill('-') << "" << endl;
				while(!infile.eof())
	    		{
				
					
		    		infile>>first>>last;
    				
				//Droid Names
				//Admirals
				if(first == "Admiral" || first == "Captain" || first == "Commander" || first == "Darth" || first == "Emperor" || first == "Queen")
				{
					// SAME CHECKS AS THE N CASE JUS THIS ONE GOES TILL EOF IS REACHED
					droidType="administrative";
					adminCount++;
					droidChance=rand()%3+1;
					if(droidChance==1)
					{
						modelNo="ET_74";
					}
					
					if(droidChance==2)         
                    {
                        modelNo="XA_540";
                    }
					
					if(droidChance==3)         
                    {
                        modelNo="a3D_4X";
                    }	
				}
				else if( first != "Admiral" || first != "Captain" || first != "Commander" || first != "Darth" || first != "Emperor" || first != "Queen")
					{
						droidChance2 = rand() % 3+1;
						if(droidChance2 == 1) {
							maintCount++;
					droidType="maintenance";
					
					droidChance=rand()%4;
					//Droid Model
					if(droidChance==1)
					{
						modelNo="F1_DX";
                    }
                        
                    if(droidChance==2)
                    {       
                    modelNo="EB_89";
                    }
                    
                    if(droidChance==3)
                    {       
                    modelNo="CB_2B";
                    }
					
                    if(droidChance==4)
                    {
                    modelNo="SA_45";
                    }
							}

						else if(droidChance2 == 2){
							protoCount++;
                        droidType="protocol";
									

					droidChance=rand()% 4 + 1;
					//Droid Model
                    if(droidChance==1)
                    {
                    modelNo="C3PO";
                    }
					
                    if(droidChance==2)
                	{
                	modelNo="L80";
                    }
					
                    if(droidChance==3)
                    {
                    modelNo="SA_5";
                    }
					
                    if(droidChance==4)
                    {
                    modelNo="RA_7";
                    }
							}

						else if(droidChance2 == 3){
							
							astroCount++;
                            droidType="astromerch";
										  
						//Droid Model
						droidChance=rand() % 4 + 1;
                        
						if(droidChance==1)
						{
                    	modelNo="M4_Y6";
                        }
					
                        if(droidChance==2)
                        {
                        modelNo="BB_8";
                        }
					
                        if(droidChance==3)
                        {
                        modelNo="D3_S5";
                        }
					
                        if(droidChance==4)
                        {
                        modelNo="R2_D2";
                        }
							}

					}
								counter++;
								outfile << setfill('0') << setw(4) << right << counter;
				outfile << setfill(' ') << "    ";
				outfile << left << setw(15) << first;
				outfile << left << setw(14) << last;
				outfile << left << setw(16) << droidType;
				outfile << left << modelNo << '\n';

				
			if(infile.eof()){
					// ONCE eof is reached this message is given with the total tally count
					// sent into the file
				
				outfile << endl;


				outfile << "**********************" << endl;
				outfile << "Assigned Droid Count" << endl;
				outfile << "**********************" << endl;
				outfile << "Astromech:       " << astroCount << endl;
				outfile << "Maintenance:     " << maintCount << endl;
				outfile << "Protocol:        " << protoCount << endl;
				outfile << "Administrative:  " << adminCount << endl;
				outfile << endl;
				outfile << endl;
				outfile << "Total Droids Required     " << counter -1  << endl;
				
				
			}
	    		} 
				infile.close();
				// closing both input and output files
	    		
				outfile.close();
    }
    break;
		// default case in case (haha) the user
		// chooses to enter something not y or n 
		default:
			cout << "Exiting... " << endl;
			return 0 ;
				
		}
	}
	
	//opens output file
	//does not need a loop since it will
	//create a new output file
	

	//reads in a line (reads in first and last name)
	//on each line

	//ask the user if they want to read in the entire file
	//or a portion of it

	//you want to make this a counter contolled loop if
	//the user does not want to read the whole file,
	//possibly add an && clause to the while condition
	
		//check the first name if it's a manager or
		//a regular person
	
	/*	if (first != "Admiral" || first != "Captain" || first != "Commander" || first != "Darth" || first != "Emperor" || first != "Queen")
		{


		}
		//if (first == )
		//if manager, just randomly choose a droid in
		//the administrative class
		if (first == "Admiral" || first == "Captain" || first == "Commander" || first == "Darth" || first == "Emperor" || first == "Queen")
		{
			ADMINISTRATIVE_TYPES dice2 = ADMINISTRATIVE_TYPES(rand() % 4 + 1);
			DROID_TYPES droid = ADMINISTRATIVE;
		}
		//otherise randomly choose a class and randomly
		//choose a droid within the class

		//maintain a counter
		*/
	}

	

