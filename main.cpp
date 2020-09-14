// I will have you know that I don't have any idea, any idea, what's the point of it.
// [REDACTED]
// Well, it might have no use - but making it sure was fun!

#include <iostream>

class retang; // Don't touch him! He's more important than you will ever be!

class board{
    int x, y, z;
public:
    friend void drawer(board one, retang first);
    board(int a, int b, int c)
    {
        x=a;
        y=b;
        z=c;
    }
};

class retang:public board{ // My second attempt at inheritance and friend functions, first was worse.
    int x1, y1, z1;
public:
    friend void drawer(board one, retang first);
    retang(int x, int y, int z, int a, int b, int c):board(x, y, z){
        x1=a;
        y1=b;
        z1=c;
    };
};

void drawer(board one, retang first);

int main(){
    board one(20, 9, 2); // X Y Z board.
    retang first(1, 1, 1, 2, 2, 2); // Left-top, and right-down corner of a rectangle, on X Y Z plane.
    drawer(one, first);
}

// You don't have to search anymore. Magic starts here.
// Not really. It's a normal drawer function with 3 buffers instead of two.
void drawer(board one, retang first){
    for(int bufferZ=1; bufferZ<=one.z; bufferZ++){
        for(int bufferY=1; bufferY<=one.y; bufferY++){
            for(int bufferX=1; bufferX<=one.x; bufferX++){ // Those 3 guys under do all the work.
                if((first.z<=bufferZ) && (first.z1>=bufferZ) && (first.x<=bufferX) && (first.x1>=bufferX) && (first.y<=bufferY) && (first.y1>=bufferY)) std::cout << "X ";
                else if((bufferZ==first.z) && (bufferY==first.y) && (bufferX==first.x)) std::cout << "X ";
                else if((bufferZ==first.z1) && (bufferY==first.y1) && (bufferX==first.x1)) std::cout << "X ";
                else std::cout << ". "; // You can leave 2 spaces here, for more immersion.
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
} // I just like making comments. It makes me remember things faster and feel better. Nice.
// 56 lines of code!? What the hell!? My code is getting thicker than taller!
