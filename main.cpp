#include<iostream>
#include<string.h>
using namespace std;
typedef struct node
{
 char row_no;
 int seat_no,pin;
 char book;
 struct node *next,*prev;
}node;


struct table
{
    public:
    int p;
    int length;
    int start;
}t1[20];


class dcll
 {
  public:
  node *hn;
  dcll()
   {
     hn=NULL;
   }
  public:
  void create()
   {
    node *nn,*cn;
    int j=1;
    volatile int k=2;
    char c ='A';
    do
    {
      int i=1;
     do
     {
       k=(k*k)/10+100-k/2;
       nn=new node();
       nn->next=nn->prev=NULL;
       nn->row_no=c;
       nn->seat_no=i;
       nn->pin=k;
       nn->book='e';
       if(hn==NULL)
        {
         hn=nn;
         nn->next=nn->prev=hn;
        }
      else
       {
         cn=hn;
        while(cn->next!=hn)
          cn=cn->next;

          cn->next=nn;
          nn->prev=cn;
          nn->next=hn;
          hn->prev=nn;
       } 
      i++;
     }while(i<=7);
     j++;
     c++;
    }while(j<=10);
   }
  public:
  void display();
  void platinum_indexed(int i);
  void platinum_continuous(int i);
  void gold(int i);
  void regist(int c,char n,int no);
  void silver(int i);
  void book_seat();
  void cancle();
};

void dcll ::display()
{
  node *cn;
  cn=hn;
  cout<<"------------------------------------------------------------------\n";
  cout<<"|                            Platinum                            |\n";
  while(cn->next!=hn)
   {
    if((cn->prev)->row_no!=cn->row_no)
      cout<<"| ";
    cout<<cn->row_no;
    cout<<cn->seat_no;
    if(cn->book=='e')
      cout << "\033[32;40m -> e  \033[0m";  //green text with black background
    else
      cout << "\033[1;31;43m -> b  \033[0m";  //red text
    if((cn->next)->row_no!=cn->row_no)
      cout<<"|\n";
    if(cn->row_no=='C'&&cn->seat_no==7)
     {
       cout<<"------------------------------------------------------------------\n";
       cout<<"|                             gold                               |\n";
      }
     if(cn->row_no=='H'&&cn->seat_no==7)
      {
       cout<<"------------------------------------------------------------------\n";
       cout<<"|                            Silver                              |\n";
      }
      cn=cn->next;
    }
   cout<<cn->row_no;
   cout<<cn->seat_no;
   if(cn->book=='e')
       cout << "\033[32;40m -> e \033[0m";  //green text with black background

   else
       cout << "\033[1;31;43m -> b  \033[0m";  //red text
       cout<<"|\n";

       cout<<"------------------------------------------------------------------\n\n";
       cout<<"\033[1;33;49mPLATINUM-> 150              GOLD-> 100                  SILVER->60\033[0m\n";
}



void display1(int pin1,int n,int x1)
 {
     table t1[20];
     int flag;
     for(int i=0;i<20;i++)
     {
       if(t1[i].p==0)
        {
            t1[i].p=pin1;
            t1[i].length=n;
            t1[i].start=x1;
            break;
        }
        
        
     }
     int k=0;
     cout<<"pin"<<"    "<<"no of people"<<"    "<<"start"<<endl;
   while(t1[k].p!=0)
   {
       cout<<t1[k].p<<"    "<<t1[k].length<<"    "<<t1[k].start<<endl;
       k++;
   }
   
 }

 void dcll::regist(int cnt,char row,int n)
{
    
     node *cn;
     cn=hn;
      int x=cnt-n+1;
      int x1=cnt-n+1;
      int pin1=rand()+1;
  while(cn->next!=hn)
  {
    if(cn->row_no==row && cn->seat_no==x && x<=cnt)
    {
        cn->book='b';
        cn->pin=pin1;
        x++;
        if(cnt>7)
         row++;
       
    }
    cn=cn->next;
  }
  display1(pin1,n,x1);
}





void dcll:: platinum_indexed(int n)
{
  int i=1;
  node *cn;
  cn=hn;
  do
  {
     
     if(cn->book=='e' && cn->row_no<='C')
      {
          i++;
          cn->book='b';
          cn=cn->next;
      }
      else
      {
        cn=cn->next;
      }
      if(cn->row_no>'C')
      {
          cout<<"no seats avaliable in platinum";
          
          
      }
  }
  while(cn->next!=hn && i<=n);
  
   
}

void dcll::platinum_continuous(int n)
{
    
    
    node *cn;
    cn=hn;
    int flag=0;
    int i=0;
    int cnt=0;
    char row;
    do
    {
     
     if(cn->book=='e' && cn->row_no<='C')
      {
          i++;
          cnt++;
          cn=cn->next;
      }
      if(cn->book=='b')
      {
        i=0;
        cnt++;
        cn=cn->next;
      }
      if(cn->row_no>'C')
      {
          cout<<"no seats avaliable in platinum";
          break;
      }
  }
  while(cn->next!=hn && i<n);
 
row='A';
if(cnt>7 && cnt<=14)
  {
      cnt=cnt%7;
      row='B';
  }
  else if(cnt>14 && cnt<=21)
  {
      cnt=cnt%7;
      row='C';
  }
 regist(cnt,cn->row_no,n);
   
}

void dcll:: book_seat()
{
     int n;
     int pref;
    cout<<"enter number of seats"<<endl;
    cin>>n;
    cout<<"enter preference indexed or continuous"<<endl;
    cin>>pref;
    if(pref==2)
    {
    platinum_continuous(n);
    }
    else
     {
         platinum_indexed(n);
     }
    
}

void dcll:: cancle()
{
   char row,ch;
   int seat,pin;
   node *cn;
   do
    {
     ch='a';
     cn=hn;
     cout<<"SEAT NUMBRE :";
     cin>>row>>seat;
     cout<<"PIN :";
     cin>>pin;
     while(cn->next!=hn)
      {
       if(cn->row_no==row && cn->seat_no==seat && cn->pin==pin)
         {
             cout<<"Are you sure u want to cancle the Seat (y/n) ";
             char c;
             cin>>c;
             if(c=='y'||c=='Y')
              {
                cout<<"SEAT CANCELED SUCCESFULLY!\n";
                cn->book='e';
              }
          }
       else if(cn->row_no==row && cn->seat_no==seat && cn->pin!=pin)
             {
               cout<<"invalid SEAT NUMBER && PIN combination!!!!\n";
             }
          cn=cn->next;
      }
      cout<<"\n\nPRESS 1 To Check Seat Status\n"; 
      cout<<"PRESS 2 To Cancle More Tickets\n"; 
      cout<<"PRESS 3 To Exit CANCELATION PORTAL\n";
      cout<<"\ninput: ";
      cin>>ch;
      if(ch==1)
        display();
    }while(ch=='2');
}


int main()
{

  for(int i=0;i<20;i++)
  {
      t1[i].p=0;
  }
  
  dcll o;
  int ch; 
  char c;
  cout<<"\n\n\n";
  cout<<"                 @@@@@@   Cinemax  @@@@@@\n";
  cout<<"                vvvvvv ARRANGEMENT vvvvvv\n\n";
  o.create();
  o.display();

  do
   {
    cout<<"\n\n\n";
    cout<<"PRESS 1-> BOOK TICKETS\n";
    cout<<"PRESS 2-> CANCLE TICKETS\n";
    cout<<"PRESS 3-> EXIT\n";
    cout<<"\ninput: ";
    cin>>ch;
    switch(ch)
      {
        case 1:
         o.book_seat();
         o.display();
          break;
        case 2:
         o.cancle();
         o.display();
         break;
       }
    if(ch!=3)
    {
      cout<<"\n\nPRESS 1 To Main Menu\n";
      cout<<"PRESS 2 To Exit CINEMAX PORTAL\n";
      cout<<"\ninput: ";
      cin>>c;
    }
  }while(c=='1');
  cout<<"\n\n\n";
  return 0;
}





















