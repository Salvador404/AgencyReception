#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class custom_Node
{
	public:
		int vip;
		int enter;
		custom_Node *next=nullptr;
		custom_Node(int,int);
};
custom_Node::custom_Node(int v , int e)
{
	vip=v;
	enter=e;
}


class eventList
{
	private:
		custom_Node *head=nullptr;
	public:
		void append(int,int );
};

///////////-------------------------/////////////
void eventList:: append(int v,int e )
{
	if(!head){ head=new custom_Node(v,e);}
	else{
		custom_Node *ptr=head;
		while(ptr->next){ptr=ptr->next;}
		ptr->next=new custom_Node(v,e);
	}
}







void scan(){
int a,b;
	while (1){
		cin>>a>>b;
		if (!a){break;}
		list.append(a,b);
	}
}







int main()
{
    string filename;
    cout<<""<<endl;
    cout>>filename;
    ifstream inputFile(filename);
    if (!inputFile){cerr<<""<<endl;	return 1;}  
     //---if the filename or something in input path is wrong,the program will close
    int i,j;
    eventList list;
    while (inputFile >> i >> j){ list.append(i,j); }


    inputFile.close();
    return 0;
}
