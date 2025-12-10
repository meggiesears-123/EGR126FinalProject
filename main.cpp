/******************************************************************************

*******************************************************************************/
#include <iostream>
using namespace std;

struct Letters{ 
    string shownChar;
    string realChar; 
    bool guessed; 
};

bool isGameDone (Letters phrase [15]);
bool didTheyGuessRight(string guess);

string allLetters[26] = {" a"," b"," c"," d"," e"," f"," g"," h"," i"," j"," k"," l"," m"," n"," o"," p"," q"," r"," s"," t"," u"," v"," w"," x"," y"," z"}; 
string guessedLetters[26] = {" #", " #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #",};
string printGuessedLetter = "";  


int main()
{
    string guess = " "; 
    bool gameFinished = false;
    bool didTheyWin = false;
    
    //Hard coding phrase
    Letters phrase [15];
    phrase[0] = {"*", "c" , false};
    phrase[1] = {"*", "o" , false};
    phrase[2] = {"*", "d" , false};
    phrase[3] = {"*", "i" , false};
    phrase[4] = {"*", "n" , false};
    phrase[5] = {"*", "g" , false};
    phrase[6] = {" ", " " , false};
    phrase[7] = {"*", "i" , false};
    phrase[8] = {"*", "s" , false};
    phrase[9] = {" ", " " , false};
    phrase[10] = {"*", "g" , false};
    phrase[11] = {"*", "r" , false};
    phrase[12] = {"*", "e" , false};
    phrase[13] = {"*", "a" , false};
    phrase[14] = {"*", "t" , false};
  
    
    // Printing initial display  
    cout << "INPUT A LETTER TO BEGIN PLAYING. YOU HAVE 16 GUESSES!" << endl;
    
    cout << "---------------------------------" << endl << "|   | ";
    for (int i = 0; i < 7; i++){
        cout << phrase[i].shownChar << " | "; 
    }
    cout << endl << "---------------------------------" << endl << "| ";
    for (int i = 7; i < 15; i++){
        cout << phrase[i].shownChar << " | "; 
    }
    cout << endl << "---------------------------------" << endl;
    
    cout << "Avalible Letters:" ;
    for (int i = 0; i < 26; i++){
        cout << allLetters[i];
    }

    // game loop
    while (gameFinished == false){ 
        
     int gameLength = 16;
     
        for (int i = 0; i < gameLength; i++){ 
           
            // cin-ing guess
            cout << endl << "Letter guess: "; 
            cin >> guess; 
            cout << endl;
            
         //Finding and changing matching letters
            for (int i = 0; i < 15; i++){
            if (guess == phrase[i].realChar){
                    phrase[i].shownChar = phrase[i].realChar;
                }
            }
            
            //Saving guessed letters
            guess = " " + guess;
            
            for ( int i = 0; i < 26; i++){
               
                if (guess == allLetters[i]){
                    
                    cout << "Good Guess! " << endl;
                    guessedLetters[i] = allLetters[i];
                    allLetters[i] = " #";
                }
            }
            
            //Provide feedback 
            bool didTheyGuessRightBool = didTheyGuessRight(guess);
            
            if (didTheyGuessRightBool == true){
                cout << "Good Guess!" << endl;
            }
            
            else cout << "Try again :(" << endl;
            
            //Guesses Left 
            cout << "Guesses Remaining: " << gameLength - i - 1 << endl;
            
            
            //Printing new board 
            cout << "---------------------------------" << endl << "|   | ";
            for (int i = 0; i < 7; i++){
                cout << phrase[i].shownChar << " | "; 
            }
            cout << endl << "---------------------------------" << endl << "| ";
            for (int i = 7; i < 15; i++){
                cout << phrase[i].shownChar << " | "; 
            }
            cout << endl << "---------------------------------" << endl;
            cout << endl;
            
            
            printGuessedLetter += guess;
            cout << "Guessed Letters:" << printGuessedLetter << endl;
            
            cout << "Avalible Letters:";
            for (int i = 0; i < 26; i++){
                
                if (allLetters[i] != " #"){
                    
                    cout << allLetters[i];
                }
            }
            
            gameFinished = isGameDone;
            
            if (gameFinished == true){
                didTheyWin = true;
            }
        }
    }

    if (didTheyWin == false) {
        
        cout << "YOU LOST";
    }

    else cout << "YOU WON";

    return 0;
}

bool didTheyGuessRight(string guess){
    
    Letters phrase [15];
    phrase[0] = {"*", "c" , false};
    phrase[1] = {"*", "o" , false};
    phrase[2] = {"*", "d" , false};
    phrase[3] = {"*", "i" , false};
    phrase[4] = {"*", "n" , false};
    phrase[5] = {"*", "g" , false};
    phrase[6] = {" ", " " , false};
    phrase[7] = {"*", "i" , false};
    phrase[8] = {"*", "s" , false};
    phrase[9] = {" ", " " , false};
    phrase[10] = {"*", "g" , false};
    phrase[11] = {"*", "r" , false};
    phrase[12] = {"*", "e" , false};
    phrase[13] = {"*", "a" , false};
    phrase[14] = {"*", "t" , false};
    
    if (guess == phrase[1].realChar || guess == phrase[2].realChar || guess == phrase[3].realChar || guess == phrase[4].realChar ||
    guess == phrase[5].realChar || guess == phrase[6].realChar || guess == phrase[7].realChar || guess == phrase[8].realChar ||
    guess == phrase[9].realChar || guess == phrase[10].realChar || guess == phrase[11].realChar || guess == phrase[12].realChar || 
    guess == phrase[13].realChar || guess == phrase[14].realChar || guess == phrase[0].realChar){ 
        
        return true;
    }
    
    else return false;
}

bool isGameDone (Letters phrase [15]){
    
    if (phrase[0].realChar == phrase[0].shownChar && phrase[1].realChar == phrase[1].shownChar && phrase[2].realChar == phrase[2].shownChar && 
    phrase[3].realChar == phrase[3].shownChar && phrase[4].realChar == phrase[4].shownChar && phrase[5].realChar == phrase[5].shownChar && 
    phrase[6].realChar == phrase[6].shownChar && phrase[7].realChar == phrase[7].shownChar && phrase[8].realChar == phrase[8].shownChar && 
    phrase[9].realChar == phrase[9].shownChar && phrase[10].realChar == phrase[10].shownChar && phrase[11].realChar == phrase[11].shownChar && 
    phrase[12].realChar == phrase[12].shownChar && phrase[13].realChar == phrase[13].shownChar && phrase[14].realChar == phrase[14].shownChar){
        
        return true;
        
    }
    
    else return false;
}