#include<iostream>
#include<fstream> //for file handling
using namespace std;

class info
{
    string Name,Email,Password,a,b,c;
    string searchName,searchPass,searchEmail;
    fstream file;
    
    public:
        void login();
        void SignUp();
        void forgot();
}obj;


// SignUp logic start Here
void info :: SignUp()
{

    getline(cin,a);
    cout<<"\n Enter Your User Name:";
    getline(cin,Name);

    cout<<"\n Enter Your Email Adderss:";
    getline(cin,Email);

    cout<<"\n Enter Your Password:";
    getline(cin,Password);

    file.open("loginData.txt",ios :: out | ios :: app);
    file<<Name<<"*"<<Email<<"*"<<Password<<endl;
    file.close();

}



// login Logic start here
void info :: login()
{
    

    cout<<"-------------------LOGIN------------------"<<endl;
    getline(cin,b);
    cout<<"Enter Your User name:";
    getline(cin, searchName);

    cout<<"Enter Your User Password:";
    getline(cin, searchPass);


    file.open("loginData.txt",ios :: in); //Creating file
    getline(file,Name,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');
    while(!file.eof())
    {
        if(Name==searchName)
        {
            if(Password==searchPass)
            {
                cout<<"\nAccount Login Successfull.....!"<<endl;
                cout<<"\nUserName:"<<Name;
                cout<<"\nEmail:"<<Email;
            }
            
        }
        else
            {
                cout<<"Password is Incorrect......!!";
            }
        getline(file,Name,'*');
        getline(file,Email,'*');
        getline(file,Password,'\n');

    }
    file.close();
}

//Forgot logic starts From here 

void info::forgot() {
    getline(cin, c);
    cout << "\nEnter Your UserName:";
    getline(cin, searchName);
    cout << "\nEnter Your Email address:";
    getline(cin, searchEmail);

    file.open("loginData.txt", ios::in);
    getline(file, Name, '*');
    getline(file, Email, '*');
    getline(file, Password, '\n');

    while (!file.eof()) {
        if (Name == searchName) {
            if (Email == searchEmail) {
                cout << "Account Found..!!" << endl;
                cout << "Your Password:" << Password << endl;
                file.close(); // Close the file after finding the account
                return; // Exit the function as the account is found
            }
        }
        // Read next set of data for the next iteration
        getline(file, Name, '*');
        getline(file, Email, '!');
        getline(file, Password, '\n');
    }

    // If the loop completes without finding the account
    cout << "\nAccount Not found...!!" << endl;
    file.close(); // Close the file here if account is not found
}





int main()
{
    char choice;
    // ofstream file;
    cout<<"\n 1.Login";
    cout<<"\n 2.Sign-Up";
    cout<<"\n 3.Forgot Password";
    cout<<"\n 4.Exit";

    cout<<"\nEnter Your choice:";
    cin>>choice;

    switch(choice)
    {
        case '1':
                obj.login();
        break;

        case '2':
                obj.SignUp();
                break;

        case '3':
                obj.forgot();
                break;

        case '4':
                return 0;
                break;

        default:
            cout<<"Envalid Choice!!"<<endl;
    }   
}