/*
                                                Tower of Hanoi
                                    - The player has 2^n + n total moves.
                                    - The player wins if he can put all the rings on the third stack before the moves run out.
                                    - The game is displayed on a console using x-y coordinate.
*/
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<cmath>
using namespace std;

struct stackNode{  // stack declaration
    int item;
    stackNode *next = nullptr;
};
stackNode *head1 = nullptr, *head2 = nullptr, *head3 = nullptr; //pointers to the stacks
int numtotal;       // number of integers used in game
int size1 = 0, size2 = 0, size3 = 0; // size of each stack
int moves;  // total moves allowed

bool isEmpty(int pos)  // checks if a stack is empty using parameter
{
    switch(pos)
    {
        case 1:
            return (head1 == nullptr);
        case 2:
            return (head2 == nullptr);
        case 3:
            return (head3 == nullptr);

    }
    return false;
}
void push(int pos, int data)  // push value to specific stack using parameter
{
    stackNode *st = new stackNode;
    switch(pos)
    {
        case 1:
            st->item = data;
            st->next = head1;
            head1 = st;
            st = nullptr;
            size1++;
            break;
        case 2:
            st->item = data;
            st->next = head2;
            head2 = st;
            st = nullptr;
            size2++;
            break;
        case 3:
            st->item = data;
            st->next = head3;
            head3 = st;
            st = nullptr;
            size3++;
            break;

    }
}
int pop(int pos)   // remove an item from a stack
{
    int stackTop;
    stackNode *temp;
    switch(pos)
    {
        case 1:
            if (isEmpty(1)){
                cout  << "Empty stack pick another move!" << endl;
            }
            else{
                stackTop = head1->item;
                temp = head1;
                head1 = head1->next;
                temp->next = nullptr;
                delete temp;
                size1--;
                return stackTop;
            }
            break;
        case 2:
            if (isEmpty(2)){
                cout  << "Empty stack pick another move!" << endl;
            }
            else{
                stackTop = head2->item;
                temp = head2;
                head2 = head2->next;
                temp->next = nullptr;
                delete temp;
                size2--;
                return stackTop;
            }
            break;
        case 3:
            if (isEmpty(3)){
                cout  << "Empty stack pick another move!" << endl;
            }
            else{
                stackTop = head3->item;
                temp = head3;
                head3 = head3->next;
                temp->next = nullptr;
                delete temp;
                size3--;
                return stackTop;
            }
            break;
    }
    exit(0);
}
void makeEmpty(int i)   // remove values from a stack
{
    switch(i)
    {
        stackNode *temp;
        case 1:
            if (head1 != nullptr){
                while (head1->next != nullptr){
                    temp = head1;
                    head1 = head1->next;
                    delete temp;
                }
                delete head1;
                head1 = nullptr;
            }
            break;
        case 2:
            if (head2 != nullptr){
                while (head2->next != nullptr){
                    temp = head2;
                    head2 = head2->next;
                    delete temp;
                }
                delete head2;
                head2 = nullptr;
            }
            break;
        case 3:
            if (head3 != nullptr){
                while (head3->next != nullptr){
                    temp = head3;
                    head3 = head3->next;
                    delete temp;
                }
                delete head3;
                head3 = nullptr;
            }
            break;
    }

}
void initialize()  // initialize first stack with values
{
    system("cls");
    if (isEmpty(3) == false){
        makeEmpty(3);
    }
    cout << "\n\n\t\t\t\t\t     ----------------------" << endl;
    cout << "\t\t\t\t\t       Tower of Hanoi !!!  "<< endl;
    cout << "\t\t\t\t\t     ----------------------" << endl;
    cout << "\n\n\t\t\t\tHow many integers do you want in the game?" << endl;
    cout << "\t\t\t\t\t\tChoice: "; cin >> numtotal;
    for (int i = numtotal; i >= 1; i--){
        stackNode *st = new stackNode;
        st->item = i;
        st->next = head1;
        head1 = st;
    }
    size1 = numtotal;
    moves = pow(2,numtotal) + numtotal;
}
bool peek(int from, int to)   // checks the value on top of the two stacks
{
    int num1, num2;
    switch(from)
    {
        case 1: if(isEmpty(1))
                {
                    cout << "Stack is empty!" << endl;
                    return false;
                }
                num1 = head1->item;
                break;
        case 2: if(isEmpty(2))
                {
                    cout << "Stack is empty!" << endl;
                    return false;
                }
                num1 = head2->item;
                break;
        case 3: if(isEmpty(3))
                {
                    cout << "Stack is empty!" << endl;
                    return false;
                }
                num1 = head3->item;
                break;
    }
    switch(to)
    {
        case 1: if(isEmpty(1))
                {
                    return true;
                }
                num2 = head1->item;
                break;
        case 2: if(isEmpty(2))
                {
                    return true;
                }
                num2 = head2->item;
                break;
        case 3: if(isEmpty(3))
                {
                    return true;
                }
                num2 = head3->item;
                break;
    }
    return (num1 < num2);
}
void SetCursorPosition(int x, int y)    // x-y coordinate places the cursor in right position
{
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(output, pos);
}
void display()  // display stacks using x-y coordinate
{
    system("cls");
    system("cls");
    cout << "\n\n\t\t\t\t\t     ----------------------" << endl;
    cout << "\t\t\t\t\t       Tower of Hanoi !!!  "<< endl;
    cout << "\t\t\t\t\t     ----------------------" << endl;
    cout << "\n\n\t\t    How to Play!" << endl;
        cout << "\n\t\tFrom A to B Press: 1" << endl;
        cout << "\t\tFrom A to C Press: 2" << endl;
        cout << "\t\tFrom B to A Press: 3" << endl;
        cout << "\t\tFrom B to C Press: 4" << endl;
        cout << "\t\tFrom C to A Press: 5" << endl;
        cout << "\t\tFrom C to B Press: 6" << endl;
        cout << "\n\t\tNumber of moves left: " << moves;
    int x = 70, y = 7;
    stackNode *p = head1;
    size1 = 0;
    size2 = 0;
    size3 = 0;
    for (int i = 0; i <= numtotal; i++){
            if (i == numtotal){
                SetCursorPosition(x, y + i);
                cout << "|_________|";
                SetCursorPosition(x, y + i + 1);
                cout << "     A     ";
                SetCursorPosition(x + 15, y + i);
                cout << "|_________|";
                SetCursorPosition(x + 15, y + i + 1);
                cout << "     B     ";
                SetCursorPosition(x + 30, y + i);
                cout << "|_________|";
                SetCursorPosition(x + 30, y + i + 1);
                cout << "     C     ";
            }
            SetCursorPosition(x, y + i);
            cout << "|";
            SetCursorPosition(x + 10, y + i);
            cout << "|";
            SetCursorPosition(x + 15, y + i);
            cout << "|";
            SetCursorPosition(x + 25, y + i);
            cout << "|";
            SetCursorPosition(x + 30, y + i);
            cout << "|";
            SetCursorPosition(x + 40, y + i);
            cout << "|";
            cout << endl;
    }
    if (isEmpty(1)){
        goto next;
    }
    while (p != nullptr)
    {
        p = p->next;
        size1++;
    }
    p = head1;
    for (int i = numtotal - size1 + 1; i <= numtotal; i++){
        SetCursorPosition(x + 5, y + i);
        if (p != nullptr){
            cout << p->item;
            p = p->next;
        }
        else
            break;
    }
    size1 = 0;
    next:
    p = head2;
    if (isEmpty(2)){
        goto next2;
    }
    while (p != nullptr)
    {
        p = p->next;
        size2++;
    }
    p = head2;
    for (int i = numtotal - size2 + 1; i <= numtotal; i++){
        SetCursorPosition(x + 20, y + i);
        if (p != nullptr){
            cout << p->item;
            p = p->next;
        }
        else
            break;
    }
    size2 = 0;
    next2:
    p = head3;
    if (isEmpty(3)){
        goto next3;
    }
    while (p != nullptr)
    {
        p = p->next;
        size3++;
    }
    p = head3;
    for (int i = numtotal - size3 + 1; i <= numtotal; i++){
        SetCursorPosition(x + 35, y + i);
        if (p != nullptr){
            cout << p->item;
            p = p->next;
        }
        else
            break;
    }
    size3 = 0;
    next3:
    p = nullptr;
}
void retrial(); // asks user if he/she wants to play again
void playGame()  // plays the game till win/lose using loops
{
    initialize();
    system("cls");
    int moved = 0;
    while(!(isEmpty(1) && isEmpty(2))){
        retry:
        display();
        cout << "\n\n\n\n\n\n\n\n\n\t\tChoice: ";
        moved = getch();
        --moves;
        if(moves == 0){
            system("cls");
            cout << "\n\t\t\t\t\t\t\tGame over!" << endl;
            cout << "\t\t\t\t\t\t   Too many attempts." << endl;
            retrial();
            return;
        }
        switch(moved)
        {
            case '1':
                if(peek(1, 2)){
                    push(2, pop(1));
                }
                else{
                    moves++;
                    system("pause");
                }
                break;
            case '2':
                if(peek(1, 3)){
                    push(3, pop(1));
                }
                else{
                    moves++;
                    system("pause");
                }
                break;
            case '3':
                if(peek(2, 1)){
                    push(1, pop(2));
                }
                else{
                    moves++;
                    system("pause");
                }
                break;
            case '4':
                if(peek(2, 3)){
                    push(3, pop(2));
                }
                else{
                    moves++;
                    system("pause");
                }
                break;
            case '5':
                if(peek(3, 1)){
                    push(1, pop(3));
                }
                else{
                    moves++;
                    system("pause");
                }
                break;
            case '6':
                if(peek(3, 2)){
                    push(2, pop(3));
                }
                else{
                    moves++;
                    system("pause");
                }
                break;
            default:
                cout << "Invalid try again!\n";
                system("pause");
                goto retry;
        }
    }
    system("cls");
    display();
    cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tCongratulations You win!!!" << endl;
    retrial();
}
int main() // game menu
{
     system("color f0");
     int choice;
     system("cls");
     cout << "\n\n\t\t\t\t\t|----------------------|" << endl;
     cout << "\t\t\t\t\t|  Tower of Hanoi !!!  |"<< endl;
     cout << "\t\t\t\t\t|----------------------|" << endl;
     cout << "\n\t\t\t\t\t\t Menu" << endl;
     cout << "\n\t\t\t\t\t 1. Play a game." << endl;
     cout << "\t\t\t\t\t 2. How to play." << endl;
     cout << "\t\t\t\t\t 3. Credits." << endl;
     cout << "\t\t\t\t\t Choice: "; cin >> choice;
     switch(choice)
     {
         case 1: playGame();
             break;
         case 2:
             system("cls");
             cout << "\n \t\t\t\t How to Play:" << endl;
             cout << "\t\t\t\t-------------\n" << endl;
             cout << "\tTower of Hanoi consists of three towers with n integers placed one over the other. " << endl;
             cout << "\tThe objective of the puzzle is to move the numbers to the third tower using the following rules:" << endl;
             cout << "\t1.	Only one number can be moved at a time" << endl;
             cout << "\t2.	No larger number can be placed on top of smaller number" << endl;
             cout << "\t3.	Minimum numbers of moves for n numbers= 2^n -1." << endl;
             cout << "\t4.      Maximum moves allowed is minimum moves + total rings." << endl;
             retrial();//goes to main
             break;
         case 3:
            system("cls");
            cout << "\n\tDevelopers: " << endl;
            cout << "\n\t\tName               ID" << endl;
            cout << "\t1. Natan Mekebib      ETS 1029/12" << endl;
            cout << "\n\n\tInstructor: Abdurahman" << endl;
            retrial(); // goes to main
            break;
         default:
            cout << "Invalid choice!" << endl;
            retrial();

     }


}
void retrial()
{
    char choice;
    cout << "\n\tDo you want to go back to the main menu?(Y/N)" << endl;
    cout << "\tChoice: "; cin >> choice;
    if (tolower(choice) == 'y'){
        size1 = 0;
        size2 = 0;
        size3 = 0;
        makeEmpty(1);
        makeEmpty(2);
        makeEmpty(3);
        main();
    }
    else
        cout << "\n\tHave a nice day!" << endl;
        exit(0);
}

