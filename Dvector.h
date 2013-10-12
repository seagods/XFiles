#include <stdio.h>
#include <iostream>
class Dvector{

    public:

        Dvector();                     //constructor
        Dvector(  int &);         //constructor
        Dvector(const Dvector &);      //copy constructor

        ~Dvector();                    // destructor

        void SetLength( int &);
        void SetMem( int &);

        int* GetLength() const;
        double* GetV() const;

        double& operator() (  int &);
        double operator() ( int &) const;

        Dvector& operator= (const Dvector&);

        Dvector operator+(const Dvector&);
        void operator+=(const Dvector&);

        Dvector operator-(const Dvector&);
        void operator-=(const Dvector&);

        Dvector operator*(const double &);
        void operator*=(const double &);

        Dvector operator/(const double &);
        void operator/=(const double &);

        void SetElem(double &,  int &);
        double GetElem( int &) const;

        void SwapElems( int &,  int &);

    private:
        int* length;
        double* V;

};

Dvector::Dvector(){

       V=NULL;
       length=new int;
       *length=0;
}

Dvector::Dvector(  int &i){

       length=new int;
       *length=i;
       V=new double[i];
       for(int k=0;k<i;k++)
            *(V+k)=0.0;

}
Dvector::Dvector(const Dvector& rhs)
{
   length=new int;
   int *rhslength;
   rhslength=rhs.GetLength();

   *length=*rhslength;

   V=new double[*length];
       for(int k=0;k<*length;k++)
            *(V+k)=0.0;

   double* rhsV;
   rhsV=rhs.GetV();


   for(int i=0; i< *length; i++)
         *(V+i)=*(rhsV+i);
}
Dvector::~Dvector(){

     if(V){
         delete[] V;
         V=NULL;
     }
     // length is garbage as soon as destructor called
     delete length;
     length=NULL;
}

void Dvector::SetLength(  int &i){
   if(*length !=0)
       {printf("SetLength:  Vector length already set!\n) ");  exit(1);}

    *length=i;
    if(!V){
        V=new double[i];
       for(int k=0;k<i;k++)
            *(V+k)=0.0;
       }
    else
       {printf("SetLength: Vector memory already set!\n"); exit(1);}

}


int* Dvector::GetLength() const{
     return length;
}
double* Dvector::GetV() const{
     return V;
}
void  Dvector::SetMem( int &i) {
   if(*length==0)*length=i;
   if(i!=*length ){printf(  " Memory Mismatch! \n");  exit(1);}
   if(!V){
      V=new double[i];
       for(int k=0;k<i;k++)
            *(V+k)=0.0;
       }
   else
     { printf("SetMem: Vector memory already set!\n"); exit(1);}
}

Dvector& Dvector::operator=(const Dvector& rhs){
      int* rhslength=rhs.GetLength();
      if(*length==0)*length=*rhslength;
      double* rhsV;
      rhsV=rhs.GetV();

     if(*length != *rhslength ){
          printf("Lengths  do not match!\n");
          exit(1);
      }

     //if memory not yet set
     if(!V) V=new double[*length];
      
      for(int i=0; i< *length; i++)
           *(V+i)=*(rhsV+i);
}
double& Dvector::operator() ( int &i){
   if(i >= *length ){printf( "Array bound error\n " ); exit(1);}
   return *(V+i);
}
double Dvector::operator() (  int &i) const {
   if(i >= *length){printf( "Array bound error\n ");  exit(1);}
   return *(V+i);
}
Dvector Dvector::operator+(const Dvector& rhs){

      int* rhslength=rhs.GetLength();

      double* rhsV;
      rhsV=rhs.GetV();


     if(*length != *rhslength ){
          printf("Lengths do not match!\n");
          exit(1);
      }
      int nlength=*length;

     Dvector Temp(nlength);

     double* TempV;
     TempV=Temp.GetV();
  
      for( int i=0; i< *length; i++)
           *(TempV+i)=*(V+i) + *(rhsV+i);
  
      return Temp;
}
void Dvector::operator+=(const Dvector& rhs){


      int* rhslength=rhs.GetLength();
      double* rhsV;
      rhsV=rhs.GetV();

     if(*length != *rhslength){
          printf("Lengths do not match!\n");
          exit(1);
      }
  
      for( int i=0; i< *length; i++)
           *(V+i)=*(V+i) + *(rhsV+i);
}
Dvector Dvector::operator-(const Dvector& rhs){


      int* rhslength=rhs.GetLength();
      double* rhsV;
      rhsV=rhs.GetV();

     if(*length != *rhslength){
          printf("Lengths do not match!\n");
          exit(1);
      }
      int nlength=*length;
      Dvector Temp(nlength);
      double* TempV;
      TempV=Temp.GetV();
  
      for( int i=0; i< *length; i++)
           *(TempV+i)=*(V+i) - *(rhsV+i);
  
      return Temp;
}
void Dvector::operator-=(const Dvector& rhs){

      int* rhslength=rhs.GetLength();
      double* rhsV;
      rhsV=rhs.GetV();

     if(*length != *rhslength){
          printf("Lengths do not match!\n");
          exit(1);
      }
  
      for( int i=0; i< *length; i++)
           *(V+i)=*(V+i) - *(rhsV+i);
}

Dvector Dvector::operator*(const double& rhs){

       int nlength=*length;

      Dvector Temp(nlength);
      double* TempV;
      TempV=Temp.GetV();

  
      for( int i=0; i< *length; i++)
           *(TempV+i)=*(V+i)*rhs;

    return Temp;
}

void Dvector::operator*=(const double& rhs){

  
      for( int i=0; i< *length; i++)
           *(V+i)=*(V+i)*rhs;
}
Dvector Dvector::operator/(const double& rhs){

       int nlength=*length;

      Dvector Temp(nlength);
      double* TempV;
      TempV=Temp.GetV();

  
      for( int i=0; i< *length; i++)
           *(TempV+i)=*(V+i)/rhs;
    return Temp;
}

void Dvector::operator/=(const double& rhs){
  
      for( int i=0; i< *length; i++)
           *(V+i)=*(V+i)/rhs;
}

void Dvector::SetElem(double &x,  int &i){
    *(V+i)=x;
}

double Dvector::GetElem( int &i) const {
    return *(V+i);
}

void Dvector::SwapElems( int &i,  int &j){

      double temp1,temp2;
      temp1=GetElem(i);
      temp2=GetElem(j);
      SetElem(temp2,i);
      SetElem(temp1,j);
}











  
