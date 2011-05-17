#include <iostream>
#include "throwcatch.h"
#include "Cat.h"
#include "NodeAVL.h"
#include "BinTreeAVL.h"


int main(){
	typedef CMyNode2<Cat> DoubleNode;
	typedef CMyBinTree<DoubleNode> CatTree;
	Cat* TheCat=new Cat;
	int i;

	CatTree TreeOfCats;

	char KOccur='Y';

	i=5;
	TheCat->setage(i);
	DoubleNode* TwoNode1=new DoubleNode;
	TwoNode1->SetNode(TheCat);

        i=1;
	TheCat->setage(i);
	DoubleNode* TwoNode2=new DoubleNode;
	TwoNode2->SetNode(TheCat);

	i=11;
	TheCat->setage(i);
	DoubleNode* TwoNode3=new DoubleNode;
	TwoNode3->SetNode(TheCat);

	i=7;
	TheCat->setage(i);
	DoubleNode* TwoNode4=new DoubleNode;
	TwoNode4->SetNode(TheCat);

	i=9;
	TheCat->setage(i);
	DoubleNode* TwoNode5=new DoubleNode;
	TwoNode5->SetNode(TheCat);

	i=21;
	TheCat->setage(i);
	DoubleNode* TwoNode6=new DoubleNode;
	TwoNode6->SetNode(TheCat);

	i=7;
	TheCat->setage(i);
	DoubleNode* TwoNode7=new DoubleNode;
	TwoNode7->SetNode(TheCat);

        i=13;
	TheCat->setage(i);
	DoubleNode* TwoNode8=new DoubleNode;
	TwoNode8->SetNode(TheCat);

	i=12;
	TheCat->setage(i);
	DoubleNode* TwoNode9=new DoubleNode;
	TwoNode9->SetNode(TheCat);

	i=14;
	TheCat->setage(i);
	DoubleNode* TwoNode10=new DoubleNode;
	TwoNode10->SetNode(TheCat);

	i=10;
	TheCat->setage(i);
	DoubleNode* TwoNode11=new DoubleNode;
	TwoNode11->SetNode(TheCat);

	i=23;
	TheCat->setage(i);
	DoubleNode* TwoNode12=new DoubleNode;
	TwoNode12->SetNode(TheCat);

	i=19;
	TheCat->setage(i);
	DoubleNode* TwoNode13=new DoubleNode;
	TwoNode13->SetNode(TheCat);

	DoubleNode* ReturnNode;

	ReturnNode=TreeOfCats.AddToTree(TwoNode1,KOccur);
	ReturnNode=TreeOfCats.AddToTree(TwoNode2,KOccur);
	ReturnNode=TreeOfCats.AddToTree(TwoNode3,KOccur);
	ReturnNode=TreeOfCats.AddToTree(TwoNode4,KOccur);
	ReturnNode=TreeOfCats.AddToTree(TwoNode5,KOccur);
	ReturnNode=TreeOfCats.AddToTree(TwoNode6,KOccur);
	ReturnNode=TreeOfCats.AddToTree(TwoNode7,KOccur);
	ReturnNode=TreeOfCats.AddToTree(TwoNode8,KOccur);
	ReturnNode=TreeOfCats.AddToTree(TwoNode9,KOccur);
	ReturnNode=TreeOfCats.AddToTree(TwoNode10,KOccur); 
	ReturnNode=TreeOfCats.AddToTree(TwoNode11,KOccur); 
	ReturnNode=TreeOfCats.AddToTree(TwoNode12,KOccur); 
	ReturnNode=TreeOfCats.AddToTree(TwoNode13,KOccur); 

	DoubleNode* Start;
	Start=TreeOfCats.GetRoot();
	cout << "££££££££££££££££££££££££££££££££££" << endl;
        i=TreeOfCats.WriteTheTree(Start); 

	Start=TreeOfCats.GetRoot();
	int iDepth=0,iMaxDepth=0;
	i=TreeOfCats.GetMaxDepth(Start,iDepth,&iMaxDepth);

	cout << "The Maximum depth of this tree is "<< iMaxDepth << endl;

	Cat* AnotherCat=new Cat;
	i=15;
	AnotherCat->setage(i);
	DoubleNode* AnotherNode=new DoubleNode;
	AnotherNode->SetNode(AnotherCat);

        ReturnNode=TreeOfCats.AddToTree(AnotherNode,KOccur);

	DoubleNode* WhichNode;
	
	Start=TreeOfCats.GetRoot();
	WhichNode=TreeOfCats.SearchTheTree(AnotherNode, Start); 
	Start=TreeOfCats.GetRoot();

	if(WhichNode==NULL){
		cout << "No Cat found in tree with this data" << endl;
	}
	else
	{
		cout << "Found Cat in tree at Node " << WhichNode << endl;
	} 
	cout << "AnotherCat was " << i << "  years old" << endl;

	cout << "Left Most of Node 1 is " << endl;
	DoubleNode* LeftMost;
	DoubleNode* RightMost;
	Start=TwoNode4;
	LeftMost=TreeOfCats.GetLeftMost(Start);
	RightMost=TreeOfCats.GetRightMost(Start);
	cout << "Left Most of Node 4 is " << LeftMost << endl;
	cout << "Right Most of Node 4 is " << RightMost << endl;

	Start=TreeOfCats.GetRoot();
 	i=TreeOfCats.DeleteFromTree(TwoNode5);

        DoubleNode *Point;
	Point=TreeOfCats.GetPointToRightMost(TwoNode8);
	i=29;
	TheCat->setage(i);
	DoubleNode* TwoNode14=new DoubleNode;
	TwoNode14->SetNode(TheCat);
	ReturnNode=TreeOfCats.AddToTree(TwoNode14,KOccur);
	Point=TreeOfCats.GetPointToRightMost(TwoNode8);

	i=TreeOfCats.DeleteFromTree(TwoNode9);
	// To Test, i=0, success, i=1, cant find the node in the tree
	// i=2, can get to the node but without knowing what to reconnect
	// i=3, root node is a NULL pointer

        Start=TreeOfCats.GetRoot();
	cout << "££££££££££££££££££££££££££££££££££" << endl;
        TreeOfCats.WriteTheTree(Start); 

	return 0;
}
