/* Auction Database Program
 use later to clear screen system("cls");
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>
#include <sstream>


using namespace std;

int clear(string hmsg)
{
    
    int x = 0;
    int y = 0;    
	system("cls");
	while (x<80)
	{
	cout << "-";
	x++;
    }
    cout << "\n";
    x = 0;
   	while (x<36)
	{
	cout << " ";
	x++;
    }
    cout << "Database";
   	while (x<36)
	{
	cout << " ";
	x++;
    }
    cout << "\n\n";
    x = 0;
	while (x<80)
	{
	cout << "-";
	x++;
    }
    cout << "*";
    x=0;
    while (x<78)    
    {
          cout << " ";
          x++;
    }
    cout <<"*";
    if (hmsg == "" )
    {cout << "\n";}
    else {
    cout << hmsg;}
    x = 0;
    while (x < 80)
    { cout << "*";
      x++;
    }
    cout << "\n\n";
}
void setcolor()
{ 
 HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); 
 SetConsoleTextAttribute(hCon,10);
// SetConsoleBackgroundAttribute(hCon,5); 
} 






int main()
{
    setcolor();
// DELCARATION OF VARIABLES
    int quit;
    string rep;
    string pricestr[8];
    float price;
    float lot;
    float buyer;
    string item;
    string array[1000][4][100];
    int n;
    int b;
    int p;
    string target[5];
    int flag;
    string tmp1;
    string tmp2;
    string tmp3;
    string tmp4;
    int x;
    string hmsg;
    float total;
    float sub;
   
//END OF DECLARATION    
    
//START OF MAIN FUNCTION

     cout << "Now running auction database program.\n";
     start:
     
     cout << "Loading database.dat...\n";
     ifstream myfile;
     myfile.open("database.dat");
     if (myfile.is_open())
     {
     p = 0;

     while (!myfile.eof())
     {
           getline (myfile,tmp1,'|');
           getline (myfile,tmp2,'|');
           getline (myfile,tmp3,'|');
           getline (myfile,tmp4,'|');
           array[p][0][0] = tmp1;
           array[p][1][0] = tmp2;
           array[p][2][0] = tmp3;
           array[p][3][0] = tmp4;
           p+=1;          
     }
     }
     else 
     { cout << "File doesn't exsist.  Creating file.\n\n";
       ofstream myfile;
            myfile.open ("database.dat", ios::app);
            myfile << "";
            myfile.close();
            cout << "File Created.\n\n";
            system("PAUSE");
            hmsg = "File 'database.dat' successfully created.\n";
            clear(hmsg);
            goto start;
       }
     hmsg= "Database.dat successfully loaded.\n";  
     cout << "\nData file loaded!\n\n\n\n";
     system("PAUSE");
     myfile.close();
while (quit != 'x')
{ 
     
     select:
     clear(hmsg);      
     x = 0;
     cout << ".....:::::";
     while( x <22)
     { cout << " "; x++;}
     cout << "Select a function";
     x = 0;
     while( x <22)
     { cout << " "; x++;}
     cout << "::::.....";
     cout << "\n\n\t[1] - Input\n\t[2] - Retrieve\n\t[3] - Total Buyer's Bill\n\t[4] - Print Buyer Info\n\n";
     cout << ">";
     cin >> rep;
     if (rep == "1")
     {
             hmsg = "Type the buyer information to be put into the database.\n";
             clear(hmsg);
             // input information start
            cout << "Buyer number: ";
            cin >> buyer;
            cout << "Lot number: ";
            cin >> lot;
            cout << "Item: ";
            cin >> item;
            cout << "Price: $";
            cin >> price;
            // input information end
            
          
            //save to file start
            
            ofstream myfile;
            myfile.open ("database.dat", ios::app);
            myfile << buyer << "|" << lot << "|" << item << "|" << price  << "|";
            myfile.close();
            hmsg = "Buyer data successfully entered.\n";
            goto select;
            //save to file end
     }
     else if (rep == "2")
     {
            hmsg = "Search database for buyer information using the buyer number.\n";
            clear(hmsg);
            cout << "Enter buyer number:\n";
            cout << ">";
            cin >> target[0];
            ifstream myfile;
            myfile.open("database.dat");
     p = 0;

     while (!myfile.eof())
     {
           getline (myfile,tmp1,'|');
           getline (myfile,tmp2,'|');
           getline (myfile,tmp3,'|');
           getline (myfile,tmp4,'|');
           array[p][0][0] = tmp1;
           array[p][1][0] = tmp2;
           array[p][2][0] = tmp3;
           array[p][3][0] = tmp4;
           p+=1;          
     }
     
            hmsg = "Buyer data found!\n";
            clear(hmsg);
            total = 0;
             for(long cntr = 0; cntr < 1000; cntr++)
              {
                if(array[cntr][0][0] == target[0])
                 {
                
                 cout << "\n\nBuyer found!\n";
                 tmp1 = array[cntr][0][0];
                 stringstream(tmp1) >> buyer;
                 tmp2 = array[cntr][1][0];
                 stringstream(tmp2) >> lot;
                 item = array[cntr][2][0];
                 tmp4 = array[cntr][3][0];
                 stringstream(tmp4) >> price;
                 cout << "Buyer: " << buyer << "\n";
                 cout << "Lot: " << lot << "\n";
                 cout << "Item: " << item << "\n";
                 cout << "Price: $" << price << "\n\n";
                 total = total + price   ;           
                 flag += 1;
                  }
               }
               
  
// Test to see if target was found.

            if(flag < 1)
             {
             
             cout << "Buyer not found." << endl;
             system("PAUSE");
             hmsg = "Are you sure you typed the buyer number correctly?\n."; 
             goto select;
             }
             cout << "Display buyer total?\n\t[1] - Yes\n\t[2] - No\n>";
             cin >> rep;
             if (rep == "1")
             {
                hmsg= "Would this buyer like to pay his/her bill?\n";     
                ptotal:
                clear(hmsg);     
                cout << "\nTotal for buyer " << buyer << " is: $" << total << "\nPay total?\n\t[1] - Yes\n\t[2] - No\n>";
                cin >> rep;
                if (rep == "1")
                {
                        hmsg = "Enter amout to be subtracted from buyer's total.\n";
                        clear(hmsg);
                        cout<<"\nEnter amount buyer paid.\n>$";
                        cin >> sub;
                        price = total;
                        total = total - sub;
                        lot = 0;
                        item = "Payment";
                        price = total - price;
                        ofstream myfile;
                        myfile.open ("database.dat", ios::app);
                        myfile << buyer << "|" << lot << "|" << item << "|" << price  << "|";
                        myfile.close();
                        cout <<"Buyers remaining total is $" << total << "\n";
                        hmsg = "Payment to total successfully made.\n";
                        
                }
                else if (rep == "2")
                {
                     hmsg = "No payment made to total.\n";
                     goto select;
                }
                else
                {
                    cout << "Invalid selection.  Please try again.\n";
                    hmsg = "Please type 1 for yes and 2 for no.\n";
                    goto ptotal;
                }
             }         
             
                         
            system("PAUSE");
            goto select;
     }
     else if (rep == "3")
     {
          hmsg = "Pay total from the 'input' selection.\n";
          goto select;
     }
     else if (rep == "4")
     {
            hmsg = "Search database for buyer information using the buyer number.\n";
            clear(hmsg);
            cout << "Enter buyer number:\n";
            cout << ">";
            cin >> target[0];
            ifstream myfile;
            myfile.open("database.dat");
     p = 0;

     while (!myfile.eof())
     {
           getline (myfile,tmp1,'|');
           getline (myfile,tmp2,'|');
           getline (myfile,tmp3,'|');
           getline (myfile,tmp4,'|');
           array[p][0][0] = tmp1;
           array[p][1][0] = tmp2;
           array[p][2][0] = tmp3;
           array[p][3][0] = tmp4;
           p+=1;          
     }
     
            hmsg = "Buyer data found!\n";
            clear(hmsg);
            total = 0;
             for(long cntr = 0; cntr < 1000; cntr++)
              {
                if(array[cntr][0][0] == target[0])
                 {
                 
                 cout << "\n\nBuyer found!\n";
                 tmp1 = array[cntr][0][0];
                 stringstream(tmp1) >> buyer;
                 tmp2 = array[cntr][1][0];
                 stringstream(tmp2) >> lot;
                 item = array[cntr][2][0];
                 tmp4 = array[cntr][3][0];
                 stringstream(tmp4) >> price;
                 cout << "Buyer: " << buyer << "\n";
                 cout << "Lot: " << lot << "\n";
                 cout << "Item: " << item << "\n";
                 cout << "Price: $" << price << "\n\n";
                 ofstream print; 
                 print.open(ios::out); 
                 print << "Buyer: " << buyer << "\n";
                 print << "Lot: " << lot << "\n";
                 print << "Item: " << item << "\n";
                 print << "Price: $" << price << "\n\n";
                 print.close();
                 total = total + price   ;           
                 flag += 1;
                 }
                  
               }
               if (flag > 1)
               {
                  ofstream print; 
                  print.open; 
                  cout << "Total: $" << total << "\n\n\n";
                  print << "Total: $" << total << "\n";
                  print.close();
                  system("PAUSE");
                  hmsg = "Information on this buyer has been printed.\n";
                  clear(hmsg);
               }
               else
               {
                   cout << "Buyer not found." << endl;
                   system("PAUSE");
                   hmsg = "Are you sure you typed the buyer number correctly?\n."; 
                   goto select;
               }
          
        
     }
     else 
     {
          
          hmsg = "Invalid choice.  Please choose again.\n";
          goto select;
     }
             
             
//END OF MAIN FUNCTION
}
    hmsg = "Please select 1 for yes and 2 for no.\n";
    clear(hmsg);
    cout << "ARE YOU SURE YOU WANT TO QUIT?\n\t[1] - Yes\n\t[2] - No\n";
    cout << ">";
    cin >> rep;
    if (quit == 1)
    {
    quit:
    system("PAUSE");
    }
    else if (quit == 2)
    {    hmsg = "Returned to function selection.";
         goto select;}
    else 
    { cout << "Invalid choice.  Please choose again.\n\n";
      hmsg = "Please select 1 for yes and 2 for no.\n";
      clear(hmsg);
    }
}
