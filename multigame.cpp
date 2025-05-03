#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

int main() {
    srand(time(0));  // Seed random number generator

    bool validInput = false;
    int gameChoice;

    cout << "Hello, user. It is me again, the magic ball! I have two new games for you to play." << endl;

    while (!validInput) {
        cout << "Please press 1 or 2:\n";
        cin >> gameChoice;

        if (cin.fail()) {
            cin.clear();             // clear error flag
            cin.ignore(1000, '\n');  // discard invalid input
            cout << "That is not a valid input\n";
            continue;
        }

        if (gameChoice == 1) {
            validInput = true;
            cout << "Time to play rock, paper, scissors!!!\n";
            cout << "The rules are simple, type 1(rock), 2(paper), or 3(scissors) and see if you win!\nGood luck!\n";

            string userPlay;
            cout << "Play \n1. Rock \n2. Paper \n3. Scissors\n";
            cin >> userPlay;

            int aiChoice = rand() % 3 + 1;

            // Rock
            if (userPlay == "1" || userPlay == "rock") {
                if (aiChoice == 1) {
                    cout << "You both play rock and tie!!\n";
                } else if (aiChoice == 2) {
                    cout << "Your rock is suffocated in the paper and you lose!!\n";
                } else {
                    cout << "Your rock destroys the scissors, you win!!!\n";
                }
            }

            // Paper
            else if (userPlay == "2" || userPlay == "paper") {
                if (aiChoice == 1) {
                    cout << "Paper beats rock, you win!\n";
                } else if (aiChoice == 2) {
                    cout << "You both play paper and tie!!\n";
                } else {
                    cout << "You're torn to shreds by scissors, you lose!\n";
                }
            }

            // Scissors
            else if (userPlay == "3" || userPlay == "scissors") {
                if (aiChoice == 1) {
                    cout << "You're destroyed by the rock, you lose\n";
                } else if (aiChoice == 2) {
                    cout << "You dispose of paper with ease, you win\n";
                } else {
                    cout << "You both play scissors and tie\n";
                }
            } else {
                cout << "Invalid choice.\n";
            }
        }

        else if (gameChoice == 2) {
            validInput = true;
            cout << "Looks like we're flipping a coin!!!\n";
            cout << "The game is simple: choose heads or tails and how many times to flip.\n";
            cout << "If you get more of your side than the other, you win!\n";

            string choice;
            bool goodInput = false;

            while (!goodInput) {
                cout << "Heads or tails?\n";
                cin >> choice;

                int heads = 0;
                int tails = 0;
                int flips;

                if (choice == "heads" || choice == "Heads") {
                    goodInput = true;
                    cout << "How many flips do you want?\n";
                    cin >> flips;

                    for (int i = 0; i < flips; ++i) {
                        int coin = rand() % 2 + 1;
                        if (coin == 1) {
                            cout << "Heads\n";
                            heads++;
                        } else {
                            cout << "Tails\n";
                            tails++;
                        }
                    }

                    if (heads > tails) {
                        cout << "You guessed heads, and WON!!!\n";
                    } else if (heads == tails) {
                        cout << "It was a tie, flipping 1 more coin to break the tie...\n";
                        int last = rand() % 2 + 1;
                        if (last == 1)
                            cout << "YOU WON THE TIEBREAKER\n";
                        else
                            cout << "Unlucky, you lose\n";
                    } else {
                        cout << "You lost this time!\n";
                    }
                }

                else if (choice == "tails" || choice == "Tails") {
                    goodInput = true;
                    cout << "How many flips do you want?\n";
                    cin >> flips;

                    for (int i = 0; i < flips; ++i) {
                        int coin = rand() % 2 + 1;
                        if (coin == 1) {
                            cout << "Heads\n";
                            heads++;
                        } else {
                            cout << "Tails\n";
                            tails++;
                        }
                    }

                    if (tails > heads) {
                        cout << "You guessed tails, and WON!!!\n";
                    } else if (heads == tails) {
                        cout << "It was a tie, flipping 1 more coin to break the tie...\n";
                        int last = rand() % 2 + 1;
                        if (last == 2)
                            cout << "YOU WON THE TIEBREAKER\n";
                        else
                            cout << "Unlucky, you lose\n";
                    } else {
                        cout << "You lost this time!\n";
                    }
                }

                else {
                    cout << "Invalid input, please type 'heads' or 'tails'.\n";
                }
            }
        }

        else {
            cout << "That is not a 1 or 2, please try again\n";
        }
    }
}