#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

float mini = 0.0;
float maxi = 0.0;
float W = 0.0;

float fs = 600.0;
float T = 2.0;
int n = fs*T;

float *bity;

float A1 = 200.0;
float A2 = 2.0;

float N = 2.0;
float Tb = 0.75;
int fn = N * (1/Tb);

float fn1 = (N + 1)/Tb;
float fn2 = (N + 2)/Tb;

float *tablica_za;
float *tablica_zp;
float *tablica_zpt;

float *tablica1;
float *tablica2;

float expi = 0.0;
float expi1 = 0.0;
float expi2 = 0.0;
float expo1 = 0.0;
float expo2 = 0.0;

float M = 0.0;
float Mp = 0.0;
float fk = 0.0;

float bit(){
	
bity = new float[10];
bity[0] = 1;
bity[1] = 0;
bity[2] = 0;
bity[3] = 1;
bity[4] = 1;
bity[5] = 0;
bity[6] = 0;
bity[7] = 1;
bity[8] = 0;
bity[9] = 1;

return 0;	
}

float *zad1a(){

string linia;
fstream zad2a;
zad2a.open("zad2a.txt", ios::out | ios::trunc);

if(zad2a.good() == true)
{	   
	
tablica_za = new float[n];

if(A1 != A2) cout << "Warunek A1 != A2 spelniony!" <<endl;
else cout << "Warunek A1 != A2 niespelniony!" <<endl;
for(int i=0; i<=9; i++){
for(int t=0; t<=n; t++){
	if(bity[i]==0){
		tablica_za[t] = A1 * sin(2.0 * M_PI * fn * t);
			zad2a << t;
    		zad2a <<" ";
    		zad2a << tablica_za[t];
    		zad2a << endl;
	}
	else{
		tablica_za[t] =	A2 * sin(2.0 * M_PI * fn * t);
			zad2a << t;
    		zad2a <<" ";
    		zad2a << tablica_za[t];
    		zad2a << endl;
	}
}
}

zad2a.close();
}
return(tablica_za);	
}

float oblicz1a(){
		
tablica1 = new float[n];
tablica2 = new float[n];

string linia;
fstream zad1a;
zad1a.open("zad1a.txt", ios::out | ios::trunc);

if(zad1a.good() == true)
{	   
for(int h=0; h<=n; h++){
	for(int k=0; k<=n-1; k++){
	expi = (2.0*M_PI*k*h)/n;	
	expi1 = expi1 + (tablica_za[k] * cos(expi));
	expi2 = expi2 + (tablica_za[k] * sin(expi));	
	}
tablica1[h] = expi1; 
expi1=0;
tablica2[h] = expi2;
expi2=0;
}

for(int k=0; k<=n/2; k++){
	M = sqrt(pow(tablica1[k],2)+pow(tablica2[k],2));	
	Mp = 10.0*log10(M);	
	fk = k*fs/n;
			
		if (mini == 0.0) mini=fk;	
		if(fk>=mini) maxi=fk;
		             
	zad1a << fk;
    zad1a <<" ";
    zad1a << M;
    zad1a << endl;
}
zad1a.close();
}
return 0;	
}

float *zad1b(){

string linia;
fstream zad2b;
zad2b.open("zad2b.txt", ios::out | ios::trunc);

if(zad2b.good() == true)
{		
tablica_zp = new float[n];

if(A1 != A2) cout << "Warunek A1 != A2 spelniony!" <<endl;
else cout << "Warunek A1 != A2 niespelniony!" <<endl;

for(int i=0; i<=9; i++){
for(int t=0; t<=n; t++){
	if(bity[t]==0){
		tablica_zp[t] = sin(2.0 * M_PI * fn1 * t);
			zad2b << t;
    		zad2b <<" ";
    		zad2b << tablica_zp[t];
    		zad2b << endl;
	}
	else{
		tablica_zp[t] =	sin(2.0 * M_PI * fn2 * t);
			zad2b << t;
    		zad2b <<" ";
    		zad2b << tablica_zp[t];
    		zad2b << endl;
	}
}
}
zad2b.close();
}
return(tablica_zp);	
}

float oblicz1b(){
		
tablica1 = new float[n];
tablica2 = new float[n];

string linia;
fstream zad1b;
zad1b.open("zad1b.txt", ios::out | ios::trunc);

if(zad1b.good() == true)
{	   
for(int h=0; h<=n; h++){
	for(int k=0; k<=n-1; k++){
	expi = (2.0*M_PI*k*h)/n;	
	expi1 = expi1 + (tablica_zp[k] * cos(expi));
	expi2 = expi2 + (tablica_zp[k] * sin(expi));	
	}
tablica1[h] = expi1; 
expi1=0;
tablica2[h] = expi2;
expi2=0;
}

for(int k=0; k<=n/2; k++){
	M = sqrt(pow(tablica1[k],2)+pow(tablica2[k],2));	
	Mp = 10.0*log10(M);	
	fk = k*fs/n;
	
		if (mini == 0.0) mini=fk;	
		if(fk>=mini) maxi=fk;
		             
	zad1b << fk;
    zad1b <<" ";
    zad1b << M;
    zad1b << endl;
}
zad1b.close();
}
return 0;	
}

float *zad1c(){

string linia;
fstream zad2c;
zad2c.open("zad2c.txt", ios::out | ios::trunc);

if(zad2c.good() == true)
{		
	
tablica_zpt = new float[n];

if(A1 != A2) cout << "Warunek A1 != A2 spelniony!" <<endl;
else cout << "Warunek A1 != A2 niespelniony!" <<endl;

for(int i=0; i<=9; i++){
for(int t=0; t<=n; t++){
	if(bity[t]==0){
		tablica_zpt[t] = sin(2.0 * M_PI * fn * t);
			zad2c << t;
    		zad2c <<" ";
    		zad2c << tablica_zpt[t];
    		zad2c << endl;
	}
	else{
		tablica_zpt[t] =	sin(2.0 * M_PI * fn * t + M_PI);
			zad2c << t;
    		zad2c <<" ";
    		zad2c << tablica_zpt[t];
    		zad2c << endl;
	}
}
}
zad2c.close();
}
return(tablica_zpt);	
}

float oblicz1c(){
		
tablica1 = new float[n];
tablica2 = new float[n];

string linia;
fstream zad1c;
zad1c.open("zad1c.txt", ios::out | ios::trunc);

if(zad1c.good() == true)
{	   
for(int h=0; h<=n; h++){
	for(int k=0; k<=n-1; k++){
	expi = (2.0*M_PI*k*h)/n;	
	expi1 = expi1 + (tablica_zpt[k] * cos(expi));
	expi2 = expi2 + (tablica_zpt[k] * sin(expi));	
	}
tablica1[h] = expi1; 
expi1=0;
tablica2[h] = expi2;
expi2=0;
}

for(int k=0; k<=n/2; k++){
	M = sqrt(pow(tablica1[k],2)+pow(tablica2[k],2));	
	Mp = 10.0*log10(M);	
	fk = k*fs/n;
	
		if (mini == 0.0) mini=fk;	
		if(fk>=mini) maxi=fk;
		             
	zad1c << fk;
    zad1c <<" ";
    zad1c << M;
    zad1c << endl;
}
zad1c.close();
}
return 0;	
}

int main(){
	
bit();

zad1a();
oblicz1a();
	cout<<"Zad1a fMin = "<<mini<<endl; 
	cout<<"Zad1a fMax = "<<maxi<<endl;
	W = maxi - mini;
	cout<<"Zad1a Szerokosc pasma = "<<W<<endl;

zad1b();
oblicz1b();
	cout<<"Zad1b fMin = "<<mini<<endl; 
	cout<<"Zad1b fMax = "<<maxi<<endl;
	W = maxi - mini;
	cout<<"Zad1b Szerokosc pasma = "<<W<<endl;

zad1c();
oblicz1c();
	cout<<"Zad1c fMin = "<<mini<<endl; 
	cout<<"Zad1c fMax = "<<maxi<<endl;
	W = maxi - mini;
	cout<<"Zad1c Szerokosc pasma = "<<W<<endl;

return 0;
}
