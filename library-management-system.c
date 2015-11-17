#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

 struct books
 {
  char book_name[25];
  char author_name[25];
  char book_id[20];
  int cost;
  int book_number;
  char subject[20];
  
 };
 struct student
 {
  char stu_name[30];
  int year;
  int semester;
  char stu_rollno[10];
  char stu_branch[20];
  int number_of_books;
  int date;
  int month;
  int year1;
 };

void studentmenu();

void booksmenu();
void admin();
void user();

void add_new_book();

void edit_existing_book();
void delete_book();
void view_all_books();
void add_student_record();
void view_students();


void edit_student_record();
void delete_student_record();

void issue_book();
void return_book();

void search_book();


int main()
{ char password[30];
  again:
  printf("\t\t");
 for(int i=0;i<25;i++)
  printf("*");
 printf("\n\t\t*\t1.Administrator *\n\t\t*\t2.User          *\n\t\t*\t3.Exit     \t*");
 printf("\n\t\t");
 for(int i=0;i<25;i++)
  printf("*");
 printf("\nEnter your option : ");
 int choice;
 scanf("%d",&choice);
 int k=0,i=0;
 char ch,temp[80];
 switch(choice)
{ 
 case 1:
   printf("\nEnter the password : ");
scanf("%s",password);	
   if(strcmp(password,"projectnitk")==0)
   {
   admin();
   }
   else
   {
    printf("\n Enter appropriate choice \n");
    goto again;
   }
   break; 
 case 2:
   user();
   break;
 case 3:
 exit(0);
 default :
 printf("\n Enter an Appropriate Option\n ");
 goto again;  
}

}

//Funtion for the students menu..
void studentmenu()
{ student_again:
 printf("\n\t\t");
 for(int i=0;i<40;i++)
  printf("*");
 printf("\n\t\t*\t1.Add New Record               *\n\t\t*\t2.Edit Existing Record         *\n\t\t*\t3.Delete Student record        *\n\t\t*\t4.Issue Book                   *\n\t\t*\t5.Return Book                  *\n\t\t*\t6.EXIT                         *");
 printf("\n\t\t");
 for(int i=0;i<40;i++)
  printf("*");
printf("\nEnter Your Choice : ");
int choice;
scanf("%d",&choice);
switch(choice)
{
 case 1:
  add_student_record();
  break;
 case 2:
  edit_student_record();
  break;
 case 3:
  delete_student_record();
  break;
 case 4:
  issue_book();
  break;
 case 5:
  return_book();
  break;
 case 6:
  exit(0);
 break;
 default :
  printf("\n Enter appropriate Choice : \n");
  goto student_again;
}

}


void booksmenu()
{books_again:
 printf("\n\t\t");
 for(int i=0;i<40;i++)
  printf("*");
 printf("\n\t\t*\t1.Add New Book                 *\n\t\t*\t2.Edit Existing Book Record    *\n\t\t*\t3.Delete book record           *\n\t\t*\t4.EXIT                         *");
 printf("\n\t\t");
 for(int i=0;i<40;i++)
  printf("*");
printf("\nEnter Your Choice : ");
int choice;
scanf("%d",&choice);
switch(choice)
{
 case 1:
  add_new_book();
  break;
 case 2:
  edit_existing_book();
  break;
 case 3:
  delete_book();
  break;
 case 4:
  exit(0);
  break;
 default :
  printf("\n Enter appropriate Choice \n");
  goto books_again;
}

}
void admin()
{
 again:
  printf("\t\t");
 for(int i=0;i<25;i++)
  printf("*");
 printf("\n\t\t*\t1.Student  \t*\n\t\t*\t2.Books   \t*\n\t\t*\t3.Exit     \t*");
 printf("\n\t\t");
 for(int i=0;i<25;i++)
  printf("*");
 printf("\nEnter your option : ");
 int choice;
 scanf("%d",&choice);
 switch(choice)
{ 
 case 1:
   studentmenu();
   break; 
 case 2:
   booksmenu();
   break;
 case 3:
 exit(0);
 default :
 printf("\n Enter an Appropriate Option\n ");
 goto again;  
}


}
void user()
{ again:
 printf("\n\t\t");
 for(int i=0;i<40;i++)
  printf("*");
 printf("\n\t\t*\t1.View All Students            *\n\t\t*\t2.View All Books               *\n\t\t*\t3.Search books                 *\n\t\t*\t4.EXIT                         *");
 printf("\n\t\t");
 for(int i=0;i<40;i++)
  printf("*");
printf("\nEnter Your Choice : ");
int choice;
scanf("%d",&choice);
switch(choice)
{
 case 1:
  view_students();
  break;
 case 2:
  view_all_books();
  break;
 case 3:
  search_book();
  break;
 case 4:
  exit(0);
  break;
 default : 
  printf("\n Enter appropriate Option : \n");
  goto again;
}

}
void add_new_book()
{
 struct books b;
 FILE *fp1;
 fp1=fopen("book1.txt","a+");
 printf("\nEnter the Books Name : "); 
 fscanf(stdin," %s",b.book_name);
 printf("\nEnter Authors Name : ");
 fscanf(stdin," %s",b.author_name);
 printf("\nEnter Book id : ");
 fscanf(stdin," %s",b.book_id);
 printf("\nEnter Book Cost : ");
 fscanf(stdin,"%d",&b.cost);
 printf("\nEnter the number of copies : ");
 fscanf(stdin,"%d",&b.book_number);
 printf("\nEnter the Subject : ");
 fscanf(stdin," %s",b.subject);
 fprintf(fp1,"\n%25s %25s %25s %25d %25d %25s",b.book_name,b.author_name,b.book_id,b.cost,b.book_number,b.subject);
 printf("\n\n\t\t SUCCUSSFULLY ADDED \n");
 fclose(fp1);
 admin();
}
void edit_existing_book()
{
 FILE *fp1; 
char name[30];
int n;
 FILE *fp2;
 struct student s; 
 struct books b;
 fp2=fopen("Dummy.txt","w");
 fp1=fopen("book1.txt","r");
 printf("\n Enter the name of the book : ");
 scanf("%s",name);
 printf("\nEnter the Number of Copies extra added : ");
 scanf("%d",&n);
 int found=0;
 do
  {
   fscanf(fp1,"%s %s %s %d %d %s",b.book_name,b.author_name,b.book_id,&b.cost,&b.book_number,b.subject);
   if(strcmp(name,b.book_name)==0)
    { b.book_number=b.book_number+n;
     fprintf(fp2,"\n%25s %25s %25s %25d %25d %25s",b.book_name,b.author_name,b.book_id,b.cost,b.book_number,b.subject);
 	found=1;
    }
   else
   {  
   fprintf(fp2,"\n%25s %25s %25s %25d %25d %25s",b.book_name,b.author_name,b.book_id,b.cost,b.book_number,b.subject);
   }
   }while(!feof(fp1));
 if(found!=1)
  printf("\n Book Doesnt Exist "); 
fclose(fp1);
 fclose(fp2);
 remove("book1.txt");
 rename("Dummy.txt","book1.txt");
admin();
}
void delete_book()
{ 
 struct books b;
 FILE *fp1,*fp2;
 char ch; 
int count=0;
 fp1=fopen("book1.txt","r");
 fp2=fopen("Temp_list.txt","w");
 

    char name[30];
    printf("\n Enter the Book ID : ");
    scanf("%s",name);
     do
      {fscanf(fp1,"%s %s %s %d %d %s",b.book_name,b.author_name,b.book_id,&b.cost,&b.book_number,b.subject);
      if(strcmp(name,b.book_id)!=0) 
       { 
 	fprintf(fp2,"\n%25s %25s %25s %25d %25d %25s",b.book_name,b.author_name,b.book_id,b.cost,b.book_number,b.subject);
 	
       }
      else
        count++;
      }while(!feof(fp1));
    if(count)
     printf("\n\t\tSUCCESSFULLY DELETED \n\n\n");
    else
     printf("\n\t\tNO SUCH RECORD EXISTS\n\n\n");
        fclose(fp1);
        fclose(fp2);
        remove("book1.txt");
        rename("Temp_list.txt","book1.txt");

 admin();

}
void view_all_books()
{
 struct books b;
 FILE *fp1;
 fp1=fopen("book1.txt","r");
 
 printf("%20s %20s %20s %20s %20s %20s","Books Name","Author Name","Book ID","Book Cost","Number Of Copies","Subject");
 
do
 { 
 fscanf(fp1,"%s %s %s %d %d %s",b.book_name,b.author_name,b.book_id,&b.cost,&b.book_number,b.subject);
  fprintf(stdout,"\n%20s %20s %20s %20d %20d %20s",b.book_name,b.author_name,b.book_id,b.cost,b.book_number,b.subject);
 
 }while(!feof(fp1));
 fclose(fp1);
 user();


}
void add_student_record()
{
 
  struct student s;
 FILE *fp1;
 fp1=fopen("student2.txt","a+");
char temp[80];
 printf("\nEnter the Student's Name : ");
 fscanf(stdin," %[^\n]s",s.stu_name);
printf("\nEnter Student's Roll Number : ");
   fscanf(stdin," %[^\n]s",s.stu_rollno);
printf("\nEnter Student's Branch : ");
  fscanf(stdin," %[^\n]s",s.stu_branch);
printf("\nEnter Year : "); 
 fscanf(stdin,"%d",&s.year);
printf("\nEnter Semester : ");
  fscanf(stdin,"%d",&s.semester);
 
 
 /*printf("\nEnter the day,month,year: ");
  fscanf(stdin,"%d %d %d",&s.day,&s.month,&s.year);
 */
 s.date=0;
 s.month=0;
 s.year1=0;
 s.number_of_books=0;
 
 
 fprintf(fp1,"\n%20s %20s %20s %d %d %d %d %d %d",s.stu_name,s.stu_rollno,s.stu_branch,s.year,s.semester,s.number_of_books,s.date,s.month,s.year1);
 printf("\n\n\t\t SUCCUSSFULLY ADDED \n");
 fclose(fp1);
 admin();


}
void view_students()
{ 
struct student s;
 FILE *fp1;

 fp1=fopen("student2.txt","r");
 
 printf("\n%20s %20s %20s %20s %20s %20s %10s","Student Name","Roll Number","Branch","Year","Semester","Number Of Books","Date of issue");
 do
 { 
  fscanf(fp1,"%20s %20s %20s %20d %20d %20d %20d %20d %20d",s.stu_name,s.stu_rollno,s.stu_branch,&s.year,&s.semester,&s.number_of_books,&s.date,&s.month,&s.year1);
  fprintf(stdout,"\n%20s %20s %20s %20d %20d %20d %10d/%d/%d",s.stu_name,s.stu_rollno,s.stu_branch,s.year,s.semester,s.number_of_books,s.date,s.month,s.year1);
   
 }while(!feof(fp1));
 fclose(fp1);
 user();
 
}
void edit_student_record()
{
 
 FILE *fp2;
 FILE *fp1;
struct student s;
 fp1=fopen("student2.txt","r");
 fp2=fopen("Dummy.txt","w");
 char rollno[30];
again: 
printf("\nEnter the Roll Number : ");
 scanf("%s",rollno);
 char choice[20];
 printf("\n Enter the Attribute You Want To change (semester)/(branch)");
 scanf("%s",choice);
 int found=1;
 if(fp1==NULL)
  printf("\nFile doesnt Exist ");
 else if(strcmp(choice,"semester")==0)
 {
 do
 { 
  fscanf(fp1,"%20s %20s %20s %20d %20d %20d %d %d %d",s.stu_name,s.stu_rollno,s.stu_branch,&s.year,&s.semester,&s.number_of_books,&s.date,&s.month,&s.year1);
 if(strcmp(rollno,s.stu_rollno)==0)
  {
   s.semester++;
  s.year=s.semester/2+s.semester%2;
  fprintf(fp2,"\n%20s %20s %20s %20d %20d %20d %15d %d %d",s.stu_name,s.stu_rollno,s.stu_branch,s.year,s.semester,s.number_of_books,s.date,s.month,s.year1);
  printf("\n\t\t*****SEMESTER CHANGE*****\n");
  found=0;
  } 
 else
  {
  fprintf(fp2,"\n%20s %20s %20s %20d %20d %20d %15d %d %d",s.stu_name,s.stu_rollno,s.stu_branch,s.year,s.semester,s.number_of_books,s.date,s.month,s.year1);
  }

 }while(!feof(fp1));
}
	else if(strcmp(choice,"branch")==0)
{ char new_branch[30];
   printf("\n Enter the new branch : ");
   scanf("%s",new_branch);
  
do
 { 
  fscanf(fp1,"%20s %20s %20s %20d %20d %20d %d %d %d",s.stu_name,s.stu_rollno,s.stu_branch,&s.year,&s.semester,&s.number_of_books,&s.date,&s.month,&s.year1);
if(strcmp(rollno,s.stu_rollno)==0)
  { 
   strcpy(s.stu_branch,new_branch);
  fprintf(fp2,"\n%20s %20s %20s %20d %20d %20d %15d %d %d",s.stu_name,s.stu_rollno,s.stu_branch,s.year,s.semester,s.number_of_books,s.date,s.month,s.year1);
  printf("\n\t\t*****BRANCH CHANGE*****\n");
  found=0;
  } 
 else
  {
  fprintf(fp2,"\n%20s %20s %20s %20d %20d %20d %15d %d %d",s.stu_name,s.stu_rollno,s.stu_branch,s.year,s.semester,s.number_of_books,s.date,s.month,s.year1);
  }

 }while(!feof(fp1));
}
else
 { printf("\n Enter Proper Attribute : \n");goto again;}
if(found)
printf("\nNo Record Found\n");
 fclose(fp2); 
 fclose(fp1);
 remove("student2.txt");
 rename("Dummy.txt","student2.txt"); 
admin();
}
 
 void delete_student_record()
{
  struct student s;
 FILE *fp1,*fp2;
 char ch; 
int count=0;
 fp1=fopen("student2.txt","r");
 fp2=fopen("Temp_list.txt","w");
 
    char names[30];

    printf("\n Enter Student's Roll Number : ");
    scanf("%s",names);
     do
      {fscanf(fp1,"%s %s %s %d %d %d %d %d %d",s.stu_name,s.stu_rollno,s.stu_branch,&s.year,&s.semester,&s.number_of_books,&s.date,&s.month,&s.year1);
      if(strcmp(names,s.stu_rollno)!=0) 
       {
        
 	fprintf(fp2,"\n%20s %20s %20s %20d %20d %20d %15d %d %d",s.stu_name,s.stu_rollno,s.stu_branch,s.year,s.semester,s.number_of_books,s.date,s.month,s.year1);
 	
       }
     else
      {
      count++;
     }
      }while(!feof(fp1));
    
    if(count)
     printf("\n\t\tSUCCESSFULLY DELETED \n\n\n");
    else
     printf("\n\t\tNO SUCH RECORD EXISTS\n\n\n");
        fclose(fp1);
        fclose(fp2);
        remove("student2.txt");
        rename("Temp_list.txt","student2.txt");

 admin();


}

   void issue_book()
{ struct student s;
  struct books b; 
FILE *fp3;
FILE *fp4;
 int found=0;
 int found1=0;
int found2=0;
  
  char bookid[20];
  char rollno[30];
  int flag=1;
  printf("\n Enter the Roll Number : ");
  scanf("%s",rollno);
  FILE *fp1;
  fp1=fopen("student2.txt","r");
  FILE *fp2; 
  fp2=fopen("book1.txt","r");
  int date,month,year;
 
if(fp1==NULL)
   printf("\n Empty File");
  else
   {
    do{
    fscanf(fp1,"%s %s %s %d %d %d %d %d %d",s.stu_name,s.stu_rollno,s.stu_branch,&s.year,&s.semester,&s.number_of_books,&s.date,&s.month,&s.year1);
    if(strcmp(rollno,s.stu_rollno)==0)
     {
	if(s.number_of_books<1)
          found1=1; 
	found=1; 
	break;
     }
    }while(!feof(fp1));
   if(found1)
     {
      printf("\n Enter the Book ID : ");
      scanf("%s",bookid);
      printf("\n Enter the date month year : ");
      scanf("%d %d %d",&date,&month,&year);
       if(date>30||month>12)
          {flag=0;}
      if(fp2==NULL)
       {
  	printf("\nEmpty file");
       }
      else
 	{
  	 do{
            fscanf(fp2,"%s %s %s %d %d %s",b.book_name,b.author_name,b.book_id,&b.cost,&b.book_number,b.subject);
     		if(strcmp(bookid,b.book_id)==0)
			{  
				if(b.book_number>0)
					found2=1;
			break; 
			}
           }while(!feof(fp2));
        }
      }
  }
fclose(fp1);
fclose(fp2);
fp2=fopen("student2.txt","r");
fp1=fopen("book1.txt","r");
fp3=fopen("dummy_text_1.txt","w");
fp4=fopen("dummy_text_2.txt","w");
if(flag==0)
{printf("\n Enter Appropriate Date ");
admin();}
if(fp4==NULL)
 {
  printf("\n File doesnt exist");
 }
  if(found1&&found2)
   {
    do
    { 
     fscanf(fp1,"%s %s %s %d %d %s",b.book_name,b.author_name,b.book_id,&b.cost,&b.book_number,b.subject);
     if(strcmp(bookid,b.book_id)==0)
	{  
         b.book_number--;
         fprintf(fp3,"\n%20s %20s %20s %20d %20d %20s",b.book_name,b.author_name,b.book_id,b.cost,b.book_number,b.subject);
        }
     else
         fprintf(fp3,"\n%20s %20s %20s %20d %20d %20s",b.book_name,b.author_name,b.book_id,b.cost,b.book_number,b.subject);            
    }while(!feof(fp1));
   do
    {
     fscanf(fp2,"%s %s %s %d %d %d %d %d %d",s.stu_name,s.stu_rollno,s.stu_branch,&s.year,&s.semester,&s.number_of_books,&s.date,&s.month,&s.year1);
    	if(strcmp(rollno,s.stu_rollno)==0)
     	 {       s.date=date;
    		 s.month=month;
		 s.year1=year;
    	   	s.number_of_books++;
    	   	fprintf(fp4,"\n%20s %20s %20s %20d %20d %20d %15d %d %d",s.stu_name,s.stu_rollno,s.stu_branch,s.year,s.semester,s.number_of_books,s.date,s.month,s.year1);
  	 }
    	else
        	fprintf(fp4,"\n%20s %20s %20s %20d %20d %20d %15d %d %d",s.stu_name,s.stu_rollno,s.stu_branch,s.year,s.semester,s.number_of_books,s.date,s.month,s.year1);
    }while(!feof(fp2));

   printf("\n\t\tBOOK ISSUED SUCCESSFULLY\n\n");
   
fclose(fp1);
fclose(fp2);
fclose(fp3);
fclose(fp4);
remove("book1.txt");
rename("dummy_text_1.txt","book1.txt");
remove("student2.txt");
rename("dummy_text_2.txt","student2.txt");


}
  else if(found1==0)
    printf("\n\t\t Haven't Returned the Previous Books !!\n");
  else
    printf("\n\t\t Sorry Stock Ended OR Book Doesnt Exist\n");
  admin();
}
void return_book()  
{ char id[30];
  int days;
  char name_id[30];
 struct student s;
 struct books b;
 int count=0;
 int found=0;
 int flag=1;
 int date,month,year;
 FILE *fp1,*fp2,*fp3,*fp4;
 fp1=fopen("book1.txt","r");
 fp2=fopen("student2.txt","r");
 fp3=fopen("Dummy1.txt","w");
 fp4=fopen("Dummy2.txt","w");
 if(fp3==NULL)
  printf("\n File doesnt exist");
 else if(fp4==NULL)
  printf("\n File doesnt Exist " );
 else
  {
   printf("\n Enter your Roll Number : ");
   scanf("%s",id);
   printf("\n Enter the Books ID : ");
   scanf("%s",name_id);
   printf("\n Enter the Date of Return : ");
   scanf("%d %d %d",&date,&month,&year);
   do
   {
    fscanf(fp1,"%s %s %s %d %d %s",b.book_name,b.author_name,b.book_id,&b.cost,&b.book_number,b.subject);
    if(strcmp(name_id,b.book_id)==0)
     {count=1;
      b.book_number++;
      fprintf(fp3,"%20s %20s %20s %20d %20d %20s",b.book_name,b.author_name,b.book_id,b.cost,b.book_number,b.subject);
     }
    else
      fprintf(fp3,"%20s %20s %20s %20d %20d %20s",b.book_name,b.author_name,b.book_id,b.cost,b.book_number,b.subject);
   }while(!feof(fp1));
    if(count)
     { do
      {
       fscanf(fp2,"%s %s %s %d %d %d %d %d %d",s.stu_name,s.stu_rollno,s.stu_branch,&s.year,&s.semester,&s.number_of_books,&s.date,&s.month,&s.year1);
    	if(strcmp(id,s.stu_rollno)==0)
     	 {     if(s.date>date&&s.month>month||s.year1>year)
                 {flag=0;break;}
          
              	if(year>s.year1)
                {
                  days=(date+(12-s.month)*30+(30-s.date)+(month-1)*30+(year-s.year1)*360);
                }
                else
                { 
                   days=(date-s.date+(month-s.month)*30);
                }
                float fine;
              if(days>45)
                 {fine=(days-45)*0.50;printf("\n\t\t**** FINE OF %f ****\n\t\t****SUCCESSFULLY RETURNED****\n",fine);}
              else
                 printf("\n\t\t**** NO FINE ****\n\t\t****SUCCESSFULLY RETURNED****\n");
          s.date=0;
           s.month=0;
          s.year1=0;
    	   	s.number_of_books--;
    	   	fprintf(fp4,"\n%20s %20s %20s %20d %20d %20d %15d %d %d",s.stu_name,s.stu_rollno,s.stu_branch,s.year,s.semester,s.number_of_books,s.date,s.month,s.year1);
                
  	 }
    	else
        	fprintf(fp4,"\n%20s %20s %20s %20d %20d %20d %15d %d %d",s.stu_name,s.stu_rollno,s.stu_branch,s.year,s.semester,s.number_of_books,s.date,s.month,s.year1);
    }while(!feof(fp2));
 if(flag==0)
  printf("\n Enter appropriate Date ");
  }
 else
  printf("\n BOOK DOESNT EXIST ");

  fclose(fp1);
fclose(fp2);
fclose(fp3);
fclose(fp4);
remove("student2.txt");
rename("Dummy2.txt","student2.txt");
remove("book1.txt");
rename("Dummy1.txt","book1.txt");



}
 
admin();
}
void search_book()
{char ch[4];
 struct books b;
  FILE *fp1;
  fp1=fopen("book1.txt","r");
  
  int flag=1;
  char name[20];
  
  printf("\n Search by name (name) , Search By Author (athr) , Search By Subject (sub) "); 
 scanf("%s",ch);
   if(strcmp(ch,"name")==0)
  {
   printf("\nEnter the name of the book : "); 
   scanf("%s",name);
   printf("\n%20s %20s %20s %20s %20s %20s","Books Name","Author Name","Book ID","Book Cost","Number Of Copies","Subject");
   do{ 
    fscanf(fp1,"%s %s %s %d %d %s",b.book_name,b.author_name,b.book_id,&b.cost,&b.book_number,b.subject);
     if(strcmp(name,b.book_name)==0)
      {flag=0;
       fprintf(stdout,"\n%20s %20s %20s %20d %20d %20s",b.book_name,b.author_name,b.book_id,b.cost,b.book_number,b.subject);
      }
    }while(!feof(fp1));
 if(flag==1)
  printf("\n No Book found With that name "); 
}
  else if(strcmp(ch,"athr")==0)
  { 
   
    printf("\n Enter the authors name : "); 
    scanf("%s",name);
   printf("\n%20s %20s %20s %20s %20s %20s","Books Name","Author Name","Book ID","Book Cost","Number Of Copies","Subject");
    do{ 
    fscanf(fp1,"%s %s %s %d %d %s",b.book_name,b.author_name,b.book_id,&b.cost,&b.book_number,b.subject);
     if(strcmp(name,b.author_name)==0)
      { flag=0;
       fprintf(stdout,"\n%20s %20s %20s %20d %20d %20s",b.book_name,b.author_name,b.book_id,b.cost,b.book_number,b.subject);
      }
    }while(!feof(fp1));
 if(flag==1)
  printf("\n No Book Found With the provided Author Name ");   
} 
   else if(strcmp(ch,"sub")==0)
 {
  
   printf("\n Enter the Subject : "); 
    scanf("%s",name);
 printf("\n%20s %20s %20s %20s %20s %20s","Books Name","Author Name","Book ID","Book Cost","Number Of Copies","Subject");
    do{ 
    fscanf(fp1,"%s %s %s %d %d %s",b.book_name,b.author_name,b.book_id,&b.cost,&b.book_number,b.subject);
     if(strcmp(name,b.subject)==0)
      {flag=0;
       fprintf(stdout,"\n%20s %20s %20s %20d %20d %20s",b.book_name,b.author_name,b.book_id,b.cost,b.book_number,b.subject);
      }
    }while(!feof(fp1));
   if(flag==1)
    printf("\n No Book Of that subject ");
 }

 fclose(fp1);
 user();
}



