#include<iostream>
using namespace std;

class Weapon {
public:
    string wName;
    int damage;
};

class Player {
public:
    string pName;
    int health;
    Weapon w;
    static int active;

    Player() { active++; }
    ~Player() { active--; }

    void showStatus() const {
        cout << "Player: " << pName << " | HP: " << health
             << " | Weapon: " << w.wName << " | Dmg: " << w.damage << endl;
    }
};

int Player::active = 0;

int main() {
    Player players[3];
    players[0].pName = "Ali";   players[0].health = 100; players[0].w.wName = "Sword"; players[0].w.damage = 50;
    players[1].pName = "Sara";  players[1].health = 80;  players[1].w.wName = "Bow";   players[1].w.damage = 30;
    players[2].pName = "John";  players[2].health = 90;  players[2].w.wName = "Axe";   players[2].w.damage = 60;

    cout << "Active Players: " << Player::active << endl;
    for (int i = 0; i < 3; i++) players[i].showStatus();
}
