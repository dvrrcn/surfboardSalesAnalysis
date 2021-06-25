//  week 05
//  surfboardSalesAnalysis.cpp : 
//  Darren Cronover

using namespace std;

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

//call to functions, so they can be used in any order throughout.
int MakeChoice(int iTotalXXXS, int iTotalSmall, int iTotalMedium, int iTotalLarge);
void DisplayPurchase(const int iTotalXXXS, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge);
void DisplayTotal(const int iTotalXXXS, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge);


void DisplayHeader(int WIDTH) {
    //use format manipulators to beautify the console
    string STR1 = " Welcome to my Johnny Utah's PointBreak SurfShop ";
    cout << setfill('*') << setw(WIDTH) << '*' << endl;
    cout << setw((WIDTH / 2) - (STR1.length() / 2)) << ' ' << STR1 << setw((WIDTH / 2) - (STR1.length() / 2)) << " " << endl;
    cout << setw(WIDTH) << '*' << endl;
    cout << "\n" << endl;
}

void ShowUsage(int iTotalXXXS, int iTotalSmall, int iTotalMedium, int iTotalLarge) {
    // diplay instructions to the user
    cout << "To show program usage 'S'" << endl;
    cout << "To purchase a surfboard press 'P'" << endl;
    cout << "To display current purchases press 'C'" << endl;
    cout << "To display total amount due press 'T'" << endl;
    cout << "To quit the program press 'Q'" << endl;
    MakeChoice(iTotalXXXS, iTotalSmall, iTotalMedium, iTotalLarge);
}
void MakePurchase(int& iTotalXXXS, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge) {
    // user enters their quantity and type of board, the total amount of each board increments by the quantity
    string type;
    char size;
    int quantity;
    cout << "Please enter the quantity and type (X=xxxsmall, S=small, M=medium, L=large) of surfboard you would like to purchase: ";
    cin.get(); // this, with the getline() allow the dev to access specific indexed elements of the string.
    getline(cin, type);
    quantity = (int(type[0]) - '0'); // converts the char to an int, first converting it to ascii value then subtracting the ascii value of 0 to get the real integer number
    size = type[type.length()-1]; // always take the last character of the string, allows for spaces in between the quantity and the size
    switch (toupper(size)) {
    case('S'):
        iTotalSmall = iTotalSmall + quantity;
        break;
    case('M'):
        iTotalMedium = iTotalMedium + quantity;
        break;
    case('L'):
        iTotalLarge = iTotalLarge + quantity;
        break;
    case('X'):
        iTotalXXXS = iTotalXXXS + quantity;
        break;
    }
    MakeChoice(iTotalXXXS, iTotalSmall, iTotalMedium, iTotalLarge);
}
int MakeChoice(int iTotalXXXS, int iTotalSmall, int iTotalMedium, int iTotalLarge) {
    // calls a different function based on the key pressed by the user.
    // each function calls back to MakeChoice()

    string CHOICE = "\nPlease enter selection: ";
    char selection = ' ';
    cout << CHOICE;
    cin >> selection;
    switch (toupper(selection)) {
    case ('S'):
        ShowUsage(iTotalXXXS, iTotalSmall, iTotalMedium, iTotalLarge);
        break;
    case ('P'):
        MakePurchase(iTotalXXXS, iTotalSmall, iTotalMedium, iTotalLarge);
        break;
    case('C'):
        DisplayPurchase(iTotalXXXS, iTotalSmall, iTotalMedium, iTotalLarge);
        break;
    case('T'):
        DisplayTotal(iTotalXXXS, iTotalSmall, iTotalMedium, iTotalLarge);
        break;
    case('Q'):
        cout << "Thank you" << endl;
        system("pause");
        return 0;
        break;
    }
}
void DisplayPurchase(const int iTotalXXXS, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge) {
    // displays the total number of each surfboard purchased
    string strS = "The total number of small surfboards is ",
           strM = "The total number of medium surfboards is ",
           strL = "The total number of large surfboards is ",
           strX = "The total number of XXXS surfboards is ";

    if (iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0 && iTotalXXXS == 0) { // if none of them - print this
        cout << "No purchases made yet." << endl;
    }
    if (iTotalSmall > 0) {
        cout << strS << iTotalSmall << endl;
    }
    if (iTotalMedium > 0) {
        cout << strM << iTotalMedium << endl;
    }
    if (iTotalLarge > 0) {
        cout << strL << iTotalLarge << endl;
    }
    if (iTotalXXXS > 0) {
        cout << strX << iTotalXXXS << endl;
    }
    MakeChoice(iTotalXXXS, iTotalSmall, iTotalMedium, iTotalLarge);
}
void DisplayTotal(const int iTotalXXXS, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge) {
    // display the contents of the entire sale
    // also accounts for if there is none of a given value
    string strS = "The total number of small surfboards is ",
           strM = "The total number of medium surfboards is ",
           strL = "The total number of large surfboards is ",
           strX = "The total number of XXXS surfboards is ",
           strT = " at a total of $";

    double smallprice = 175.00,
           mediumprice = 190.00,
           largeprice = 200.00,
           xsprice = 150.00,
           totalprice = 0.00;

    if (iTotalSmall > 0) {
        cout << strS << iTotalSmall << strT << iTotalSmall * smallprice << endl;
        totalprice = totalprice + (smallprice*iTotalSmall);
    }
    if (iTotalMedium > 0) {
        cout << strM << iTotalMedium << strT << setprecision(2) << fixed << iTotalMedium * mediumprice << endl;
        totalprice = totalprice + (mediumprice*iTotalMedium);
    }
    if (iTotalLarge > 0) {
        cout << strL << iTotalLarge << strT << setprecision(2) << fixed << iTotalLarge * largeprice << endl;
        totalprice = totalprice + (largeprice*iTotalLarge);
    }
    if (iTotalXXXS > 0) {
        cout << strX << iTotalXXXS << strT << setprecision(2) << fixed << iTotalXXXS * xsprice << endl;
        totalprice = totalprice + (xsprice * iTotalXXXS);
    }
    if (iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0 && iTotalXXXS == 0) {
        cout << "No purchases made yet." << endl;
    }
    else
        cout << "Amount due: $" << setprecision(2) << fixed << totalprice << endl;
    MakeChoice(iTotalXXXS, iTotalSmall, iTotalMedium, iTotalLarge);
}
int main()
{
    // declare variables, aimed to keep main as simple as possible for this assignment
    const float WIDTH = 60;
    int iTotalSmall = 0,
        iTotalMedium = 0,
        iTotalXXXS = 0,
        iTotalLarge = 0;

    DisplayHeader(WIDTH);
    ShowUsage(iTotalXXXS, iTotalSmall, iTotalMedium, iTotalLarge);
    return 0;
}