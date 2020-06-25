/*
NAME:Mateusz Bieda
Description:
This program teaches us how to further use functions with different kinds of loops, going in depth
on specific results for sizes, and creating shapes that are hollow inside and more
In addition it brings in the use of using and creating files.

Input: the main is provided but we get to input the AS8Data file which then is opened and the data
inside is used when we move onto the output section

Output: After the data is processes we then move onto using the it with if statements
matchinig the strings
and then passing the information into functions that will use the values 
and create, open, and write out to the output file
and close it for each specific shape, size, and character
once all that is done and files are complete 3 statements are given notifying the user
the program is over

Algorithim:
THE MAIN WAS GIVEN THAT PROMPTS THE USER
OPENS THE FILE
CHECKS IF ITS OPEN WITH THE FILE OPEN FUNCTION
IF THAT IS TRUE IT PROCCESSES THE INFO FROM ANOTEHR FUNCITON
AND FROM THERE THE INFO IS PASSED INTO THE APPROPRIATE IF STATEMENT THAT CHECKS
STRINGS TO SEE IF THEY MATCH THE SHAPES
OPEN OUTPUT FILE
USE DATA READ FROM FILE
WRITE IT TO OUTFILE, WITH SHAPES AND NUMBER LINES
CLOSE FILE 
THIS IS REPEATED UNTIL EOF IS REACHED
GIVE GOOBYE MESSAGE

*/
#include <iostream>
#include <fstream>
#include <iomanip>
// IMPORT LIBRARIES
using namespace std;


// prototypes
int sd(int size, int a);
void openInputFile( ifstream&, string);
bool openOutputFile( ofstream & oFile, string fname);
void outputChar( ofstream&, int count, char l);
void makeEight( ofstream& oFile, int size, char c );
void makeTriangle( ofstream&, int size, char c );
void makeSlash( ofstream& oFile, int size, char c);
string createOutputFilename(  string typeString, int labelSize );
bool readRecord ( ifstream& iFile, string& typeString, int& lSize, char& c );

// Do not change main 
int main(){
    ifstream iFile;
    ofstream oFile;
    string ofName;
    string typeString;
    int  labelSize = 0;
    char labelChar=0;
    int recordCount =0;
    bool done = false;

    cout << "Welcome to Rebel Alliance Computational Support" << endl;
    cout << "\t            x" << endl;
    cout << "\t      x    xxx    x" << endl;
    cout << "\t     x    x x x    x" << endl;
    cout << "\t    x      xxx      x" << endl;
    cout << "\t   xx       x       xx" << endl;
    cout << "\t  xxx      xxx      xxx" << endl;
    cout << "\t  xxxx     xxx     xxxx" << endl;
    cout << "\t  xxxxx    xxx   xxxxx" << endl;
    cout << "\t   xxxxxxxxxxxxxxxxxxx" << endl;
    cout << "\t    xxxxxxxxxxxxxxxxx" << endl;
    cout << "\t     xxxxxxxxxxxxxxx" << endl;
    cout << "\t       xxxxxxxxxxx" << endl;

    cout << endl << endl;
    
    // Open input file
    openInputFile( iFile, "Input Specification File: " );
    
    // read all records from the specification file. 
    while(true){
        
        // read a record from the file
         done = readRecord ( iFile, typeString,  labelSize, labelChar );
            
         // verify that it worked, if not exit.
         if ( !done ){   
            cout << "Finished processing input file" << endl;
            cout << recordCount<< " Shapes Created " <<endl;
            iFile.close();
            oFile.close();
            exit(0);            
        }

        recordCount++;    
  
        // create the output filename
        ofName = createOutputFilename( typeString, labelSize );

        // open output file
        if( !openOutputFile( oFile, ofName )) // what does the ofName do with oFile???? 
         {
            // output a message if the file did not open
            cout << "Output file \"" << ofName << "\" did not open" << endl;
            cout << "File \"" << ofName << "\" not generated" << endl;
        }else{
               // output a message that the file successfully opened
               cout << "File \"" << ofName << "\" successfully opened" << endl;

               // call appropriate function 
               if( typeString == "figureEight")
                    makeEight( oFile, labelSize, labelChar );
                else if(typeString == "triangle")
                    makeTriangle( oFile, labelSize, labelChar);
                else if( typeString == "slash")
                    makeSlash( oFile, labelSize, labelChar );

        } 
        // close the shape file so that we can re-use oFile variable
        oFile.close();
      }  
}
int sd(int size, int a){
    // I USE THIS SO I HAVE TO WRITE LESS 
    // HAS THE SIZE / 10 EQUATION TO FIND THE
    // VERTICAL THICKNESS
  return size / a;
}
// function documentation here
/*
Read data from the input file
this will be used till the eof 
also used in a while loop to repeat the data being read
*/
bool readRecord ( ifstream& iFile, string& typeString, int& lSize, char& c ){
   
        iFile >> typeString >> lSize >> c;
       
    if(iFile.eof()){
        return false;
    }    
    
    // reads one line, if eof  == true 
    //else  == false
    // This return is included because value returing functions must
    // return a value. It must be replaced by the appropriate return
    // value  in the students code. 
    
    return true;
                  
}

// function documentation here
string createOutputFilename(  string typeString, int labelSize ){
  // create the output filename
  // ensuring that the strings match and concatenate
  // using to_String to have ints work
    string fileName;
    // labelSize is the size of the image
    if(typeString == "figureEight"){
  fileName = "figureEight_" + to_string(labelSize) + ".txt.";
        return fileName;
    }
    else if( typeString == "triangle"){
        fileName = "triangle_" + to_string(labelSize) + ".txt.";
			
        return fileName;
    }
    else if(typeString == "slash"){
      fileName = "slash_" + to_string(labelSize) + ".txt.";
			
        return fileName;
    }
				// this creates the column numbers
// THIS WILL GO INSIDE EVERY INDIVIDUAL SHAPE CREATION POSSIBLY
// BEFORE WE OPEN THE OFSTEREAM, WE NEED TO PASS THE PARAMETERS FOR SIZE
//AND SHAPE TO THIS LEAVING THE CHAR Output
// THIS WILL BE SIMPLY USED FOR MAKING THE OUTPUT FILE NAME
// 

  //Help later to create the file
  //stringVar = fileNameString+"_"+numberstring+".txt";
    // This return is included because value returing functions must
    // return a value. It must be replaced by the appropriate return
    // value  in the students code. 
   // return "out.txt";

}

// function documentation here
void openInputFile( ifstream& iFile, string prompt ){
    /*
    when the question input file specification is given this will
    take in the input file
    and ensure that it opens
    if it doesn't open then its reprompted
    also if the file doesn't exist, it wont open

    */
    cout << prompt ;
    string fName = "";
    cin >> fName;
    iFile.open(fName);
    while(cin.fail() || !iFile.is_open()){
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Error Reading File" << endl;
        cout << "Input Specificatoin File: ";
        cin >> fName;
        iFile.open(fName);
    }
   
    if(iFile.is_open()){
      return;
    }
   
    
    
}
  


// function documentation here
/*
this is used to open the output file ensuring that its true so the
program can proceed with the proper output filie
*/
bool openOutputFile( ofstream & oFile, string fname){

    // This return is included because value returing functions must
    // return a value. It must be replaced by the appropriate return
    // value  in the students code. 
    oFile.open(fname);
    if(!oFile.is_open()){
      return false;
    }
    else{
    return true;
    }
}      


// function documentation here
void makeEight( ofstream& oFile, int size, char c ){
    /*
this function creates the figure eight using the values passsed in from the function
size is used in an equation that makes the vertical thickness
and the result is divided by 2 for the horizontal thickness
there are for loops and while loops that create the speicific portions of the shape
and the number lines as well are at the top and bottom of the code where the shape
is created
    */
  oFile << "Symbol: Figure Eight " << "Size : " << size;
  oFile << " Character: " << '"' << c << '"' << endl;
  // identifies what shape and etc
  int num = 0;
  int sie = size %2;
  int count = 1;
  int topLineCount= 1;
  int x= 0;
  
  oFile << "    ";
  // this creates the top number line
  while(x != size){
    
    oFile << topLineCount;
    x++;
    topLineCount++;
    if(topLineCount == 10){
      topLineCount = 0;
    }
  }
  oFile <<endl;
  oFile << endl;
  if(size < 10){
      // checks if the size is valid
    oFile << "Error Invalid Size, Must Be Bigger Than 10";
    oFile << endl; 
  }
  // make the equations stored into variables to
  // 
  int siONE = size / 2;
  int si = size / 10;
  count = 1;
  if(si < 3){
    
    for(int o = 0; o < 5; o++){
      // checks the number lines
      if(o == 0 || o == 2 || o ==4){
       // if the line are on these levels then the side line will
       // increments the left colummn number line
       // THIS IS MADE FOR EACH SPECIFIC CALCULATION 
       // SUCH AS IF THE SIZE / 10 == 3 FOR 31, OR 5 FOR 58
       // This code structure was reused and implimented for each variety of 
       //figure eight  
        oFile << right << setfill(' ') << setw(2);
        oFile << count;
        oFile << "    ";
        count++;
        for(int e = 0; e < size - 4; e++){
          outputChar(oFile, size, c);
        }

      }
      if(o == 1 || o == 3){
        
        if(sie == 0){
          if( o == 3 ) {
                            oFile << endl;
                            while( num < ((siONE)-1)) {
                                oFile << right;           
                                oFile << setfill(' ') ;        
                                   oFile  << setw(2 );
                  
                                oFile << count << "  ";
                                
                                count++;
                                int i= 0;
                                // the loop ensures that the middle row
                                // has its side spaces 
                                while(i < size ) {
                                    if( i< 2 || i> size-3 ) {  
                                        outputChar( oFile, size, c );
                                        // this will output the shape
                                    }
                                    else{
                                        // creates the spaces in between the vertical columns
                                        oFile << " ";
                                    }  
                                    i++ ;
                                }
                                oFile << endl;
                                
                                num++;
                            }   
                            num = 0;
                        }
          else {
                            oFile << endl;
                            while(num < ((siONE)-2)) {
                                oFile << right;           
                                oFile << setfill(' ') ;        
                                   oFile  << setw(2 );
                  
                                oFile << count << "  ";
                              
                                count++;
                                int i= 0;
                                while(i< size) {
                                    if(i < 2 || i > size-3 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                     i++ ;
                                }
                                oFile << endl;
                                
                                num++;
                            }   
                            num = 0;
                            // the while loop repeats
                        }
                        
                    }
                    else{
                        oFile << endl;
                        
                        while( num < ((siONE)-1)) {
                            oFile << right;           
                            oFile << setfill(' ') ;        
                                   oFile  << setw(2 );
                  
                            oFile << count;
                            oFile << "  ";
                            count++;
                            int i= 0;
                            while(i < size) {
                                if(i< 2 || i > size-3 ) {  
                                    outputChar( oFile, size, c );
                                }
                                else{
                                    oFile << " ";
                                }  
                                 i++ ;
                            }
                           oFile << endl;
                            
                            num++;
                        }
                        num = 0;
                    }
                }
            }
        }
        // the code above is repeated for this and the certain values
        // are changed to fit this version
        if( ( sd(size, 10) ) == 7 ) {
           for( int o = 0 ;  o < 5; o++ ) {
                if( o == 0 || o == 2 || o == 4 ) {
                    oFile << right << setfill(' ')<< setw(2) ;        
                    oFile  << count;
                    count++;
                    oFile << "         ";
                    for(int v = 0; v < 2 ; v++){
                    for( int z = 0; z < size - 14; z++ ) {
                        outputChar( oFile, size, c );
                    }
                    oFile << endl;
                    oFile << right << setfill(' ') << setw(2);        
                    oFile   << count;
                    count++;
                    oFile << "         ";
                   
                }
                    for( int z = 0; z < size - 14; z++ ) {
                        outputChar( oFile, size, c );
                    }
                }
                else if( o == 1 || o == 3 ) {
                    if( sie == 0 ) {
                        
                        if( o == 1 ) {
                            oFile << endl;
                            while( num < ((siONE)-5)) {
                                oFile << right;           
                                oFile << setfill(' ') ;        
                                   oFile  << setw(2 );
                  
                                oFile << count << "  ";
                              
                                count++;
                                int i= 0;
                                while(i < size) {
                                    if( i< 7 || i> size-8 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                    i++ ;
                                }
                                oFile << endl;
                                
                                num++;
                            }   
                            num = 0;
                        }
                        if( o == 3 ) {
                            oFile << endl;
                            while( num < ((siONE)-4)) {
                                oFile << right;           
                                oFile << setfill(' ') ;        
                                   oFile  << setw(2 );
                  
                                oFile << count << "  ";
                              
                                count++;
                                int i=0;
                                while( i < size ) {
                                    if( i< 7 || i> size-8 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                    i++ ;
                                }
                                oFile << endl;
                                
                                num++;
                            }   
                            num = 0;
                        }
                    }
                    else{
                        oFile << endl;
                       
                        while( num < ((siONE)-1)) {
                            oFile << right;           
                            oFile << setfill(' ') ;        
                                   oFile  << setw(2 );
                  
                            oFile << count;
                            oFile << "  ";
                            count++;
                            int i = 0;
                            while(i< size) {
                                if(i< 7 ||i> size-8 ) {  
                                    outputChar( oFile, size, c );
                                }
                                else{
                                    oFile << " ";
                                }  
                                i++ ;
                            }
                            oFile << endl;
                            
                            num++;
                        }
                        num = 0;
                    }
                }
            }
        }
        if( ( sd(size, 10) ) == 5 ) {
            for( int o = 0; o < 5; o++ ) {
                if(o == 0 || o == 2 || o ==4) {
                    oFile << right << setfill(' ')<< setw(2) ;        
                    oFile  << count;
                    count++;
                    oFile << "       ";
                    for( int z = 0; z < size - 10; z++ ) {
                        outputChar( oFile, size, c );
                    }
                    oFile << endl;
                    oFile << right << setfill(' ') << setw(2);        
                    oFile   << count;
                    count++;
                    oFile << "       ";
                    for( int z = 0; z < size - 10; z++ ) {
                        outputChar( oFile, size, c );
                    }
                }
                else if( o == 1 || o == 3 ) {
                    if( sie == 0 ) {
                        if( o == 3 ) {
                            oFile << endl;
                            while( num < ((siONE)-3)) {
                                oFile << right;           
                                oFile << setfill(' ') ;        
                                   oFile  << setw(2 );
                  
                                oFile << count << "  ";
                              
                                count++;
                                int i = 0;
                                while(i < size ) {
                                    if( i < 5 || i> size-6 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                    i++ ;
                                }
                                oFile<< endl;
                                
                                num++;
                            }   
                            num = 0;
                        }
                        else{
                            oFile << endl;
                            while( num < ((siONE)-3)) {
                                oFile << right;           
                                oFile << setfill(' ') ;        
                                   oFile  << setw(2 );
                  
                                oFile << count << "  ";
                              
                                count++;
                                int i = 0;
                                while(i < size ) {
                                    if( i < 5 || i> size-6 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                     i++ ;
                                }
                                oFile << endl;
                                
                                num++;
                            }   
                            num = 0;
                        }
                        
                    }
                    else{
                        oFile << endl;
                       
                        while( num < ((siONE)-1)) {
                            oFile << right;           
                            oFile << setfill(' ') ;        
                                   oFile  << setw(2 );
                  
                            oFile << count;
                            oFile << "  ";
                            count++;
                            int i= 0;
                            while(i< size ) {
                                if(i< 5 || i > size-6 ) {  
                                    outputChar( oFile, size, c );
                                }
                                else{
                                    oFile << " ";
                                }  
                                i++ ;
                            }
                            oFile<< endl;
                            
                            num++;
                        }
                        num = 0;
                    }
                }
                
            }
        }
        if( ( sd(size, 10) ) == 3 ) {
            for( int o = 0; o < 5; o++ ) {
                if( o== 0 || o== 2 || o== 4 ) {
                    oFile << right << setfill(' ')<< setw(2) ;        
                    oFile  << count;
                    count++;
                    oFile << "     ";
                    for( int z = 0; z < size - 6; z++ ) {
                        outputChar( oFile, size, c );
                    }
                }
                else if( o== 1 ||o== 3 ) {
                    if( sie == 0 ) {
                       if( o == 3 ) {
                            oFile <<endl;
                            while(num < ((siONE)-1)) {
                                oFile << right;           
                                oFile << setfill(' ') ;        
                                   oFile  << setw(2 );
                  
                                oFile << count << "  ";
                              
                                count++;
                                int  i= 0;
                                while(i < size) {
                                    if( i< 3 || i> size-4 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                     i++ ;
                                }
                                oFile <<endl;
                                
                                num++;
                            }   
                             num= 0;
                        }
                        else {
                            oFile <<endl;
                            while( num< ((siONE)-2)) {
                                oFile << right;           
                                oFile << setfill(' ') ;        
                                   oFile  << setw(2 );
                  
                                oFile << count << "  ";
                              
                                count++;
                                int i = 0;
                                while(i< size) {
                                    if( i< 4 ||i> size-5 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                     i++ ;
                                }
                                oFile <<endl;
                                
                                num++;
                            }   
                         num= 0;
                        }
                        
                    }
                    else{
                        oFile <<endl;
                        
                        while( num < ((siONE)-1)) {
                            oFile << right;           
                            oFile << setfill(' ') ;        
                                   oFile  << setw(2 );
                  
                            oFile << count;
                            oFile << "  ";
                            count++;
                            int i = 0;
                            while(i< size) {
                                if(i< 3 ||i> size-4 ) {  
                                    outputChar( oFile, size, c );
                                }
                                else{
                                    oFile << " ";
                                }  
                                 i++ ;
                            }
                            oFile <<endl;
                            num++;
                        }
                        num= 0;
                    }
                }
            }
        }
        if( ( sd(size, 10) ) == 6 ) {
          

            for( int o = 0; o < 5; o++ ) {
                if(o == 0 || o == 2 || o ==4) {
                    oFile << right << setfill(' ')<< setw(2) ;        
                    oFile  << count;
                    count++;
                    oFile << "     ";
                    for( int z = 0; z < size - 6; z++ ) {
                        outputChar( oFile, size, c );
                    }
                }
                else if( o == 1 || o == 3 ) {
                    if( sie == 0 ) {
                      if( o == 3 ) {
                            oFile<< endl;
                            while( num < ((siONE)-1)) {
                                oFile << right;           
                                oFile << setfill(' ') ;        
                                   oFile  << setw(2 );
                  
                                oFile << count << "  ";
                              
                                count++;
                                int  i= 0;
                                while(i < size) {
                                    if( i< 3 || i> size-4 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                     i++ ;
                                }
                                oFile << endl;
                                
                                num++;
                            }   
                            num = 0;
                        }
                        else{
                            oFile << endl;
                            while( num < ((siONE)-2)) {
                                oFile << right;           
                                oFile << setfill(' ') ;        
                                   oFile  << setw(2 );
                  
                                oFile << count << "  ";
                              
                                count++;
                                int  i= 0;
                                while(i < size) {
                                    if( i< 3 || i> size-4 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                     i++ ;
                                }
                                oFile<< endl;
                                
                                num++;
                            }   
                            num = 0;
                        }
                        
                    }
                    else{
                        oFile << endl;
                        
                        while( num < ((siONE)-1)) {
                            oFile << right;           
                            oFile << setfill(' ') ;        
                                   oFile  << setw(2 );
                  
                            oFile << count;
                            oFile << "  ";
                            count++;
                            int i = 0;
                            while(i< size) {
                                if(i< 3 ||i> size-4 ) {  
                                    outputChar( oFile, size, c );
                                }
                                else{
                                    oFile << " ";
                                }  
                                 i++ ;
                            }
                            oFile << endl;
                            
                            num++;
                        }
                        num = 0;
                    }
                }
                
            }
        }
        
        
        if( ( sd(size, 10) ) == 9 ) {
          for( int o = 0; o < 5; o++ ) {
                if( o == 0 || o == 2 || o == 4 ) {
                    oFile << right << setfill(' ')<< setw(2) ;        
                    oFile  << count;
                    count++;
                    oFile << "           ";
                    int s = 0;
                    while(s < 3 ){
                    for( int i = 0; i< size  - 18; i++ ) {
                        outputChar( oFile, size, c );
                    }
                    oFile << endl;
                    oFile << right << setfill(' ') << setw(2);        
                    oFile   << count;
                    count++;
                    oFile << "           ";
                    
                    s++;
                    }
                    for( int i = 0; i  < size  - 18; i++ ) {
                        outputChar( oFile, size, c );
                    }
                }
                else if( o == 1 || o == 3 ) {
                    if( sie == 0 ) {
                        if( o == 3 ) {
                            oFile << endl;
                            while( num < ((siONE)-6)) {
                                oFile << right;           
                                oFile << setfill(' ') ;        
                                   oFile  << setw(2 );
                  
                                oFile << count << "  ";
                              
                                count++;
                                int i = 0;
                                while(i< size) {
                                    if( i <9 || i> size-10 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                    i++ ;
                                }
                                oFile << endl;
                                
                                num++;
                            }   
                            num = 0;
                        }
                        else {
                            oFile << endl;
                            while( num < ((siONE)-6)) {
                                oFile << right;           
                                oFile << setfill(' ') ;        
                                   oFile  << setw(2 );
                  
                                oFile << count << "  ";
                              
                                count++;
                                int i = 0;
                                while(i< size) {
                                    if( i <9 || i> size-10 ) {  
                                        outputChar( oFile, size, c );
                                    }
                                    else{
                                        oFile << " ";
                                    }  
                                     i++ ;
                                }
                                oFile << endl;
                                
                                num++;
                            }   
                            num = 0;
                        }
                        
                    }
                    else{
                        oFile << endl;
                       
                        while( num < ((siONE)-1)) {
                            oFile << right;           
                            oFile << setfill(' ') ;        
                                   oFile  << setw(2 );
                  
                            oFile << count;
                            oFile << "  ";
                            count++;
                            int i = 0;
                            while(i < size) {
                                if( i< 7 || i> size-8 ) {  
                                    outputChar( oFile, size, c );
                                }
                                else{
                                    oFile << " ";
                                }  
                                 i++ ;
                            }
                            oFile << endl;
                            
                            num++;
                        }
                        num = 0;
                    }
                }
            }
        }
    
    oFile << endl;
    oFile << endl;
    oFile << "    ";
     count = 1;
  
   x= 0;
  
  
  // This creates the bottom row of numbers
  while(x != size){
    
    oFile << count;
    x++;
    count++;
    if(count == 10){
      count = 0;
    }
  }
    return;
          }
   

// function documentation here
void outputChar(ofstream& of, int count, char l){

  of << l;
  // output this in create output file?
  // output a character 
  // this below was a unused idea
  // take in integer value, and also symbol
  // then give it to a output file
  // use it to make 8 and triangle
  // pass in 7  ' ' 
}

// function documentation here
void makeTriangle( ofstream& oFile, int size, char c ){
    oFile << "Symbol: Triangle  Size: " << size << " Character: '" << c << "'\n" << "    ";

    int counter = 1;
  
  int x= 0;
  
  // creates a top number line
  
  while(x != (size*2)){
    
    oFile << counter;
    x++;
    counter++;
    if(counter == 10){
      
      counter = 0;
    }
  }
  oFile <<endl;
  oFile << endl;

    int triangleNums = 0, rowCount = 1;
// after taking in values
    for(int k = 1; k <= size-1; k++) {
        oFile << setfill(' ') << setw(2) << right << rowCount;
        for(int j = k; j < size; j++) {
            oFile << " ";
        }
        int kdva = k*2;
// we use and check the values and use this equation to check if the numbers are within a certain range
        while(triangleNums != (kdva - 1)) {
            if(triangleNums == 0) {
                oFile << " ";
                outputChar( oFile, size, c );
                outputChar( oFile, size, c );
            }
            

            if(triangleNums == kdva - 2) {
                
                outputChar( oFile, size, c );
                outputChar( oFile, size, c );
            }
            else{
                oFile << " ";
            }
            
            
            triangleNums++;
        }
        triangleNums = 0;
        oFile << endl;
        rowCount++;
    }
    oFile << setfill ( ' ') << setw ( 2) <<  right << rowCount << "  ";
    for(int k = 0; k <= ( 2 * size ) - 1 ; k++) {
// creates the bottom line of the square using the proper characters
        outputChar( oFile, size, c );

    }
    oFile << endl << endl;
    oFile << "    ";
   counter = 1;
  
   x= 0;
  // creates bottom number line
 
  
  while(x != (size*2)){
    oFile << counter;
    x++;
    counter++;
    if(counter == 10){  
      counter = 0;
    }
  }
  oFile <<endl;
  oFile << endl;
}
// function documentation here
/*
this function is for the slash it takes in the value of the size and char 
from the data read in

*/
void makeSlash( ofstream& oFile, int size, char c){

  oFile << "Symbol: Slash " << "Size : " << size;
  oFile << " Character: " << '"' << c << '"' << endl;
  int counter = 1;
  int x= 0;
  oFile << "    ";
  while(x != size){
      // creates the number line at the top
    oFile << counter;
    x++;
    counter++;
    if(counter == 10){ 
      counter = 0;
    }
  }
  oFile <<endl;
  oFile << endl;
  int rowCount = 1;
  for(int k = 1; k <= size; k++){
      // this here will create the left column
      // number line

      oFile << setfill(' ') << setw(2) << right << rowCount;
    for(int j = 1; j <= size; j++){
              if(j <= ( size +1-k)){
                if( j == (size +1-k)){
                    // these calculations will workout
                    // checking the value we are at 
                    // ensuring as we move 
                    // down we move left
                  oFile << "  ";
                  outputChar(oFile, size, c);
                }
                else{
                  oFile << " ";
                }
              }
            }
            oFile <<endl;
            rowCount++;
  }
  oFile << endl;
   counter = 1;
  // bottom number line
 x= 0;
 
  oFile<< "    ";

  while(x != size){
    
    oFile << counter;
    x++;
    counter++;
    if(counter == 10){
     
      counter = 0;
    }
  }
}