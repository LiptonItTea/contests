#include <iostream>

using namespace std;

int countDigits(long long num){
    int counter = 0;
    while(num > 0){
        num /= 10ll;
        counter++;
    }

    return counter;
}

long long reverse(long long num){
    long long newNum = 0;
    int digit = countDigits(num) - 1;
    
    while(num > 0){
        long long cipher = num % 10;
        for (int i = 0; i < digit; i++){
            cipher *= 10ll;
        }

        newNum += cipher;
        num /= 10ll;
        digit--;
    }

    return newNum;
}

bool checkPalindrome(long long num){
    long long revNum = reverse(num);

    while(num > 0){
        int cipher1 = num % 10;
        int cipher2 = revNum % 10;

        if(cipher1 != cipher2)
            return false;

        num /= 10ll;
        revNum /= 10ll;
    }

    return true;
}

int main(){
    long long n;
    cin >> n;

    long long currNum = n;
    for (int i = 0; i < 100000; i++){
        if(currNum < 0){
            break;
        }
        
        bool pal = checkPalindrome(currNum);

        if(pal){
            cout << currNum;
            return 0;
        }

        currNum += reverse(currNum);
    }

    cout << -1;
    
}