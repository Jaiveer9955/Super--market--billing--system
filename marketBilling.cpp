#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;

class Bill
{
private:
    string Item;
    int Rate, Quantity;

public:
    Bill() : Item(""), Rate(0), Quantity(0) {}

    void SetItem(string item)
    {
        Item = item;
    }
    void SetRate(int rate)
    {
        Rate = rate;
    }
    void SetQuant(int quant)
    {
        Quantity = quant;
    }

    string getItem()
    {
        return Item;
    }
    int getRate()
    {
        return Rate;
    }

    int getQuant()
    {
        return Quantity;
    }
};

void addItem(Bill b)
{
    bool close = false;
    while (!close)
    {
        int choice;
        cout << "\t1.Add" << endl;
        cout << "\t2.close" << endl;
        cout << "\t enter choice:";
        cin >> choice;

        if (choice == 1)
        {
            system("cls");
            string item;
            int rate, quant;
            cout << "\t Enter item name:";
            cin >> item;
            b.SetItem(item);

            cout << "\t enter rate of item";
            cin >> rate;
            b.SetRate(rate);

            cout << "\t enter quantity of item";
            cin >> quant;
            b.SetQuant(quant);

            ofstream out("C:/Bill.txt", ios::app);
            if (!out)
            {
                cout << "\t Error: file not open" << endl;
            }
            else
            {
                out << "\t" << b.getItem() << ":" << b.getRate() << ":" << b.getQuant() << endl
                    << endl;
            }
            cout << "\t Item Added successfuly" << endl;
            Sleep(1000);
        }
        else if (choice == 2)
        {
            system("cls");
            close = true;
            cout << "\tBack To Main Menu" << endl;
            cout << "\t ********************************" << endl;
            Sleep(1000);
        }
    }
}

void printBill()
{
    system("cls");
    int count = 0;
    bool close = false;
    while (!close)
    {
        system("cls");
        int choice;
        cout << "\t1.Add Bill" << endl;
        cout << "\t2.Close Session" << endl;
        cout << "\t.enter choice" << endl;

        cin >> choice;

        if (choice == 1)
        {
            string item;
            int quant;
            cout << "\tEnter item";
            cin >> item;
            cout << "\tEnter quantity:";
            cin >> quant;

            ifstream in("C:/Bill.txt");       // read data from file
            ofstream out("C:/Bill temp.txt"); // write data in file

            string line; // for get readed data
            bool found = false;
            while (getline(in, line))
            {
                stringstream ss;
                ss << line;
                string itemName;
                int itemRate;
                int itemQuant;
                char delimiter;
                ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant;
                if (item == itemName)
                {

                    found = true;
                    if (quant <= itemQuant)
                    {
                        int amount = itemRate * quant;
                        cout << "\t Item | Rate| Quantity | Amount" << endl;
                        cout << "\t" << itemName << "\t" << itemRate << "\t" << quant << "\t" << amount << endl;
                        int newQuant = itemQuant - quant;
                        itemQuant = newQuant;
                        count += amount;

                        out << "\t" << itemName << ":" << itemRate << ":" << itemQuant << endl;
                    }
                    else
                    {
                        cout << "\tSorry, " << item << "Ended" << endl;
                    }
                }
                else
                {
                    out << line;
                }
            }
            if (!found)
            {
                cout << "\t Item is out of stock" << endl;
            }
            out.close(); // Temporary file (out)
            in.close();
            remove("C:/Bill.txt");
            rename("C:/Bill temp.txt", "C:/Bill.txt");
        }
        else if (choice == 2)
        {
            close = true;
            cout << "\t counting Total bill" << endl;
        }
        Sleep(3000);
    }
    system("cls");
    cout << "\t Total Bill-----------------------:" <<count<< endl;
    cout << "\t Thanks for shopping" << endl;
    cout << "\t Visit Again" << endl;
    Sleep(5000);
}

int main()
{
    Bill b;

    bool exit = false;
    while (!exit)
    {
        system("cls");
        int val;

        cout << "\t Welcome  To  Super  Market" << endl;
        cout << "\t ********************************" << endl;
        cout << "\t\t1.Add Item" << endl;
        cout << "\t\t2.Print bill" << endl;
        cout << "\t\t3.exit" << endl;
        cout << "\t\t4.Enter choice:";

        cin >> val;
        if (val == 1)
        {
            system("cls");
            addItem(b);
            Sleep(1000);
        }
        else if (val == 2)
        {
            printBill();
        }

        else if (val == 3)
        {
            system("cls");
            exit = true;
            cout << "\t God luck" << endl;
            Sleep(1000);
        }
    }
}