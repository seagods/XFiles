class MeshTet{

     public:
        MeshTet();
        ~MeshTet();

        void SetTet(int, int, int, int);
        void Set1(int); void Set2(int); void Set3(int); void Set4(int);
        int Get1(); int Get2(); int Get3(); int Get4();
       
	//will look at SetTetN for neighbours across faces
	//in another class

      private:
        int *i1, *i2, *i3, *i4;
};

MeshTet::MeshTet(){
       i1=new int; i2=new int; i3=new int; i4=new int;
       *i1=-1; *i2=-1; *i3=-1; *i4=-1;
}
MeshTet::~MeshTet(){
}

void MeshTet::SetTet(int a, int b, int c, int d){
  *i1=a; *i2=b; *i3=c; *i4=d;
}
void MeshTet::Set1(int a){
    *i1=a; }
void MeshTet::Set2(int a){
    *i2=a; }
void MeshTet::Set3(int a){
    *i3=a; }
void MeshTet::Set4(int a){
    *i4=a; }

int MeshTet::Get1(){
    return *i1; }
int MeshTet::Get2(){
    return *i2; }
int MeshTet::Get3(){
    return *i3; }
int MeshTet::Get4(){
    return *i4; }


