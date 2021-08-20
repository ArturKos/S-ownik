//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
bool Koniec_Budowy(int dlugosc,int *slowo,int len)
 {
  unsigned int i;
  for(i=0;i<dlugosc;i++)
     if(slowo[i]!=len)return false;
  return true;
 }
void NastepneSlowo(unsigned int index,int *slowo,int wl)
 {
  if(slowo[index]<wl) slowo[index]++;else
   {
    slowo[index] = 0;
    if(index!=0)NastepneSlowo(index-1,slowo,wl);
   }
 }
void ZapiszSlowo(int *slowo, char *slownik,int len)
 {
  AnsiString s;
  for(unsigned int i = 0;i<len;i++)
   s+=slownik[slowo[i]];
  Form1->Memo1->Lines->Add(s);
 }
void Inicjuj_Slowo(int *slowo,int len)
 {
  for(unsigned int i=0;i<len;i++)
   slowo[i]=0;
 }
void BudujSlowa(unsigned int dlugosc_slowa,char *slownik,int wl)
 {
  int *slowo = new int[dlugosc_slowa];
  Inicjuj_Slowo(slowo,dlugosc_slowa);
  ZapiszSlowo(slowo, slownik,dlugosc_slowa);
   do{
    NastepneSlowo(dlugosc_slowa-1,slowo,wl);
    ZapiszSlowo(slowo, slownik,dlugosc_slowa);
   }while(!Koniec_Budowy(dlugosc_slowa,slowo,wl));
 }
void __fastcall TForm1::Button1Click(TObject *Sender)
{
char *ch = "artur";
BudujSlowa(5,ch,4);
}
//---------------------------------------------------------------------------
