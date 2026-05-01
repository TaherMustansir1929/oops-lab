#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;

int main() {
    ofstream f("system_log.txt", ios::app);
    time_t t = time(0);
    string ts = ctime(&t);
    ts.pop_back();
    f << "System started at: " << ts << "\n";
    f.close();
    cout << "Logged to system_log.txt" << endl;
    return 0;
}
