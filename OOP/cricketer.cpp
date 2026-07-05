#include <iostream>
#include <string>
using namespace std;

class Cricketer{
    public:
    string name;
    int age;
    int testMatches;
    float battingAverage;
    int runs;
};

int main() {
    Cricketer Virat;
    Virat.name="Virat Kohli";
    Virat.age=35;
    Virat.testMatches=123;
    Virat.battingAverage=50.5;
    Virat.runs=9230;

    Cricketer Rohit;
    Rohit.name="Rohit Sharma";
    Rohit.age=34;
    Rohit.testMatches=134;
    Rohit.battingAverage=45.5;
    Rohit.runs=8900;

    Cricketer cricketers[2]={Virat,Rohit};
    for(int i=0;i<2;i++){
        cout<<"Name: "<<cricketers[i].name<<endl;
        cout<<"Age: "<<cricketers[i].age<<endl;
        cout<<"Test Matches: "<<cricketers[i].testMatches<<endl;
        cout<<"Batting Average: "<<cricketers[i].battingAverage<<endl;
        cout<<"Runs: "<<cricketers[i].runs<<endl;
        cout<<"-----------------------------"<<endl;
    }
    return 0;
}