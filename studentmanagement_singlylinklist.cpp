                    /*STUDENT MANAGEMENT SYSTEM USING SINGLY LINKED LIST
						Ninh Thi Linh  */

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<fstream>
#include<ostream>
#include<string.h>
#include<conio.h>
#include <sstream>
using namespace std;
fstream file;
string s[100];

class Admin{
	private:
		int id, phone;
		string address;
		
	public:
		string birth;   //date of birth
		string name, gender;
		string subject_1, subject_2, subject_3;
		float score_1, score_2, score_3, avg;      
		Admin *next_Student;           //next_Studet is a link
	
	public:
		Admin *head = NULL;         

		void Read_file();
		void Insert();
		void Search();
		void Update();
		void Delete();
		void Print();
		void MainMenu();
		void AdminMenu();		
};

//insert at the end
void Admin::Insert(){
	system("cls");
    fstream file;
	int q, j, k;
	cout<<"\n\t******************* STUDENT MANAGEMENT SYSTEM *****************"<<endl;
    cout<<"\t\t************ INSERT STUDENT ************\n";
	cout<<"\t-----------------------------------------------------------------\n";
	cout<<"\t\tHow many students you want to insert?: ";
	cin>>q;
	
	for(j=1; j<=q; j++){
		Admin *new_Student = new Admin;
		cout<<endl<<"\t\t\tStudent's id: ";
		cin>>new_Student -> id;
		cin.ignore();
		cout<<endl<<"\t\t\tStudent's name: ";
		getline(cin, new_Student -> name);
		cout<<endl<<"\t\t\tStudent's gender: ";
		getline(cin, new_Student -> gender);
		cout<<endl<<"\t\t\tStudent's Date of birth: ";
		cin>>new_Student -> birth;
		cin.ignore();
		cout<<endl<<"\t\t\tStudent's phone: ";
		cin>>new_Student -> phone;
		cin.ignore();
		cout<<endl<<"\t\t\tStudent's address: ";
		getline(cin, new_Student -> address);
		
			cout<<endl<<endl<<"\t\t\tSubject 1: ";
			getline(cin, new_Student -> subject_1);
			cout<<endl<<"\t\t\tSubject 2: ";
			getline(cin, new_Student -> subject_2);
			cout<<endl<<"\t\t\tSubject 3: ";
			getline(cin, new_Student -> subject_3);
			cout<<endl<<"\t\t\tScore 1: ";
			cin>>new_Student -> score_1;
			cin.ignore();
			cout<<endl<<"\t\t\tScore 2: ";
			cin>>new_Student -> score_2;
			cin.ignore();
			cout<<endl<<"\t\t\tScore 3: ";
			cin>>new_Student -> score_3;
			cin.ignore();

	new_Student -> next_Student = NULL;
	
		file.open ("datastudent.txt",ios::out | ios::app);
		file<<" "<<new_Student -> id<<" | "<<new_Student -> name<<" | "<<new_Student -> gender<<" | "<<new_Student -> birth<<" | "<<new_Student -> phone<<" | "<<new_Student -> address<<" | "<<new_Student -> subject_1<<" | "<<new_Student -> subject_2<<" | "<<new_Student -> subject_3<<" | "<<new_Student -> score_1<<" | "<<new_Student -> score_2<<" | "<<new_Student -> score_3<<" | "<<((new_Student -> score_1 + new_Student -> score_2+ new_Student -> score_3)/3)<<endl;
		file.close();
	if(head == NULL){
		head = new_Student;
	}else
	{
		Admin *ptr = head;
		while(ptr -> next_Student != NULL){
			ptr = ptr -> next_Student;
		}
		ptr -> next_Student = new_Student;
		
		file.open ("datastudent.txt",ios::out | ios::app);
		file<<" "<<ptr -> id<<" | "<<ptr -> name<<" | "<<ptr -> gender<<" | "<<ptr -> birth<<" | "<<ptr -> phone<<" | "<<ptr -> address<<" | "<<ptr -> subject_1<<" | "<<ptr -> subject_2<<" | "<<ptr -> subject_3<<" | "<<ptr -> score_1<<" | "<<ptr -> score_2<<" | "<<ptr -> score_3<<" | "<<((ptr -> score_1 + ptr -> score_2+ ptr -> score_3)/3)<<endl;
		file.close();
	}
	cout<<endl<<"\t\t\tNew Student Inserted!"<<endl;
	}
}

//Search by student's id
void Admin::Search(){
	system("cls");
    fstream file;
	int s_id;
	int found = 0;
	cout<<"\n\t********************** STUDENT MANAGEMENT SYSTEM ********************"<<endl;
    cout<<"\t\t*************** SEARCH STUDENT **************\n";
	cout<<"\t-----------------------------------------------------------------\n";
	if(head==NULL){
		cout<<endl<<"Link list is empty"<<endl;
	}
	else{
		file.open("datastudent.txt", ios::in);
		cout<<endl<<"Student's id: ";
		cin>>s_id;
		Admin *ptr = head;
		while(ptr != NULL){
			if(s_id == ptr -> id){
				cout<<endl<<"\t\t\tStudent's id ==> "<<ptr -> id;
				cout<<endl<<"\t\t\tStudent's name ==> "<<ptr -> name;
				cout<<endl<<"\t\t\tStudent's gender ==> "<<ptr -> gender;
				cout<<endl<<"\t\t\tStudent's date of birth ==> "<<ptr -> birth;
				cout<<endl<<"\t\t\tStudent's phone ==> "<<ptr -> phone;
				cout<<endl<<"\t\t\tStudent's address ==> "<<ptr -> address;
				
				cout<<endl<<"\t\t\t"<<ptr -> subject_1<<" ==> "<<ptr -> score_1;
				cout<<endl<<"\t\t\t"<<ptr -> subject_2<<" ==> "<<ptr -> score_2;
				cout<<endl<<"\t\t\t"<<ptr -> subject_3<<" ==> "<<ptr -> score_3;
				cout<<endl<<"\t\t\tAverage ==> "<<((ptr -> score_1 + ptr -> score_2+ ptr -> score_3)/3);
						 						 
				found++;
			}
			ptr = ptr -> next_Student;	 	
		}
		if(found == 0){
			cout<<endl<<"\t\t\tStudent's id is invalid"<<endl;
		}
	}
	file.close();
}
//Update information
void Admin::Update(){
	system("cls");
    fstream file, file1;
	int s_id;
	int found = 0;
	cout<<"\n\t******************* STUDENT MANAGEMENT SYSTEM *****************"<<endl;
    cout<<"\t\t************ UPDATE INFORMATION ************\n";
	cout<<"\t-----------------------------------------------------------------\n";
	file.open("datastudent.txt", ios::in);
	if(!file){
		cout<<endl<<"Link list is empty"<<endl;
		file.close();
	}
	else{
		cout<<endl<<"\t\t\tStudent's id for update: ";
		cin>>s_id;
		file.open("datastudent.txt", ios::in);
		Admin *ptr = head;
		while(!file.eof()){
			if(s_id == ptr -> id){
				cout<<"\t`````````````````````````````````````````````````````````````"<<endl;
       			cout<<"\t\tSEE INFORMATION OF STUDENT ";
				
				cout<<endl<<"\t\t\tStudent's phone: ";
				cin>>ptr -> phone;
				cin.ignore();
				cout<<endl<<"\t\t\tStudent's address: ";
				getline(cin, ptr -> address);
		
			file1.open ("datastu.txt",ios::out | ios::app);
			file1<<" "<<ptr -> id<<" | "<<ptr -> name<<" | "<<ptr -> gender<<" | "<<ptr -> birth<<" | "<<ptr -> phone<<" | "<<ptr -> address<<" | "<<ptr -> subject_1<<" | "<<ptr -> subject_2<<" | "<<ptr -> subject_3<<" | "<<ptr -> score_1<<" | "<<ptr -> score_2<<" | "<<ptr -> score_3<<" | "<<((ptr -> score_1 + ptr -> score_2+ ptr -> score_3)/3)<<endl;
			//file.close();		
			
			cout<<endl<<"\t\t\tUpdated!"<<endl;
			found++;
			break;
			}		
		}
		if(found == 0){
			cout<<endl<<"\t\t\tStudent's id is invalid"<<endl;
		}
	}
		file1.close();
        file.close();
        remove("datastudent.txt");
        rename("datastu.txt", "datastudent.txt");
}

//Delete by student's id
void Admin::Delete(){
	int s_id;
	int found = 0;
	fstream file, file1;
	cout<<"\n\t******************* STUDENT MANAGEMENT SYSTEM *****************"<<endl;
    cout<<"\t\t************ DELETE STUDENT ************\n";
	cout<<"\t-----------------------------------------------------------------\n";
	file.open("datastudent.txt", ios::in);
	if(!file){
		cout<<endl<<"\t\t\tLink list is empty"<<endl;
		file.close();
	}
	else{
		cout<<endl<<"\t\t\tStudent's id for delete: ";
		cin>>s_id;
		file.open("datastudent.txt", ios::in);
		if(s_id == head -> id){
			Admin *ptr = head;
			head = head -> next_Student;
			
			file1.open ("record.txt",ios::out | ios::app);
			file1<<" "<<ptr -> id<<" | "<<ptr -> name<<" | "<<ptr -> gender<<" | "<<ptr -> birth<<" | "<<ptr -> phone<<" | "<<ptr -> address<<" | "<<ptr -> subject_1<<" | "<<ptr -> subject_2<<" | "<<ptr -> subject_3<<" | "<<ptr -> score_1<<" | "<<ptr -> score_2<<" | "<<ptr -> score_3<<" | "<<((ptr -> score_1 + ptr -> score_2+ ptr -> score_3)/3)<<endl;
			file1.close();
			
			cout<<endl<<"\t\t\tDeleted!"<<endl;
			found++;
			delete ptr;
		}else{
			Admin *pre = head;
			Admin *ptr = head -> next_Student;
			while(ptr != NULL){
				if(s_id = ptr -> id){
					pre -> next_Student = ptr -> next_Student;
					found++;
					delete ptr;
					break;
				}
				pre = ptr;
				ptr = ptr -> next_Student;
				
			file1.open ("record.txt",ios::out | ios::app);
			file1<<" "<<pre -> id<<" | "<<pre -> name<<" | "<<pre -> gender<<" | "<<pre -> birth<<" | "<<pre -> phone<<" | "<<pre -> address<<" | "<<pre -> subject_1<<" | "<<pre -> subject_2<<" | "<<pre -> subject_3<<" | "<<pre -> score_1<<" | "<<pre -> score_2<<" | "<<pre -> score_3<<" | "<<((pre -> score_1 + pre -> score_2+ pre -> score_3)/3)<<endl;
			file1.close();
			}
		}
		if(found == 0){
			cout<<endl<<"\t\t\tStudent's id is invalid"<<endl;
		}
	}
		file1.close();
        file.close();
        remove("datastudent.txt");
        rename("record.txt", "datastudent.txt");
}

//print all information
void Admin::Print() {
	int i;
	fstream file;
	file.open("datastudent.txt",ios::in);
	if(!file){
		cout<<endl<<"\t\t\tLink list is empty"<<endl;
		file.close();
	}
	else{
		Admin *ptr = head;	
		while(ptr!=NULL){
			cout<<endl<<"\t\t\tLINKED LIST PRINTING..."<<"\n\n";
	    for(int i=1; ptr != NULL; i++){
       		cout<<"\t\tSEE INFORMATION OF STUDENT "<<i;
	       		cout<<endl<<"\t\t\tID => "<<ptr -> id;
	       		cout<<endl<<"\t\t\tName => "<<ptr -> name;
				cout<<endl<<"\t\t\tGender => "<<ptr -> gender;
				cout<<endl<<"\t\t\tDate of birth => "<<ptr -> birth;
				cout<<endl<<"\t\t\tPhone => "<<ptr -> phone;
				cout<<endl<<"\t\t\tAddress => "<<ptr -> address<<endl;
			
			cout<<endl<<"\t\tSEE SUBJECTS AND SCORES OF STUDENT "<<i;
				cout<<endl<<"\t\t\t"<<ptr -> subject_1<<" => "<<ptr -> score_1;
				cout<<endl<<"\t\t\t"<<ptr -> subject_2<<" => "<<ptr -> score_2;
				cout<<endl<<"\t\t\t"<<ptr -> subject_3<<" => "<<ptr -> score_3;
				cout<<endl<<"\t\t\tAverage => "<<((ptr -> score_1 + ptr -> score_2+ ptr -> score_3)/3);
            cout<<endl<<"\t_______________________________________________________"<<endl<<endl;
            ptr = ptr -> next_Student;
            
       		}	
			}		
		}
		file.close();		
}

void Admin::Read_file(){
 	//this function reads the data from file
 	file.open("datastudent.txt",ios::in);
 	int i=0;
 	while(!(file.eof()))
 	{
 		file>>s[i];
 		cout<<s[i]<<endl;
 		i++;
	}
	file.close();
 }

void Admin::MainMenu()//the first menu
{
	Admin a; 
	d:
   	int n;
   	system("cls");
        cout<<"\n\t******************* STUDENT MANAGEMENT SYSTEM *****************"<<endl;
        cout<<"\t\t************ WELCOME TO MAINMENU ************\n";
        cout<<"\n\t\t>>Please Enter your choice: \n";
        cout<<"\n\t\t1.Admin";
        cout<<"\n\t\t0.Close Application\n";
        cout<<"\t-----------------------------------------------------------------\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>n;
    	switch(n){
			case 1:
				system("cls");
				a.AdminMenu();
				break;
			case 0:
				exit(0);
			default:
				cout<<"\n**Invalis choice. Pls enter your choice again**"<<endl;
            }
            getch();   
			goto d; 
}

int Register()
{
	string pass_register = " ";
    string name_register = "";
    string pass = "";
    string name = "";
    fstream file;
    int i;
    char ch, check[10];
    system("cls");
    cout << "\n\t\t --------------------------------------------------------";
    cout << "\n\t\t\t||  WELCOME TO STUDENT MANAGEMENT SYSTEM  ||";
    cout<<"\n\t\t\t\tEnter 1: login\n\t\t\t\tEnter 2:Register";
    cout << "\n\t\t --------------------------------------------------------";
    
    int choice;
    cout << "\n\nPlease Enter Value: ";
    cin >> choice;
    
    // if user press [1], then it would lead them to login.
    if (choice == 1)
    {
        system("cls");
        file.open("data.txt", ios::in);
        cout << "\n\t\t\t\t--------------------------";
        cout << "\n\t\t\t\t\t>> LOGIN STUDENT <<";
        cout << "\n\t\t\t\t--------------------------";
        cout << "\n\n\t\t\t\t\tEnter Your Name: ";
        cin >> name;
        cout << "\n\t\t\t\t\tEnter Your Password: ";
        ch = _getch();
        while (ch != 13)
        {
            pass.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        file >> name_register >> pass_register;
        
        while (!file.eof()){
            if (pass == pass_register && name == name_register)
            {
            	cout << "\n\n\n\t\t\t\t\t--------------- VERFIYING ---------------\n\t\t\t\t\t";
                cout << "\n\n\t\t\t----> Successfully login..\n\n";
                system("PAUSE");
                system("cls");
            }
            else
            {
            	cout << "\n\n\n\t\t\t\t\t------------- VERFIYING --------------\n\t\t\t\t\t";
                cout << "\n\n\t\t\t---> False!!!! Try again...\n\n";
                system("PAUSE");
                system("cls");
                Register();
            }
            file >> name_register >> pass_register;
        }
        file.close();
    }
    else if (choice == 2)
    {
        system("cls");
        cout << "\n\t\t\t\t--------------------------------------";
        cout << "\n\t\t\t\t\t>> REGISTRATION ACCOUNT <<";
        cout << "\n\t\t\t\t--------------------------------------";
        cout << "\n\n\t\t\t\t\tEnter Your Name: ";
        cin >> name_register;
        cout << "\n\t\t\t\t\tEnter Your Password: ";
        ch = _getch();
        while (ch != 13)
        {
            pass.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        file.open("data.txt", ios::app);
        file << " " << name_register << " " << pass_register << "\n";
        file.close();
        cout << "\nRegistration Succesfully save";
        getch();
        Register();
    }
    else
    {
        cout << "\nInvalid Input.. Please Try Again..";
        Register();
    }
    return 0;
}

void Admin::AdminMenu()//the Admin menu
{
	Admin a;
	int Reagister();
	Register();
	s:
	while(true){
	int choice;
	char x;
	system("cls");
	cout<<"\n\t******************* STUDENT MANAGEMENT SYSTEM *****************"<<endl;
    cout<<"\t\t************ WELCOME TO ADMINMENU ************\n";
	cout<<"\t-----------------------------------------------------------------\n";
	cout<<"\t\t1. Insert Student"<<endl;
	cout<<"\t\t2. Search "<<endl;
	cout<<"\t\t3. Update"<<endl;
	cout<<"\t\t4. Delete"<<endl;
	cout<<"\t\t5. Print all student list"<<endl;
	cout<<"\t\t6. Go to the main menu"<<endl;
	cout<<"\t\t0. Exit"<<endl;
	cout<<"\t\tEnter your choice: ";
	cin>>choice;
	switch(choice){
		case 1:
			system("cls");
			do{
			a.Insert();
			cout << "\n\n\t\t\t Add Another Student Record Press (Y, N) : ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
			break;
		case 2:
			system("cls");
			a.Search();
			break;
		case 3:
			system("cls");
			a.Update();
			break;
		case 4:
			system("cls");
			a.Delete();
			break;	
		case 5:
			system("cls");
			a.Print();
			break;	
		case 6:
			system("cls");
			a.MainMenu();
			break;	
		case 0:
			exit(0);
		default:
			cout<<"\n**Invalis choice. Pls enter your choice again**"<<endl;
	
	}	
    getch();
    goto s;
	}
}

int main() {
	Admin a;
	system("cls");
    a.MainMenu();
    getch();
    return 0;
}

