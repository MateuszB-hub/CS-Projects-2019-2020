
//Mateusz Bieda
/* Input: The program has functions that output values that are bowling scores
       When we have values that we want to extract from a file we use a bool function 
       that reads the players rolls. Or we can enter it manually, the function call we use
       will be to a void to get the player rolls. There is a menu given to the user
       with the automatic exit if error is to happen
Output: The programs output presents the scores of a bowling game in frames and rows 
        created from arrays. If there is a incomplete game the phrase Game in Progress is shown
        to the user. The games have the ability to be saved after the user enters -1 on their own
        And as well when the game is finished they can save it then, the save is output into a file

Algorithim\
1. Introduction to the User that inlcudes a menu
2. A switch statement preseted for the menu options
3.If R is selected then a file name is aked for, 
    -it goes to the bool function, to check if the file opened. 
    -If it correctly opened then the game will continue to
    print out the Frames of bowling, and display the correct final
    words if the game is incomplete or complete.
4. You choose M then you can enter data manually
    -That then allows you to run the game for the files input
    -and similarly bool checks for file open
    -and prints out the game
5. If you choose Q
    -The program will simply exit and that is it

    NOTE: THE OPTIONS TO PLAY THE GAME AND SEE THE FRAME SCORES
    HAVE THE ABILITY TO SAVE AND OUTPUT TO A FILE
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
// DECLARING PROTOTYPES
void generateScoreText(int point[], int rollCount, string& fileName);
void getPlayerRolls(int point[], int& rollCount);
void gameSaved(int point[], int rollCount, string fileName);
bool readPlayerRolls(int point[], int& rollCount, string fileName);

int main() {
// DECLARING VARIABLES
int j=0;
    string fileName;
    char I;
    int rollCount = 0, point[21] = {0};
    bool COMPLETE;
// MENU
    cout << "********************************" << endl;
    cout << "Welcome to Bedrock Bowling Alley" << endl;
    cout << "********************************" << endl;
    cout << "Menu Options" << endl;
    cout << "R/r Read roll data from file" << endl;
    cout << "M/m Manually enter data" << endl;
    cout << "Q/q quit" << endl;
    cout << "Selection: ";
    cin >> I;

    // SWITCH THAT IS USED TO GIVE THE USER THE CHOICE AT MENU OPTIONS
    switch (I) {
        // PLAY A REGULAR NON MANUAL GAME
        case 'R':
        case 'r':
            cout << "Enter filename to read: ";
            cin >> fileName;
            if(!readPlayerRolls(point, rollCount, fileName)) {
                // CHECKS FOR ANY ERRORS AND THEN CLEARS THEM
                cin.clear();
                cin.ignore(40,'\n');

                break;
            }
            else{
                generateScoreText(point, rollCount, fileName);
            }
            gameSaved(point,rollCount, fileName);

            main();
            break;
            // ENTER MANUAL DATA
        case 'M':
        case 'm':
            getPlayerRolls(point, rollCount);
            generateScoreText(point,rollCount, fileName);
            gameSaved(point,rollCount, fileName);

            main();
            break;
            // TO QUIT THE PROGRAM
        case 'Q':
        case 'q':
            COMPLETE = true;

            exit(0);
            break;
            // DEFAULT NEEDED FOR ANY GOOFY INPUTS
        default:
            cout << "Invalid Selection" << endl;

            exit(0);
    }
}

void generateScoreText(int point[], int rollCount, string& fileName) {
/* Algorithm: 
  1. A for loop to count rollCount until its reached the correct number
  2. if statements to test if there was a strike, spare, or regular rolls
  3. Calculate bonus score for each instance needed
  4. If game ends early, game is in progress output
5. return;
*/

/* function: void generateScoreText(int point[], int rollCount, string& fileName)
 function identifier: this function allows a saved array to output to the display a series of rolls
parameters: function defined by generateScoreText(int point[], int rollCount, string& fileName); 
*/
    // DECLARE VARIABLES FOR ROWS AND COLUMNS FOR ARRAY AND OUTPUT
    int numberFrame = 0, numberRow = 0, Score = 0;
    ifstream inFile;
    int j = 0;
//INCREMENTS FOR FRAME NUMBER AS WELL AS ROW NUMBER
    for(int i = 0; i < rollCount; i++) {
        if(numberFrame < 10) {
            // IF THE FRAME IS LESS THAN 10 IT WILL GO AND INCREMENT IT
            cout << "Frame # " << ++numberFrame << endl;
            cout << "-Roll # " << ++numberRow << " ";
            if(point[i] == 10) {
                // CHECKS IF THERE IS A STRIKE OR NOT IN THE GAME
                cout << "Strike";
                cout << endl;
                // ADD SCORES AND THEY ARE NOT STATIC SO THEY WILL CONTINUE SCALING
                Score += point[i] + point[i+1] + point[i+2];
                cout << "-Score " << Score;
            }
            else{
                //PRINTS OUT THE SCORE
                cout << point[i];
                Score += point[i];
                j=i;
                if(point[j] + point[++i] == 10) {
                    // THIS WILL BE CHECKING FOR A SPARE
                    // IF THE SCORE IS NOT A IMMEDIATE STRIKE
                    cout << endl;
                    cout << "-Roll # " << ++numberRow << " ";
                    cout << "Spare";   
                    cout << endl;
                    // ADDS INTO THE ARRAY AND THEN APPLYS THE VALUE TO SCORE
                    Score += point[i] + point[i+1];
                    cout << "-Score " << Score;
                }
                else{
                    // OTHERWISE IT WILL PRINT OUT THE SCORE NORMALLY
                    cout << endl;
                    cout << "-Roll #" << ++numberRow << " ";
                    cout << point[i];
                    cout << endl;
                    Score += point[i];
                    cout << "-Score " << Score;
                }
                
            }
            numberRow = 0;
            if(i == rollCount) {
                cout << endl << endl;
                // CHECKS FOR AN INCOMPLETE GAME
                cout << "-Game in Progress-" << '\n'<< endl;

                return;
            }
            cout << endl << endl;
        }
    }
    return;
}

void getPlayerRolls(int point[], int& rollCount) {

  /*  The Algorithm: 
 1. Prompt for a y/n character to create a switch statement
 2. Made a  switch statement
 3. Create cases 'y'  'n'
  4.'y'
        -Test if fileName was read in, to create text file
        -Open text file
        -oFile everything to textfile just like generateScoreText
   5. In case 'n'
    - this was to create space/ new lines
    -return
  6. default, just in case invalid selection
        -exit(0);
  */  
//THIS WILL GET THE PLAYER ROLLS FOR THE FRAMES
    int numberFrame = 0, numberRow = 0, j =0;
    rollCount = 0;

    for(int i = 0; i <= rollCount; i++) {
        if(numberFrame < 9) {
            //Checks if the FRAME is less than 9, so then it'll increment it to match
            cout << "Frame # " << ++numberFrame << endl;
            cout << "Roll # " << ++numberRow << " ";
            cin >> point[i];
            rollCount++;
            if(point[i] == -1) {
                // gives a new line
                cout << endl;

                return;
            }
            if(point[i] != 10) {
                // INCREMENTS ROLL IF NOT EQUAL TO 10
                cout << "Roll #" << ++numberRow << " ";
                j = ++i;
                cin >> point[j];
                rollCount++;      
            }
            // RESETS ROW
            numberRow = 0;
            cout << endl;
        }
        if(point[i] == -1) {
                cout << endl;

                return;
        }
        // CREATES THE 10TH ROW AFTER THE 9TH 
        if(numberFrame == 9) {
            cout << "Frame # 10" << endl;
            cout << "Roll #" << ++numberRow << " ";
            cin >> point[i+1];
            //INCREMENTS VALUES AFTER PREVIOUS
            rollCount++;
            if(point[i+1] == 10) {
                cout << endl;
                // This allows the player to get another roll
                // As well as increments the rollCount
                cout << "Bonus roll #1 ";
                cin >> point[i+2];
                rollCount++;
                //It will continue to happen as this counts for the 10th Frame 
                //Where there is 3 Squares/Shots in actual bowling
                cout << "Bonus roll #2 ";
                cin >> point[i+3];
                rollCount++;
                cout << endl << endl;
                
                return;
            }
            if(point[i+1] != 10) {
                // if the points are not equal to 10
                //then we could get only 1 extra roll
                cout << "Roll # " << ++numberRow << " ";
                cin >> point[i+2];
                rollCount++;
            }
            if(point[i+1] + point[i+2] == 10) {
                cout << "Bonus roll #1 ";
                cin >> point[i+3];
                rollCount++;
                cout << endl << endl;

                return;
            }
            else{ 
                cout << endl << endl;
                // if not then we will simply end it
                return;
            }
        }
    }
}
/*  The Algorithim:
 function: void gameSaved(int point[], int rollCount, string fileName)

 function_identifier: this function gives the option to save the game
 and upload the game into a text file
  
  parameters: function is defined by gameSaved(int point[], int rollCount, string fileName); 
*/
void gameSaved(int point[], int rollCount, string fileName) {
// this is used to save the game using an output File
    ofstream oFile;
    int j =0;
    // char correct is used for the switch statement
    char CORRECT;
    int numberFrame = 0, numberRow = 0, Score = 0;
    // this prompts the user for the filesave
    cout << "Save game to file (y/n)? ";
    cin >> CORRECT;
    
    switch(CORRECT) {
        case 'y':
        // YES IS CHOSEN THEN IT WILL OPEN THE FILE 
            if(fileName == "completeNormal.bbl") {
                oFile.open("completeNormalScored.txt");
                // INPUTTING THE FRAMES FOR THE GAME AND ALL
                for(int i = 0; i < rollCount; i++) { 
                    if(numberFrame < 10) {
                        oFile << "Frame # " << ++numberFrame << endl;
                        oFile << "-Roll # " << ++numberRow << " ";
                        if(point[i] == 10) {
                            // GIVES STRIKE IF THE ARRAY CELL VALUE IS 10
                            oFile << "Strike";
                            oFile << endl;
                            Score += point[i] + point[i+1] + point[i+2];
                            // ADDS ALL CELL POINTS TOGETHER
                            oFile << "-Score " << Score;
                            oFile << endl << endl;
                        }
                        else{
                            oFile << point[i];
                            Score += point[i];
                            if(point[i] + point[++i] == 10) {
                                oFile << endl;
                                // pRINTS OUT THE NEWEST ROW AFTER THE POINTS CELL VALUE == 10
                                oFile << "-Roll #" << ++numberRow << " ";
                                oFile << "Spare";   
                                oFile << endl;
                                Score += point[i] + point[i+1];
                                oFile << "-Score " << Score;
                                oFile << endl << endl;
                            }
                            else{
                                // IF IT ISNT THEN IT WILL SKIP OVER AND PRINT OUT 
                                oFile << endl;
                                oFile << "-Roll #" << ++numberRow << " ";
                                oFile << point[i];
                                oFile << endl;
                                Score += point[i];
                                oFile << "-Score " << Score;
                                oFile << endl << endl;
                            }
                        }
                        numberRow = 0;
                        if(i == rollCount) {
                            // CHECKS FOR GAME IF NOT COMPLETE
                            oFile << "-Game in Progress-";

                            oFile.close();
                            // SPECIFIES THE FILE NAME
                            cout << "filename: completeNormalScored.txt" << endl;
                            cout << endl << endl;
                            return;
                        }
                    }
                }
                oFile.close();
                // CLOSES FILE
                cout << "filename: completeNormalScored.txt" << endl;
                cout << endl << endl;
                return;
            }
            // CHECKS FOR OTHER FILE NAMES SUCH AS 
            else if(fileName == "completeSpare.bbl") {
                oFile.open("completeSpareScored.txt");

                for(int i = 0; i < rollCount; i++) { 
                    if(numberFrame < 10) {
                        // CHECKING FOR STRIKES
                        oFile << "Frame #" << ++numberFrame << endl;
                        oFile << "-Roll #" << ++numberRow << " ";
                        if(point[i] == 10) {
                            // CHECKS FOR STRIKE IN THIS FILE
                            oFile << "Strike";
                            oFile << endl;
                            // ADDS ARRAY CELLS TOGHETER FOR THE SCORE TO BE INCREASED
                            Score += point[i] + point[i+1] + point[i+2];
                            oFile << "-Score " << Score;
                            oFile << endl << endl;
                        }
                        else{
                            // OTHERWISE WE GO AND CHECK FOR SPARES
                            oFile << point[i];
                            Score += point[i];
                            j = i;
                            if(point[j] + point[++i] == 10) {
                                oFile << endl;
                                // CHECKING FOR SPARES
                                oFile << "-Roll #" << ++numberRow << " ";
                                oFile << "Spare";   
                                oFile << endl;
                                Score += point[i] + point[i+1];
                                oFile << "-Score " << Score;
                                oFile << endl << endl;
                            }
                            else{
                                oFile << endl;
                                oFile << "-Roll #" << ++numberRow << " ";
                                oFile << point[i];
                                oFile << endl;
                                Score += point[i];
                                oFile << "-Score " << Score;
                                oFile << endl << endl;
                            }
                        }
                        numberRow = 0;
                        if(i == rollCount) {
                            oFile << "-Game in Progress-";
                            //CHECKS IF INCOMPLETE
                            oFile.close();
                            //CLOSES FILE
                            cout << "filename: completeSpareScored.txt" << endl;
                            cout << endl << endl;
                            return;
                        }
                    }
                }
                oFile.close();
                //CLOSES FILE COMPLETELY
                cout << "filename: completeSpareScored.txt" << endl;
                cout << endl << endl;
                return;
            }
            else if(fileName == "completeStrike.bbl") {
                oFile.open("completeStrikeScored.txt");
                // OPEN FILE TO READ IN DATA
                for(int i = 0; i < rollCount; i++) { 
                    if(numberFrame < 10) {
                        oFile << "Frame #" << ++numberFrame << endl;
                        oFile << "-Roll #" << ++numberRow << " ";
                        if(point[i] == 10) {
                            //CHECKING FOR STRIKE
                            oFile << "Strike";
                            oFile << endl;
                            Score += point[i] + point[i+1] + point[i+2];
                            oFile << "-Score " << Score;
                            oFile << endl << endl;
                        }
                        else{
                            // CHECKING FOR SPARE
                            oFile << point[i];
                            Score += point[i];
                            j = i;
                            if(point[j] + point[++i] == 10) {
                                oFile << endl;
                                // AFTER NEW LINE WE CHECK FOR A SPARE
                                oFile << "-Roll #" << ++numberRow << " ";
                                oFile << "Spare";   
                                oFile << endl;
                                Score += point[i] + point[i+1];
                                oFile << "-Score " << Score;
                                oFile << endl << endl;
                            }
                            else{
                                // PRINTING OUT SCORE IF NOTHING ELSE HAPPENS
                                oFile << endl;
                                oFile << "-Roll #" << ++numberRow << " ";
                                oFile << point[i];
                                oFile << endl;
                                Score += point[i];
                                oFile << "-Score " << Score;
                                oFile << endl << endl;
                            }
                        }
                        numberRow = 0;
                        if(i == rollCount) {
                            // INCOMPLETE GAME WILL PRINT OUT THIS
                            oFile << "-Game in Progress-";

                            oFile.close();
                            cout << "filename: completeStrikeScored.txt" << endl;
                            cout << endl << endl;
                            return;
                        }
                    }
                }
                oFile.close();
                //CLOSING FILE
                cout << "filename: completeStrikeScored.txt" << endl;
                cout << endl << endl;
                return;
            }
            // THE SAME PROCESS AS BEFORE IS REPEATED 
            // CHECKING THE FILENAME AND THE FRAME COUNT
            else if(fileName == "partialBonus.bbl") {
                oFile.open("partialBonusScored.txt");

                for(int i = 0; i < rollCount; i++) { 
                    if(numberFrame < 10) {
                        oFile << "Frame #" << ++numberFrame << endl;
                        oFile << "-Roll #" << ++numberRow << " ";
                        if(point[i] == 10) {
                            //CHECKING FOR STRIKE
                            oFile << "Strike";
                            oFile << endl;
                            Score += point[i] + point[i+1] + point[i+2];
                            oFile << "-Score " << Score;
                            oFile << endl << endl;
                        }
                        else{
                            oFile << point[i];
                            Score += point[i];
                            j=i;
                            if(point[j] + point[++i] == 10) {
                                oFile << endl;
                                //CHECKING FOR SPARE
                                oFile << "-Roll #" << ++numberRow << " ";
                                oFile << "Spare";   
                                oFile << endl;
                                Score += point[i] + point[i+1];
                                oFile << "-Score " << Score;
                                oFile << endl << endl;
                            }
                            else{
                                //  IF NEITHER BEFORE WORK THEN WE PRINT OUT THIS
                                oFile << endl;
                                oFile << "-Roll #" << ++numberRow << " ";
                                oFile << point[i];
                                oFile << endl;
                                Score += point[i];
                                // ADD TO THE SCORE BY ARRAY CELL FROM PERVIOUS
                                oFile << "-Score " << Score;
                                oFile << endl << endl;
                            }
                        }
                        numberRow = 0;
                        if(i == rollCount) {
                            // IF THE GAME IS INCOMPLETE WE SHOW THIS MESSAGE
                            oFile << "-Game in Progress-";

                            oFile.close();
                            // CLOSE THE FILE
                            cout << "filename: partialBonusScored.txt" << endl;
                            cout << '\n' << endl;
                            return;
                        }
                    }
                }
                oFile.close();
                cout << "filename: partialBonusScored.txt" << endl;
                cout << endl << endl;
                return;
            }
            else if(fileName == "partialBonusNormal.bbl") {
                oFile.open("partialBonusNormalScored.txt");

                for(int i = 0; i < rollCount; i++) { 
                    if(numberFrame < 10) {
                        // for this file we once again check for the frame if
                        // there is a 10th one
                        oFile << "Frame #" << ++numberFrame << endl;
                        oFile << "-Roll #" << ++numberRow << " ";
                        if(point[i] == 10) {
                            // checks for a strike once again
                            oFile << "Strike";
                            oFile << endl;
                            // for the 10th frame we add the cells for
                            // the 3 spaces as if it were a real game 
                            Score += point[i] + point[i+1] + point[i+2];
                            oFile << "-Score " << Score;
                            oFile << endl << endl;
                        }
                        else{
                            oFile << point[i];
                            Score += point[i];
                            j=i;
                            if(point[j] + point[++i] == 10) {
                                // if the points equal up to 10 we get a spare from the TWO
                                // NEEDS TO BE TWO POINT VALUES
                                oFile << endl;
                                oFile << "-Roll #" << ++numberRow << " ";
                                oFile << "Spare";   
                                oFile << endl;
                                Score += point[i] + point[i+1];
                                oFile << "-Score " << Score;
                                oFile << endl << endl;
                            }
                            else{
                                //OTHERWISE WE PRINT OUT THIS NORMAL SCORE THAT ISNT A SPARE/ OR STRIKE
                                oFile << endl;
                                oFile << "-Roll #" << ++numberRow << " ";
                                oFile << point[i];
                                oFile << endl;
                                Score += point[i];
                                oFile << "-Score " << Score;
                                oFile << endl << endl;
                            }
                        }
                        numberRow = 0;
                        if(i == rollCount) {
                            oFile << "-Game in Progress-";
                        // CLOSING FILE AGAIN
                            oFile.close();
                            cout << "filename: partialBonusNormalScored.txt" << endl;
                            cout << endl << endl;
                            return;
                        }
                    }
                }
                //CLOSING THE FILE AGAIN
                oFile.close();
                cout << "filename: partialBonusNormalScored.txt" << endl;
                cout << endl << endl;
                return;
            }
            else if(fileName == "partialBonusSpare.bbl") {
                oFile.open("partialBonusSpareScored.txt");
                // OPENEING TO SEE DATA AS WELL AS TELL THE FRAME COUNT
                for(int i = 0; i < rollCount; i++) { 
                    if(numberFrame < 10) {
                        oFile << "Frame #" << ++numberFrame << endl;
                        oFile << "-Roll #" << ++numberRow << " ";
                        if(point[i] == 10) {
                            // CHECK FOR POINTS TO SEE IF THERE IS A STRIKE
                            oFile << "Strike";
                            oFile << endl;
                            Score += point[i] + point[i+1] + point[i+2];
                            oFile << "-Score " << Score;
                            oFile << endl << endl;
                        }
                        else{
                            oFile << point[i];
                            Score += point[i];
                            j=i;
                            if(point[j] + point[++i] == 10) {
                                oFile << endl;
                                // CHECKS IF TWO POINT VALUES EQUAL UP TO 10
                                // TO PROVE THERE IS A SPARE
                                oFile << "-Roll #" << ++numberRow << " ";
                                oFile << "Spare";   
                                oFile << endl;
                                Score += point[i] + point[i+1];
                                oFile << "-Score " << Score;
                                oFile << endl << endl;
                            }
                            else{
                                // IF NETIHER THEN THIS NOT SPARE/STIKE PROMPT IS GIVEN
                                oFile << endl;
                                oFile << "-Roll #" << ++numberRow << " ";
                                oFile << point[i];
                                oFile << endl;
                                Score += point[i];
                                oFile << "-Score " << Score;
                                oFile << endl << endl;
                            }
                        }
                        numberRow = 0;
                        if(i == rollCount) {
                            oFile << "-Game in Progress-";
                        // IF NONE ABOVE WE SAY INCOMPLETE GAME 
                            oFile.close();
                            cout << "filename: partialBonusSpareScored.txt" << endl;
                            cout << endl << endl;
                            return;
                            //CLOSING FILE
                        }
                    }
                }
                oFile.close();
                cout << "filename: partialBonusSpareScored.txt" << endl;
                cout << endl << endl;
                return;
                //CLOSED FILE
            }
            else if(fileName == "partialBonusStrike0.bbl") {
                oFile.open("partialBonusStrike0Scored.txt");

                for(int i = 0; i < rollCount; i++) { 
                    if(numberFrame < 10) {
                        oFile << "Frame #" << ++numberFrame << endl;
                        oFile << "-Roll #" << ++numberRow << " ";
                        if(point[i] == 10) {
                            //FOR THIS FILE WE ONCE AGAIN CHECK FOR A STRIKE
                            oFile << "Strike";
                            oFile << endl;
                            Score += point[i] + point[i+1] + point[i+2];
                            oFile << "-Score " << Score;
                            oFile << endl << endl;
                        }
                        else{
                            oFile << point[i];
                            Score += point[i];
                            j=i;
                            if(point[j] + point[++i] == 10) {
                                oFile << endl;
                                // NOW WE CHECK FOR A SPARE WITH TWO CELLS BEING ADDED 
                                oFile << "-Roll #" << ++numberRow << " ";
                                oFile << "Spare";   
                                oFile << endl;
                                Score += point[i] + point[i+1];
                                oFile << "-Score " << Score;
                                oFile << endl << endl;
                            }
                            else{
                                oFile << endl;
                                // IF NOT A STRIKE OR SPARE A REGUALR SCORE IS TO BE OUTPUT
                                oFile << "-Roll #" << ++numberRow << " ";
                                oFile << point[i];
                                oFile << endl;
                                Score += point[i];
                                oFile << "-Score " << Score;
                                oFile << endl << endl;
                            }
                        }
                        numberRow = 0;
                        if(i == rollCount) {
                            oFile << "-Game in Progress-";

                            oFile.close();
                            //CLOSING THE FILE
                            cout << "filename: partialBonusStrike0Scored.txt" << endl;
                            cout << endl << endl;
                            return;
                        }
                    }
                }
                oFile.close();
                //CLOSING THE FILE
                cout << "filename: partialBonusStrike0Scored.txt" << endl;
                cout << endl << endl;
                return;
            }
            else if(fileName == "partialBonusStrike1.bbl") {
                oFile.open("partialBonusStrike1Scored.txt");

                for(int i = 0; i < rollCount; i++) { 
                    if(numberFrame < 10) {
                        oFile << "Frame #" << ++numberFrame << endl;
                        oFile << "-Roll #" << ++numberRow << " ";
                        if(point[i] == 10) {
                            // NEW FILE NEW FRAME TO COUNT THE VALUE OF 10
                            //CHECK FOR STRIKE ADDING CELLS TOGETHER FOR SCORE TOTAL
                            oFile << "Strike";
                            oFile << endl;
                            Score += point[i] + point[i+1] + point[i+2];
                            oFile << "-Score " << Score;
                            oFile << endl << endl;
                        }
                        else{
                            oFile << point[i];
                            Score += point[i];
                            j=i;
                            if(point[j] + point[++i] == 10) {
                                oFile << endl;
                                // sPARE TO BE COUNTED BY ADDING TWO CELLS
                                // TO GIVE NEW SCORE OUTPUT
                                oFile << "-Roll #" << ++numberRow << " ";
                                oFile << "Spare";   
                                oFile << endl;
                                Score += point[i] + point[i+1];
                                oFile << "-Score " << Score;
                                oFile << endl << endl;
                            }
                            else{
                                oFile << endl;
                                // NEITHER sPARE NOR STRIKE THEN A REGUALR SCORE IS GIVEN
                                oFile << "-Roll #" << ++numberRow << " ";
                                oFile << point[i];
                                oFile << endl;
                                Score += point[i];
                                oFile << "-Score " << Score;
                                oFile << endl << endl;
                            }
                        }
                        numberRow = 0;
                        if(i == rollCount) {
                            oFile << "-Game in Progress-";
                            // IF GAME NOT COMPLETE PROMPT IS GIVEN
                            oFile.close();
                            cout << "filename: partialBonusStrike1Scored.txt" << endl;
                            cout << endl << endl;
                            return;
                        }
                    }
                }
                oFile.close();
                //CLOSE FILE AS WE ARE DONE USING IT
                cout << "filename: partialBonusStrike1Scored.txt" << endl;
                cout << endl << endl;
                return;
            }
            else if(fileName == "partialGame.bbl") {
                oFile.open("partialGameScored.txt");
                // OPEN FILE TO READ IN VALUES
                for(int i = 0; i < rollCount; i++) { 
                    if(numberFrame < 10) {
                        oFile << "Frame #" << ++numberFrame << endl;
                        oFile << "-Roll #" << ++numberRow << " ";
                        if(point[i] == 10) {
                            // NEW FILE NEW STRIKE CHECK
                            oFile << "Strike";
                            oFile << endl;
                            Score += point[i] + point[i+1] + point[i+2];
                            oFile << "-Score " << Score;
                            oFile << endl << endl;
                        }
                        else{
                            oFile << point[i];
                            Score += point[i];
                            j=i;
                            if(point[j] + point[++i] == 10) {
                                // CHECK FOR SPARE ADDING TWO CELLS TOGETHER FOR 
                                // NEW SCORE OUTPUT
                                oFile << endl;
                                oFile << "-Roll #" << ++numberRow << " ";
                                oFile << "Spare";   
                                oFile << endl;
                                Score += point[i] + point[i+1];
                                oFile << "-Score " << Score;
                                oFile << endl << endl;
                            }
                            else{
                                oFile << endl;
                                // NIETHER SPARE NOR STRIKE A REGUALR SCORE IS GIVEN
                                oFile << "-Roll #" << ++numberRow << " ";
                                oFile << point[i];
                                oFile << endl;
                                Score += point[i];
                                oFile << "-Score " << Score;
                                oFile << endl << endl;
                            }
                        }
                        numberRow = 0;
                        if(i == rollCount) {
                            oFile << "-Game in Progress-";
                            // INCOMPLETE GAME IS GIVEN THIS IS OUTPUT
                            oFile.close();
                            cout << "filename: partialGameScored.txt" << endl;
                            cout << endl << endl;
                            return;
                        }
                    }
                }
                oFile.close();
                cout << "filename: partialGameScored.txt" << endl;
                cout << endl << endl;
                return;
            }
            else if(fileName == "perfect.bbl") {
                oFile.open("perfectScored.txt");

                for(int i = 0; i < rollCount; i++) { 
                    if(numberFrame < 10) {
                        // NEW FILE NEW STRIKE CHECK
                        oFile << "Frame #" << ++numberFrame << endl;
                        oFile << "-Roll #" << ++numberRow << " ";
                        if(point[i] == 10) {
                            // ADDING THE ARRAY CELLS FOR NEW SCORE OUTPUT
                            oFile << "Strike";
                            oFile << endl;
                            Score += point[i] + point[i+1] + point[i+2];
                            oFile << "-Score " << Score;
                            oFile << endl << endl;
                        }
                        else{
                            oFile << point[i];
                            Score += point[i];
                            j=i;
                            if(point[j] + point[++i] == 10) {
                                oFile << endl;
                                oFile << "-Roll #" << ++numberRow << " ";
                                oFile << "Spare";   
                                // COUNT THE SPARE SCORE AMOUNT WITH THE ARRAY CELLS
                                oFile << endl;
                                Score += point[i] + point[i+1];
                                oFile << "-Score " << Score;
                                oFile << endl << endl;
                            }
                            else{
                                oFile << endl;
                                // NEITHER SPARE NOT STRIKE THIS NORMAL SCORE WILL BE OUTPUT
                                oFile << "-Roll #" << ++numberRow << " ";
                                oFile << point[i];
                                oFile << endl;
                                Score += point[i];
                                oFile << "-Score " << Score;
                                oFile << endl << endl;
                            }
                        }
                        numberRow = 0;
                        if(i == rollCount) {
                            oFile << "-Game in Progress-";

                            oFile.close();
                            cout << "filename: perfectScored.txt" << endl;
                            cout << endl << endl;
                            return;
                        }
                    }
                }
                oFile.close();
                cout << "filename: perfectScored.txt" << endl;
                cout << endl << endl;
                return;
            }
            else{
                // BEGINNING OF MANUAL ENTRY CODE
                oFile.open("manualEntriesScored.txt");
                // FOR LOOP TO INCREMEMNT ROLL COUNT
                for(int i = 0; i < rollCount; i++) { 
                    if(numberFrame < 10) {
                        // CHECK FOR FRAME IF LESS THAN
                        oFile << "Frame #" << ++numberFrame << endl;
                        oFile << "-Roll #" << ++numberRow << " ";
                        if(point[i] == 10) {
                            oFile << "Strike";
                            oFile << endl;
                            // NEW SCORE ADDING CELLS TOGETHER 
                            Score += point[i] + point[i+1] + point[i+2];
                            oFile << "-Score " << Score;
                            oFile << endl << endl;
                        }
                        else{
                            oFile << point[i];
                            Score += point[i];
                            j=i;
                            if(point[j] + point[++i] == 10) {
                                oFile << endl;
                                // SPARE SCORE ADDING AND MAKING NEW SCORE TOTAL
                                oFile << "-Roll #" << ++numberRow << " ";
                                oFile << "Spare";   
                                oFile << endl;
                                Score += point[i] + point[i+1];
                                oFile << "-Score " << Score;
                                oFile << endl << endl;
                            }
                            else{
                                oFile << endl;
                                oFile << "-Roll #" << ++numberRow << " ";
                                oFile << point[i];
                                oFile << endl;
                                Score += point[i];
                                oFile << "-Score " << Score;
                                oFile << endl << endl;
                            }
                        }
                        numberRow = 0;
                        if(i == rollCount) {
                            oFile << endl << endl;
                            oFile << "-Game in Progress-" << endl;
                            // INCOMPLETE GAME, USER GIVEN THIS MESSAGE
                            oFile.close();
                            cout << "filename: manualEntriesScored.txt" << endl;
                            cout << endl << endl;
                            return;
                        }
                    }
                }
                // CLOSES FILE
                oFile.close();
                cout << "filename: manualEntriesScored.txt" << endl;
                cout << endl << endl;
                return;
            }
            // BREAK USED TO SEPARATE THE NEXT CASE
            break;
        case 'n':
            cout << endl << endl;
            // CASE N TO CREATE NEW LINE, MOSTLY USELESS
            return;

            break;
            // IF THERE IS A IMPROPER MANUAL SELECTION THE GAME WILL
            // EXIT ITSELF IMMEDIATELY 
        default:
            cout << "Invalid Selection" << endl;
            
            exit(0);
    }
}

bool readPlayerRolls(int point[], int& rollCount, string fileName) {
    /* Algorithm: 
1. User fileName prompted in main()
2. Open the file
3. Check to see if file opened or not
    -file open, count rollCount and return true
    -If file didn't open, we give an error message, return false, then return to menu
 4. Output the file successfully opened and display rollCount
 5. return true
*/

/* function: bool readPlayerRolls(int point[], int& rollCount, string fileName

 function identifier: this function prompts the user which text file to open if they 
                      want to enter rolls from a file.
                      The file opens, it will count the correct amount of rolls and display that Roll Count. 
                      If the file does not open, user will be sent back to the menu, then given a file open error message
 
parameters: function is defined by readPlayerRolls(int points[], int& rollCount, string fileName); 
return value: returns either true or false
*/
    ifstream inFile;
    // THIS IS CHECKING THE PLAYER ROLLS USING 
    // THE BOOL
    inFile.open(fileName);    
    // OPEN THE INFILE THAT IS GIVEN FROM THE USER
    if(inFile.is_open() != true) {
        // TESTES THE FILE
        cout << "reading file error \"" << fileName << "\"" << endl;
        cout << endl << endl;

        main();
    }
    // CHECKING FOR A FAILSAFE IN ADDITION TO ADDING IN
    //ARRAY VALUE equal to i
    rollCount=0;
    for(int i = 0; i <= rollCount; i++) {
        inFile >> point[i];
        if(inFile.fail() == false) {
            // if the failsafe is false then we can increment the roll count
            rollCount++;
        }
    }

    cout << "Successfully read file \"" << fileName << "\" Roll Count: " << rollCount << endl << endl;

    return true;  
}