#ifndef ORDER_H 
#define ORDER_H
#include <iostream>
class Order {
  public:
    Order();
    ~Order();
    void Display();
    void SetBurger(std::string burger_in);
    void SetSidedish(std::string sidedish_in);
    void SetDrink(std::string drink_in);
    void SetOrderNumber(int order_num_in);
    void SetCharge(double charge_in);
  private:
    std::string burger;
    std::string sidedish;
    std::string drink;
    int order_num;
    double charge;
};
#endif 