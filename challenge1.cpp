#include <iostream>
#include <vector>

using namespace std;


/*creates asci picture that can be manipulated by row, column, or by individual characters */
class Picture {
    vector<vector<char> > rows;
  public:
    Picture(): rows(7, vector<char>(10,' ')){}
    void set_row (int,char);
    void set_column(int, char);
    void set_single(int,int, char);
    void printPicture();

};

/*sets an entire column to a single character */
void Picture::set_column(int column, char character) {
    for(size_t i = 0; i < rows.size(); i++) {
        rows[i].insert(rows[i].begin() + column, character);
    }
}

/*sets an entire row to a single character */
void Picture::set_row (int row, char character) {
    vector<char> toAdd = rows[row];
    for(size_t i = 0; i < toAdd.size(); i++) {
        toAdd[i] = character;
    }
    rows.insert(rows.begin() + row, toAdd);
}
/*inserts a single character into a specific coordinate of the picture */
void Picture::set_single(int x, int y, char character) {
    rows[x][y] = character;
}

//prints the picture
void Picture::printPicture() {
    for(vector<char> eachRow: rows) {
        for(char eachChar: eachRow) {
            cout << eachChar;
        }
        cout << endl;
    }
}



