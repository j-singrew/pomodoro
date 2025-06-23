
#include "pomo.h"
#include <iostream>
#include <string>
#include <limits>



int main()
{
    Pomodoro myPomo;

    std::cout <<"Welcome to your pomodoro Timer" << std::endl;
    std::string command;
    
    while(true){
    std::cout << "Current session type: ";
    switch(myPomo.getCurrentSessionType()){
        case SessionType::Work:
            std::cout << "Work";
            break;
        case SessionType::ShortBreak:
            std::cout << "Short break";
        case SessionType::LongBreak:
            std::cout <<"Long Break";
            break;
    }
    std::cout << std::endl;
    std::cout <<"Enter command (start,pause,resume,stop,exit): ";
    std::cin >> command;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    if (command == "start"){
        myPomo.startSession();
    }else if (command == "pause"){
        myPomo.pause();
    }else if (command == "resume"){
        myPomo.resume();
    }else if (command =="stop"){
        myPomo.stop();
    }else if (command=="exit"){
        if (myPomo.getCurrentSessionType() == SessionType::Work){
            std::cout <<"A session is active .Stopping it before exiting." << std::endl;
            myPomo.stop();
        }
        std::cout << "Exiting Pomodoro Timer .Goodbye!" << std::endl;
        break;
    }else{
        std::cout <<"Invalid command .Please try again " << std::endl;
    }
    }
    return 0;

}