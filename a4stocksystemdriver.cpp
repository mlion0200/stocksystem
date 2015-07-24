// File:        a4stocksystemdriver.cpp
// Author:      Geoffrey Tien
// Date:        2015-07-08
// Description: Interactive test driver for StockSystem class
//              Only StockSystem functions are tested. You are still responsible
//              for thoroughly testing your RedBlackTree functions
//              using your own test driver or by adding custom code to this driver.

#include <iostream>
#include <cstdlib>
#include <string>

#include "redblacktree.h"
#include "stocksystem.h"

using namespace std;

// forward declarations
void PrintMenu();
void ExtraTests();

// program entry point
int main()
{
  ExtraTests();

  int choice = 0;
  unsigned int asku;
  string adesc;
  double aprice;
  unsigned int amount;
  string ctlg = "";

  StockSystem mystore;

  while (choice != 8)
  {
    PrintMenu();
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush the cin stream including newline

    switch (choice)
    {
      case 1: // Print balance
        cout << "Funds: $" << mystore.GetBalance() << endl << endl;
        break;
      case 2: // Print catalogue
        ctlg = mystore.GetCatalogue();
        cout << ctlg << endl;
        break;
      case 3: // Add SKU
        cout << "Enter a numeric SKU (will be converted to 5 digits): ";
        cin >> asku;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter item description: ";
        getline(cin, adesc);
        cout << "Enter a retail price: $";
        cin >> aprice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (mystore.StockNewItem(StockItem(asku, adesc, aprice)))
          cout << "Successfully added item to catalogue." << endl;
        else
          cout << "Item not added to catalogue." << endl;
        break;
      case 4: // Edit item description
        cout << "Enter a numeric SKU to edit: ";
        cin >> asku;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter item description: ";
        getline(cin, adesc);
        if (mystore.EditStockItemDescription(asku, adesc))
          cout << "Item successfully updated." << endl;
        else
          cout << "Item not updated." << endl;
        break;
      case 5: // Edit item price
        cout << "Enter a numeric SKU to edit: ";
        cin >> asku;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a retail price: $";
        cin >> aprice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (mystore.EditStockItemPrice(asku, aprice))
          cout << "Item successfully updated." << endl;
        else
          cout << "Item not updated." << endl;
        break;
      case 6: // Restock an item
        cout << "Enter a numeric SKU to purchase: ";
        cin >> asku;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a quantity to purchase: ";
        cin >> amount;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the per-unit purchase price: $";
        cin >> aprice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (mystore.Restock(asku, amount, aprice))
          cout << "Item successfully restocked." << endl;
        else
          cout << "Item not restocked." << endl;
        break;
      case 7: // Sell an item
        cout << "Enter the SKU of item to sell: ";
        cin >> asku;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a quantity to sell: ";
        cin >> amount;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (mystore.Sell(asku, amount))
          cout << "Transaction complete. Have a nice day." << endl;
        else
          cout << "Item is out of stock. Sorry!" << endl;
        break;
      case 8: // Quit
        // no need to do anything, will cause while loop to break
        break;
      default:
        cout << "Invalid choice." << endl;
        break;
    }
  }

  return 0;
}

void PrintMenu()
{
  cout << "****************************************************\n"
       << "* Please select an option:                         *\n"
       << "* 1. Print balance             6. Restock an item  *\n"
       << "* 2. Print catalogue           7. Sell an item     *\n"
       << "* 3. Add a new SKU                                 *\n"
       << "* 4. Edit item description                         *\n"
       << "* 5. Edit item price           8. Quit             *\n"
       << "****************************************************\n" << endl;
  cout << "Enter your choice: ";
}

void ExtraTests()
{
  // Add additional testing code here.
  // Create RedBlackTree objects and StockSystem objects
  //   and perform operations on them, etc.
  // Pay attention to special cases!
  // Note that objects created here are local to this function,
  //   and will have their destructors called when this function returns.

  // Have fun...

}