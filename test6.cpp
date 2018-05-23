#include <iostream>
#include "Board.h"


int main() {
    Board board1{4};  // Initializes a 4x4 board
    cout << board1 << endl;   /* Shows an empty board:
	....
	....
	....
	....
	*/
    cout << board1[{1,2}] << endl; // .
    board1[{1,1}]='X';
    board1[{1,2}]='O';
    char c = board1[{1,2}]; cout << c << endl; // O
    cout << board1 << endl;  /* Shows the following board:
	....
	.XO.
	....
	....
	*/

    try {
        board1[{3,4}]='O';   // This should raise an exception
    } catch (const IllegalCoordinateException& ex) {
        cout << "Illegal coordinate: " << ex.theCoordinate() << endl;  // prints "Illegal coordinate: 3,4"
    }

    board1 = '.';     // Fill the entire board with "."
    cout << board1 << endl;  /* Shows an empty board, as above */
    try {
        board1 = 'a';        // This should raise an exception
    }    catch (const IllegalCharException& ex) {
        cout << "Illegal char: " << ex.theChar() << endl;  // "Illegal char: a"
    }

    try {
        board1[{0,1}] = 'x';  // This should raise an exception
    } catch (const IllegalCharException& ex) {
        cout << "Illegal char: " << ex.theChar() << endl;  // "Illegal char: x"
    }

    Board board2 = board1;
    board2[{0,0}] = 'X';
    cout << board1 << endl;  /* Shows an empty board, as above */
    cout << board2 << endl;  /* Shows a board with an X at top-left */

    board1 = board2;
    board1[{3,3}] = 'O';
    cout << board2 << endl;  /* Shows a board with an X at top-left */
    cout << board1 << endl;  /* Shows a board with an X at top-left and O at bottom-right */
    //cout << board1[{0,0}]<<endl; work! return X
    //cout << board1[{4,3}]; //sigbrt ?
    //new prb:
    Board board4{3};
    cout << board4<<endl;
    board4=board1;
    cout << board4<<endl;
    board4[{2,2}]='O';
    cout << board4<<endl;
    cout << board1 << endl;  /* Shows a board with an X at top-left */
    cout << board4 << endl;
    cout << "Good bye!" << endl;

    return 0;
}