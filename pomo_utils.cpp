#include "pomo.h";
#include <chrono>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;
using namespace std;

void  start()
{
    
}
void runsession(int duration)
{
    const auto timer_duration = duration;
    const auto start = std::chrono::steady_clock::now();
    std::chrono::duration<double> time_left = timer_duration - (std::chrono::steady_clock::now()-start);
    while (time_left > 0s)
    {
        const auto hrs = std::chrono::duration_cast<std::chrono::hours>(time_left);
        const auto mins = std::chrono::duration_cast<std::chrono::minutes>(time_left - hrs);
        const auto secs = std::chrono::duration_cast<std::chrono::seconds>(time_left - hrs - mins);
        std::cout << std::setfill('0') << std::setw(2) << hrs.count() << ":"
                  << std::setfill('0') << std::setw(2) << mins.count() << ":"
                  << std::setfill('0') << std::setw(2) << secs.count() << "\n";
        std::this_thread::sleep_for(1s);

        time_left = timer_duration - (std::chrono::steady_clock::now() - start);
    }
    std::cout << "Done\n";
    
}

void nextSession()
{

}

void pause()
{

}

void resume()
{

}

void stop()
{

}