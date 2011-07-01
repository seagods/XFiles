//-------------------------------------------------------------------------------
// Copyright 2011 Christopher Godsalve.
// All Rights Reserved.
//
// Permission to use, copy, modify and distribute this software (if not modified) and its
// documentation for educational, research and non-profit purposes, without fee,
// and without a written agreement is hereby granted, provided that the above
// copyright notice, this paragraph and the following three paragraphs appear in all copies.
// 
//
// To request permission to incorporate this software into commercial products
// contact Dr C. Godsalve, 42 Swainstone Road, Reading, Berks, UK or by email at
// seagods@btinternet.com or seagods@hotmail.com.
//
// IN NO EVENT SHALL CHRISTOPHER GODSALVE BE LIABLE TO ANY PARTY FOR
// DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING 
// LOST PROFITS, ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, 
// EVEN IF CHRISTOPHER GODSALVE HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
//
// CHRISTOPHER GODSALVE SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE. THE SOFTWARE PROVIDED HEREUNDER IS ON AN `AS IS' BASIS, AND CHRISTOPHER 
// GODSALVE HAS NO OBLIGATIONS TO PROVIDE MAINTAINANCE, SUPPORT, UPDATES, 
// ENHANCEMENTS, OR MODIFICATIONS IF HE CHOOSES NOT TO DO SO.
//--------------------------------------------------------------------------------

#include <math.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace::std;
// Given N roots of a monic (X^N+a X^N-1+b X^N-2+...+C) polynomial we can recover all the coefficients
// X[N]  = N roots
// coeffs[N+1] = coefficients ALTERNATING IN SIGN.  i.e coeffs[0]=1, coeffs[1]=-a, coeffs[2]=+b etc.
// set verbose=false unless you want to check out the results of picking n objects from N in Pickem
int Pickem(int** picks, int& m, int& N, int & ifacs, int &mcrit);

    double LagrangeInt( double* X, double* coeffs, int &N){

    N=4;
    bool verbose=false;

    double factor[N];

    double sum[N];

    double mult=1.0;
   
    sum[0]=1.0;   //coeff of x^N=1.0;
    sum[N-1]=1.0;  //coeff of X^0=product of all roots
    for(int i=0; i<N; i++){
       sum[N-1]=sum[N-1]*X[i];
    }
    coeffs[N+1]=sum[N-1];

    int ifacs;

    int verbose=-1;    //get verbose output for a particular value of nobj --- set negative for not verbose

    int Nend;   // we only have to do half the work
    Nend=N/2;   // the second part of the list is the first half - except the numbers are
                // to be regarded as missing instead of present 
    int iremain=N%2;

    int factorials[Nend];

    for(int i=0; i<Nend; i++){
       ifacs=1;
       int nobj=i+1;
       // pick i+1 out of N objects
        
       for(int j=0; j<nobj; j++){
      //    simple to prove j+1 always goes exactly...
            ifacs=ifacs*(N-j)/(j+1);
       }
       if(verbose)cout << "i=" << i <<  "  ifacs=" << ifacs << endl;

       factorials[i]=ifacs;
 
       if(verbose)cout <<" declare picks " <<  ifacs << "  times " << nobj << endl;

       int** picks=new int*[ifacs];


       for(int k=0; k< ifacs; k++){
           picks[k]=new int[nobj];
       }

        // we only want <= m/2
       //if >m/2 have what we picked as missing from rather than present!
       int ireturn=Pickem(picks, nobj, N, ifacs, verbose);

       bool mask[ifacs][N];
       int complement[ifacs][N];
       for(int k=0; k< ifacs; k++){
         for(int l=0; l<N; l++){
            complement[k][l]=l;
            mask[k][l]=true;
         }
       } 
       sum[nobj]=0;
       if(verbose)cout << " for n=" << nobj << " I can pick\n";
       for(int k=0; k< ifacs; k++){
         mult=1.0;
         for(int l=0; l<nobj; l++){
             if(verbose)cout << picks[k][l] << "  ";
             mask[k][picks[k][l]]=false;
             mult=mult*X[picks[k][l]];
         }
         if(verbose)cout <<   endl;
         sum[nobj]=sum[nobj]+mult;
         coeffs[nobj]=sum[nobj];
       } 

       if(i<Nend-1){
       sum[N-nobj]=0;
       if(verbose)cout << " for n=" << N-nobj << " I can pick\n";
       for(int k=0; k< ifacs; k++){
         mult=1.0;
         for(int l=0; l<N; l++){
            if(mask[k][l]){
                   if(verbose)cout << complement[k][l] << "  ";
                   mult=mult*X[complement[k][l]];
            }
         }
         if(verbose)cout << endl;
         sum[N-nobj]=sum[N-nobj]+mult;
         coeffs[N-nobj]=sum[N-nobj];
       }
       }else{
           if(iremain ==1){
             sum[N-nobj]=0;
             if(verbose)cout << " for n=" << N-nobj << " I can pick\n";
             for(int k=0; k< ifacs; k++){
               mult=1.0;
               for(int l=0; l<N; l++){
                 if(mask[k][l])cout << complement[k][l] << "  ";
               }
             if(verbose)cout << endl;
             sum[N-nobj]=sum[N-nobj]+mult;
             coeffs[N-nobj]=sum[N-nobj];
            }
           }
       }



       for(int k=0; k< ifacs; k++){
          delete[] picks[k];
       } 
       delete[] picks; 
       
   
     }  


    return 0;

}
int Pickem(int** picks, int& m, int & N, int & ifacs, int &mcrit){

    //m is the nuber of objects to picked out of N obects

    int j=m-1;


    if(m==1){
    for(int i1=0; i1<ifacs; i1++){
       for(int j=0; j<m; j++){
         picks[i1][j]=i1;
         if(mcrit==4)cout << picks[i1][j] << endl;
    }}}
    if(m==1)return 0;

    //we are picking more than one object out of N




    int nextN=N-1;
    int nextm=m-1;
    int kount=0;
    int start=0;
    int lastkount;

    while(kount<ifacs){

       for(int j1=0; j1<nextm; j1++){


       lastkount=kount;

       int nextNend=nextN/2;
       int nextiremain=nextNend%2;
       nextNend=nextNend+nextiremain;


       int nextifacs=1;
        
       for(int j1=0; j1<nextm; j1++){
            nextifacs=nextifacs*(nextN-j1)/(j1+1);
       }


       int** nextpicks=new int*[nextifacs];

       if(mcrit==4)cout <<" declare picks " <<  nextifacs << "  times " << nextm << endl;
       for(int k=0; k< nextifacs; k++){
           nextpicks[k]=new int[nextm];
       }


       int ireturn=Pickem(nextpicks, nextm, nextN, nextifacs, mcrit);

       if(mcrit==4)cout << "nextpicks picked\n";
       for(int k=0; k< nextifacs; k++){
         for(int l=0; l<nextm; l++){
            if(mcrit==4)cout << nextpicks[k][l] << "  ";
         }
        if(mcrit==4)cout << "Then " << endl;
       }


    
       for(int k=0; k<nextifacs; k++){
          

          if(mcrit==4)cout << "picks picked\n";


          picks[k+lastkount][0]=start;
          if(mcrit==4)cout << picks[k+lastkount][0] << " ";

          
          for(int l=0; l<nextm; l++){
             picks[k+lastkount][l+1]=nextpicks[k][l]+start+1;
             if(mcrit==4)cout << picks[k+lastkount][l+1] << " ";

          } 
          kount++;     
          if(mcrit==4)cout << endl;
       }
       start++;

       if(mcrit==4)cout << " Then picked " << start << "  as the new start\n";

       nextN--;

       if(mcrit==4){
          cout << " debug point " << endl;
       }

       lastkount=kount;


       

       for(int k=0; k< nextifacs; k++){
          delete[] nextpicks[k];
       } 
       delete[] nextpicks; 
       
       }

   } // end while kount
    
}

