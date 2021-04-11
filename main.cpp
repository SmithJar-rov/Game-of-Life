#include <iostream>
#include <unistd.h>
#include "life.cpp"

using namespace std;

int main(int argc, char *argv[]) {
    srand(time(NULL));
    World game_of_life(100);
    int t = 0;
    while (true){
        game_of_life.print();
        game_of_life.evolve();
        t++;
        cout << "\n\n";
        sleep(1);
        std::system("clear");
    }
    return 0;
}
