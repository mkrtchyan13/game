#include<iostream>
#include<string>
using namespace std;

class Game 
{   int clicks = 0; 

     char shuffled_cards[4][4] = { { 'a', 'b', 'c', 'd' },
                        {'e', 'f', 'g', 'h'},
                        { 'a', 'b', 'c', 'd' },
                        {'e', 'f', 'g', 'h'} };

int row1, row2, column1, column2;
public:
    Game()
    {
        row1 = 0; row2 = 0; column1 = 0; column2 = 0;
    }


void start()
{ char temp[1];

   for (int i = 0 ; i < 4 ; i++) {
   for (int j = 0 ; j < 4 ; j++) {
       int i1 = (int)(rand()%4);
       int j1 = (int)(rand()%4);
       temp[0]= shuffled_cards[i][j];
     shuffled_cards[i][j]=shuffled_cards[i1][j1];
    shuffled_cards[i1][j1]=temp[0];
   }
   }

    for (int i = 0 ; i < 4 ; i++) {
   for (int j = 0 ; j < 4 ; j++) {
   cout << " " << shuffled_cards[i][j] << " ";
        }
        cout<<endl;
   }
    cout << " \n    1 2 3 4\n";
    cout << "   ";
    for (int x = 0; x <= 8; x++)
    {
        cout << "-";
    }
    cout << endl;

    for (int x = 0; x < 4; x++)
    {
        cout << x + 1 << " | ";
        for (int y = 0; y < 4; y++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
    input();
}

void input()
{
    srand(time(0));
    cout << "Type the first card’s row and column.\n";
    cin >> row1;
    cin >> column1;
    cout << "Type the second card’s row and column\n";
    cin >> row2;
    cin >> column2;

    row1--; row2--; column1--; column2--;
    cout << "     1 2 3 4\n";
    cout << "   ";
    for (int x = 0; x <= 8; x++)
    {
        cout << "_";  
    }
    cout << endl;
    for (int x = 0; x < 4; x++)
    {
        cout << x + 1 << " | ";
        for (int y = 0; y < 4; y++)
        {
            if ((x == row1) && (y == column1))
            {
                cout << shuffled_cards[x][y] << " ";
            }
            else if ((x == row2) && (y == column2))
            {
                cout << shuffled_cards[x][y] << " ";
            }
            else cout << "* ";
        }
        cout << endl;
    }
   match();

}

 
  void match()
  {    
      
      if(row1==row2 && column2==column1){
      cout<<"You can't choose same card twice try again\n";
      input();
  }
      else if (shuffled_cards[row1][column1] == shuffled_cards[row2][column2])
    {   
        cout << "It's a match\n";
        shuffled_cards[row1][column1]="X";
        shuffled_cards[row2][column2]="X";
        clicks++;
        input();
    }
     else
        cout << "Not a match\n";
        clicks++;
        input();

}

};

 int main()
{
     Game memoryMatch;
    memoryMatch.start();
    system("pause");
     return clicks;
 }