 /*Name: Mateusz Bieda
Description:This program is mean to be a text main menu game that has 3 difficulties EASY, MEDIUM, and HARD. Each of these difficulties has
their own number range and length of the random number generated string. Then having a user guess that number with a limited amount of attempts,
the user ented password is only allowed to be in the number range and limit, anything else is given an error.
The program is meant to teach us and have us use functions, passing values by reference and value to other functions and calculations.
Including using rand and char static casting. Mainly this was to have us use and learn functions and their parameters. 
To add to the game also has a help menu that can pop up, and the ability to exit the game at any time. 

Input:The user has menu options for starting the game, getting a help message, and quitting at the start.
If the user chooses to start the game they will be given teh option of three difficulties as explained in the description of the game.
Each game mode has their number range and limit to the answers possible and the generated password
In addition there is an additional menu when the game difficulty is chosen, that notifies the user
they can ask for help or return to the main menu at any time.
WHEN a game mode is selected the user is prompted to start giving their guess at what the password is
this goes on until the attempts reach zero or the correct user guess matches the generated password


Output:
The program gives the user charts for menu options from the start having: 
1. Main: gives the next chart showing the difficulties and help and main if help or a 
return to the main menu is wanted
	*the difficulties lead to a game and a guess limit and range is given 
	*with the attempts, with each input the attempts decrement
	*at the end there are two possible outputs
		*if the user wins there is a code found successfully
		*or an abort message meaning you failed
2. If help is asked for a displayHelp functions is output to 
display what the game is and how it works
3. The last main menu option is quit and that ends the game


Algorithim:
Enter a string from main menu

Start game is entered through a string input such as easy, 

the values are passed in by value for min max, attempts, and d for amount of digits
generate passcode takes the numbers from the start game parameters and uses that in its password creation
and we use validate guess to check the users answer to the password that was generated
and then pass values to reportDifferences
if that works then the numbers passed by the user are cross checked
by the correct password and the results are given saying eitehr teh numberes space
by space are too high or low or correct

If all numbers match then the user is given a winning message and the 
game is sent back to the main menu

If the user runs out of attempts then a losing message is given on the other hand


WE NEED TO FIND OUT HOW TO PASS THE PASSCODE GENERATED INTO THE VALIDATE GUESS FUNCTION
AND HAVE A USER ENTER THEIR OWN PASSCODE TO COMPARE IT TO THE GENERATED ONE


*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//Function Prototypes
void foldCase(string&);
void setupGame();
void startGame(int d, int min, int max, int attempt);
void generatePasscode(string& distance, int d, int min, int max);
bool validateGuess(string guessPassing, int min, int max, uint distan, string& guessPass ); // unsigned int is a integer that cannot be negative
// there would not be any negative symobls or values inside of the string
// going into each thing comparing the ascii value using a loop

void reportDifference(string distance, string guessPass);
void displayHelp();

//-----------------------------------------------
//------------DO NOT ALTER MAIN------------------
//-----------------------------------------------
int main(int argc, char* argv[])
{
	//Check command line arguments for debug mode
	//Normal
	if(argc == 1)
	{
		srand(time(NULL));
	}
	else if(argc >= 2)
	{
		//Debug Mode
		string argument = argv[1];
		if(argc == 2 && argument == "debug")
		{
			srand(0);
		}
		//Usage Guidelines
		else
		{
			cout << "To start program in debug mode: \n";
			cout << argv[0] << " debug\n";
			return -1;
		}
	}
	    
	//Main Menu
	string choice = "";
	do
	{
		cout << "+--------------------+\n";
		cout << "| Main Menu          |\n";
		cout << "+--------------------+\n";
		cout << "| [Start] Simulation |\n";
		cout << "| [Help] Guide       |\n";
		cout << "| [Quit]             |\n";
		cout << "+--------------------+\n";
		cout << endl;
		
		do
		{
			cout << "Select a menu option: ";
			cin >> choice;
			foldCase(choice);
			if(choice == "start")
			{
				setupGame();
				break;
			}
			else if(choice == "help")
			{
				displayHelp();
				break;
			}
			else if(choice == "quit")
			{
				break;
			}
			else
			{
				cout << "Invalid menu selection.\n";
        cout<< endl;
			}
		}
		while(true);
	}
	while(choice != "quit");
	
	return 0;
}
//-----------------------------------------------
//------------DO NOT ALTER MAIN------------------
//-----------------------------------------------
/*
FUNCTION: foldCase
PARAMETER(S): a string that is passed by reference
RETURN: void
DESCRIPTION: this function goes through each character of the
string one a time and converts each character to lower case
*/

void foldCase(string& str)
{
	for(uint i = 0; i < str.length(); i++)
	{
		str[i] = tolower(str[i]); //reassigns character in str at position i to a lowercase equivalent
	}
	return;
}
void setupGame()
{
  /*
SET UP GAME FUNCTIONS
ONCE MAIN IS ENTERED FROM THE MAIN MENU THE FUNCTIONS GIVES A DIFFICULTY CHART
AND OTHER OPTIONS
TAKES IN A STRING FOR CERTAIN DIFFICULTIES
EACH DIFFICULTY THEN ENTERS START GAME WITH THE
PROPER VALUES
ALSO GIVES OPTION TO ENTER HELP OR RETUNR TO MAIN
MENU 
ALSO CHECKS FOR INVALID INPUTS

RETURN VOID
*/
	string choice;
    do{
    	cout << "+--------------------+\n";
		cout << "|  Select Difficulty |\n";
		cout << "+--------------------+\n";
		cout << "| [Easy]             |\n";
		cout << "| [Medium]           |\n";
		cout << "| [Hard]             |\n";
		cout << "+--------------------+\n";
        cout << "| [Help]             |\n";
        cout << "| [Main] Menu        |\n";
        cout << "+--------------------+\n";
		cout << endl;

        cout << "Select a menu option: ";
        
        
		// while the input choice is not any of the allowed optinos
		// how do I do that?
		cin >> choice;
        cout << endl;
        foldCase(choice);
        if(choice == "easy")
        {
		cout << "+--------------------+\n";
		cout << "| Additional Options |\n";
		cout << "+--------------------+\n";
        cout << "| [Help]             |\n";
        cout << "| [Main] Menu        |\n";
        cout << "+--------------------+\n";
		cout << endl;

			startGame(3, 1, 3, 10);
      return;
        }
        else if(choice == "medium")
        {
		cout << "+--------------------+\n";
		cout << "| Additional Options |\n";
		cout << "+--------------------+\n";
        cout << "| [Help]             |\n";
        cout << "| [Main] Menu        |\n";
        cout << "+--------------------+\n";
		cout << endl;

            startGame(4, 1, 5, 15);
            return;
        }
        else if(choice == "hard")
        {
		cout << "+--------------------+\n";
		cout << "| Additional Options |\n";
		cout << "+--------------------+\n";
        cout << "| [Help]             |\n";
        cout << "| [Main] Menu        |\n";
        cout << "+--------------------+\n";
		cout << endl;

			startGame(5,0,9,20);
      return;
        }
        else if(choice == "help")
        {
            displayHelp();
			break;  
        }
        else if(choice == "main")
        {
			//return;
            break;
			
        }
		else{
			cout << "Invalid menu selection" << endl;
    cout << endl;
		}
    }while(true);
    
}

void startGame(int d, int min, int max, int attempt){
/*
	VOID FUNCTION

THIS IS THE IMPORTANT PART OF THE PROGRAM AS IT COMBINES MOST OF THE FUNCTIONS
USING A WHILE LOOP TO KEEP THE GAME GOING UNTIL THE USER RUNS OUT OF ATTEMPTS
OR THE CORRECT ANSWER IS GIVEN
PASSING THE DISTANCE OF THE GAME DIFFICULTY PASSCODE CHECKING THAT TO USE THE 
CORRECT CODE SECTION
THEN ALL THE DIFFERENT DISTANCES HAVE THE SAME CODE BUT 
ARE ABLE TO HAVE DIFFERENT VALUES PASSED INTO THEM
wE CHECK IF THE USER GUESS IS VALID AND IF IT IS WE 
ENTER REPORT DIFFERENES TO CHECK THE USER GUESS WITH
THE ACTUAL PASSWORD AND THE USER GETS TO KNOW THE CORRECT 
AND TOO HIGH OR LOW VALUES
 THIS IS REPEATED UNTIL THE GAME IS OVER
*/

	string passCodeNums;
	string userGuess;
	
	//while(count != attempt){

	
	// for each passed in value give the ability to pass it into 
	// generate the passcode first
		// Do i make an empty string to pass into generate Passcode????
		// how will it be given back out??
	string pass;
	int attemptCount = attempt;
	int retryCount = 0;
	int minimum = min;
	int maximum = max;
	int dist = d;
	// distance has to be a string that has 
		generatePasscode(pass, dist, minimum, maximum);
	// atemppts reach end or if userPasscode is equal to the generatedPasscode
  while( userGuess != pass || attemptCount != 0){
		if( dist == 3)
		{
			cout << endl;
			cout << "Guess Code (3 Digits, " << min << " - " << max << ") ";
			cout << "[Attempts: " << attemptCount << "/" << attempt;
      cout << "]: ";
			cin >>userGuess;
      cout << endl;
      // THESE TWO GIVES THE CHANCE FOR THE USER
	// IF THE GAME IS RUNNING AT ANYTIME 
	// THE USER CAN ASK FOR HELP OR RETURN TO THE MAIN MENU
 
  foldCase(userGuess);
      if (userGuess == "help"){
       
        displayHelp();
        
        continue;
      }

      else if(userGuess == "main"){
        return;
      }
     
      // check for help or main// call fold case// if equals main return
      // else if == help display
    validateGuess(pass, minimum, maximum, dist,userGuess);
    
      // validate guess call then
      if(validateGuess(pass, minimum, maximum, dist, userGuess)){
        reportDifference(pass, userGuess );
	// IF EVERYTHING WORKS REPORT DIFFFERENCES SEES THE 
	//DIFFERENCES BETWEEN EACH NUMBER THAT COMES IN ORDER
	//HIGH OR LOW OR CORRECT AND THE ATTEMPTS GO DOWN
        attemptCount--;
      }
      else
      {
	// OTHERWISE IF FALSE THE GUESS WAS NOT VALILD
        cout << "Error. Invalid Code Format" << endl;
      }
      // then true then call report differences
      // into the correct guess and the necessary
			
			
		}

		if(dist == 4)
		{
				cout << endl;
        cout << endl;
			cout << "Guess Code (4 Digits, " << min << " - " << max << ") ";
			cout << "[Attempts: " << attemptCount << "/" << attempt;
      cout << "]: ";
			cin >>userGuess;
      cout << endl;
      
      foldCase(userGuess);
      if (userGuess == "help"){
        displayHelp();
        continue;
      }
      else if(userGuess == "main"){
        return;
      }
      // check for help or main// call fold case// if equals main return
      // else if == help display
    validateGuess(pass, minimum, maximum, dist,userGuess );
      // validate guess call then
      if(validateGuess(pass, minimum, maximum, dist, userGuess)){
        reportDifference(pass, userGuess );
        attemptCount--;
      }
      else
      {
        cout << "Error. Invalid Code Format" << endl;
      }
      // then true then call report differences
      // into the correct guess and the necessary
			
			
		}
		if(dist == 5)
		{
				cout << endl;
        cout << endl;
			cout << "Guess Code (5 Digits, " << min << " - " << max << ") ";
			cout << "[Attempts: " << attemptCount << "/" << attempt;
      cout << "]: ";
			cin >>userGuess;
      cout << endl;
      
      foldCase(userGuess);
      if (userGuess == "help"){
        displayHelp();
        continue;
      }
      else if(userGuess == "main"){
        return;
      }
      // check for help or main// call fold case// if equals main return
      // else if == help display
    validateGuess(pass, minimum, maximum, dist,userGuess );
      // validate guess call then
      if(validateGuess(pass, minimum, maximum, dist, userGuess)){
        reportDifference(pass, userGuess);
        attemptCount--;
      }
      else
      {
        cout << "Error. Invalid Code Format" << endl;
      }
      // then true then call report differences
      // into the correct guess and the necessary
		
			
		}
		retryCount ++;
    
    if(attemptCount == 0){
      cout << "Abort Mission: Imperial security" ;
      cout << " alerted to intrusion." << endl;
      cout << "Code was " << pass;
      cout << endl;
      cout << endl;
      
      return;
    }
    if(userGuess == pass ){
        cout << "Code found successfully: "<< pass;
        cout << endl;
        return;
    }
  }
	return;
	
	
	// then give out the game chart display and have the numbers display in a vertical fashion
	// after the user has input some value use validateGuess and reprint password chart
}

void generatePasscode(string& distance, int d, int min, int max)
{
    // FIND OUT HOW TO MAKE THE CIN FAIL IF THE USER ENTERS SOMETHING
    // THAT IS NOT THE PROPER LENGTH 
    //char arr[d];
	// VOID FUNCTION
	// GENERATES TEH RANDOM NUMBER USEING THE
	// VALUES PASSED THROUGH THE DIFFICULTY IN THE SETUP GAME
	// USING IN THE RANDOM GENERATING LIMITS
	// STORE PASSCODE INTO DISTANCE AND USE THAT TO COMPARE IN
	// IN EVERY INSTANCE THE CORRECT PASSCODE NEEDED
		string dist = "";
    string temp = "";
		srand(time(NULL));
		for (int i  = 0; i < d ; i++){
      temp = char('0' + rand() % max + min);
			dist = dist+ temp;
      // this has confused me so much it works and it dosen't rarely
      // I'm just going to leave this here :)
      
		}
    
		//dist.append(arr);
    distance = dist;
		
		return ;
}


bool validateGuess(string guessPassing, int min, int max, uint distan, string& guessPass )
{

	// after the users input is taken in and stored into a string
	// bring that here and we want to ensure that the input is allowed
	// if the input is valid, meaning that it is number string and NOTHING ELSE
	// IF IT IS SOMETHING ELSE THEN WE WILL SAY ERROR INVALID INPIT AND REPROMPT THE USER
	// IF THE INPUT IS VALID THEN WE ARE ABLE TO PASS IT PASSCODE[0]
	/*string guessPassing;
	cin >> guessPassing;
  */
 	
		
  // if the guess entered is not fitting the limits of the 
// then validate Guess is returned false and the guess is invalid
// if its true then we check the distance of the guess and in each
// check every individual number from left to right
  if(guessPass.length() != distan)
  {
    return false;
  }

 // if not false then it can for sure distan and length 
else{
  
	if (distan == 3)
	{
		if(guessPass.length() == 3){ // use Guess Pass
    // 
		for( int t = 0; t < guessPass.length(); t++){
			if (guessPass[t] < min + '0' || guessPass[t] > max + '0'){
				return false;
			}
		}
		}
		}

	else if ( distan == 4 )
	{
			if(guessPass.length() == 4){
		for( int t = 0; t < guessPass.length(); t++){
			if (guessPass[t] < min + '0' || guessPass[t] > max + '0'){
				return false;
			}
	}
			}
	}
	else if( distan == 5)
	{
			if(guessPass.length() == 5){
		for( int t = 0; t < guessPass.length(); t++){
			if (guessPass[t] < min + '0' || guessPass[t] > max + '0'){
				return false;
			}
	}
			}
	}
}
return true;
/*	else
	{
		cout << "Error Invalid Entry" << endl;
		return false;
	}
  */
	// 
  
}

void reportDifference(string distance, string guessPass )
{	
	int maxCount= 0;
       int minCount=0;
      int  totalCount=0;
	int gotRight = 0, tooHigh = 0, tooLow = 0;
	// report difference void function
// VOID FUNCTION
//	checks the length of the actaul password
// then we check the range and limits of the game mode
// then passing the values into a for loop for the proper 
//parameters, the for loop goes and checks every index of an array
//checking if too high or too low, or if the numbers match 
// it will increment the correct variable
//and then the final prompt is given with the values shown 
  
		if(distance.length() == 3)
		{
			// easy mode 
			
			maxCount = 3;
			minCount = 1;
			totalCount = 3;
      
	
		}
		else if(distance.length() == 4)
		{
			
			maxCount = 5;
			minCount = 1;
			totalCount = 4;
		
		}

		else if(distance.length() == 5)
		{
			
			maxCount = 9;
			minCount = 0;
			totalCount = 5;
		
		}
	
		if(1 == 1)
		{
		
				for(int u = 0; u < totalCount; u ++){
			
					if (distance[u] == guessPass[u])
					{
						gotRight++;
					}
					if(guessPass[u] > distance[u])
					{
						tooHigh++;
					}
					if(guessPass[u] < distance[u])
					{
						tooLow++;
					}
        
				}



		cout << '\n';
		cout << "+--------------------+\n";
        cout << "| Correct       | " << gotRight << "  |\n";
        cout << "| Too High      | " << tooHigh << "  |\n";
		cout << "| Too Low       | " << tooLow << "  |\n";
        cout << "+--------------------+\n";
		// create an individual for each individual 
		// inside report differences


		}
}

void displayHelp()
{
	// if the user asks for help
//by inputting help from the main menu or start menu
// this is given out, this is a void function
//
	cout << endl;
	
    cout << "This is to help you understand how the game works" << endl;
    cout << "The game if you [Start] the simulation will then prompt you " << endl;
    cout << "-----------------------------------------------------------------------------------";
    cout << endl;
    cout << "There are Three Difficulties" << endl;
    cout << "Ranging from Easy, Medium, and Hard; " << endl;
    cout << "-----------------------------------------------------------------------------------";
    cout << endl;
    cout << "Each difficulty will present you with a password to decrypt, with " << endl;
    cout << "the increasing difficulty you will get a harder password and also more attempts " << endl;
    cout << "to guess it, also the very first integer shows the length of the password on the " << endl;
    cout << "Guess Code word section, which appears above each chart when a password is entered" << endl;
    cout << "the next numbers show the range, and finally the attempts are show and kept track of "<< endl;
    cout << "Aside from the difficulties you can choose to ask for help " << endl;
    cout << "or you can go back to the menu, and if you enter [Quit] you " << endl;
    cout << "will exit the game. " << endl;
}

