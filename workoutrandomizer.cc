#include "workoutrandomizer.h"

/*
This function reads the file and places each line into the vector indexes.
 */
void workout::readFromFile(string fileName){

    string line; 
    ifstream file(fileName);

    if(file.is_open()){
        while(getline(file,line)){
            ppl.push_back(line);
        }
        file.close();
    }

    randomize(ppl);

}

//https://en.cppreference.com/w/cpp/algorithm/random_shuffle
/*
This funciton creates a random device object and then generates a random order which is used to
shuffle the vector indexes
 */
  void workout::randomize(vector<string>ppl){


    random_device rr;
    mt19937 r2(rr());
    //Don't want to randomize first index
    shuffle(ppl.begin()+1,ppl.end(),r2);

    print(ppl);
    outFileCSV(ppl);
}


//Prints workout
void workout::print(vector<string>ppl){


   cout << ppl[0] <<endl;
   for(int i =1; i < ppl.size();i++){
       cout << ppl[i] << endl;
   }
    
}

/*
Outputs the workout to a csv file, which is then immediately placed in a folder in the cloud
 */
void workout::outFileCSV(vector<string>ppl){
    string s = date()+"-workout.csv";
    string path = "/Users/nate/Library/Mobile Documents/com~apple~CloudDocs/Documents/"+s;
    ofstream out;
    out.open(path);
    if(!out.is_open()){
        cout << "error opening file \n";
    }
    out << ppl[0] <<endl;
    //Arbitrary number chosen for limit
    for(int i =1; i < 6;i++){
       out << ppl[i] << endl;
    }

}

//http://www.cplusplus.com/reference/ctime/
//Returns the date month-day
string workout::date(){
    
    time_t t = time(0);   
    tm* now = localtime(&t);
    string today = to_string(now->tm_mon + 1) + "-" + to_string(now->tm_mday);
    return today; 

}