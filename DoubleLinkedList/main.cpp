//
//  main.cpp
//  DoubleLinkedList
//
//  Created by Prashant Gurung on 22/04/2022.
//

#include <iostream>
#include "DoubleLinked.h"

int main(int argc, const char * argv[]) {
   

    DoubleLink list1;
    list1.addAtBegining(1);
    list1.addAtBegining(60);
    list1.addAtLast(9);
    list1.addAtLast(90);
    list1.addatPos(3, 8);
    list1.deleteAtPos(1);
    list1.deleteAtBegining();
    list1.deleteAtLast();
    list1.deleteAtBegining();
    list1.deleteAtLast();
    
    
    list1.display();
    
    
    std::cin.get();
    return 0;
}
