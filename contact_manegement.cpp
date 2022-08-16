/*
CONTACT INFORMATION MANAGEMENT SYSTEM

FUNCTIONALITY
    1.Add a new Contact
    2.List all Contacts
    3.Search for Contact
    4.Edit a Contact
    5.Delete a Contact
    6.Exit

INTRODUCTION
Each element should have 5 data descriptors
    1.Name
    2.Surname
    3.Date of birth
    4.Passport or Id (should not be repeated)
    5.Phone number
    6.Email
*/

#include <iostream>
#include <string>
#include <fstream>

class Database {
	public:
  	     Database() {};
 	     void Add_a_contact();
	     void list_all_contacts();
	     void search_contact();
             void delete_contact();
	     void edit_contact(int);
  	     ~Database() {};
	private:
	    std::string _Name;
	    std::string _Surname;
	    std::string _Date_of_birth;
	    std::string _Passport_or_Id;
	    std::string _Phone_number;
	    std::string _Email;
};

void Database::Add_a_contact() {
    std::cout << " Name: ";
    std::cin >> _Name;
    std::cout << " Surname: ";
    std::cin >> _Surname;
    std::cout << " Date of birth: ";
    std::cin >> _Date_of_birth;
    int num = 0;
    std::cout << " Passpotr or ID: ";
    std::cin >> _Passport_or_Id;

    std::string line;
    std::string pass;
    std::ifstream myfile ("Database.txt");
    if (myfile.is_open()) {
        while (getline (myfile,line)) {
            int i = 0;
            pass = "";
            while (line[i] != ' ') {
                pass += line[i];
                ++i;
            }
            if (pass == _Passport_or_Id) {
                return;
            }
        }
        myfile.close();
    }

    std::cout << " Phone number: ";
    std::cin >> _Phone_number;
    std::cout << " Email ";
    std::cin >> _Email;

    std::ofstream add ("Database.txt", std::ios::app);
    if (add.is_open()) {
        add << _Passport_or_Id << " ";
        add << _Name << " ";
        add << _Surname << " ";
        add << _Date_of_birth << " ";
        add << _Phone_number << " ";
        add << _Email << " ";
        add << "\n";

        add.close ();
    }
    else std::cout << "Unable to open file";
    return;
}


void Database::list_all_contacts() {
    std::string line;
    std::ifstream myfile("Database.txt");
    if (myfile.is_open()) {
        while (getline (myfile,line)) {
            std::cout << line << '\n';
        }
        myfile.close();
    }
    else
        std::cout << "Unable to open file";

    return;
}

void Database::search_contact() {
    std::string passid;
    std::cout << " enter Passport or Id: ";
    std::cin >> passid;
    std::string line;
    std::string pass;
    std::ifstream myfile ("Database.txt");
    if (myfile.is_open()) {
        while (getline (myfile,line)) {
            int i = 0;
            pass = "";
            while (line[i] != ' ') {
                pass += line[i];
                ++i;
            }
            if (passid == pass) {
                std::cout << line << '\n';
            }
        }
        myfile.close();
    }
    else
        std::cout << "Unable to open file";

}

void Database::delete_contact() {
    std::string passid;
    std::cout << " enter Passport or Id: ";
    std::cin >> passid;
    std::string line;
    std::string pass;
    std::ifstream myfile ("Database.txt");
    std::ofstream temp;
    temp.open("temp.txt");
    if (myfile.is_open()) {
        while (getline (myfile,line)) {
            int i = 0;
            pass = "";
            while (line[i] != ' ') {
                pass += line[i];
                ++i;
            }
            if (passid != pass) {
                temp << line << std::endl;
            }
        }
        temp.close();
        myfile.close();
        remove("Database.txt");
        rename("temp.txt","Database.txt");
    }
    else
        std::cout << "Unable to open file";
}

void Database::edit_contact(int n) {
    std::string str;
    std::cin >> str;
    std::string passid;
    std::string line;
    std::string pass;
    std::cout << " enter Passport or Id: ";
    std::cin >> passid;

    std::ifstream myfile ("Database.txt");
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            int i = 0;
            pass = "";
            while (line[i] != ' ') {
                pass += line[i];
                ++i;
            }
            if (passid == pass) {
                _Passport_or_Id = passid;
                while (line[i] == ' ') { ++i; }
                while (line[i] != ' ') {
                    _Name += line[i];
                    ++i;
                }
                while (line[i] == ' ') { ++i; }
                while (line[i] != ' ') {
                    _Surname += line[i];
                    ++i;
                }
                while (line[i] == ' ') { ++i; }
                while (line[i] != ' ') {
                    _Date_of_birth += line[i];
                    ++i;
                }
                while (line[i] == ' ') { ++i; }
                while (line[i] != ' ') {
                    _Phone_number += line[i];
                    ++i;
                }
                while (line[i] == ' ') { ++i; }
                while (line[i] != ' ') {
                    _Email += line[i];
                    ++i;
                }
            }
        }
        myfile.close();
    }
    else
        std::cout << "Unable to open file";

    std::string lin;
    std::ifstream file ("Database.txt");
    std::ofstream temp;
    temp.open("temp.txt");
    if (file.is_open()) {
        while (getline (file,lin)) {
            int i = 0;
            pass = "";
            while (lin[i] != ' ') {
                pass += lin[i];
                ++i;
            }
            if (passid != pass) {
                temp << lin << std::endl;
            }
        }
        temp.close();
        myfile.close();
        remove("Database.txt");
        rename("temp.txt","Database.txt");
    }
    else
        std::cout << "Unable to open file";

    switch(n)
    {
        case 1:
            _Name = str;
            break;
        case 2:
            _Surname = str;
            break;
        case 3:
            _Date_of_birth = str;
            break;
        case 4:
            _Passport_or_Id = str;
            break;
        case 5:
            _Phone_number = str;
            break;
        case 6:
            _Email = str;
            break;
    }
    std::ofstream add ("Database.txt", std::ios::app);
    if (add.is_open()) {
        add << _Passport_or_Id << " ";
        add << _Name << " ";
        add << _Surname << " ";
        add << _Date_of_birth << " ";
        add << _Phone_number << " ";
        add << _Email << " ";
        add << "\n";

        add.close ();
    }
    else std::cout << "Unable to open file";
    return;

}


void Add_a_new_Contact();
void List_all_Contacts();
void Search_for_Contact();
void Edit_a_Contact();
void Delete_a_Contact();

int main() {
    int num;
    do {
        std::cout << " 1.Add a new Contact \n 2.List all Contacts \n 3.Search for Contact \n 4.Edit a Contact \n 5.Delete a Contact \n 6.Exit " << std::endl;
        std::cout << "number: ";
        std::cin >> num;
        switch(num)
        {
            case 1:
                Add_a_new_Contact();
                break;
            case 2:
                List_all_Contacts();
                break;
            case 3:
                Search_for_Contact();
                break;
            case 4:
                Edit_a_Contact();
                break;
            case 5:
                Delete_a_Contact();
                break;
            case 0:
                return 0;
        }
    }while (num != 6 );
}

void Add_a_new_Contact() {
    Database obj;
    obj.Add_a_contact();
}

void List_all_Contacts() {
    Database obj1;
    obj1.list_all_contacts();
}

void Search_for_Contact() {
    Database obj2;
    obj2.search_contact();
}

void Delete_a_Contact() {
    Database obj3;
    obj3.delete_contact();
}

void Edit_a_Contact() {
    Database obj4;

    int num;
    std::cout << " edit \n 1.Name \n 2.Surname \n 3.Date of birth \n 4.Passport or Id \n 5.Phone number \n 6.Email \n 0.exit " << std::endl;
    std::cout << " number: ";
    std::cin >> num;
    switch(num)
    {
        case 1:
            obj4.edit_contact(1);
            break;
        case 2:
            obj4.edit_contact(2);
            break;
        case 3:
            obj4.edit_contact(3);
            break;
        case 4:
            obj4.edit_contact(4);
            break;
        case 5:
            obj4.edit_contact(5);
            ;
            break;
        case 6:
            obj4.edit_contact(6);
            break;
        case 0:
            return;
    }
}
