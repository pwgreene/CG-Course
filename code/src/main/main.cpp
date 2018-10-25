#include <stdio.h>
#include <iostream>
#include "linalg/Vector2.h"
#include "linalg/Vector3.h"

void test_Vector2()
{
    Vector2 v0 = Vector2();
    Vector2 v1 = Vector2(1, 3);
    Vector2 v2 = v0 + v1;
    assert(v2[0] == 1 && v2[1] == 3);
    v2 = v0 * v1;
    assert(v2[0] == 0 && v2[1] == 0);
    v2 = v1 * 0;
    assert(v2[0] == 0 && v2[1] == 0);
}

void test_Vector3()
{
    Vector3 v0 = Vector3(1, 1, 1);
    Vector3 v1 = Vector3(3, 4.5, 6);
    Vector3 v2 = v0 * v1;
    assert(v2[0] == 3 && v2[1] == 4.5 && v2[2] == 6);
    assert(v0.magnitude() == sqrt(3));
    assert(Vector3::dot(v0, v1) == 13.5);
    v2 = Vector3::cross(v0, v1);
    assert(v2[0] == 1.5 && v2[1] == -3 && v2[2] == 1.5);
}

int main()
{
    test_Vector2();
    test_Vector3();
    std::cout << "All tests pass!\n";
}
