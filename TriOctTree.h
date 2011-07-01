//-------------------------------------------------------------------------------
// Copyright 2008 Christopher Godsalve.
// All Rights Reserved.
//
// Permission to use, copy, modify and distribute this software and its
// documentation for educational, research and non-profit purposes, without fee,
// and without a written agreement is hereby granted, provided that the above
// copyright notice - this paragraph -  and the following three paragraphs appear in all copies.
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


double const Overlap=0.1; 
void  TestTri(
        int itri, double x1, double x2, double y1, double y2, 
	double z1, double z2,
	bool &lsw, bool &lse, bool &lnw, bool &lne,
       	bool &usw, bool &use, bool &unw, bool &une);

void  TestPos(
        D3Dvec&, double x1, double x2, double y1, double y2, 
	double z1, double z2,
	bool &lsw, bool &lse, bool &lnw, bool &lne,
       	bool &usw, bool &use, bool &unw, bool &une);

 //  Make the zones of the tree overlap slightly, must be small!

template <class T>
class CMyTriOctTree{
public:
	CMyTriOctTree();
	~CMyTriOctTree();
	T*  AddToTree(double,double,double,double,double,double, int , int );
	void  GetList(intList**, D3Dvec& ,double,double,double,double,double,double, int );
	T* GetRoot();
	void SetRoot(T*  NewRoot);
        int WriteTheTree(T*);

        int GetNumberNodes(){return i_NodesInTree;}
        void IncNodesInTree(){i_NodesInTree++;}


private:
	T* RootNode;
        static int i_NodesInTree;

};
template <class T>
int CMyTriOctTree<T>::i_NodesInTree=0;
//**********************************************************
	//Constructor
//**********************************************************
template <class T>
CMyTriOctTree<T>::CMyTriOctTree(){
	RootNode=NULL;
        i_NodesInTree=0;
}
template <class T>
CMyTriOctTree<T>::~CMyTriOctTree(){
        delete RootNode;
	RootNode=NULL;
}
//**********************************************************
	//GetRoot
//**********************************************************
template <class T>
T* CMyTriOctTree<T>::GetRoot(){
	return RootNode;
}
template <class T>
void CMyTriOctTree<T>::SetRoot(T* NewRoot){
  RootNode=NewRoot;
}
template <class T>
int CMyTriOctTree<T>::WriteTheTree(T* TheNode){

	T *Direction;

        Direction=TheNode->GetUpperSouthWest();
        if(Direction)WriteTheTree(Direction);


        Direction=TheNode->GetUpperNorthWest();
        if(Direction)WriteTheTree(Direction);


        Direction=TheNode->GetUpperNorthEast();
        if(Direction)WriteTheTree(Direction);


        Direction=TheNode->GetUpperSouthEast();
        if(Direction)WriteTheTree(Direction);

        Direction=TheNode->GetLowerSouthWest();
        if(Direction)WriteTheTree(Direction);


        Direction=TheNode->GetLowerNorthWest();
        if(Direction)WriteTheTree(Direction);


        Direction=TheNode->GetLowerNorthEast();
        if(Direction)WriteTheTree(Direction);


        Direction=TheNode->GetLowerSouthEast();
        if(Direction)WriteTheTree(Direction);

        TheNode->show();
        int i=TheNode->GetOccur();
	return 0;
}
template <class T>
T* CMyTriOctTree<T>::AddToTree(double x1, double x2, double y1, double y2
                                , double z1, double z2, int itri, int Depth){

	int i,j,k,i1,i2,j1,j2,k1,k2;

	intList* LocalTri=NULL;
	ListNode* NodeX;

        int  nvert=3;
        //bools for triangles
        bool lsw, lse, lne, lnw, unw, une, usw, use; 
        lsw=false;lse=false;lne=false;lnw=false;
        unw=false;une=false;usw=false;use=false;

        TestTri(itri,x1,x2,y1,y2,z1,z2,lsw,lse,lnw,lne,usw,use,unw,une);

	double x1old,x2old,y1old,y2old,z1old,z2old;
	x1old=x1; x2old=x2;
	y1old=y1; y2old=y2;
	z1old=z1; z2old=z2;


              int count=0;
              if(une)count++;            
              if(unw)count++;            
              if(use)count++;            
              if(usw)count++;            
              if(lne)count++;            
              if(lnw)count++;            
              if(lse)count++;            
              if(lsw)count++;            

	T* OtherNode;
        RootNode=this->GetRoot();
	if(RootNode==NULL)
	{
                T *RootNode=new T;
		RootNode->IncOccur();
		this->SetRoot(RootNode);

               // cout <<"ROOT OF TREE=" << RootNode << endl;
                if(count==0){
		LocalTri=new intList;
	 	NodeX=new ListNode;
		NodeX->SetNode(itri);
		LocalTri->AddToTop(NodeX); 
                RootNode->SetList(LocalTri);

	//	cout  << "A Snark! Adding to current root list\n";
	//	cout  << "Tree Node=" << RootNode << endl;
	//	cout  << "List=" << LocalTri<< endl;  

		return RootNode;
		}
        }
	//cout <<  "Root=" << RootNode << endl;

	OtherNode=RootNode;

	T* UpperNorthWest; 
	T* UpperNorthEast; 
	T* UpperSouthWest; 
	T* UpperSouthEast; 

	T* LowerNorthWest; 
	T* LowerNorthEast; 
	T* LowerSouthWest; 
	T* LowerSouthEast; 

        T* ReturnNode;

       UpperNorthEast=RootNode->GetUpperNorthEast();
       UpperNorthWest=RootNode->GetUpperNorthWest();	
       UpperSouthEast=RootNode->GetUpperSouthEast();
       UpperSouthWest=RootNode->GetUpperSouthWest();	

       LowerNorthEast=RootNode->GetLowerNorthEast();
       LowerNorthWest=RootNode->GetLowerNorthWest();	
       LowerSouthEast=RootNode->GetLowerSouthEast();
       LowerSouthWest=RootNode->GetLowerSouthWest();	

       bool verbose=false;


              if(count ==0  && Depth <= MD){
                // The polygon has nodes in more than one octant
				   //Add to list of polygons
				   //Node GetList is not recursive (returns intList*)
				   //Tree GetList is (void return)
		// If count=MD no need to create an extra list
		// as it is taken care of by the if{Depth <MD} else {Add to List}
		// later

                                      LocalTri=RootNode->GetList();
                                      if(LocalTri==NULL){
                                         LocalTri=new intList;
                                         RootNode->SetList(LocalTri);
					      if(verbose){
	        cout  << "A Snark! Adding list to current root="<< RootNode << endl;
		cout  << "Tree Node=" << RootNode << endl;
		cout  << "List=" << LocalTri<< endl; }
                                      }
				      NodeX=new ListNode;
				      NodeX->SetNode(itri);
                                      LocalTri->AddToTop(NodeX);
				      if(verbose)
     cout << "Adding " << itri << " to List " <<LocalTri << " Depth=" << Depth << endl;
	                              RootNode=OtherNode;
                                      return RootNode;
              }

	      //count >=1
	      //(Same triangle can appear in different lists)
	      //(if count >1 we are at max depth and just add to list anyway)

                    if(lsw){
                                   if(Depth <  MD){
                                        x2=x1+(x2-x1)/2.0*(1.0+Overlap);
                                        y2=y1+(y2-y1)/2.0*(1.0+Overlap);
                                        z2=z1+(z2-z1)/2.0*(1.0+Overlap);

 					if(!LowerSouthWest){
   				   	  LowerSouthWest=new T;
					  if(verbose)
                cout << "Setting "<< RootNode << "  LSW to  " <<LowerSouthWest << endl;
					  RootNode->
					  SetNode(LowerSouthWest, 'w', 's', 'l');
     					} 
                                        Depth++;
					if(verbose)
		cout << RootNode <<"  branching to LSW  " << LowerSouthWest << endl;
                                        RootNode=LowerSouthWest;
					ReturnNode=this->
					AddToTree(x1,x2,y1,y2,z1,z2,itri,Depth);
					Depth--;
					RootNode=OtherNode;
					x1=x1old; x2=x2old;
					y1=y1old; y2=y2old;
					z1=z1old; z2=z2old;
					//in case say, une is also true
					//we have to reset Depth to current level
				   }
				   else
				   {
				   //Add to list of polygons
                                       LocalTri=RootNode->GetList();
                                       if(LocalTri==NULL){
                                         LocalTri=new intList;
                                         RootNode->SetList(LocalTri);

					if(verbose){
		cout  << "Adding list to current Tree root="<< RootNode << endl;
		cout  << "List=" << LocalTri<< endl; }
                                       }
				      NodeX=new ListNode;
				      NodeX->SetNode(itri);
                                      LocalTri->AddToTop(NodeX);
					if(verbose)
      cout << "Adding " << itri << " to List " <<LocalTri << " Depth=" << Depth << endl;
				      RootNode=OtherNode;
				      return RootNode;
                                   }  
                           }
                           if(lnw){
                                   if(Depth <  MD){
                                        x2=x1+(x2-x1)/2.0*(1.0+Overlap);
                                        y1=y1+(y2-y1)/2.0*(1.0-Overlap);
					z2=z1+(z2-z1)/2.0*(1.0+Overlap);

      					if(!LowerNorthWest){
       					  LowerNorthWest=new T;
					if(verbose)
                cout << "Setting "<< RootNode << "  LNW to  " <<LowerNorthWest << endl;
				 	  RootNode->
					  SetNode(LowerNorthWest, 'w', 'n', 'l');
      					}
					Depth++;
					if(verbose)
		cout << RootNode <<"  branching to LNW  " << LowerNorthWest << endl;
                                        RootNode=LowerNorthWest;
					ReturnNode=this->
					AddToTree(x1,x2,y1,y2,z1,z2,itri,Depth);
					Depth--;
					RootNode=OtherNode;
					x1=x1old; x2=x2old;
					y1=y1old; y2=y2old;
					z1=z1old; z2=z2old;
					//in case say, une is also true
					//we have to reset Depth to current level
                                   }
                                   else
                                   {
                                   //Add to list of polygons
                                       LocalTri=RootNode->GetList();
                                       if(LocalTri==NULL){
                                         LocalTri=new intList;
                                         RootNode->SetList(LocalTri);
					if(verbose){
		cout  << "Adding list to current Tree root="<< RootNode << endl;
		cout  << "List=" << LocalTri<< endl; }
                                       }
				      NodeX=new ListNode;
				      NodeX->SetNode(itri);
                                      LocalTri->AddToTop(NodeX);
					if(verbose)
       cout << "Adding " << itri << " to List " <<LocalTri << " Depth=" << Depth << endl;
				      RootNode=OtherNode;
				      return RootNode;
                                   }
                              }
                              if(lse){
                                   if(Depth <  MD){

                                        x1=x1+(x2-x1)/2.0*(1.0-Overlap);
                                        y2=y1+(y2-y1)/2.0*(1.0+Overlap);
                                        z2=z1+(z2-z1)/2.0*(1.0+Overlap);

  				        if(!LowerSouthEast){
       					  LowerSouthEast=new T;
					if(verbose)
                cout << "Setting "<< RootNode << "  LSE to  " <<LowerSouthEast << endl;
					  RootNode->
					  SetNode(LowerSouthEast, 'e', 's', 'l');
      				        }
                                        Depth++;
					if(verbose)
		cout << RootNode <<"  branching to LSE  " << LowerSouthEast<< endl;
                                        RootNode=LowerSouthEast;
					ReturnNode=this->
					AddToTree(x1,x2,y1,y2,z1,z2,itri,Depth);
					Depth--;
					RootNode=OtherNode;
					x1=x1old; x2=x2old;
					y1=y1old; y2=y2old;
					z1=z1old; z2=z2old;
					//in case say, une is also true
					//we have to reset Depth to current level
                                   }
                                   else
                                   {
                                   //Add to list of polygons
                                       LocalTri=RootNode->GetList();
                                       if(LocalTri==NULL){
                                         LocalTri=new intList;
                                         RootNode->SetList(LocalTri);
					if(verbose){
		cout  << "Adding list to current Tree root="<< RootNode << endl;
		cout  << "List=" << LocalTri<< endl;} 
                                       }
				      NodeX=new ListNode;
				      NodeX->SetNode(itri);
                                      LocalTri->AddToTop(NodeX);
					if(verbose)
  cout << "Adding " << itri << " to List " <<LocalTri << " Depth=" << Depth << endl;
				      RootNode=OtherNode;
				      return RootNode;
                                   }
                              }
                              if(lne){
                                   if(Depth <  MD){
                                        x1=x1+(x2-x1)/2.0*(1.0-Overlap);
                                        y1=y1+(y2-y1)/2.0*(1.0-Overlap);
                                        z2=z1+(z2-z1)/2.0*(1.0+Overlap);
                                        if(!LowerNorthEast){
       					  LowerNorthEast=new T;
					if(verbose)
                cout << "Setting "<< RootNode << "  LNE to  " <<LowerNorthEast << endl;
					  RootNode->
					  SetNode(LowerNorthEast, 'e', 'n', 'l');
                                        }
                                        Depth++;
					if(verbose)
		cout << RootNode <<"  branching to LNE  " << LowerNorthEast<< endl;
                                        RootNode=LowerNorthEast;
					ReturnNode=this->
					AddToTree(x1,x2,y1,y2,z1,z2,itri,Depth);
					Depth--;
					RootNode=OtherNode;
					x1=x1old; x2=x2old;
					y1=y1old; y2=y2old;
					z1=z1old; z2=z2old;
					//in case say, une is also true
					//we have to reset Depth to current level
                                   }
                                   else
                                   {
                                   //Add to list of polygons
                                       LocalTri=RootNode->GetList();
                                       if(LocalTri==NULL){
                                         LocalTri=new intList;
                                         RootNode->SetList(LocalTri);
					if(verbose){
		cout  << "Adding list to current Tree root="<< RootNode << endl;
		cout  << "List=" << LocalTri<< endl; }
                                       }
				      NodeX=new ListNode;
				      NodeX->SetNode(itri);
                                      LocalTri->AddToTop(NodeX);
					if(verbose)
      cout << "Adding " << itri << " to List " <<LocalTri << " Depth=" << Depth << endl;
				      RootNode=OtherNode;
				      return RootNode;
                                   }
	               	   }              

                           if(usw){
                                   if(Depth <  MD){
                                        x2=x1+(x2-x1)/2.0*(1.0+Overlap);
                                        y2=y1+(y2-y1)/2.0*(1.0+Overlap);
                                        z1=z1+(z2-z1)/2.0*(1.0-Overlap);
                                        if(!UpperSouthWest){
       					  UpperSouthWest=new T;
					if(verbose)
                cout << "Setting "<< RootNode << "  USW to  " <<UpperSouthWest << endl;
					  RootNode->
					  SetNode(UpperSouthWest, 'w', 's', 'u');
                                        }
                                        Depth++;
					if(verbose)
		cout << RootNode <<"  branching to USW " << UpperSouthWest<< endl;
                                        RootNode=UpperSouthWest;
					ReturnNode=this->
					AddToTree(x1,x2,y1,y2,z1,z2,itri,Depth);
					Depth--;
					RootNode=OtherNode;
					x1=x1old; x2=x2old;
					y1=y1old; y2=y2old;
					z1=z1old; z2=z2old;
					//in case say, une is also true
					//we have to reset Depth to current level
                                   }
                                   else
                                   {
                                   //Add to list of polygons
                                       LocalTri=RootNode->GetList();
                                       if(LocalTri==NULL){
                                         LocalTri=new intList;
                                         RootNode->SetList(LocalTri);
					if(verbose){
		cout  << "Adding list to current Tree root="<< RootNode << endl;
		cout  << "List=" << LocalTri<< endl; }
                                       }
				      NodeX=new ListNode;
				      NodeX->SetNode(itri);
					if(verbose)
       cout << "Adding " << itri << " to List " <<LocalTri << " Depth=" << Depth << endl;
                                      LocalTri->AddToTop(NodeX);
				      RootNode=OtherNode;
				      return RootNode;
                                   }
		             }
                             if(unw){
                                   if(Depth <  MD){
                                        x2=x1+(x2-x1)/2.0*(1.0+Overlap);
                                        y1=y1+(y2-y1)/2.0*(1.0-Overlap);
                                        z1=z1+(z2-z1)/2.0*(1.0-Overlap);
                                        if(!UpperNorthWest){
       					  UpperNorthWest=new T;
					if(verbose)
         cout << "Setting "<< RootNode << "  UNW to  " <<UpperNorthWest << endl;
					  RootNode->
					  SetNode(UpperNorthWest, 'w', 'n', 'u');
                                        }
                                        Depth++;
					if(verbose)
	cout << RootNode <<"  branching to UNW " << UpperNorthWest<< endl;
                                        RootNode=UpperNorthWest;
					ReturnNode=this->
					AddToTree(x1,x2,y1,y2,z1,z2,itri,Depth);
					Depth--;
					RootNode=OtherNode;
					x1=x1old; x2=x2old;
					y1=y1old; y2=y2old;
					z1=z1old; z2=z2old;
					//in case say, une is also true
					//we have to reset Depth to current level
                                   }
                                   else
                                   {
                                   //Add to list of polygons
                                       LocalTri=RootNode->GetList();
                                       if(LocalTri==NULL){
                                         LocalTri=new intList;
                                         RootNode->SetList(LocalTri);
					if(verbose){
		cout  << "Adding list to current Tree root="<< RootNode << endl;
		cout  << "List=" << LocalTri<< endl; }
                                       }
				      NodeX=new ListNode;
				      NodeX->SetNode(itri);
                                      LocalTri->AddToTop(NodeX);
					if(verbose)
      cout << "Adding " << itri << " to List " <<LocalTri << " Depth=" << Depth << endl;
				      RootNode=OtherNode;
				      return RootNode;
                                   }
                              }
			     if(use){
                                   if(Depth <  MD){
                                        x1=x1+(x2-x1)/2.0*(1.0-Overlap);
                                        y2=y1+(y2-y1)/2.0*(1.0+Overlap);
                                        z1=z1+(z2-z1)/2.0*(1.0-Overlap);
                                        if(!UpperSouthEast){
       					  UpperSouthEast=new T;
					if(verbose)
                cout << "Setting "<< RootNode << " USE to  " <<UpperSouthEast << endl;
					  RootNode->
					  SetNode(UpperSouthEast, 'e', 's', 'u');
                                         }
                                        Depth++;
					if(verbose)
		cout << RootNode <<"  branching to USE  " << UpperSouthEast<< endl;
                                        RootNode=UpperSouthEast;
					ReturnNode=this->
					AddToTree(x1,x2,y1,y2,z1,z2,itri,Depth);
					Depth--;
					RootNode=OtherNode;
					x1=x1old; x2=x2old;
					y1=y1old; y2=y2old;
					z1=z1old; z2=z2old;
					//in case say, une is also true
					//we have to reset Depth to current level
                                   }
                                   else
                                   {
                                   //Add to list of polygons
                                       LocalTri=RootNode->GetList();
                                       if(LocalTri==NULL){
                                         LocalTri=new intList;
                                         RootNode->SetList(LocalTri);
					if(verbose){
		cout  << "Adding list to current Tree root="<< RootNode << endl;
		cout  << "List=" << LocalTri<< endl; }
                                       }
				      NodeX=new ListNode;
				      NodeX->SetNode(itri);
                                      LocalTri->AddToTop(NodeX);
				      if(verbose)
     cout << "Adding " << itri << " to List " <<LocalTri << " Depth=" << Depth << endl;
				      RootNode=OtherNode;
				      return RootNode;
                                   }
                                }
				if(une){
                                   if(Depth <  MD){
                                        x1=x1+(x2-x1)/2.0*(1.0-Overlap);
                                        y1=y1+(y2-y1)/2.0*(1.0-Overlap);
                                        z1=z1+(z2-z1)/2.0*(1.0-Overlap);
                                        if(!UpperNorthEast){
       					  UpperNorthEast=new T;
					  if(verbose)
                cout << "Setting "<< RootNode << "  UNE to  " <<UpperNorthEast<< endl;
					  RootNode->
					  SetNode(UpperNorthEast, 'e', 'n', 'u');
                                        }
                                        Depth++;
					  if(verbose)
		cout << RootNode <<"  branching to UNE  " << UpperNorthEast<< endl;
                                        RootNode=UpperNorthEast;
					ReturnNode=this->
				        AddToTree(x1,x2,y1,y2,z1,z2,itri,Depth);
					Depth--;
					RootNode=OtherNode;
					x1=x1old; x2=x2old;
					y1=y1old; y2=y2old;
					z1=z1old; z2=z2old;
                                   }
                                   else
                                   {
                                   //Add to list of polygons
                                       LocalTri=RootNode->GetList();
                                       if(LocalTri==NULL){
                                         LocalTri=new intList;
                                         RootNode->SetList(LocalTri);
					  if(verbose){
		cout  << "Adding list to current Tree root="<< RootNode << endl;
		cout  << "List=" << LocalTri<< endl; }
                                       }
				      NodeX=new ListNode;
				      NodeX->SetNode(itri);
                                      LocalTri->AddToTop(NodeX);
				      if(verbose)
       cout << "Adding " << itri << " to List " <<LocalTri << " Depth=" << Depth << endl;
				      RootNode=OtherNode;
				      return RootNode;
                                   }
				} 

	RootNode=OtherNode;
        return RootNode;

}

int iToAddmax(int i, int j){
	if(i>j)return i;
	return j;
}
 

template <class T>
void CMyTriOctTree<T>::GetList(intList** ListArray,D3Dvec& Pos
		,double x1, double x2, double y1, double y2
                ,double z1, double z2,  int Depth){

	int icompare,jcompare,kcompare,i,j,k,i1,i2,j1,j2,k1,k2;

        double x1old, x2old, y1old, y2old, z1old, z2old;
	x1old=x1; x2old=x2; y1old=y1, y2old=y2, z1old=z1, z2old=z2;

	bool verbose=false;

        intList* LocalTri;

	// avoid repeats when icount >1
	intList* LastLocalTri;

        bool lsw, lse, lne, lnw, unw, une, usw, use; 
        lsw=false;lse=false;lne=false;lnw=false;
        unw=false;une=false;usw=false;use=false;

        TestPos(Pos,x1,x2,y1,y2,z1,z2,lsw,lse,lnw,lne,usw,use,unw,une);

	RootNode=this->GetRoot();
        T* OtherNode;
	OtherNode=RootNode;
        
         if(RootNode)
        {
	T* UpperNorthWest; 
	T* UpperNorthEast; 
	T* UpperSouthWest; 
	T* UpperSouthEast; 

	T* LowerNorthWest; 
	T* LowerNorthEast; 
	T* LowerSouthWest; 
	T* LowerSouthEast; 


       UpperNorthEast=RootNode->GetUpperNorthEast();
       UpperNorthWest=RootNode->GetUpperNorthWest();	
       UpperSouthEast=RootNode->GetUpperSouthEast();
       UpperSouthWest=RootNode->GetUpperSouthWest();	

       LowerNorthEast=RootNode->GetLowerNorthEast();
       LowerNorthWest=RootNode->GetLowerNorthWest();	
       LowerSouthEast=RootNode->GetLowerSouthEast();
       LowerSouthWest=RootNode->GetLowerSouthWest();	

       //Dont add lists here!
	       int count;
	       count=0;
	       if(use)count++;
	       if(usw)count++;
	       if(une)count++;
	       if(unw)count++;
	       if(lse)count++;
	       if(lsw)count++;
	       if(lne)count++;
	       if(lnw)count++;

	       //Note OctTree GetList is recursive, OctNode's GetList is not!

                    if(lsw){
                                   if(Depth <  MD){
                                        x2=x1+(x2-x1)/2.0*(1.0+Overlap);
                                        y2=y1+(y2-y1)/2.0*(1.0+Overlap);
                                        z2=z1+(z2-z1)/2.0*(1.0+Overlap);
                                        LocalTri=RootNode->GetList();
                                        *(ListArray+nlists)=LocalTri;
					nlists++;
					if(verbose)
			cout <<" List " << LocalTri << " Tree Node=" << RootNode 
				<< "  Depth=" << Depth << endl;
                                        Depth++;
                                        RootNode=LowerSouthWest;
					if(verbose)
			cout << "branching LSW\n";
					if(RootNode)this->
					GetList(ListArray,Pos,x1,x2,y1,y2,z1,z2,Depth);
					Depth--;
					x1=x1old; x2=x2old;
					y1=y1old; y2=y2old;
					z1=z1old; z2=z2old;
					RootNode=OtherNode;
				   }
                                   else
                                   {
                                        LocalTri=RootNode->GetList();
                                        *(ListArray+nlists)=LocalTri;
					nlists++;
					if(verbose)
			cout <<" List " << LocalTri << " Tree Node=" << RootNode 
				<< "  Depth=" << Depth << endl;
					RootNode=OtherNode;
                                   }
                           }
                           if(lnw){
                                   if(Depth <  MD){
                                        x2=x1+(x2-x1)/2.0*(1.0+Overlap);
                                        y1=y1+(y2-y1)/2.0*(1.0-Overlap);
					z2=z1+(z2-z1)/2.0*(1.0+Overlap);
					LastLocalTri=LocalTri;
                                        LocalTri=RootNode->GetList();
					if(LocalTri != LastLocalTri){
                                        *(ListArray+nlists)=LocalTri;
					nlists++;
					}
					if(verbose)
			cout <<" List " << LocalTri << " Tree Node=" << RootNode 
				<< "  Depth=" << Depth << endl;
                                        Depth++;
                                        RootNode=LowerNorthWest;
					if(verbose)
			cout << "branching LNW\n";
					if(RootNode)this->
					GetList(ListArray,Pos,x1,x2,y1,y2,z1,z2,Depth);
					Depth--;
					x1=x1old; x2=x2old;
					y1=y1old; y2=y2old;
					z1=z1old; z2=z2old;
					RootNode=OtherNode;
				   }
                                   else
                                   {
                                        LocalTri=RootNode->GetList();
                                        *(ListArray+nlists)=LocalTri;
					nlists++;
					if(verbose)
			cout <<" List " << LocalTri << " Tree Node=" << RootNode 
				<< "  Depth=" << Depth << endl;
					RootNode=OtherNode;
                                   }
                           }
                             if(lse){
                                   if(Depth <  MD){
                                        x1=x1+(x2-x1)/2.0*(1.0-Overlap);
                                        y2=y1+(y2-y1)/2.0*(1.0+Overlap);
                                        z2=z1+(z2-z1)/2.0*(1.0+Overlap);
					LastLocalTri=LocalTri;
                                        LocalTri=RootNode->GetList();
					if(LocalTri != LastLocalTri){
                                        *(ListArray+nlists)=LocalTri;
					nlists++;
					}
					if(verbose)
			cout <<" List " << LocalTri << " Tree Node=" << RootNode 
				<< "  Depth=" << Depth << endl;
                                        Depth++;
                                        RootNode=LowerSouthEast;
					if(verbose)
			cout << "branching LSE\n";
					if(RootNode)this->
					GetList(ListArray,Pos,x1,x2,y1,y2,z1,z2,Depth);
					Depth--;
					x1=x1old; x2=x2old;
					y1=y1old; y2=y2old;
					z1=z1old; z2=z2old;
					RootNode=OtherNode;
                                   }
                                   else
                                   {
                                        LocalTri=RootNode->GetList();
                                        *(ListArray+nlists)=LocalTri;
					nlists++;
					if(verbose)
			cout <<" List " << LocalTri << " Tree Node=" << RootNode 
				<< "  Depth=" << Depth << endl;
					RootNode=OtherNode;
                                   }
                              }
                              if(lne){
                                   if(Depth <  MD){
                                        x1=x1+(x2-x1)/2.0*(1.0-Overlap);
                                        y1=y2+(y2-y1)/2.0*(1.0-Overlap);
                                        z2=z1+(z2-z1)/2.0*(1.0+Overlap);
					LastLocalTri=LocalTri;
                                        LocalTri=RootNode->GetList();
					if(LocalTri != LastLocalTri){
                                        *(ListArray+nlists)=LocalTri;
					nlists++;
					}
					if(verbose)
			cout <<" List " << LocalTri << " Tree Node=" << RootNode 
				<< "  Depth=" << Depth << endl;
                                        Depth++;
                                        if(RootNode)RootNode=LowerNorthEast;
					if(verbose)
			cout << "branching LNE\n";
					this->
					GetList(ListArray,Pos,x1,x2,y1,y2,z1,z2,Depth);
					Depth--;
					x1=x1old; x2=x2old;
					y1=y1old; y2=y2old;
					z1=z1old; z2=z2old;
					RootNode=OtherNode;
                                   }
                                   else
                                   {
                                        LocalTri=RootNode->GetList();
                                        *(ListArray+nlists)=LocalTri;
					nlists++;
					if(verbose)
			cout <<" List " << LocalTri << " Tree Node=" << RootNode 
				<< "  Depth=" << Depth << endl;
					RootNode=OtherNode;
                                   }
	               	   }              

                           if(usw){
                                   if(Depth <  MD){
                                        x2=x1+(x2-x1)/2.0*(1.0+Overlap);
                                        y2=y1+(y2-y1)/2.0*(1.0+Overlap);
                                        z1=z1+(z2-z1)/2.0*(1.0-Overlap);
                                        LocalTri=RootNode->GetList();
					LastLocalTri=LocalTri;
					if(LocalTri != LastLocalTri){
                                        *(ListArray+nlists)=LocalTri;
					nlists++;
					}
					if(verbose)
			cout <<" List " << LocalTri << " Tree Node=" << RootNode 
				<< "  Depth=" << Depth << endl;
                                        Depth++;
                                        RootNode=UpperSouthWest;
					if(verbose)
			cout << "branching USW\n";
					if(RootNode)this->
					GetList(ListArray,Pos,x1,x2,y1,y2,z1,z2,Depth);
					Depth--;
					x1=x1old; x2=x2old;
					y1=y1old; y2=y2old;
					z1=z1old; z2=z2old;
					RootNode=OtherNode;
                                   }
                                   else
                                   {
                                        LocalTri=RootNode->GetList();
                                        *(ListArray+nlists)=LocalTri;
					nlists++;
					if(verbose)
			cout <<" List " << LocalTri << " Tree Node=" << RootNode 
				<< "  Depth=" << Depth << endl;
					RootNode=OtherNode;
                                   }
		             }
                             if(unw){
                                   if(Depth <  MD){
                                        x2=x1+(x2-x1)/2.0*(1.0+Overlap);
                                        y1=y1+(y2-y1)/2.0*(1.0-Overlap);
                                        z1=z1+(z2-z1)/2.0*(1.0-Overlap);
					LastLocalTri=LocalTri;
                                        LocalTri=RootNode->GetList();
					if(LocalTri != LastLocalTri){
                                        *(ListArray+nlists)=LocalTri;
					nlists++;
					}
					if(verbose)
			cout <<" List " << LocalTri << " Tree Node=" << RootNode 
				<< "  Depth=" << Depth << endl;
                                        Depth++;
                                        RootNode=UpperNorthWest;
					if(verbose)
			cout << "branching UNW\n";
					if(RootNode)this->
					GetList(ListArray,Pos,x1,x2,y1,y2,z1,z2,Depth);
					Depth--;
					x1=x1old; x2=x2old;
					y1=y1old; y2=y2old;
					z1=z1old; z2=z2old;
					RootNode=OtherNode;
                                   }
                                   else
                                   {
                                        LocalTri=RootNode->GetList();
                                        ListArray[Depth]=LocalTri;
                                        *(ListArray+nlists)=LocalTri;
					nlists++;
					if(verbose)
			cout <<" List " << LocalTri << " Tree Node=" << RootNode 
				<< "  Depth=" << Depth << endl;
					RootNode=OtherNode;
                                   }
                              }
			     if(use){
                                   if(Depth <  MD){
                                        x1=x1+(x2-x1)/2.0*(1.0-Overlap);
                                        y2=y1+(y2-y1)/2.0*(1.0+Overlap);
                                        z1=z1+(z2-z1)/2.0*(1.0-Overlap);
					LastLocalTri=LocalTri;
                                        LocalTri=RootNode->GetList();
					if(LocalTri != LastLocalTri){
                                        *(ListArray+nlists)=LocalTri;
					nlists++;
					}
					if(verbose)
			cout <<" List " << LocalTri << " Tree Node=" << RootNode 
				<< "  Depth=" << Depth << endl;
                                        Depth++;
                                        RootNode=UpperSouthEast;
					if(verbose)
			cout << "branching USE\n";
					if(RootNode)this->
					GetList(ListArray,Pos,x1,x2,y1,y2,z1,z2,Depth);
					Depth--;
					x1=x1old; x2=x2old;
					y1=y1old; y2=y2old;
					z1=z1old; z2=z2old;
					RootNode=OtherNode;
                                   }
                                   else
                                   {
                                        LocalTri=RootNode->GetList();
                                        *(ListArray+nlists)=LocalTri;
					nlists++;
					if(verbose)
			cout <<" List " << LocalTri << " Tree Node=" << RootNode 
				<< "  Depth=" << Depth << endl;
					RootNode=OtherNode;
                                   }

                              }
				if(une){
                                   if(Depth <  MD){
                                        x1=x1+(x2-x1)/2.0*(1.0-Overlap);
                                        y1=y1+(y2-y1)/2.0*(1.0-Overlap);
                                        z1=z1+(z2-z1)/2.0*(1.0-Overlap);
					LastLocalTri=LocalTri;
                                        LocalTri=RootNode->GetList();
					if(LocalTri != LastLocalTri){
                                        *(ListArray+nlists)=LocalTri;
					nlists++;
					}
					if(verbose)
			cout <<" List " << LocalTri << " Tree Node=" << RootNode 
				<< "  Depth=" << Depth << endl;
                                        Depth++;
                                        RootNode=UpperNorthEast;
					if(verbose)
			cout << "branching UNE\n";
					if(RootNode)this->
					GetList(ListArray,Pos,x1,x2,y1,y2,z1,z2,Depth);
					Depth--;
					x1=x1old; x2=x2old;
					y1=y1old; y2=y2old;
					z1=z1old; z2=z2old;
					RootNode=OtherNode;
                                   }
                                   else
                                   {
                                        LocalTri=RootNode->GetList();
                                        *(ListArray+nlists)=LocalTri;
					nlists++;
					if(verbose)
			cout <<" List " << LocalTri << " Tree Node=" << RootNode 
				<< "  Depth=" << Depth << endl;
					RootNode=OtherNode;
                                   }
				} 
           }  //endif for if(RootNode)
	 RootNode=OtherNode; //need for stack rewind to get original root back

}

void  TestPos(
        D3Dvec& Pos, double x1, double x2, double y1, double y2,
       	double z1, double z2, bool &lsw, bool &lse, bool &lnw, bool &lne, 
	bool &usw, bool &use, bool &unw, bool &une)
      {
	//centre of box
        double x,y,z;

        x=(x1+x2)/2.0;
        y=(y1+y2)/2.0;
        z=(z1+z2)/2.0;

	//next level box edges
	double xa=x1+(x2-x1)/2.0*(1.0-Overlap);  
	double xb=x1+(x2-x1)/2.0*(1.0+Overlap);
	double ya=y1+(y2-y1)/2.0*(1.0-Overlap);  
	double yb=y1+(y2-y1)/2.0*(1.0+Overlap);
	double za=z1+(z2-z1)/2.0*(1.0-Overlap);  
	double zb=z1+(z2-z1)/2.0*(1.0+Overlap);

	D3Dvec VecLSW(xa,ya,za);  // intersections of faces of 
	D3Dvec VecLSE(xb,ya,za);  // next level bounding boxes
	D3Dvec VecLNW(xa,yb,za);
	D3Dvec VecLNE(xb,yb,za);
	D3Dvec VecUSW(xa,ya,zb);
	D3Dvec VecUSE(xb,ya,zb);
	D3Dvec VecUNW(xa,yb,zb);
	D3Dvec VecUNE(xb,yb,zb);

		int icompare, jcompare, kcompare;

                lsw=false;lse=false;lne=false;lnw=false;
		unw=false;une=false;usw=false;use=false;

	   	//is it lsw
		   icompare=Pos.CompareEW(VecUNE);
		   jcompare=Pos.CompareNS(VecUNE);  
		   kcompare=Pos.CompareUD(VecUNE);  
		   if(icompare==0 && jcompare==0 && kcompare==0)lsw=true;
	   	//is it lse
		   icompare=Pos.CompareEW(VecUNW);
		   jcompare=Pos.CompareNS(VecUNW);  
		   kcompare=Pos.CompareUD(VecUNW);  
		   if(icompare==2 && jcompare==0 && kcompare==0)lse=true;
	   	//is it lnw
		   icompare=Pos.CompareEW(VecUSE);
		   jcompare=Pos.CompareNS(VecUSE);  
		   kcompare=Pos.CompareUD(VecUSE);  
		   if(icompare==0 && jcompare==2 && kcompare==0)lnw=true;
	   	//is it lne
		   icompare=Pos.CompareEW(VecUSW);
		   jcompare=Pos.CompareNS(VecUSW);  
		   kcompare=Pos.CompareUD(VecUSW);  
		   if(icompare==2 && jcompare==2 && kcompare==0)lne=true;
	   	//is it usw
		   icompare=Pos.CompareEW(VecLNE);
		   jcompare=Pos.CompareNS(VecLNE);  
		   kcompare=Pos.CompareUD(VecLNE);  
		   if(icompare==0 && jcompare==0 && kcompare==2)usw=true;
	   	//is it use
		   icompare=Pos.CompareEW(VecLNW);
		   jcompare=Pos.CompareNS(VecLNW);  
		   kcompare=Pos.CompareUD(VecLNW);  
		   if(icompare==2 && jcompare==0 && kcompare==2)use=true;
	   	//is it unw
		   icompare=Pos.CompareEW(VecLSE);
		   jcompare=Pos.CompareNS(VecLSE);  
		   kcompare=Pos.CompareUD(VecLSE);  
		   if(icompare==0 && jcompare==2 && kcompare==2)unw=true;
	   	//is it une
		   icompare=Pos.CompareEW(VecLSW);
		   jcompare=Pos.CompareNS(VecLSW);  
		   kcompare=Pos.CompareUD(VecLSW);  
		   if(icompare==2 && jcompare==2 && kcompare==2)une=true;
}

void  TestTri(
        int itri, double x1, double x2, double y1, double y2,
       	double z1, double z2, bool &lsw, bool &lse, bool &lnw, bool &lne, 
	bool &usw, bool &use, bool &unw, bool &une)
      {
	//centre of box
        double x,y,z;

        x=(x1+x2)/2.0;
        y=(y1+y2)/2.0;
        z=(z1+z2)/2.0;

	//next level box edges
	double xa=x1+(x2-x1)/2.0*(1.0-Overlap);  
	double xb=x1+(x2-x1)/2.0*(1.0+Overlap);
	double ya=y1+(y2-y1)/2.0*(1.0-Overlap);  
	double yb=y1+(y2-y1)/2.0*(1.0+Overlap);
	double za=z1+(z2-z1)/2.0*(1.0-Overlap);  
	double zb=z1+(z2-z1)/2.0*(1.0+Overlap);

	D3Dvec VecLSW(xa,ya,za);  // intersections of faces of 
	D3Dvec VecLSE(xb,ya,za);  // next level bounding boxes
	D3Dvec VecLNW(xa,yb,za);
	D3Dvec VecLNE(xb,yb,za);
	D3Dvec VecUSW(xa,ya,zb);
	D3Dvec VecUSE(xb,ya,zb);
	D3Dvec VecUNW(xa,yb,zb);
	D3Dvec VecUNE(xb,yb,zb);

                int  nvert=3;

		int icompare, jcompare, kcompare;

                D3Dvec Vertex;
		int nodenum, count;

                lsw=false;lse=false;lne=false;lnw=false;
		unw=false;une=false;usw=false;use=false;

	        Triangle Tee;
	        Tee=Triangles[itri];

		int iv[3];
		iv[0]=Tee.Get1();
		iv[1]=Tee.Get2();
		iv[2]=Tee.Get3();

	   	//is it lsw
		count=0;
                for(int nv=0; nv < nvert; nv++){
                   Vertex=NodeV[iv[nv]];
		   icompare=Vertex.CompareEW(VecUNE);
		   jcompare=Vertex.CompareNS(VecUNE);  
		   kcompare=Vertex.CompareUD(VecUNE);  
		   if(icompare==0 && jcompare==0 && kcompare==0)count++;
		}
                if(count==3)lsw=true;
	   	//is it lse
		count=0;
                for(int nv=0; nv < nvert; nv++){
                   Vertex=NodeV[iv[nv]];
		   icompare=Vertex.CompareEW(VecUNW);
		   jcompare=Vertex.CompareNS(VecUNW);  
		   kcompare=Vertex.CompareUD(VecUNW);  
		   if(icompare==2 && jcompare==0 && kcompare==0)count++;
		}
                if(count==3)lse=true;
	   	//is it lnw
		count=0;
                for(int nv=0; nv < nvert; nv++){
                   Vertex=NodeV[iv[nv]];
		   icompare=Vertex.CompareEW(VecUSE);
		   jcompare=Vertex.CompareNS(VecUSE);  
		   kcompare=Vertex.CompareUD(VecUSE);  
		   if(icompare==0 && jcompare==2 && kcompare==0)count++;
		}
                if(count==3)lnw=true;
	   	//is it lne
		count=0;
                for(int nv=0; nv < nvert; nv++){
                   Vertex=NodeV[iv[nv]];
		   icompare=Vertex.CompareEW(VecUSW);
		   jcompare=Vertex.CompareNS(VecUSW);  
		   kcompare=Vertex.CompareUD(VecUSW);  
		   if(icompare==2 && jcompare==2 && kcompare==0)count++;
		}
                if(count==3)lne=true;
	   	//is it usw
		count=0;
                for(int nv=0; nv < nvert; nv++){
                   Vertex=NodeV[iv[nv]];
		   icompare=Vertex.CompareEW(VecLNE);
		   jcompare=Vertex.CompareNS(VecLNE);  
		   kcompare=Vertex.CompareUD(VecLNE);  
		   if(icompare==0 && jcompare==0 && kcompare==2)count++;
		}
                if(count==3)usw=true;
	   	//is it use
		count=0;
                for(int nv=0; nv < nvert; nv++){
                   Vertex=NodeV[iv[nv]];
		   icompare=Vertex.CompareEW(VecLNW);
		   jcompare=Vertex.CompareNS(VecLNW);  
		   kcompare=Vertex.CompareUD(VecLNW);  
		   if(icompare==2 && jcompare==0 && kcompare==2)count++;
		}
                if(count==3)use=true;
	   	//is it unw
		count=0;
                for(int nv=0; nv < nvert; nv++){
                   Vertex=NodeV[iv[nv]];
		   icompare=Vertex.CompareEW(VecLSE);
		   jcompare=Vertex.CompareNS(VecLSE);  
		   kcompare=Vertex.CompareUD(VecLSE);  
		   if(icompare==0 && jcompare==2 && kcompare==2)count++;
		}
                if(count==3)unw=true;
	   	//is it une
		count=0;
                for(int nv=0; nv < nvert; nv++){
                   Vertex=NodeV[iv[nv]];
		   icompare=Vertex.CompareEW(VecLSW);
		   jcompare=Vertex.CompareNS(VecLSW);  
		   kcompare=Vertex.CompareUD(VecLSW);  
		   if(icompare==2 && jcompare==2 && kcompare==2)count++;
		}
                if(count==3)une=true;

      }
