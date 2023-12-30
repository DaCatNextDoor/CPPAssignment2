#include "YoutubeAlgorithm.h"
#include "User.h"
#include "Creator.h"

enum class currentPerson
{
	USER,
	CREATOR,
	ERROR
};

class Application
{

public:
	Application(YoutubeAlgorithm* yta); // Constructor (ctor for short)
	~Application(); // dtor

	// Driver Code
	void run(); // This will contain the main loop
	void cleanup(); // after the main application is run, free any pointers we used in this class. 

private:
	currentPerson cp;
	YoutubeAlgorithm* mp_yalgo; // This is not a pointer so we don't need to free it in cleanup
};