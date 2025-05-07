#include <assert.h>
#include <iostream>
#include "Monster.h"
#include "Player.h"
#include "GameManager.h"
#include "Engine.h"
#include "Point2D.h"

void Point2DUnitTest()
{
    Point2D A(0, 1);
    Point2D B(2, 3);

    // equality
    bool bEqual = A == B;
    assert(bEqual == false);

    bEqual = B == Point2D(2, 3);
    assert(bEqual == true);

    // Inequality
    bool bNotEqual = A != B;
    assert(bNotEqual == true);

    bNotEqual = B != Point2D(2, 3);
    assert(bNotEqual == false);

    // Point2D + Point2D
    Point2D C = A + B;
    assert(C == Point2D(2, 4));

    // Point2D - Point2D
    C = B - A;
    assert(C == Point2D(2, 2));

    // Point2D * int
    C = A * 2;
    assert(C == Point2D(0, 2));

    // Point2D / int
    C = Point2D(6, 4) / 2;
    assert(C == Point2D(3, 2));

    // int * Point2D
    C = 2 * B;
    assert(C == Point2D(4, 6));

    // negate
    C = -B;
    assert(C == Point2D(-2, -3));

    // Point2D += Point2D
    B += Point2D(2, 1);
    assert(B == Point2D(4, 4));

    // Point2D -= Point2d
    B -= Point2D(2, 1);
    assert(B == Point2D(2, 3));

    // Point2D *= int
    B *= 2;
    assert(B == Point2D(4, 6));

    // Point2D /= int
    B /= 2;
    assert(B == Point2D(2, 3));

    std::cout << "Point2DUnitTest Passed all asserts." << std::endl;
}

//int main()
//{
//    Engine::Initialize();
//
//    Point2D* point2D = new Point2D;
//
//    Point2DUnitTest();
//    GameManager* manager = new GameManager();
//    Monster* monster = new Monster();
//
//    Player* player = new Player();
//
//    manager->runGame(monster, player);
//    return 0;
//}