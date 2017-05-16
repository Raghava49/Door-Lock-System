#include<regx51.h>
void dscmd(unsigned char a);
void dsdata(unsigned char b);
void delay(unsigned int c);
void enpass(unsigned char x);
void check(void);
void welcome(void);
void clear(void);

#define lcd P2

sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;

sbit m0=P1^3;
sbit m1=P1^4;

sbit c1=P3^4;
sbit c2=P3^5;
sbit c3=P3^6;
sbit r1=P3^0;
sbit r2=P3^1;
sbit r3=P3^2;
sbit r4=P3^3;

int z;
unsigned char i,k,y;
unsigned char mess1[]=" ENTER PASSWORD";
unsigned char pass[] = "123456789";
unsigned char mwell[]="    WELCOME";
unsigned char errpass[]=" PASSWORD ERROR";
unsigned char pass1[10];
main()
{
	m0=0;
	m1=0;
	
	dscmd(0x38);
	
	dscmd(0x06);
	
	dscmd(0x0C);
	
	dscmd(0x80);
	
  dscmd(0x01);
	
	
	
	welcome();
	dscmd(0xC0);
	
	while(1)
	{	
	while(1)
	{
		

		P3=0xFF;
		r1=0;
			if(c1==0)
			{
				while(c1==0);
				dsdata(0x31);
				enpass('1');
					
			}
			
			
		P3=0xFF;
		r1=0;
			if(c2==0)
			{
				while(c2==0);
				dsdata(0x32);
				enpass('2');			
			}
		P3=0xFF;
		r1=0;
			if(c3==0)
			{
				while(c3==0);
				dsdata(0x33);
				enpass('3');
			}
			

			
		P3=0xFF;
		r2=0;
			if(c1==0)
			{
				while(c1==0);
				dsdata(0x34);
				enpass('4');
			}
			
			
		P3=0xFF;
		r2=0;	
			if(c2==0)
			{
				while(c2==0);
				dsdata(0x35);
				enpass('5');
			}
		P3=0xFF;
		r2=0;
			if(c3==0)
			{
				while(c3==0);
				dsdata(0x36);
				enpass('6');
			}
			
			
			
		P3=0xFF;
		r3=0;
			if(c1==0)
			{
				while(c1==0);
				dsdata(0x37);
				enpass('7');
			}
			
			
		P3=0xFF;
		r3=0;	
			if(c2==0)
			{
				while(c2==0);
				dsdata(0x38);
				enpass('8');
			}
		P3=0xFF;
		r3=0;
			if(c3==0)
			{
				while(c3==0);
				dsdata(0x39);
				enpass('9');
			}
	
			
			
			
			
			
			
		P3=0xFF;
		r4=0;
			if(c1==0)
			{
				while(c1==0);
				m0=0;
				m1=1;
				delay(600);
				m0=0;
				m1=0;
				welcome();
			}
			
			
		P3=0xFF;
		r4=0;	
			if(c2==0)
			{
				while(c2==0);
				dsdata(0x30);
				enpass('0');
			}
		P3=0xFF;
		r4=0;
			if(c3==0)
			{
				while(c3==0);
				check();
				
			}
	
}
}
	}


void dscmd(unsigned char a)
{
	P2=a;
	rs=0;
	rw=0;
	en=1;
	delay(5);
	en=0;
}


void dsdata(unsigned char b)
{
	P2=b;
	rs=1;
	rw=0;
	en=1;
	delay(5);
	en=0;
}

void delay(unsigned int c)
{
	unsigned int j;
	for (z=0;z<=c;z++)
	{
	for(j=0;j<1000;j++);
	}
}



void enpass(unsigned char x)
	{
		P0=x;
		pass1[y]=x;
		y++;
	return;
	}
	
	
void check(void)
	{
		unsigned char j;
		for (j=0;j<=8;j++)
		{
			if(pass[j]==pass1[j])
			{
				if(j==8)
				{
					dscmd(0x01);
					dscmd(0x80);
					for(j=0;j<11;j++)
					{
						dsdata(mwell[j]);
					}
				
					m0=1;
					m1=0;
					delay(600);
					m0=0;
					m1=0;
					y=0;
					
				}
			}
			else
			{
				dscmd(0x01);
					dscmd(0x80);
				for(j=0;j<16;j++)
				{
					dsdata(errpass[j]);
				}
				delay(300);
				y=0;
				welcome();
			}
		}
		clear();
	}
	
	
void welcome(void)
{
	dscmd(0x01);
	dscmd(0x80);
	dscmd(0x02);
	for(i=0;i<=16;i++)
	{
		dsdata(mess1[i]);
		delay(5);
	}
	dscmd(0xC0);
}

void clear(void)
{
for(i=0;i<=10;i++)
{
	pass1[i]='\0';
}
dscmd(0xC0);
}
