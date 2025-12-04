#include "../include/ide.h"
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Starting Complex Multi-Language IDE..." << std::endl;
    
    IDEApp app;
    app.initialize();
    app.run();
    app.shutdown();
    
    return 0;
}