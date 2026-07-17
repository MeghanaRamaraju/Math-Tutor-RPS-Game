// This program prompts the user with three options: math tutor program, rock, paper scissors game, and an exit option. The math tutor prompts the user with multiple options to practice their skills and displays their stats after each problem. The RPS game prompts the user to choose R, P, or S, while the computer randomly chooses one option as well; then the results are compared and the player's stats are displayed after each round. The exit option allows the user to exit the entire program.

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

//Struct - Stats (for the statTracker function)
struct Stats
{
    string name;
    //Math Tutor stats
    int numCorrect = 0, numWrong = 0;
    
    //RPS stats
    int computerPoints = 0, playerPoints = 0, numRoundsWon = 0, numRoundsLost = 0, numRoundsTied = 0;
};

// function prototypes
void addition(Stats &);
void subtraction(Stats &);
void multiplication(Stats &);
void division(Stats &);
void displayMenu();
bool isValid(int num, int min, int max);
void statsTracker(Stats &);
void RPSgame(Stats &);
void showStats();
void showStats(Stats &);

int main()
{
    //Struct variable declaration
    Stats student;
    
    // variables
    int choice, choice1, min = 1, max = 5;
    string choice2, choice3;
    double seed = time(0);
    srand(seed);
    
    // constants
    const string ERROR = "Invalid choice. Please choose a given option.";
    const string QUIT_1 = "Thank you for using this program, ", QUIT_2 = "! Please use it again if you need more practice!\n\n";
    
    do
    {
        cout << endl << "                        MAIN MENU                       \n";
        cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n";
        // Outputs the three optionns for the switch statement
        cout << "Welcome! Please choose one of the following options: " << endl;
        cout << "1. Math Tutor" << endl;
        cout << "2. Rock Paper Scissors" << endl;
        cout << "3. EXIT" << endl << endl;
        cin >> choice;
        cout << endl;
        
        //validate user input
        while (!(isValid(choice, 1, 3)))
        {
            cin >> choice;
        }
        
        // Switch statement - allows the user to choose which program they want to work with
        switch (choice)
        {
                // OPTION 1: Math Tutor
            case 1:
                
                // Welcome message
                cout << "What is your name?\n";
                cin >> student.name;
                cout << "\nWelcome to Math Tutor, " << student.name << "!\nI will help you test your simple addition, subtraction, multiplication, or division skills.\n";
                do
                {
                    // Calls function displayMenu (displays the menu and taked the input)
                    displayMenu(); // MATH TUTOR
                    cin >> choice1;
                    
                    //validate user input
                    while (!(isValid(choice1, min, max)))
                    {
                        cin >> choice1;
                    }

                    switch (choice1)
                    {
                            // Addition choice
                        case 1:
                            addition(student);
                            break;
                            // Subtraction Choice
                        case 2:
                            subtraction(student);
                            break;
                            // Multiplication Choice
                        case 3:
                            multiplication(student);
                            break;
                            // Division Choice
                        case 4:
                            division(student);
                            break;
                            // QUIT Choice
                        case 5:
                            cout << "\nYou chose to quit the Math Tutor program.\n\n";
                            break;
                            // Invalid Choice
                        default: // use this to catch input errors
                            cout << ERROR << endl;
                            break;
                    }
                    
                    cout << "-------------------------------------------------\n";
                    
                    if (choice1 != 5)
                    {
                        //Prompts the user to input whether or not they want to continue the math tutor program
                        cout << "Would you like to continue with the Math Tutor? (y/n): ";
                        cin >> choice2;
                    }
                    
                } while (choice1 != 5 && (choice2 == "y" || choice2 == "Y"));
                
                //Resets the stats to 0
                student.numCorrect = 0;
                student.numWrong = 0;
                break;
                
                // OPTION 2: Rock Paper Scissors
            case 2:
                
                cout << "Welcome to the Rock Paper Scissors Program!" << endl;
                
                do
                {
                    //rock paper scissors game FUNCTION
                    RPSgame(student);
                    
                    //Prompts the user to input whether or not they want to continue the math tutor program
                    cout << "Would you like to continue playing Rock Paper Scissors? (y/n): ";
                    cin >> choice3;
                    
                    cout << "-------------------------------------------------\n";
                    
                } while (choice3 == "y" || choice3 == "Y");
                
                //Resets the stats to 0
                student.playerPoints = 0;
                student.computerPoints = 0;
                student.numRoundsWon = 0;
                student.numRoundsLost = 0;
                student.numRoundsTied = 0;
                break;
                
                // OPTION 3: EXIT
            case 3:
                
                cout << "You chose to EXIT.\nThank you for using the program!" << endl << endl;
                break;
                
                
                // OPTION Default: Error/Invalid option
            default:
                
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
        
        if (choice == 3)
        {
            break;
        }
        
    } while((choice2 == "n" || choice2 == "N") || (choice3 == "n" || choice3 == "N"));
    
    return 0;
}


// Function - addition()
void addition(Stats &s)
{
    // variables
    int num1, num2, min, max, result, answer;
    int attempts = 1;
    // Range of Addition Numbers, top number between 2 and 500
    min = 2;
    max = 500;
    num1 = (rand() % (max - min + 1)) + min;
    // Bottom number between 10 and 99
    min = 1;
    max = 99;
    num2 = (rand() % (max - min + 1)) + min;
    // makes sure that num2 is less than num1 and fits the other requirements
    while (num2 >= num1)
    {
        num2 = (rand() % (max - min + 1)) + min;
    }
    result = num1 + num2;
    // User inputs an answer
    cout << "You have chosen addition.\n";
    cout << "\nInput your answer. (You have 3 attempts!)\n\n";
    cout << setw(5) << num1 << endl;
    cout << "+ " << num2 << endl;
    cout << "-----" << endl;
    cin >> answer;
    if (answer == result)
    {
        cout << "\nExcellent! You are correct.\n\n";
        s.numCorrect++;
    }
    else
    {
        while (answer != result)
        {
            if (attempts >= 3)
            {
                cout << "Sorry, you ran out of attempts!\n";
                cout << "The correct answer is " << result << ".\n\n";
                s.numWrong++;
                break;
            }
            else
            {
                cout << "\nIncorrect. Please try again.\n\n";
                cin >> answer;
            }
            // keep track of number of attempts
            attempts++;
        }
        if (answer == result)
        {
            cout << "\nExcellent! You are correct.\n\n";
            s.numCorrect++;
        }
    }
    
    //displays the stats after every problem
    statsTracker(s);
}

// Function - subtraction()
void subtraction(Stats &s)
{
    // variables
    int num1, num2, min, max, result, answer;
    int attempts = 1;
    // Range of Subtraction Numbers, top number between 10 and 99
    min = 2;
    max = 500;
    num1 = (rand() % (max - min + 1)) + min;
    // Bottom number between 1 and 9
    min = 1;
    max = 500;
    num2 = (rand() % (max - min + 1)) + min;
    // makes sure that num2 is less than num1 and fits the other requirements
    while (num2 >= num1)
    {
        num2 = (rand() % (max - min + 1)) + min;
    }
    result = num1 - num2;
    // User inputs an answer
    cout << "You have chosen subtraction.\n";
    cout << "\nInput your answer. (You have 3 attempts!)\n\n";
    cout << fixed << showpoint << setw(6) << num1 << endl;
    cout << "- " << num2 << endl;
    cout << "------" << endl;
    cin >> answer;
    if (answer == result)
    {
        cout << "\nExcellent! You are correct.\n\n";
        s.numCorrect++;
    }
    else
    {
        while (answer != result)
        {
            if (attempts >= 3)
            {
                cout << "Sorry, you ran out of attempts!\n";
                cout << "The correct answer is " << result << ".\n\n";
                s.numWrong++;
                break;
            }
            else
            {
                cout << "\nIncorrect. Please try again.\n\n";
                cin >> answer;
            }
            // keep track of number of attempts
            attempts++;
        }
        if (answer == result)
        {
            cout << "\nExcellent! You are correct.\n\n";
            s.numCorrect++;
        }
    }
    
    //displays the stats after every problem
    statsTracker(s);
}

// Function - multiplication()
void multiplication(Stats &s)
{
    // variables
    int num1, num2, min, max, result, answer;
    int attempts = 1;
    // Range of Multiplication Numbers, top number between 1 and 12
    min = 1;
    max = 12;
    num1 = (rand() % (max - min + 1)) + min;
    // Bottom number between 10 and 12
    min = 1;
    max = 12;
    num2 = (rand() % (max - min + 1)) + min;
    result = num1 * num2;
    // User inputs an answer
    cout << "You have chosen multiplication.\n";
    cout << "\nInput your answer. (You have 3 attempts!)\n\n";
    cout << setw(4) << num1 << endl;
    cout << "x " << num2 << endl;
    cout << "-----" << endl;
    cin >> answer;
    if (answer == result)
    {
        cout << "\nExcellent! You are correct.\n\n";
        s.numCorrect++;
    }
    else
    {
        while (answer != result)
        {
            if (attempts >= 3)
            {
                cout << "Sorry, you ran out of attempts!\n";
                cout << "The correct answer is " << result << ".\n\n";
                s.numWrong++;
                break;
            }
            else
            {
                cout << "\nIncorrect. Please try again.\n\n";
                cin >> answer;
            }
            // keep track of number of attempts
            attempts++;
        }
        if (answer == result)
        {
            cout << "\nExcellent! You are correct.\n\n";
            s.numCorrect++;
        }
    }
    
    //displays the stats after every problem
    statsTracker(s);
}

// Function - division()
void division(Stats &s)
{
    // variables
    int num1, num2, min, max, result, answer;
    int attempts = 1;
    // Range of Division Numbers, top number between 10 and 999
    min = 10;
    max = 999;
    num1 = (rand() % (max - min + 1)) + min;
    // Bottom number between 1 and 9
    min = 1;
    max = 9;
    num2 = (rand() % (max - min + 1)) + min;
    // loops to make sure there is no remainder
    while (!(num1 % num2 == 0))
    {
        num1 = (rand() % (max - min + 1)) + min;
        num2 = (rand() % (max - min + 1)) + min;
    }
    // calculates the quotient
    result = num1 / num2;
    // User inputs an answer
    cout << "You have chosen division.\n";
    cout << "\nInput your answer. (You have three attempts!)\n\n";
    cout << setw(4) << num1 << endl;
    cout << "/ " << num2 << endl;
    cout << "-----" << endl;
    cin >> answer;
    if (answer == result)
    {
        cout << "\nExcellent! You are correct.\n\n";
        s.numCorrect++;
    }
    else
    {
        while (answer != result)
        {
            if (attempts >= 3)
            {
                cout << "Sorry, you ran out of attempts!\n";
                cout << "The correct answer is " << result << ".\n\n";
                s.numWrong++;
                break;
            }
            else
            {
                cout << "\nIncorrect. Please try again.\n\n";
                cin >> answer;
            }
            // keep track of number of attempts
            attempts++;
        }
        if (answer == result)
        {
            cout << "\nExcellent! You are correct.\n\n";
            s.numCorrect++;
        }
    }
    
    //displays the stats after every problem
    statsTracker(s);
}

// Function - displayMenu() - MATH TUTOR
void displayMenu()
{
    // Menu choice
    cout << endl << "Which of the following do you want to practice?\n";
    cout << "1: Addition\n";
    cout << "2: Subtraction\n";
    cout << "3: Multiplication\n";
    cout << "4: Division\n";
    cout << "5: QUIT\n\n";
}

// Function - isValid(num, min, max)
bool isValid(int num, int min, int max)
{
    if (num < min || num > max)
    {
        cout << "Invalid Input. Please try again.\n\n";
        return false;
    }
    else
    {
        return true;
    }
}

//Function - statsTracker() - Math Tutor
void statsTracker(Stats &s)
{
    cout << endl << "==============================\n";
    cout << "         CURRENT STATS        \n";
    cout << "Name               : " << s.name << endl;
    cout << "Problems Correct   : " << s.numCorrect << endl;
    cout << "Problems Incorrect : " << s.numWrong << endl;
    cout << "==============================\n\n";
}

//Function - RPSgame()
void RPSgame(Stats &player)
{
    // variables
    int compChoice, userChoice, min, max;
    string computerChoice, playerChoice;
    
    // Range of Division Numbers, top number between 10 and 999
    min = 1;
    max = 3;
    compChoice = (rand() % (max - min + 1)) + min;
    
    //cout << "Computer Generated Number: " << compChoice << endl;
    
    if (compChoice == 1)
        computerChoice = "ROCK";
    else if (compChoice == 2)
        computerChoice = "PAPER";
    else
        computerChoice = "SCISSORS";
    
    //Displays the options (1. rock, 2. paper, 3. scissors)
    cout << "Please choose one of the following:\n1. Rock\n2. Paper\n3. Scissors\n";
    cin >> userChoice;
    
    //validate user input
    while (!(isValid(userChoice, min, max)))
    {
        cin >> userChoice;
    }
    
    //switch statement
    switch(userChoice)
    {
            //ROCK option
        case 1:
            playerChoice = "ROCK";
            
        //checks who the winner is or if it's a tie
            
            //when it is NOT a tie
            if (computerChoice != playerChoice)
            {
                // Computer - paper, COMPUTER WINS
                if (computerChoice == "PAPER")
                {
                    cout << "You chose " << playerChoice << ".\n";
                    cout << "The computer chose " << computerChoice << ".\n\n";
                    cout << computerChoice << " covers " << playerChoice << ". You LOSE.\n\n";
                    player.computerPoints++;
                    player.numRoundsLost++;
                    
                    showStats(player);
                }
                else
                // Computer - scissors, PLAYER WINS
                if (computerChoice == "SCISSORS")
                {
                    cout << "You chose " << playerChoice << ".\n";
                    cout << "The computer chose " << computerChoice << ".\n\n";
                    cout << playerChoice << " smashes " << computerChoice << ". You WIN.\n\n";
                    player.playerPoints++;
                    player.numRoundsWon++;
                    
                    showStats(player);
                }
            }
            //when it IS a tie
            else
            {
                // Player & Computer - rock, TIE
                cout << "You both chose " << playerChoice << ". This round is a TIE!\n\n";
                player.playerPoints++;
                player.computerPoints++;
                player.numRoundsTied++;
                
                //displays stats
                showStats(player);
            }
            
            break;
            
            //PAPER option
        case 2:
            playerChoice = "PAPER";
            
            //checks who the winner is or if it's a tie
                
                //when it is NOT a tie
                if (computerChoice != playerChoice)
                {
                    // Computer - rock, PLAYER WINS
                    if (computerChoice == "ROCK")
                    {
                        cout << "You chose " << playerChoice << ".\n";
                        cout << "The computer chose " << computerChoice << ".\n\n";
                        cout << playerChoice << " covers " << computerChoice << ". You WIN.\n\n";
                        player.playerPoints++;
                        player.numRoundsWon++;
                        
                        showStats(player);
                    }
                    else
                    // Computer - scissors, COMPUTER WINS
                    if (computerChoice == "SCISSORS")
                    {
                        cout << "You chose " << playerChoice << ".\n";
                        cout << "The computer chose " << computerChoice << ".\n\n";
                        cout << computerChoice << " cuts " << playerChoice << ". You LOSE.\n\n";
                        player.computerPoints++;
                        player.numRoundsLost++;
                        
                        showStats(player);
                    }
                }
                //when it IS a tie
                else
                {
                    // Player & Computer - paper, TIE
                    cout << "You both chose " << playerChoice << ". This round is a TIE!\n\n";
                    player.playerPoints++;
                    player.computerPoints++;
                    player.numRoundsTied++;
                    
                    //displays stats
                    showStats(player);
                }
                
            break;
            
            //SCISSORS option
        case 3:
            playerChoice = "SCISSORS";
            //checks who the winner is or if it's a tie
                
                //when it is NOT a tie
                if (computerChoice != playerChoice)
                {
                    // Computer - paper, PLAYER WINS
                    if (computerChoice == "PAPER")
                    {
                        cout << "You chose " << playerChoice << ".\n";
                        cout << "The computer chose " << computerChoice << ".\n\n";
                        cout << playerChoice << " cuts " << computerChoice << ". You WIN.\n\n";
                        player.playerPoints++;
                        player.numRoundsWon++;
                        
                        showStats(player);
                    }
                    else
                    // Computer - rock, COMPUTER WINS
                    if (computerChoice == "ROCK")
                    {
                        cout << "You chose " << playerChoice << ".\n";
                        cout << "The computer chose " << computerChoice << ".\n\n";
                        cout << computerChoice << " smashes " << playerChoice << ". You LOSE.\n\n";
                        player.computerPoints++;
                        player.numRoundsLost++;
                        
                        showStats(player);
                    }
                }
                //when it IS a tie
                else
                {
                    // Player & Computer - scissors, TIE
                    cout << "You both chose " << playerChoice << ". This round is a TIE!\n\n";
                    player.playerPoints++;
                    player.computerPoints++;
                    player.numRoundsTied++;
                    
                    //displays stats
                    showStats(player);
                }
                
            break;
            
            //DEFAULT option
        default:
            cout << "Invalid Input. Please exit and try again." << endl;
    }
}


//Function - showStats() - RPS game
void showStats(Stats &player)
{
    cout << endl << "==============================\n";
    cout << "         CURRENT STATS        \n";
    cout << "YOUR Points       : " << player.playerPoints << endl;
    cout << "Rounds Won        : " << player.numRoundsWon << endl;
    cout << "Rounds Lost       : " << player.numRoundsLost << endl;
    cout << "Rounds Tied       : " << player.numRoundsTied << endl << endl;
    cout << "COMPUTER's Points : " << player.computerPoints << endl;
    cout << "==============================\n\n";
}
