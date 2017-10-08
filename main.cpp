//_________________________________________________________________________//
//This Small application helps in Caesar Cipher Encryption and Decryption
//It was written by Abdulaziz Saad
//For any suggestion, don't hesitate to contact me on xreinheitx@gmail.com
//_________________________________________________________________________//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void Mapping (char [26]);
int  Mapping_Reuest(char [26],char);
void Reverse_Mapping(char [26]);
char Reverse_Mapping_Request(char[26],int);
void Caesar_Encryption(char [26]);
void Caesar_Decryption(char [26]);

int main()
{
    cout << "-----------|) This Small Application Is written by Abdulaziz Saad (|-----------"<< endl << endl;
    cout << "----------------------|) It Helps Us With Dealing With (|----------------------"<< endl << endl;
    cout << "------------------------------|) Caesar Cipher (|------------------------------"<< endl << endl;
    cout << "--|) Feel Free to Contact Me If You Found Any Bugs at xreinheitx@gmail.com (|--"<< endl << endl;
    cout << "-------------------------------------------------------------------------------"<< endl;

    //ـــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــ//

    char Alphapetic [26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    //ـــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــ//

    Start:
    cout << "Select one of these Operation : " << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "1 - Mapping." << endl;
    cout << "2 - Reverse Mapping."<< endl;
    cout << "3 - Encryption." << endl;
    cout << "4 - Decryption." << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    //ـــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــ//

    int Selection;
    cout << "YR Selection Is : ";
    cin  >> Selection;
    cout << "-------------------------------------------------------------------------------" << endl;

    //ـــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــ//

    switch (Selection)
    {
        case 1 : Mapping(Alphapetic);
                 cout << "-------------------------------------------------------------------------------" << endl;
                 break;
        case 2 : Reverse_Mapping(Alphapetic);
                 cout << "-------------------------------------------------------------------------------" << endl;
                 break;
        case 3 : Caesar_Encryption(Alphapetic);
                 cout << "-------------------------------------------------------------------------------" << endl;
                 break;
        case 4 : Caesar_Decryption(Alphapetic);
                 cout << "-------------------------------------------------------------------------------" << endl;
                 break;
    }
    cout << "                              1 - Continue." << endl;
    cout << "                              2 - Quit." << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "Enter Your Decision : ";
    int Decision;
    cin  >> Decision;
    if(Decision == 1)
    {
        system("CLS");
        goto Start;
    }
    else
    {
        return 0;
    }
    //ـــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــ//

}
void Mapping (char Alphapetic [26])
{
    system("CLS");
    char charachter;
    cout << "Alright, I can help you in Character_To_Number mapping" << endl;
    Again:
    cout << endl << "If u don't mind type the character : ";
    cin  >> charachter;
    for(int i = 0 ; i < 25 ; i++)
    {

        if(Alphapetic[i] == charachter)
        cout << endl << "The Number associated with ( " << charachter << " ) is : " << i << endl << endl;
    }
    cout << "Want to Continue ( Y / N ) : ";
    cin  >> charachter;
    if (charachter == 'Y' || charachter == 'y')
        goto Again;
}
void Reverse_Mapping(char Alphapetic [26])
{
    system("CLS");
    int Value;
    cout << "Alright, I can help you in Number_To_Character mapping" << endl;
    Again:
    cout << endl << "If u don't mind type the Number: ";
    cin  >> Value;
    for(int i = 0 ; i < 25 ; i++)
    {
        if(Value == i)
        {
             cout << endl << "The Character Associated with ( " << Value << " ) is : " << Alphapetic[i] << endl << endl;
        }
    }
}
int  Mapping_Reuest(char Alphapetic[26],char character)
{
    for(int i = 0 ; i < 25 ; i++)
    {
        if(Alphapetic[i] == character)
        {
            return i;
        }
    }
}
char Reverse_Mapping_Request(char Alphapetic [26],int Value)
{
    for(int i = 0 ; i < 25 ; i++)
    {
        if(Value == i)
        {
            return Alphapetic[Value];
        }
    }
}
void Caesar_Encryption(char Alphapetic [26])
{
    system("CLS");
    cout << "Enter The Plain Text : ";
    string Plain_Text;
    cin  >> Plain_Text;
    cout << "Enter The Key : ";
    int Key;
    cin  >> Key;
    cout << "The Length of the Plain Text is ( " << Plain_Text.size() <<" )" <<endl;
    int Mapped_String [Plain_Text.size()];
    string::const_iterator char_in_String;
    /*
    cout << "The Encrypted Text is : ";
    for(char_in_String=Plain_Text.begin(); char_in_String!=Plain_Text.end() ; char_in_String++)
    {
        cout << *char_in_String;
    }
    cout <<endl;
    */
    int Index = 0;
    for(char_in_String=Plain_Text.begin(); char_in_String!=Plain_Text.end() ; char_in_String++)
    {
        //cout << "'" << *char_in_String << "' Is Mapped to : " << Mapping_Reuest(Alphapetic,*char_in_String) << endl;
        Mapped_String[Index] = Mapping_Reuest(Alphapetic,*char_in_String);
        Index++;
    }
    for(int i = 0 ; i < Plain_Text.size(); i++)
    {
        cout << Mapped_String[i] <<" ";
    }
    cout << endl;
    for(int i = 0 ; i < Plain_Text.size() ; i++)
    {
        Mapped_String[i]=(Mapped_String[i]+Key)%26;
    }
    for(int i = 0 ; i < Plain_Text.size(); i++)
    {
        cout << Mapped_String[i] <<" ";
    }
    cout << endl;
    char Encrypted_Text[Plain_Text.size()];
    for(int i = 0 ; i < Plain_Text.size(); i++)
    {
        Encrypted_Text[i]=Reverse_Mapping_Request(Alphapetic,Mapped_String[i]);
    }
    cout << "The Encrypted Text is : ";
    for(int i = 0 ; i < Plain_Text.size(); i++)
    {
        cout << Encrypted_Text[i];
    }
    cout <<endl;
}
void Caesar_Decryption(char Alphapetic [26])
{
    system("CLS");
    cout << "Enter The Encrypted Text : ";
    string Ciphered_Text;
    cin  >> Ciphered_Text;
    cout << "Enter The Key : ";
    int Key;
    cin  >> Key;
    cout << "The Length of the Cipher Text is ( " << Ciphered_Text.size() <<" )" <<endl;
    int Mapped_String [Ciphered_Text.size()];
    string::const_iterator char_in_String;
    /*
    cout << "The Ciphered Text is : ";
    for(char_in_String=Ciphered_Text.begin(); char_in_String!=Ciphered_Text.end() ; char_in_String++)
    {
        cout << *char_in_String;
    }
    cout << endl;
    */
    int Index = 0;
    for(char_in_String=Ciphered_Text.begin(); char_in_String!=Ciphered_Text.end() ; char_in_String++)
    {
        // cout << "'" << *char_in_String << "' Is Mapped to : " << Mapping_Reuest(Alphapetic,*char_in_String) << endl;
        Mapped_String[Index] = Mapping_Reuest(Alphapetic,*char_in_String);
        Index++;
    }
    for(int i = 0 ; i < Ciphered_Text.size() ; i++)
    {
        Mapped_String[i]=(Mapped_String[i]-Key)%26;
    }
    for(int i = 0 ; i < Ciphered_Text.size(); i++)
    {
        if (Mapped_String[i]<0)
        {
            Mapped_String[i]=Mapped_String[i]+26;
        }
    }
    cout << endl;
    char Decrypted_Text[Ciphered_Text.size()];
    for(int i = 0 ; i < Ciphered_Text.size(); i++)
    {
        Decrypted_Text[i]=Reverse_Mapping_Request(Alphapetic,Mapped_String[i]);
    }
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "The Plain Text is : ";
    for(int i = 0 ; i < Ciphered_Text.size(); i++)
    {
        cout << Decrypted_Text[i];
    }
    cout <<endl<<endl;
}
