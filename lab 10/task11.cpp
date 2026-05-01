#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

int main() {
    ifstream f("article.txt");
    string line, word;
    int chars = 0, words = 0, lines = 0, puncts = 0;
    string puncsyms = ".,!?;:'\"()-";

    while (getline(f, line)) {
        lines++;
        chars += line.length();
        for (char c : line)
            if (puncsyms.find(c) != string::npos)
                puncts++;
        istringstream ss(line);
        while (ss >> word) words++;
    }
    f.close();

    ofstream r("report.txt");
    r << "Total Characters : " << chars << "\n";
    r << "Total Words      : " << words << "\n";
    r << "Total Lines      : " << lines << "\n";
    r << "Punctuation Marks: " << puncts << "\n";
    r.close();

    cout << "Report saved to report.txt" << endl;
    return 0;
}
