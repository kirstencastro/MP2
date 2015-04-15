#ifndef __2048__
#define __2048__

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <time.h>

class G2048 {
    private:
        // This data member represents the 4x4 board.
        int board[4][4];

        // This data member represents the current score for the game.
        int score;

        // This data member stores the name of the file to which the game is/will be saved.
        char* filename;


        // This function randomly adds a tile of value 2 or 4 to the board after each valid turn.
        void addTile() {
            srand(time(NULL));
            int tile, rand_tile = rand() % 2;
            int place, rand_place = rand() % 16;
            int k, l;

            if (rand_tile == 0) {tile = 2;}
            else {tile = 4;}

            k = rand_place/4;
            l = rand_place%4;

            while (true) {
                if (board[k][l] == 0) {
                    board[k][l] = tile;
                    break;
                }

                else {
                    k = (rand() % 16)/4;
                    l = (rand() % 16)%4;
                }
            }
        };


        /* This function prompts for an input character from the player, then returns the value.
        The input represents the direction to take, or the player's desire to quit. */
        char getInput() {
            char direction;

            std::cout << "Enter move: ";
            std::cin >> direction;
            return direction;
        };


        /* This function moves the tiles in the specified direction, computes, and updates the score.
        It returns true if the state of the board has changed (move is valid). */
        bool move(char direction) {
            // char direction = getInput();

            bool key = hasMove();
            bool valid;
            int i, j = 1, temp = 0, cur, k = 0;

            if (key) {
                if (direction == 'a' || direction == 'A' || direction == 's' || direction == 'S' ||
                direction == 'd' || direction == 'D' || direction == 'w' || direction == 'W') {

                    if (direction == 'a' || direction == 'A') {
                        for (i = 0; i < 4; i++) {
                            temp = 0;
                            j = 1;
                            while (j != 4 && temp != 3)  {
                                if (board[i][temp] == 0) {
                                    board[i][temp] += board[i][j];
                                    board[i][j] = 0;
                                }

                                else if (board[i][temp] != 0) {
                                    temp++;
                                    j = temp;
                                }
                                j++;
                            }
                            for (k = 0; k < 3; k++) {
                                if (board[i][k] == board[i][k+1]) {
                                    board[i][k] += board[i][k+1];
                                    score += board[i][k+1];
                                    if (k == 0) {
                                        board[i][1] = board[i][2];
                                        board[i][2] = board[i][3];
                                        board[i][3] = 0;
                                    }
                                    else if (k == 1) {
                                        board[i][2] = board[i][3];
                                        board[i][3] = 0;
                                    }
                                    else {
                                        board[i][3] = 0;
                                    }
                                }
                            }
                        }
                    }
                    else if (direction == 'd' || direction == 'D') {
                        for (i = 0; i < 4; i++) {
                            temp = 3;
                            j = 2;
                            while (j >=0 && temp > 0)  {
                                if (board[i][temp] == 0) {
                                    board[i][temp] = board[i][j];
                                    board[i][j] = 0;
                                }

                                else if (board[i][temp] != 0) {
                                    temp--;
                                    j = temp;
                                }
                                j--;
                            }
                            for (k = 3; k != 0; k--) {
                                if (board[i][k] == board[i][k-1]) {
                                    board[i][k] += board[i][k-1];
                                    score += board[i][k-1];
                                    if (k == 3) {
                                        board[i][k-1] = board[i][k-2];
                                        board[i][k-2] = board[i][k-3];
                                        board[i][k-3] = 0;
                                    }
                                    else if (k == 2) {
                                        board[i][k-1] = board[i][k-2];
                                        board[i][k-2] = 0;
                                    }
                                    else {
                                        board[i][k-1] = 0;
                                    }
                                }
                            }
                        }
                    }


                            /*for (j = 0; j < 3; j++) {
                                temp =
                                if (board[i][j] = 0) {
                                    board[i][j+1] = 0;
                                    board[i][j] = board[i][j+1];
                                }*/
                    /*            else if (board[i][j] == board[i][j+1]) {
                                    board[i][j] += board[i][j+1];
                                    board[i][j+1] = 0;
                                } */
//                            }


                    addTile();
                }
/*                else {
                    std::cout << "Invalid key. Try again." << std::endl;
                    valid = 0;
                }
*/            }

            /* INSERT CODE: If user enters this key, checks if move is possible then moves.
            If tiles are combined, compute for the score, and update the score. */

            // hasMove();

/*            if (direction == 'q' || direction == 'Q') {
                score += 10;
                key = 0;
                saveGame();
            }

            else {
                key = 1;
            }
*/
            return key;
        };


        // This function prints in the terminal the current state of the board.
        void drawBoard() {
            bool loop = 1;

            while (loop) {
//                system("cls"), system("clear");
                if (system("cls")) system("clear");
                int k, l;
                std::cout << "Let's play 2048!" << std::endl << std::endl;
                std::cout << "SCORE: " << score << std::endl << std::endl;


/*                std::cout << std::endl << std::endl;

                for (k = 0; k < 4; k++) {
                    for (l = 0; l < 4; l++) {
                        std::cout << board[k][l] << " ";
                    }
                    std::cout << std::endl;
                }
*/

                int i = 0, j = 0;
                for (k = 0; k < 9; k++) {
                    for (l = 0; l < 29; l++) {
                        if (k % 2 ==0) {
                            if (l % 7 == 0) {std::cout << '+';}
                            else {std::cout << '-';}
                        }

                        else {
                            if (l % 7 == 0) {
                                std::cout << '|';
                                if (l != 0) {
                                    j++;
                                }
                            }
                            else if (l % 7 == 4) {
                                if (board[i][j] !=0) {std::cout << board[i][j];}
                                else {std::cout << ' ';}
                            }
                            else {std::cout << ' ';}
                        }
                    }
                    if ((k % 2 == 0) && (k != 0)) {
                        i++;
                        j = 0;
                    }
                    std::cout << std::endl;
                }

                std::cout << std::endl << std::endl;
                std::cout << "(W) Up" << "     " << "(S) Down" << "     " << "(A) Left" << "     " << "(D) Right";
                std::cout << "     " << "(Q) Quit" << std::endl << std::endl;

                bool hasmove = hasMove();
                if (!hasmove) {
                    std::cout << std::endl << "GAME OVER. You scored " << score << ".";
                    std::cout << std::endl << "Thanks for playing!" << std::endl;
                    loop = 0;
                }
                else {
                    char direction = getInput();
                    if (direction == 'q'|| direction == 'Q') {saveGame(); loop = 0;}
                    else {move(direction);}
                }

//                else {move(direction);}

            }
        };


        // This function checks if the game is already won.
        bool hasReached2048();


        // This function checks if there is still a possible move.
        bool hasMove() {
            bool moves;
            int k, l, ctr = 0;
            int row, col;

            // INSERT CODE: Check if there are still moves.

            for (k = 0; k < 4; k++) {
                for (l = 0; l < 4; l++) {
                    if (board[k][l] != 0) {
                        moves = 1;
                        break;
                    }

                    else {
                        if (l < 4) {
                            if (board[k][l] == board[k][l+1]) {
                                moves = 1;
                                break;
                            }
                        }
                    }
/*
                        if (k != 3) {
                            if (board[k][l] == board[k+1][l]) {
                                moves = 1;
                                break;
                            }
                        }

                        else {ctr++;}

*/
                }
            }


//            if (ctr == 16) {
//                moves = 0;
//            }
            return moves;
        };


        // This function tries to load a 2048 game from the specified file.
        void loadGame() {
            int k, l;
            std::ifstream in(filename);

            in >> score;

            for (k = 0; k < 4; k++){
                for (l = 0; l < 4; l++) {
                    in >> board[k][l];
                }
            }

        };


        /* This function saves the instance of this class to the specified file.
        If the argument is NULL, prompt for a valid filename. */
        void saveGame() {
            int k, l;
            std::ofstream in(filename);

            in << score << std::endl;

            for (k = 0; k < 4; k++){
                for (l = 0; l < 4; l++) {
                    in << board[k][l] << " ";
                }
                in << std::endl;
            }
        };


        /*********************************************
        PLACE ANY ADDITIONAL MEMBER DECLARATIONS HERE
        **********************************************/

    public:
        /* This initializes a game of 2048 - the board, score, and filename.
        When the filename given is valid, check for the existence of the file, and load the values contained in it accordingly.
        Use the same file to save the game upon quitting. */
        G2048(char* filename) {
            this->filename = filename;

            int k, l;
            for (k = 0; k < 4; k++) {
                for (l = 0; l < 4; l++) {
                    board[k][l] = 0;
                }
            }

            if (filename == NULL) {
                score = 0;
                addTile();
                addTile();
            }

            else {
                std::ifstream file;
                file.open(filename);

                if (file.fail()) {
                    std::cout << "File does not exist." << std::endl;
                    exit(1);
                }

                else {
                    std::cout << "Successfully opened." << std::endl << std::endl;
                    loadGame();
                }

                file.close();
            }

            drawBoard();
            std::cout << std::endl << std::endl;
        };


        // This function starts/resumes a game of 2048.
        void startGame() {};
};

#endif
