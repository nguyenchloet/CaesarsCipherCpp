#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, int s) {
   string result = "";
   char ch;
      for(int i = 0; i < text.length(); i++) {
         ch = text[i];
         int c = ch;
         //encrypt for lowercase letter
         if (islower(ch)) {
            //result += char(int(text[i]+s-97)%26+97)
            int a = 'a';
            int c_index = c - a;
            //shift
            int new_index = (c_index + s) % 26;
            //convert to new char
            int new_unicode = new_index + a;
            char new_char = char(new_unicode);
            result += new_char; 
         }    
         //encrypt for uppercase letter
         else if (isupper(ch)) {
            //result += char(int(text[i]+s-65)%26+65);
            int a = 'A';
            int c_index = c - a;
            //shift
            int new_index = (c_index + s) % 26;
            //convert to new char
            int new_unicode = new_index + a;
            char new_char = char(new_unicode);
            result += new_char; 
         }
         // encrypt for number
         else if (isdigit(text[i])) {
            //result +=  char(int(text[i]+s-45)%10+45);
            int a = '0';
            int c_index = c - a;
            //shift
            int new_index = (c_index + s) % 10;
            //convert to new char
            int new_unicode = new_index + a;
            char new_char = char(new_unicode);
            result += new_char; 
         }
         // else if not a number or letter, add as is
         else {
            result += ch;
         }
      }
   return result;
}

string decrypt(string etext, int s) {
   string result = "";
   char ch;
      for(int i = 0; i < etext.length(); i++) {
         ch = etext[i];
         int c = ch;
         //encrypt for lowercase letter
         if (islower(ch)) {
            int z = 'z';
            int c_index = z - c;
            //shift
            int new_index = (c_index + s) % 26;
            //convert to new char
            int new_unicode = z - new_index;
            char new_char = char(new_unicode);
            result += new_char; 
         }    
         //encrypt for uppercase letter
         else if (isupper(ch)) {
            int z = 'Z';
            int c_index = z - c;
            //shift
            int new_index = (c_index + s) % 26;
            //convert to new char
            int new_unicode = z - new_index;
            char new_char = char(new_unicode);
            result += new_char; 
         }
         // encrypt for number
         else if (isdigit(etext[i])) {
            int z = '9';
            int c_index = z - c;
            //shift
            int new_index = (c_index + s) % 10;
            //convert to new char
            int new_unicode = z - new_index;
            char new_char = char(new_unicode);
            result += new_char; 
         }
         // else if not a number or letter, add as is
         else {
            result += ch;
         }
      }
   return result;
}

void brute_force(string text) {
   string attempt = "";
   char ch;
   int x = 0;
   cout << "Brute Force ------->" << endl;
   while (x < 26) {
      x++;
      for(int i = 0; i < text.length(); i++) {
         ch = text[i];
         int c = ch;
         //encrypt for lowercase letter
         if (islower(ch)) {
            int a = 'a';
            int c_index = c - a;
            //shift
            int new_index = (c_index + x) % 26;
            //convert to new char
            int new_unicode = new_index + a;
            char new_char = char(new_unicode);
            attempt += new_char; 
         }    
         //encrypt for uppercase letter
         else if (isupper(ch)) {
            int a = 'A';
            int c_index = c - a;
            //shift
            int new_index = (c_index + x) % 26;
            //convert to new char
            int new_unicode = new_index + a;
            char new_char = char(new_unicode);
            attempt += new_char; 
         }
         // encrypt for number
         else if (isdigit(text[i])) {
            int a = '0';
            int c_index = c - a;
            //shift
            int new_index = (c_index + x + 4) % 10;
            //convert to new char
            int new_unicode = new_index + a;
            char new_char = char(new_unicode);
            attempt+= new_char; 
         }
         // else if not a number or letter, add as is
         else {
            attempt += ch;
         }
      }
      attempt += "\n";
   }
   cout << attempt << endl;
}


int main() {
   string plain_text;
   string encrypted_text = "";
   int shift;
   char prompt;

   //take the message as input
   cout<<"\nEnter a message to encrypt: ";
   // issues accepting spaces with cin, thus using getline
   getline(cin, plain_text);

   //take the shift as input
   cout << "Enter shift: ";
   cin >> shift; 
   
   encrypted_text = encrypt(plain_text, shift);

   cout << "\nEncrypted: " << encrypted_text << endl;
   cout << "\nDecrypted: " << decrypt(encrypted_text, shift) << endl;

   cout << "\nPress y to get all possible solutions or any key to exit: ";
   cin >> prompt;

   if (prompt == 'y' || prompt == 'Y') {
      brute_force(encrypted_text);
   }

}
