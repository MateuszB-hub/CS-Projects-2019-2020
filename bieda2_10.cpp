/*
Mateusz Bieda
Description: This program is meant to be a city builder game something
like sim city or cities skylines
Where the user enters blocks in the game they want to replace with different kinds
of resources and the resources provide and take away certain benefits
The total score is given at the end multiplying the popularity by the lowest
scored resource
This focuses on using enums and structs together to acheive the goal
of higher levels of data management 
Input: User inputs the block and then the kind of resource that will
take over that block, very simple. It is done by a int zone
type variable that matches to the enums, 
and the limits are created to ensure that nothing goes out of bounds

There is also input checks that what the user enters is
within the bounds and a valid value for the datatype

In addition there is a score output that keeps the user up to date
by the getscore function,  that uses the lowest resource value, and 
multiplies it by the popularity value giving out the score at the 
time

Output: There is a lot, the chart is created by a for loop and using arrays
then the current score and colony status is updated by the getscore
function and getResourceTotals function


Program Header Here
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//Constants
const int RESOURCE_TYPES = 4;
enum resourceTypes {POPULARITY, ECOLOGY, COMMERCE, INDUSTRY};

const int UPGRADE_COUNT = 6;

//Colony Array is Height x Width
const int COLONY_HEIGHT = 4;
const int COLONY_WIDTH = 5;

//insert improvement struct here
struct improvement{
    string name;
    int collects[RESOURCE_TYPES];
    int develops[RESOURCE_TYPES];
};

//insert sector struct here
struct sector{
    int resources[RESOURCE_TYPES];
    improvement zone;
};

//function prototype
void printColony(const sector[][COLONY_WIDTH]);
void getResourceTotals(const sector[][COLONY_WIDTH], int[], int);
int getScore(int[], int);
void placeImprovement(sector[][COLONY_WIDTH], improvement, int, int);

//Handles I/O with user as well as the game loop
int main()
{
	sector colony[COLONY_HEIGHT][COLONY_WIDTH];
	int resourceTotals[RESOURCE_TYPES];
	//Sector Improvements
	improvement upgrades[UPGRADE_COUNT];
	upgrades[0] = {"Wilderness",{0,0,0,0}, { 0, 0, 0, 0}};
	upgrades[1] = {"Settlement",{1,1,1,1}, { 0, 0, 0, 0}};
	upgrades[2] = {"Farm",{0,2,0,0}, { 1, 1,-1,-1}};
	upgrades[3] = {"Mine",{0,0,0,2}, {-1,-1, 1, 1}};
	upgrades[4] = {"City",{0,0,2,0}, { 0,-1, 2,-1}};
	upgrades[5] = {"Resort",{2,0,0,0}, { 1, 1, 0,-2}};
	
	//Seed Random Number Generator
	srand(time(NULL));

	//Initialize sector resource values to random amounts from 0-3
	for(int i=0; i<COLONY_HEIGHT; i++)
	{
		for(int j=0; j<COLONY_WIDTH; j++)
		{
			colony[i][j].zone = upgrades[0];
			for(int k=0; k<RESOURCE_TYPES; k++)
			{
				int randomAmount = rand()%100;
				if(randomAmount >= 95)
				{
					colony[i][j].resources[k] = 3;
				}
				else if(randomAmount >= 80)
				{
					colony[i][j].resources[k] = 2;
				}
				else if(randomAmount >= 50)
				{
					colony[i][j].resources[k] = 1;
				}
				else
				{
					colony[i][j].resources[k] = 0;
				}
			}
		}
	}
	
	//Allows user to select 12 improvements to the colony then provides a final score
	for(int i=12; i>0; i--)
	{
		//Colony Status
    	printColony(colony);
    	
    	getResourceTotals(colony,resourceTotals,RESOURCE_TYPES);
    	
    	cout << "Colony Status: ";
        cout << "[" << resourceTotals[POPULARITY] << " Popularity] ";
	    cout << "[" << resourceTotals[ECOLOGY] << " Ecology] ";
	    cout << "[" << resourceTotals[COMMERCE] << " Commerce] ";
	    cout << "[" << resourceTotals[INDUSTRY] << " Industry] ";
    	cout << "\nCurrent Score: " << getScore(resourceTotals, RESOURCE_TYPES) << endl;
    	
		//Improvement Selection Menu
        cout << "Place Improvement ("<<i<<"/12)\n";
    	cout << "[1] Settlement (Px1 Ex1 Cx1 Ix1)(P 0 E 0 C 0 I 0)\n";
    	cout << "[2] Farm       (Px0 Ex2 Cx0 Ix0)(P+1 E+1 C-1 I-1)\n";
    	cout << "[3] Mine       (Px0 Ex0 Cx0 Ix2)(P-1 E-1 C+1 I+1)\n";
    	cout << "[4] City       (Px0 Ex0 Cx2 Ix0)(P 0 E-1 C+2 I-1)\n";
    	cout << "[5] Resort     (Px2 Ex0 Cx0 Ix0)(P+1 E+1 C 0 I-2)\n";
    	
		//User Selects Improvement to Build
    	int zoneType = 0;
    	do
    	{
    	    cout << "Select improvement to construct(1-"<<UPGRADE_COUNT-1<<"): ";
    	    cin >> zoneType;
    	    if(cin.fail())
    	    {
    	        cout << "Invalid improvement type, please try again.\n";
    	        cin.clear();
    	        cin.ignore(100000,'\n');
    	    }
    	}
    	while(zoneType <= 0 || zoneType > UPGRADE_COUNT);
    	cin.ignore(100000,'\n');
    	
		//User Selects Location to Build Improvement
    	string location;
    	int x, y;
    	do
    	{
    	    cout << "Construct "<<upgrades[zoneType].name<<" location: ";
            cin >> location;
            if(location.length() == 2)
            {
				//Allows location to be selected with either lower or upper case coordinate value
                if(location[1] >= 'a' && location[1] <= 'z')
                {
                    location[1]-='a'-'A';
                }
				//Converts user input to coordinates
                x = location[1]-'A';
                y = location[0]-'1';
				
				//Ensures coordinates are within the colony bounds
                if(y >= 0 && y < COLONY_HEIGHT && x >= 0 && x < COLONY_WIDTH)
                {
                    break;
                }
                else
                {
                    cout << "Invalid location, please try again.\n";
                }
            }
            else
            {
                cout << "Invalid location, please try again.\n";
            }
    	}
    	while(true);
    	cin.ignore(100000,'\n');
    	
	    placeImprovement(colony,upgrades[zoneType],x,y);
	}
	
	//Final Status of Colony
	printColony(colony);
	
	getResourceTotals(colony,resourceTotals,RESOURCE_TYPES);
	
	cout << "\nFinished Colony: ";
	cout << "[" << resourceTotals[POPULARITY] << " Popularity] ";
	cout << "[" << resourceTotals[ECOLOGY] << " Ecology] ";
	cout << "[" << resourceTotals[COMMERCE] << " Commerce] ";
	cout << "[" << resourceTotals[INDUSTRY] << " Industry] ";
	cout << "\nFinal Score: " << getScore(resourceTotals, RESOURCE_TYPES) << endl;
}

//Prints the sectors of the colony in tabular format
void printColony(const sector colony[][COLONY_WIDTH])
{
	for(int i=0; i<COLONY_HEIGHT; i++)
	{
		for(int j=0; j<COLONY_WIDTH; j++)
		{
			cout << "+----" << i+1 << static_cast<char>('A'+j);
			cout << "----+ ";
		}
		cout << endl;
	
		for(int j=0; j<COLONY_WIDTH; j++)
		{
			cout << "|";
			uint spaces = 10 - colony[i][j].zone.name.length();
			for(uint k=0; k<spaces/2; k++)
			{
			    cout << " ";
			}
			cout << colony[i][j].zone.name;
			for(uint k=0; k < spaces - spaces/2; k++)
			{
			    cout << " ";
			}
			cout << "| ";
		}
		cout << endl;
		
		for(int j=0; j<COLONY_WIDTH; j++)
		{
			cout << "|POP: " << colony[i][j].zone.collects[POPULARITY];
			cout << " x" << setw(2) << colony[i][j].resources[POPULARITY] <<"| ";
		}
		cout << endl;
		
		for(int j=0; j<COLONY_WIDTH; j++)
		{
			cout << "|ECO: " << colony[i][j].zone.collects[ECOLOGY];
			cout << " x" << setw(2) << colony[i][j].resources[ECOLOGY] <<"| ";	
		}
		cout << endl;
		
		for(int j=0; j<COLONY_WIDTH; j++)
		{
			cout << "|COM: " << colony[i][j].zone.collects[COMMERCE];
			cout << " x" << setw(2) << colony[i][j].resources[COMMERCE] <<"| ";	
		}
		cout << endl;

		for(int j=0; j<COLONY_WIDTH; j++)
		{			
			cout << "|IND: "<< colony[i][j].zone.collects[INDUSTRY];
			cout << " x" << setw(2) << colony[i][j].resources[INDUSTRY] <<"| ";	
		}
		cout << endl;
	}
	
	for(int j=0; j<COLONY_WIDTH; j++)
	{
		cout << "+----------+ ";
	}
	cout << endl;

    return;
}

void getResourceTotals(const sector colony[][COLONY_WIDTH], int resourceTotals[], int resourceCount){
/*
This here gets the resouce totals for each of the resource types
setting the values to 0 at the start to not have left over values 
from past calculations, using the counter controlled while loops 
to go through and check the needed block with its assocaited values

*/
int placement= resourceCount;
placement++;
     resourceTotals[POPULARITY]= 0;
     resourceTotals[ECOLOGY]= 0;
     resourceTotals[COMMERCE]= 0;
     resourceTotals[INDUSTRY]= 0;
int t = 0;
     while(t < COLONY_HEIGHT){  
       int g = 0;
         while(g < COLONY_WIDTH){
         
         
		 resourceTotals[POPULARITY]+= (colony[t][g].zone.collects[POPULARITY]* colony[t][g].resources[POPULARITY]);
		 resourceTotals[ECOLOGY]+= (colony[t][g].zone.collects[ECOLOGY]* colony[t][g].resources[ECOLOGY]);
		 resourceTotals[COMMERCE]+= (colony[t][g].zone.collects[COMMERCE]* colony[t][g].resources[COMMERCE]);
		 resourceTotals[INDUSTRY]+= (colony[t][g].zone.collects[INDUSTRY]* colony[t][g].resources[INDUSTRY]);

        g++;
        }
    t++;
     }
     return;
}

int getScore(int resources[], int resourceCount){
  /*
  This is used to check if every resource type is below 
  other resources, then if one conditional evaluates to true then 
  the lowest resource is multiplied by popularity, this
  works with every instance that get Score is called 
  and keeps the score as low as possible
  */
    int negate = 0;
    resourceCount = 0;

    //this ensures if popularity is less than negate it does not stay negative
    if(resources[POPULARITY] <= negate) {
         return   negate;
    }
    else if(resources[COMMERCE] <=resources[ECOLOGY]){
        if(resources[COMMERCE]<= resources[INDUSTRY]){
           if(resources[COMMERCE] <negate) {
             return  negate;
        }
        resourceCount= resources[POPULARITY]* resources[COMMERCE];
         return resourceCount;
      }
    }
      else if(resources[ECOLOGY] <=resources[COMMERCE]){
           if(resources[ECOLOGY]<= resources[INDUSTRY]){
            if(resources[ECOLOGY] <negate) {
             return  negate;
        }
        resourceCount=resources[POPULARITY]* resources[ECOLOGY];
          return resourceCount;
        }
    }
    else if(resources[INDUSTRY] <=resources[COMMERCE]){
        if(resources[INDUSTRY]<= resources[ECOLOGY]){
           if(resources[INDUSTRY] <=negate) {
             return  negate;
        }
         resourceCount= resources[POPULARITY]* resources[INDUSTRY];
          return resourceCount;
      }
    }
    
    
    
  return resourceCount;
}

void placeImprovement(sector colony[][COLONY_WIDTH], improvement newZone, int x, int y){
  /*The Big One 
  This here goes and checks whatever the input block is
  with whatever resource the user wants there, this will check 
  one by one, what the values are, what the block is currently
  occupied by and change the values accordingly with what 
  the resource adds or takes away, Moreover, it also has
  a check within here to ensure that when nearby blocks 
  are being checked we do not go out of bounds
  (that would be a nightmate, a simple one but still) 

  That's about it I think, umm its kind of like one of 
  the previous assignments where we had to use
  while loops to check the dice rolls
  I forget which atm...

  */
int t = y - 1;
while(t <= y + 1) {  
  int g = x - 1;
        while(g <= x + 1)  {// checks the boundaries
      
             if ((t >= 0 && t < COLONY_HEIGHT )== false){
            g++;
            continue;
             }
             if((g >= 0 && g < COLONY_WIDTH)== false){
                 g++;
            continue;
             }
        // if the colony is this one nothing should be changed
            if(colony[y][x].zone.name== "Wilderness") {
                  g++;
                  continue;
            }

            // If its any of these thne certain resource values are added
            // and subtracted depending on the current colony block
            // This is basically the rest of the function, but changed around 
            // values that are checked if there is a new colony being 
            // introduced, 
            else if(colony[y][x].zone.name== "Settlement") {
             g++;
             continue;
            }
            else if(colony[y][x].zone.name== "City") {
              
                colony[t][g].resources[ECOLOGY] =colony[t][g].resources[ECOLOGY]+ 1;
                colony[t][g].resources[COMMERCE] =colony[t][g].resources[COMMERCE]- 2;
                colony[t][g].resources[INDUSTRY] =colony[t][g].resources[INDUSTRY]+ 1;
            }
            else if(colony[y][x].zone.name== "Farm") {
                colony[t][g].resources[POPULARITY] =colony[t][g].resources[POPULARITY]- 1;
                colony[t][g].resources[ECOLOGY] =colony[t][g].resources[ECOLOGY]- 1;
                colony[t][g].resources[COMMERCE] =colony[t][g].resources[COMMERCE]+ 1;
                colony[t][g].resources[INDUSTRY] =colony[t][g].resources[INDUSTRY]+ 1;
            }
            else if(colony[y][x].zone.name== "Resort") {
                colony[t][g].resources[POPULARITY] =colony[t][g].resources[POPULARITY]- 1;
                colony[t][g].resources[ECOLOGY] =colony[t][g].resources[ECOLOGY]- 1;
                
                colony[t][g].resources[INDUSTRY] =colony[t][g].resources[INDUSTRY]+ 2;
            }
            else if(colony[y][x].zone.name== "Mine") {
                colony[t][g].resources[POPULARITY] =colony[t][g].resources[POPULARITY]+ 1;
                colony[t][g].resources[ECOLOGY] =colony[t][g].resources[ECOLOGY] + 1;
                colony[t][g].resources[COMMERCE] =colony[t][g].resources[COMMERCE]-1;
                colony[t][g].resources[INDUSTRY] =colony[t][g].resources[INDUSTRY]- 1;
            }
            
            
        g++;
        }
    t++;
    }
t = y - 1;
    while( t <= y + 1) {
      int g = x - 1;   
        while(g <= x + 1)  {
             if ((t >= 0 && t < COLONY_HEIGHT )== false){
            g++;
            continue;
             }
             if((g >= 0 && g < COLONY_WIDTH)== false){
                 g++;
            continue;
             }
           // If its any of these thne certain resource values are added
            // and subtracted depending on the current colony block
           	  if(newZone.name=="Settlement")
		  {
              g++;
                  continue;
		}
             else if(newZone.name== "Farm") {
                colony[t][g].resources[POPULARITY] =colony[t][g].resources[POPULARITY]+ 1;
                colony[t][g].resources[ECOLOGY] =colony[t][g].resources[ECOLOGY]+ 1;
                colony[t][g].resources[COMMERCE] =colony[t][g].resources[COMMERCE]-1;
                colony[t][g].resources[INDUSTRY] =colony[t][g].resources[INDUSTRY]- 1;
            }
            else if(newZone.name== "Resort") {
                colony[t][g].resources[POPULARITY] =colony[t][g].resources[POPULARITY]+ 1;
                colony[t][g].resources[ECOLOGY] =colony[t][g].resources[ECOLOGY]+ 1;
                
                colony[t][g].resources[INDUSTRY] =colony[t][g].resources[INDUSTRY]- 2;
            }
            else if(newZone.name== "Mine") {
                colony[t][g].resources[POPULARITY] =colony[t][g].resources[POPULARITY]- 1;
                colony[t][g].resources[ECOLOGY] =colony[t][g].resources[ECOLOGY]- 1;
                colony[t][g].resources[COMMERCE] = colony[t][g].resources[COMMERCE]+ 1;
                colony[t][g].resources[INDUSTRY] = colony[t][g].resources[INDUSTRY]+ 1;
            }
            else if(newZone.name== "City") {
               
                colony[t][g].resources[ECOLOGY] =colony[t][g].resources[ECOLOGY]- 1;
                colony[t][g].resources[COMMERCE] =colony[t][g].resources[COMMERCE]+ 2;
                colony[t][g].resources[INDUSTRY] =colony[t][g].resources[INDUSTRY]- 1;
            }
            
        g++;
        }
    t++;
    }
     // If its any of these thne certain resource values are added
            // and subtracted depending on the current colony block
if(colony[y][x].zone.name== "Wilderness") {
        if(newZone.name== "Settlement") {
               colony[y][x].zone.name= "Settlement";
            colony[y][x].zone.collects[POPULARITY]=colony[y][x].zone.collects[POPULARITY]+ 1;
            colony[y][x].zone.collects[ECOLOGY]=colony[y][x].zone.collects[ECOLOGY]+ 1;
            colony[y][x].zone.collects[COMMERCE]=colony[y][x].zone.collects[COMMERCE]+ 1;
            colony[y][x].zone.collects[INDUSTRY]=colony[y][x].zone.collects[INDUSTRY]+ 1;
        }
        else if(newZone.name== "Farm") {
               colony[y][x].zone.name= "Farm";
            colony[y][x].zone.collects[ECOLOGY]=colony[y][x].zone.collects[ECOLOGY]+ 2;
        }
        else if(newZone.name== "Resort") {
               colony[y][x].zone.name= "Resort";
            colony[y][x].zone.collects[POPULARITY]=colony[y][x].zone.collects[POPULARITY]+ 2;
        }
        else if(newZone.name== "Mine") {
               colony[y][x].zone.name= "Mine";
            colony[y][x].zone.collects[INDUSTRY]=colony[y][x].zone.collects[INDUSTRY]+ 2;
        }
        else if(newZone.name== "City") {
               colony[y][x].zone.name= "City";
            colony[y][x].zone.collects[COMMERCE]=colony[y][x].zone.collects[COMMERCE]+ 2;
        }
        
    }
     // If its any of these thne certain resource values are added
            // and subtracted depending on the current colony block
    else if(colony[y][x].zone.name== "Settlement") {
        colony[y][x].zone.collects[POPULARITY]=colony[y][x].zone.collects[POPULARITY]- 1;
            colony[y][x].zone.collects[ECOLOGY]=colony[y][x].zone.collects[ECOLOGY]-1;
            colony[y][x].zone.collects[COMMERCE]=colony[y][x].zone.collects[COMMERCE]-1;
            colony[y][x].zone.collects[INDUSTRY]=colony[y][x].zone.collects[INDUSTRY]-1;
        if(newZone.name== "Settlement") {
               colony[y][x].zone.name= "Settlement";
            colony[y][x].zone.collects[POPULARITY]=colony[y][x].zone.collects[POPULARITY]+ 1;
            colony[y][x].zone.collects[ECOLOGY]=colony[y][x].zone.collects[ECOLOGY]+ 1;
            colony[y][x].zone.collects[COMMERCE]=colony[y][x].zone.collects[COMMERCE]+ 1;
            colony[y][x].zone.collects[INDUSTRY]=colony[y][x].zone.collects[INDUSTRY]+ 1;
        }
        else if(newZone.name== "Farm") {
               colony[y][x].zone.name= "Farm";
            colony[y][x].zone.collects[ECOLOGY]=colony[y][x].zone.collects[ECOLOGY]+ 2;
        }
        else if(newZone.name== "City") {
               colony[y][x].zone.name= "City";
            colony[y][x].zone.collects[COMMERCE]=colony[y][x].zone.collects[COMMERCE]+ 2;
        } 
        else if(newZone.name== "Mine") {
               colony[y][x].zone.name= "Mine";
            colony[y][x].zone.collects[INDUSTRY]=colony[y][x].zone.collects[INDUSTRY]+ 2;
        }
        else if(newZone.name== "Resort") {
               colony[y][x].zone.name= "Resort";
            colony[y][x].zone.collects[POPULARITY]=colony[y][x].zone.collects[POPULARITY]+ 2;
        }
        
        
    }
     // If its any of these thne certain resource values are added
            // and subtracted depending on the current colony block
    else if(colony[y][x].zone.name== "Farm") {
        colony[y][x].zone.collects[ECOLOGY]=colony[y][x].zone.collects[ECOLOGY]-2;
        if(newZone.name== "Settlement") {
               colony[y][x].zone.name= "Settlement";
            colony[y][x].zone.collects[POPULARITY]=colony[y][x].zone.collects[POPULARITY]+ 1;
            colony[y][x].zone.collects[ECOLOGY]=colony[y][x].zone.collects[ECOLOGY]+ 1;
            colony[y][x].zone.collects[COMMERCE]=colony[y][x].zone.collects[COMMERCE]+ 1;
            colony[y][x].zone.collects[INDUSTRY]=colony[y][x].zone.collects[INDUSTRY]+ 1;
        }
        else if(newZone.name== "Mine") {
               colony[y][x].zone.name= "Mine";
            colony[y][x].zone.collects[INDUSTRY]=colony[y][x].zone.collects[INDUSTRY]+ 2;
        }
        else if(newZone.name== "Farm") {
               colony[y][x].zone.name= "Farm";
            colony[y][x].zone.collects[ECOLOGY]=colony[y][x].zone.collects[ECOLOGY]+ 2;
        }
        
        else if(newZone.name== "Resort") {
               colony[y][x].zone.name= "Resort";
            colony[y][x].zone.collects[POPULARITY]=colony[y][x].zone.collects[POPULARITY]+ 2;
        }
        else if(newZone.name== "City") {
               colony[y][x].zone.name= "City";
            colony[y][x].zone.collects[COMMERCE]=colony[y][x].zone.collects[COMMERCE]+ 2;
        }
        
    }
     // If its any of these thne certain resource values are added
            // and subtracted depending on the current colony block
    else if(colony[y][x].zone.name== "Resort") {
        colony[y][x].zone.collects[POPULARITY]=colony[y][x].zone.collects[POPULARITY]-2;
        if(newZone.name== "Settlement") {
               colony[y][x].zone.name= "Settlement";
            colony[y][x].zone.collects[POPULARITY]=colony[y][x].zone.collects[POPULARITY]+ 1;
            colony[y][x].zone.collects[ECOLOGY]=colony[y][x].zone.collects[ECOLOGY]+ 1;
            colony[y][x].zone.collects[COMMERCE]=colony[y][x].zone.collects[COMMERCE]+ 1;
            colony[y][x].zone.collects[INDUSTRY]=colony[y][x].zone.collects[INDUSTRY]+ 1;
        }
        else if(newZone.name== "Farm") {
                colony[y][x].zone.name= "Farm";
            colony[y][x].zone.collects[ECOLOGY]=colony[y][x].zone.collects[ECOLOGY]+ 2;
        }
        else if(newZone.name== "Resort") {
                colony[y][x].zone.name= "Resort";
            colony[y][x].zone.collects[POPULARITY]=colony[y][x].zone.collects[POPULARITY]+ 2;
        }
        
        else if(newZone.name== "City") {
                colony[y][x].zone.name= "City";
            colony[y][x].zone.collects[COMMERCE]=colony[y][x].zone.collects[COMMERCE]+ 2;
        }
        else if(newZone.name== "Mine") {
                colony[y][x].zone.name= "Mine";
            colony[y][x].zone.collects[INDUSTRY]=colony[y][x].zone.collects[INDUSTRY]+ 2;
        }
        
    }
     // If its any of these thne certain resource values are added
            // and subtracted depending on the current colony block
    else if(colony[y][x].zone.name== "City") {
        colony[y][x].zone.collects[COMMERCE]=colony[y][x].zone.collects[COMMERCE]-2;
        if(newZone.name== "Settlement") {
               colony[y][x].zone.name= "Settlement";
            colony[y][x].zone.collects[POPULARITY]=colony[y][x].zone.collects[POPULARITY]+ 1;
            colony[y][x].zone.collects[ECOLOGY]=colony[y][x].zone.collects[ECOLOGY]+ 1;
            colony[y][x].zone.collects[COMMERCE]=colony[y][x].zone.collects[COMMERCE]+ 1;
            colony[y][x].zone.collects[INDUSTRY]=colony[y][x].zone.collects[INDUSTRY]+ 1;
        }
        if(newZone.name== "Farm") {
               colony[y][x].zone.name= "Farm";
            colony[y][x].zone.collects[ECOLOGY]=colony[y][x].zone.collects[ECOLOGY]+ 2;
        }
        else if(newZone.name== "Mine") {
               colony[y][x].zone.name= "Mine";
            colony[y][x].zone.collects[INDUSTRY]=colony[y][x].zone.collects[INDUSTRY]+ 2;
        }
        else if(newZone.name== "Resort") {
               colony[y][x].zone.name= "Resort";
            colony[y][x].zone.collects[POPULARITY]=colony[y][x].zone.collects[POPULARITY]+ 2;
        }
        else if(newZone.name== "City") {
               colony[y][x].zone.name= "City";
            colony[y][x].zone.collects[COMMERCE]=colony[y][x].zone.collects[COMMERCE]+ 2;
        }
        
    }
     // If its any of these thne certain resource values are added
            // and subtracted depending on the current colony block
    else if(colony[y][x].zone.name== "Mine") {
        colony[y][x].zone.collects[INDUSTRY]=colony[y][x].zone.collects[INDUSTRY]-2;
        if(newZone.name== "Settlement") {
               colony[y][x].zone.name= "Settlement";
            colony[y][x].zone.collects[POPULARITY]=colony[y][x].zone.collects[POPULARITY]+ 1;
            colony[y][x].zone.collects[ECOLOGY]=colony[y][x].zone.collects[ECOLOGY]+ 1;
            colony[y][x].zone.collects[COMMERCE]=colony[y][x].zone.collects[COMMERCE]+ 1;
            colony[y][x].zone.collects[INDUSTRY]=colony[y][x].zone.collects[INDUSTRY]+ 1;
        }
        if(newZone.name== "Farm") {
               colony[y][x].zone.name= "Farm";
            colony[y][x].zone.collects[ECOLOGY]=colony[y][x].zone.collects[ECOLOGY]+ 2;
        }
        else if(newZone.name== "Resort") {
               colony[y][x].zone.name= "Resort";
            colony[y][x].zone.collects[POPULARITY]=colony[y][x].zone.collects[POPULARITY]+ 2;
        }
        else if(newZone.name== "City") {
               colony[y][x].zone.name= "City";
            colony[y][x].zone.collects[COMMERCE]=colony[y][x].zone.collects[COMMERCE]+ 2;
        }
        else if(newZone.name== "Mine") {
               colony[y][x].zone.name= "Mine";
            colony[y][x].zone.collects[INDUSTRY]=colony[y][x].zone.collects[INDUSTRY]+ 2;
        }
        
        
    }
    
    

return;
}