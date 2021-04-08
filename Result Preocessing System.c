#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct detail
{
		char name[80];
		int roll;
		char sex[7];
		char address[70];
		char fathersname[70];
		char contact[70];
	};
	
	struct marks
	{
		int roll;
		float english;
		float maths;
		float cprogramming;
		float account;
		float  microprocessor;
		float per;
		char res[10];
		char divison[20];
		float total;
	};

void details();
void entry_marks();
void view();
void line();
void line2();
void update();
void delet();




void line()
{
	int i;
	for (i = 1; i <= 58*4; ++i)
	{
		printf("=");
	}
	printf("\n");
}


void line2()
{
	int i;
	for (i = 1; i <= 58*4; ++i)
	{
		printf("-");
	}
	printf("\n");
}


void main()
{
	int choice;
	line2();
	printf("\t\t\t\t\t\t\t\t\t\t\t>>>>>Welcome to Result processing system for BCA 2nd <<<<<\n");
	line2();
	printf("\n\tChoose any action from the menu given below:\n");
	line();
	printf("\t[1]. To Add Student Details.\n\n");
	printf("\t[2]. TO Enter Marks of Student/s.\n\n");
	printf("\t[3]. TO View Result/details of Student/s.\n\n");
	printf("\t[4]. To Edit the details of student.\n\n");
	printf("\t[5]. To Delete the data of Student/\n\n");
	printf("\t[6]. Exit.\n");
	line2();
	printf("\nEnter your choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			system("cls");
			details();
			break;
		case 2:
			system("cls");
			entry_marks();
			break;
		case 3:
			view();
			break;
		case 4:
			update();
			break;
		case 5:
			delet();
		case 6:
			exit(0);
			break;
		default:
		{
			system("cls");
			printf("\t\tWorng entry please try again\n");
			main();
		}
	}
	getch();
}

void details()
{
	struct detail st;
	int roll,b=0,i,j,a=0;
	char ans,ans1,contact[15];
	FILE *fp,*fp1;
	fp=fopen("student1.dat","ab");
	fp1=fopen("student1.dat","rb");
	if(fp==NULL||fp1==NULL)
	{
		printf("File error...");
		exit(0);
	}
	st.roll=0;
	do
	{
		printf("Enter detail of student to store:\n");
		line();
		printf("Roll = ");
		fflush(stdin);
		scanf("%d",&roll);
		if(a==roll)
		{
			system("cls");
			printf("Already exist! Try next roll number.\n");
			details();
		}
		a=roll;
		while(fread(&st,sizeof(st),1,fp1))
		{
			if(roll==st.roll)
			{
				system("cls");
				printf("Already exist! Try next roll number.\n");
				details();
			}
		}
		st.roll=roll;
		fflush(stdin);
		printf("Name = ");
		gets(st.name);
		printf("Sex = ");
		gets(st.sex);
		printf("Address = ");
		gets(st.address);
		printf("Father name = ");
		gets(st.fathersname);
		wrong:printf("Contact = ");
		gets(contact);
		b=0;
		for (j = 0; contact[j] !='\0'; ++j)
				{
					b++;
				}
		for (i = 0; contact[i] != '\0'; ++i)
		{
			if (contact[i] >= 'a' && contact[i] <= 'z' || contact[i]>='A' && contact[i]<='Z')
			{
				printf("Invalid Contact Number.\n");
				goto wrong;
			}
		}
		if (b!=10)
		{
			printf("Invalid Contact Number.\n");
			goto wrong;
		}
		strcpy(st.contact,contact);
		fwrite(&st,sizeof(st),1,fp);
		fflush(stdin);
		printf("Do U want to add another record[y/n]?: ");
		ans=getchar();
		if(ans=='y'|| ans=='Y')
			system("cls");
	}while(ans=='y'|| ans=='Y');
	fclose(fp);
	system("cls");
	printf("Do you want to go to main menu?:[y/n]\n");
	fflush(stdin);
	ans1=getchar();
	if(ans1=='y'|| ans=='Y')
		{
			system("cls");
			main();
		}
	else
		exit(0);
}


void entry_marks()
{
	int r,i=1;
	char ans;
	int flag=0;
	struct detail st;
	struct marks sm;
	FILE *fp , *fp1;
	fp1=fopen("student1.dat","rb");
	fp=fopen("markentry.dat","ab");
	printf("Enter roll of student to enter mark: ");
	scanf("%d",&r);
	while(fread(&st,sizeof(st),1,fp1))
	{
		 if(r == st.roll)
		 {
		 	flag=1;
		 }
	}
	if(flag==0)
	{
		while(i<=5)
		{
			system("cls");
			printf("Student with roll %d is not in student database.\n------------------------------------------------\nPlease try again.\n\n",r);
			if(i==5)
			{
				system("cls");
				printf("You Entered roll number 5 times. Press any key to exit!!!!!");
				break;
			}
			i++;
			entry_marks();
		}
	}
	else
	{
		sm.roll = r;
		line();
		printf("Enter marks for roll %d:\n",r);
		printf("English= ");
		scanf("%f",&sm.english);
		printf("Microprocessor= ");
		scanf("%f",&sm.microprocessor);
		printf("Account = ");
		scanf("%f",&sm.account);
		printf("C Programming= ");
		scanf("%f",&sm.cprogramming);
		printf("Maths= ");
		scanf("%f",&sm.maths);
		sm.total = sm.english+sm.maths+sm.microprocessor+sm.cprogramming+sm.account;
		sm.per = sm.total/5;
		if(sm.account<40||sm.cprogramming<40||sm.maths<40||sm.microprocessor<40||sm.english<40)
		{
			strcpy(sm.res,"Fail");
			strcpy(sm.divison,"***");
		}
		else
		{
			strcpy(sm.res,"Pass");
			if (sm.per>=80)
			{
				strcpy(sm.divison,"Distinction");
			}
			else if (sm.per>=70)
			{
				strcpy(sm.divison,"First Divison");
			}
			else if (sm.per>=60)
			{
				strcpy(sm.divison,"Second Divison");
			}
			else
			{
				strcpy(sm.divison,"Third Divison");	
			}
		}
		fwrite(&sm,sizeof(sm),1,fp);
	}
	fclose(fp);
	fclose(fp1);
	printf("\n\nDo you want to go to main menu?:[y/n]\n");
	fflush(stdin);
	ans=getchar();
	if(ans=='y'|| ans=='Y')
		{
			system("cls");
			main();
		}
	else
		exit(0);
}



void view()
{
	system("cls");
	struct detail rs;
	struct marks st;
	int choice,r,i,cnt;
	int ans,k;
	FILE *f1,*f;
	do
	{
		f=fopen("student1.dat","rb");
		f1=fopen("markentry.dat","rb");
		printf("1. View individual student details and results\n\n");
		printf("2.  View Results of all students\n\n3. Exit.\n\n Enter your choice: ");
		scanf("%d",&choice);
		system("cls");
		switch(choice)
		{
			case 1: 
				printf("Enter roll of students to view detail: ");
				scanf("%d",&r);
				system("cls");
				printf("students detail with roll %d are:\n",r);
				while(fread(&rs,sizeof(rs),1,f))
				{
					if(r==rs.roll)
					{
						while(fread(&st,sizeof(st),1,f1))
						{
							if(r==st.roll)
							{
								line();
								printf("Roll = %d\n",rs.roll);
								for(i=0; rs.name[i]!='\0'; i++)
								{
									if(i==0)
									{
										if((rs.name[i]>='a' && rs.name[i]<='z'))
											rs.name[i]=rs.name[i]-32;
										continue;
									}
									if(rs.name[i]==' ')
									{
										++i;
										if(rs.name[i]>='a' && rs.name[i]<='z')
										{
											rs.name[i]=rs.name[i]-32;
											continue;
										}
									}
									else
									{
										if(rs.name[i]>='A' && rs.name[i]<='Z')
										rs.name[i]=rs.name[i]+32;
									}
								}
								printf("Name = %s\n",rs.name);
								printf("Sex = %s\n",rs.sex);
								printf("Address = %s\n",rs.address);
								for(i=0; rs.fathersname[i]!='\0'; i++)
								{
									if(i==0)
									{
										if((rs.fathersname[i]>='a' && rs.fathersname[i]<='z'))
											rs.fathersname[i]=rs.fathersname[i]-32;
										continue;
									}
									if(rs.fathersname[i]==' ')
									{
										++i;
										if(rs.fathersname[i]>='a' && rs.fathersname[i]<='z')
										{
											rs.fathersname[i]=rs.fathersname[i]-32;
											continue;
										}
									}
									else
									{
										if(rs.fathersname[i]>='A' && rs.fathersname[i]<='Z')
										rs.fathersname[i]=rs.fathersname[i]+32;
									}
								}
								printf("Father name = %s\n",rs.fathersname);
								printf("Contact = %s\n",rs.contact);
								printf("English = %.2f\n",st.english);
								printf("Micro Processor = %.2f\n",st.microprocessor);
								printf("Account = %.2f\n",st.account);
								printf("C Programming = %.2f\n",st.cprogramming);
								printf("Math = %.2f\n",st.maths);
								printf("Total = %.2f\n",st.total);
								printf("Percentage = %.2f\n",st.per);
								printf("Result = %s\n",st.res);
								printf("Divison = %s\n",st.divison);
							}
								
						}
					}
				}
				fclose(f);
				fclose(f1);
				break;
			case 2:
				cnt=0;
				printf("Result of all Students are:\n");
				line();
				printf("Roll\tName\t\t\tEnglish\t\tMicroprocessor\t\tAccount\t\tMaths\t\tCprogramming\t\tTotal\t\tPercent\t\tResult\t\tDivison\n");
				line2();
				while(fread(&rs,sizeof(rs),1,f))
				{
					fread(&st,sizeof(st),1,f1);
					{
						if(rs.roll==st.roll)
						{	
							cnt++;
							printf("%d\t%-24s%-16.2f%-24.2f%-16.2f%-16.2f%-24.2f%-16.2f%-16.2f%-16s%-16s\n"
									,st.roll,rs.name,st.english,st.microprocessor,st.account,st.maths,st.cprogramming,st.total,st.per,st.res,st.divison);
						}
						
					}
				}
				line();
				printf("Total record = %d\n",cnt);
				fclose(f1);
				fclose(f);
				break;
			case 3:
				exit(0);
		}
	}while(choice > 3||choice==0);
	line2();
	do
	{
		printf("\n\n\nDo you want to go to main menu OR to view result?:\n\n1. Main Menu.\n\n2. Result Processing.\n\n3. Exit.\n");
		fflush(stdin);
		scanf("%d",&ans);
		switch(ans)
		{
			case 1:
				system("cls");
				main();
				break;
			case 2:
				system("cls");
				view();
				break;
			case 3:
				system("cls");
				exit(0);
		}
	}while(ans!=1||ans!=2||ans!=3);
	
}


void update()
{
	int choice,choice1,r,ans;
	float marks;
	char con[50];
	struct detail st;
	struct marks sm;
	FILE *f1,*f2;
	system("cls");
	do
	{
		printf("Do you want to change student details or subject marks?\n\n1. Student Details.\n\n2. Student Subject Marks.\n\n3.Exit.\n");
		scanf("%d",&choice);
		fflush(stdin);
		switch(choice)
		{
			case 1:
				fflush(stdin);
				system("cls");
				f1=fopen("student1.dat","rb");
				printf("Database Contain following roll number:\n");
				printf("Roll\t Name\n");
				line2();
				while(fread(&st,sizeof(st),1,f1))
				{
					printf("%d\t%s\n",st.roll,st.name);
				}
				fclose(f1);
				printf("Enter roll number to update:\n");
				scanf("%d",&r);
				system("cls");
				fflush(stdin);
				do
				{
					printf("Which field do you want to edit?\n");
					printf("1. Name.\n\n2. Sex.\n\n3.Address.\n\n4. Fathersname\n\n5. Contact\n\n6. Exit.\n");
					printf("\nEnter your choice: ");
					scanf("%d",&choice1);
					fflush(stdin);
					switch(choice1)
					{
						case 1:
							system("cls");
							f1=fopen("student1.dat","rb");
							f2=fopen("temp.dat","wb");
							while(fread(&st,sizeof(st),1,f1))	
							{
								if(r==st.roll)
									printf("Old Name=%s\n\n",st.name);
							}
							printf("Enter new Name: ");
							gets(con);
							rewind(f1);
							while(fread(&st,sizeof(st),1,f1))	
							{
								if(r==st.roll)
									strcpy(st.name,con);
								fwrite(&st,sizeof(st),1,f2);
							}
							fclose(f1);
							fclose(f2);
							remove("student1.dat");
							rename("temp.dat","student1.dat");
							printf("\n\nRecord updated sucessfully.");
							getch();
							do
							{
								system("cls");
								printf("1. Main Menu.\n\n2. Update another data.\n\n 3. Exit.\n\n");
								line();
								scanf("%d",&ans);
								switch(ans)
								{
									case 1:
										system("cls");
										main();
										break;
									case 2:
										system("cls");
										update();
										break;
									case 3:
										exit(0);
								}
							}while(ans!=1||ans!=2||ans!=3);
							exit(0);
						case 2:
							system("cls");
							f1=fopen("student1.dat","rb");
							f2=fopen("temp.dat","wb");
							while(fread(&st,sizeof(st),1,f1))	
							{
								if(r==st.roll)
									printf("Old Sex=%s\n\n",st.sex);
							}
							printf("Enter new Sex: ");
							gets(con);
							rewind(f1);
							while(fread(&st,sizeof(st),1,f1))	
							{
								if(r==st.roll)
								{
									printf("Old Sex=%s\n",st.sex);
									strcpy(st.sex,con);
								}
								fwrite(&st,sizeof(st),1,f2);
							}
							fclose(f1);
							fclose(f2);
							remove("student1.dat");
							rename("temp.dat","student1.dat");
							printf("\n\nRecord updated sucessfully.");
							getch();
							do
							{
								getch();
								printf("1. Main Menu.\n\n2. Update another data.\n\n 3. Exit.\n\n");
								line();
								scanf("%d",&ans);
								switch(ans)
								{
									case 1:
										system("cls");
										main();
										break;
									case 2:
										system("cls");
										update();
										break;
									case 3:
										exit(0);
								}
							}while(ans!=1||ans!=2||ans!=3);
							exit(0);
						case 3:
							system("cls");
							f1=fopen("student1.dat","rb");
							f2=fopen("temp.dat","wb");
							while(fread(&st,sizeof(st),1,f1))	
							{
								if(r==st.roll)
									printf("Old Address = %s\n\n",st.address);
							}
							printf("Enter new Address: ");
							gets(con);
							rewind(f1);
							while(fread(&st,sizeof(st),1,f1))	
							{
								if(r==st.roll)
									strcpy(st.address,con);
								fwrite(&st,sizeof(st),1,f2);
							}
							fclose(f1);
							fclose(f2);
							remove("student1.dat");
							rename("temp.dat","student1.dat");
							printf("\n\nRecord updated sucessfully.");
							getch();
							do
							{
								system("cls");
								printf("1. Main Menu.\n\n2. Update another data.\n\n 3. Exit.\n\n");
								line();
								scanf("%d",&ans);
								switch(ans)
								{
									case 1:
										system("cls");
										main();
										break;
									case 2:
										system("cls");
										update();
										break;
									case 3:
										exit(0);
								}
							}while(ans!=1||ans!=2||ans!=3);
							exit(0);
						case 4:
							system("cls");
							f1=fopen("student1.dat","rb");
							f2=fopen("temp.dat","wb");
							while(fread(&st,sizeof(st),1,f1))	
							{
								if(r==st.roll)
									printf("Old Fathers Name = %s\n\n",st.fathersname);
							}
							printf("Enter new Fathers Name: ");
							gets(con);
							rewind(f1);
							while(fread(&st,sizeof(st),1,f1))	
							{
								if(r==st.roll)
									strcpy(st.fathersname,con);
								fwrite(&st,sizeof(st),1,f2);
							}
							fclose(f1);
							fclose(f2);
							remove("student1.dat");
							rename("temp.dat","student1.dat");
							printf("\n\nRecord updated sucessfully.");
							getch();
							do
							{
								system("cls");
								printf("1. Main Menu.\n\n2. Update another data.\n\n 3. Exit.\n\n");
								line();
								scanf("%d",&ans);
								switch(ans)
								{
									case 1:
										system("cls");
										main();
										break;
									case 2:
										system("cls");
										update();
										break;
									case 3:
										exit(0);
								}
							}while(ans!=1||ans!=2||ans!=3);
							exit(0);
						case 5:
							system("cls");
							f1=fopen("student1.dat","rb");
							f2=fopen("temp.dat","wb");
							while(fread(&st,sizeof(st),1,f1))	
							{
								if(r==st.roll)
									printf("Old contact = %s\n\n",st.contact);
							}
							printf("Enter new Contact: ");
							gets(con);
							rewind(f1);
							while(fread(&st,sizeof(st),1,f1))	
							{
								if(r==st.roll)
									strcpy(st.contact,con);
								fwrite(&st,sizeof(st),1,f2);
							}
							fclose(f1);
							fclose(f2);
							remove("student1.dat");
							rename("temp.dat","student1.dat");
							printf("\n\nRecord updated sucessfully.");
							getch();
							do
							{
								system("cls");
								printf("1. Main Menu.\n\n2. Update another data.\n\n 3. Exit.\n\n");
								line();
								scanf("%d",&ans);
								switch(ans)
								{
									case 1:
										system("cls");
										main();
										break;
									case 2:
										system("cls");
										update();
										break;
									case 3:
										exit(0);
								}
							}while(ans!=1||ans!=2||ans!=3);
							exit(0);
						case 6:
							exit(0);
					}
				} while(choice1>6||choice1==0);
				break;
			case 2:
				system("cls");
				printf("Enter roll number to update:\n");
				scanf("%d",&r);
				system("cls");
				do
				{
					printf("Which field do you want to edit?\n");
					printf("1. English\n\n2. Microprocessor\n\n3. Maths\n\n4. C Programming\n\n5. Account\n\n6. Exit.\n\n");
					printf("Enter your choice: ");
					scanf("%d",&choice1);
					fflush(stdin);
					switch(choice1)
					{
						case 1:
							system("cls");
							f1=fopen("markentry.dat","rb");
							f2=fopen("temp.dat","wb");
							while(fread(&sm,sizeof(sm),1,f1))	
							{
								if(r==sm.roll)
									printf("Old English Marks = %.2f\n\n",sm.english);
							}
							printf("Enter new English Marks: ");
							scanf("%d",&marks);
							rewind(f1);
							while(fread(&sm,sizeof(sm),1,f1))	
							{
								if(r==sm.roll)
									sm.english=marks;
								fwrite(&sm,sizeof(sm),1,f2);
							}
							fclose(f1);
							fclose(f2);
							remove("markentry.dat");
							rename("temp.dat","markentry.dat");
							printf("\n\nRecord updated sucessfully.");
							getch();
							do
							{
								system("cls");
								printf("1. Main Menu.\n\n2. Update another data.\n\n 3. Exit.\n\n");
								line();
								scanf("%d",&ans);
								switch(ans)
								{
									case 1:
										system("cls");
										main();
										break;
									case 2:
										system("cls");
										update();
										break;
									case 3:
										exit(0);
								}
							}while(ans!=1||ans!=2||ans!=3);
							exit(0);
						case 2:
							system("cls");
							f1=fopen("markentry.dat","rb");
							f2=fopen("temp.dat","wb");
							while(fread(&sm,sizeof(sm),1,f1))	
							{
								if(r==sm.roll)
									printf("Old Microprocessor Marks = %.2f\n\n",sm.microprocessor);
							}
							printf("Enter new Microprocessor Marks: ");
							scanf("%d",&marks);
							rewind(f1);
							while(fread(&sm,sizeof(sm),1,f1))	
							{
								if(r==sm.roll)
									sm.microprocessor=marks;
								fwrite(&sm,sizeof(sm),1,f2);
							}
							fclose(f1);
							fclose(f2);
							remove("markentry.dat");
							rename("temp.dat","markentry.dat");
							printf("\n\nRecord updated sucessfully.");
							getch();
							do
							{
								system("cls");
								printf("1. Main Menu.\n\n2. Update another data.\n\n 3. Exit.\n\n");
								line();
								scanf("%d",&ans);
								switch(ans)
								{
									case 1:
										system("cls");
										main();
										break;
									case 2:
										system("cls");
										update();
										break;
									case 3:
										exit(0);
								}
							}while(ans!=1||ans!=2||ans!=3);
							exit(0);
						case 3:
							system("cls");
							f1=fopen("markentry.dat","rb");
							f2=fopen("temp.dat","wb");
							while(fread(&sm,sizeof(sm),1,f1))	
							{
								if(r==sm.roll)
									printf("Old Maths Marks = %.2f\n\n",sm.maths);
							}
							printf("Enter new Maths Marks: ");
							scanf("%d",&marks);
							rewind(f1);
							while(fread(&sm,sizeof(sm),1,f1))	
							{
								if(r==sm.roll)
									sm.maths=marks;
								fwrite(&sm,sizeof(sm),1,f2);
							}
							fclose(f1);
							fclose(f2);
							remove("markentry.dat");
							rename("temp.dat","markentry.dat");
							printf("\n\nRecord updated sucessfully.");
							getch();
							do
							{
								system("cls");
								printf("1. Main Menu.\n\n2. Update another data.\n\n 3. Exit.\n\n");
								line();
								scanf("%d",&ans);
								switch(ans)
								{
									case 1:
										system("cls");
										main();
										break;
									case 2:
										system("cls");
										update();
										break;
									case 3:
										exit(0);
								}
							}while(ans!=1||ans!=2||ans!=3);
							exit(0);
						case 4:
							system("cls");
							f1=fopen("markentry.dat","rb");
							f2=fopen("temp.dat","wb");
							while(fread(&sm,sizeof(sm),1,f1))	
							{
								if(r==sm.roll)
									printf("Old C Programming Marks = %.2f\n\n",sm.cprogramming);
							}
							printf("Enter new C Programming Marks: ");
							scanf("%d",&marks);
							rewind(f1);
							while(fread(&sm,sizeof(sm),1,f1))	
							{
								if(r==sm.roll)
									sm.cprogramming=marks;
								fwrite(&sm,sizeof(sm),1,f2);
							}
							fclose(f1);
							fclose(f2);
							remove("markentry.dat");
							rename("temp.dat","markentry.dat");
							printf("\n\nRecord updated sucessfully.");
							getch();
							do
							{
								system("cls");
								printf("1. Main Menu.\n\n2. Update another data.\n\n 3. Exit.\n\n");
								line();
								scanf("%d",&ans);
								switch(ans)
								{
									case 1:
										system("cls");
										main();
										break;
									case 2:
										system("cls");
										update();
										break;
									case 3:
										exit(0);
								}
							} while(ans!=1||ans!=2||ans!=3);
							exit(0);
						case 5:
							system("cls");
							f1=fopen("markentry.dat","rb");
							f2=fopen("temp.dat","wb");
							while(fread(&sm,sizeof(sm),1,f1))	
							{
								if(r==sm.roll)
									printf("Old Account Marks = %.2f\n\n",sm.account);
							}
							printf("Enter new Account Marks: ");
							scanf("%d",&marks);
							rewind(f1);
							while(fread(&sm,sizeof(sm),1,f1))	
							{
								if(r==sm.roll)
									sm.account=marks;
								fwrite(&sm,sizeof(sm),1,f2);
							}
							fclose(f1);
							fclose(f2);
							remove("student1.dat");
							rename("temp.dat","markentry.dat");
							printf("\n\nRecord updated sucessfully.");
							getch();
							do
							{
								system("cls");
								printf("1. Main Menu.\n\n2. Update another data.\n\n 3. Exit.\n\n");
								line();
								scanf("%d",&ans);
								switch(ans)
								{
									case 1:
										system("cls");
										main();
										break;
									case 2:
										system("cls");
										update();
										break;
									case 3:
										exit(0);
								}
							} while(ans!=1||ans!=2||ans!=3);
							exit(0);
						case 6:
							exit(0);
					}
				} while(choice1!=1||choice1!=2||choice1!=3||choice1!=4||choice1!=5||choice1!=6);
				break;
			case 3:
				exit(0);
		}
		system("cls");
		printf("\tWrong choice please try again: \n\n");
	}while(choice!=1||choice!=2||choice!=3);
}

void delet()
{
	FILE *f1,*f2,*f3,*f4;
	struct detail st;
	struct marks ms;
	int r,flag=0;
	f1=fopen("student1.dat","rb");
	f2=fopen("temp.dat","wb");
	system("cls");
	printf("Database Contain following roll number:\n");
	printf("Roll\t Name\n");
	line2();
	while(fread(&st,sizeof(st),1,f1))
	{
		printf("%d\t%s\n",st.roll,st.name);
	}
	printf("Enter roll to delete record of student: ");
	scanf("%d",&r);
	rewind(f1);
	while(fread(&st,sizeof(st),1,f1))	
	{
		if(r==st.roll)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("student with Roll no %d do not exit.",r);
		return;
	}
	rewind(f1);
	while(fread(&st,sizeof(st),1,f1))	
	{
		if(r==st.roll)
			continue;
		fwrite(&st,sizeof(st),1,f2);
	}
	fclose(f1);
	fclose(f2);
	remove("student1.dat");
	rename("temp.dat","student1.dat");
	f3=fopen("markentry.dat","rb");
	f4=fopen("temp1.dat","wb");
	flag=0;
	while(fread(&ms,sizeof(ms),1,f3))	
	{
		if(r==ms.roll)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("student with Roll no %d do not exit.",r);
		return;
	}
	rewind(f3);
	while(fread(&ms,sizeof(ms),1,f3))	
	{
		if(r==ms.roll)
			continue;
		fwrite(&ms,sizeof(ms),1,f4);
	}
	fclose(f3);
	fclose(f4);
	remove("markentry.dat");
	rename("temp1.dat","markentry.dat");
	printf("\nRecord Deteted Sucessfully!!!!\n");
	line();
}
