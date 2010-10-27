class MeshNode{

     public:
        MeshNode();
        ~MeshNode();
        MeshNode(MeshNode &);

        void SetPos(double &, double &, double &, D3Dvec *);
        D3Dvec* GetVec(){return Vec;}

        void SetFreedom(char a){freedom=a;}
        char GetFreedom(){return freedom;}
        
        void SetID(int);
        void SetID(int , int );
        void SetID(int, int, int);

	int* GetID(){return ID;} //returns address held by ID;
        int GetID1(){return *ID;}
        int GetID2(){return *(ID+1);}
        int GetID3(){return *(ID+2);}

	char GetAlias(){return aliases;}
	      	//get and set number of aliases for node

	void SetMyTet(int it){MyTet=it;}
	int GetMyTet(){return MyTet;}

      private:

        D3Dvec *Vec;
        int *ID;  //points to any aliases due to periodic bcs

        char freedom; //don't use 4 byte pointers for a 1 byte char
	char aliases;
	//The number of aliases the node has
	//under periodic boundary conditions
	int MyTet;
};
MeshNode::MeshNode(){
      Vec=NULL;
      freedom=0;
      ID = NULL;
      aliases=0;
      MyTet=-1;
}
MeshNode::~MeshNode(){

}
MeshNode::MeshNode(MeshNode & Old){
    Vec=new D3Dvec;
    double *V=Vec->GetV();
    int* OldID;
    D3Dvec* OldVec;
    OldVec=Old.GetVec();
    double *oldV;
    oldV=OldVec->GetV();

    *V=*oldV;
    *(V+1)=*(oldV+1);
    *(V+2)=*(oldV+2);

    freedom=Old.GetFreedom();
    aliases=Old.GetAlias();
    OldID=Old.GetID();
    if((int)aliases>0){
    ID=new int[(int)aliases];
    for(char ichar=0; ichar < aliases; ichar++){
       *(ID+ichar)=*(OldID+ichar);
            }
    }
    else
    {  
      ID=NULL;}
}
void MeshNode::SetPos(double &x, double &y, double &z, D3Dvec* VecSet){
    Vec=VecSet;
    Vec->SetVec(x,y,z);
}
void MeshNode::SetID(int period1){
	   if(!ID)ID=new int[1];
	   *ID=period1;
	   aliases=1;
}
void MeshNode::SetID( int period1, int period2 ){
	   if(ID){delete[] ID;}
	   ID=new int[2];
	   *(ID)=period1;
	   *(ID+1)=period2;
	   aliases=2;
}
void MeshNode::SetID(int period1, int period2, int  period3){
	   if(ID){delete[] ID;}
	   ID=new int[3];
	   *(ID)=period1;
	   *(ID+1)=period2;
	   *(ID+2)=period3;
	   aliases=3;
}
