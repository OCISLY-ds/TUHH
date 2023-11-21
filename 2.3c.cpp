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
    for (int i = 30; i < 42; i++) {
        picture.set(30, i, bmp::Red);
    }
    for (int i = 100; i < 108; i++) {
        picture.set(i, 111, bmp::Blue);
    }
    int a = 15;
    for (; a < 26; a++) {
        picture.set(a, a, bmp::Green);
    }

    picture.save("/Users/florianvonbargen/Desktop/TUHH C++/Übung 2/empty_picsavedLines.bmp");


    return 0; 
}
