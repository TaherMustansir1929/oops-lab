#include <iostream>
#include <string>
using namespace std;

class FootballPlayer {
private:
    string playerName;
    string position;
    int goalCount;

public:
    FootballPlayer() {
        playerName = "Unknown Player";
        position = "Benchwarmer";
        goalCount = 0;
    }
    
    FootballPlayer(string name, string pos, int goals) {
        playerName = name;
        position = pos;
        goalCount = goals;
    }
    
    FootballPlayer(const FootballPlayer &p) {
        playerName = p.playerName;
        position = p.position;
        goalCount = p.goalCount;
    }
    
    FootballPlayer(string name, string pos = "Midfielder", int goals = 10) {
        playerName = name;
        position = pos;
        goalCount = goals;
    }
    
    void addGoals(int g) {
        goalCount = goalCount + g;
    }
    
    void display() {
        cout << "Player Name: " << playerName << endl;
        cout << "Position: " << position << endl;
        cout << "Goal Count: " << goalCount << endl;
        cout << "Ready for Ballon d'Or!" << endl;
        cout << endl;
    }
};

int main() {
    FootballPlayer f1;
    cout << "Player 1 (Default Constructor):" << endl;
    f1.display();
    
    FootballPlayer f2("Messi", "Forward", 50);
    cout << "Player 2 (Parameterized Constructor):" << endl;
    f2.display();
    
    FootballPlayer f3(f2);
    cout << "Player 3 (Copy Constructor - clone of Messi):" << endl;
    f3.display();
    
    FootballPlayer f4("Ronaldo");
    cout << "Player 4 (Default Arguments - only name):" << endl;
    f4.display();
    
    FootballPlayer f5("Neymar", "Winger");
    cout << "Player 5 (Default Arguments - name and position):" << endl;
    f5.display();
    
    cout << "Boosting goal counts:" << endl;
    f2.addGoals(20);
    f4.addGoals(15);
    
    cout << "\nFinal Stats:" << endl;
    f2.display();
    f4.display();
    
    return 0;
}
