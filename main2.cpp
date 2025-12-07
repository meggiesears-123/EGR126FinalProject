/******************************************************************************

*******************************************************************************/
#include <iostream>
using namespace std;

struct Letters{ 
    string shownChar;
    string realChar; 
    bool guessed; 
};

//Function to remove what letter are able to be guessed 
string availbeLetters (string allLeters[26], string guessedLetter[26]);

//Function that adds together guessed letter 
string usedLetters(string guessedLetter[26]);

string allLetters[26] = {" a"," b"," c"," d"," e"," f"," g"," h"," i"," j"," k"," l"," m"," n"," o"," p"," q"," r"," s"," t"," u"," v"," w"," x"," y"," z"}; 
string guessedLetters[26] = {" #", " #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #",};
  
int main()
{
    string guess = " "; 
    bool gameFinished = false;
    
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

    while (gameFinished == false){ 
        
     int gameLength = 16;
        for (int i = 0; i < gameLength; i++){ 
            
            cout << "Letter guess: "; 
            cin >> guess; 
            cout << endl;
            
            //Saving guessed letters
            guess = " " + guess;
            
            for ( int i = 0; i < 26; i++){
               
                if (guess == allLetters[i]){
                 
                    allLetters[i] = guessedLetters[i];
                }
            }
            
         //Finding and changing matching letters
            for (int i = 0; i < 15; i++){
            if (guess == phrase[i].realChar){
                    phrase[i].shownChar = phrase[i].realChar;
                }
            }
            
            //Provide feedback 
            if (guess == phrase[1].realChar || guess == phrase[2].realChar || guess == phrase[3].realChar || guess == phrase[4].realChar ||
            guess == phrase[5].realChar || guess == phrase[6].realChar || guess == phrase[7].realChar || guess == phrase[8].realChar ||
            guess == phrase[9].realChar || guess == phrase[10].realChar || guess == phrase[11].realChar || guess == phrase[12].realChar || 
            guess == phrase[13].realChar || guess == phrase[14].realChar || guess == phrase[0].realChar){ 
                
                cout << "Good Guess!" << endl;
            }
            else cout << "Try agian :(" << endl;
            
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
            
            cout << "Guessed Letters:" << usedLetters(guessedLetters[26]) << endl;
            cout << "Avalible Letters:" << availbeLetters (allLetters[26], guessedLetters[26]) << endl;
            
            //Checking to see it game is done
            if (phrase[0].realChar == phrase[0].shownChar && phrase[1].realChar == phrase[1].shownChar && phrase[2].realChar == phrase[2].shownChar && 
            phrase[3].realChar == phrase[3].shownChar && phrase[4].realChar == phrase[4].shownChar && phrase[5].realChar == phrase[5].shownChar && 
            phrase[6].realChar == phrase[6].shownChar && phrase[7].realChar == phrase[7].shownChar && phrase[8].realChar == phrase[8].shownChar && 
            phrase[9].realChar == phrase[9].shownChar && phrase[10].realChar == phrase[10].shownChar && phrase[11].realChar == phrase[11].shownChar && 
            phrase[12].realChar == phrase[12].shownChar && phrase[13].realChar == phrase[13].shownChar && phrase[14].realChar == phrase[14].shownChar){
                
                gameFinished = true;
            }
            
            if (gameFinished = true){
                    cout << "YOU WON!";
                }
        }
        
    }

return 0;
    
}

string availbeLetters (string allLeters[26], string guessedLetter[26]){
    string returnString = " "; 
    
    for (int i = 0; i < 26; i++){ 
        
        if (guessedLetter[i] != allLeters[i]){
            
            returnString += allLeters[i]; 
        }
    }
    
    return returnString;
}


string usedLetters(string guessedLetter[26]){
    string returnString = " ";
    
    for (int i = 0; i < 26; i++){ 
        
        if (guessedLetter[i] != "#"){
            
            returnString += lettersArray[i]; 
        }
    }
    
    return returnString; 
}


