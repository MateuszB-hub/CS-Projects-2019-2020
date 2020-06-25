
/*Name: Mateusz Bieda
 *Description: This assignment is supposed to show how users can use the argument and 
 *execution commands to open up specific game modes in the program, for the programmer
 *this is to show us how to create specific game modes using command line argv and c, 
 *in addition to limiting numbers to a range using modulo, using while loops.
 *
 *Input: The user when executing the program has three choices, to  do
 *./a.out for a normal game mode
 *./a.out debug for a set sequence game mode that uses the exact same values
 *and 
 *./a.out silent that runs the game but does not print out the tables
 *only at the end does it do that, and the user does not need to click enter to 
 *get the rounds to come out
 *Output: When the user enters their game mode if normal
 *	-They press enter to get the rounds going, and there is a random generated rolls for 
 *	-dice that is given to them thru modulo randomization
 *	-hitting enter to get thru the rounds the body parts that are tied
 *	-to the numbers are given out showing what the user got from that roll
 *	-once the user gets the correct amounts a winning board is given and 
 *	-a game end screen
 *For the debug game
 *	-The user entered the debug executable, and the special title
 *	-debug is given and the same output as the normal game mode is given
 *	-BUT..... the roll nuumber is given with each body part so the its clearer
 *	-to the user the roll they got, in addition there is set value with the debug
 *	-mode, and the same end as the normal game mode is given when the same value
 *	-amounts are reached
 *For the silent game
 *	-The same output is given as normal with a randomized sequence
 *	-BUT..... There are no tables shown to the user and the enter clicks
 *	-are automatically entered and the game runs and completes immediately
 *	- the same end board is given, the outputs of what body part the user got do not
 *	- have the roll integer valeus like in the debug game mode
 *
 *The Algorithim:
 * Declare variables
 * Player 1 and 2 variabels with body part counts, round counts,
 * argc and v  for the game mode selections and using the int datatype for 
 * teh dice roll making two dice roll for 2 players
 * using a while loop to keep the game going until one of the players gets the 
 * body amounts correct values
 * using if statements to check for specific gamemodes and srand to have a random
 * number sequence or a set number sequesnce like for debug
 * usinga  switch statement and taking in a dice roll for player one and then within each
 * case I store the different game modes if selected and the opportunities for player 1 and all of
 * the chanced from the dice roll for player two that include duplicate outomces and parts that do not
 * come in the correct order
 * this is set for each case and each case has a something modified to make sure it checks the proper
 * dice rolls checks for player 1 and 2 for the approritate game mode
 * the end table can be used for all the game modes as it has a VERY specific if expression 
 * check that counts eitehr player 1 or player 2's body part counts
 * and gives the proper end game board output
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdlib> //rand()
#include <ctime> //time(NULL)
#include <iomanip>
using namespace std;
// librareis needed
int main(int args, char * argv[])
{
	string argument = "";
	char ch;
	int dice, dice2;
    /* declare variables for body parts and assign
     them int values
     if an int value is "hit" then that body part is 
     give and accounted for in game
     important note: body first, nothing else
     head before eyes
     leg, tail, wings, after body anytime
    */
   string body1 = "BODY";
   string head1 = "HEAD";
   string eye1 = "EYE";
   string wing1 = "WING";
   string leg1 = "LEG";
   string tail1 = "TAIL";
   // USE THESE WHEN A CERTAIN PART IS 
   // ROLLED IT WILL DISPLAY THE CORRECLATING
   // STRING
   //int playerNumberOne = 0;
   //int playerNumberTwo = 0;
   string player1 = "one";
   string player2 = "two";

   int  pl1bodyCount = 0;
   int  pl1headCount = 0;
   int  pl1wingCount = 0;
   int pl1legCount = 0;
   int pl1eyeCount = 0;
   int pl1tailCount  = 0;
	// these variables keep track of the plaers body part counts
   int  pl2bodyCount = 0;
   int  pl2headCount = 0;
   int pl2wingCount = 0;
   int pl2legCount = 0;
   int  pl2eyeCount = 0;
   int pl2tailCount  = 0;
   //playerNumberOne = pl1bodyCount + pl1eyeCount + pl1headCount + pl1legCount + pl1tailCount + pl1wingCount;
   //playerNumberTwo = pl2bodyCount + pl2eyeCount + pl2headCount + pl2legCount + pl2tailCount + pl2wingCount;
   int roundCount = 0;
    //HOW DO I GET IT TO GO BETWEEN THE TWO PLAYERS
    //I ASSUME GETTING SRAND FOR BOTH OF THEM
    //AND NEITHER WOULD GET THE SAME BODY PART CHOICE
    //I COULD MAKE A SEPARATE INVENTORY COUT STREAM LIKE I MADE THE EXAMPLE
    //FOR BUT 
   
    /*
    PSEUDO CODE SECTION
    dice == pl2bodyCount 
    have all the same checks from player 1 but create a duplicate set for player 2 within each case section
    run tests for each 

    for silent
    simply output what is given from dice with message and no board

    if(pl1bodyCount ==1){
                
                cout <<"Player " << player1 << " roll is duplicate "  << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
              
            }  
        while (pl1bodyCount != 1){
          
        if (dice == pl1body){
            
            cout << "Player " << player1 <<  " roll is " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            pl1bodyCount++;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
            
            
            
            }
            
            // increase the bodyCount, and if its anything else 
            // then wait until body gets hit first
            
        }

if(pl2bodyCount ==1){
                
                cout <<"Player " << player2 << " roll is duplicate "  << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
              
            }  
        while (pl2bodyCount != 1){
          
        if (dice == pl2body){
            
            cout << "Player " << player2 <<  " roll is " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            pl2bodyCount++;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
            
            
            
            }
            
            // increase the bodyCount, and if its anything else 
            // then wait until body gets hit first
            
        }








    */	//proper header
            cout << "************************" << endl;
            cout << "   Welcome to Can-cell    " << endl;
            cout << "************************" ;
	//checks to see if we passed in anything via command line argument
	if (args == 2)
	{// tracks the input from the execution line
		argument = argv[1]; //if we did, assign that to the string variable
	}

	//if we wish to run in debug mode, set the random number generator seed to 0
	//so the random numbers will be the same everytime you run your program
	if(argument == "silent") {
		cout <<  endl;
	cout << endl;		
	cout << "<<<<<<<<<<<Silent Mode Active>>>>>>>>>>>>>" << endl;
		}
	if (argument == "debug")
	{
		srand(0);
	cout << endl;
	cout << endl;	
       cout << "<<<<<<<<<<<Debug mode activated>>>>>>>>>>>" << endl;
        // thses two couts  above are used for their specific game mode
	}
	else
	{
		srand(time(NULL)); //if not debug mode, then make the random number generator different each time you run the program
	}

	while (true) //infinite loop
	{
		//if silent mode not enabled
		if (argument != "silent")
		{
             
			cin.get(ch); //wait for user to hit enter
      		}
		
		dice = rand() % 6 + 1; //genrates a random number between 1 to 6
         // this is for the second player to have their own 
        //rolls that do not match player 1's
        cout << "##############" << endl;
        cout << "Round #" << roundCount + 1 << endl;
       cout << endl; 
        
        // want to find a way to check if the dice is equal to the body int
        // and if its not then it has to skip it
        switch(dice){
		case 1:
        
        if (argument == "silent"){
            if(pl1bodyCount ==1){
                
                cout <<"Player " << player1 << " roll is duplicate " << body1 << endl;
            
         // for the silent game mode it goes like this for all the cases and I really hope its
         // ok that I did not do comments for all 5000+ Lines of code, its the same stuff just 
         // repeated and modified a bit to fit the code
         // very brute forced and I am sorry but i couldn't think of anoitehr way by the time the week time
         // for the assignment was already due    
            }
        else if (pl1bodyCount != 1){
            
            cout << "Player " << player1 <<  " roll is " << body1 << endl;
            
            pl1bodyCount++;
           
           
            
            
            }
          dice2 = rand()% 6 + 1;
          // rolls for the second player to have their input taken and used
        if (dice2 == 1){
         
         if(pl2bodyCount == 1){
                
                cout <<"Player " << player2 << " roll is duplicate " << body1 << endl;
            
              
            }  
         else if (pl2bodyCount != 1){
            
            cout << "Player " << player2 <<  " roll is " << body1 << endl;
           
            pl2bodyCount++;
            
            
            
            }
        
        }
        else if (dice2 == 2){
             if(pl2bodyCount == 0 )
            {
                 cout << "Player " << player2 << " roll is " << head1 << ", must have ";
                    cout << body1 << " first" << endl;
                   
             
            
            }
            if(pl2headCount ==0 && pl2bodyCount == 1) {
                    
                    pl2headCount++;
                    
                     cout << "Player " << player2 <<  " roll is " << head1 << endl;
            
              
             
            }
            else if(pl2headCount == 1 && pl2bodyCount == 1){
                
                cout << "Player " << player2 << " roll is duplicate " << head1<< endl;
               
           
            
            }
        }

        else if(dice2 == 3){
            if(pl2headCount ==1 && pl2eyeCount ==2){
                    
                    
                    
                     cout << "Player " << player2 <<  " roll is duplicate " << eye1 << endl;
            
              
                    
                }
                
            
        
            if (pl2headCount == 1)
            {
                if( pl2eyeCount <2) {
                    pl2eyeCount++;
                         
            cout << "Player " << player2 <<  " roll is " << eye1 << endl;
           
            
            

                }
            }
            if(pl2eyeCount == 0){
                
                if(pl2headCount < 1){
                    
                    cout << "Player " << player2 << " roll is " << eye1 << ", must have ";
                    cout << head1 << " first" << endl;
                    
           
            
                }
            }
        }
        else if(dice2 == 4){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << wing1;
            cout  << ", must have " << body1 << " first"<< endl;
         
        
        }
            else if(pl2bodyCount ==1){
                
                if(pl2wingCount == 4){
                
                cout << "Player " << player2 << " roll is duplicate " << tail1<< endl;
                
         
            
        }
                else if(pl2wingCount < 4){
                
                pl2wingCount++;
                 cout << "Player " << player2 <<  " roll is " << wing1 << endl;
           
             
            
                }
                     
            }
        }
        else if(dice2 == 5){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << leg1;
            cout  << ", must have " << body1 << " first"<< endl;
            
       
        
        }
            else if(pl2legCount <  6){
                
                if(pl2bodyCount ==1){
                
                pl2legCount++;
                 cout << "Player " << player2 <<  " roll is " << leg1 << endl;
            
           
            
                }  
                
            }
            
            else if(pl2legCount == 6){

                
                cout << "Player " << player2 << " roll is duplicate " << leg1 << endl;
                
          
            
            }
        }
        else if (dice2 == 6){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << tail1;
            cout  << ", must have " << body1 << " first"<< endl;
             
           
        
        }
            else if(pl2tailCount <1){
                
                if(pl2bodyCount ==1){
                
                pl2tailCount++;
                 cout << "Player " << player2 <<  " roll is " << tail1 << endl;
            
           
            
                }   
                
            }
            
            else if(pl2tailCount == 1){
                
                cout << "Player " <<player2 << " roll is duplicate " << tail1 << endl;
                
         
            }
        }
        
        
        break;
        }
        cout << "Hit enter to roll the die:" << endl;
        if(argument == "debug"){
       // if the user entered debug as an arugment my code would start here for teh firt
       // case if the dice roll permits and teh same goes for any case
       // first we start with the check for a body part the body must come first
       // if the body is not first then we tell that it is needed and the game goes onto teh 
       // 2nd players roll 
        if(pl1bodyCount ==1){
                
                cout <<"Player " << player1 << " roll is 1 duplicate " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
              
            }
        else if (pl1bodyCount != 1){
            
            cout << "Player " << player1 <<  " roll is 1 " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            pl1bodyCount++;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
            
            
            }
          dice2 = rand()% 6 + 1;
          // after getting past the first player check which is set for all body parts in all cases
          //we roll the 2nd players own dice and there are chekc FOR EVERYTHING 
          //THIS GOES FOR TEH NROMAL GAME MODE SILENT OR DEBUG IN EVERY CASE ALL TEH SAEM CHECKS FOR THE ROLLS
          //I hope its ok to have this comment serve for every player 2 instance in every game
          //so that I do not have to comment everything for teh 5000+ lines
        if (dice2 == 1){
         
         if(pl2bodyCount == 1){
                
                cout <<"Player " << player2 << " roll is 1 duplicate " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
           
            }  
         else if (pl2bodyCount != 1){
            
            cout << "Player " << player2 <<  " roll is 1 " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            pl2bodyCount++;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            
            }
        
        }
        else if (dice2 == 2){
             if(pl2bodyCount == 0 )
            {
                 cout << "Player " << player2 << " roll is 2 " << head1 << ", must have ";
                    cout << body1 << " first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
            }
            if(pl2headCount ==0 && pl2bodyCount == 1) {
                    
                    pl2headCount++;
                    
                     cout << "Player " << player2 <<  " roll is 2 " << head1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
              
             
            }
            else if(pl2headCount == 1 && pl2bodyCount == 1){
                
                cout << "Player " << player2 << " roll is 2 duplicate " << head1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }

        else if(dice2 == 3){
            if(pl2headCount ==1 && pl2eyeCount ==2){
                    
                    
                    
                     cout << "Player " << player2 <<  " roll is 3 duplicate " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
                }
                
            
        
            if (pl2headCount == 1)
            {
                if( pl2eyeCount <2) {
                    pl2eyeCount++;
                         
            cout << "Player " << player2 <<  " roll is 3 " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            

                }
            }
            if(pl2eyeCount == 0){
                
                if(pl2headCount < 1){
                    
                    cout << "Player " << player2 << " roll is 3 " << eye1 << ", must have ";
                    cout << "head first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
            }
        }
        else if(dice2 == 4){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is 4 " << wing1;
            cout  << ", must have body first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2bodyCount ==1){
                
                if(pl2wingCount == 4){
                
                cout << "Player " << player2 << " roll is 6 duplicate " << tail1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
        }
                else if(pl2wingCount < 4){
                
                pl2wingCount++;
                 cout << "Player " << player2 <<  " roll is 6 " << wing1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
                     
            }
        }
        else if(dice2 == 5){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is 5 " << leg1;
            cout  << ", must have body first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2legCount <  6){
                
                if(pl2bodyCount ==1){
                
                pl2legCount++;
                 cout << "Player " << player2 <<  " roll is 5 " << leg1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
            
                }  
                
            }
            
            else if(pl2legCount == 6){

                
                cout << "Player " << player2 << " roll is 5 duplicate " << leg1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
        else if (dice2 == 6){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is 6 " << tail1;
            cout  << ", must have body first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2tailCount <1){
                
                if(pl2bodyCount ==1){
                
                pl2tailCount++;
                 cout << "Player " << player2 <<  " roll is 6 " << tail1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
                }   
                
            }
            
            else if(pl2tailCount == 1){
                
                cout << "Player " <<player2 << " roll is 6 duplicate " << tail1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
        
        
        break;
        
        }
        if(pl1bodyCount ==1){
         // Now we gave reached the nromal game mode if the user did not enter silent or debug at teh start
         // the normla game plays out with teh checks for player 1 in whatever ase for the specific body part
         // this goes for all cases and teh plauer 2 has its own check for everything in everycase since its
         // has to be taht way stored
         // one gets checked then 2 is always check for everything in EVERY ONE       
                cout <<"Player " << player1 << " roll is duplicate " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
              
            }
        else if (pl1bodyCount != 1){
            
            cout << "Player " << player1 <<  " roll is " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            pl1bodyCount++;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
            
            
            
            }
          dice2 = rand()% 6 + 1;
          
        if (dice2 == 1){
         
         if(pl2bodyCount == 1){
                
                cout <<"Player " << player2 << " roll is duplicate " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               }  
         else if (pl2bodyCount != 1){
            
            cout << "Player " << player2 <<  " roll is " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            pl2bodyCount++;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
     
            
            
            }
        
        }
        else if (dice2 == 2){
             if(pl2bodyCount == 0 )
            {
                 cout << "Player " << player2 << " roll is 2 " << head1 << ", must have ";
                    cout << body1 << " first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
                      
            }
            if(pl2headCount ==0 && pl2bodyCount == 1) {
                    
                    pl2headCount++;
                    
                     cout << "Player " << player2 <<  " roll is 2 " << head1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            }
            else if(pl2headCount == 1 && pl2bodyCount == 1){
                
                cout << "Player " << player2 << " roll is 2 duplicate " << head1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }

        else if(dice2 == 3){
            if(pl2headCount ==1 && pl2eyeCount ==2){
                    
                    
                    
                     cout << "Player " << player2 <<  " roll is duplicate " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
              
                      }
                
            
        
            if (pl2headCount == 1)
            {
                if( pl2eyeCount <2) {
                    pl2eyeCount++;
                         
            cout << "Player " << player2 <<  " roll is " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            

                }
            }
            if(pl2eyeCount == 0){
                
                if(pl2headCount < 1){
                    
                    cout << "Player " << player2 << " roll is " << eye1 << ", must have ";
                    cout << head1 << " first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
            }
        }
        else if(dice2 == 4){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << wing1;
            cout  << ", must have " << body1 << " first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2bodyCount ==1){
                
                if(pl2wingCount == 4){
                
                cout << "Player " << player2 << " roll is duplicate " << tail1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
        }
                else if(pl2wingCount < 4){
                
                pl2wingCount++;
                 cout << "Player " << player2 <<  " roll is " << wing1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
                     
            }
        }
        else if(dice2 == 5){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << leg1;
            cout  << ", must have " << body1 << " first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2legCount <  6){
                
                if(pl2bodyCount ==1){
                
                pl2legCount++;
                 cout << "Player " << player2 <<  " roll is " << leg1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
            
                }  
                
            }
            
            else if(pl2legCount == 6){

                
                cout << "Player " << player2 << " roll is duplicate " << leg1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
        else if (dice2 == 6){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << tail1;
            cout  << ", must have " << body1 << " first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2tailCount <1){
                
                if(pl2bodyCount ==1){
                
                pl2tailCount++;
                 cout << "Player " << player2 <<  " roll is " << tail1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
                }   
                
            }
            
            else if(pl2tailCount == 1){
                
                cout << "Player " <<player2 << " roll is duplicate " << tail1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
        
        
        break;
        













        case 2:
        
        if(argument == "silent"){
            if(pl1bodyCount == 0 )
            {
                 cout << "Player " << player1 << " roll is " << head1 << ", must have ";
                    cout << body1 << " first" << endl;
         
            
            }
            else if
            (pl1bodyCount == 1){
            if(pl1headCount ==0) {
                    
                    pl1headCount++;
                    
                     cout << "Player " << player1 <<  " roll is " << head1 << endl;
           
             
            }
            else if(pl1headCount == 1){
                
                cout << "Player " << player1 << " roll is duplicate " << head1<< endl;
                
   
            
            }
            }
            dice2 = rand()% 6 + 1;
            
        if (dice2 == 1){
         
         if(pl2bodyCount == 1){
                
                cout <<"Player " << player2 << " roll is duplicate " << body1 << endl;
    
            }  
         else if (pl2bodyCount != 1){
            
            cout << "Player " << player2 <<  " roll is " << body1 << endl;
            
            pl2bodyCount++;
            
   
            
            
            }
        
        }
        else if (dice2 == 2){
             if(pl2headCount ==0) {
                    
                    pl2headCount++;
                    
                     cout << "Player " << player2 <<  " roll is " << head1 << endl;
            
  
             
            }
            else if(pl2headCount == 1){
                
                cout << "Player " << player2 << " roll is duplicate " << head1<< endl;
                
         
            
            }
        }

        else if(dice2 == 3){
            if(pl2headCount ==1 && pl2eyeCount ==2){
                    
                    
                    
                     cout << "Player " << player2 <<  " roll is duplicate " << eye1 << endl;
           
         
                }
                
            
        
            if (pl2headCount == 1)
            {
                if( pl2eyeCount <2) {
                    pl2eyeCount++;
                         
            cout << "Player " << player2 <<  " roll is " << eye1 << endl;
            
            
      
            

                }
            }
            if(pl2eyeCount == 0){
                
                if(pl2headCount < 1){
                    
                    cout << "Player " << player2 << " roll is " << eye1 << ", must have ";
                    cout << head1 << " first" << endl;
        
                }
            }
        }
        else if(dice2 == 4){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << wing1;
            cout  << ", must have " << body1 << " first"<< endl;
         
        }
            else if(pl2bodyCount ==1){
                
                if(pl2wingCount == 4){
                
                cout << "Player " << player2 << " roll is duplicate " << tail1<< endl;
               
           
            
        }
                else if(pl2wingCount < 4){
                
                pl2wingCount++;
                 cout << "Player " << player2 <<  " roll is " << wing1 << endl;
            
        
                }
                     
            }
        }
        else if(dice2 == 5){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << leg1;
            cout  << ", must have " << body1 << " first"<< endl;
            
      
        
        }
            else if(pl2legCount <  6){
                
                if(pl2bodyCount ==1){
                
                pl2legCount++;
                 cout << "Player " << player2 <<  " roll is " << leg1 << endl;
            
           
            
                }  
                
            }
            
            else if(pl2legCount == 6){

                
                cout << "Player " << player2 << " roll is duplicate " << leg1 << endl;
                
         
            }
        }
        else if (dice2 == 6){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << tail1;
            cout  << ", must have " << body1 << " first"<< endl;
             
           
        }
            else if(pl2tailCount <1){
                
                if(pl2bodyCount ==1){
                
                pl2tailCount++;
                 cout << "Player " << player2 <<  " roll is " << tail1 << endl;
            
          
            
                }   
                
            }
            
            else if(pl2tailCount == 1){
                
                cout << "Player " <<player2 << " roll is duplicate " << tail1 << endl;
              
         
            }
        }
        break;

        }
        cout << "Hit enter to roll the die:" << endl;
        if( argument == "debug"){
            if(pl1bodyCount == 0 )
            {
                 cout << "Player " << player1 << " roll is 2 " << head1 << ", must have ";
                    cout << body1 << " first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
               
            
            }
            if(pl1headCount ==0 && pl1bodyCount == 1) {
                    
                    pl1headCount++;
                    
                     cout << "Player " << player1 <<  " roll is 2 " << head1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
              
             
            }
            else if(pl1headCount == 1 && pl1bodyCount == 1){
                
                cout << "Player " << player1 << " roll is 2 duplicate " << head1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
            
            
            }
            dice2 = rand()% 6 + 1;
            
        if (dice2 == 1){
         
         if(pl2bodyCount == 1){
                
                cout <<"Player " << player2 << " roll is 1 duplicate " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
              
            }  
         else if (pl2bodyCount != 1){
            
            cout << "Player " << player2 <<  " roll is 1 " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            pl2bodyCount++;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            
            }
        
        }
        else if (dice2 == 2){
             if(pl2bodyCount == 0 )
            {
                 cout << "Player " << player2 << " roll is 2 " << head1 << ", must have ";
                    cout << body1 << " first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
            }
            if(pl2headCount ==0 && pl2bodyCount == 1) {
                    
                    pl2headCount++;
                    
                     cout << "Player " << player2 <<  " roll is 2 " << head1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
              
             
            }
            else if(pl2headCount == 1 && pl2bodyCount == 1){
                
                cout << "Player " << player2 << " roll is 2 duplicate " << head1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }

        else if(dice2 == 3){
            if(pl2headCount ==1 && pl2eyeCount ==2){
                    
                    
                    
                     cout << "Player " << player2 <<  " roll is 3 duplicate " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
                    
                }
                
            
        
            if (pl2headCount == 1)
            {
                if( pl2eyeCount <2) {
                    pl2eyeCount++;
                         
            cout << "Player " << player2 <<  " roll is 3 " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            

                }
            }
            if(pl2eyeCount == 0){
                
                if(pl2headCount < 1){
                    
                    cout << "Player " << player2 << " roll is 3 " << eye1 << ", must have ";
                    cout << "head first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
            }
        }
        else if(dice2 == 4){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is 4" << wing1;
            cout  << ", must have body first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2bodyCount ==1){
                
                if(pl2wingCount == 4){
                
                cout << "Player " << player2 << " roll is 6 duplicate " << tail1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
        }
                else if(pl2wingCount < 4){
                
                pl2wingCount++;
                 cout << "Player " << player2 <<  " roll is 4 " << wing1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
                     
            }
        }
        else if(dice2 == 5){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is 5 " << leg1;
            cout  << ", must have body first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2legCount <  6){
                
                if(pl2bodyCount ==1){
                
                pl2legCount++;
                 cout << "Player " << player2 <<  " roll is 5 " << leg1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
            
                }  
                
            }
            
            else if(pl2legCount == 6){

                
                cout << "Player " << player2 << " roll is 5 duplicate " << leg1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
        else if (dice2 == 6){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is 6 " << tail1;
            cout  << ", must have body first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2tailCount <1){
                
                if(pl2bodyCount ==1){
                
                pl2tailCount++;
                 cout << "Player " << player2 <<  " roll is 6 " << tail1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
                }   
                
            }
            
            else if(pl2tailCount == 1){
                
                cout << "Player " <<player2 << " roll is 6 duplicate " << tail1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
        break;
        }
            if(pl1bodyCount == 0 )
            {
                 cout << "Player " << player1 << " roll is " << head1 << ", must have ";
                    cout << body1 << " first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
               
            
            }
            else if
            (pl1bodyCount == 1){
            if(pl1headCount ==0) {
                    
                    pl1headCount++;
                    
                     cout << "Player " << player1 <<  " roll is " << head1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
              
             
            }
            else if(pl1headCount == 1){
                
                cout << "Player " << player1 << " roll is duplicate " << head1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
            
            
            }
            }
            dice2 = rand()% 6 + 1;
            
        if (dice2 == 1){
         
         if(pl2bodyCount == 1){
                
                cout <<"Player " << player2 << " roll is duplicate " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
              
            }  
         else if (pl2bodyCount != 1){
            
            cout << "Player " << player2 <<  " roll is " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            pl2bodyCount++;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            
            }
        
        }
        else if (dice2 == 2){
             if(pl2headCount ==0) {
                    
                    pl2headCount++;
                    
                     cout << "Player " << player2 <<  " roll is " << head1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
              
             
            }
            else if(pl2headCount == 1){
                
                cout << "Player " << player2 << " roll is duplicate " << head1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }

        else if(dice2 == 3){
            if(pl2headCount ==1 && pl2eyeCount ==2){
                    
                    
                    
                     cout << "Player " << player2 <<  " roll is duplicate " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
                    
                }
                
            
        
            if (pl2headCount == 1)
            {
                if( pl2eyeCount <2) {
                    pl2eyeCount++;
                         
            cout << "Player " << player2 <<  " roll is " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            

                }
            }
            if(pl2eyeCount == 0){
                
                if(pl2headCount < 1){
                    
                    cout << "Player " << player2 << " roll is " << eye1 << ", must have ";
                    cout << head1 << " first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
            }
        }
        else if(dice2 == 4){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << wing1;
            cout  << ", must have " << body1 << " first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2bodyCount ==1){
                
                if(pl2wingCount == 4){
                
                cout << "Player " << player2 << " roll is duplicate " << tail1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
        }
                else if(pl2wingCount < 4){
                
                pl2wingCount++;
                 cout << "Player " << player2 <<  " roll is " << wing1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
                     
            }
        }
        else if(dice2 == 5){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << leg1;
            cout  << ", must have " << body1 << " first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2legCount <  6){
                
                if(pl2bodyCount ==1){
                
                pl2legCount++;
                 cout << "Player " << player2 <<  " roll is " << leg1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
            
                }  
                
            }
            
            else if(pl2legCount == 6){

                
                cout << "Player " << player2 << " roll is duplicate " << leg1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
        else if (dice2 == 6){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << tail1;
            cout  << ", must have " << body1 << " first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2tailCount <1){
                
                if(pl2bodyCount ==1){
                
                pl2tailCount++;
                 cout << "Player " << player2 <<  " roll is " << tail1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
                }   
                
            }
            
            else if(pl2tailCount == 1){
                
                cout << "Player " <<player2 << " roll is duplicate " << tail1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
        break;

















        case 3:
        if (argument == "silent"){
                if(pl1headCount ==1 && pl1eyeCount ==2){
                    
                    
                    
                     cout << "Player " << player1 <<  " roll is duplicate " << eye1 << endl;
           
                }
                
            
        
            if (pl1headCount == 1)
            {
                if( pl1eyeCount <2) {
                    pl1eyeCount++;
                         
            cout << "Player " << player1 <<  " roll is " << eye1 << endl;
    
            

                }
            }
            else if(pl1eyeCount == 0){
                
                if(pl1headCount < 1){
                    
                    cout << "Player " << player1 << " roll is " << eye1 << ", must have ";
                    cout << head1 << " first" << endl;
        
            
                }
            }
            
        dice2 = rand()% 6 + 1;
        
        if (dice2 == 1){
         
         if(pl2bodyCount == 1){
                
                cout <<"Player " << player2 << " roll is duplicate " << body1 << endl;
       
            }  
         else if (pl2bodyCount != 1){
            
            cout << "Player " << player2 <<  " roll is " << body1 << endl;
            
            pl2bodyCount++;
        
      
            
            
            }
        
        }
        else if (dice2 == 2){
             if(pl2headCount ==0) {
                    
                    pl2headCount++;
                    
                     cout << "Player " << player2 <<  " roll is " << head1 << endl;

             
            }
            else if(pl2headCount == 1){
                
                cout << "Player " << player2 << " roll is duplicate "  << head1<< endl;
          
            
            }
        }

        else if(dice2 == 3){
            if(pl2headCount ==1 && pl2eyeCount ==2){
                   
                    
                     cout << "Player " << player2 <<  " roll is duplicate " << eye1 << endl;
            
           
                }
                
            
        
            if (pl2headCount == 1)
            {
                if( pl2eyeCount <2) {
                    pl2eyeCount++;
                         
            cout << "Player " << player2 <<  " roll is " << eye1 << endl;
           
    

                }
            }
            if(pl2eyeCount == 0){
                
                if(pl2headCount < 1){
                    
                    cout << "Player " << player2 << " roll is " << eye1 << ", must have ";
                    cout << head1 << " first" << endl;
         
            
                }
            }
        }
        else if(dice2 == 4){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << wing1;
            cout  << ", must have " << body1 << " first"<< endl;
         
        }
            else if(pl2bodyCount ==1){
                
                if(pl2wingCount == 4){
                
                cout << "Player " << player2 << " roll is duplicate " << tail1<< endl;
             
        
            
        }
                else if(pl2wingCount < 4){
                
                pl2wingCount++;
                 cout << "Player " << player2 <<  " roll is " << wing1 << endl;
          
         
                }
                     
            }
        }
        else if(dice2 == 5){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << leg1;
            cout  << ", must have " << body1 << " first"<< endl;
            
      
        
        }
            else if(pl2legCount <  6){
                
                if(pl2bodyCount ==1){
                
                pl2legCount++;
                 cout << "Player " << player2 <<  " roll is " << leg1 << endl;
           
          
            
                }  
                
            }
            
            else if(pl2legCount == 6){

                
                cout << "Player " << player2 << " roll is duplicate " << leg1 << endl;
                cout << "----------------------" << endl;
           
        
            }
        }
        else if (dice2 == 6){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << tail1;
            cout  << ", must have " << body1 << " first"<< endl;
           
         
        
        }
            else if(pl2tailCount <1){
                
                if(pl2bodyCount ==1){
                
                pl2tailCount++;
                 cout << "Player " << player2 <<  " roll is " << tail1 << endl;
          
       
            
                }   
                
            }
            
            else if(pl2tailCount == 1){
                
                cout << "Player " <<player2 << " roll is duplicate " << tail1 << endl;
           
     
            
            }
        }
                
            
        break;

















        }
        cout << "Hit enter to roll the die:" << endl;
        if(argument == "debug") {
             if(pl1headCount ==1 && pl1eyeCount ==2){
                    
                    
                    
                     cout << "Player " << player1 <<  " roll is 3 duplicate " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
               
                    
                }
                
            
        
            if (pl1headCount == 1)
            {
                if( pl1eyeCount <2) {
                    pl1eyeCount++;
                         
            cout << "Player " << player1 <<  " roll is 3 " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
            
            

                }
            }
            else if(pl1eyeCount == 0){
                
                if(pl1headCount < 1){
                    
                    cout << "Player " << player1 << " roll is 3 " << eye1 << ", must have ";
                    cout << "head first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
               
            
                }
            }
                
           
        dice2 = rand()% 6 + 1;
        
        if (dice2 == 1){
         
         if(pl2bodyCount == 1){
                
                cout <<"Player " << player2 << " roll is 1 duplicate " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
              
            }  
         else if (pl2bodyCount != 1){
            
            cout << "Player " << player2 <<  " roll is 1 " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            pl2bodyCount++;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            
            }
        
        }
        else if (dice2 == 2){
             if(pl2bodyCount == 0 )
            {
                 cout << "Player " << player2 << " roll is 2 " << head1 << ", must have ";
                    cout << body1 << " first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
            }
            if(pl2headCount ==0 && pl2bodyCount == 1) {
                    
                    pl2headCount++;
                    
                     cout << "Player " << player2 <<  " roll is 2 " << head1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
              
             
            }
            else if(pl2headCount == 1 && pl2bodyCount == 1){
                
                cout << "Player " << player2 << " roll is 2 duplicate " << head1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }

        else if(dice2 == 3){
            if(pl2headCount ==1 && pl2eyeCount ==2){
                    
                    
                    
                     cout << "Player " << player2 <<  " roll is 2 duplicate " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
                    
                }
                
            
        
            if (pl2headCount == 1)
            {
                if( pl2eyeCount <2) {
                    pl2eyeCount++;
                         
            cout << "Player " << player2 <<  " roll is 3 " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            

                }
            }
            if(pl2eyeCount == 0){
                
                if(pl2headCount < 1){
                    
                    cout << "Player " << player2 << " roll is 3 " << eye1 << ", must have ";
                    cout << "head first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
            }
        }
        else if(dice2 == 4){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is 4 " << wing1;
            cout  << ", must have body first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2bodyCount ==1){
                
                if(pl2wingCount == 4){
                
                cout << "Player " << player2 << " roll is 6 duplicate " << tail1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
        }
                else if(pl2wingCount < 4){
                
                pl2wingCount++;
                 cout << "Player " << player2 <<  " roll is 4 " << wing1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
                     
            }
        }
        else if(dice2 == 5){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is 5 " << leg1;
            cout  << ", must have body first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2legCount <  6){
                
                if(pl2bodyCount ==1){
                
                pl2legCount++;
                 cout << "Player " << player2 <<  " roll is 5 " << leg1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
            
                }  
                
            }
            
            else if(pl2legCount == 6){

                
                cout << "Player " << player2 << " roll is 5 duplicate " << leg1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
        else if (dice2 == 6){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is 6 " << tail1;
            cout  << ", must have body first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2tailCount <1){
                
                if(pl2bodyCount ==1){
                
                pl2tailCount++;
                 cout << "Player " << player2 <<  " roll is 6 " << tail1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
                }   
                
            }
            
            else if(pl2tailCount == 1){
                
                cout << "Player " <<player2 << " roll is 6 duplicate " << tail1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
                
            
        break;
        }
        if(pl1headCount ==1 && pl1eyeCount ==2){
                    
                    
                    
                     cout << "Player " << player1 <<  " roll is duplicate " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
               
                    
                }
                
            
        
            if (pl1headCount == 1)
            {
                if( pl1eyeCount <2) {
                    pl1eyeCount++;
                         
            cout << "Player " << player1 <<  " roll is " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
            
            

                }
            }
            else if(pl1eyeCount == 0){
                
                if(pl1headCount < 1){
                    
                    cout << "Player " << player1 << " roll is " << eye1 << ", must have ";
                    cout << head1 << " first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
               
            
                }
            }
                
            /*else if(eyeCount != 2){
                        
            cout << "Player " << player1 <<  " roll is " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            eyeCount++;
            cout << "Body:" << setw(5) << bodyCount << endl;
            cout << "Head:" << setw(5) << headCount << endl;
            cout << "Eye:" << setw(5) << eyeCount<< endl;
            cout << "Wing:" << setw(5) << wingCount << endl;
            cout << "Leg:" << setw(5) << legCount << endl;
            cout << "Tail:" << setw(5) << tailCount << endl;
            
            

                    }*/

             /*   else if(headCount == 1 && eyeCount < 2){
                        
            cout << "Player " << player1 <<  " roll is " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            eyeCount++;
            cout << "Body:" << setw(5) << bodyCount << endl;
            cout << "Head:" << setw(5) << headCount << endl;
            cout << "Eye:" << setw(5) << eyeCount<< endl;
            cout << "Wing:" << setw(5) << wingCount << endl;
            cout << "Leg:" << setw(5) << legCount << endl;
            cout << "Tail:" << setw(5) << tailCount << endl;
            
            cout << "xcheckhead" << endl;
                    }*/
        dice2 = rand()% 6 + 1;
        
        if (dice2 == 1){
         
         if(pl2bodyCount == 1){
                
                cout <<"Player " << player2 << " roll is duplicate " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
              
            }  
         else if (pl2bodyCount != 1){
            
            cout << "Player " << player2 <<  " roll is " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            pl2bodyCount++;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            
            }
        
        }
        else if (dice2 == 2){
             if(pl2headCount ==0) {
                    
                    pl2headCount++;
                    
                     cout << "Player " << player2 <<  " roll is " << head1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
              
             
            }
            else if(pl2headCount == 1){
                
                cout << "Player " << player2 << " roll is duplicate "  << head1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }

        else if(dice2 == 3){
            if(pl2headCount ==1 && pl2eyeCount ==2){
                    
                    
                    
                     cout << "Player " << player2 <<  " roll is duplicate " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
                    
                }
                
            
        
            if (pl2headCount == 1)
            {
                if( pl2eyeCount <2) {
                    pl2eyeCount++;
                         
            cout << "Player " << player2 <<  " roll is " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            

                }
            }
            if(pl2eyeCount == 0){
                
                if(pl2headCount < 1){
                    
                    cout << "Player " << player2 << " roll is " << eye1 << ", must have ";
                    cout << head1 << " first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
            }
        }
        else if(dice2 == 4){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << wing1;
            cout  << ", must have " << body1 << " first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2bodyCount ==1){
                
                if(pl2wingCount == 4){
                
                cout << "Player " << player2 << " roll is duplicate " << tail1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
        }
                else if(pl2wingCount < 4){
                
                pl2wingCount++;
                 cout << "Player " << player2 <<  " roll is " << wing1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
                     
            }
        }
        else if(dice2 == 5){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << leg1;
            cout  << ", must have " << body1 << " first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2legCount <  6){
                
                if(pl2bodyCount ==1){
                
                pl2legCount++;
                 cout << "Player " << player2 <<  " roll is " << leg1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
            
                }  
                
            }
            
            else if(pl2legCount == 6){

                
                cout << "Player " << player2 << " roll is duplicate " << leg1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
        else if (dice2 == 6){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << tail1;
            cout  << ", must have " << body1 << " first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2tailCount <1){
                
                if(pl2bodyCount ==1){
                
                pl2tailCount++;
                 cout << "Player " << player2 <<  " roll is " << tail1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
                }   
                
            }
            
            else if(pl2tailCount == 1){
                
                cout << "Player " <<player2 << " roll is duplicate " << tail1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
                
            
        break;

















        case 4:
        
        if (argument == "silent")
        {
            if(pl1bodyCount ==0){
            cout << "Player " << player1 << " roll is " << wing1;
            cout  << ", must have " << body1 <<  " first"<< endl;
            
        
        }
            else if(pl1bodyCount ==1){
                
                if(pl1wingCount == 4){
                
                cout << "Player " << player1 << " roll is duplicate " << wing1<< endl;
        
            
        }
                if(pl1wingCount < 4){
                
                pl1wingCount++;
                 cout << "Player " << player1 <<  " roll is " << wing1 << endl;
        
            
                }
                
                
            
        
             
            }
            dice2 = rand()% 6 + 1;
        if (dice2 == 1){
         
         if(pl2bodyCount == 1){
                
                cout <<"Player " << player2 << " roll is duplicate " << body1 << endl;
           
      
            }  
         else if (pl2bodyCount != 1){
            
            cout << "Player " << player2 <<  " roll is " << body1 << endl;
            
            pl2bodyCount++;
            
         
            
            
            }
        
        }
        else if (dice2 == 2){
             if(pl2headCount ==0) {
                    
                    pl2headCount++;
                    
                     cout << "Player " << player2 <<  " roll is " << head1 << endl;
         
             
            }
            else if(pl2headCount == 1){
                
                cout << "Player " << player2 << " roll is duplicate " << head1<< endl;
                
            
            }
        }

        else if(dice2 == 3){
            if(pl2headCount ==1 && pl2eyeCount ==2){
                    
                    
                    
                     cout << "Player " << player2 <<  " roll is duplicate " << eye1 << endl;
        
                }
                
            
        
            if (pl2headCount == 1)
            {
                if( pl2eyeCount <2) {
                    pl2eyeCount++;
                         
            cout << "Player " << player2 <<  " roll is " << eye1 << endl;
            
            
            

                }
            }
            if(pl2eyeCount == 0){
                
                if(pl2headCount < 1){
                    
                    cout << "Player " << player2 << " roll is " << eye1 << ", must have ";
                    cout << head1 << " first" << endl;
          
            
                }
            }
        }
        else if(dice == 4){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << wing1;
            cout  << ", must have " << body1 << " first"<< endl;
            
     
        
        }
            else if(pl2bodyCount ==1){
                
                if(pl2wingCount == 4){
                
                cout << "Player " << player2 << " roll is duplicate "  << wing1<< endl;
            
     
            
        }
               else if(pl2wingCount < 4){
                
                pl2wingCount++;
                 cout << "Player " << player2 <<  " roll is " << wing1 << endl;
           
    
            
                }
                     
            }
        }
        else if(dice2 == 5){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << leg1;
            cout  << ", must have " << body1 << " first"<< endl;
         
         
        
        }
            else if(pl2legCount <  6){
                
                if(pl2bodyCount ==1){
                
                pl2legCount++;
                 cout << "Player " << player2 <<  " roll is " << leg1 << endl;
        
            
                }  
                
            }
            
            else if(pl2legCount == 6){

                
                cout << "Player " << player2 << " roll is duplicate " << leg1 << endl;
             
           
            
            }
        }
        else if (dice2 == 6){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << tail1;
            cout  << ", must have " << body1 << " first"<< endl;
            
      
        
        }
            else if(pl2tailCount <1){
                
                if(pl2bodyCount ==1){
                
                pl2tailCount++;
                 cout << "Player " << player2 <<  " roll is " << tail1 << endl;
            
           
            
                }   
                
            }
            
            else if(pl2tailCount == 1){
                
                cout << "Player " <<player2 << " roll is duplicate " << tail1 << endl;
           
         
            
            }
        }
        break;
        
























        }
        cout << "Hit enter to roll the die:" << endl;
        if (argument == "debug"){
            if(pl1bodyCount ==0){
            cout << "Player " << player1 << " roll is 4 " << wing1;
            cout  << ", must have body first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
             
        
        }
            else if(pl1bodyCount ==1){
                
                if(pl1wingCount == 4){
                
                cout << "Player " << player1 << " roll is 4 duplicate " << wing1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
            
            
        }
                if(pl1wingCount < 4){
                
                pl1wingCount++;
                 cout << "Player " << player1 <<  " roll is 4 " << wing1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
               
            
                }
                
                
            
        
             
            }
            dice2 = rand()% 6 + 1;
        if (dice2 == 1){
         
         if(pl2bodyCount == 1){
                
                cout <<"Player " << player2 << " roll is 1 duplicate " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
              
            }  
         else if (pl2bodyCount != 1){
            
            cout << "Player " << player2 <<  " roll is 1 " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            pl2bodyCount++;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            
            }
        
        }
        else if (dice2 == 2){
             if(pl2bodyCount == 0 )
            {
                 cout << "Player " << player2 << " roll is 2 " << head1 << ", must have ";
                    cout << body1 << " first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
            }
            if(pl2headCount ==0 && pl2bodyCount == 1) {
                    
                    pl2headCount++;
                    
                     cout << "Player " << player2 <<  " roll is 2 " << head1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
              
             
            }
            else if(pl2headCount == 1 && pl2bodyCount == 1){
                
                cout << "Player " << player2 << " roll is 2 duplicate " << head1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }

        else if(dice2 == 3){
            if(pl2headCount ==1 && pl2eyeCount ==2){
                    
                    
                    
                     cout << "Player " << player2 <<  " roll is 3 duplicate " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
                           }
                
            
        
            if (pl2headCount == 1)
            {
                if( pl2eyeCount <2) {
                    pl2eyeCount++;
                         
            cout << "Player " << player2 <<  " roll is 3 " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            

                }
            }
            if(pl2eyeCount == 0){
                
                if(pl2headCount < 1){
                    
                    cout << "Player " << player2 << " roll is 3 " << eye1 << ", must have ";
                    cout << "head first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
            }
        }
        else if(dice == 4){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is 4" << wing1;
            cout  << ", must have body first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2bodyCount ==1){
                
                if(pl2wingCount == 4){
                
                cout << "Player " << player2 << " roll is 4 duplicate "  << wing1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
        }
               else if(pl2wingCount < 4){
                
                pl2wingCount++;
                 cout << "Player " << player2 <<  " roll is 4 " << wing1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
                     
            }
        }
        else if(dice2 == 5){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is 5 " << leg1;
            cout  << ", must have body first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2legCount <  6){
                
                if(pl2bodyCount ==1){
                
                pl2legCount++;
                 cout << "Player " << player2 <<  " roll is 5 " << leg1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
            
                }  
                
            }
            
            else if(pl2legCount == 6){

                
                cout << "Player " << player2 << " roll is 5 duplicate " << leg1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
        else if (dice2 == 6){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is 6 " << tail1;
            cout  << ", must have body first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2tailCount <1){
                
                if(pl2bodyCount ==1){
                
                pl2tailCount++;
                 cout << "Player " << player2 <<  " roll is 6 " << tail1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
                }   
                
            }
            
            else if(pl2tailCount == 1){
                
                cout << "Player " <<player2 << " roll is 6 duplicate " << tail1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
        break;
        }
        if(pl1bodyCount ==0){
            cout << "Player " << player1 << " roll is " << wing1;
            cout  << ", must have body first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
             
        
        }
            else if(pl1bodyCount ==1){
                
                if(pl1wingCount == 4){
                
                cout << "Player " << player1 << " roll is duplicate " << wing1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
            
            
        }
                if(pl1wingCount < 4){
                
                pl1wingCount++;
                 cout << "Player " << player1 <<  " roll is " << wing1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
               
            
                }
                
                
            
        
             
            }
            dice2 = rand()% 6 + 1;
        if (dice2 == 1){
         
         if(pl2bodyCount == 1){
                
                cout <<"Player " << player2 << " roll is duplicate " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
              
            }  
         else if (pl2bodyCount != 1){
            
            cout << "Player " << player2 <<  " roll is " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            pl2bodyCount++;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            
            }
        
        }
        else if (dice2 == 2){
             if(pl2headCount ==0) {
                    
                    pl2headCount++;
                    
                     cout << "Player " << player2 <<  " roll is " << head1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
              
             
            }
            else if(pl2headCount == 1){
                
                cout << "Player " << player2 << " roll is duplicate " << head1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }

        else if(dice2 == 3){
            if(pl2headCount ==1 && pl2eyeCount ==2){
                    
                    
                    
                     cout << "Player " << player2 <<  " roll is duplicate " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
                         }
                
            
        
            if (pl2headCount == 1)
            {
                if( pl2eyeCount <2) {
                    pl2eyeCount++;
                         
            cout << "Player " << player2 <<  " roll is " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            

                }
            }
            if(pl2eyeCount == 0){
                
                if(pl2headCount < 1){
                    
                    cout << "Player " << player2 << " roll is " << eye1 << ", must have ";
                    cout << head1 << " first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
            }
        }
        else if(dice == 4){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << wing1;
            cout  << ", must have " << body1 << " first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2bodyCount ==1){
                
                if(pl2wingCount == 4){
                
                cout << "Player " << player2 << " roll is duplicate "  << wing1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
        }
               else if(pl2wingCount < 4){
                
                pl2wingCount++;
                 cout << "Player " << player2 <<  " roll is " << wing1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
                     
            }
        }
        else if(dice2 == 5){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << leg1;
            cout  << ", must have " << body1 << " first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2legCount <  6){
                
                if(pl2bodyCount ==1){
                
                pl2legCount++;
                 cout << "Player " << player2 <<  " roll is " << leg1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
            
                }  
                
            }
            
            else if(pl2legCount == 6){

                
                cout << "Player " << player2 << " roll is duplicate " << leg1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
        else if (dice2 == 6){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << tail1;
            cout  << ", must have " << body1 << " first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2tailCount <1){
                
                if(pl2bodyCount ==1){
                
                pl2tailCount++;
                 cout << "Player " << player2 <<  " roll is " << tail1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
                }   
                
            }
            
            else if(pl2tailCount == 1){
                
                cout << "Player " <<player2 << " roll is duplicate " << tail1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
        break;
        
























        case 5:
        
        if(argument == "silent"){
            if(pl1bodyCount ==0){
            cout << "Player " << player1 << " roll is " << leg1;
            cout  << ", must have " << body1 << " first"<< endl;
            
        
        }
            else if(pl1legCount <  6){
                
                if(pl1bodyCount ==1){
                
                pl1legCount++;
                 cout << "Player " << player1 <<  " roll is " << leg1 << endl;
            
            
                }  
                
            }
            
            else if(pl1legCount == 6){

                
                cout << "Player " << player1 << " roll is duplicate " << leg1 << endl;
             
            
            }
            dice2 = rand()% 6 + 1;
           
        if (dice2 == 1){
         
         if(pl2bodyCount == 1){
                
                cout <<"Player " << player2 << " roll is duplicate " << body1 << endl;
             
            }  
         else if (pl2bodyCount != 1){
            
            cout << "Player " << player2 <<  " roll is " << body1 << endl;
            
            pl2bodyCount++;
          
            
            
            }
        
        }
        else if (dice2 == 2){
             if(pl2headCount ==0) {
                    
                    pl2headCount++;
                    
                     cout << "Player " << player2 <<  " roll is " << head1 << endl;
            
             
            }
            else if(pl2headCount == 1){
                
                cout << "Player " << player2 << " roll is duplicate "  << head1<< endl;
           
            
            }
        }

        else if(dice2 == 3){
            if(pl2headCount ==1 && pl2eyeCount ==2){
                    
                    
                    
                     cout << "Player " << player2 <<  " roll is duplicate " << eye1 << endl;
       
                }
                
            
        
            if (pl2headCount == 1)
            {
                if( pl2eyeCount <2) {
                    pl2eyeCount++;
                         
            cout << "Player " << player2 <<  " roll is " << eye1 << endl;
         
            

                }
            }
            if(pl2eyeCount == 0){
                
                if(pl2headCount < 1){
                    
                    cout << "Player " << player2 << " roll is " << eye1 << ", must have ";
                    cout << head1 << " first" << endl;
            
            
                }
            }
        }
        else if(dice2 == 4){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << wing1;
            cout  << ", must have " << body1 << " first"<< endl;
         
        
        }
            else if(pl2bodyCount ==1){
                
                if(pl2wingCount == 4){
                
                cout << "Player " << player2 << " roll is duplicate "  << wing1<< endl;
       
            
        }
                else if(pl2wingCount < 4){
                
                pl2wingCount++;
                 cout << "Player " << player2 <<  " roll is " << wing1 << endl;
       
            
                }
                     
            }
        }
        else if(dice2 == 5){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << leg1;
            cout  << ", must have " << body1 << " first"<< endl;
         
        
        }
            else if(pl2bodyCount == 1){
                
                if(pl2legCount <  6){
                
                pl2legCount++;
                cout << "Player " << player2 << " roll is " << leg1 << endl;
            
                }  
                
            }
            
            else if(pl2legCount == 6){

                
                cout << "Player " << player2 << " roll is duplicate " << leg1 << endl;
            
            
            }
        }
        else if (dice2 == 6){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << tail1;
            cout  << ", must have " << body1 << " first"<< endl;
           
        
        }
            else if(pl2tailCount <1){
                
                if(pl2bodyCount ==1){
                
                pl2tailCount++;
                 
            
                }   
                
            }
            
            else if(pl2tailCount == 1){
                
                cout << "Player " <<player2 << " roll is duplicate " << tail1 << endl;
              
            
            }
        }
        break;


























        }
        cout << "Hit enter to roll the die:" << endl;
        if (argument == "debug"){
            if(pl1bodyCount ==0){
            cout << "Player " << player1 << " roll is 5 " << leg1;
            cout  << ", must have body first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
             
        
        }
            else if(pl1legCount <  6){
                
                if(pl1bodyCount ==1){
                
                pl1legCount++;
                 cout << "Player " << player1 <<  " roll is 5 " << leg1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
             
            
                }  
                
            }
            
            else if(pl1legCount == 6){

                
                cout << "Player " << player1 << " roll is 5 duplicate " << leg1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
            
            
            }
                
                
            
        
             
            
            dice2 = rand()% 6 + 1;
        if (dice2 == 1){
         
         if(pl2bodyCount == 1){
                
                cout <<"Player " << player2 << " roll is 1 duplicate " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
              
            }  
         else if (pl2bodyCount != 1){
            
            cout << "Player " << player2 <<  " roll is 1 " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            pl2bodyCount++;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            
            }
        
        }
        else if (dice2 == 2){
             if(pl2bodyCount == 0 )
            {
                 cout << "Player " << player2 << " roll is 2 " << head1 << ", must have ";
                    cout << body1 << " first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
            }
            if(pl2headCount ==0 && pl2bodyCount == 1) {
                    
                    pl2headCount++;
                    
                     cout << "Player " << player2 <<  " roll is 2 " << head1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
              
             
            }
            else if(pl2headCount == 1 && pl2bodyCount == 1){
                
                cout << "Player " << player2 << " roll is 2 duplicate " << head1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }

        else if(dice2 == 3){
            if(pl2headCount ==1 && pl2eyeCount ==2){
                    
                    
                    
                     cout << "Player " << player2 <<  " roll is 3 duplicate " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
                           }
                
            
        
            if (pl2headCount == 1)
            {
                if( pl2eyeCount <2) {
                    pl2eyeCount++;
                         
            cout << "Player " << player2 <<  " roll is 3 " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            

                }
            }
            if(pl2eyeCount == 0){
                
                if(pl2headCount < 1){
                    
                    cout << "Player " << player2 << " roll is 3 " << eye1 << ", must have ";
                    cout << "head first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
            }
        }
        else if(dice2 == 4){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is 4" << wing1;
            cout  << ", must have body first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2bodyCount ==1){
                
                if(pl2wingCount == 4){
                
                cout << "Player " << player2 << " roll is 4 duplicate "  << wing1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
        }
               else if(pl2wingCount < 4){
                
                pl2wingCount++;
                 cout << "Player " << player2 <<  " roll is 4 " << wing1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
                     
            }
        }
        else if(dice2 == 5){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is 5 " << leg1;
            cout  << ", must have body first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2legCount <  6){
                
                if(pl2bodyCount ==1){
                
                pl2legCount++;
                 cout << "Player " << player2 <<  " roll is 5 " << leg1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
            
                }  
                
            }
            
            else if(pl2legCount == 6){

                
                cout << "Player " << player2 << " roll is 5 duplicate " << leg1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
        else if (dice2 == 6){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is 6 " << tail1;
            cout  << ", must have body first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2tailCount <1){
                
                if(pl2bodyCount ==1){
                
                pl2tailCount++;
                 cout << "Player " << player2 <<  " roll is 6 " << tail1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
                }   
                
            }
            
            else if(pl2tailCount == 1){
                
                cout << "Player " <<player2 << " roll is 6 duplicate " << tail1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
        break;
        }
           
        if(pl1bodyCount ==0){
            cout << "Player " << player1 << " roll is " << leg1;
            cout  << ", must have " << body1 << " first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
             
        
        }
            else if(pl1legCount <  6){
                
                if(pl1bodyCount ==1){
                
                pl1legCount++;
                 cout << "Player " << player1 <<  " roll is " << leg1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
             
            
                }  
                
            }
            
            else if(pl1legCount == 6){

                
                cout << "Player " << player1 << " roll is duplicate " << leg1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
            
            
            }
            dice2 = rand()% 6 + 1;
            
        if (dice2 == 1){
         
         if(pl2bodyCount == 1){
                
                cout <<"Player " << player2 << " roll is duplicate " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
              
            }  
         else if (pl2bodyCount != 1){
            
            cout << "Player " << player2 <<  " roll is " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            pl2bodyCount++;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            
            }
        
        }
        else if (dice2 == 2){
             if(pl2headCount ==0) {
                    
                    pl2headCount++;
                    
                     cout << "Player " << player2 <<  " roll is " << head1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
              
             
            }
            else if(pl2headCount == 1){
                
                cout << "Player " << player2 << " roll is duplicate "  << head1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }

        else if(dice2 == 3){
            if(pl2headCount ==1 && pl2eyeCount ==2){
                    
                    
                    
                     cout << "Player " << player2 <<  " roll is duplicate " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
                          }
                
            
        
            if (pl2headCount == 1)
            {
                if( pl2eyeCount <2) {
                    pl2eyeCount++;
                         
            cout << "Player " << player2 <<  " roll is " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            

                }
            }
            if(pl2eyeCount == 0){
                
                if(pl2headCount < 1){
                    
                    cout << "Player " << player2 << " roll is " << eye1 << ", must have ";
                    cout << head1 << " first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
            }
        }
        else if(dice2 == 4){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << wing1;
            cout  << ", must have " << body1 << " first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2bodyCount ==1){
                
                if(pl2wingCount == 4){
                
                cout << "Player " << player2 << " roll is duplicate "  << wing1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
        }
                else if(pl2wingCount < 4){
                
                pl2wingCount++;
                 cout << "Player " << player2 <<  " roll is " << wing1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
                     
            }
        }
        else if(dice2 == 5){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << leg1;
            cout  << ", must have " << body1 << " first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2legCount <  6){
                
                if(pl2bodyCount ==1){
                
                pl2legCount++;
                 cout << "Player " << player2 <<  " roll is " << leg1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
            
                }  
                
            }
            
            else if(pl2legCount == 6){

                
                cout << "Player " << player2 << " roll is duplicate " << leg1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
        else if (dice2 == 6){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << tail1;
            cout  << ", must have " << body1 << " first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2tailCount <1){
                
                if(pl2bodyCount ==1){
                
                pl2tailCount++;
                 cout << "Player " << player2 <<  " roll is " << tail1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
                }   
                
            }
            
            else if(pl2tailCount == 1){
                
                cout << "Player " <<player2 << " roll is duplicate " << tail1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
        break;


























        case 6: 
        
        if(argument == "silent"){
            if(pl1bodyCount ==0){
            cout << "Player " << player1 << " roll is " << tail1;
            cout  << ", must have " << body1 << " first"<< endl;
         
        
        }
            else if(pl1tailCount <1){
                
                if(pl1bodyCount ==1){
                
                pl1tailCount++;
                 cout << "Player " << player1 <<  " roll is " << tail1 << endl;
           
            
                }   
                
            }
            
            else if(pl1tailCount == 1){
                
                cout << "Player " <<player1 << " roll is duplicate " << tail1 << endl;
             
            
            }
            
            dice2 = rand()% 6 + 1;
            
        if (dice2 == 1){
         
         if(pl2bodyCount == 1){
                
                cout <<"Player " << player2 << " roll is duplicate " << body1 << endl;
            
            }  
         else if (pl2bodyCount != 1){
            
            cout << "Player " << player2 <<  " roll is " << body1 << endl;
           
            pl2bodyCount++;
           
            
            
            }
        
        }
        else if (dice2 == 2){
             if(pl2headCount ==0) {
                    
                    pl2headCount++;
                    
                     cout << "Player " << player2 <<  " roll is " << head1 << endl;
            
             
            }
            else if(pl2headCount == 1){
                
                cout << "Player " << player2 << " roll is duplicate "  << head1<< endl;
            
            
            }
        }

        else if(dice2 == 3){
            if(pl2headCount ==1 && pl2eyeCount ==2){
                    
                    
                    
                     cout << "Player " << player2 <<  " roll is duplicate " << eye1 << endl;
            
                    
                }
                
            
        
            if (pl2headCount == 1)
            {
                if( pl2eyeCount <2) {
                    pl2eyeCount++;
                         
            cout << "Player " << player2 <<  " roll is " << eye1 << endl;
           
            

                }
            }
            if(pl2eyeCount == 0){
                
                if(pl2headCount < 1){
                    
                    cout << "Player " << player2 << " roll is " << eye1 << ", must have ";
                    cout << head1 << " first" << endl;
                 
            
                }
            }
        }
        else if(dice2 == 4){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << wing1;
            cout  << ", must have " << body1 << " first"<< endl;
           
        
        }
            else if(pl2bodyCount ==1){
                
                if(pl2wingCount == 4){
                
                cout << "Player " << player2 << " roll is duplicate "  << wing1<< endl;
           
            
        }
                else if(pl2wingCount < 4){
                
                pl2wingCount++;
                 cout << "Player " << player2 <<  " roll is " << wing1 << endl;
            
            
                }
                     
            }
        }
        else if(dice2 == 5){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << leg1;
            cout  << ", must have " << body1 << " first"<< endl;
         
        
        }
            else if(pl2legCount <  6){
                
                if(pl2bodyCount ==1){
                
                pl2legCount++;
                 cout << "Player " << player2 <<  " roll is " << leg1 << endl;
          
            
                }  
                
            }
            
            else if(pl2legCount == 6){

                
                cout << "Player " << player2 << " roll is duplicate " << leg1 << endl;
         
            
            }
        }
        else if (dice2 == 6){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << tail1;
            cout  << ", must have " << body1 << " first"<< endl;
         
        
        }
            else if(pl2tailCount <1){
                
                if(pl2bodyCount ==1){
                
                pl2tailCount++;
                 cout << "Player " << player2 <<  " roll is " << tail1 << endl;
            
            
                }   
                
            }
            
            else if(pl2tailCount == 1){
                
                cout << "Player " <<player2 << " roll is duplicate " << tail1 << endl;
           
            
            }
        }
        break;
        
        }
        cout << "Hit enter to roll the die:" << endl;
        if (argument == "debug"){
             if(pl1bodyCount ==0){
            cout << "Player " << player1 << " roll is 6 " << tail1;
            cout  << ", must have body first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
             
        
        }
            else if(pl1tailCount <1){
                
                if(pl1bodyCount ==1){
                
                pl1tailCount++;
                 cout << "Player " << player1 <<  " roll is 6 " << tail1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
            
            
                }   
                
            }
            
            else if(pl1tailCount == 1){
                
                cout << "Player " <<player1 << " roll is 6 duplicate " << tail1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
            
            
            }
            dice2 = rand()% 6 + 1;
            
            
        if (dice2 == 1){
         
         if(pl2bodyCount == 1){
                
                cout <<"Player " << player2 << " roll is 1 duplicate " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
              
            }  
         else if (pl2bodyCount != 1){
            
            cout << "Player " << player2 <<  " roll is 1 " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            pl2bodyCount++;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            
            }
        
        }
        else if (dice2 == 2){
             if(pl2bodyCount == 0 )
            {
                 cout << "Player " << player2 << " roll is 2 " << head1 << ", must have ";
                    cout << body1 << " first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
            }
            if(pl2headCount ==0 && pl2bodyCount == 1) {
                    
                    pl2headCount++;
                    
                     cout << "Player " << player2 <<  " roll is 2 " << head1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
              
             
            }
            else if(pl2headCount == 1 && pl2bodyCount == 1){
                
                cout << "Player " << player2 << " roll is 2 duplicate " << head1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }

        else if(dice2 == 3){
            if(pl2headCount ==1 && pl2eyeCount ==2){
                    
                    
                    
                     cout << "Player " << player2 <<  " roll is 3 duplicate " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
                    
                }
                
            
        
            if (pl2headCount == 1)
            {
                if( pl2eyeCount <2) {
                    pl2eyeCount++;
                         
            cout << "Player " << player2 <<  " roll is 3 " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            

                }
            }
            if(pl2eyeCount == 0){
                
                if(pl2headCount < 1){
                    
                    cout << "Player " << player2 << " roll is 3 " << eye1 << ", must have ";
                    cout << "head first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
            }
        }
        else if(dice2 == 4){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is 4" << wing1;
            cout  << ", must have body first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2bodyCount ==1){
                
                if(pl2wingCount == 4){
                
                cout << "Player " << player2 << " roll is 4 duplicate "  << wing1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
        }
               else if(pl2wingCount < 4){
                
                pl2wingCount++;
                 cout << "Player " << player2 <<  " roll is 4 " << wing1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
                     
            }
        }
        else if(dice2 == 5){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is 5 " << leg1;
            cout  << ", must have body first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2legCount <  6){
                
                if(pl2bodyCount ==1){
                
                pl2legCount++;
                 cout << "Player " << player2 <<  " roll is 5 " << leg1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
            
                }  
                
            }
            
            else if(pl2legCount == 6){

                
                cout << "Player " << player2 << " roll is 5 duplicate " << leg1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
        else if (dice2 == 6){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is 6 " << tail1;
            cout  << ", must have body first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2tailCount <1){
                
                if(pl2bodyCount ==1){
                
                pl2tailCount++;
                 cout << "Player " << player2 <<  " roll is 6 " << tail1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
                }   
                
            }
            
            else if(pl2tailCount == 1){
                
                cout << "Player " <<player2 << " roll is 6 duplicate " << tail1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
        break;
        }
        
        if(pl1bodyCount ==0){
            cout << "Player " << player1 << " roll is " << tail1;
            cout  << ", must have " << body1 << " first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
             
        
        }
            else if(pl1tailCount <1){
                
                if(pl1bodyCount ==1){
                
                pl1tailCount++;
                 cout << "Player " << player1 <<  " roll is " << tail1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
            
            
                }   
                
            }
            
            else if(pl1tailCount == 1){
                
                cout << "Player " <<player1 << " roll is duplicate " << tail1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 1 Inventory" << endl;
            cout << "Body:" << setw(5) << pl1bodyCount << endl;
            cout << "Head:" << setw(5) << pl1headCount << endl;
            cout << "Eye:" << setw(6) << pl1eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl1wingCount << endl;
            cout << "Leg:" << setw(6) << pl1legCount << endl;
            cout << "Tail:" << setw(5) << pl1tailCount << endl;
            
            
            }
            
            dice2 = rand()% 6 + 1;
            
        if (dice2 == 1){
         
         if(pl2bodyCount == 1){
                
                cout <<"Player " << player2 << " roll is duplicate " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
              
            }  
         else if (pl2bodyCount != 1){
            
            cout << "Player " << player2 <<  " roll is " << body1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            pl2bodyCount++;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            
            }
        
        }
        else if (dice2 == 2){
             if(pl2headCount ==0) {
                    
                    pl2headCount++;
                    
                     cout << "Player " << player2 <<  " roll is " << head1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
              
             
            }
            else if(pl2headCount == 1){
                
                cout << "Player " << player2 << " roll is duplicate "  << head1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }

        else if(dice2 == 3){
            if(pl2headCount ==1 && pl2eyeCount ==2){
                    
                    
                    
                     cout << "Player " << player2 <<  " roll is duplicate " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
                           }
                
            
        
            if (pl2headCount == 1)
            {
                if( pl2eyeCount <2) {
                    pl2eyeCount++;
                         
            cout << "Player " << player2 <<  " roll is " << eye1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            

                }
            }
            if(pl2eyeCount == 0){
                
                if(pl2headCount < 1){
                    
                    cout << "Player " << player2 << " roll is " << eye1 << ", must have ";
                    cout << head1 << " first" << endl;
                    cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
            }
        }
        else if(dice2 == 4){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << wing1;
            cout  << ", must have " << body1 << " first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2bodyCount ==1){
                
                if(pl2wingCount == 4){
                
                cout << "Player " << player2 << " roll is duplicate "  << wing1<< endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
        }
                else if(pl2wingCount < 4){
                
                pl2wingCount++;
                 cout << "Player " << player2 <<  " roll is " << wing1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
               
            
                }
                     
            }
        }
        else if(dice2 == 5){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << leg1;
            cout  << ", must have " << body1 << " first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2legCount <  6){
                
                if(pl2bodyCount ==1){
                
                pl2legCount++;
                 cout << "Player " << player2 <<  " roll is " << leg1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
            
                }  
                
            }
            
            else if(pl2legCount == 6){

                
                cout << "Player " << player2 << " roll is duplicate " << leg1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
        else if (dice2 == 6){
            if(pl2bodyCount ==0){
            cout << "Player " << player2 << " roll is " << tail1;
            cout  << ", must have " << body1 << " first"<< endl;
             cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
             
        
        }
            else if(pl2tailCount <1){
                
                if(pl2bodyCount ==1){
                
                pl2tailCount++;
                 cout << "Player " << player2 <<  " roll is " << tail1 << endl;
            cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
                }   
                
            }
            
            else if(pl2tailCount == 1){
                
                cout << "Player " <<player2 << " roll is duplicate " << tail1 << endl;
                cout << "----------------------" << endl;
            cout << "Player 2 Inventory" << endl;
            cout << "Body:" << setw(5) << pl2bodyCount << endl;
            cout << "Head:" << setw(5) << pl2headCount << endl;
            cout << "Eye:" << setw(6) << pl2eyeCount<< endl;
            cout << "Wing:" << setw(5) << pl2wingCount << endl;
            cout << "Leg:" << setw(6) << pl2legCount << endl;
            cout << "Tail:" << setw(5) << pl2tailCount << endl;
            
            
            }
        }
        break;
        
        }
        roundCount++;
       // this here increments the round as all teh code is ran and then the while loop goes and 
       // restarts with all teh code above and the round is given a higher number +1 
            //reprompt the body generator
        
         //Write the code here to output content and increment bug parts if applicable

		//set p1 to true or p2 to true based on certain conditions
        /*if(bodyCount == 1 && headCount == 1 && eyeCount== 2 && wingCount == 4 && legCount == 6 && tailCount == 1)
        break;     
      {*/
		// here is the game end board output and the proper checks for teh total body coounts
		// for player 1 and 2 
		// using set w and setfill for the lines in a fancy way
		if (pl1bodyCount == 1 && pl1headCount == 1 && pl1eyeCount== 2 && pl1wingCount == 4 && pl1legCount == 6 && pl1tailCount == 1 ) {
        cout << "*******************" << endl;
        cout << "Player one has won" << endl;
        cout << setw(27) <<"Game Results" << endl;
        cout << setfill('-') << setw(45) << " " << endl;
        cout << "Player 1 Inventory"; cout <<'\t'<<"Player 2 Inventory" << endl;
        cout << "Body:       "<< pl1bodyCount << "          Body:       " << pl2bodyCount << endl;
        cout << "Head:       "  << pl1headCount << "          Head:       " << pl2headCount<< endl;
        cout << "Eye:        "<< pl1eyeCount << "          Eye:        " << pl2eyeCount << endl;
        cout << "Wing:       "<< pl1wingCount << "          Wing:       " << pl2wingCount << endl;
        cout << "Leg:        "<< pl1legCount << "          Leg:        " << pl2legCount << endl;
        cout << "Tail:       "<< pl1tailCount << "          Tail:       " << pl2tailCount << endl << endl;
        
            break;
        }
		else if (pl2bodyCount == 1 && pl2headCount == 1 && pl2eyeCount== 2 && pl2wingCount == 4 && pl2legCount == 6 && pl2tailCount == 1) {
        cout << "*******************" << endl;
        cout << "Player two has won" << endl;
        cout << setw(27) <<"Game Results" << endl;
        cout << setfill('-') << setw(45) << " " << endl;
        cout << "Player 1 Inventory";cout<< '\t'<<"Player 2 Inventory" << endl;
        cout << "Body:       "<< pl1bodyCount << "          Body:       " << pl2bodyCount << endl;
        cout << "Head:       "  << pl1headCount << "          Head:       " << pl2headCount<< endl;
        cout << "Eye:        "<< pl1eyeCount << "          Eye:        " << pl2eyeCount << endl;
        cout << "Wing:       "<< pl1wingCount << "          Wing:       " << pl2wingCount << endl;
        cout << "Leg:        "<< pl1legCount << "          Leg:        " << pl2legCount << endl;
        cout << "Tail:       "<< pl1tailCount << "          Tail:       " << pl2tailCount << endl << endl;
		 //if player 2 won, escape loop
			break;
        }
	}
 //using break to escape the loop once the proper amounts are fulfilled   

	return 0;
}
