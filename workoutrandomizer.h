#ifndef WORKOUT_H
#define WORKOUT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include<random>
#include<algorithm>

using namespace std; 

class workout{
public:
void readFromFile(string fileName);
void randomize(vector<string> ppl);
void print(vector<string>ppl);
void outFileCSV(vector<string>ppl);
string date();
private:
vector<string> ppl; 
vector<int> randomvec; 


};

#endif