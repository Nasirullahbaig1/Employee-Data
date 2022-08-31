#include<iostream>
#include<fstream>
#include<string.h>
#include<windows.h>
using namespace std;

struct employee{
	int regno;
	char name[20];
	char addr[30];
	
	
};
employee emp;
save_employee_record(){
	cout<<"Enter Employee ID : "<<endl;
	cin>>emp.regno;
	cout<<"Enter Employee Name :"<<endl;
	cin>>emp.name;
	cout<<"Enter Employee address"<<endl;
	cin>>emp.addr;
	
	ofstream sf;
	sf.open("employee.txt",ios::app);
	sf<<endl;
	sf<<emp.regno;
	sf<<endl;
	sf<<emp.name;
	sf<<endl;
	sf<<emp.addr;
	sf<<endl;
	sf.close();
	return 0;
}

Show_All_Employee_Recorded(){
	ifstream rf;
	rf.open("employee.txt");
	rf>>emp.regno;
	rf>>emp.name;
	rf>>emp.addr;
	while(!rf.eof()){
		cout<<"Employee REG No. : "<<emp.regno<<endl;
		cout<<"Employee Name  : "<<emp.name<<endl;
		cout<<"Employee address : "<<emp.addr<<endl;
		rf>>emp.regno;
		rf>>emp.name;
		rf>>emp.addr;
		
	}
	rf.close();
	return 0;
}

Employee_Record_Deleted(){
	int se;
	cout<<"Enter Employee ID to Delete "<<endl;
	cin>>se;
	ifstream delt;
	delt.open("employee.txt");
	ofstream temp;
	temp.open("temparory.txt");
	delt>>emp.regno;
	delt>>emp.name;
	delt>>emp.addr;
	while(!delt.eof()){
		if(emp.regno!=se){
			temp<<endl;
			temp<<emp.regno;
			temp<<endl;
			temp<<emp.name;
			temp<<endl;
			temp<<emp.addr;
			temp<<endl;
		}
		else
		{
			cout<<"Record Deleted\n";
		}
		delt>>emp.regno;
		delt>>emp.name;
		delt>>emp.addr;
	}
	delt.close();
	temp.close();
	remove("employee.txt");
	rename("temparory.txt","employee.txt");
	return 0; 
}

Employee_Record_Update(){
int uid;
int uname;
int uaddr;
int se;
cout<<"Enter the employee ID to Update "<<endl;

ifstream upd;
upd.open("employee.txt");
ofstream temp;
temp.open("temparory.txt");
upd>>emp.regno;
upd>>emp.name;
upd>>emp.addr;
while(!upd.eof()){
	if(emp.regno!=se){
		temp<<endl;
		temp<<emp.regno;
		temp<<endl;
		temp<<emp.name;
		temp<<endl;
		temp<<emp.addr;
		temp<<endl;
	}
	else
	{
		cout<<"Enter New ID : "<<endl;
		cin>>uid;
		cout<<"Enter Name : "<<endl;
		cin>>uname;
		cout<<"Enter Address : "<<endl;
		cin>>uaddr;
		
		temp<<endl;
		temp<<uid;
		temp<<endl;
		temp<<uname;
		temp<<endl;
		temp<<uaddr;
	}
	upd>>emp.regno;
	upd>>emp.name;
	upd>>emp.addr;
}  
upd.close();
temp.close();
remove("employee.txt");
rename("temparory.txt","employee");
return 0;
}

Search_Spacific_Record(){
	employee emp;
	int s;
	ifstream srf;
	srf.open("Employee.txt");
	cout<<"Enter Search Id "<<endl;
	cin>>s;
while(!srf.eof()){
	srf>>emp.regno;
	srf>>emp.name;
	srf>>emp.addr;
	if(emp.regno==s)
	break;
}
cout<<"Employee ID : "<<emp.regno<<endl;
cout<<"Name : "<<emp.name<<endl;
cout<<"Address : "<<emp.addr<<endl;
return 0;	 
	
}
Clear_Screen(int clear){
	if (clear ==0){
		clear=1;
	}
	else if(clear==1){
		system("PAUSE");
		system("CLS");
	}
	else if(clear=2){
		system("CLS");
	}
	return 0;
}


int main(){
	int check_status=0;
	start:
		check_status=Clear_Screen(check_status);
	
	
		int ch;
		cout<<"********************************************"<<endl;
		cout<<" Employee Information System\n ";
		cout<<"********************************************"<<endl;
		cout<<"1: New Record\n";
		cout<<"2: Show All Record\n";
		cout<<"3: Delete Record\n";
		cout<<"4: Update Record\n";
		cout<<"5: Search any Record\n";
		cout<<"6: Exit\n";
		cout<<"********************************************"<<endl;
		cin>>ch;
		switch(ch){
			case 1:
				save_employee_record();
				goto start;
				break;
			case 2:
				Show_All_Employee_Recorded();
				goto start;
				break;
			case 3:
				Employee_Record_Deleted();
				goto start;
				break;
			case 4:
				Employee_Record_Update();
				goto start;
				break;
			case 5:
				Search_Spacific_Record();
				goto start;
				break;
			default:
				Clear_Screen(2);
				cout<<"\t\t\t\t\t\n\n\n\n\n THANK YOU FOR USEING";
				
		return 0;		
		}



	return 0;
}

