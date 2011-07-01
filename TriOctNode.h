//-------------------------------------------------------------------------------
// Copyright 2008 Christopher Godsalve.
// All Rights Reserved.
//
// Permission to use, copy, modify and distribute this software (if not modified) and its
// documentation for educational, research and non-profit purposes, without fee,
// and without a written agreement is hereby granted, provided that the above
// copyright notice - this paragraph - and the following three paragraphs appear in all copies.
// A
//
// To request permission to incorporate this software into commercial products
// contact Dr C. Godsalve, 42 Swainstone Road, Reading, Berks, UK or by email at
// seagods@btinternet.com.
//
// IN NO EVENT SHALL CHRISTOPHER GODSALVE BE LIABLE TO ANY PARTY FOR
// DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING 
// LOST PROFITS, ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, 
// EVEN IF CHRITOPHER GODSALVE HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
//
// CHRISTOPHER GODSALVE SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE. THE SOFTWARE PROVIDED HEREUNDER IS ON AN `AS IS' BASIS, AND CHRISTOPHER 
// GODSALVE HAS NO OBLIGATIONS TO PROVIDE MAINTAINANCE, SUPPORT, UPDATES, 
// ENHANCEMENTS, OR MODIFICATIONS IF HE CHOOSES NOT TO DO SO.
//--------------------------------------------------------------------------------

//Here T will be a 3D data item such as a point
// Might need forward decarations
template <class T> class CMyOctNode; 

template <class T>
class CMyOctNode{

	public:
		CMyOctNode();
		~CMyOctNode();
		CMyOctNode(CMyOctNode&);

		//accessor functions
		CMyOctNode* GetUpperNorthEast();
		CMyOctNode* GetUpperNorthWest();
		CMyOctNode* GetUpperSouthEast();
		CMyOctNode* GetUpperSouthWest();

		CMyOctNode* GetLowerNorthEast();
		CMyOctNode* GetLowerNorthWest();
		CMyOctNode* GetLowerSouthEast();
		CMyOctNode* GetLowerSouthWest();


		T* GetDatumPtr();


		void SetNode(CMyOctNode&,char,char,char);
		void SetNode(CMyOctNode*,char,char,char); 

		void SetNode(T&, CMyOctNode&,char,char,char);
		void SetNode(T*, CMyOctNode*,char,char,char); 

		void SetNode(T&);
		void SetNode(T*);

		int CompareEW(CMyOctNode*);
		int CompareEW(CMyOctNode&);

		int CompareNS(CMyOctNode*);
		int CompareNS(CMyOctNode&);

		int CompareUD(CMyOctNode*);
		int CompareUD(CMyOctNode&);

		void IncOccur();
		int  GetOccur();

                intList*  GetList(){return Tees;}
                void SetList(intList* LocalTri){Tees=LocalTri;}
                void show();

	private:
		T* Datum;
		int i_occur;
		int i_height;

		CMyOctNode* ptrUpperNorthEast;
		CMyOctNode* ptrUpperNorthWest;
		CMyOctNode* ptrUpperSouthEast;
		CMyOctNode* ptrUpperSouthWest;

		CMyOctNode* ptrLowerNorthEast;
		CMyOctNode* ptrLowerNorthWest;
		CMyOctNode* ptrLowerSouthEast;
		CMyOctNode* ptrLowerSouthWest;


                intList *Tees;
};

//   FUNCTION DEFINITIONS

//constructor
template <class T>
CMyOctNode<T>::CMyOctNode(){

	ptrUpperNorthEast=NULL;
	ptrUpperNorthWest=NULL;
	ptrUpperSouthEast=NULL;
	ptrUpperSouthWest=NULL;

	ptrLowerNorthEast=NULL;
	ptrLowerNorthWest=NULL;
	ptrLowerSouthEast=NULL;
	ptrLowerSouthWest=NULL;

	Datum=new T;

        Tees=NULL;

	i_occur=0;
	i_height=0;

}
template <class T>
CMyOctNode<T>::~CMyOctNode(){
	cout << "OctNode destroyed" << endl;
}

//copy constructor
template <class T>
CMyOctNode<T>::CMyOctNode(CMyOctNode<T>& rhs)
{
	        ptrUpperNorthEast=new CMyOctNode;
		ptrUpperNorthWest=new CMyOctNode;
	        ptrUpperSouthEast=new CMyOctNode;
		ptrUpperSouthWest=new CMyOctNode;

	        ptrLowerNorthEast=new CMyOctNode;
		ptrLowerNorthWest=new CMyOctNode;
	        ptrLowerSouthEast=new CMyOctNode;
		ptrLowerSouthWest=new CMyOctNode;
		Datum=new T;


		ptrUpperNorthEast=rhs.GetUpperNorthEast();
		ptrUpperNorthWest=rhs.GetUpperNorthWest();
		ptrUpperSouthEast=rhs.GetUpperSouthEast();
		ptrUpperSouthWest=rhs.GetUpperSouthWest();

		*Datum=*rhs.GetDatumPtr();
		cout << " Node Copied!" << endl;
}
// accessors
template <class T>
T* CMyOctNode<T>::GetDatumPtr(){
	return Datum;
}
template <class T>
CMyOctNode<T>* CMyOctNode<T>::GetUpperNorthEast(){
	return ptrUpperNorthEast;
} 
template <class T>
CMyOctNode<T>* CMyOctNode<T>::GetUpperNorthWest(){
	return ptrUpperNorthWest;
}  
template <class T>
CMyOctNode<T>* CMyOctNode<T>::GetUpperSouthEast(){
	return ptrUpperSouthEast;
} 
template <class T>
CMyOctNode<T>* CMyOctNode<T>::GetUpperSouthWest(){
	return ptrUpperSouthWest;
}  
template <class T>
CMyOctNode<T>* CMyOctNode<T>::GetLowerNorthEast(){
	return ptrLowerNorthEast;
} 
template <class T>
CMyOctNode<T>* CMyOctNode<T>::GetLowerNorthWest(){
	return ptrLowerNorthWest;
}  
template <class T>
CMyOctNode<T>* CMyOctNode<T>::GetLowerSouthEast(){
	return ptrLowerSouthEast;
} 
template <class T>
CMyOctNode<T>* CMyOctNode<T>::GetLowerSouthWest(){
	return ptrLowerSouthWest;
}  
// COMPARISONS
template <class T>
int CMyOctNode<T>::CompareEW(CMyOctNode* rhs){
	int i=Datum->CompareEW(rhs->GetDatumPtr() );
	return i;
}
template <class T>
int CMyOctNode<T>::CompareEW(CMyOctNode& rhs){
	int i=Datum->CompareEW(rhs.GetDatumPtr() );
	return i;
}
template <class T>
int CMyOctNode<T>::CompareNS(CMyOctNode* rhs){
	int i=Datum->CompareNS(rhs->GetDatumPtr() );
	return i;
}
template <class T>
int CMyOctNode<T>::CompareNS(CMyOctNode& rhs){
	int i=Datum->CompareNS(rhs.GetDatumPtr() );
	return i;
}
template <class T>
int CMyOctNode<T>::CompareUD(CMyOctNode* rhs){
	int i=Datum->CompareUD(rhs->GetDatumPtr() );
	return i;
}
template <class T>
int CMyOctNode<T>::CompareUD(CMyOctNode& rhs){
	int i=Datum->CompareUD(rhs.GetDatumPtr() );
	return i;
}

//  SETTING NODE FUNCTIONS

template <class T>
void CMyOctNode<T>::SetNode(CMyOctNode<T>& NodeWhich, char eastwest, char northsouth, char updown){
    if(updown=='u' || updown=='U'){
	if(eastwest=='e' || eastwest=='E'){
               if(northsouth='n' || northsouth='N')
	        	ptrUpperNorthEast=&NodeWhich;
               if(northsouth=='s' || northsouth='S')
	        	ptrUpperSouthEast=&NodeWhich;
	}
        if(eastwest=='w' || eastwest=='W'){
               if(northsouth=='n' || northsouth='N')
	        	ptrUpperNorthWest=&NodeWhich;
               if(northsouth=='s' || northsouth='S')
	        	ptrUpperSouthWest=&NodeWhich;
	}
     }
     else
    {
	if(eastwest=='e' || eastwest=='E'){
               if(northsouth='n' || northsouth='N')
	        	ptrLowerNorthEast=&NodeWhich;
               if(northsouth=='s' || northsouth='S')
	        	ptrLowerSouthEast=&NodeWhich;
	}
        if(eastwest=='w' || eastwest=='W'){
               if(northsouth=='n' || northsouth='N')
	        	ptrLowerNorthWest=&NodeWhich;

               if(northsouth=='s' || northsouth='S')
	        	ptrLowerSouthWest=&NodeWhich;
	}
    }
} 
template <class T>
void CMyOctNode<T>::SetNode(CMyOctNode<T>* NodeWhich, char eastwest, char northsouth, char updown){

    if(updown=='u' || updown=='U'){
	if(eastwest=='e' || eastwest=='E'){
               if(northsouth=='n' || northsouth=='N')
	        	ptrUpperNorthEast=NodeWhich;
               if(northsouth=='s' || northsouth=='S')
	        	ptrUpperSouthEast=NodeWhich;
	}
        if(eastwest=='w' || eastwest=='W'){
               if(northsouth=='n' || northsouth=='N')
	        	ptrUpperNorthWest=NodeWhich;
               if(northsouth=='s' || northsouth=='S')
	        	ptrUpperSouthWest=NodeWhich;
	}
     }
     else
    {

	if(eastwest=='e' || eastwest=='E'){
               if(northsouth=='n' || northsouth=='N')
	        	ptrLowerNorthEast=NodeWhich;
               if(northsouth=='s' || northsouth=='S')
	        	ptrLowerSouthEast=NodeWhich;
	}
        if(eastwest=='w' || eastwest=='W'){
               if(northsouth=='n' || northsouth=='N')
	        	ptrLowerNorthWest=NodeWhich;
               if(northsouth=='s' || northsouth=='S')
	        	ptrLowerSouthWest=NodeWhich;
	}
    }
} 

template <class T>
void CMyOctNode<T>::SetNode(T& Object, CMyOctNode<T>& NodeWhich, char eastwest, char northsouth, char updown){
    if(updown=='u' || updown=='U'){
	if(eastwest=='e' || eastwest=='E'){
               if(northsouth=='n' || northsouth=='N')
	        	ptrUpperNorthEast=&NodeWhich;
               if(northsouth=='s' || northsouth=='S')
	        	ptrUpperSouthEast=&NodeWhich;
	}
        if(eastwest=='w' || eastwest=='W'){
               if(northsouth=='n' || northsouth=='N')
	        	ptrUpperNorthWest=&NodeWhich;
               if(northsouth=='s' || northsouth='S')
	        	ptrUpperSouthWest=&NodeWhich;
	}

     }
     else
    {
	if(eastwest=='e' || eastwest=='E'){
               if(northsouth=='n' || northsouth=='N')
	        	ptrLowerNorthEast=&NodeWhich;
               if(northsouth=='s' || northsouth=='S')
	        	ptrLowerSouthEast=&NodeWhich;
	}
        if(eastwest=='w' || eastwest=='W'){
               if(northsouth=='n' || northsouth=='N')
	        	ptrLowerNorthWest=&NodeWhich;
               if(northsouth=='s' || northsouth='S')
	        	ptrLowerSouthWest=&NodeWhich;
	}
      
    }  
	*Datum=Object;
} 
template <class T>
void CMyOctNode<T>::SetNode(T* Object, CMyOctNode<T>* NodeWhich, char eastwest, char northsouth, char updown){
    if(updown=='u' || updown=='U'){
	if(eastwest=='e' || eastwest=='E'){
               if(northsouth=='n' || northsouth=='N')
	        	ptrUpperNorthEast=NodeWhich;
               if(northsouth=='s' || northsouth=='S')
	        	ptrUpperSouthEast=NodeWhich;
	}
        if(eastwest=='w' || eastwest=='W'){
               if(northsouth=='n' || northsouth=='N')
	        	ptrUpperNorthWest=NodeWhich;
               if(northsouth=='s' || northsouth=='S')
	        	ptrUpperSouthWest=NodeWhich;
	}

     }
     else
    {
	if(eastwest=='e' || eastwest=='E'){
               if(northsouth=='n' || northsouth=='N')
	        	ptrLowerNorthEast=NodeWhich;
               if(northsouth=='s' || northsouth=='S')
	        	ptrLowerSouthEast=NodeWhich;
	}
        if(eastwest=='w' || eastwest=='W'){
               if(northsouth=='n' || northsouth=='N')
	        	ptrLowerNorthWest=NodeWhich;
               if(northsouth=='s' || northsouth=='S')
	        	ptrLowerSouthWest=NodeWhich;
	}

     }
	*Datum=*Object;
} 

template <class T>
void CMyOctNode<T>::SetNode(T* Object){
	*Datum=*Object;
}
template <class T>
void CMyOctNode<T>::SetNode(T& Object){
	*Datum=Object;
}

template <class T>
void CMyOctNode<T>::IncOccur(){
i_occur++;
}
template <class T>
int CMyOctNode<T>::GetOccur(){
	return i_occur;
}
template <class T>
void CMyOctNode<T>::show(){
    cout << "This Node holds data at " << this << endl;
    Datum->show();
    cout <<  "This Node points to " << ptrUpperSouthWest << " to the USW " << endl;
    cout <<  "This Node points to " << ptrUpperNorthWest << " to the UNW " << endl;
    cout <<  "This Node points to " << ptrUpperNorthEast << " to the UNE " << endl;
    cout <<  "This Node points to " << ptrUpperSouthEast << " to the USE " << endl;

    cout <<  "This Node points to " << ptrLowerSouthWest << " to the LSW " << endl;
    cout <<  "This Node points to " << ptrLowerNorthWest << " to the LNW " << endl;
    cout <<  "This Node points to " << ptrLowerNorthEast << " to the LNE " << endl;
    cout <<  "This Node points to " << ptrLowerSouthEast << " to the LSE " << endl;
}
