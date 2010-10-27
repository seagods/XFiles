class RayMeshTet{

     public:
        RayMeshTet();
        ~RayMeshTet();

        void SetTet(int, int, int, int);
        void SetTet(int, int, int, int,
		    int, int, int, int);
        void SetTet(int, int, int, int,
		    int, int, int, int,
		    char, char, char, char);
        void Set1(int); void Set2(int); void Set3(int); void Set4(int);
        void SetN1(int); void SetN2(int); void SetN3(int); void SetN4(int);
        void SetC1(char); void SetC2(char); void SetC3(char); void SetC4(char);
        void SetNC1(int,char); void SetNC2(int,char);
       	void SetNC3(int,char); void SetNC4(int, char);
        int Get1(); int Get2(); int Get3(); int Get4();
	// We allways have nodes, but neighbours can be NULL
	// need to return pointers
        int* GetN1(); int* GetN2(); int* GetN3(); int* GetN4();
        char GetC1(); char GetC2(); char GetC3(); char GetC4();

	void SetNULL1(); void SetNULL2(); void SetNULL3(); void SetNULL4();
	//can reset neighbours to NULL and delete j1 etc
       
	//will look at SetTetN for neighbours across faces
	//in another class

      private:
        int *i1, *i2, *i3, *i4;
        int *j1, *j2, *j3, *j4;
        char c1, c2, c3, c4;  //which face is NULL if 0
};

RayMeshTet::RayMeshTet(){
       i1=new int; i2=new int; i3=new int; i4=new int;
       *i1=-1; *i2=-1; *i3=-1; *i4=-1;
       j1=NULL; j2=NULL; j3=NULL; j4=NULL;
       c1=0; c2=0, c3=0, c4=0;
	// don't use four byte pointers for 1 byte objects
	// if there are lots of them!
}
RayMeshTet::~RayMeshTet(){
}

void RayMeshTet::SetTet(int a, int b, int c, int d){
  *i1=a; *i2=b; *i3=c; *i4=d;
}
void RayMeshTet::SetTet(int a, int b, int c, int d,
	       	     int e, int f, int g, int h){
  *i1=a; *i2=b; *i3=c; *i4=d;
  if(!j1)j1=new int; if(!j2)j2=new int; if(!j3)j3=new int; if(!j4)j4=new int;
  *j1=d; *j2=e; *j3=f; *j4=g;
}
void RayMeshTet::SetTet(int a, int b, int c, int d,
	       	     int e, int f, int g, int h,
		     char i, char j, char k, char l){
  *i1=a; *i2=b; *i3=c; *i4=d;
  if(!j1)j1=new int; if(!j2)j2=new int; if(!j3)j3=new int; if(!j4)j4=new int;
  *j1=e; *j2=f; *j3=g; *j4=h;
  c1=i; c2=j; c3=k; c4=l;
}
void RayMeshTet::Set1(int a){
    *i1=a; }
void RayMeshTet::Set2(int a){
    *i2=a; }
void RayMeshTet::Set3(int a){
    *i3=a; }
void RayMeshTet::Set4(int a){
    *i4=a; }

void RayMeshTet::SetN1(int a){
    if(!j1)j1=new int;  *j1=a; }
void RayMeshTet::SetN2(int a){
    if(!j2)j2=new int; *j2=a; }
void RayMeshTet::SetN3(int a){
    if(!j3)j3=new int; *j3=a; }
void RayMeshTet::SetN4(int a){
    if(!j4)j4=new int; *j4=a; }

void RayMeshTet::SetC1(char a){
    c1=a; }
void RayMeshTet::SetC2(char a){
    c2=a; }
void RayMeshTet::SetC3(char a){
    c3=a; }
void RayMeshTet::SetC4(char a){
    c4=a; }

void RayMeshTet::SetNC1(int a, char b){
    if(!j1)j1=new int; *j1=a;  c1=b; }
void RayMeshTet::SetNC2(int a, char b){
    if(!j2)j2=new int; *j2=a;  c2=b; }
void RayMeshTet::SetNC3(int a, char b){
    if(!j3)j3=new int; *j3=a;  c3=b; }
void RayMeshTet::SetNC4(int a, char b){
    if(!j4)j4=new int; *j4=a;  c4=b; }

int RayMeshTet::Get1(){
    return *i1; }
int RayMeshTet::Get2(){
    return *i2; }
int RayMeshTet::Get3(){
    return *i3; }
int RayMeshTet::Get4(){
    return *i4; }

int* RayMeshTet::GetN1(){
    return j1; }
int* RayMeshTet::GetN2(){
    return j2; }
int* RayMeshTet::GetN3(){
    return j3; }
int* RayMeshTet::GetN4(){
    return j4; }

char RayMeshTet::GetC1(){
    return c1; }
char RayMeshTet::GetC2(){
    return c2; }
char RayMeshTet::GetC3(){
    return c3; }
char RayMeshTet::GetC4(){
    return c4; }

void RayMeshTet::SetNULL1(){
	delete j1; j1=NULL;}
void RayMeshTet::SetNULL2(){
	delete j2; j2=NULL;}
void RayMeshTet::SetNULL3(){
	delete j3; j3=NULL;}
void RayMeshTet::SetNULL4(){
	delete j4; j4=NULL;}



	//inline most, if not all?


