#include <iostream>
#include <string>
using namespace std;

class Player {
private:
    int health;
    int score;
    string name;

public:
    void setHealth(int h) {
        health = h;
    }
    void setScore(int s) {
        score = s;
    }
    void setName(string n) {
        name = n;
    }
    int getHealth() {
        return health;
    }
    int getScore() {
        return score;
    }
    string getName() {
        return name;
    }
};

int main() {
    Player p1;

    p1.setHealth(23);
    p1.setScore(80);
    p1.setName("Abhitics");

    cout << "Health: " << p1.getHealth() << endl;
    cout << "Score: " << p1.getScore() << endl;
    cout << "Name: " << p1.getName() << endl;

    return 0;
}