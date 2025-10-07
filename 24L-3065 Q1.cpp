//#include <iostream>
//#include <conio.h>
//using namespace std;
//
//bool isAlnum(char c)
//{
//    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
//}
//
//char toLower(char c)
//{
//    if (c >= 'A' && c <= 'Z') 
//    {
//        return c + 32;
//    }
//    return c;
//}
//
//bool isPalindrome(char* s) 
//{
//    char cleaned[1000];
//    int len = 0;
//    for (int i = 0; s[i] != '\0'; i++) 
//    {
//        if (isAlnum(s[i])) 
//        {
//            cleaned[len++] = toLower(s[i]);
//        }
//    }
//    cleaned[len] = '\0';
//
//    for (int i = 0, j = len - 1; i < j; i++, j--) 
//    {
//        if (cleaned[i] != cleaned[j])
//        {
//            return false;
//        }
//    }
//    return true;
//}
//
//int main() 
//{
//    char input[1000];
//
//    cout << "Press ESC to exit..." << endl << endl;
//    while (true)
//    {
//        cout << "Enter a string to check if it's a palindrome: ";
//
//        int i = 0;
//        while (true) 
//        {
//            char c = _getch();
//            if (c == 27)
//            {
//                cout << endl << "Exiting program." << endl;
//                return 0;
//            }
//            if (c == '\r')
//            {
//                input[i] = '\0';
//                cout << endl;
//                break;
//            }
//            if (i < 999)
//            {
//                input[i++] = c;
//                cout << c;
//            }
//        }
//
//        if (isPalindrome(input)) 
//        {
//            cout << "Palindrome" << endl;
//        }
//        else 
//        {
//            cout << "Not Palindrome" << endl;
//        }
//
//        cout << endl;
//    }
//    return 0;
//}