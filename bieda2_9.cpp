/*NAME: Mateusz Bieda
Description:This program is meant to teach us how to use parallel arrays and 
pass values through parameters with arrays. 
This program in general is meant to take in two files one at a time
Reading the data and storing it into the array, in the appropriate places
For the second file that is entered it reads in each targets point value
and from there we can use it in loops that go and cross check with names 
and their array rows and also check to see where the hits are and
have a boolean check to see how many hits there are and the total score for that
trooper
Repeating this and then at the end outputting the best three

Input:Take in two files one by one
The first file read in the names, hits and misses, and 
the second reads in the target values
Storing the names and hit misses in specific arrays 
so that in seperate loops they can be cross checked 
and see if hit are true and count them


Output:
After reading in data there is a table shown with the names 
of the troopers, hits having X's and a count of how many hits there
were and a total score for each and every trooper
At the end there is a top three chart that uses a function that
outputs the three best that a if else statement goes and checks


*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;
// Declaring vairbales and functions 
const int SIZE = 20;
const int TRGTS = 10;



int readData(string[], bool[][TRGTS], double[]);
double computeScore(bool[][TRGTS], double[], int);
void outputStormTroopers(string[], bool[][TRGTS], double[], int);
void outputOneStormTrooper(string, bool[], double);

int main() {
    // decalaring the variables again
    string names[SIZE] = { " " };
    bool targets[SIZE][TRGTS] = { {false},{false} };
    double targetWeights[TRGTS] = { 0.0 };
    double scores[SIZE] = { 0.0 };
    int countEm = 0;
    int tempCount = 0, length = 0;
    ifstream iFile;
    // these below are for the top three storm troopers so I can have 
    // them not in a sorting loop but replace them with one another
    string stormOne;
    string stormTwo;
    string stormThree;
    int stormCount1;
    int stormCount2;
    int stormCount3;
    double stormScore1;
    double stormScore2;
    double stormScore3;
    stormCount3 = 0;
    int filler = stormCount3;
    filler++;
    // counts up a counter and repeats to a centerain number
    // goes until the end of a file
    // using length to limit a while loop furhter down
    length = readData(names, targets, targetWeights);
    // nice table
    cout << "NAME       T1   T2   T3   T4   T5   T6   T7   T8   T9   T10  TOTAL      SCORE" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;;
    countEm = 0;
    
        // NEED targets countEm I
        // I is second index
        //outputStormTroopers(names, targets[countEm], targetWeights, countEm);
        // in a loop
        // this gets the score for each of the targets and passes the
        // target weights so that the total score can be computed
        for(int i = 0; i < length; i++){
            scores[i] = computeScore(targets, targetWeights,i);
        }
        // this outputs the names and hits with X's and the target count
        // and the score for every individual name 
        outputStormTroopers(names, targets, scores, length);
        //for(int i = 0; i < length; i++)

        tempCount = 0;
        // counts the targets being hit
        for(int i = 0; i < TRGTS; i++) {
            if(targets[countEm][i] == true) {
                tempCount++;
            }  
        }
      // tell which targets to pass in 
      // which index was it in
      // targets in fnction call and which row
     //BRUTE FORCING for the top three to set them in their spots

      while(countEm < length) {
          //CAUSING RANDOM SEGMENTATION FAULTS
          // this is what compares and puts the troopers 
          // in the proper top 3 positions
        tempCount = 0;
        if(scores[countEm- 1]<=scores[countEm]) {
            if(stormScore1 < 1 &&stormScore1 > -1) {
                 stormOne =names[countEm];
                  stormCount1 =tempCount;
                 stormScore1= scores[countEm];
            }
            else if(stormScore1< scores[countEm]) {
                
                 stormThree = stormTwo;
                  stormCount3 = stormCount2;
                stormScore3  = stormScore2 ;

                 stormTwo = stormOne;
                  stormCount2 = stormCount1;
                 stormScore2  = stormScore1 ;

                 stormOne= names[countEm];
                  stormCount1 = tempCount;
                 stormScore1  = scores[countEm];
            }
            else if(stormScore2  <scores[countEm]) {
                
                stormThree = stormTwo;
                 stormCount3 = stormCount2;
                 stormScore3  = stormScore2 ;
                
                  stormTwo = names[countEm];
                 stormCount2 = tempCount;
                 stormScore2  = scores[countEm];
            }
            else if(stormScore3  <scores[countEm]) {
               
                 stormThree = names[countEm];
                
                 stormCount3 = tempCount;
                  stormScore3  = scores[countEm];   
            }
        }
        
        countEm++;
    }
     cout << endl;
      cout <<  "Top 3" ;
     cout << endl << endl;
     // this creates the top three and I made the checks to ensure that the 

  int countMe = 0;
  while(countMe < length){
      if(stormOne==names[countMe] ){
          if(stormScore1 ==scores[countMe]){
      outputOneStormTrooper(stormOne, targets[countMe], stormScore1 );
          }
      }
      else if(stormTwo==names[countMe]){
          if( stormScore2==scores[countMe]){
     outputOneStormTrooper(stormTwo, targets[countMe], stormScore2 );
          }
      }
      else if(stormThree==names[countMe] ){
          if(stormScore3==scores[countMe]){
         outputOneStormTrooper(stormThree, targets[countMe], stormScore3);
          }
       }
          countMe++;
   }
    //In otpt1St
    // pass in one row of 2d array into function contains 10 target 
    // data that adss all trues

   

    return 0;
}

int readData(string names[], bool targets[][TRGTS], double targetWeights[]) {
   /*
This reads in both files, one by one and checks that the first one is open and if thats
true then the second one can be tried to open and checked
the info from the files is read in beforethey are closed
and eof is checked
we have a counter here to see the distance to eof and that is returned to the 
variable length in main which then creates teh length of loop in int main

   */
    ifstream iFile;
    string fileNumOne;
    string fileNumTwo;
    
    int countEm=0;
    string t;

    cout << endl;
    
     cout << "Please enter storm trooper results file: ";
    cin >> fileNumOne;

    iFile.open(fileNumOne);
    
     while(iFile.is_open() == false || cin.fail()) {
        cout << "Invalid file!";
        
         cout << endl;
        cout << endl;
        // first file entered

         cout << "Please enter storm trooper results file: ";
        
         cin >> fileNumOne;
         iFile.open(fileNumOne);
    }

    while(countEm < SIZE) {
        iFile >> names[countEm];
        if(iFile.eof()) {
            iFile.close();
            // eof checked and a counter made
            break;
        }
        for(int j = 0; j < TRGTS; j++) {
            iFile >> t;
            for(uint i=0; i < t.length(); i++) {
                t[i]=tolower(t[i]); 
            }
            // to lower to have a check for the hit
            // and miss to see if they are hit and 
            // all lowercase letters to properly check
            if(t=="hit") {
                targets[countEm][j] = true;
            }
        }
        countEm++;
    }
    
    cout << "Stormtrooper data read successfully" << endl;
    cout << endl;
    // second file read in 
    cout << "Enter target weights: ";
    cin >> fileNumTwo;

    iFile.open(fileNumTwo);
    // checking for valid input and also file opening
    while(!iFile.is_open()|| cin.fail()) {
        cout << "Invalid file!" << endl;
        cout << endl;

        cout << "Enter target weights: ";
        cin >> fileNumTwo;
        iFile.open(fileNumTwo);
    }
    cout << endl;
    
    for(int i = 0; i < TRGTS; i++) {
        iFile >> targetWeights[i];
    }
// all weights set
    cout << "Target weights updated!" << endl;
    cout << endl;
    iFile.close();

    return countEm;
}

double computeScore(bool targets[][TRGTS], double targetWeights[], int count) {
/*
This double function adds together all the targets that are hit with their proper scores 
stored into sumSc
// use a for loop to iterate thorugh all the targets
*/
    double sumSc = 0;
    
    sumSc = 0;
      for(int i= 0; i < TRGTS; i++){
        if(targets[count][i] == true) {
            sumSc+=targetWeights[i];
        }
      // adds the target weighst that are connected to the bool 
      }
    

    return sumSc;
}

void outputStormTroopers(string names[], bool targets[][TRGTS], double scores[], int countEm) {
/*
This function outputs the names and the hits that are marked by X's 
Also each x that is printed has  acounter that counts how many hits are made, and given out

At the end of each trooper their score is given
*/
    int tempCount;
    
    
    tempCount = 0;
// count names targets, and check if targets are hit
    for(int i = 0; i < countEm; i++) {
      tempCount = 0;
      cout << names[i] << "    ";
        for(int j = 0 ; j < TRGTS ; j++){
            if(targets[i][j] == true) {
            cout << "X    ";
            tempCount++;
        }
        else{
            // spacing between x's
            cout << "     ";
        }
        }
       cout << "    " << tempCount << "      ";
       cout << setprecision(4) <<  scores[i] << endl; 
       // used so that two digits after the decimal are present
       
    }

    return;
}

void outputOneStormTrooper(string names, bool targets[], double scores) {
/*
This nicely ouputs the name, target hitsm and score
for the storm trooper that the functions has passed in
the loop in here counts the target hits and outputs it

*/
    
        int hitCount=0;
        // this counts up the target hit for the top three
        // storm troopers since I could not get the other value to pass through and in 
        for(int j = 0; j < TRGTS ; j++){
            if(targets[j] == true) {
            hitCount++;
        }
        
    }
    // for every value passed in with the function call
    // these here output the values
    cout << "NAME: "<< names << endl;
    cout << "Targets hit: " << hitCount  << endl;
    cout << "SCORE: " << scores << endl;

    cout << endl << endl;
    
    return;
}
