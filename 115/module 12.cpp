#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct Show {
    int rank;
    string title;
    int year;
    double rating;
    string genre;
};

int main() {

    ifstream file("topshow.csv");   // automatically use your CSV file
    if (!file.is_open()) {
        cout << "couldnt open the csv file :(\n";
        return 0;
    }

    vector<Show> shows;
    string line;

    getline(file, line); // skip header

    int limit = 0;

    while (getline(file, line)) {

        string rnk, ttl, yr, rt, gn;
        stringstream ss(line);

        getline(ss, rnk, ',');
        getline(ss, ttl, ',');
        getline(ss, yr, ',');
        getline(ss, rt, ',');
        getline(ss, gn, ',');

        Show s;
        s.rank = stoi(rnk);
        s.title = ttl;
        s.year = stoi(yr);
        s.rating = stod(rt);
        s.genre = gn;

        shows.push_back(s);

        limit++;
        if (limit == 10) {  // just load first 10
            break;
        }
    }

    cout << "\nHere are the top " << shows.size() << " shows:\n\n";

    for (int i = 0; i < shows.size(); i++) {
        cout << "Rank: " << shows[i].rank << "\n";
        cout << "Title: " << shows[i].title << "\n";
        cout << "Year: " << shows[i].year << "\n";
        cout << "Rating: " << shows[i].rating << "\n";
        cout << "Genre: " << shows[i].genre << "\n";
        cout << "-------------------------\n";
    }

    return 0;
}
