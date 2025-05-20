#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//---------------classes and our instruments-------------//

/////////////*********///////////////

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

/////////////*********///////////////

class eventList
{
	private:
		custom_Node *head=nullptr;
	public:
		void append(int,int );
};

void eventList:: append(int v,int e )
{
	if(!head){ head=new custom_Node(v,e);}
	else{
		custom_Node *ptr=head;
		while(ptr->next){ptr=ptr->next;}
		ptr->next=new custom_Node(v,e);
	}
}

/////////////*********///////////////
class queue
{
	private :
		custom_Node *head=nullptr;
		custom_Node *tail=nullptr;
	public:
		bool isEmpty(){if (head==nullptr){return true;}return false;}
				
		void Enqueue(int ,int );
		//custom_Node Dequeue(); we dont need it in this program
};

void queue::Enqueue(int a , int b)
{
	if(head==nullptr){head=new custom_Node(a,b); tail=head;}
	else{
		tail->next=new custom_Node(a,b);
		tail=tail->next;

}

// ^ we used a queue just to suppurt different data structures;
//   the program would work fine with a linkedList or even an array.

/////////////*********///////////////






void scan(eventList& list){
int a,b;
	while (1){
		cin>>a>>b;
		if (!a){break;}
		list.append(a,b);
	}
}






//------------------------------------------------------//

int main()
{
    cout<<""<<endl;
    int a;
    cin>>a;
    eventList list;
    if (a==1){
    	string filename;
	cout<<""<<endl;
	cin>>filename;
	ifstream inputFile(filename);
    	if (!inputFile){cerr<<""<<endl;	return 1;}  
     	//---if the filename or something in input path is wrong,the program will close
    	int i,j;
    	while (inputFile >> i >> j){ list.append(i,j); }
        inputFile.close();
	}
    else{scan(list);}

    
    return 0;
}



