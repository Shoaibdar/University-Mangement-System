#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
class  Project
{
	public:
	    string facultyusername;
		string facultypassword;
		string studentpassword;
		string studentusername;
	    string update_file;            //update file indiviually
	    string update_students_file;
		string delete_students_file;   //update file for all
	    char update_students_password[];
	    //string delete_students_file;
	    char updatefacultypassword[];
	    char writetask[];
	    char studentswork[]; 
		char write_students_task[];      //student will write yor work
	    int choice;
	    int task;
	    int AssignTask;
	    int updatetask;
	    int deletetask;
	    int studentstask;
	    char regno[8];
	    char reg[8];
	    int changefacultypassword;
	    int write_submit;
	    int press;
    public:
		void mainmenu();
		void studentlogin();
		void facultylogin();
		void choose();
		void writeTASK();    //write task
		void readTASK();    //read task
		void Projectdetails();
		void Loginpage();
};
void Project::Projectdetails()
{
	std::cout<<"\n                                   "<<"---------------------------------";
	std::cout<<"\n                                   "<<"|       CREATED BY SHOAIB.      |"<<endl;
	std::cout<<"\n                                   "<<"| GUIDED TO GOUTAM MAJUMDER. |"<<endl;
	std::cout<<"                                   "<<"---------------------------------"<<endl;
	std::cout<<endl;
}
void Project::mainmenu()
{
	std::cout<<std::setfill('_')<<std::setw(112);
	cout<<"\n";
	std::cout<<std::setfill(' ')<<std::setw(75);
	
	std::cout<<"**************WELLCOME TO LOGIN PAGE**************"<<endl;
	std::cout<<"\nPlease Select Your Choice............"<<endl;
	std::cout<<"\nPress 1 For Faculty Login."<<endl;
	std::cout<<"\nPress 2 For Student Login."<<endl;
	std::cin>>choice;
	std::cin.ignore();
}
void Project::facultylogin()
{
    std::cout<<std::setfill('-')<<std::setw(112);
	std::cout<<"\n";
	
	std::cout<<"\nPlease Enter Your Username Or UID : "<<endl;
	std::cin>>facultyusername;
	std::cin.ignore();
	std::cout<<"\nPlease Enter Your Password        : "<<endl;
	std::cin>>facultypassword;
	std::cin.ignore();
	system("cls");
}
void Project::studentlogin()
{
		std::cout<<std::setfill('-')<<std::setw(112);
	    std::cout<<"\n";
		cout<<"\nPlease Enter Username or Registiration:"<<endl;
		cin>>studentusername;
		std::cout<<"\nPlease Enter Your Password : "<<endl;
		cin>>studentpassword;
		cin.ignore();
		system("cls");
}
void Project::choose()
{
	if(choice==1)
	{
		fstream file;
		fstream file1;
		string line;
		string line1;
		
		file.open("facultypassword.txt",ios::in);
		file1.open("facultyusername.txt",ios::in);
		
	if(file.is_open() && file1.is_open())
	{
		while(getline(file,line) && getline(file1,line1))
	    {
		facultylogin();
		
			if(line==facultypassword && line1==facultyusername)
			{
				std::cout<<"\nSucessfully Logined!"<<endl;
			}
			else
		    {
			cout<<"Incorrect Password or UID!"<<endl;
			exit(1);
		    }
     	}
     	file.close();
     	file1.close();
}		
		std::cout<<std::setfill('-')<<std::setw(112);
		std::cout<<"\n";
		
		std::cout<<"\nPress 1 To Create a Task"<<endl;
        std::cout<<"\nPress 2 To Assign a Task"<<endl;
        std::cout<<"\nPress 3 To Update The Task"<<endl;
        std::cout<<"\nPress 4 To Delete a Task"<<endl;
        std::cout<<"\nPress 5 To Update Your Password"<<endl;
       // std::cout<<"\nPress 6 To Go Mainmenu."<<endl;
        std::cin>>task;
        
        std::cout<<std::setfill('-')<<std::setw(112);
        std::cout<<"\n";
        
        switch(task)
        {
        	case 1:
        	//	std::cout<<"\nWrite Your Task"<<endl;
				break;
			case 2:
				std::cout<<"\nPress 1 To Assign Task Individually"<<endl;
				std::cout<<"\nPress 2 To Assign Task All"<<endl;
				std::cin>>AssignTask;
				break;
			case 3:
				std::cout<<"\nPress 1 To Update The Task Individually"<<endl;
				std::cout<<"\nPress 2 To Update The  Task For All"<<endl;
				std::cin>>updatetask;
				break;
			case 4:
				std::cout<<"\nPress 1 To Delete The  Task Individually"<<endl;
				std::cout<<"\nPress 2 To Delete The  Task For All"<<endl;
				std::cin>>deletetask;
				break;
			case 5:
				//
				break;
			default:
				std::cout<<"Invalid Input.";
				break;
		}
	}

	else if(choice==2)
	{	
		studentlogin();
		fstream file;
	    file.open(studentusername.c_str());
	    if(!file)
	    {
	    	std:cout<<"\nIncorrect Username or Password."<<endl;
	    	exit(1);
		}
		string line;
		string str = "password.txt";
		string password = studentusername + str;
        
		ifstream file1(password.c_str(),ios::in);
		if(file1.is_open())
		{
			while(getline(file1,line))
			{
				if(studentpassword!=line)
				{
					std::cout<<"Incorrect Username or Password";
					exit(1);
				}
			}
		}
		std::cout<<std::setfill('-')<<std::setw(112);
   	    std::cout<<"\n";
		std::cout<<"Sucessfully Logined!"<<endl;
		
		std::cout<<std::setfill('-')<<std::setw(112);
   	    std::cout<<"\n";
   	    
        std::cout<<"\nPress 1 To View Your Personal Task"<<endl;
	   	std::cout<<"\nPress 2 To Submit Your Task"<<endl;
        std::cout<<"\nPress 3 To  Check The Submission Date"<<endl;
        std::cout<<"\nPress 4 To Update Your Password"<<endl;
        std::cout<<"\nPress 5 To View Task(Assignd For All)"<<endl;
        std::cin>>studentstask;
        cin.ignore();
		
        switch(studentstask)
        {
        	case 1:
        		//std::cout<<"View your task (under construction)"<<endl;
        		//exit(1);
        		readTASK();
        		break;
        	case 2:
        		//std::cout<<"submit your task (under construction)"<<endl;
        		readTASK();
        		break;
        	case 3:
        	//	std::cout<<"\nLast Date Of Submission is 06-04-2019."<<endl;
        	//	std::cout<<"\nThank You!"<<endl;
        	    readTASK();
        		break;
        	case 4:
        	//	std::cout<<"Final Result your task (under construction)"<<endl;
        		readTASK();  //update password
        		break;
        	case 5:
        		//
        		readTASK();
        		break;
        	default:
        		std::cout<<"Invalid Input.";
        		break;
		}
	}
	
}
void Project::writeTASK()
{    
	 if(task==1)
	{
		char writetofile;
    	ofstream file;
    	file.open("write.txt",ios::out);   
    	std::cout<<"\nWrite Your Task (Press # at The End of Writing):"<<endl;
		std::cin.getline(writetask,sizeof(writetask)); 
		
		while((writetofile=getchar())!='#')
		{
        file<<writetofile;        //write in file
        }                       
		file.close();
		
		std::cout<<std::setfill('-')<<std::setw(112);
   	    std::cout<<"\n";
   	    
		std::cout<<"\nYou Wrote Sucessfully!"<<endl;
		string line;
        ifstream file1 ("write.txt");
        
    if (file1.is_open())
        {
            while(getline(file1,line))
            	{
               		std::cout<<"\n"<<line<<endl;
                }
        }
            file1.close();
    }
		
    else if(task==2)
   {
   	std::cout<<std::setfill('-')<<std::setw(112);
   	std::cout<<"\n";
   	
   	if(AssignTask==1)    //assin task individually
   	    {
   	   	    char reg[8];
		//	int i;
			char writetofile;
			
   	        std::cout<<"\nEnter Students Registiration Number:"<<endl;
   	       	std::cout<<"\n****Remark Registiration Number Cannot Be Greater Than 8****\n"<<endl;
   	        cin>>reg;
			  /*if(reg[i]>8)
   	           {
   	            	cout<<"Sorry"<<endl;
   	                exit(1);
   	            }
   	        /*else{*/
			   
   	   	    //cin>>reg;
   	   	    std::cout<<std::setfill('-')<<std::setw(112);
        	std::cout<<"\n";
        	
   	   	    std::cout<<"Enter Your Task(Press # at The End of The File.):"<<endl;
   	   	    ofstream file;
			file.open(reg,ios::out);
			std::cin.getline(write_students_task,sizeof(write_students_task));
		//	cin>>write_students_task;
			while((writetofile=getchar())!='#')
			{
				file<<writetofile;
			}
			
		ofstream filea;	
		char writetofilea;
		
			string str;
			string str1;
		
	//	getline(cin,reg);
			str = "password.txt";
			str1 = reg + str;
			filea.open(str1.c_str(),ios::out|ios::trunc);
			filea<<reg;
			file.close();
			filea.clear();
			
			std::cout<<std::setfill('-')<<std::setw(112);
   	        std::cout<<"\n";
   	        
			std::cout<<"\nYou Wrote Sucessfully!"<<endl;
	     	string line;
            ifstream file1 (reg);
            
            if (file1.is_open())
            {
                while(getline(file1,line))
            		{
               			std::cout<<"\n"<<line<<endl;
                    }
            }
        		file.close();
	    }
	    
	else if(AssignTask==2)     //assign task to all
	    {
	    	char writetofile;                   
			ofstream file;                                   
			file.open("Assigntask.txt",ios::out);
			std::cin.getline(writetask,sizeof(writetask));
			std::cout<<"\nWrite Your Task (Press # at The End of Writing):"<<endl;
			
			while((writetofile=getchar())!='#')
		    {            
				file<<writetofile;
			}
			file.close();
			
			std::cout<<"\nYou Wrote Sucessfully!\n"<<endl;
	      	string line;
    	    ifstream file1("Assigntask.txt");
    	    
    		if (file1.is_open())
	        {
            	while(getline(file1,line))
            	{
               		std::cout<<"\n"<<line<<endl;
                }
        	}
            file1.close();                               
    	}
    }
    
    else if(task==3)
    {
    	std::cout<<std::setfill('-')<<std::setw(112);
   	    std::cout<<"\n";
   	    
    	if(updatetask==1)
    	{
    		//ofstream file;
    		char writetofile;
    		int update;
    		std::cout<<"\nEnter The Students Registiration Number Whose Task You Want To Update:"<<endl;
    		cout<<"\n****Remark Registiration Number Cannot Be Greater Than 8****\n"<<endl;
			cin>>regno;
			
		    std::cout<<"\nPress 1 To Update All."<<endl;
			std::cout<<"\nPress 2 To Edit a File"<<endl;
			cin>>update;	
			
			if(update==1)
			{
		
				fstream filea;
				string line;
	        	filea.open(regno,ios::in);
	        
	        	std::cout<<"Pervious Task Of The Student\n";
	        	std::cout<<std::setfill('-')<<std::setw(112);
         		std::cout<<"\n";
	        
	        	while(getline(filea,line))
	        		{
	        			std::cout<<line<<endl;
					}
				filea.close();		

			
	            ofstream file1;
	            file1.open(regno,ios::out|ios::trunc);
	            
				std::cout<<"\nUpdate Your Task (Press # at The End of Writing)"<<endl;
    			getline(cin,update_students_file);
    			while((writetofile=getchar())!='#')
    				{
    					file1<<writetofile;
					}	
				file1.close();
			}
			
			else if(update==2)
			{
				ifstream file;
				file.open(regno,ios::in);
				
				string line;
				std::cout<<std::setfill('-')<<std::setw(112);
         		std::cout<<"\n";
         		
				std::cout<<"\nPervious Task..."<<endl;
				while(getline(file,line))
				{
					cout<<line<<endl;
				}
				file.close();
				
				ofstream file1;
				file1.open(regno,ios::out|ios::app);
				std::cout<<std::setfill('-')<<std::setw(112);
         		std::cout<<"\n";
         		
				std::cout<<"\nUpdate Your Task (Press # at The End of Writing)"<<endl;
    			getline(cin,update_students_file);
    			while((writetofile=getchar())!='#')
    				{
    					file1<<writetofile;
					}	
				std::cout<<"\nFile Updated Successfully"<<endl;
				file1.close();
				
		/*	ifstream fileb;
			string linea;
			
	        fileb.open(regno);
	        std::cout<<std::setfill('-')<<std::setw(112);
         	std::cout<<"\n";
	        
	        if(fileb.is_open())
	        {
	        	while(getline(fileb,linea))
	        	{
	        		std::cout<<line<<endl;
				}
			}*/
		} 
	}		
		else if(updatetask==2)
		{
			int update;
			std::cout<<"\nPress 1 To Update All"<<endl;
			std::cout<<"\nPress 2 To Edit The Task"<<endl;
			cin>>update;
			
			if(update==1)
			{
				ifstream file;
    			//char writetofile;
		    	file.open("Assigntask.txt",ios::in);
		    
				if(!file)
				{
					std::cout<<"\nError In Opening a File.";
					exit(1);
				}
				std::cout<<endl;
				
				string line;
				std::cout<<"Pervious Task Of The Student\n";
				while(getline(file,line))
				{
					std::cout<<line<<endl;
				}
			    file.close();
			
			    char writetofile;
				ofstream filea;
	        	filea.open("Assigntask.txt",ios::out|ios::trunc);
	        	
    		std::cout<<std::setfill('-')<<std::setw(112);
   	        std::cout<<"\n";
   	        
    		std::cout<<"\nUpdate Your Task (Press # at The End of Writing)"<<endl;
    		getline(cin,update_file);
    		
    	//	file.seekp(position);
    		while((writetofile=getchar())!='#')
    		{
    			filea<<writetofile;
			}
			filea.close();
			
			std::cout<<std::setfill('-')<<std::setw(112);
   	        std::cout<<"\n";
   	        
			std::cout<<"\nFile Updated Sucessfully!"<<endl;
			
	      	string line1;
    	    ifstream fileb("Assigntask.txt");
    	    
    		if (fileb.is_open())
	        {
            	while(getline(fileb,line1))
            	{
               	    std::cout<<"\n"<<line1<<endl;
                }
        	}
            fileb.close();  
        }
        else if(update==2)
        {
        	ifstream file;
        	file.open("Assigntask.txt",ios::in);
        	
        	string line;
        	std::cout<<std::setfill('-')<<std::setw(112);
   	        std::cout<<"\n";
   	        
        	std::cout<<"\nPervious Task......"<<endl;
        	while(getline(file,line))
        	{
        		std::cout<<line<<endl;
			}
        	file.close();
        	
        	char writetofile;
        	ofstream file1;
        	file1.open("Assigntask.txt",ios::out|ios::ate);
        	
        	std::cout<<std::setfill('-')<<std::setw(112);
   	        std::cout<<"\n";
   	        
        	std::cout<<"\nUpdate Your Task (Press # at The End of Writing)"<<endl;
    		getline(cin,update_file);
    		
    		while((writetofile=getchar())!='#')
    			{
    				file1<<writetofile;
				}	
			std::cout<<"\nFile Updated Successfully"<<endl;
			file1.close();
			
			ifstream filea;
			filea.open("Assigntask.txt",ios::in);
			
			string linea;
			std::cout<<std::setfill('-')<<std::setw(112);
   	        std::cout<<"\n";
   	        
			//std::cout<<"\nFile Updated Successfully!"<<endl;
			while(getline(filea,linea))
			{
				std::cout<<linea<<endl;
			}
			filea.close();
		} 
	}
}
	else if(task==4)
	{
		if(deletetask==1)
		{		
		//	char delete_students[8];												//detele individually 1		
			fstream file;
			std::cout<<std::setfill('-')<<std::setw(112);
   	        std::cout<<"\n";
   	        
			std::cout<<"\nEnter The Students Registiration Whose File You Want To Delete:"<<endl;
            //getline(cin,delete_students_file);

            cin>>delete_students_file;
            string str = "password.txt";
            string str1= delete_students_file + str;
            
          //  file.open(delete_students_file);
            
            if(!file)     
            {
            	std::cout<<std::setfill('-')<<std::setw(112);
   	            std::cout<<"\n";
   	            
            	std::cout<<"\nStudent Does Not Exist [No Such File Is Not There]."<<endl;
            	exit(1);
			}
				int surety;
				std::cout<<std::setfill('-')<<std::setw(112);
   	            std::cout<<"\n";
   	            
		        std::cout<<"\nAre You Sure You Want To Delete This File."<<endl;
                std::cout<<"1->Yes"<<endl;
                std::cout<<"0->No"<<endl;
                std::cin>>surety;
                cin.ignore();

				if(surety==1)
				{
					remove(str1.c_str());    //remove students file
					remove(delete_students_file.c_str());   //students password file
					
					std::cout<<std::setfill('-')<<std::setw(112);
   	                std::cout<<"\n";
   	                
					cout<<"\nFile Has Been Deleted Sucessfully!.";
				}
				
				else if(surety==0)
				{
					std::cout<<std::setfill('-')<<std::setw(112);
   	                std::cout<<"\n";
   	                
					std::cout<<"\nFile Is Safe.";
					exit(1);
				}
				file.close();
		}												
		else if(deletetask==2)
		{                                                       
			int surety;
			std::cout<<std::setfill('-')<<std::setw(112);
   	        std::cout<<"\n";
   	        
			cout<<"\nAre You Sure You Want Delete Task For All Students."<<endl;
			
			cout<<"\n1->Yes"<<endl;
			cout<<"\n0->No"<<endl;
			cin>>surety;
			
			if(surety==1)
			{
				remove("write.txt");
				std::cout<<std::setfill('-')<<std::setw(112);
   	            std::cout<<"\n";
   	            
				cout<<"\nFile Has Been Deleted Sucessfully!";
			}
			
			else if(surety==0)
			{
				std::cout<<std::setfill('-')<<std::setw(112);
   	            std::cout<<"\n";
				std::cout<<"\nFile Is Safe.";
				exit(1);
			}
		}														//delete for all 2
	}
	else if(task==5)
	{
		char writetofile;
		fstream file;
		file.open("facultypassword.txt",ios::out|ios::trunc);
		
		std::cout<<std::setfill('-')<<std::setw(112);
   	    std::cout<<"\n";
   	        
		std::cout<<"\nEnter Your New Password(Press # at The End of Password)."<<endl;
	    //cin>>updatefacultypassword;
	    cin.getline(updatefacultypassword,sizeof(updatefacultypassword));
		if(file.is_open())
		{
			while((writetofile=getchar())!='#')
			{
				file<<writetofile;
			}
			std::cout<<std::setfill('-')<<std::setw(112);
   	        std::cout<<"\n";
   	        
   	        std::cout<<"\nPassword Updated Sucessfully!";
		}
		
		else if(!file)
		{
			std::cout<<std::setfill('-')<<std::setw(112);
   	        std::cout<<"\n";
   	        
			std::cerr<<"\nError In Opening a File!";
		}
		
		file.close();
	}
}

void Project::readTASK()                  //students will read
{
	if(studentstask==1)
	{
		//std::cout<<std::setfill('-')<<std::setw(112);
   	    //std::cout<<"\n";
   	    
     	string line;
        ifstream file (studentusername.c_str());
        
     if (file.is_open())
       {
       	std::cout<<std::setfill('-')<<std::setw(112);
		std::cout<<"\n";
		
       	std::cout<<"Your Task is......\n"<<endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
            while(getline(file,line))
            {
                std::cout << line << '\n';
            }
            exit(1);
        }
    else if (!file)
    	{
    		std::cerr<<"\nError In Opening a File.";
		}
        file.close();
	}
	else if(studentstask==2)
	{
		std::cout<<std::setfill('-')<<std::setw(112);
		std::cout<<"\n";
		
		std::cout<<"\nPress 1 To Write Your Task."<<endl;
		std::cout<<"\nPress 2 To Submit Your Task."<<endl;
		std::cin>>write_submit;
		
		if(write_submit==1)
			{
				ofstream file;
				file.open("studentspersonalfile.txt",ios::out);
				
				if(!file.is_open())
				{
					std::cout<<std::setfill('-')<<std::setw(112);
   	    			std::cout<<"\n";
   	    			
					std::cout<<"\nError In Opening The File!"<<endl;
				}
				if(file.is_open())
				{
					char writetofile;
					std::cout<<std::setfill('-')<<std::setw(112);
					std::cout<<"\n";
					
					std::cin.getline(studentswork,sizeof(studentswork));
					std::cout<<"\nWrite Your Work(Press # at The End of File)......."<<endl;
					
					while((writetofile=getchar())!='#')
					{
       				 file<<writetofile;        //write in file
        			}  
        			
				std::cout<<std::setfill('-')<<std::setw(112);
   	   			std::cout<<"\n";
					      
				std::cout<<"You Wrote Sucessfully!"<<endl;                 
				file.close();	
				}
				exit(1);
			}
		else if(write_submit==2)
		{
			std::cout<<std::setfill('-')<<std::setw(112);
   	    	std::cout<<"\n";
   	    	
			std::cout<<"\nYour Task Has Been Sucessfully Submited!"<<endl;
			std::cout<<"Thank You!";
			
			std::cout<<std::setfill('-')<<std::setw(112);
   	        std::cout<<"\n";
			exit(1);
		}
	}
	else if(studentstask==3)
	{
		string line;
		ifstream file;
		file.open("submission date.txt",ios::in);
		
		if(!file.is_open())
		{
			std::cout<<std::setfill('-')<<std::setw(112);
   	    	std::cout<<"\n";
   	    	
			std::cout<<"\nError Opening In The File!"<<endl;
			exit(1);
		}
		if(file.is_open())
		{
			while(getline(file,line))
			{
				std::cout<<std::setfill('-')<<std::setw(112);
   	    		std::cout<<"\n";
   	    		
				std::cout<<"\nLast Date Of Submision is "<<line<<endl;
				std::cout<<"\nRemark: If Date Is Over.Submission Is Not Allowed."<<endl;
				std::cout<<"\nThank You!";
				
				std::cout<<std::setfill('-')<<std::setw(112);
   	            std::cout<<"\n";
				exit(1);
				
			}
		}
		exit(1);
	}
	
	else if(studentstask==4)
	{
		char writetofile;
		string line;
		string reg;
		string str;
		string str1;
		
		std::cout<<std::setfill('-')<<std::setw(112);
   	    std::cout<<"\n";
   	    
		std::cout<<"\nEnter Registiration Number or Username:"<<endl;
	//	getline(cin,reg);
		cin>>reg;
		str = "password.txt";
		str1 = reg + str;
		
		if(studentusername!=reg)
		{
			std::cout<<std::setfill('-')<<std::setw(112);
   	    	std::cout<<"\n";
   	    	
			std::cout<<"\nIncorrect username"<<endl;
			exit(1);
		}
		ofstream file;
		file.open(str1.c_str(),ios::out|ios::trunc);
		
		if(!file.is_open())
		{
			std::cout<<std::setfill('-')<<std::setw(112);
   	    	std::cout<<"\n";
   	    	
			std::cout<<"\nError Opening In The File!"<<endl;
			exit(1);
		}
		if(file.is_open())
		{
			std::cout<<std::setfill('-')<<std::setw(112);
   	    	std::cout<<"\n";
   	    	
			std::cout<<"\nEnter Your New Password(Press # at The End Of Password)."<<endl;
			cin.getline(update_students_password,sizeof(update_students_password));
			//cin>>update_students_password;
			
			while((writetofile=getchar())!='#')
			{
				file<<writetofile;
			}
			std::cout<<std::setfill('-')<<std::setw(112);
   	    	std::cout<<"\n";
			std::cout<<"\nPassword Updated Sucessfully!"<<endl;
		}
		file.close();
		exit(1);
	}
	else if(studentstask==5)
	{
		string line;
		ifstream file;
		file.open("Assigntask.txt",ios::in);
		
		if(!file.is_open())
		{
			std::cerr<<"\nError."<<endl;
			exit(1);
		}
		
		if(file.is_open())
		{
			std::cout<<std::setfill('-')<<std::setw(112);
   	        std::cout<<"\n";
			
			while(getline(file,line))
			{
				std::cout<<line;
			}
		}
		file.close();
		exit(1);
	}
//	mainmenu();
}
void Project::Loginpage()
{
	std::cout<<std::setfill('-')<<std::setw(135);
	
	std::cout<<"\nPress 1 For Login Page."<<endl;
	std::cout<<"\nPress 0 To Exit."<<endl;
	std::cin>>press;
	
	if(press==1)
	{
		mainmenu();
	}
	else if(press==0)
	{
		std::cout<<"\nExited.";
		exit(1);
	}
}

int main()
{
	Project P;
	P.Projectdetails();
	P.Loginpage(); 
	//P.mainmenu();	           //Do not call mainmenu again.
	P.choose();
	P.writeTASK();
	P.readTASK();

}
