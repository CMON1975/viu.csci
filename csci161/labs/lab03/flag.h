class Flag {
  public:
    //create a Flag object 
    Flag(int width, int height, char symbol);
    //create a Flag object with width = height = 1 and symbol = '*'
    Flag();
    ~Flag();  // properly destroy a Flag object
    int GetWidth();     //get width of the flag object
    int GetHeight();    //get height of the flag object
    char GetSymbol();   //get the display symbol of the flag object
    void Resize(int new_width, int new_height);
    void ChangeSymbol(char new_symbol);
    int Calculate();    //calculate the number of characters 
                        //needed to display this Flag object
    void Display();     //display the Flag object using its symbol
    bool BigFlag();     //return true if this Flag object uses
                        //more than 25 characters to display;
                        //otherwise, return false
  private:
    int width;
    int height;
    char symbol;
};
