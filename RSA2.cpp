#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int char2int(char A[], int B[])
{
	int i;
	for(i=0;A[i]!='\0';i++)
	{
		B[i]=A[i]-' ';
	}
	return i;
}
void int2char(int B[], char A[], int l)
{
	for(int i=0;B[i]<l;i++)
	{
		A[i]=' '+B[i];
	}
}
int* RSAencrypt(int m[], int n, int e, int l)
{
	for(int i=0;i<l;i++)
	{
		m[i]=(m[i]^e)%n;
	}
	return m;
}
void RSAdecrypt(int m[], int n, int d, int l)
{
	for(int i=0;i<l;i++)
	{
		m[i]=(m[i]^d)%n;
	}
}
void dispintarr(int A[], int l)
{
	for(int i=0;i<l;i++)
	{
		cout<<A[i]<<"  ";
	}
}
int main()
{
	cout<<"RSA Encryption Module"<<endl<<endl<<"Input a character string (max 120 characters) - ";
	char ch[120];
	int m[120];
	cin.get(ch,120);
	int i=char2int(ch,m);
	int p,q;
	cout<<"Input two very large PRIMES - ";
	cin>>p>>q;
	int n=p*q;
	cout<<"Your encryption modulus is "<<n<<endl;
	p=q=0;						//removing trapdoor
	int d,e;
	srand(time(NULL));
	d=rand()%(n-1);
	d++;
	int n1=(p-1)*(q-1);
	for(int e=1;e>=n/d;e++)
	{
		if(d*e%n1==1)
		break;
	}
	cout<<"Psst! Your Secret Key is "<<d<<" ! Kindly note it down for decryption.";	
	char choice;
	cout<<endl<<"Commence encryption? (y/n)";
	cin>>choice;
	switch(choice)
	{
		case 'y':
		case 'Y':cout<<"Encrypted Data - "; dispintarr(RSAencrypt(m,n,e,i),i);
			 break;
		default:exit(0);
	};
	cout<<endl<<"Your public key is - "<<e<<" (complement to the trapdoor) and the Encrypted Data.";
	int d1;
	cout<<endl<<endl<<"Enter secret key for decryption - ";
	cin>>d1;
	if(d==d1)
	{
		RSAdecrypt(m,n,d,i);
		int2char(m,ch,i);
		cout<<"Decrypted Data - "<<ch<<endl;
	}
	else cout<<"Infiltrator DETECTED, SELF DESTRUCT SEQUENCE INITIATED.";
	return(0);
}
	
