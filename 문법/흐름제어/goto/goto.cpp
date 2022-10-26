#include <iostream>

using namespace std;

int main(){

    // do {
    //     cout << 1 << endl;
    // } while(true);

    // go:
    //     cout << 1 << endl;

    // goto go;
    

    // int num = 7;
    // do{
    //     if (num % 3 == 0){
    //         cout << "Can divide 3 and 5" << endl;
    //         break;
    //         }
    //     if (num % 5 == 0){
    //         cout << "Can divide 3 and 5" << endl;
    //         break;
    //         }
    //     cout << "Can't divide 3 and 5" << endl;
    // } while(false);

    // if (num % 3 == 0){
        
    //     goto go;}
    // if (num % 5 == 0){
        
    //     goto go;}
    // else {cout << "Can't divide 3 and 5" << endl;}

    // go : {
    //     cout << "Can divide 3 and 5" << endl;}

    // factorial
//     int num;
//     cin >> num;

//     int total = 1;

// multiply: 
//     total *= num;
//     if (--num) {
//         goto multiply;
//     }

//     cout << total << endl;

    // a-z
//     char ch = 'a';

// go: 
//     cout << ch << endl;
//     if (++ch <= 'z'){
//         goto go;
//     }

    // 피보나치

    int num;
    cin >> num;
    if (num <= 1)
        cout << num << endl;

    int prevValue = 0;
    int currValue = 1;

add:{
    int nextValue = prevValue + currValue;
    prevValue = currValue;
    currValue = nextValue;
    if (--num - 1){
        goto add;
    }
    }
    cout << currValue << endl; 
}