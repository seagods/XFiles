template <class T>
class CMyNode1{

   public:

     CMyNode1();
     ~CMyNode1();
     CMyNode1(CMyNode1 &);

     void SetNode(T&,CMyNode1 &);
     void SetNode(T*,CMyNode1 *);

     void SetNode(T&);
     void SetNode(T*);

     void SetNode(CMyNode1 &);
     void SetNode(CMyNode1 *);

     CMyNode1* GetNextPtr();

     T* GetDatumPtr();

     CMyNode1& operator=(CMyNode1&);
     CMyNode1* operator=(CMyNode1*);

     int Compare(CMyNode1 &);
     int Compare(CMyNode1 *);
     void show();

     private:

     CMyNode1 *ptrNode1;
     T*  Datum;
};
template <class T>
CMyNode1<T>::CMyNode1(){
   CMyNullCheck<T> checkit;
   ptrNode1=NULL;
   Datum=new T;

   checkit.MyCheck(Datum);
}
template <class T>
CMyNode1<T>::~CMyNode1(){
     delete Datum;
     Datum=NULL;
     delete ptrNode1;
     ptrNode1=NULL;

 //   cout << "node deletion\n";
}

template <class T>
CMyNode1<T>::CMyNode1(CMyNode1<T>& rhs){
CMyNullCheck<T> checkdatum;
CMyNullCheck<CMyNode1> checknode;

  ptrNode1=new CMyNode1;

  Datum=new T;
  checkdatum.MyCheck(Datum);
  checknode.MyCheck(ptrNode1);

  ptrNode1=rhs.GetNextPtr();
  Datum=rhs.GetDatumPtr();
}

template <class T>
void CMyNode1<T>::SetNode(T& Object,CMyNode1<T> &Node){
      ptrNode1=&Node;
      *Datum=Object;
}

template <class T>
void CMyNode1<T>::SetNode(T& Object){
      *Datum=Object;
}
template <class T>
void CMyNode1<T>::SetNode(T* Object){
      *Datum=*Object;
}

template <class T>
void CMyNode1<T>::SetNode(CMyNode1<T> &Node){
      ptrNode1=&Node;
}

template <class T>
void CMyNode1<T>::SetNode(CMyNode1<T> *Node){
      ptrNode1=Node;
}

template <class T>
void CMyNode1<T>::SetNode(T* Object,CMyNode1<T> *Node){
      ptrNode1=Node;
      *Datum=*Object;
}

template <class T>
CMyNode1<T>*  CMyNode1<T>::GetNextPtr(){
     return ptrNode1;
}

template <class T>
T* CMyNode1<T>::GetDatumPtr(){
    return Datum;
}

template <class T>
CMyNode1<T>& CMyNode1<T>::operator=(CMyNode1<T>& rhs){
//Warning, assumes lhs exists already
 if(this == &rhs)return *this;
Datum=rhs.GetDatumPtr();
ptrNode1=rhs.GetNextPtr();
return this;
}

template <class T>
CMyNode1<T>* CMyNode1<T>::operator=(CMyNode1<T>* rhs){
//Warning, assumes lhs exists already
 if(this == &rhs)return *this;
Datum=rhs->GetDatumPtr();
ptrNode1->rhs.GetNextPtr();
return this;
}

template <class T>
int CMyNode1<T>::Compare(CMyNode1<T>* rhs){
  int i=Datum->Compare(rhs.GetDatumPtr() );
  return i;
}
template <class T>
int CMyNode1<T>::Compare(CMyNode1<T>& rhs){
  int i=Datum->Compare(rhs.GetDatumPtr() );
  return i;
}
template <class T>
void CMyNode1<T>::show(){
    cout << " Node holds data at " << this << endl;
    Datum->show();
    cout << " and points to " << ptrNode1 << endl;
}
