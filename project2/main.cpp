#include "LoanBookHeap.h"
#include <string>
#include <iostream>


int main()
{
    LoanBookHeap<std::string> bHeap;

    try{
        bHeap.insert("jonhyeok");
        bHeap.insert("taewan");
        bHeap.insert("jeyoung");
        bHeap.insert("minkyu");
        bHeap.insert("jaehyun");
        bHeap.insert("dongu");
        bHeap.insert("habin");
        bHeap.insert("donghyun");
        bHeap.insert("seungsoo");
		bHeap.insert("youngro");
        bHeap.print();
		std::cout << std::endl << std::endl;
		bHeap.pop();
		bHeap.pop();
		bHeap.pop();
		bHeap.pop();
		bHeap.pop();
		bHeap.pop();
		bHeap.print();
    }
	catch(char const *str)
	{
		std::cout << str;
		return 0;
	}
	return 0;
}