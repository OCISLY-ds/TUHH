#include "/Users/florianvonbargen/Desktop/TUHH C++/kittens/BitmapPlusPlus.hpp"

int main() {
    bmp::Bitmap picture;

    picture.load("/Users/florianvonbargen/Desktop/TUHH C++/Übung 2/empty_pic.bmp");
    
    picture.set(10,11,bmp::Red);
    picture.set(10,12,bmp::Green);
    picture.set(10,13,bmp::Blue);
    picture.set(11,11,bmp::Green);
    picture.set(11,12,bmp::Blue);
    picture.set(11,13,bmp::Red);
    picture.set(12,11,bmp::Blue);
    picture.set(12,12,bmp::Red);
    picture.set(12,13,bmp::Green);

    picture.save("/Users/florianvonbargen/Desktop/TUHH C++/Übung 2/empty_picsavedSquare.bmp");

    return 0; 
}
