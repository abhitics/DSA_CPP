#include <iostream>
#include <string>
using namespace std;

class Gun{
public:
    int ammo;
    int damage;
    int scope;
};
class Player {
private:
    int health;
    int score;
    string name;
    Gun gun;
    
public:
    void setHealth(int h) {
        this->health = h;
    }

    void setScore(int s) {
        this->score = s;
    }

    void setName(string n) {
        this->name = n;
    }
    void setGun(Gun g){
        this->gun=g;
    }
    Gun getGun(){
        return this->gun;
    }
    int getHealth() {
        return this->health;
    }

    int getScore() {
        return this->score;
    }

    string getName() {
        return this->name;
    }
    class Helmet{ //class inside a class is called nested class
    public:
        int durability;
        int protection;
        void setDurability(int d){
            this->durability=d;
        }
        void setProtection(int p){
            this->protection=p;
        }
        int getDurability(){
            return this->durability;
        }
        int getProtection(){
            return this->protection;
        }
    } helmet;
};

int maxScore(Player a, Player b) {
    return (a.getScore() > b.getScore())
        ? a.getScore()
        : b.getScore();
}

Player maxHealth(Player a, Player b) {
    return (a.getHealth()>b.getHealth())?a:b;
}

int main() {

    Gun awm;
    awm.ammo=10;
    awm.damage=100;
    awm.scope=5;

    Player p1; //static allocation
    p1.setHealth(23);
    p1.setScore(80);
    p1.setName("Abhitics");
    p1.setGun(awm);
    p1.helmet.setDurability(100);
    p1.helmet.setProtection(50);

    Gun akm;
    akm.ammo=30;
    akm.damage=90;
    akm.scope=3;

    Player p2; //static allocation
    p2.setHealth(70);
    p2.setScore(100);
    p2.setName("Shreyanza");
    p2.setGun(akm);
    p2.helmet.setDurability(180);
    p2.helmet.setProtection(80);

   
    cout<<"P1 stats: "<<endl;
    cout<<"Name: "<<p1.getName()<<endl;
    cout<<"Health: "<<p1.getHealth()<<endl;
    cout<<"Score: "<<p1.getScore()<<endl;
    cout<<"Ammo: "<<p1.getGun().ammo<<endl;
    cout<<"Damage: "<<p1.getGun().damage<<endl;
    cout<<"Scope: "<<p1.getGun().scope<<endl;
    cout<<"Helmet Durability: "<<p1.helmet.getDurability()<<endl;
    cout<<"Helmet Protection: "<<p1.helmet.getProtection()<<endl;

    cout<<"-----------------------------------------------------------------"<<endl;

    cout<<"P2 stats: "<<endl;
    cout<<"Name: "<<p2.getName()<<endl;
    cout<<"Health: "<<p2.getHealth()<<endl;
    cout<<"Score: "<<p2.getScore()<<endl;
    cout<<"Ammo: "<<p2.getGun().ammo<<endl;
    cout<<"Damage: "<<p2.getGun().damage<<endl;
    cout<<"Scope: "<<p2.getGun().scope<<endl;
    cout<<"Helmet Durability: "<<p2.helmet.getDurability()<<endl;
    cout<<"Helmet Protection: "<<p2.helmet.getProtection()<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;

    Player *hristi= new Player; //dynamic allocation
    // *hristi.setHealth(30); //WRONG
    hristi->setScore(85);
    Player shristi= *hristi; //copying the object

    shristi.setHealth(50);
    shristi.setScore(90);   
    cout << "Max Score: " << maxScore(p1, p2) << endl;

    Player sanket = maxHealth(p1, p2);

    cout <<"Player with max health:" << endl;
    cout <<"Sanket " << sanket.getName() << endl;
    cout <<"Sanket's Health"<< sanket.getHealth() << endl;
    cout<<hristi->getScore()<<endl;
    cout<<shristi.getScore()<<endl;
    cout<<hristi->getHealth()<<endl;
    cout<<shristi.getHealth()<<endl;

    return 0;
}