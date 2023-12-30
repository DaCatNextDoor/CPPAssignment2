#include "YoutubeAlgorithm.h"

class Application
{

public:
	Application(YoutubeAlgorithm* yta); // Constructor (ctor for short)
	~Application(); // dtor

	// Driver Code
	void run(); // This will contain the main loop
	void cleanup(); // after the main application is run, free any pointers we used in this class. 

private:
	//User** mpp_users; //Just as an example preferably you are using std::vector<User> which means the "cleanup()" func is not needed
	YoutubeAlgorithm* mp_yalgo; // This is not a pointer so we don't need to free it in cleanup
};