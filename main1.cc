

/*This is a program for randomizing a workout schedule for the day. 
It will have a few constant workouts, as well a few fixed like Squats for leg days or pull ups any day*/


#include <iostream>
#include <string>
#include "workoutrandomizer.h"
using namespace std; 

string lowerCase(string input);

int main(){

srand ( time(NULL) );

string day; 
string fileName;
workout w;
bool x = false; 
cout << "What workout are you doing today? (Push/Pull/Legs)\n";

cin >> day; 
while(x == false){
    if(lowerCase(day) == "push"){
        fileName = "pushDay.txt";
        w.readFromFile(fileName);
        x = true;
        //get push workouts
    }
    else if(lowerCase(day) == "pull"){
        fileName = "pullDay.txt";
        w.readFromFile(fileName);
        x = true;

    }
    else if(lowerCase(day) == "legs"){
        fileName = "legDay.txt";
        w.readFromFile(fileName);
        x = true;
    }
    else{
        cout<<"Improper input -- Enter push, pull, or legs\n";
        cin >> day; 
    }
}
return 0; 
}


string lowerCase(string input){
    for(int i = 0; i < input.length(); i++){
        if(int(input[i]) < 91){
            //cout << int(input[i]);
            input[i] = input[i] + 32; 
        }
    }

    
    return input;
}