//-------------------------------------------------------------------------------
// Copyright 2003-2004 Christopher Godsalve.
// All Rights Reserved.
//
// Permission to use, copy, modify and distribute this software and its
// documentation for educational, research and non-profit purposes, without fee,
// and without a written agreement is hereby granted, provided that the above
// copyright notice and the following three paragraphs appear in all copies.
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
class CMyBinTree{

public:

	CMyBinTree();
	~CMyBinTree(){cout << "Tree got the chop" << endl;}

	T* AddToTree(T*,char);
	T* SearchTheTree(T*, T*);
	int WriteTheTree(T*);
	int DeleteFromTree(T*);
	T* GetLeftMost(T*);
	T* GetRightMost(T*);
	T* GetPointToRightMost(T*);
	T* GetRoot();
	int GetMaxDepth(T*, int, int*);

	T* RightRotate(T* );
	T* LeftRotate(T* );
	T* RightLeftRotate(T* );
	T* LeftRightRotate(T* );



	static int i_NodesInTree;
private:
	T* RootNode;
};
//**********************************************************
	//Static integer
//**********************************************************

template <class T>
int CMyBinTree<T>::i_NodesInTree=0;
//**********************************************************
	//Constructor
//**********************************************************
template <class T>
CMyBinTree<T>::CMyBinTree(){
	RootNode=NULL;
}
//**********************************************************
	//GetRoot
//**********************************************************
template <class T>
T* CMyBinTree<T>::GetRoot(){
	return RootNode;
}
//**********************************************************
	//Tree Traversal
//**********************************************************
template <class T>
int CMyBinTree<T>::WriteTheTree(T* TheNode){

	T* Direction;
	Direction=TheNode->GetLeft();
	if(Direction !=NULL)WriteTheTree(Direction);

	TheNode->show();
	int i=TheNode->GetOccur();
	cout <<" Number of Occurences=" << i << endl;

	Direction=TheNode->GetRight();
	if(Direction != NULL)WriteTheTree(Direction);
	return 0;
}
//**********************************************************
	//Add Node to Tree
//**********************************************************
template <class T>
T* CMyBinTree<T>::AddToTree(T* ToAdd, char CountOccur){

	T* Left=NULL;
	T* Right=NULL;
	T* OtherNode;
	int i,j,l,m,icompare;

	bool moveright=0;
	bool moveleft=0;

	if(RootNode==NULL){
		RootNode=ToAdd;
		RootNode->IncOccur();
		OtherNode=RootNode;
	}
	else
	{ 
		OtherNode=RootNode;
		icompare=ToAdd->Compare(RootNode);
		Left=RootNode->GetLeft();
		Right=RootNode->GetRight();

		switch(icompare){
		case 0:
			moveleft=1;
			if(Left==NULL){
				RootNode->SetNode(ToAdd, 'l');
				Left=ToAdd;
				ToAdd->IncOccur();    // even when not counting, i_occur=1 not zero
			}
			else
			{ 

				RootNode=RootNode->GetLeft();
				this->AddToTree(ToAdd,CountOccur);
			}

			break;
		case 1:
			moveleft=1;
			if(CountOccur=='n' || CountOccur=='N'){
					if(Left==NULL){
						ToAdd->IncOccur();
						RootNode->SetNode(ToAdd, 'l');
						Left=ToAdd;
					}
					else
					{ 
						RootNode=RootNode->GetLeft();
						this->AddToTree(ToAdd,CountOccur);
					}
			}
			else
			{
				RootNode->IncOccur();
			} 
			break; 
		case 2:
			moveright=1;
			if(Right==NULL){
				RootNode->SetNode(ToAdd, 'r');
				ToAdd->IncOccur();
				Right=ToAdd;

			}
            else
			{
				RootNode=RootNode->GetRight();
				this->AddToTree(ToAdd, CountOccur);
			}
			break;
		}

	} 
//***********************************************************
// on a recursive call RootNode should now either be the 
// left or right node. Otherwise a rotation has altered the structure
// so that's fixed here
// of OtherNode or equal to it. 
// Note that moveleft and moveright rewind.

	  if( (OtherNode!=RootNode)  ){
          if(moveleft){
			  if( (RootNode !=Left) ){
				  OtherNode->SetNode(RootNode,'l');
				  Left=RootNode;
			  }
		  }
	       if(moveright){
			 if( (RootNode != Right) ){
				  OtherNode->SetNode(RootNode,'r');
				  Right=RootNode;
			  }
		  } 
	  } 
	//**************************************
	// Update node depths here
	if(Left)
		i=Left->GetHeight();
	else
		i=-1;

	if(Right)
		j=Right->GetHeight();
	else
		j=-1;

	if(i >= j)
		OtherNode->SetHeight(i+1);
	else
		OtherNode->SetHeight(j+1);  


	//*******************************************
//**********************************************************
	//check for imbalances and take action here
//**********************************************************

	if( i-j==2){

		if(Left){
			T* LeftLeft=Left->GetLeft();
			T* LeftRight=Left->GetRight();
			if(LeftLeft)
				l=LeftLeft->GetHeight();
			else
				l=-1;
			if(LeftRight)
				m=LeftRight->GetHeight();
			else
				m=-1;

			if(l > m)
				OtherNode=RightRotate(OtherNode);
					else
				OtherNode=LeftRightRotate(OtherNode);
			
		}
	}

	if(j-i==2){

		if(Right){
			T* RightLeft=Right->GetLeft();
			T* RightRight=Right->GetRight();
			if(RightRight)
				l=RightRight->GetHeight();
			else
				l=-1;
			if(RightLeft)
				m=RightLeft->GetHeight();
			else
				m=-1;

		if(l>m)
			OtherNode=LeftRotate(OtherNode);
		else
			OtherNode=RightLeftRotate(OtherNode);
		}
	}


	RootNode=OtherNode;
	return RootNode;
}
//**********************************************************
	//Search for Node
//**********************************************************
template <class T>
T* CMyBinTree<T>::SearchTheTree(T* ToFind, T* Start){

	T* Found=NULL; //returns NULL if not found

	if(RootNode==NULL){
	   return Found;  //Tree is empty!
	}
	else
	{ 

		int i=ToFind->Compare(RootNode);

		switch(i){
		case 0:

			if(Start->GetLeft()==NULL){
				return Found;
			 // Have Failed to find returns NULL;
			}
			else
			{
				// continue search
				Start=Start->GetLeft();
				this->SearchTheTree(ToFind, Start);
			}
			break;
		case 1:
                 // found
                 Found=RootNode;
				 return Found;
			break; 
		case 2:
			if(Start->GetRight()==NULL){
				return Found;
			}
            else
			{
				Start=Start->GetRight();
				this->SearchTheTree(ToFind, Start);
			}
			break;
		} 
	}
    return Found; 
}
//**********************************************************
	//Delete from tree
//**********************************************************
template <class T>
int CMyBinTree<T>::DeleteFromTree(T* ToDelete){

	T* Left;
	T* Right;
	T* LeftLeft;
	T* LeftRight;
	T* RightLeft;
	T* RightRight;
	T* OtherNode;
	T* LeftRightMost;
    int i,j,l,m,icompare;
	bool moveleft=0;
	bool moveright=0;
	bool to_return=false;
	T* PointToLeftRighMost=NULL;

	OtherNode=RootNode;

	if(OtherNode==NULL){
	   return 3;  //Tree is empty!
	}
	Left=OtherNode->GetLeft();
	Right=OtherNode->GetRight();

	//********************************************
	if(RootNode==ToDelete){
		if(Left==NULL && Right==NULL){
			RootNode=NULL;
			return 0;
		}
		// If Left or Right is NULL, then RootNode will be pointing only to
		// a leaf, on deletion the new root is a leaf
		if(Left==NULL){
			RootNode=Right;
			RootNode->SetHeight(0);
			return 0;
		}
		if(Right==NULL){
			RootNode=Left;
			RootNode->SetHeight(0);
			return 0;
		}
		if((Left != NULL) && (Right !=NULL) ){

			// then RootNode has two branches


			// We shall want to delete the LeftRightMost from the tree
			// but cannot use delete from tree
			    T* Point;
				Point=GetPointToRightMost(Left);  //Points to the rightmost of the left of the node to delete
				LeftRightMost=Point->GetRight();  // is the leftrightmost 

				Left=LeftRightMost->GetLeft();    //It might have a leaf to the left
				Point->SetNode(Left,'r');
                
				Left=Point->GetLeft();
				Right=Point->GetRight();

				i=Left->GetHeight();
				j=Right->GetHeight();

				if(i>=j)
					Point->SetHeight(i+1);
				else
					Point->SetHeight(j+1);

				Right=ToDelete->GetRight();
				Left=ToDelete->GetLeft();

				RootNode=LeftRightMost;
				OtherNode=RootNode;

				RootNode->SetNode(Right,'r');
				RootNode->SetNode(Left,'l');

			    to_return=true;
				goto rebalance;

		}
	}  //that was all in case we want to delete the root node 



		// first check to see if one side of ToDelete is NULL or both.
	    // If so ToDelete has only a subtree one deep 
	    // BECAUSE IT'S AN AVL TREE!!

	if( Left==ToDelete || Right==ToDelete){
		i=0;
		if(Left==ToDelete){
			 LeftLeft=Left->GetLeft();
			 LeftRight=Left->GetRight();
			 if( (LeftLeft==NULL) && (LeftRight==NULL) ){
				 OtherNode->SetNode(NULL, 'l');	
				 // cannot set any height here
				 to_return=true;
			 }

			if( (LeftLeft==NULL) && (LeftRight !=NULL) ){
				OtherNode->SetNode(LeftRight,'l');
				LeftRight->SetHeight(i);
				to_return=true;
			 }

				 if( (LeftLeft != NULL) && (LeftRight ==NULL) ){
				 OtherNode->SetNode(LeftLeft,'l');
				 LeftLeft->SetHeight(i);
				 to_return=true;
			 }
		}
        else
		{
			 RightLeft=Right->GetLeft();
			 RightRight=Right->GetRight();
			 if( (RightLeft==NULL) && (RightRight==NULL) ){
				 to_return=true;
				 OtherNode->SetNode(NULL, 'r');
				 //cannot set any height here
			 }
			 if( (RightLeft==NULL) && (RightRight !=NULL) ){
				 to_return=true;
				 OtherNode->SetNode(RightRight,'r');
				 RightRight->SetHeight(i);
			 }
			 if( (RightLeft != NULL) && (RightRight ==NULL) ){
				 to_return=true;
				 OtherNode->SetNode(RightLeft,'r');
			  	 RightLeft->SetHeight(i);
			 }
		}  




		if(!to_return){
			// then ToDelete has two branches
			if(Left==ToDelete){
				LeftRightMost=this->GetRightMost(LeftLeft);

				this->DeleteFromTree(LeftRightMost);
				OtherNode->SetNode(LeftRightMost,'l');

				LeftRightMost->SetNode(LeftLeft,'l');
				LeftRightMost->SetNode(LeftRight,'r');

				i=LeftLeft->GetHeight();
				j=LeftRight->GetHeight();
				if(i>=j)
					LeftRightMost->SetHeight(i+1);
				else
					LeftRightMost->SetHeight(j+1);
			}
			else
			{
				LeftRightMost=this->GetRightMost(RightLeft);

				this->DeleteFromTree(LeftRightMost);
				OtherNode->SetNode(LeftRightMost,'r');

				LeftRightMost->SetNode(RightLeft,'l');
				LeftRightMost->SetNode(RightRight,'r');

				i=RightLeft->GetHeight();
				j=RightRight->GetHeight();
				if(i>=j)
					LeftRightMost->SetHeight(i+1);
				else
					LeftRightMost->SetHeight(j+1);

			}
			to_return=true;

		}  //end of to_return=false check
 
	}  // end of right or left check

	//	That was all fine if either left or right, if it isn't we must search for it

	if(!to_return){
 	    icompare=ToDelete->Compare(RootNode);

		switch(icompare){
		case 0:
			moveleft=1;
			if(RootNode->GetLeft()==NULL){
				return 1;
			 // Have Failed to find the node to delete, returns 1;
			}
			else
			{
				// continue search
				RootNode=RootNode->GetLeft();
				this->DeleteFromTree(ToDelete);
			}
			break;
		case 1:
                 // found but not without deletion!
				 return 2;
				 // failed to find the node to delete one step ahead
			break; 
		case 2:
			moveright=1;
			if(RootNode->GetRight()==NULL){
				return 1;
			}
            else
			{
				RootNode=RootNode->GetRight();
				this->DeleteFromTree(ToDelete);
			}
			break;
		}  
	}
		//***********************************************************
// on a recursive call RootNode should now either be the 
// left or right node. Otherwise a rotation has altered the structure
// so that's fixed here
// of OtherNode or equal to it. 
// Note that moveleft and moveright rewind.

rebalance:	  if( (OtherNode!=RootNode)  ){
          if(moveleft){
			  if( (RootNode !=Left) ){
				  OtherNode->SetNode(RootNode,'l');
				  Left=RootNode;
			  }
		  }
	       if(moveright){
			 if( (RootNode != Right) ){
				  OtherNode->SetNode(RootNode,'r');
				  Right=RootNode;
			  }
		  } 
	  } 
	//**************************************


    // rebalance tree
     //***********************************************************
	//**************************************
	// Update node depths here

	Left=OtherNode->GetLeft();
	Right=OtherNode->GetRight();

	if(Left)
		i=Left->GetHeight();
	else
		i=-1;

	if(Right)
		j=Right->GetHeight();
	else
		j=-1;

	if(i >= j)
		OtherNode->SetHeight(i+1);
	else
		OtherNode->SetHeight(j+1);  


	//*******************************************
//**********************************************************
	//check for imbalances and take action here
//**********************************************************

	if( i-j==2){

		if(Left){
			T* LeftLeft=Left->GetLeft();
			T* LeftRight=Left->GetRight();
			if(LeftLeft)
				l=LeftLeft->GetHeight();
			else
				l=-1;
			if(LeftRight)
				m=LeftRight->GetHeight();
			else
				m=-1;

			if(l > m)
				OtherNode=RightRotate(OtherNode);
					else
				OtherNode=LeftRightRotate(OtherNode);			
		}
	}

	if(j-i==2){

		if(Right){
			T* RightLeft=Right->GetLeft();
			T* RightRight=Right->GetRight();
			if(RightRight)
				l=RightRight->GetHeight();
			else
				l=-1;
			if(RightLeft)
				m=RightLeft->GetHeight();
			else
				m=-1;

		if(l>m)
			OtherNode=LeftRotate(OtherNode);
		else
			OtherNode=RightLeftRotate(OtherNode);
		}
			 
				}  //End of if(Left=ToDelete || Right==ToDelete)
         RootNode=OtherNode;


		return 0;  //This return is arrived at on stack rewind
}
//**********************************************************
	//Get lowest member of tree
//**********************************************************
template <class T>
T* CMyBinTree<T>::GetLeftMost(T* StartOff){
	T* Left;
	start: Left=StartOff->GetLeft();
	if(Left==NULL){
		return StartOff;}
	else{
		StartOff=Left;
                goto start;
	//	this->GetLeftMost(StartOff);
	}
}
//**********************************************************
	//Get highest member of tree
//**********************************************************
template <class T>
T* CMyBinTree<T>::GetRightMost(T* StartOff){
	T* Right;
	start: Right=StartOff->GetRight();
	if(Right==NULL){
		return StartOff;}
	else{
		StartOff=Right;
                goto start;
	//	this->GetRightMost(StartOff);
	}

}
template <class T>
T* CMyBinTree<T>::GetPointToRightMost(T* StartOff){
	T* Right;
	T*RightRight=NULL;
StartAgain:	Right=StartOff->GetRight();
			if(Right)RightRight=Right->GetRight();

			if(RightRight==NULL){
				return StartOff;}
			else{
				StartOff=Right;
				goto StartAgain;
	}
	return NULL;
}
//**********************************************************
	//Get maximum depth of tree
//**********************************************************
template <class T>
int CMyBinTree<T>::GetMaxDepth(T* Start, int i_CurrentDepth, int* i_MaxDepth){

	if(Start != NULL){
	i_CurrentDepth++;
	if(i_CurrentDepth > *i_MaxDepth)*i_MaxDepth=i_CurrentDepth;;
	this->GetMaxDepth(Start->GetLeft(),i_CurrentDepth, i_MaxDepth);
	this->GetMaxDepth(Start->GetRight(),i_CurrentDepth, i_MaxDepth);
	}
	return 0;
}
//**********************************************************
	//right rotations
//**********************************************************
template <class T>
T* CMyBinTree<T>::RightRotate(T* RotateNode){

	T* New;
	T* Left=RotateNode->GetLeft();
	T* Right=RotateNode->GetRight();
	T* LeftRight=Left->GetRight();

	New=Left;			    // left is to replace RotateNode
	RotateNode->SetNode(LeftRight,'l'); // for subtrees
	New->SetNode(RotateNode,'r');       // the new root points to RotateNode on the right

	T* NewLeft=New->GetLeft();
	T* NewRight=New->GetRight();   //should replace with New=RotateNode
	Left=RotateNode->GetLeft();

	//now we have to update the depths
    int i,j;

	if(Left)
		i=Left->GetHeight();
	else
		i=-1;
	if(Right)
		j=Right->GetHeight();
	else
		j=-1;

    if(i>=j)
		RotateNode->SetHeight(i+1);
		else
		RotateNode->SetHeight(j+1);
	

	if(NewLeft)
		i=NewLeft->GetHeight();
	else
		i=-1;
	if(NewRight)
		j=NewRight->GetHeight();
	else
		j=-1;

	if(i>=j)
		New->SetHeight(i+1);
	else
		New->SetHeight(j+1);


    return New;
}
//**********************************************************
	//left rotations
//**********************************************************
template <class T>
T* CMyBinTree<T>::LeftRotate(T* RotateNode){

	T* New;
	T* Right=RotateNode->GetRight();
	T* Left=RotateNode->GetLeft();
	T* RightLeft=Right->GetLeft();
	

	New=Right;			// left is to replace OtherNode
	RotateNode->SetNode(RightLeft,'r');			// for subtrees
	New->SetNode(RotateNode,'l');  // the new root points to rotatenode on the right

	T* NewLeft=New->GetLeft();
	T* NewRight=New->GetRight();
	Right=RotateNode->GetRight();

	//now we have to update the depths
    int i,j;

	if(Left)
		i=Left->GetHeight();
	else
		i=-1;
	if(Right)
		j=Right->GetHeight();
	else
		j=-1;

    if(i>=j)
		RotateNode->SetHeight(i+1);
		else
		RotateNode->SetHeight(j+1);
	

	if(NewLeft)
		i=NewLeft->GetHeight();
	else
		i=-1;
	if(NewRight)
		j=NewRight->GetHeight();
	else
		j=-1;

	if(i>=j)
		New->SetHeight(i+1);
	else
		New->SetHeight(j+1);


    return New;
}
//**********************************************************
	// two double rotations
//**********************************************************
template <class T>
T* CMyBinTree<T>::RightLeftRotate(T* RotateNode){
     T* Right=RotateNode->GetRight();
	 Right=RightRotate(Right);
	 // in a double rotation the first rotation doesn't reset the RotateNode
	 RotateNode->SetNode(Right,'r');
	 return LeftRotate(RotateNode);
}
template < class T>
T* CMyBinTree<T>::LeftRightRotate(T* RotateNode){
     T* Left=RotateNode->GetLeft();
	 Left=LeftRotate(Left);
	 RotateNode->SetNode(Left,'l');
	 return RightRotate(RotateNode);
}
