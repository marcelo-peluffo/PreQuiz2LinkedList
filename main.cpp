#include <iostream>

#include "LinkedList.hpp"

int main()
{   
    LinkedList<int> list;

    // {2, 4}
    list.append(2);
    list.append(4);
    list.setHead(1);
    list.setTail(67);
    
    std::cout << list;  

}
