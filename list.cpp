//Author: Raed K
//Date: November 7th 2021 
//This program compiles a list of students based on user input using vector pointers, which points to a struct 

#include <iostream> 
#include <vector> 
#include <cstring> 
#include <iomanip>

using namespace std; 

  //student struct
  struct student{
        char fname[20]; 
        char lname[20]; 
        float gpa; 
        int ID; 
 };

//function prototypes 
void add(vector<student*> *list); 
void print(vector<student*> *list);
void del(vector<student*> *list); 

int main() {
    bool run = true;
     //vector
    vector <student*>* list = new vector<student*>();

    char cmd[10];

    while (run == true) {
        cout << "\nWould you like to ADD, DELETE, PRINT, or QUIT" << endl;
        cin >> cmd;

        //add student
        if (strcmp(cmd,"ADD") == 0) {
            add(list); 
        }
        //print everyone
        else if (strcmp(cmd,"PRINT") == 0) {
            if (list->empty()) {
              cout << "There are no students entered" << endl; 
            } 
            else {
              print(list); 
              cout << "Students Listed!" << endl;
          }
        }
        else if (strcmp(cmd,"DELETE") == 0) { 
            del(list); 
            cout << "Student Deleted!" << endl;
        }
        else 
            cout << "Invalid Input, dummy"; 
    }
}

void add(vector<student*> *list) {
    //create a new student everytime a user wants to add 
    student* s = new student(); 

    //inputting data into new student object 
    cout << "Enter First Name: " << endl; 
    cin >> s->fname; 
    cout << "Enter Last Name: " << endl; 
    cin >> s->lname;
    cout << "Enter GPA: " << endl; 
    cin >> s->gpa; 
    cout << "Enter ID: " << endl; 
    cin >> s->ID; 
  
    list->push_back(s); //insert student from back 
}


void print(vector<student*> *list) {
    //iterate through entire vector; print out each student, specifically the data within each student
    for (vector<student*>::iterator iter = list->begin(); iter != list->end(); ++iter) {
        cout << "NAME: " << (*iter)->fname << " " << (*iter)->lname << " "; cout << "ID: " << (*iter)->ID << " ";
        //round gpa 
        cout << "GPA: " << fixed << setprecision(2) << (*iter)->gpa << endl;
    }
}
void del(vector<student*> *list) {
    int check; 
    int count = 0; 
    cout << "Enter the ID of the student you wish to delete: " << endl; 
    cin >> check;
    //iterate through vector and if a student as the same ID 
    for (vector<student*>::iterator iter = list->begin(); iter != list->end(); ++iter) {
        if ((*iter)->ID == check) { //if same ID, erase element
            list->erase(list->begin() + count); //erase using distance from beginning of array 
            break; //break out, or else segmentation fault
        }
        else
          count++;  //iteraate count to next position.
    }
} 
