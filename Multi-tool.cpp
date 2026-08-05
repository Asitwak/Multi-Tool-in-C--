#pragma region Multi-Tool Code
#pragma region Libraries and Definitions
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <iomanip>
#include <vector>
#include <thread>
#include <algorithm>
#include <cctype>
#include <conio.h>
#include <random>
#include <atomic>

#ifdef _WIN32
#include <conio.h> 
#else
#include <sys/select.h>
#include <termios.h>
#include <unistd.h>
#endif

int universal_kbhit() {
#ifdef _WIN32
    return _kbhit();
#else
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv) > 0;
#endif
}

#define PI 3.1415926535897932384626433832795028841971693993

std::string Place_Holder_Value;
#pragma endregion

#pragma region Function Declarations
void Calculator();
void Distance();
void Angle();
void Dice();
void CurrentTime();
void SimpleTrigCalculator();
void Terminals();
void Rock_Paper_Scissors_Game();
void Tic_Tac_Toe_Game();
void Draw_Board_for_Tic_Tac_Toe(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);
void check_input(std::atomic<bool>& running);
void StartButton(std::string Questions[]);
void DrawButton();
void QButton(std::string Questions[]);
void UserInput_Button(std::string Questions[]);
void WaitButton();
void DrawL();
void ErrorMessage();
void ClearBuffer();
void Button();
#pragma endregion

#pragma region Functions
int main () {
    Terminals();

    std::cout << "Press Enter to exit...";
    std::cin.get();

    return 0;
}
void Calculator () {
    double num1;
    double num2;
    std::string operation;
    int num;

    std::cout << "\n**************-Calculator-**************\n";
    std::cout << "*                                       *\n";
    std::cout << "* Use +, -, *, /, ^, sqrt(), and cbrt() *\n";
    std::cout << "*                                       *\n";
    std::cout << "*****************************************\n";

    std::cout << "Enter number 1: ";
    std::cin >> num1;

    std::cout << "\n\nEnter in operator: ";
    std::getline(std::cin, operation);

    std::cout << "\n\nEnter number 2: ";
    std::cin >> num2;

    if (operation == "+") {
        std::cout << "Answer:\n";
        std::cout << num1 + num2;
    }
    else if (operation == "-") {
        std::cout << "Answer:\n";
        std::cout << num1 - num2;
    }
    else if (operation == "*") {
        std::cout << "Answer:\n";
        std::cout << num1*num2;
    }
    else if (operation == "/") {
        std::cout << "Answer:\n";
        std::cout << num1/num2;
    }
    else if (operation == "^") {
        std::cout << "Answer:\n";
        std::cout << std::pow(num1, num2);
    }
    else if (operation == "sqrt" or operation == "sqrt()" or operation == "square root" or operation == "Square root" or operation == "Square Root") {
        
        std::cout << "Which number? (1 for number 1 or 2 for number 2)\n";
        std::cin >> num;

        if (num == 0) {
            std::cout << "\nAnswer:";
            std::cout << "\n" << sqrt(num1);
        }
        else if (num == 1) {
            std::cout << "\nAnswer:";
            std::cout << "\n" << sqrt(num2);
        }
        else {
            std::cout << "Invalid input. Please try again";
        }
    }
    else if (operation == "Sqrt" or operation == "SQRT" or operation == "SQRT()" or operation == "Square Root" or operation == "square root") {
        
        std::cout << "Which number? (0 for number 1 or 1 for number 2)\n";
        std::cin >> num;

        if (num == 0) {
            std::cout << "\nAnswer:";
            std::cout << "\n" << sqrt(num1);
        }
        else if (num == 1) {
            std::cout << "\nAnswer:";
            std::cout << "\n" << sqrt(num2);
        }
        else {
            std::cout << "Invalid input. Please try again";
        }
    }
    else if (operation == "Sqrt()") {
        
        std::cout << "Which number? (0 for number 1 or 1 for number 2)\n";
        std::cin >> num;

        if (num == 0) {
            std::cout << "\nAnswer:";
            std::cout << "\n" << sqrt(num1);
        }
        else if (num == 1) {
            std::cout << "\nAnswer:";
            std::cout << "\n" << sqrt(num2);
        }
        else {
            std::cout << "Invalid input. Please try again";
        }
    }
    else if (operation == "cbrt" or operation == "cbrt()" or operation == "cube root" or operation == "Cube root" or operation == "Cube Root") {
        
        std::cout << "Which number? (0 for number 1 or 1 for number 2)\n";
        std::cin >> num;
        
        if (num == 0) {
            std::cout << "\nAnswer:";
            std::cout << "\n" << cbrt(num1);
        }
        else if (num == 1) {
            std::cout << "\nAnswer:";
            std::cout << "\n" << cbrt(num2);
        }
        else {
            std::cout << "Invalid input. Please try again";
        }
    }
    else if (operation == "Cbrt" or operation == "CBRT" or operation == "CBRT()") {
        
        std::cout << "Which number? (0 for number 1 or 1 for number 2)\n";
        std::cin >> num;
        
        num--;

        if (num == 0) {
            std::cout << "\nAnswer:";
            std::cout << "\n" << cbrt(num1);
        }
        else if (num == 1) {
            std::cout << "\nAnswer:";
            std::cout << "\n" << cbrt(num2);
        }
        else {
            std::cout << "Invalid input. Please try again";
        }
    }
    else if (operation == "Cbrt()" or operation == "Cube Root" or operation == "cube root") {
        
        std::cout << "Which number? (0 for number 1 or 1 for number 2)\n";
        std::cin >> num;
        
        if (num == 0) {
            std::cout << "\nAnswer:";
            std::cout << "\n" << cbrt(num1);
        }
        else if (num == 1) {
            std::cout << "\nAnswer:";
            std::cout << "\n" << cbrt(num2);
        }
        else {
            std::cout << "Invalid input. Please try again";
        }
    }
    else {
        std::cout << "Invalid operation. Please try again";
    }
}
void Distance () {

    std::vector<double> xnum; 
    std::vector<double> ynum; 

    double xAmt; 
    double yAmt; 
    int DistAmt; 

    std::cout << "\n************-Distance-************\n"; 
    std::cout << "*                                *\n"; 
    std::cout << "* Enter in x and y coordinates   *\n"; 
    std::cout << "*                                *\n"; 
    std::cout << "**********************************\n\n"; 

    std::cout << "How many distances do you need?\n"; 
    std::cin >> DistAmt; 

    bool hasError1;

    double TtD = 0.0;

    do {

        hasError1 = false; 
        xnum.clear();
        ynum.clear();
        TtD = 0.0;

        for (int i = 0; i <= DistAmt - 1; i++) { 
            std::cout << "Enter in x value number " << i + 1 << ": "; 
            std::cin >> xAmt; 
            xnum.push_back(xAmt); 
            std::cout << "\n\n"; 
        } 

        for (int i = 0; i <= DistAmt - 1; i++) { 
            std::cout << "Enter in y value number " << i + 1 << ": "; 
            std::cin >> yAmt; 
            ynum.push_back(yAmt); 
            std::cout << "\n\n"; 
        } 

        for (int j = 0; j < DistAmt - 1; j++) { 

            double xDiff = xnum.at(j) - xnum.at(j + 1);
            double yDiff = ynum.at(j) - ynum.at(j + 1);
            double sumofSquares = std::pow(xDiff, 2) + std::pow(yDiff, 2);

            if (sumofSquares < 0) { 
                std::cout << "Number is imaginary. Cannot print distance.\n"; 
                hasError1 = true;
                break;
            } else { 
                std::cout << "Distance " << j + 1 << ": " << sqrt(sumofSquares) << " units\n";
                TtD += std::sqrt(sumofSquares);
            } 
        } 

    std::cout << "\nTotal Distance: " << TtD << " units";
    } while (hasError1);

}
void Angle() {
    double x1;
    double x2;
    double y1;
    double y2;

    std::vector<double> x;
    std::vector<double> y;
    std::string RorD;

    double xA;
    double yA;

    int AngAmt;
    
    std::cout << "\n**************-Angle-**************\n";
    std::cout << "*                                  *\n";
    std::cout << "*   Enter in x and y coordinates   *\n";
    std::cout << "*                                  *\n";
    std::cout << "************************************\n\n";

    std::cout << "How many angles do you need?\n";
    std::cin >> AngAmt;

    bool hasError2;

    do{

        x.clear();
        y.clear();

        std::cout << "Radians or Degrees? ";
        std::cin >> RorD;
        std::cout << "\n\n";

        for (int i = 0; i <= AngAmt - 1; i++) { 
            std::cout << "Enter in x value number " << i + 1 << ": "; 
            std::cin >> xA; 
            x.push_back(xA); 
            std::cout << "\n\n"; 
        } 

        for (int i = 0; i <= AngAmt - 1; i++) { 
            std::cout << "Enter in y value number " << i + 1 << ": "; 
            std::cin >> yA; 
            y.push_back(yA); 
            std::cout << "\n\n"; 
        }

        for (int j = 0; j < AngAmt - 1; j++) {

        double Diff_y = y.at(j + 1) - y.at(j);
        double Diff_x = x.at(j + 1) - x.at(j);

        double Ang = std::atan2(Diff_y, Diff_x);

        double Rad_to_Deg = (180/PI);

        if (Ang > 180) {
            Ang = 360 - Ang;
        }
        if (Diff_x == 0.0) {
            if (RorD == "Radians" or RorD == "radians" or RorD == "RADIANS" or RorD == "r" or RorD == "R") {
                std::cout << "Degree " << j + 1 << ": 0 radians\n";
            }
            else if (RorD == "Degrees" or RorD == "degrees" or RorD == "DEGREES" or RorD == "d" or RorD == "D") {
                std::cout << "Degree " << j + 1 << ": 0 degrees\n";
            }
        }
        else {       
            if (RorD == "Radians" or RorD == "radians" or RorD == "RADIANS" or RorD == "r" or RorD == "R") {
                std::cout << "Degree " << j + 1 << ": " << Ang << " radians\n";
            }
            else if (RorD == "Degrees" or RorD == "degrees" or RorD == "DEGREES" or RorD == "d" or RorD == "D") {
                std::cout << "Degree " << j + 1 << ": " << Ang * Rad_to_Deg << " degrees\n";
            }
        }
        }
    } while (hasError2);


}
void Dice() {
    int rolls;
    int sides;

    std::cout << "********************-Dice-********************\n\n";

    std::cout << "How many sides? ";
    std::cin >> sides;
    std::cout << "\n\n";

    std::cout << "How many rolls? ";
    std::cin >> rolls;
    std::cout << "\n\n";

    if (rolls <= 10 && sides <= 100) {

    srand(static_cast<unsigned int>(time(NULL)));

    for (int i = 0; i < rolls; ++i) {
        int dieRoll = (rand() % sides) + 1; 
        std::cout << "Roll " << i + 1 << ": " << dieRoll << "\n\n";
    }
    }
    else if (rolls > 10) {
        std::cout << "Too many rolls!\n\n";
    }
    else if (sides > 100) {
        std::cout << "Too many sides!\n\n";
    }

    std::cout << "**********************************************";

}
void CurrentTime () {

    std::string time;

    std::cout << "24 hour or 12 hour time? ";

    std::getline(std::cin, time);



    if (time == "12" or time == "Twelve" or time == "twelve" or time == "TWELVE" or time == "12 hours" or time == "12 HOURS" or time == "twenty-four hours" or time == "Twelve Hours" or time == "twelve hours" or time == "TWENTY-FOUR Hours" or time == "Twelve hours" or time == "TWELVE HOURS" or time == "TWELVE hours") {
        std::atomic<bool> running(true);
        std::thread input_thread(check_input, std::ref(running));

        std::cout << "The current time is: \n\n";
        std::cout << "Press 'q' and hit Enter to exit:\n> " << std::flush;

        while (running) {
            std::time_t now = std::time(nullptr);
            std::tm* local_time = std::localtime(&now);
            char buf12[32];
            std::strftime(buf12, sizeof(buf12), "%I:%M:%S %p", local_time);

            std::cout << "\033[3A\rThe current time is: " << buf12 
                    << "\n\n\n\r> " << std::flush;

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        if (input_thread.joinable()) {
            input_thread.join();
        }
    }
    else if (time == "24" or time == "Twenty-four" or time == "Twenty four" or time == "24 hours" or time == "24 HOURS" or time == "twenty-four hours" or time == "twenty four hours" or time == "Twenty-Four Hours" or time == "TWENTY-FOUR Hours" or time == "twenty-four Hours" or time == "Twenty-Four hours" or time == "TWENTY FOUR HOURS" or time == "TWENTY FOUR hours") {
        std::atomic<bool> running(true);
        std::thread input_thread(check_input, std::ref(running));

        std::cout << "The current time is: \n\n";
        std::cout << "Press 'q' and hit Enter to exit:\n> " << std::flush;

        while (running) {
            std::time_t now = std::time(nullptr);
            std::tm* local_time = std::localtime(&now);
            char buf24[32];
            std::strftime(buf24, sizeof(buf24), "%H:%M:%S", local_time);

            std::cout << "\033[3A\rThe current time is: " << buf24 
                    << "\n\n\n\r> " << std::flush;

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        if (input_thread.joinable()) {
            input_thread.join();
        }
    }
    else {
        std::cout << "Invalid Response. Please try again\n";
    }

    
}
void SimpleTrigCalculator() {
    
    std::string RadorDeg;
    std::string TrigFunction;
    double RadorDeg_Amt;

    std::cout << "\n**************-SimpleTrigCalculator-**************\n";
    std::cout << "*                                                 *\n";
    std::cout << "*          Simple Trignometry Calculator          *\n";
    std::cout << "*                                                 *\n";
    std::cout << "***************************************************\n\n";

    std::cout << "Radians or Degrees?\n";
    std::cin >> RadorDeg;
    std::cout << "\n\n";

    std::cout << "Which trignometric function? (sin, cos, tan, asin, acos, atan)\n";
    std::cin >> TrigFunction;
    std::cout << "\n\n";

    if (RadorDeg == "Radians" or RadorDeg == "radians" or RadorDeg == "RADIANS" or RadorDeg == "r" or RadorDeg == "R") {
        std::cout << "How many Radians?\n";
        std::cin >> RadorDeg_Amt;
        std::cout << "\n\n\n";

        if (TrigFunction == "sin" or TrigFunction == "SIN") {
            std::cout << "Answer: " << sin(RadorDeg_Amt);
        }
        else if (TrigFunction == "cos" or TrigFunction == "COS" or TrigFunction == "cosine" or TrigFunction == "COSINE") {
            std::cout << "Answer: " << cos(RadorDeg_Amt);
        }
        else if (TrigFunction == "tan" or TrigFunction == "TAN" or TrigFunction == "tangent" or TrigFunction == "TANGENT") {
            std::cout << "Answer: " << tan(RadorDeg_Amt);
        }
        else if (TrigFunction == "asin" or TrigFunction == "arcsin" or TrigFunction == "ASIN" or TrigFunction == "ARCSIN") {
            std::cout << "Answer: " << asin(RadorDeg_Amt);
        }
        else if (TrigFunction == "acos" or TrigFunction == "arccos" or TrigFunction == "ACOS" or TrigFunction == "ARCCOS" or TrigFunction == "acosine" or TrigFunction == "arccosine" or TrigFunction == "ACOSINE" or TrigFunction == "ARCCOSINE") {
            std::cout << "Answer: " << acos(RadorDeg_Amt);
        }
        else if (TrigFunction == "atan" or TrigFunction == "arctan" or TrigFunction == "ATAN" or TrigFunction == "ARCTAN" or TrigFunction == "atangent" or TrigFunction == "arctangent" or TrigFunction == "ATANGENT" or TrigFunction == "ARCTANGENT") {
            std::cout << "Answer: " << atan(RadorDeg_Amt);
        }

    }
    else if (RadorDeg == "Degrees" or RadorDeg == "degrees" or RadorDeg == "DEGREES" or RadorDeg == "d" or RadorDeg == "D") {
        std::cout << "How many Degrees?\n";
        std::cin >> RadorDeg_Amt;
        std::cout << "\n\n\n";

        RadorDeg_Amt = RadorDeg_Amt * 180/PI;

        if (TrigFunction == "sin" or TrigFunction == "SIN") {
            std::cout << "Answer: " << sin(RadorDeg_Amt);
        }
        else if (TrigFunction == "cos" or TrigFunction == "COS" or TrigFunction == "cosine" or TrigFunction == "COSINE") {
            std::cout << "Answer: " << cos(RadorDeg_Amt);
        }
        else if (TrigFunction == "tan" or TrigFunction == "TAN" or TrigFunction == "tangent" or TrigFunction == "TANGENT") {
            std::cout << "Answer: " << tan(RadorDeg_Amt);
        }
        else if (TrigFunction == "asin" or TrigFunction == "arcsin" or TrigFunction == "ASIN" or TrigFunction == "ARCSIN") {
            std::cout << "Answer: " << asin(RadorDeg_Amt);
        }
        else if (TrigFunction == "acos" or TrigFunction == "arccos" or TrigFunction == "ACOS" or TrigFunction == "ARCCOS" or TrigFunction == "acosine" or TrigFunction == "arccosine" or TrigFunction == "ACOSINE" or TrigFunction == "ARCCOSINE") {
            std::cout << "Answer: " << acos(RadorDeg_Amt);
        }
        else if (TrigFunction == "atan" or TrigFunction == "arctan" or TrigFunction == "ATAN" or TrigFunction == "ARCTAN" or TrigFunction == "atangent" or TrigFunction == "arctangent" or TrigFunction == "ATANGENT" or TrigFunction == "ARCTANGENT") {
            std::cout << "Answer: " << atan(RadorDeg_Amt);
        }
    }
    else {
        std::cout << "Error. Please try again";
    }

}
void Terminals() {
    std::string terminal;
    std::cout << "*****************-Main_Terminal-*****************\n\n";
    std::cout << "What do you want to do? (Calculator, Distance, Angle, Dice, Current Time, Simple Trignometry Calculator(a bit buggy), Rock-Paper-Scissors(rps), Tic-Tac-Toe(TTT), The Button Game >:)(Enter in word for word for the button game))\n\n";
    std::getline(std::cin, terminal);
    std::cout << "\n\n\n";

    if (terminal == "Calculator" or terminal == "calculator") {
        Calculator();
    }
    else if (terminal == "Distance" or terminal == "distance") {
        Distance();
    }
    else if (terminal == "Angle" or terminal == "angle") {
        Angle();
    }
    else if (terminal == "Dice" or terminal == "dice") {
        Dice();
    }
    else if (terminal == "Current time" or terminal == "current time" or terminal == "current Time" or terminal == "Current Time") {
        CurrentTime();
    }
    else if (terminal == "Simple Trignometry Calculator" or terminal == "simple trignometry calculator" or terminal == "Simple Trignometry calculator" or terminal == "Simple trignometry Calculator" or terminal == "simple Trignometry Calculator" or terminal == "simple trignometry Calculator" or terminal == "Simple trignometry calculator" or terminal == "Simple Trignometry calculator" or terminal == "stc" or terminal == "Stc" or terminal == "sTc" or terminal == "stC" or terminal == "sTC" or terminal == "StC" or terminal == "STc" or terminal == "STC") {
        SimpleTrigCalculator();
    }
    else if (terminal == "Rock Paper Scissors" or terminal == "rock paper scissors" or terminal == "rps" or terminal == "RPS") {
        Rock_Paper_Scissors_Game();
    }
    else if (terminal == "ttt" or terminal == "TTT" or terminal == "Tic-Tac-Toe" or terminal == "tic-tac-toe" or terminal == "TIC-TAC-TOE" or terminal == "Tic Tac Toe" or terminal == "TIC TAC TOE" or terminal == "tic tac toe") {
        Tic_Tac_Toe_Game();
    }
    else if (terminal == "The Button Game >:)" or terminal == "The Button Game") {
        Button();
    }
    else {
        std::cout << "Invalid response. Please type in one of the options above\n";
    }

    std::cout << "\n\n\n*************************************************\n";
}
void Rock_Paper_Scissors_Game() {
    std::string OneorTwo; 
    std::cout << "Welcome to Rock-Paper-Scissors!\n\n"; 
    std::cout << "One player (computer) or 2 player (local)? "; 
    std::getline(std::cin >> std::ws, OneorTwo);

    std::transform(OneorTwo.begin(), OneorTwo.end(), OneorTwo.begin(), [](unsigned char c) {
        return std::toupper(c);
    }); 

    if (OneorTwo == "ONE PLAYER" or OneorTwo == "ONE" or OneorTwo == "1 PLAYER" or OneorTwo == "1") { 
        std::string choice;

        std::cout << "\n\nWhat are you choosing?";
        std::cin >> choice;

        std::transform(choice.begin(), choice.end(), choice.begin(), [](unsigned char n) {
            return std::toupper(n);
        });
        if (choice == "ROCK" or choice == "PAPER" or choice == "SCISSORS") {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distr(1, 3);

            int storedRandomValue = distr(gen);
            
            std::cout << "\n\nComputer's turn!";

            if (storedRandomValue == 1) {
                std::cout << "\n\nThe computer chose rock!\n\n";
                std::string computer_choice = "rock";

                if (choice == "PAPER") {
                    std::cout << "Congratulations! You win!";
                }
                else if (choice == "SCISSORS") {
                    std::cout << "Sorry! You lose!";
                }
                else if (choice == "ROCK") {
                    std::cout << "Tie! Play again?";
                }
            }
            else if (storedRandomValue == 2) {
                std::cout << "\n\nThe computer chose scissors!";
                std::string computer_choice = "scissors";

                if (choice == "ROCK") {
                    std::cout << "Congratulations! You win!";
                }
                else if (choice == "PAPER") {
                    std::cout << "Sorry! You lose!";
                }
                else if (choice == "SCISSORS") {
                    std::cout << "Tie! Play again?";
                }
            }
            else if (storedRandomValue == 3) {
                std::cout << "\n\nThe computer chose paper!";
                std::string computer_choice = "paper";
                
                if (choice == "SCISSORS") {
                    std::cout << "Congratulations! You win!";
                }
                else if (choice == "ROCK") {
                    std::cout << "Sorry! You lose!";
                }
                else if (choice == "PAPER") {
                    std::cout << "Tie! Play again?";
                }
            }
        }
    } 
    else if (OneorTwo == "TWO PLAYER" or OneorTwo == "TWO" or OneorTwo == "2 PLAYER" or OneorTwo == "2") { 
        
        std::string choice1 = ""; 
        std::string choice2; 
        
        std::cout << "Please make player 2 step out of the room.\n\n"; 
        std::cout << "Player 1 choice (30 seconds): " << std::flush; 

        auto start_time = std::chrono::steady_clock::now();
        bool timed_out = false;

        while (true) {
            auto current_time = std::chrono::steady_clock::now();
            if (std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count() >= 30) {
                timed_out = true;
                break;
            }

            if (universal_kbhit()) {
                char ch;
                std::cin >> ch;
                
                if (ch == '\r' || ch == '\n') {
                    break;
                } 
                else if (ch == '\b') {
                    if (!choice1.empty()) {
                        choice1.pop_back();
                        std::cout << "\b \b" << std::flush;
                    }
                } 
                else {
                    choice1 += ch;
                    std::cout << '*' << std::flush;
                }
            }
        }

        std::cout << "\r                                                                " << std::flush;


        if (timed_out) {
            std::cout << "\r########## (Time's up!)\n\n";
        } else {
            std::cout << "\r########## (Saved!)\n\n";
        }

        std::transform(choice1.begin(), choice1.end(), choice1.begin(), [](unsigned char d) { return std::toupper(d); }); 

        if (choice1 != "ROCK" && choice1 != "PAPER" && choice1 != "SCISSORS") { 
            std::cout << "Game has ended for not choosing a right choice\n"; 
        } 
        else { 
            std::cout << "Please make player 1 step out of the room now.\n\n"; 
            std::cout << "Player 2 choice: "; 
            std::cin >> choice2; 
            
            std::transform(choice2.begin(), choice2.end(), choice2.begin(), [](unsigned char e) { return std::toupper(e); }); 

            if (choice2 != "ROCK" && choice2 != "PAPER" && choice2 != "SCISSORS") { 
                std::cout << "Game has ended for not choosing a right choice\n"; 
            } 
            else {
                if ((choice1 == "ROCK" && choice2 == "SCISSORS") or (choice1 == "SCISSORS" && choice2 == "PAPER") or (choice1 == "PAPER" && choice2 == "ROCK")) { 
                    std::cout << "\n\nCongratulations! The winner is player 1!\n"; 
                } 
                else if ((choice2 == "ROCK" && choice1 == "SCISSORS") or (choice2 == "SCISSORS" && choice1 == "PAPER") or (choice2 == "PAPER" && choice1 == "ROCK")) { 
                    std::cout << "\n\nCongratulations! The winner is player 2!\n"; 
                } 
                else { 
                    std::cout << "\n\nTie! Play again?\n"; 
                } 
            }
        } 
    }
}
void Tic_Tac_Toe_Game() {
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    Draw_Board_for_Tic_Tac_Toe(spaces);

    while (running){
        playerMove(spaces, player);
        Draw_Board_for_Tic_Tac_Toe(spaces);
        if (checkWinner(spaces, player, computer)) {
            running = false;
            break;
        }
        else if (checkTie(spaces)) {
            running = false;
            break;
        }

        computerMove(spaces, computer);
        Draw_Board_for_Tic_Tac_Toe(spaces);
        if (checkWinner(spaces, player, computer)) {
            running = false;
            break;
        }
        else if (checkTie(spaces)) {
            running = false;
            break;
        }
    }
    std::cout << "Thank you for playing!\n";

}
void Draw_Board_for_Tic_Tac_Toe(char *spaces) {
    std::cout << '\n';
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  \n";
    std::cout << "     |     |     \n";
    std::cout << '\n';
}
void playerMove(char *spaces, char player) {
    int number;
    do {
        std::cout << "Enter a spot to place a marker (1-9): ";
        std::cin >> number;
        number--;
        if (spaces[number] == ' ') {
            spaces[number] = player;
            break;
        }
    } while (!number > 0 or !number < 8);
}
void computerMove(char *spaces, char computer) {
    int number;
    srand(time(0));

    while (true) {
        number = rand() % 9;
        if (spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
}
bool checkWinner(char *spaces, char player, char computer) {

    if ((spaces[0] != ' ') && (spaces[0] == spaces[1] && spaces[1] == spaces[2])) {
        spaces[0] == player ? std::cout << "Congratulations! You win!\n" : std::cout << "Sorry. You lose!\n";
    }
    else if ((spaces[3] != ' ') && (spaces[3] == spaces[4] && spaces[4] == spaces[5])) {
        spaces[3] == player ? std::cout << "Congratulations! You win!\n" : std::cout << "Sorry. You lose!\n";
    }
    else if ((spaces[6] != ' ') && (spaces[6] == spaces[7] && spaces[7] == spaces[8])) {
        spaces[6] == player ? std::cout << "Congratulations! You win!\n" : std::cout << "Sorry. You lose!\n";
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[3] && spaces[3] == spaces[6])) {
        spaces[0] == player ? std::cout << "Congratulations! You win!\n" : std::cout << "Sorry. You lose!\n";
    }
    else if ((spaces[1] != ' ') && (spaces[1] == spaces[4] && spaces[4] == spaces[7])) {
        spaces[1] == player ? std::cout << "Congratulations! You win!\n" : std::cout << "Sorry. You lose!\n";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[5] && spaces[5] == spaces[8])) {
        spaces[2] == player ? std::cout << "Congratulations! You win!\n" : std::cout << "Sorry. You lose!\n";
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[4] && spaces[4] == spaces[8])) {
        spaces[0] == player ? std::cout << "Congratulations! You win!\n" : std::cout << "Sorry. You lose!\n";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[4] && spaces[4] == spaces[6])) {
        spaces[2] == player ? std::cout << "Congratulations! You win!\n" : std::cout << "Sorry. You lose!\n";
    }
    else {
        return false;
    }
    return true;

}
bool checkTie(char *spaces) {

    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }

    std::cout << "IT'S A TIE!\n";

    return true;
}
void check_input(std::atomic<bool>& running) {
    char ch;
    while (running) {
        if (std::cin >> ch && ch == 'q') {
            running = false;
        }
    }
}
void Button() {
    std::string Questions[] = {
        "(Easy😀)What is 1 + 1", 
        "(Medium🤓)What is 2 * 2 * 2", 
        "(Hard💀)Type in: I H4V3 P1ZZ4!!", 
        "(Impossible😈)What is the hex code for pure blue?", 
        "(Godly Impossible🔥🔥🔥, 30 seconds)What is x if 4(x-2) - (2x-3)/3 = 5/2*(x+1) + 3?", 
        "(Easy😀)What did Sir Issac Newton discover?: A. Inertia, B. Planetary Paths, C. Calculus, D. Gravity", 
        "What is true? A. 1+1 is 5, B. Earth is flat, C. A cloud weighs around a million tons, D. The Great Wall of China is visible from space", 
        "Which fact is false? A. Tyrannosaurus rex usually roars for 1 hour every day, B. A shrimp's heart is located inside its head, C. All the electrons powering the entire internet globally weigh about the same as a single apricot, D. Roblox is not a game", 
        "What did I eat for breakfast? A. Bread, B. I don't know, C. Breakfast", 
        "Why did the person cross the road? A. I don't know, B. To get to the other side?, C. Because the walk light was on", 
        "Pick a number: A. 10, B. 18, C. 12351345, D. 17", 
        "What was the answer for Question number 3?"
    };

    StartButton(Questions);
    DrawButton();
    UserInput_Button(Questions);
}
void DrawButton() {
    std::cout << R"(               )" << std::endl;
    std::cout << R"(                  ___________         )" << std::endl;
    std::cout << R"(                / ***********\       )" << std::endl;
    std::cout << R"(              / ***************\     )" << std::endl;
    std::cout << R"(            / *******************\   )" << std::endl;
    std::cout << R"( *********************************************)" << std::endl;
    std::cout << R"( *                                           *)" << std::endl;
    std::cout << R"( *                                           *)" << std::endl;
    std::cout << R"( *                                           *)" << std::endl;
    std::cout << R"( *                                           *)" << std::endl;
    std::cout << R"( *                                           *)" << std::endl;
    std::cout << R"( *                                           *)" << std::endl; 
}
void StartButton(std::string Questions[]) {
    std::cout << std::endl << std::endl << "   (Press enter to hit the button)" << std::endl << std::endl << std::endl << std::endl;
    std::cout << "           DON'T PRESS THE BUTTON!!!" << std::endl << std::endl << std::endl;
}
void UserInput_Button(std::string Questions[]) {
    std::string enter;
    while (true) {
        std::getline(std::cin, enter);
        if (enter.empty()) {
            QButton(Questions);
            break;
        }
        std::cout << "PRESS ENTER ONLY" << std::endl << std::endl;
    }
}
void QButton(std::string Questions[]) {
    std::string E; 
    double Q1, Q2, Q5; 
    std::string Q3, Q4, Q12; 
    char Q6, Q7, Q8, Q9, Q10, Q11; 

    std::cout << "Button has been pressed.\n\n"; 
    WaitButton(); 

    std::cout << std::endl << Questions[0] << std::endl; 
    std::cin >> Q1; 
    if (Q1 != 2) { std::cout << "WRONG!!! TRY AGAIN!!!\n\n\n"; DrawL(); } 
    ClearBuffer();

    std::cout << "\n\nThe button is surpised!   😮\n\n"; WaitButton(); 
    std::cout << std::endl << Questions[1] << std::endl; 
    std::cin >> Q2; 
    if (Q2 != 8) { ErrorMessage(); } 
    ClearBuffer();

    std::cout << "\n\nThe button is not happy!   😡\n\n"; WaitButton(); 
    std::cout << std::endl << Questions[2] << std::endl; 
    std::getline(std::cin, Q3); 
    if (Q3 != " I H4V3 P1ZZ4!!") { ErrorMessage(); } 

    std::cout << "\n\nThe button is scared!   😨\n\n"; WaitButton(); 
    std::cout << std::endl << Questions[3] << std::endl; 
    std::cin >> Q4; 
    if (Q4 != "#0000FF") { ErrorMessage(); } 
    ClearBuffer();

    std::cout << "\n\nThe button gives you a side eye!   ~_~\n\n"; WaitButton(); 
    std::cout << std::endl << Questions[4] << std::endl; 
    std::cin >> Q5; 
    if (Q5 != 15) { ErrorMessage(); }
    ClearBuffer();


    std::cout << "\n\nThe button is pissed off!   o(*≧▽≦)ツ┏━┓\n\n"; WaitButton(); 
    std::cout << std::endl << Questions[5] << std::endl; 
    std::cin >> Q6; 
    if (Q6 != 'D') { ErrorMessage(); }
    ClearBuffer();


    std::cout << "\n\nThe button is really mad!!!   🤬\n\n"; WaitButton(); 
    std::cout << std::endl << Questions[6] << std::endl; 
    std::cin >> Q7; 
    if (Q7 != 'C') { ErrorMessage();}
    ClearBuffer();

    std::cout << "\n\nTHE BUTTON TURNED INTO 3 DEMONS!   😈😈😈\n\n"; WaitButton(); 
    std::cout << std::endl << Questions[7] << std::endl; 
    std::cin >> Q8; 
    if (Q8 != 'B') { ErrorMessage();}
    ClearBuffer();

    std::cout << "\n\nTHE THREE DEMONS ARE MAD!   👿👿👿\n\n"; WaitButton(); 
    std::cout << std::endl << Questions[8] << std::endl; 
    std::cin >> Q9; 
    if (Q9 != 'C') { ErrorMessage();}
    ClearBuffer();

    std::cout << "\n\nThe button is ready to fight!   ⚔️⚔️⚔️\n\n"; WaitButton(); 
    std::cout << std::endl << Questions[9] << std::endl; 
    std::cin >> Q10; 
    if (Q10 != 'C') { ErrorMessage();}
    ClearBuffer();

    std::cout << "\n\nHowever, you get your atomic bomb...   😱😱😱\n\n"; WaitButton(); 
    std::cout << std::endl << Questions[10] << std::endl; 
    std::cin >> Q11; 
    if (Q11 != 'D') { ErrorMessage();}
    ClearBuffer();

    std::cout << "\n\nAND VAPORIZE THE DEMONS!!!   💀🪦💀\n\n"; WaitButton(); 
    std::cout << std::endl << Questions[11] << std::endl; 
    std::cin >> Q12; 
    if (Q12 != "(Enters in completely safe and correct answer)") { std::cout << "BUT THE DEMONS EMERGE FROM THE ASHES AND DESTROY YOU, THEREFORE MAKING YOU TAKE THE L!!!!!!\n"; ErrorMessage();}

    std::cout << "\n\nCONGRATULATIONS! You beat the button! Wait...\n";

    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "It can't be...\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(2500));

    std::cout << "WHAT IS THAT?!?!?!?!?!?!                                                      👾-hello i have come to destroy u for k*lling my button friend >:)\n";

}
void WaitButton() {
    int lower_bound = 300;
    int upper_bound = 1000;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(lower_bound, upper_bound);
    
    int random_num = distr(gen);
    if (random_num % 100 < 10) {
        std::cout << "(" << random_num / 100 << ".0" << random_num % 100 << " seconds)" << std::endl << std::endl;
    }
    else {
        std::cout << "(" << random_num / 100 << "." << random_num % 100 << " seconds)" << std::endl << std::endl;
    }
    
    for (int centiseconds = 0; centiseconds <= random_num; ++centiseconds) {
        int seconds = centiseconds / 100;
        int remaining_centiseconds = centiseconds % 100;
        std::cout << "\rTime: " << seconds << "." << std::setw(2) << std::setfill('0') << remaining_centiseconds << "s" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    std::cout << std::endl;
}
void ErrorMessage() {
    std::cout << "WRONG!!! TRY AGAIN!!!\n\n\n";
    DrawL();
}
void DrawL() {
    int N = 3;
    
    std::cout << "\033[2J\033[1;1H";

    for (int i = 0; i < N; i++) { 
        std::cout << "  ___ \n";
        std::cout << " |   |\n";
        std::cout << " |   |\n";
        std::cout << " |   |\n";
        std::cout << " |   |\n";
        std::cout << " |   |\n";
        std::cout << " |   |________\n";
        std::cout << " |____________|\n" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(470));
        std::cout << "\033[8A";

        std::cout << "   ___ \n";
        std::cout << "  |   |\n";
        std::cout << "  |   |\n";
        std::cout << "  |   |\n";
        std::cout << "  |   |\n";
        std::cout << "  |   |\n";
        std::cout << "  |   |________\n";
        std::cout << "  |____________|\n" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(470));
        std::cout << "\033[8A";

        std::cout << "  ___ \n";
        std::cout << " |   |\n";
        std::cout << " |   |\n";
        std::cout << " |   |\n";
        std::cout << " |   |\n";
        std::cout << " |   |\n";
        std::cout << " |   |________\n";
        std::cout << " |____________|\n" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(470));
        std::cout << "\033[8A";

        std::cout << " ___ \n";
        std::cout << "|   |\n";
        std::cout << "|   |\n";
        std::cout << "|   |\n";
        std::cout << "|   |\n";
        std::cout << "|   |\n";
        std::cout << "|   |________\n";
        std::cout << "|____________|\n" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(470));

        if (i < (N - 1)) { 
            std::cout << "\033[8A"; 
        } 
    }

    std::exit(0);
}
void ClearBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
#pragma endregion
#pragma endregion
