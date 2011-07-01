//-------------------------------------------------------------------------------
// Copyright 2003-2004 Christopher Godsalve.
// All Rights Reserved.
//
// Permission to use, copy, modify and distribute this software and its
// documentation for educational, research and non-profit purposes, without fee,
// and without a written agreement is hereby granted, provided that the above
// copyright notice - this paragraph - and the following three paragraphs appear in all copies.
//
// To request permission to incorporate this software into commercial products
// contact Dr C. Godsalve, 42 Swainstone Road, Reading, Berks, UK or by email at
// tethysgods@yahoo.com.
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
//

// Note that taking a node out of the list does not delete it
// Deleting a node works recursively, so deleting the head node
// deletes the entire list

// To delete just the data in a node no longer in the lists
// requires separate functionality

//  Just adding and taking off the top we have a stack
//  Just adding to the top and taking of the bottom we have a queue
//  Otherwise, we have a fully functional linked list.
//  We can knock out or put in  a new node anywhere

template <class T>
class CMyLinkedList{
  
    public:
       CMyLinkedList();
       ~CMyLinkedList();

        void AddToTop(T&);
        void AddToTop(T*);

        void AddToBottom(T &);
        void AddToBottom(T *);

	void AddAfterN(T&, int);
	void AddAfterN(T*, int);

	void SubtractNth(int);
        void SubtractFirst();

        
        void show();

	CMyLinkedList& operator=(CMyLinkedList&);
	CMyLinkedList* operator=(CMyLinkedList*);

        int GetLength(){return listlength;}

        T* GetHead(){return HeadNode;}
        T* GetTail(){return TailNode;}
        T* GetBottom(){return Bottom;}


    private:
      T*  HeadNode;
      T*  TailNode;
      T*  Bottom; //keeps track of what points to tail node
      int listlength;
};

template <class T>
CMyLinkedList<T>::CMyLinkedList(){
     HeadNode=new T; 
     TailNode=new T; 
     HeadNode->SetNode(TailNode);
     Bottom=HeadNode;
     listlength=0;
}
template <class T>
CMyLinkedList<T>::~CMyLinkedList(){
     // Note, deleting any node
     // calls delete on the node that it points and so
     // the destructor is called recursively.
     // Deleting the head node deletes the entire list,
     // deleting any node in the list deletes the part of the list
     // below it
     //Deleting the HeadNode deletes the TailNode
     delete HeadNode;
   //  delete TailNode;
     HeadNode=NULL;
     Bottom=NULL;
     TailNode=NULL;
   //  cout << " List Deleted ";
}
template <class T>
void CMyLinkedList<T>::AddToTop(T& ToAdd){
   if(listlength==0)Bottom=&ToAdd;
   ToAdd.SetNode(HeadNode->GetNextPtr() );
   HeadNode->SetNode(ToAdd);
   listlength++;
}
template <class T>
void CMyLinkedList<T>::AddToTop(T* ToAdd){
   if(listlength==0)Bottom=ToAdd;
   ToAdd->SetNode(HeadNode->GetNextPtr() );
   HeadNode->SetNode(ToAdd);
   listlength++;
}
template <class T>
void CMyLinkedList<T>::AddToBottom(T* ToAdd){
      Bottom->SetNode(ToAdd);
      ToAdd->SetNode(TailNode);
      Bottom=ToAdd;
      listlength++;
}
template <class T>
void CMyLinkedList<T>::AddToBottom(T& ToAdd){
      Bottom->SetNode(ToAdd);
      ToAdd.SetNode(TailNode);
      Bottom=&ToAdd;
      listlength++;
}
template <class T> 
void CMyLinkedList<T>::show(){
   T* TempNode;
   TempNode=HeadNode;
   for(int i=0; i< listlength;i++){
      TempNode=TempNode->GetNextPtr();
      TempNode->show();
   }
}
template <class T>
void CMyLinkedList<T>::AddAfterN(T* ToAdd, int iadd){
	if(iadd >= listlength){
	cout <<	"i_add too big in AddAfter N" << endl;
	throw;
	}

	T* TempNode1;
	TempNode1=HeadNode;
	for(int i=1; i <= iadd; i++){
		TempNode1=TempNode1->GetNextPtr();
	}
	T* TempNode2;
	TempNode2=TempNode1->GetNextPtr();
	TempNode1->SetNode(ToAdd);
	ToAdd->SetNode(TempNode2);
        listlength++;
}
template <class T>
void CMyLinkedList<T>::AddAfterN(T& ToAdd, int iadd){
	if(iadd >= listlength){
	cout <<	"i_add too big in AddAfter N" << endl;
	throw;
	}

	T* TempNode1;
	TempNode1=HeadNode;
	for(int i=1; i <= iadd; i++){
		TempNode1=TempNode1->GetNextPtr();
	}
	T* TempNode2;
	TempNode2=TempNode1->GetNextPtr();
	TempNode1->SetNode(ToAdd);
	ToAdd.SetNode(TempNode2);
        listlength++;
}
template <class T>
void CMyLinkedList<T>::SubtractNth(int isub){
	if(isub > listlength){
	cout <<	"i_sub too big in Suntract Nth" << endl;
	throw;
	}

	T* TempNode1;
	TempNode1=HeadNode;
	for(int i=1; i <= isub-1; i++){
		TempNode1=TempNode1->GetNextPtr();
	}
	T* TempNode2, *TempNode3;
	TempNode2=TempNode1->GetNextPtr();
	TempNode3=TempNode2;
	TempNode2=TempNode2->GetNextPtr();
	TempNode1->SetNode(TempNode2);
        listlength--;
}
template <class T>
void CMyLinkedList<T>::SubtractFirst(){
	T* TempNode1;
	TempNode1=HeadNode->GetNextPtr();
	T* TempNode2;
	TempNode2=TempNode1->GetNextPtr();
	HeadNode->SetNode(TempNode2);
	listlength--;
	if(listlength==1){
		Bottom=TempNode2;
	}
        listlength--;
}
template <class T>
CMyLinkedList<T>& CMyLinkedList<T>::operator=(CMyLinkedList<T>& rhs){
             //Assumes LHS exists already

              HeadNode=rhs.GetHead();
              TailNode=rhs.GetTail();
              Bottom=rhs.GetBottom();

             return *this;
}
template <class T>
CMyLinkedList<T>* CMyLinkedList<T>::operator=(CMyLinkedList<T>* rhs){
               if(rhs){
                 HeadNode=rhs->GetHead();
                 TailNode=rhs->GetTail();
                 Bottom=rhs->GetBottom();
                 return this;
                }
                else
                {
                 HeadNode=NULL;
                 TailNode=NULL;
                 Bottom=NULL;
                 return this;
                }
}
