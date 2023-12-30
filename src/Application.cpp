#include "Application.h"

Application::Application(YoutubeAlgorithm* yta) : mp_yalgo{ yta }
{
    //should contain setup
}

Application::~Application() //dtor
{
    delete mp_yalgo;
} 

  // Driver Code
void Application::run() // This will contain the main loop
{
    
}

void Application::cleanup() // after the main application is run, free any pointers we used in this class. 
{

}