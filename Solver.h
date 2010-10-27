#include <math.h>
#include <iostream>
using namespace std;
void Solver(int &dim, double &maxerr, Dmatrix& Matrix, Dvector& rhs, Dvector& SolveVec){

        Dvector lhs(dim);

        Dmatrix SpareMatrix(dim,dim);
	SpareMatrix=Matrix;
	Dvector Sparerhs(dim);
	Sparerhs=rhs;

	Dvector RowVec1(dim);
	Dvector RowVec2(dim);


	for(int i=0; i<dim; i++)
		lhs(i)=-1e10;

	double maxel=-1;
	double absval;
	for(int i=0; i<dim; i++){
	for(int j=0; j<dim; j++){
	   absval=fabs(Matrix(i,j));
           if(absval > maxel)maxel=absval; 
	}
	}
	if(maxel<0){cout << "ZERO MATRIX\n"; exit(1);}

	//Brutality!
	double Tol=1.0e-11;
	for(int i=0;i<dim;i++){
	for(int j=0;j<dim;j++){
		if(fabs(Matrix(i,j))/maxel<Tol)Matrix(i,j)=0.0; }}
	

	int SwapVec[dim];
	for(int i=0;i<dim;i++)SwapVec[i]=i; // keep tabs on swaps

	int Whereis[dim];
	for(int i=0;i<dim;i++)Whereis[i]=i; // recover swaps

	int whatsin1, whatsin2, whatswhere1, whatswhere2;



	double divide;
	double largest;
	int klarge;

	for(int i=0; i<dim; i++){
		largest=-1.0;
		for(int k=0; k<dim; k++){
			absval=fabs(Matrix(i,k));
			if(absval>largest){
			       largest=absval;
			       klarge=k;
			}}
		if(klarge!=i){
			//Pivot here
                        if(SwapVec[klarge]>i){

                        whatsin1=SwapVec[klarge];
			whatsin2=SwapVec[Whereis[i]];

			whatswhere1=Whereis[whatsin1];
			whatswhere2=Whereis[whatsin2];

			SwapVec[Whereis[i]]=SwapVec[klarge];
			SwapVec[klarge]=i;

			Whereis[whatsin1]=whatswhere2;
			Whereis[whatsin2]=whatswhere1;

			}
		}

		int iswap;
		for( int j=i; j<dim; j++){
		  divide=Matrix(j,klarge);
	   	  if(fabs(divide) >0){
	            for(int k=i; k<dim; k++){
			    iswap=SwapVec[k];
			Matrix(j,Whereis[k])=Matrix(j,Whereis[k])/divide;
			    }
		        rhs(j)=rhs(j)/divide;
	                }
	        	}

		RowVec1=Matrix.GetRow(i);
		for(int j=i+1; j< dim; j++){
		    if(fabs(Matrix(j,klarge)) > 0.0){
                       RowVec2=Matrix.GetRow(j);
		       RowVec2=RowVec2-RowVec1;
                       Matrix.SetRow(RowVec2,j);
		       rhs(j)=rhs(j)-rhs(i);
		       }
		}
		
	}
	double sum;
	int irow;
	for(int i=0; i<dim; i++){
              sum=0; 
	      irow=dim-1-i;
	      for(int j=dim-i; j<dim; j++){
		sum=sum+Matrix(irow,Whereis[j])*lhs(j);
	      }
		lhs(irow)=rhs(irow)-sum;
	}

	Dvector ErrVec(dim);
	Dvector CheckVec(dim);
	for(int i=0; i<dim; i++){
            SolveVec(i)=lhs(SwapVec[i]);
	}

	CheckVec=SpareMatrix*SolveVec;

	ErrVec=Sparerhs-CheckVec;

        maxerr=-1.0;
	for(int i=0; i<dim; i++){
		if(fabs(ErrVec(i))>maxerr)
			maxerr=fabs(ErrVec(i));
	}

        maxerr=maxerr/maxel;
	/*
			for(int p=0; p< dim; p++){
			cout << "Vector p=" << p << "  SolveVec=" << SolveVec(p) << endl;
			} */

	if(maxerr > 1e-10){
	cout << "maxerr=" << maxerr  << endl;
		cout << " Solver failed!\n";
		cout << "Matrix  and started off as as\n";
			for(int p=0; p< dim; p++){
			for(int q=0; q< dim; q++){
			  cout << " Matrix p=" << p << "  q=" << q <<
				  "  " << SpareMatrix(p,q) << endl; }
			cout << "Vector p=" << p << "  rhs=" << Sparerhs(p) << endl;
			}
		cout << "Matrix ended up as\n";
			for(int p=0; p< dim; p++){
			for(int q=0; q< dim; q++){	
			  cout << "Matrix p=" << p << "  q=" << q <<
				  "  " << Matrix(p,q) << endl; }
			cout << "Vector p=" << p << "  rhs=" << rhs(p) << endl;
			}
		exit(1);
	}

}
