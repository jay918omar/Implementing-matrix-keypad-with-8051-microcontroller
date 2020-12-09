#include<reg51.h>
void lcd_init(void);
void writecmd(int);
void writedata(char);
void delay(int);
void check_col1();
void check_col2();
void check_col3();
sbit RS = P3^0;
sbit E  = P3^1;
sbit row1=P1^0;
sbit row2=P1^1;
sbit row3=P1^2;
sbit row4=P1^3;
sbit col1=P1^4;
sbit col2=P1^5;
sbit col3=P1^6;
int i=0;

void delay(int a)               //Delay function
{
int i;
for(i=0;i<a;i++);  

}

void writecmd(int z)        //command function
{

RS = 0;            
P2 = z;                                //Data transfer
E  = 1;            
delay(150);
E  = 0;            
delay(150);
}

void lcd_init(void)
{
writecmd(0x38);    //for 8 bit mode
writecmd(0x0c);    //display on, cursor off
writecmd(0x01);    //clear display
writecmd(0x80);    //force cursor to beginning of 1st line
}

void writedata(char t)     //data function
{
RS = 1;            
P2 = t;                                //Data transfer
E  = 1;            
delay(150);
E  = 0;           
delay(150);
}


void main()
{
P0 = 0x00;   //not used
P3 = 0x00;   //output port for setting RS and EN
P2 = 0x00;   //used as data output port   for LCD
P1 = 0xf0;   //lower bits as outputs, upper bits as inputs
lcd_init();
writedata('W');                               
delay(5000000);
writedata('e');                                
delay(5000000);
writedata('l');  
delay(5000000);                             
writedata('c');
delay(5000000);                                                                 
writedata('o');
delay(5000000);                                
writedata('m');
delay(5000000);                                
writedata('e');
delay(5000000);
writecmd(0x01);                               //clear display
writedata('E');
writedata('N');
writedata('T');
writedata('E');
writedata('R');
writedata(' ');
writedata('N');
writedata('o');
writedata('.');
delay(5000000);

do
{
col1=1;
col2=1;
col3=1;
row1=row2=row3=row4=0;
if(col1==0) check_col1();
else if(col2==0) check_col2();
else if(col3==0) check_col3();
}while(1);
}


void check_col1() //Function for checking column one
{
row1=row2=row3=row4=1;
row1=0;
if(col1==0)
{
writecmd(0x01); 
writedata('1'); 
delay(5000000); 
}
row1=1;
row2=0;
if(col1==0)
{
writecmd(0x01);  
writedata('4'); 
delay(5000000); 
}
row2=1;
row3=0;
if(col1==0)
{
writecmd(0x01); 
writedata('7'); 
delay(5000000); 
}
row3=1;
row4=0;
if(col1==0)
{
writecmd(0x01);	
writedata('*'); 
delay(5000000); 
}
row4=1;
}

void check_col2() //Function for checking column two
{
row1=row2=row3=row4=1;
row1=0;
if(col2==0)
{
writecmd(0x01); 
writedata('2'); 
delay(5000000); 
}
row1=1;
row2=0;
if(col2==0)
{
writecmd(0x01); 
writedata('5'); 
delay(5000000); 
}
row2=1;
row3=0;
if(col2==0)
{
writecmd(0x01); 
writedata('8'); 
delay(5000000); 
}
row3=1;
row4=0;
if(col2==0)
{
writecmd(0x01);	
writedata('0'); 
delay(5000000);
}
row4=1;
}



void check_col3() //Function for checking column three
{
row1=row2=row3=row4=1;
row1=0;
if(col3==0)
{
writecmd(0x01); 
writedata('3'); 
delay(5000000); 
}
row1=1;
row2=0;
if(col3==0)
{
writecmd(0x01);  
writedata('6'); 
delay(5000000); 
}
row2=1;
row3=0;
if(col3==0)
{
writecmd(0x01); 
writedata('9');
delay(5000000);
}
row3=1;
row4=0;
if(col3==0)
{
writecmd(0x01);  
writedata('#'); 
delay(5000000);
row4=1;
}

