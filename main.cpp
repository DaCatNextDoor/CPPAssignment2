#include <iostream>
#include <fstream>
#include "src/Creator.h"
#include "src/Person.h"
#include "src/User.h"
#include "src/Application.h"

/*
int main(int argc, char const *argv[])
{
    int opt;
    std::cout << "Enter 1 to proceed or 0 to quit:" << std::endl;
    std::cin >> opt;

    outerloop: while (opt > 0)
    {
        std::cout << "Please login with your details blah blah" << std::endl;

        usertypeLoop: while (true)
        {
            //code 
        }
        
        //code
    }
    
    //code
    std::cout << "Hello";
    return 0;
}
*/

enum class StatusCode { SUCCESS = 0, FAILURE = 1 };
#define STATUS_SUCCESSFUL StatusCode::SUCCESS

// Deduce the return type of main at compile time (for fun)
template<typename T>
struct MainReturnType 
{
    using type = typename std::conditional<
            std::is_enum<T>::value,
            std::underlying_type_t<T>,
            T
            >::type
};
#define MAIN_RETURN_TYPE MainReturnType<decltype(STATUS_SUCCESSFUL)>::type

auto main() -> MAIN_RETURN_TYPE
{

    Application* app;
    app->run();
    app->cleanup();
    delete app;

    return static_cast<MAIN_RETURN_TYPE>(STATUS_SUCCESSFUL);
}
