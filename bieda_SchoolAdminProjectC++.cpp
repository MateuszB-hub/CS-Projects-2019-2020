/*
NAME: Mateusz Bieda
Description:This program automated through a command line interface, and works as a student administration
system that can handle student and faculty that are a part of classes, and more.
In addition being able to remove and add them, keeping track of their personal data
using inheritance also understanding parameterization
Moreover, we include vectors to manage and store multiple objects that are students, or faculty,
or courses. Using pointers to fetch information

Input:The input is handled through a commandline interface where 
that hols multiple commands with informative input senetenes that specify what is needed
Also abbreviations are provided to show what input to enter

Output: The output... there is a lot that goes into it. 
It depends on command you selected such as show course or student,
and it will output the inforamtion that is requested


I do output whats happening when certain actions are made
Also if student tries tp register or drop, also tells if the faculty tries to

I gave all of this output to prove it that it works
I never recieved an answer that told me not to do it and I did it to be safe
In addition all the output is commeneted to show the tasks

We were told to omit some of the commands in a meeting on June 29th in a webex 
class

*/

#include <vector>
#include <iostream>
//including the vecotr library to use vectors
using namespace std;

class teacherAssistant;
class Course;
class Faculty;
class GradStudent;
// using forward declaration to be able to use classes that are
// declared above others

/** class_identifier: this class contains the name of a person
 *                    in addition to the time they waited, we gathered
 *                    the info through the functions and main* 
 * constructors: PersonClass()
 *               PersonClass(string)*
 *  public functions: setName, 
 *                    getName,
 *                    getTime*
 *  static members:unsure if there were any*
 *                 
 * (string m_personName, int m_waitingTime, string nameNow)*/
class Person{
private:
    string firstName;
    string lastName;
    //string //familyName;
    string dob;
public:
    Person(){
        string firstName = "";
        string lastName = "";
        //string familyName = "";
        string dob = "";
    }

    Person(string firstN,string lastN,string date){
        firstName = firstN;
        lastName = lastN;
        //familyName = lastN;
        dob = date;
        setName(firstN, lastN);
    }

    void setName(string setter, string setter2){
      firstName =  setter + " " + setter2;
    }
    
    string getName(){
      return firstName;
    }
    
    string getLName(){
      return lastName;
    }

    void setDOB(string Dset){
      dob = Dset;
    }
    
    string getDOB(){
        return dob;
    }
    
   virtual int getID() = 0;
    
};

// student that has a parent function so that the names
// that are made in the object declration and passed to the 
// person constructor
// in addition student is used by grad student so that the grad student
// info can be passed from the gradstudent class type declarations
class Student: public Person{
protected:
    int sid;
    int totalCourses;
    double gpa;
    //Course * registeredCourses[6];
    vector<Course*> registeredCourses;
    string status;
    bool TA;
    bool isGrad;
    string thesisTitle;
    int adviser;
    // ALL OF THESE VARIABLES WERE USED IN TESTS AND ARE NOT
    // COMMENTED OUT SINCE I RECIEVE NO ERROR WARNINGS
    //string semester;
public:
    Student(){
      // since we need a default value for the status variable
      // it is set to UNKNOWN as default
      status = "UNKNOWN";
    }

    Student(int sid,string nameIN,string lnameIn,string date, bool TA, bool isGrad, string thesisTitle, int adviser): Person(nameIN, lnameIn, date){
      gpa = 0.0;
      totalCourses = 6;
      this->TA = TA;
      this->sid = sid;
      status = "active";// 
      this->isGrad = isGrad;
      this->adviser = adviser;
        
    }
    
    int * getCourses(){
       return &totalCourses; 
    }
    // RETURNS A POINTER TO THE STUDENT COURSES ARRRAY

    bool registerClasses(int cid, bool grad){
    //This was used in the previous assignment 
    // kept it incase i needed to use it in this assignment
     if( grad == true){
            for( int i= 0;i< 3;i++){
              //if(registeredCourses[i] == -1){
               // registeredCourses[i] = cid;
               return true;
              
            }
          }
          if(grad == false){
           for( int i= 0;i< 6;i++){
            //if(registeredCourses[i] == -1){
             // registeredCourses[i] = cid;
              return true;
           // }
           
          }
          }
          cout << "This Student has the max amount";
            cout << " of classes they are allowed"<< endl;
            cout << "Drop a class to register for another";
            cout << endl;
        
            return false;
    }

  int CoursePickUp(){
    return totalCourses;
  }
  // this was to get courses and return 

  bool Is_Grad(){
    return isGrad;
  }
  // this bool is used to check if a student is a graduate when
  // they are passed through the grad commands
  bool TA_Validation() {
        return TA;
    // this validates if a person is a TA in case a commadn is 
    //ran to check if a certain student beloings somewhere
    }
  bool registerStudent(Course *course){
      //KEEPS POINTERS TO THE COURSES THAT THE STUDENTS HAS REGISTERED FOR
    // MANAGED DYNAMICALLY
    if(!Is_Grad()){
      if(registeredCourses.size() < totalCourses){
            registeredCourses.push_back(course);
            return true;
      }   
    else {
      cout << "Class could not be registered for, student may have too many classes" << endl;
      return false;
    }
  }
  else{
    if(registeredCourses.size() < totalCourses){
      registeredCourses.push_back(course);
      return true;
      }
    else{
      cout << "Class could not be registered for";
      cout << endl;
      cout << "Grad Student not able to register for course" << endl;
      return false;
      }
    }
  }

  void Show_Courses(){
    // this is used to output the courses
    // finding the courses and outputting them
    // there is an issue with the address being output
    for(int i=0;i<registeredCourses.size();i++){
      cout <<registeredCourses.at(i) << endl;
    }
  }
  // set thesis is here just in case
  void setThesis(string ttitle){
      if(thesisTitle == "UNKNOWN"){
         thesisTitle = ttitle;
      }
      else
      {
        cout <<"A thesis title has already been set" << endl;

      }
    }

    string getThesis(){
     return thesisTitle;
    }
    
    void setAdviser(int fid){
      if(adviser == -1){
        adviser = fid;
      }
      else
      {
        cout << "Adviser is already assigned to the student" << endl;
      }
    }
  //string getSemester(){
    //return semester;
  //}
      /*
After clearing the course that was stored in a specific element of the dynamic array, make sure to have it empties and filled with
-1 so that something else can take its place later
      */
  bool drop(Course *course){
      /*
      for(int i= 0;i< registeredCourses.size();i++){
        if(registeredCourses.at(i) == course)
        {
          delete &registeredCourses[i];
          */
         // this goes thru the courses and checks if the input course is present in the vector
         // this functino is meant to drop the student from the class

          for(int i=0;i<totalCourses;i++){
              if(registeredCourses.at(i) == course){
                registeredCourses.erase(registeredCourses.begin() + i);
                 return true;
              }
              else {
          cout << "The Student " << sid << " failed to be dropped from " << course << endl;
          return false;
        }
      }
          //registeredCourses[i] = nullptr; 
      return false;
    } 

    void changeStatus(string s){
        // this is to change the status of the student
        // if they are active and a regualr
        // or if they are graudated
      for(size_t i = 0; i < s.length(); i++)
	    {
		    s[i] = tolower(s[i]); //reassigns character in str at position i to a lowercase equivalent
	    }
      if(s == "active"){
          status = s;
      }
      else if(s == "graduated"){
          status = s;
      }
      else if(s == "suspended"){
          status = s;
      }
      else{
          // this is incase the user entered something wrong
        cout << "Invalid Input, input not 'active','graduated','suspended'" << endl;
      }
      
    }

    // this is to present the status in int main
    string getStatus(){
      return status;
    }
    // get ID simply is used to identify students and present their iD
    // also fid is used to present the faciulty id
    int getID(){
      return sid;
    }
};

/*

NOTE: totalCourses MUST BE SET TO 3 AND NOT 6 FOR THE GRADUATES
Total Courses is in student 

This class does NOT need to override the registeredStudents(cid) function of the student class

*/
class GradStudent: public Student{

private:
    string thesisTitle;
    int adviser;
    // sets the thesis title to unknwon as asked for
      // in addition to the adviser to be empty until filled
public:
    GradStudent() {}

    GradStudent(int id,string nameIN, string lnameIn, string date, bool TA, bool grad, string thesisTitle, int adviser): Student(id, nameIN, lnameIn, date, TA, grad, thesisTitle, adviser){
       thesisTitle = "UNKNOWN";
        adviser = -1;
        totalCourses = 3;


   }

    void setThesis(string ttitle){
      if(thesisTitle == "UNKNOWN"){
         thesisTitle = ttitle;
      }
      else
      {
        cout <<"A thesis title has already been set" << endl;

      }
    }
    // gets a thesis of a student when the command is used
    string getThesis(){
     return thesisTitle;
    }
    // this can change a students advisor which is a fauclty member
    void setAdviser(int fid){
      if(adviser == -1){
        adviser = fid;
      }
      else
      {
        cout << "Adviser is already assigned to the student" << endl;
      }
    }
  /*  
  past code it can be Ignored
    string getAdviser(){
      if(adviser == 99111){
        string adv1 = "Elizabeth Jones";
        return adv1;
      }
      else if(adviser == 99222){
        string adv2 = "Sam Williams";
        return adv2;
      }
      else if(adviser == 99333){
        string adv3 = "Olive Yew";
        return adv3;
      }
      string null = "null";
      return null;
    }
  */
};


class Faculty: public Person{
private:
  int fid;
  // use the vector courses to store values and pull them out in function
  // also store values from functoins

  vector<Course*> courses;
public:

    Faculty(){}

    Faculty(int fid,string nameIN, string lnameIn, string date): Person(nameIN, lnameIn, date){
            string nameHold = nameIN + lnameIn;
            this->fid = fid;
            
    }

      vector<Course*> getCourses(){
      return courses;
      // get corueses to the user in main when called upon
    }

    bool assignCourse(Course *course){
    // assinging a course to the vecotr array
    // and ensuring that not too much is stored
      if(courses.size() < 3 ){
          courses.push_back(course);
          return true;
      }
      else
      {
        cout <<"Error, " << fid << " Teacher is teaching";
        cout << " their max course amount (3)";
        cout << endl;
        return false;
      }
          
    }

    bool removeCourse(Course *course){
        // taking away class from the vector
        // also ensures that the course is the right course usinga 
    // for loop
        for( int i= 0;i< courses.size();i++){
          if(courses.at(i) == course){
            delete &courses[i];
            return true;
          }
          //
          else if(courses.at(i) != course){
            cout << "The course you're looking is not here, fail" << endl;
            return false;
          }
        }
        return false;
    }
    int getID(){
      return fid;
    }
};

class Course{
private:
// for the course this is what manipulates 
// holds registedStudents in side so when certain commands call for 
// also uses faculty teacher since they belong in courses
  int cid;
  string cname;
  int courseCapacity;
  vector<Student*> registeredStudents;
  Faculty *teacher;
public:
    Course(int cin, string cname, int courseCapacity, Faculty *teacher){
      this->cid = cin;
      this->cname = cname;
      this->courseCapacity = courseCapacity;
      this->teacher = teacher;
    }
  Course(int cid, string cname){
    this->cid = cid;
    this->cname = cname;
  }
    string getCourseName(){
        return cname;
    }

    bool addStudent(Student *S){
        // this adds a sturdent to a class 
        // also stores the, in the vecotr for students
      if(registeredStudents.size() < 25){
         registeredStudents.push_back(S);
         return true;
      }
      else{
        cout << "Error: Could Not add student" << endl;
        return false;
      }
    }
    // If anything Ignore the function below
  void outputStudents(vector<Student>* S){
      //this function was a extra function that I used to present students and it didn't work
    for( int i = 0; i <registeredStudents.size();i++){
      //registeredStudents->getName();
      // ALL MY FAILED IDEAS
      // dummy variable = registeredStudents.at(i);

      //Student &filler = registeredStudents[i];
      //cout << &filler << endl;

      // Student = registeredStudents[]&dummy
      //Student filler;
      //filler = &registeredStudents[i];
      //&filler = registeredStudents[i];
      //cout << &dummy variable << endl; //im hoping this is the value at 0x556c0ad43780

      //cout << S->at(i);

      //cout << registeredStudents.at(i) << endl;
      // cout << registeredStudents[*i] << endl;
    }
  }
    bool removeStudent(Student *S){
        // this is meant to take students from a course and class
        // checking if the students matches the input in the vector
      for( int i = 0;i< registeredStudents.size();i++){
        if(registeredStudents[i] == S){
          delete registeredStudents[i];
          return true;
        }
        else{
          cout << "Error: fail to remove student"<< endl;
          return false;
        }
      }
      // probably use erase to clear out the specific student
      //registeredStudents.erase()
      return false;
    }
    bool assignTeacher(Faculty *fi){
        // assinging a teacher and storing them
        if(teacher == NULL){
            teacher = fi;
            return true;
        }
        else{
            return false;
        }
    }
    bool removeTeacher(){
        // this checks if a teacher slot is empty and also 
        // ensures there is no dangling ppinter with the null ptr
      if(teacher != NULL){
        teacher = nullptr;
        return true;
      }
    return false;
    }
  void changeCourseCapacity(int capacity){
      // for the command to change capacity 
      // for a class
    courseCapacity = capacity;
  }
  int getID(){ 
      // this is meant to return the class id
        return cid;
    }
};
class teacherAssistant: public Faculty, public Student{
private:
// this is specifically for TAs
// the semester is for TAs being assinged course help times
  string semester;
public:
  teacherAssistant(){

  }
  teacherAssistant(int id, string firstName, string lastName, string birthDate,string semester, bool TA, bool grad, string thesisTitle, int adviser):Student(id, firstName, lastName, birthDate, TA, grad, thesisTitle, adviser){
    this->semester = semester;
  }

  string getSemester(){
      // assings a TA stuednt a course time to help
    return semester;
  }
  
};

  int main(){
    //Using getID since a derived class can be used as a arguement/input parameter for a base class member function
    //Person P;
    //P.getID(S);

    // pointers best way to interface with all objects, with having the address
    // crud: create, read, update, delete
    vector<Faculty> facultyArray;
    vector<Student> studentsArray;
    vector<Course> coursesArray;
    //C.resize(i+1);
    // declaring my variables to use for inptus
  string cname = "";
  string Fname = "";
  string Lname = "";
  string yearStatus = "";
  string birthDate = "";
  string gradeInfo = "";
  string semester = "";
  int ID = 0;
  int Class_Capacity;
  int Class_ID = 0;
// test 
  Course *Course_Ptr;
  Student *Student_Ptr;
  Faculty *Faculty_Ptr;

  bool exit = false;
  string userInput;

/*

Get student name or ID
Match that with studentArray vector by checking by traversing vector and by checking if any items in the vector matches
  If vector.at(id/name) doesn't "bounce" i.e. find a match 
  for each item in vecotr, check ID by using student.getID();
  if item found
return match
retunr studentArray.at(index);
index from the for loop


*/
  while(exit != true){
  
    
    cout << "Command Line Interface " << endl;
    cout << "Admit a Student (AAS)" << endl;
    cout << "Hire a Faculty (HAF)" << endl;
    cout << "Remove a Faculty (RAF)" << endl;
    cout << "Graduate a Student (GAS)" << endl;
    cout << "Remove a Student (RAM)" << endl;
    cout << "Suspend a Student (SAS)" << endl;
    cout << "Add a Course (AAC)" << endl;
    cout << "Remove a Course (RAC)" << endl;
    cout << "Register (R)" << endl;
    cout << "Drop (D)" << endl;
    cout << "Set TA (SETA)" << endl;
    cout << "Remove TA (RTA)" << endl;
    cout << "Change Course Teacher (CCA)" << endl;
    cout << "Show Faculty Memebrs (SFM)" << endl;
    cout << "Show Students (SS)" << endl;
    cout << "Show TAs (SHTA)" << endl;
    cout << "Show Courses (SC)" << endl;
    cout << "Course Information (CI)" << endl;
    cout << "Student Information (SI)" << endl;
    cout << "Faculty Information (FI)" << endl;
    cout << "Change Course Capacity (CCC)" << endl;
    cout << "Change Adviser (CA)" << endl;
    cout << "Change Thesis (CT)" << endl;
    cout << "EXIT School Administration Program (EXT)" << endl;
    cout << endl;
    cout << "Enter An Abbreviated Command " ;

    cin >> userInput;

  
  if(userInput == "AAS"){
      // Admit a student
            cout << "Enter Student ID: "; cin >> ID;
            while(cin.fail()){
                cin.clear();
                cin.ignore(5000, '\n');
                cout << "Invalid Input, try again" << endl;
                cout << "Enter Student ID: "; 
                cin >> ID;
            }
            // takes in student infomation
            cout << "Enter The Students First Name: ";
            cin >> Fname;
            cout << "Enter The Students Last Name: ";
            cin >> Lname;
            cout << "Enter The Student's Date of Birth: "; 
            cin >> birthDate;
            cout << "Is Student a Graduate? Enter \"yes\" or \"no "; 
            cin >> gradeInfo;
            //student is a graduate
            for(size_t i = 0; i < gradeInfo.length(); i++)
              {
                gradeInfo[i] = tolower(gradeInfo[i]); //reassigns character in str at position i to a lowercase equivalent
              }
            if(gradeInfo == "yes") {
                // checks if they are a gradaute or not
                GradStudent New_Grad_Student(ID, Fname, Lname, birthDate, false, true, "UNKNOWN", -1);
                studentsArray.push_back(New_Grad_Student);
                // shoves the now new grad student back into student
            }
            //student is not a graduate
            else if(gradeInfo == "no") {
                // if not a new grad student ehen the 
                // student becomes a new freshMan
                Student freshMan(ID, Fname, Lname, birthDate, false, false, "UNKNOWN", -1);
                studentsArray.push_back(freshMan);
            }
        }
  else if(userInput == "HAF"){
      // this hired a new faculty person
            cout << "Enter Faculty ID: "; 
            cin >> ID;
            while(cin.fail()){
                cin.clear();
                cin.ignore(5000, '\n');
                cout << "Invalid Input, try again" << endl;
                cout << "Faculty ID: "; 
                cin >> ID;
            }
            // gets more info on them
            cout << "Faculty First Name: "; 
            cin >> Fname;
            cout << "Faculty Last Name: "; 
            cin >> Lname;
            cout << "Faculty's Date of Birth: "; 
            cin >> birthDate;
            Faculty faculty(ID, Fname, Lname, birthDate);
            facultyArray.push_back(faculty);
            cout << "Assign Faculty to Class?";
            cout << endl;
            cout <<"Enter Yes or No";
            cin >> gradeInfo;
            for(int i= 0;i< gradeInfo.length(); i++) {
                gradeInfo[i] = tolower(gradeInfo[i]);
            }
            if(gradeInfo == "yes") {
                gradeInfo = "CCT";
            }
        }
  else if(userInput == "RAF"){
            cout << "ID of Faculty You Want Removed: ";
            cin >> ID;
            while(cin.fail()){
                cin.clear();
                cin.ignore(5000, '\n');
                cout << "Invalid Input, try again" << endl;
                cout << "ID of Faculty You Want Removed: "; 
                cin >> ID;
            }
            for(int i= 0;i< facultyArray.size(); i++) {
                if(facultyArray[i].getID() == ID) {
                    facultyArray.erase (facultyArray.begin() + i);
                }
            }
        }
  else if(userInput == "GAS"){
      //to graduate a student taking in their id 
      // in addition to changing theri STATUS
            cout << "ID of Student You Want To Set as Graduated: ";
            cin >> ID;
            while(cin.fail()){
                cin.clear();
                cin.ignore(5000, '\n');
                cout << "Invalid Input, try again" << endl;
                cout << "ID of Student You Want To Set as Graduated: "; 
                cin >> ID;
            }
            for(int i= 0;i< studentsArray.size(); i++) {
                if(studentsArray[i].getID()==ID){
                    studentsArray[i].changeStatus("graduated");
                }
            }
        }
  else if(userInput == "RAS"){
      // this is to REMOVE NOT REGISTER a student
            cout << "Student ID, to be removed: ";
            cin >> ID;
            while(cin.fail()){
                cin.clear();
                cin.ignore(5000, '\n');
                cout << "Invalid Input, try again" << endl;
                cout << "Student ID, to be removed: ";
                cin >> ID;
                // takes their info and ERASES THEM, all gone
            }
            for(int i= 0;i< studentsArray.size(); i++) {
                if(studentsArray[i].getID()==ID){
                    studentsArray.erase (studentsArray.begin()+i);
                }
            }
        }
  else if(userInput == "SAS"){
      //This suspends a student 
            cout << "ID of Student, to be Suspended ";
            cin >> ID;
            while(cin.fail()){
                cin.clear();
                cin.ignore(5000, '\n');
                cout << "Invalid Input, try again" << endl;
                cout << "ID of Student, to be Suspended "; 
                cin >> ID;
                // simply enter their ID 

                // and the sysyme changes their status
            }
            for(int i= 0;i< studentsArray.size(); i++) {
                if(studentsArray[i].getID()==ID){
                    studentsArray[i].changeStatus("suspended");
                }
            }
        }
  else if(userInput == "AAC"){
      // creates a course that then is sotred intoa  course vector
            cout << "Enter the Course ID: ";
            cin >> ID;
            while(cin.fail()){
                cin.clear();
                cin.ignore(5000, '\n');
                cout << "Invalid Input, try again" << endl;
                cout << "Enter the Course ID: "; 
                cin >> ID;
            }
            // have to make the id and name
            cout << "Enter the Course Name: ";
            cin >> cname;
            Course courses(ID, cname);
            coursesArray.push_back(courses);
        }
  else if(userInput == "RAC"){
      // REMOVES NOT REGISTERS A course
            cout << "ID of  the Course You Want Removed: ";
            cin >> ID;
            while(cin.fail()){
                cin.clear();
                cin.ignore(5000, '\n');
                cout << "Invalid Input, try again" << endl;
                cout << "ID of  the Course You Want Removed: "; 
                cin >> ID;
            }
            // erases it from the vector , erase is really all we can do
            for(int i= 0;i< coursesArray.size(); i++) {
                if(coursesArray[i].getID() == ID) {
                    coursesArray.erase (coursesArray.begin() + i);
                }
            }
        }
  else if(userInput == "R"){
      // registeres a student for a class
    // takes the student ID and then the Class ID and stores the student into it
     // BY far so far the most confusing and complicated command
     // It sadly does not output the correct value but it does \
     // give a hex value  address
            cout << "ID of the Student to Register: ";
            cin >> ID;
            while(cin.fail()){
                cin.clear();
                cin.ignore(5000, '\n');
                cout << "Invalid Input, try again" << endl;
                cout << "ID of Student to Add to Class"; 
                cin >> ID;
            }
            // 
            cout << "ID of the Class to Enroll to: ";
            cin >> Class_ID;
            while(cin.fail()){
                cin.clear();
                cin.ignore(5000, '\n');
                cout << "Invalid Input, try again" << endl;
                cout << "ID of the Class to Enroll to: "; 
                cin >> Class_ID;
            }
            for(int i= 0;i< coursesArray.size(); i++) {
                if(coursesArray[i].getID() == Class_ID) {
                  Course_Ptr = &coursesArray[i];
                    for(int j=0; j<studentsArray.size(); j++) {
                        if(studentsArray[j].getID() == ID) {
                          Student_Ptr = &studentsArray[j];
                          cout << endl;
                          cout << Student_Ptr;
                          cout << endl;
                          //coursesArray.
                          /*
                            void foo(vector<Student>* a){
                              for(int i= 0;i< registeredStudents.size();i++){
                                cout << a->at(i) << endl;
                              }
                            }
                            
                            vector<Student> a;
                            a.push_back(6);
                            
                            foo(&a);

                          */
                          studentsArray[j].registerStudent(Course_Ptr);
                          coursesArray[i].addStudent(Student_Ptr);
                          cout << endl;
                        }
                    }
                }
            }
        }
  else if(userInput == "D") {
      // this drops a course for a student
        // drops a STUDENT from a Class, 
        // gets the student and class info
        // finds the proper values going throug a loop
        // once the value is found the functions go 

            cout << "ID of Student to Drop: ";
            cin >> ID;
            while(cin.fail()) {
                // these fails are to ensure the user enters the 
                // right thing 
                cin.clear();
                cin.ignore(5000, '\n');
                cout <<endl;
                cout << "Input failed, try again" << endl;
                cout << "ID of the Student you want Dropped: "; 
                cin >> ID;
            }
            cout << "ID of Class for Student to Drop: ";
            cin >> Class_ID;
            while(cin.fail()){
                cin.clear();
                cin.ignore(5000, '\n');
                cout <<endl;
                cout << "Input failed, try again" << endl;
                
                cout << "ID of the Class for the Student you want Dropped: "; 
                cin >> Class_ID;
            }
            for(int i= 0;i< coursesArray.size(); i++) {
                 if(coursesArray[i].getID() == Class_ID) {
                    Course* ptr1=&coursesArray[i];
                     for(int j=0; j<studentsArray.size(); j++) {
                        if(studentsArray[j].getID() == ID) {
                           Student* ptr2=&studentsArray[j];
                            studentsArray[j].drop(ptr1);
                           coursesArray[i].removeStudent(ptr2);
                        }
                    }
                }
            }
        }
  else if(userInput == "SETA"){
      // sets a TA to a class
            cout << "ID of the Student to Make TA: " ;
            cin >> ID;
            while(cin.fail()){
                cin.clear();
                cin.ignore(5000, '\n');
                cout << "Invalid Input, try again" << endl;
                cout << "ID of the Student to Make TA: ";
                cin >> Class_ID;
            }
            cout << "Semester the TA is Working: " ;
            cin >> semester;
            // this chooses the semester the ta is working in and the 
            // ID of the TA IS FOUND AND the semester is set in for that
            // TA
            for (int i=0;i<studentsArray.size(); i++) {
                 if (studentsArray[i].getID()==ID){
                 Fname = studentsArray[i].getName();
                     Lname = studentsArray[i].getLName();
                      birthDate = studentsArray[i].getDOB();
                       studentsArray.erase (studentsArray.begin()+i);
                    teacherAssistant TA(ID, Fname, Lname, birthDate, semester, true, false, "UNKNOWN" ,-1);
                      studentsArray.push_back(TA);
                }
            }
        }
  else if(userInput == "RTA"){
      // THIS REMOVES A TA 
            cout << "ID of TA to make a Student: ";
            cin >> ID;
            while(cin.fail()){
                cin.clear();
                cin.ignore(5000, '\n');
                cout << "Invalid Input, try again" << endl;
                cout << "ID of TA to make a Student: "; 
                cin >> Class_ID;
            }
            // after removing the TA they are then set back to the student they were
            // graduate or not

            for(int i= 0;i< studentsArray.size(); i++) {
                if(studentsArray[i].getID()==ID){
                    Fname = studentsArray[i].getName();
                    Lname = studentsArray[i].getLName();
                    birthDate = studentsArray[i].getDOB();
                    studentsArray.erase (studentsArray.begin()+i);
                    cout << "Is Student a Graduate? Enter yes or no"; 
                    cin >> gradeInfo;
                    //student is a graduate
                    for(size_t i = 0; i < gradeInfo.length(); i++)
                      {
                        gradeInfo[i] = tolower(gradeInfo[i]); //reassigns character in str at position i to a lowercase equivalent
                      }
                    if(gradeInfo == "yes") {
                        GradStudent New_Grad_Student(ID,Fname, Fname, birthDate, false, true, "UNKNOWN", -1);
                        studentsArray.push_back(New_Grad_Student);
                    }
                    //student is not a graduate
                    else if(gradeInfo == "no") {
                        Student freshMan(ID, Fname, Lname, birthDate, false, false, "UNKNOWN" ,-1);
                        studentsArray.push_back(freshMan);
                    }
                }
            }
        }
  else if(userInput == "CCT"){
      // This cahnges the couse teacher, it should be a class faulcty type
            cout << "Course Faculty is assigned to: ";
            cin >> Class_ID;
            while(cin.fail()){
            
                cin.clear();
                cin.ignore(5000, '\n');
                cout << "Invalid Input, try again" << endl;
                cout << "Course Faculty is assigned to: "; 
                cin >> Class_ID;
            }
            cout <<"Faculty Course To Assign: ";
            cin >> Class_ID;
            //
            while(cin.fail()){
                cin.clear();
                cin.ignore(5000, '\n');
                cout << "Invalid Input, try again" << endl;
                cout << "Faculty Course To Assign: "; 
                cin >> Class_ID;
            }
            for(int i= 0;i< coursesArray.size(); i++) {
                if(coursesArray[i].getID() == Class_ID) {
                    for(int j=0; j<studentsArray.size(); j++) {
                        if(facultyArray[j].getID() == ID) {
                            //nothing here since I didn't know how to go
                            // about this

                        }
                    }
                }
            }
        }
  else if(userInput == "SFM"){
      // This shows the (multiple) faculty members that exist
       
            cout << endl;
            for(int i= 0;i< facultyArray.size(); i++) {
                // simply uses a for loop to display and getname
                cout << facultyArray[i].getName() << endl;
            }
        }
  else if(userInput == "SS"){
      // Shows the students that exist and are registered
            cout << endl;
            for(int i= 0;i< studentsArray.size(); i++) {
                if(studentsArray[i].TA_Validation() == false) {
                  cout << studentsArray[i].getName() << endl;
                }
            }
        }
  else if(userInput == "SHTA") {
      // Shows all TAs even if undergrad or grad
            cout << endl;
            for(int i= 0;i< studentsArray.size(); i++) {
                if(studentsArray[i].TA_Validation()) {
                  cout << studentsArray[i].getName() << endl;
                  // we need to fetch the semester the TA is teaching in but it has been stated that
                  // we can only have these three arrays in int main and the inheritance is made so
                  // that teacherAssistant inherits student, but this doesn't work out
                  //cout << studentsArray[i].getSemester() << endl;
                }
            }
        }
  else if(userInput == "SC"){
      // Show s all created Courses
    // show courses
    for(int i= 0;i< coursesArray.size();i++){
      cout << coursesArray[i].getCourseName();

      cout << endl;
    }

  }
  
  //Course Information was told not to be included in class meeting
  else if(userInput == "CI"){
      // Supposed to show class informaiton 
    cout << "Enter the class ID ";
    cin >> ID;
    for(int i= 0;i< coursesArray.size();i++){
       coursesArray[i].outputStudents(&studentsArray); // 
    }

  }
  
  else if(userInput == "SI"){
      // Shows inforamiton of specific student
    cout << "ID of the Student you want info of: ";
    cout << endl;
    cin >>ID;
    for(int i=0;i<studentsArray.size();i++){
      if(studentsArray[i].getID() == ID){
        cout << "Graduate Student";
        cout << endl;
        cout << studentsArray[i].getName();
        cout << endl;
      }
      else
      {
        cout <<"UnderGraduate Student";
        cout << endl;
        cout << studentsArray[i].getName();
        cout << endl;
      }
      if(studentsArray[i].getID() == ID)
      {
        cout << "Student Classes Enrolled";
        cout << endl;
        cout << studentsArray[i].getName() << endl;
        studentsArray[i].Show_Courses();
        cout << endl;
      }
    }
  }
  else if(userInput == "FI"){
      // This command shows information of a faculty member
    cout << "Enter the ID of a Faculty member ";
    cin >> ID;
    for(int i= 0;i< facultyArray.size(); i++) {
                if(facultyArray[i].getID() == ID) {
                    for(int j = 0; j < facultyArray.size();j++){
                      facultyArray[i].getCourses();
                    }
                }
    }
  }
  else if(userInput == "CCC"){
    //Change the course capacity ensure that you get the correct course 
    // In additoin to entering your own custom capacity
    cout << "Enter the course ID and name that you want to the capacity of ";
    cin >> cname >> ID;
    cout << "Now enter the capacity you want it to be ";
    cin >> Class_Capacity;

    for(int i = 0;i < coursesArray.size();i++){
      if(coursesArray[i].getCourseName() == cname){
        coursesArray[i].changeCourseCapacity(Class_Capacity);
      }
    }
  }

  else if(userInput == "CA"){
      // This changes the adviser for the grad student or
      cout << "Enter the student that needs an advisor ";
      cin >> ID;
      for( int i = 0 ; i < studentsArray.size();i++){
      if(studentsArray[i].getID() == ID){
        //studentsArray[i].set
      }
    }
  }
  else if(userInput == "CT"){
      // change the adviser for the graduate student
    cout << "Enter the student id that needs a thesis change ";
    cin >> ID;
    for( int i = 0 ; i < studentsArray.size();i++){
      if(studentsArray[i].getID() == ID){
        //studentsArray[i].set
      }
    }

  }
  else if(userInput == "EXT")
  {
      // if the person wants out they type this command in
    exit = true;
  }
  

}
// FIN
  }