#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream.h>
#include<iomanip.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>
#include<time.h>
#define hel "student.txt"
#define mess "mess.txt"
#define mfil "bill.txt"
fstream sf;
fstream mf;
fstream bf;
void effects()
{
	int i,val=80,p=120;
	clrscr();
	for(i=0;i<2;i++){
	clrscr();
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t  | | | |\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\t\t\t\t  ~~~~~~~\n";
	delay(val*2);
	clrscr();
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t    | | |\n";
	cout<<"\t\t\t\t  | \n";
	cout<<"\n";
	cout<<"\t\t\t\t  ~~~~~~~\n";
	delay(val*2);
	clrscr();
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t      | |\n";
	cout<<"\t\t\t\t    |\n";
	cout<<"\t\t\t\t  |\n";
	cout<<"\t\t\t\t  ~~~~~~~\n";
	delay(val*2);
	clrscr();
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t        |\n";
	cout<<"\t\t\t\t  |   |\n";
	cout<<"\t\t\t\t    |\n";
	cout<<"\t\t\t\t  ~~~~~~~\n";
	delay(val*2);
	clrscr();
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t  |      \n";
	cout<<"\t\t\t\t    |   |\n";
	cout<<"\t\t\t\t      |\n";
	cout<<"\t\t\t\t  ~~~~~~~\n";
	delay(val*2);
	clrscr();
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t  | |    \n";
	cout<<"\t\t\t\t       |  \n";
	cout<<"\t\t\t\t        |\n";
	cout<<"\t\t\t\t  ~~~~~~~\n";
	delay(val*2);
	clrscr();
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t  | | |  \n";
	cout<<"\t\t\t\t        |  \n";
	cout<<" \n";
	cout<<"\t\t\t\t  ~~~~~~~\n";
	delay(val*2);
	clrscr();
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t  | | | |\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\t\t\t\t  ~~~~~~~\n";
	delay(val*2);
	}
	delay(val);
	clrscr();
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t\t		 hos\r";
	delay(p);
	cout<<"\t\t	        hoste\r";
	delay(p);
	cout<<"\t\t	       hostel m\r";
	delay(p);
	cout<<"\t\t	      hostel mana\r";
	delay(p);
	cout<<"\t\t	     hostel manage\r";
	delay(p);
	cout<<"\t\t	    hostel manageme\r";
	delay(p);
	cout<<"\t\t	   hostel management\r";
	delay(p);
	cout<<"\t\t	  hostel management s\r";
	delay(p);
	cout<<"\t\t	 hostel management sys\r";
	delay(p);
	cout<<"\t\t     hostel management syste\r";
	delay(p);
	cout<<"\t\t      hostel management system\r";
	delay(1000);
}
int opener(fstream &ifile,char *fn,int mode,int p,int s)
{
	int i;
	ifile.open(fn,ios::in);
	if(!ifile)
	{
	  ifile.open(fn,mode);
	  ifile.fill('*');
	  for(i=0;i<p;i++)
	  ifile<<setiosflags(ios::left)<<setw(s)<<"*"<<endl;
	  return 1;
	}else {
		ifile.close();
		ifile.open(fn,mode);
		return 0;
	      }
}
class student{
private:
	char id[15],name[20],clg[5],num[11],place[10],fat[20],ro[5],ser[4];
	int room,serial;
	int year,month;
public:
	void cs();
	void display();
	int verify(char *);
	void pack();
	int roomcheck();
	void showrooms();
	int namromch();
	void disp();
	int del();
	void inbill();
	void bill();
	char* getserial(int,int);
	void pay();
};
void student::pay(){
     char id1[15],mon[5],req[15],req2[15],temp2[70];
     int l1,i,p1=0,flag=0;
     cout<<"enter the usn to pay bill for:";
     cin>>id1;
     cout<<"enter first three character of the month to pay(ex-jun,jul,feb):";
     cin>>mon;
     strcpy(mon,strupr(mon));
     while(!(strcmp(mon,"JAN")==0 || strcmp(mon,"FEB")==0 || strcmp(mon,"MAR")==0 || strcmp(mon,"APR")==0 || strcmp(mon,"MAY")==0 || strcmp(mon,"JUN")==0 || strcmp(mon,"JUL")==0 || strcmp(mon,"AUG")==0 || strcmp(mon,"SEP")==0 || strcmp(mon,"OCT")==0 || strcmp(mon,"NOV")==0 || strcmp(mon,"DEC")==0))
	  {
		printf("invalid month code \n");
		cin>>mon;
	  }
	l1=strlen(id1);
	for(i=5;i<(l1-1);i++)
	{
		req[i-5]=id1[i];
	}
	req[i]='\0';
	req2[0]=id1[l1-1];
	req2[1]='\0';
	l1=atoi(req);
	while(p1<3){
		bf.seekg((122*p1*50)+((l1-1)*122),ios::beg);
		i=bf.tellg();
		bf.getline(temp2,15,'|');
		if(strcmp(temp2,id1)==0){
			bf.getline(temp2,60,'#');
			bf.seekg(-1,ios::cur);
			bf<<"|"<<mon<<"#";
			flag++;
			break;
		}
		p1++;
	}
	if(flag==0)
		cout<<"record not found\n";
	else printf("DONE\N");
     getch();
     display();
}
char* timer()
{
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,sizeof(buffer),"%d-%m-%Y",timeinfo);
  return buffer;
}
void student::bill(){
	int i;
	char temp2[122];
	clrscr();
	cout<<endl<<endl;
	textcolor(GREEN);
	for(i=0;i<80;i++)
	cprintf("%c",220);
	textcolor(WHITE);
	for(i=0;i<150;i++)
	{
		bf.seekp(i*122,ios::beg);
		bf.getline(temp2,70,'#');
		if(temp2[0]!='*')
			cout<<temp2<<endl<<endl;
	}
       textcolor(GREEN);
	for(i=0;i<80;i++)
	cprintf("%c",220);
	textcolor(WHITE);
	getch();
	display();
}
void student::inbill(){
	int  p1=0,flag=0,l1,i;
	char temp2[100],id1[15],req[15],req2[15];
	cout<<"enter the id to display its bill:";
	cin>>id1;
	l1=strlen(id1);
	for(i=5;i<(l1-1);i++)
	{
		req[i-5]=id1[i];
	}
	req[i]='\0';
	req2[0]=id1[l1-1];
	req2[1]='\0';
	l1=atoi(req);
	textcolor(GREEN);
	for(i=0;i<80;i++)
	cprintf("%c",220);
	textcolor(WHITE);
	cout<<"mess bill for "<<id1<<endl;
	textcolor(GREEN);
	for(i=0;i<80;i++)
	cprintf("%c",45);
	textcolor(WHITE);
	while(p1<3){
		bf.seekg((122*p1*50)+((l1-1)*122),ios::beg);
		i=bf.tellg();
		bf.getline(temp2,15,'|');
		if(strcmp(temp2,id1)==0){
			bf.getline(temp2,100,'#');
			cout<<temp2<<endl;
			flag++;
		}
		p1++;
	}
	if(flag==0)
		cout<<"record not found\n";
	textcolor(GREEN);
	for(i=0;i<80;i++)
	cprintf("%c",220);
	textcolor(WHITE);
	getch();
	display();
}
char* student::getserial(int ser,int ro)
{
	char ser1[10],ser2[10],temp[60];
	int k,s,r,t,l,m;
	k=sf.tellg();
	l=mf.tellg();
	m=bf.tellg();
	sf.seekg((ro-1)*122,ios::beg);
	if(ser==1){
		sf.getline(temp,20,'|');
		sf.getline(ser1,10,'|');
		ser1[0]=ser1[strlen(ser1)-1];
		ser1[1]='\0';
		s=atoi(ser1);
		r=s+ser;
		if(r==4)
			r=1;
		itoa(r,ser2,10);
		sf.seekg(k,ios::beg);
		}
	else{
	   if(ser==2){
		sf.getline(temp,20,'|');
		sf.getline(ser1,10,'|');
		ser1[0]=ser1[strlen(ser1)-1];
		ser1[1]='\0';
		s=atoi(ser1);
		sf.getline(temp,60,'#');
		sf.getline(temp,20,'|');
		sf.getline(ser1,10,'|');
		ser1[0]=ser1[strlen(ser1)-1];
		ser1[1]='\0';
		r=atoi(ser1);
		t=(s+r)%4;
		if(t==0)
			t=2;
		itoa(t,ser2,10);
		sf.seekg(k,ios::beg);
		}else itoa(1,ser2,10);
	}
	sf.seekp(k,ios::beg);
	mf.seekp(l,ios::beg);
	bf.seekp(m,ios::beg);
       return ser2;
}
int student::del(){
	char id2[10],cnt[4],req[50],req2[11],id1[15],temp2[122],roo[4];
	int x,i,l1,l2,p1,p2=0,b1;
	fflush(stdin);
	cout<<"enter the id to delete:";
	gets(id1);
	if(id1[0]=='\0'){
	cout<<"pressing enter will stop the operation enter the id to delete:";
	gets(id1);
	if(id1[0]=='\0')
		return 0;
	}
	l1=strlen(id1);
	for(i=5;i<(l1-1);i++)
	{
		req[i-5]=id1[i];
	}
	req[i]='\0';
	req2[0]=id1[l1-1];
	req2[1]='\0';
	l1=atoi(req);
	mf.seekg(12*(l1-1),ios::beg);
	mf.getline(roo,5,'|');
	strcpy(temp2,roo);
	mf.getline(cnt,4,'*');
	sf.seekg(122*(l1-1),ios::beg);
	p1=b1=atoi(cnt);
	strcat(roo,"|");
	itoa(b1-1,req,10);
	strcat(roo,req);
	while(p1){
		i=sf.tellg();
		sf.getline(temp2,6,'|');
		sf.getline(id2,14,'|');
		if(strcmp(id1,id2)==0){
			sf.getline(temp2,60,'#');
			x=strlen(temp2)+strlen(id1)+2;
			sf.getline(temp2,122,'\n');
			sf.seekg(i,ios::beg);
			sf<<temp2;
			for(i=0;i<x;i++)
				sf<<"*";
			mf.seekg(12*(l1-1),ios::beg);
			mf<<roo;
			p2=1;
			break;
		}else {
			sf.getline(temp2,60,'#');
		}
		p1--;
	}
	p1=0;
	while(p1<3){
		bf.seekg((122*p1*50)+((l1-1)*122),ios::beg);
		i=bf.tellg();
		bf.getline(temp2,15,'|');
		if(strcmp(temp2,id1)==0){
			bf.seekg(i,ios::beg);
			bf<<"********************************************************************";
		}
		p1++;
	}
	return p2;
}
int student::namromch(){
	int i,count,stat=0;
	 char temp[60],temp2[10],ro1[5],name1[20],clg1[10];
	for(i=0;i<150;i++){
		sf.seekg(122*i,ios::beg);
		mf.seekg(12*i,ios::beg);
		mf.getline(temp,10,'|');
		mf.getline(temp,10,'\n');
		count=atoi(temp);
	       while(count)
		{
			fflush(stdin);
			stat=0;
			sf.getline(ro1,25,'|');
			sf.getline(temp,25,'|');
			sf.getline(name1,25,'|');
			sf.getline(clg1,25,'|');
		       sf.getline(temp,60,'#');
		       itoa(room,temp,10);
		       if(strcmp(name,name1)==0){
			   if(strcmp(clg,clg1)==0||strcmp(temp,ro1)==0)
				stat++;
			   }
		       if(stat>=1){
				printf("this name exist either in the clg or in the room\n");
				return 0;
		       }
		count--;
		}
		}
	fflush(stdin);
	return 1;
}
int student::verify(char * s)
{
	s=strupr(s);
	if(!(strcmp(s,"RNS")))
		return 1;
	else if(!(strcmp(s,"SJB")))
		return 1;
	else if(!(strcmp(s,"BGS")))
		return 1;
	else    return 0;
}
void student::pack(){
	char temp[10],temp2[10],temp3[10];
	char buffer[100],buf2[100];
	int ss,flag=0,i;
	fflush(stdin);
	sf.seekg((122*(room-1)),ios::beg);
	bf.seekp((122*(room-1)),ios::beg);
	mf.seekg(12*(room-1),ios::beg);
	mf.getline(temp,4,'|');
	strcpy(buffer,temp);
	mf.getline(temp,4,'*');
	serial=atoi(temp);
	ss=serial+1;
	strcpy(temp,getserial(serial,room));
	mf.seekg(12*(room-1),ios::beg);
	mf.getline(temp2,4,'|');
	strcat(temp2,"|");
	itoa(ss,temp3,10);
	strcat(temp2,temp3);
	mf.seekp(12*(room-1),ios::beg);
	mf<<temp2<<setw(10);
	strcat(id,temp);
	strcat(buffer,"|");
	strcat(buffer,id);
	strcat(buffer,"|");
	strcat(buffer,name);
	strcat(buffer,"|");
	strcat(buffer,clg);
	strcat(buffer,"|");
	strcat(buffer,fat);
	strcat(buffer,"|");
	strcat(buffer,num);
	strcat(buffer,"#");
	while(serial){
	sf.getline(buf2,60,'#');
	sf.seekp(sf.tellg(),ios::beg);
	serial--;
	}
	strcpy(buf2,id);
	strcat(buf2,"|");
	strcat(buf2,"#");
	sf<<buffer;
	bf.seekg(0,ios::beg);
	for(i=0;i<3;i++)
	{
	    bf.seekg((122*50*i)+(122*(room-1)),ios::beg);
	    cout<<(122*50*i)+(122*(room-1))<<endl;
	    bf.getline(temp2,10,'\n');
	    if(temp2[0]=='*'){
		flag=1;
		break;
	    }
	}
	cout<<flag;
	cout<<"temp"<<temp2[0];
	bf.seekp((122*50*i)+(122*(room-1)),ios::beg);
	if(flag==1)
		bf<<buf2;
	getch();
}
int student::roomcheck(){
	int ro;
	char temp[6];
	if(room<=50){
		mf.seekg(12*(room-1),ios::beg);
		mf.getline(temp,4,'|');
		mf.getline(temp,4,'\n');
		ro=atoi(temp)+1;
		if(ro<=3)
			return 1;
		else
			return 0;
	}else return 0;
}
void student::showrooms(){
	int ro,i;
	char avail[3],temp[4];
	for(i=0;i<50;i++){
      mf.seekg(i*12,ios::beg);
      mf.getline(avail,4,'|');
      mf.getline(temp,3,'\n');
      ro=atoi(temp)+1;
      if(ro<=3)
	cprintf("%s",avail);
      cout<<"\t";
      }
}
void student::disp(){
	char ro1[5],ser1[4],id1[15],name1[20],fat1[20],num1[14],clg1[5],temp[6],temp2[6];
	int i,j=0,count=0;
	clrscr();
	fflush(stdin);
	cout<<endl<<endl;
	textcolor(GREEN);
	for(i=0;i<80;i++)
	cprintf("%c",220);
	textcolor(WHITE);
	cout<<setw(10)<<"id"<<setw(18)<<"name"<<setw(10)<<"college"<<setw(7)<<"room"<<setw(15)<<"father"<<setw(14)<<"number"<<endl;
	textcolor(GREEN);
	for(i=0;i<80;i++)
	cprintf("%c",45);
	textcolor(WHITE);
	for(j=0;j<50;j++){
		fflush(stdin);
		mf.seekg(j*12,ios::beg);
		sf.seekg(j*122,ios::beg);
		mf.getline(temp,4,'|');
		mf.getline(temp2,4,'*');
		count=atoi(temp2);
		//i=atoi(temp);
		while(count){
		sf.getline(ro1,5,'|');
		sf.getline(id1,15,'|');
		sf.getline(name1,20,'|');
		sf.getline(clg1,5,'|');
		sf.getline(fat1,15,'|');
		sf.getline(num1,14,'#');
		cout<<setw(10)<<id1<<setw(18)<<name1<<setw(10)<<clg1<<setw(7)<<ro1<<setw(15)<<fat1<<setw(14)<<num1<<endl;
		count--;
		}
	}
	textcolor(GREEN);
	for(i=0;i<80;i++)
	cprintf("%c",220);
	textcolor(WHITE);
	getch();
	display();
}
void student::cs(){
	char ro[5];
	fflush(stdin);
	textcolor(GREEN);
	//colfact=1;
	year=atoi(&timer()[6]);
	while(1){
	cprintf("enter student name:");gets(name);
	if(name[0]=='\0'){
	 cout<<"if you want to exit press ENTER else enter the name";
	 gets(name);
	 if(name[0]=='\0')
		return;
	}
	while(1){
	cprintf("enter college code:");gets(clg);
	if(verify(clg)==0){
		cout<<"invalid code use following\n";
		cout<<"RNS BGS SJB\n";
		}else break;
		}
	while(1){
		cprintf("enter room number(1-50 only):");scanf("%d",&room);
		fflush(stdin);
		if(roomcheck()==0){
			cout<<"room is either full or not available\n availability";
			showrooms();
		}else break;
	}
	if(namromch()==0)
	{
		cout<<"this name exist in this room please enter different or full name\n";
	}else break;
	}
	cprintf("enter fathers name:");gets(fat);
	cprintf("phone number:");gets(num);
	year=year%100;
	itoa(year,id,10);
	itoa(room,ro,10);
	strcat(id,clg);
	strcat(id,ro);
	pack();
	textcolor(WHITE);
	display();
}
void student::display(){
	int i=0;
	char v;
	clrscr();
	textcolor(GREEN);
	v=(char)177;
	cout<<endl<<endl;
	for(i=0;i<80;i++)
	cprintf("%c",220);
	cprintf("%c",v);
	cout<<setw(18)<<"  1.DISPLAY	      		 2.INSERT             	  3.DELETE STUDENT"<<setw(5)<<"";
	cprintf("%c",v);
	cprintf("%c",v);
	cout<<setw(18)<<"  4.INDIVIDUAL BILL             5.all mess bills  	  6.pay mess bill "<<setw(5)<<"";
	cprintf("%c",v);
	for(i=0;i<80;i++)
	cprintf("%c",223);
	textcolor(WHITE);
	}
void main()
{
	int op,sp,i;
	char ss[10],as[10];
	clrscr();
	effects();
	clrscr();
	textcolor(WHITE);
	sp=opener(sf,hel,ios::ate|ios::out|ios::in,150,120);
	sp=opener(bf,mfil,ios::ate|ios::out|ios::in,150,120);
	sp=opener(mf,mess,ios::ate|ios::out|ios::in,150,10);
	if(sp==1)
	{
		mf.seekp(0,ios::beg);
		fflush(stdin);
		for(i=0;i<50;i++){
			itoa((i+1),ss,10);
			strcat(ss,"|");
			itoa(0,as,10);
			strcat(ss,as);
			mf<<setw(10)<<ss<<endl;
			}
	}
	student s;
	s.display();
	while(1)
	{
		cout<<"enter your choice:";
		scanf("%d",&op);
		switch(op)
		{
			case 1:s.disp();
				break;
			case 2:s.cs();
				cprintf("success\n");
				break;
			case 3:sp=s.del();
				if(sp==0)
					cout<<"unsuccessfull atempt\n";
				else cout<<"done\n";
				getch();
				break;
			case 4:s.inbill();
				break;
			case 5:s.bill();
				break;
			case 6:s.pay();
				break;
			default:exit(0);
		}
	}
}