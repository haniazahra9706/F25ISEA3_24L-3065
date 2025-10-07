//#include <iostream>
//#include <fstream>
//#include <ctime>
//#include <conio.h>
//using namespace std;
//
//const int MAX_WORDS = 100;
//const int MAX_WORD_LEN = 50;
//
//int isAlpha(char ch)
//{
//    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
//}
//
//char toLower(char ch)
//{
//    if (ch >= 'A' && ch <= 'Z')
//    {
//        return ch + 32;
//    }
//    return ch;
//}
//
//int strLen(const char* str)
//{
//    int len = 0;
//    while (str[len] != '\0')
//    {
//        len++;
//    }
//    return len;
//}
//
//int loadWords(char words[][MAX_WORD_LEN], int maxWords)
//{
//    ifstream file("24L-3065 Q2.txt");
//    if (!file)
//    {
//        cout << "error: could not open '24L-3065 Q2.txt'" << endl;
//        return 0;
//    }
//
//    int count = 0;
//    char buffer[MAX_WORD_LEN];
//    while (count < maxWords && file >> buffer)
//    {
//        int i = 0;
//        while (buffer[i] && i < MAX_WORD_LEN - 1)
//        {
//            words[count][i] = buffer[i];
//            i++;
//        }
//        words[count][i] = '\0';
//        count++;
//    }
//    file.close();
//    return count;
//}
//
//void displayWord(const char* word, const int* guessed, int wordLength, int remainingMistakes)
//{
//    system("cls");
//    cout << "============= Hangman Game =============" << endl << endl;
//    cout << "You are allowed to make " << remainingMistakes << " mistakes." << endl << endl;
//    cout << "Guess the word below:" << endl;
//
//    int boxWidth = wordLength * 2 + 4;
//
//    cout << "\xDA";
//    for (int i = 0; i < boxWidth - 2; i++)
//    {
//        cout << "\xC4";
//    }
//    cout << "\xBF" << endl;
//
//    cout << "\xB3 ";
//    for (int i = 0; i < wordLength; i++)
//    {
//        if (guessed[i])
//        {
//            cout << word[i] << " ";
//        }
//        else
//        {
//            cout << "_ ";
//        }
//    }
//    cout << " \xB3" << endl;
//
//    cout << "\xC0";
//    for (int i = 0; i < boxWidth - 2; i++)
//    {
//        cout << "\xC4";
//    }
//    cout << "\xD9" << endl;
//}
//
//int main()
//{
//    srand(time(0));
//
//    char words[MAX_WORDS][MAX_WORD_LEN];
//    int totalWords = loadWords(words, MAX_WORDS);
//
//    if (totalWords == 0)
//    {
//        cout << "no words found. please check '24L-3065 Q2.txt'" << endl;
//        return 0;
//    }
//
//    char* word = words[rand() % totalWords];
//    int wordLength = strLen(word);
//
//    int guessed[MAX_WORD_LEN] = { 0 };
//    int remainingMistakes = 7;
//    int correctCount = 0;
//
//    while (remainingMistakes > 0 && correctCount < wordLength)
//    {
//        displayWord(word, guessed, wordLength, remainingMistakes);
//
//        cout << endl << "enter a letter: ";
//        char guess = toLower(_getch());
//        cout << guess << endl;
//
//        if (!isAlpha(guess)) {
//            cout << "please enter a single letter." << endl;
//            cout << endl << "press any key to continue...";
//            _getch();
//            continue;
//        }
//
//        int alreadyguessed = 0;
//        for (int i = 0; i < wordLength; i++)
//        {
//            if (guessed[i] && toLower(word[i]) == guess)
//            {
//                alreadyguessed = 1;
//                break;
//            }
//        }
//
//        if (alreadyguessed)
//        {
//            cout << "you already guessed that letter!" << endl;
//            cout << endl << "press any key to continue...";
//            _getch();
//            continue;
//        }
//
//        int found = 0;
//        for (int i = 0; i < wordLength; i++)
//        {
//            if (toLower(word[i]) == guess && !guessed[i])
//            {
//                guessed[i] = 1;
//                correctCount++;
//                found = 1;
//            }
//        }
//
//        if (!found)
//        {
//            remainingMistakes--;
//            cout << "incorrect guess! remaining mistakes: " << remainingMistakes << endl;
//        }
//        else
//        {
//            cout << "correct guess!" << endl;
//        }
//
//        cout << endl << "press any key to continue...";
//        _getch();
//    }
//
//    displayWord(word, guessed, wordLength, remainingMistakes);
//
//    if (correctCount == wordLength)
//    {
//        cout << "you won! the word was: " << word << endl;
//    }
//    else
//    {
//        cout << "you lose! the word was: " << word << endl;
//    }
//
//    cout << endl << "press any key to exit...";
//    _getch();
//
//    return 0;
//}