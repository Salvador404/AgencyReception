#include <iostream>

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















int main()
{
    
    return 0;
}
