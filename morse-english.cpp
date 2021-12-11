#include <iostream>
#include <fstream>
#include <string.h>
using std::ifstream;
using std::ofstream;
using std::cout;

void englishToMorse(ifstream&, ofstream&);
void morseToEnglish(ifstream&, ofstream&);

int main(int argc, char** argv) {
  if (argc != 4) { //check for correct argument count
    printf("INVALID ARGUMENT COUNT\nSyntax: <exe> <input file> <-mc|-e> <output file>");
    return 0;
  } else if ((!strcmp( argv[2], "-mc" )==0) && (!strcmp( argv[2], "-e" )==0)) { //check for correct argument -e or -mc only
    printf("INVALID ARGUMENTS\nSyntax: <exe> <input file> <-mc|-e> <output file>");
    return 0;
  } else { 
    //create i/o fstream from line args
    ofstream outFile (argv[3]);
    ifstream inFile (argv[1]);
    //check if file was open and read successfully
    if (inFile.is_open()) {
      //call appropriate function for outputing transcription
      if (strcmp( argv[2], "-mc" )==0) {
	englishToMorse(inFile, outFile);
      } else if (strcmp( argv[2], "-e" )==0) {
        morseToEnglish(inFile, outFile);                                                                                               
      }
    } else {
      cout << "Couldn't open input file";
      return 0;
    }
  }
  return 0;
}

//pass by reference iofstream to translate from english to morse
void englishToMorse(ifstream& inFile, ofstream& outFile) {
  //loop through each line in inFile
  for (char lineString[256]; inFile.getline(lineString, 256); ) {
    //loop through each char in line
    for (int i = 0; i < (int)strlen(lineString); i++) {
      //the if else block begins:(
      //checking each char for english letter, upper or lowercase, then outputting appropriate morse code
      if (lineString[i] == ' ') {
	outFile << "/" << "|";
      }else if (lineString[i] == 'A' || lineString[i] == 'a'){
	outFile << ".-" << "|";
      }else if (lineString[i] == 'B' || lineString[i] == 'b'){
	outFile << "-..." << "|";
      }else if (lineString[i] == 'C' || lineString[i] == 'c'){
	outFile << "-.-." << "|";
      }else if (lineString[i] == 'D' || lineString[i] == 'd'){
	outFile << "-.." << "|";
      }else if (lineString[i] == 'E' || lineString[i] == 'e'){
	outFile << "." << "|";
      }else if (lineString[i] == 'F' || lineString[i] == 'f'){
	outFile << "..-." << "|";
      }else if (lineString[i] == 'G' || lineString[i] == 'g'){
	outFile << "--." << "|";
      }else if (lineString[i] == 'H' || lineString[i] == 'h'){
	outFile << "...." << "|";
      }else if (lineString[i] == 'I' || lineString[i] == 'i'){
	outFile << ".." << "|";
      }else if (lineString[i] == 'J' || lineString[i] == 'j'){
	outFile << ".---" << "|";
      }else if (lineString[i] == 'K' || lineString[i] == 'k'){
	outFile << "-.-" << "|";
      }else if (lineString[i] == 'L' || lineString[i] == 'l'){
	outFile << ".-.." << "|";
      }else if (lineString[i] == 'M' || lineString[i] == 'm'){
	outFile << "--" << "|";
      }else if (lineString[i] == 'N' || lineString[i] == 'n'){
	outFile << "-." << "|";
      }else if (lineString[i] == 'O' || lineString[i] == 'o'){
	outFile << "---" << "|";
      }else if (lineString[i] == 'P' || lineString[i] == 'p'){
	outFile << ".--." << "|";
      }else if (lineString[i] == 'Q' || lineString[i] == 'q'){
	outFile << "--.-" << "|";
      }else if (lineString[i] == 'R' || lineString[i] == 'r'){
	outFile << ".-." << "|";
      }else if (lineString[i] == 'S' || lineString[i] == 's'){
	outFile << "..." << "|";
      }else if (lineString[i] == 'T' || lineString[i] == 't'){
	outFile << "-" << "|";
      }else if (lineString[i] == 'U' || lineString[i] == 'u'){
	outFile << "..-" << "|";
      }else if (lineString[i] == 'V' || lineString[i] == 'v'){
	outFile << "...-" << "|";
      }else if (lineString[i] == 'W' || lineString[i] == 'w'){
	outFile << ".--" << "|";
      }else if (lineString[i] == 'X' || lineString[i] == 'x'){
	outFile << "-..-" << "|";
      }else if (lineString[i] == 'Y' || lineString[i] == 'y'){
	outFile << "-.--" << "|";
      }else if (lineString[i] == 'Z' || lineString[i] == 'z'){
	outFile << "--.." << "|";
      } else if (lineString[i] == ' '){
	outFile << " ";
      } else {
	outFile << "eeee" << "|";
      }
    }
    //creating new line in output file after every line is checked
    outFile << "\n";
  }  
}

//pass by reference iofstream to translate from english to morse   
void morseToEnglish(ifstream& inFile, ofstream& outFile) {
  //letterString and counter will be used in scope of function to determine where morse char are located
  char letterString[4];
  int counter =0;
  //loop through each line in input file
  for (char lineString[256]; inFile.getline(lineString, 256); ) {
    //loop through each char in line
    for (int i = 0; i < (int)strlen(lineString); i++) {
      //at beginning of line, letterString is set to ['x','x','x','x']
      if (i == 0) {
	letterString[0] = 'x';
        letterString[1] = 'x';
        letterString[2] = 'x';
        letterString[3] = 'x';
      }
      //if char is '/' output a space
      if (lineString[i] == '/') {
        outFile << " ";
      }else if (lineString[i] == '|') {
	//if char is '|', this means one letter has passed and we can check which morse code matches and output result
	if (letterString[0] == '.' && letterString[1] == '-' &&letterString[2] == 'x' &&letterString[3] == 'x') {
          outFile << "A";
        }else if (letterString[0] == '-' && letterString[1] == '.' &&letterString[2] == '.' &&letterString[3] == '.') {
	  outFile << "B";
	}else if (letterString[0] == '-' && letterString[1] == '.' &&letterString[2] == '-' &&letterString[3] == '.') {
          outFile << "C";
	}else if (letterString[0] == '-' && letterString[1] == '.' &&letterString[2] == '.' &&letterString[3] == 'x') {
          outFile << "D";
	}else if (letterString[0] == '.' && letterString[1] == 'x' &&letterString[2] == 'x' &&letterString[3] == 'x') {
          outFile << "E";
	}else if (letterString[0] == '.' && letterString[1] == '.' &&letterString[2] == '-' &&letterString[3] == '.') {
          outFile << "F";
	}else if (letterString[0] == '-' && letterString[1] == '-' &&letterString[2] == '.' &&letterString[3] == 'x') {
          outFile << "G";
	}else if (letterString[0] == '.' && letterString[1] == '.' &&letterString[2] == '.' &&letterString[3] == '.') {
          outFile << "H";
	}else if (letterString[0] == '.' && letterString[1] == '.' &&letterString[2] == 'x' &&letterString[3] == 'x') {
          outFile << "I";
	}else if (letterString[0] == '.' && letterString[1] == '-' &&letterString[2] == '-' &&letterString[3] == '-') {
          outFile << "J";
	}else if (letterString[0] == '-' && letterString[1] == '.' &&letterString[2] == '-' &&letterString[3] == 'x') {
          outFile << "K";
	}else if (letterString[0] == '.' && letterString[1] == '-' &&letterString[2] == '.' &&letterString[3] == '.') {
          outFile << "L";
	}else if (letterString[0] == '-' && letterString[1] == '-' &&letterString[2] == 'x' &&letterString[3] == 'x') {
          outFile << "M";
	}else if (letterString[0] == '-' && letterString[1] == '.' &&letterString[2] == 'x' &&letterString[3] == 'x') {
          outFile << "N";
	}else if (letterString[0] == '-' && letterString[1] == '-' &&letterString[2] == '-' &&letterString[3] == 'x') {
          outFile << "O";
	}else if (letterString[0] == '.' && letterString[1] == '-' &&letterString[2] == '-' &&letterString[3] == '.') {
          outFile << "P";
	}else if (letterString[0] == '-' && letterString[1] == '-' &&letterString[2] == '.' &&letterString[3] == '-') {
          outFile << "Q";
	}else if (letterString[0] == '.' && letterString[1] == '-' &&letterString[2] == '.' &&letterString[3] == 'x') {
          outFile << "R";
	}else if (letterString[0] == '.' && letterString[1] == '.' &&letterString[2] == '.' &&letterString[3] == 'x') {
          outFile << "S";
	}else if (letterString[0] == '-' && letterString[1] == 'x' &&letterString[2] == 'x' &&letterString[3] == 'x') {
          outFile << "T";
	}else if (letterString[0] == '.' && letterString[1] == '.' &&letterString[2] == '-' &&letterString[3] == 'x') {
          outFile << "U";
	}else if (letterString[0] == '.' && letterString[1] == '.' &&letterString[2] == '.' &&letterString[3] == '-') {
          outFile << "V";
	}else if (letterString[0] == '.' && letterString[1] == '-' &&letterString[2] == '-' &&letterString[3] == 'x') {
          outFile << "W";
	}else if (letterString[0] == '-' && letterString[1] == '.' &&letterString[2] == '.' &&letterString[3] == '-') {
          outFile << "X";
	}else if (letterString[0] == '-' && letterString[1] == '.' &&letterString[2] == '-' &&letterString[3] == '-') {
          outFile << "Y";
	}else if (letterString[0] == '-' && letterString[1] == '-' &&letterString[2] == '.' &&letterString[3] == '.') {
          outFile << "Z";
	}else if (letterString[0] == 'e' && letterString[1] == 'e' &&letterString[2] == 'e' &&letterString[3] == 'e') {
          outFile << "#";
	}
	//after letter is output to file reset counter and letterString[]
        counter = 0;
        letterString[0] = 'x';
        letterString[1] = 'x';
	letterString[2] = 'x';
	letterString[3] = 'x';
      }else if (lineString[i] != ' ') {
	//if char is not ' ' or '/' or '|', this means char is a morse code char and it is added to lineString and counter increased
	letterString[counter] =lineString[i];
        counter++;
      }
    }
    //new line output after prev line
    outFile << "\n";
  }
}


