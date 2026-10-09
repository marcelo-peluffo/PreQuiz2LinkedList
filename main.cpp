#include <sstream>
#include <iostream>
#include "Vector.hpp"
#include "LinkedList.hpp"

int main() {   
    LinkedList<int> list;

    // {2, 4}
    list.append(2);
    list.append(4);
    list.setHead(1);
    list.setTail(67);
    
    std::cout << list;

    // Google Gemini (Xcode Antigravity) ZyBooks Test Case Simulation for Vector.hpp:
    std::cout << "=== Running Vector<T> Tests ===" << std::endl;

    // Test 1: Default constructor
    {
        std::cout << "\n[Test 1] Default Constructor: ";
        Vector<int> v;
        if (v.getX() == 1 && v.getY() == 1) {
            std::cout << "PASS (x = 1, y = 1)" << std::endl;
        } else {
            std::cout << "FAIL (expected x=1, y=1; got x=" << v.getX() << ", y=" << v.getY() << ")" << std::endl;
        }
    }

    // Test 2: Parameterized constructor
    {
        std::cout << "\n[Test 2] Parameterized Constructor: ";
        Vector<int> v(3, 7);
        if (v.getX() == 3 && v.getY() == 7) {
            std::cout << "PASS (x = 3, y = 7)" << std::endl;
        } else {
            std::cout << "FAIL (expected x=3, y=7; got x=" << v.getX() << ", y=" << v.getY() << ")" << std::endl;
        }
    }

    // Test 3: Setters and Getters
    {
        std::cout << "\n[Test 3] Setters and Getters: ";
        Vector<int> v;
        v.setX(15);
        v.setY(25);
        if (v.getX() == 15 && v.getY() == 25) {
            std::cout << "PASS (x = 15, y = 25)" << std::endl;
        } else {
            std::cout << "FAIL (expected x=15, y=25; got x=" << v.getX() << ", y=" << v.getY() << ")" << std::endl;
        }
    }

    // Test 4: operator+
    {
        std::cout << "\n[Test 4] Operator+: ";
        Vector<int> v1(2, 3);
        Vector<int> v2(4, 5);
        Vector<int> sum = v1 + v2;
        if (sum.getX() == 6 && sum.getY() == 8) {
            std::cout << "PASS (2, 3) + (4, 5) = (6, 8)" << std::endl;
        } else {
            std::cout << "FAIL (expected (6, 8); got (" << sum.getX() << ", " << sum.getY() << "))" << std::endl;
        }
    }

    // Test 5: operator-
    {
        std::cout << "\n[Test 5] Operator-: ";
        Vector<int> v1(7, 9);
        Vector<int> v2(3, 4);
        Vector<int> diff = v1 - v2;
        if (diff.getX() == 4 && diff.getY() == 5) {
            std::cout << "PASS (7, 9) - (3, 4) = (4, 5)" << std::endl;
        } else {
            std::cout << "FAIL (expected (4, 5); got (" << diff.getX() << ", " << diff.getY() << "))" << std::endl;
        }
    }

    // Test 6: Prefix ++
    {
        std::cout << "\n[Test 6] Prefix ++: ";
        Vector<int> v(2, 3);
        Vector<int> &ref = ++v;
        if (v.getX() == 3 && v.getY() == 4 && &ref == &v) {
            std::cout << "PASS (mutated to (3, 4) and returned reference to *this)" << std::endl;
        } else {
            std::cout << "FAIL (expected (3, 4); got (" << v.getX() << ", " << v.getY() << "))" << std::endl;
        }
    }

    // Test 7: Postfix ++
    {
        std::cout << "\n[Test 7] Postfix ++: ";
        Vector<int> v(2, 3);
        Vector<int> old = v++;
        std::cout << "Returned value: (" << old.getX() << ", " << old.getY() << "), ";
        std::cout << "Current value: (" << v.getX() << ", " << v.getY() << ") -> ";
        if (old.getX() == 2 && old.getY() == 3 && v.getX() == 3 && v.getY() == 4) {
            std::cout << "PASS" << std::endl;
        } else {
            std::cout << "FAIL" << std::endl;
        }
    }

    // Test 8: Prefix --
    {
        std::cout << "\n[Test 8] Prefix --: ";
        Vector<int> v(5, 6);
        Vector<int> &ref = --v;
        if (v.getX() == 4 && v.getY() == 5 && &ref == &v) {
            std::cout << "PASS (mutated to (4, 5) and returned reference to *this)" << std::endl;
        } else {
            std::cout << "FAIL (expected (4, 5); got (" << v.getX() << ", " << v.getY() << "))" << std::endl;
        }
    }

    // Test 9: Postfix --
    {
        std::cout << "\n[Test 9] Postfix --: ";
        Vector<int> v(5, 6);
        Vector<int> old = v--;
        std::cout << "Returned value: (" << old.getX() << ", " << old.getY() << "), ";
        std::cout << "Current value: (" << v.getX() << ", " << v.getY() << ") -> ";
        if (old.getX() == 5 && old.getY() == 6 && v.getX() == 4 && v.getY() == 5) {
            std::cout << "PASS" << std::endl;
        } else {
            std::cout << "FAIL" << std::endl;
        }
    }

    // Test 10: Stream insertion operator<< with std::ostringstream & chaining
    {
        std::cout << "\n[Test 10] Stream insertion operator<<: ";
        Vector<int> v1(10, 20);
        Vector<int> v2(30, 40);
        std::ostringstream oss;
        // Test formatted output and chaining
        oss << v1 << " -> " << v2;
        std::string expected = "(10, 20) -> (30, 40)";
        if (oss.str() == expected) {
            std::cout << "PASS (captured output: \"" << oss.str() << "\")" << std::endl;
        } else {
            std::cout << "FAIL (expected \"" << expected << "\", got \"" << oss.str() << "\")" << std::endl;
        }
    }

    // Test 11: Floating-point Vector<double>
    {
        std::cout << "\n[Test 11] Vector<double>: ";
        Vector<double> vd1(1.5, 2.5);
        Vector<double> vd2(0.5, 1.5);
        Vector<double> vdSum = vd1 + vd2;
        if (vdSum.getX() == 2.0 && vdSum.getY() == 4.0) {
            std::cout << "PASS ((1.5, 2.5) + (0.5, 1.5) = (2.0, 4.0))" << std::endl;
        } else {
            std::cout << "FAIL" << std::endl;
        }
    }

    std::cout << "\n=== Finished Vector<T> Tests ===" << std::endl;
    return 0;
}
