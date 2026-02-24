#include<iostream>
using namespace std;

class Player {
public:
    string name;
    static int total;

    Player(string n) {
        name = n;
        total++;
    }
    ~Player() {
        total--;
        cout << name << " left. Players online: " << total << endl;
    }
    static void showPlayers() {
        cout << "Total players: " << total << endl;
    }
};

int Player::total = 0;

int main() {
    Player::showPlayers();
    {
        Player p1("Ali"), p2("Sara"), p3("John");
        Player::showPlayers();
    }
    Player::showPlayers();
}
