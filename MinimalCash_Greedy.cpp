// Adam 
//

#include <iostream>
#include <algorithm>

const int N = 5;
int Count[N] = { 4,2,2,2,6 };//the number of each cash 
int Value[N] = { 1,5,10,50,100 };// 1$,5$,10$......
//this function require input money , return the numbers of cash that can be minimal used
int Minimal_CashNumber(int money) {
    int num = 0;
    for (int i = N - 1; i >= 0; i--) {
        int c = std::min(money / Value[i], Count[i]);//the number require 
        money = money - c * Value[i];
        num += c;//total numbers of cash 
    }
    if (money > 0) num = -1;
    return num;
}//solve
int main()
{
    std::cout << Minimal_CashNumber(361);
}//main
