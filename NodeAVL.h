//-------------------------------------------------------------------------------
// Copyright 2003 Christopher Godsalve.
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
//--------------------------------------------------------------------------------
template <class T>
class CMyNode2{
public:
	CMyNode2();
	~CMyNode2(){cout << "destroying Node" << endl;}
	CMyNode2(CMyNode2&);
	void SetNode(T&, CMyNode2&, CMyNode2&);
	void SetNode(T*, CMyNode2*, CMyNode2*);

	void SetNode(CMyNode2&, CMyNode2&);
	void SetNode(CMyNode2*, CMyNode2*);

	void SetNode(CMyNode2&,char);
	void SetNode(CMyNode2*,char);

	void SetNode(T&, CMyNode2&,char);
	void SetNode(T*, CMyNode2*,char);

	void SetNode(T&);
	void SetNode(T*);

	void SetNode(CMyNode2&);
	void SetNode(CMyNode2*);

	CMyNode2* GetLeft();
	CMyNode2* GetRight();
	T* GetDatumPtr();

	int Compare(CMyNode2*);
	int Compare(CMyNode2&);
	CMyNode2& operator=(CMyNode2&);
	CMyNode2* operator=(CMyNode2*);

	void IncOccur();  //increment and decrement for i_occur
	void DecOccur();
	int GetOccur();

	void show();

	int GetHeight();
	void SetHeight(int);

private:
	CMyNode2* ptrNodeLeft;
	CMyNode2* ptrNodeRight;
	T* Datum;
	int i_occur;
	int i_height;
};
template <class T>
CMyNode2<T>::CMyNode2(){
	ptrNodeLeft=NULL;
	ptrNodeRight=NULL;
	Datum=new T;
	CMyNullCheck<T> returnNullDatum;
	returnNullDatum.MyCheck(Datum);
	i_occur=0;
	i_height=0;
}
template <class T>
CMyNode2<T>::CMyNode2(CMyNode2<T>& rhs)
{
	ptrNodeLeft=new CMyNode2;
		CMyNullCheck<CMyNode2> returnNullNode;
		CMyNullCheck<T> returnNullDatum;

		returnNullNode.MyCheck(ptrNodeLeft);
		ptrNodeRight=new CMyNode2;
		returnNullNode.MyCheckPtr(ptrNodeRight);
		Datum=new T;
		returnNullDatum.MyCheckPtr(Datum);

	//char which='l';
	ptrNodeLeft=rhs.GetLeft();
	//which='r';
	ptrNodeRight=rhs.GetRight();

	Datum=rhs.GetDatumPtr();
	cout << " Node Copied!" << endl;

}

template <class T>
CMyNode2<T>* CMyNode2<T>::GetLeft(){
	return ptrNodeLeft;
}
template <class T>
CMyNode2<T>* CMyNode2<T>::GetRight(){
	return ptrNodeRight;
}
template <class T>
T* CMyNode2<T>::GetDatumPtr(){
	return Datum;
}
template <class T>
void CMyNode2<T>::SetNode(T& Object,CMyNode2<T>& NodeL, CMyNode2<T>& NodeR){
	ptrNodeLeft=&NodeL; 
	ptrNodeRight=&NodeR
	*Datum=Object;
} 
template <class T>
void CMyNode2<T>::SetNode(T* Object,CMyNode2<T>* NodeL, CMyNode2<T>* NodeR){
	ptrNodeLeft=NodeL; 
	ptrNodeRight=NodeR
	*Datum=*Object;
} 
template <class T>
void CMyNode2<T>::SetNode(CMyNode2<T>& NodeL, CMyNode2<T>& NodeR){
	ptrNodeLeft=&NodeL; 
	ptrNodeRight=&NodeR;
} 
template <class T>
void CMyNode2<T>::SetNode(CMyNode2<T>*NodeL, CMyNode2<T>* NodeR){
	ptrNodeLeft=NodeL; 
	ptrNodeRight=NodeR;
} 
template <class T>
void CMyNode2<T>::SetNode(CMyNode2<T>& NodeWhich, char which){
	if(which=='l' || which=='L'){
		ptrNodeLeft=&NodeWhich;
	}
    if(which=='r' || which=='R'){
		ptrNodeRight=&NodeWhich;
	}
//	cout << "Node direction failed" << endl;
//	throw;
} 
template <class T>
void CMyNode2<T>::SetNode(CMyNode2<T>* NodeWhich, char which){
		if(which=='l' || which=='L'){
		ptrNodeLeft=NodeWhich;
	}
    if(which=='r' || which=='R'){
		ptrNodeRight=NodeWhich;
	}
// cout << "Node direction failed" << endl;
// throw;
}
template <class T>
void CMyNode2<T>::SetNode(T& Object, CMyNode2<T>& NodeWhich, char which){
	if(which=='l' || which=='L'){
		ptrNodeLeft=&NodeWhich;
	}
    if(which=='r' || which=='R'){
		ptrNodeRight=&NodeWhich;
	}
	*Datum=Object;
//	cout << "Node direction failed" << endl;
//	throw;
} 
template <class T>
void CMyNode2<T>::SetNode(T* Object, CMyNode2<T>* NodeWhich, char which){
		if(which=='l' || which=='L'){
		ptrNodeLeft=NodeWhich;
	}
    if(which=='r' || which=='R'){
		ptrNodeRight=NodeWhich;
	}
	*Datum=Object;

//	cout << "Node direction failed" << endl;
//	throw;
}
template <class T>
void CMyNode2<T>::SetNode(T* Object){
	*Datum=*Object;
}
template <class T>
void CMyNode2<T>::SetNode(T& Object){
	*Datum=Object;
}

template <class T>
void CMyNode2<T>::SetNode(CMyNode2& ToSet){
	*Datum=ToSet.GetDatumPtr();
}
template <class T>
void CMyNode2<T>::SetNode(CMyNode2* ToSet){
	*Datum=*(ToSet->GetDatumPtr());
}
template <class T>
void CMyNode2<T>::show(){
	cout << "This node holds data at " << this << endl;
	Datum->show();
	cout << " I Point to " << ptrNodeLeft << endl;
	cout << "On the Left" << endl;
	cout << " I Point to " << ptrNodeRight << endl;
	cout << "On the Right" << endl;
	if(ptrNodeLeft)
	cout << "My Left Node has a subtree that is " << ptrNodeLeft->GetHeight() << " deep "<< endl;
	else
		cout << "My Left Node is NULL" << endl;
	if(ptrNodeRight)
	cout << "My Right Node has a subtree that is " << ptrNodeRight->GetHeight() << " deep "<< endl;
	else
		cout << "My Right Node is NULL"   << endl;
}
template <class T>
int CMyNode2<T>::Compare(CMyNode2<T>* rhs)
{
	int i=Datum->Compare(rhs->GetDatumPtr());
    return i;
}
template <class T>
int CMyNode2<T>::Compare(CMyNode2<T>& rhs)
{
	int i=Datum->Compare(rhs.GetDatumPtr() );
	return i;
} 
template <class T>
CMyNode2<T>& CMyNode2<T>::operator=(CMyNode2<T>& rhs)
{
	if(this == &rhs)
		return *this;

	*Datum=rhs.GetDatumPtr();

	ptrNodeLeft=rhs.GetLeft();
	ptrNodeRight=rhs.GetRight();
	return *this;
}
template <class T>
CMyNode2<T>* CMyNode2<T>::operator=(CMyNode2<T>* rhs)
{
	if(this == rhs)
		return this;


	*Datum=*(rhs->GetDatumPtr());

	//char which;

	//which='l';
	ptrNodeLeft=rhs->GetLeft();
	//which='r';
	ptrNodeRight=rhs->GetRight(which);
	return this;
}
template <class T>
void CMyNode2<T>::IncOccur(){
i_occur++;
}
template <class T>
void CMyNode2<T>::DecOccur(){
i_occur--;
}
template <class T>
int CMyNode2<T>::GetOccur(){
	return i_occur;
}
template <class T>
int CMyNode2<T>::GetHeight(){
	return i_height;
}
template <class T>
void CMyNode2<T>::SetHeight(int k){
	i_height=k;
}
