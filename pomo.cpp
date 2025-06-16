
#include "pomo_utils.cpp"
#include <iostream>



int main()
{
    std::cout << "Welcome to the Pomodoro Timer App!" << std::endl;
   
    start(current_session_type);    

    while (true){
        std::cout << "\nSession ended. Press enter to start next session (or 'q' to quite):";
        std::string input;
        std::getline(std::cin,input);

        if (input =="q" || input = "Q"){
            break;
        }
        nextSession();
    }
    std::cout << "Thanks for using the Pomodoro App!  Toodleloo" << std:endl;
    return 0;
}