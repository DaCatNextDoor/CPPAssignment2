

#include "Application.h"#
#//usign: fix this for moving average later

Application::Application(YoutubeAlgorithm* yta) : mp_yalgo{ yta }
{
    //should contain setup
    Moving_Average<double, double, 30> MovAvg;


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