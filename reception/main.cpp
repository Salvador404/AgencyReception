#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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
	public:
		custom_Node *head=nullptr;
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
	public :
		custom_Node *head=nullptr;
		custom_Node *tail=nullptr;
		int nsize=0;
		bool isEmpty(){if (head==nullptr){return true;}return false;}
				
		void Enqueue(int ,int );
		void Dequeue(); //we just need to remove someone from queue
};

void queue::Enqueue(int a , int b)
{
	if(head==nullptr){head=new custom_Node(a,b); tail=head; nsize++;}
	else{
		tail->next=new custom_Node(a,b);
		tail=tail->next;
		nsize++;
	}

}

void queue::Dequeue()
{
	if(!this->isEmpty())
	{
		custom_Node*ptr=head;
		head=head->next;
		delete ptr;
		--nsize;
		if(head==nullptr){tail=nullptr;}
	}
}

// ^ we used a queue just to suppurt different data structures;
//   the program would work fine with a linkedList or even an array.

/////////////*********///////////////


struct res
{
	int vi;
	int en;
	int time;
	int wait;
};





void scan(eventList& list){
int a,b;
	while (1){
		cin>>a>>b;
		if (!a){break;}
		list.append(a,b);
	}
}

void massg()
{
	cout<<"     ============================================================"<<endl;
	cout<<"     |                 Wellcome to my project!                  |"<<endl;
	cout<<"     | Check out the code and development details on my GitHub: |"<<endl;
	cout<<"     |    https://github.com/Salvador404/AgencyReception.git    |"<<endl;
	cout<<"     ============================================================"<<endl;

}

void upck(res arr[],int s,int i)
    {
	    for(int j=0;j<i;j++)
	    {
		    if(arr[j].vi==1 && arr[j].time>s)
		    {
			    arr[j].time+=3;
			    arr[j].wait+=3;
		    }

	    }

    }

int calcwaits(res arr[],int a)
{
	    int sum=0;
	    for (int i=0;i<a;i++)
	    {
		    sum+= arr[i].wait;
	    }
	    return sum;
}

int calcvip(res arr[], int a)
{
            int sum=0;
	    for(int i=0;i<a;i++)
	    {
		    if(arr[i].vi==2){sum+=arr[i].wait;}
	    }
	    return sum;
}

int calcnvip(res arr[], int a)
{
            int sum=0;
	    for(int i=0;i<a;i++)
	    {
		    if(arr[i].vi==1){sum+=arr[i].wait;}
	    }
	    return sum;
}





int maxWait(res arr[], int a)
{
        int maxi=0;
	for(int i=0 ; i<a ; i++)
	{
		if(arr[i].wait>maxi){maxi=arr[i].wait;}
	}
	return maxi;
}





//------------------------------------------------------//

int main()
{
    massg();
    cout<<"Choose :"<<endl;
    cout<<"1 - Import file "<<endl;
    cout<<"2 - Enter data manually"<<endl;
    int a;
    cin>>a;
    eventList list;
    if (a==1){
	cout<<"Already in the file's folder? Enter filename.txt"<<endl;
	cout<<"If not, type the complete path like C:/Users/Me/Desktop/input.txt"<<endl;
    	string filename;
	cin>>filename;
	ifstream inputFile(filename);
    	if (!inputFile){cerr<<""<<endl;	return 1;}  
     	//---if the filename or something in input path is wrong,the program will close
    	int i,j;
    	while (inputFile >> i >> j){ list.append(i,j); }
        inputFile.close();
	}
    else{
	    cout<<"Please enter your data items. When done press 0"<<endl;
	    scan(list);
    }
	

    queue vip;
    queue nonVip;
    custom_Node *check=list.head;

    if (!check){
	    cout<<"There is NO data!!!"<<endl;
	    return 1;
    }
    
    
    
    int emp=0;
    int count=0;
    int vcount=0;
    int i;
    res arr[500];
    

    while(check)
    {
	    i=count++;//*****
	    if(check->vip==2){vcount++;}
	    arr[i].vi=check->vip; arr[i].en=check->enter; 
	    //if (check->enter >= emp){emp=check->enter+3;}
	    //if(check==list.head){emp=check->enter+3;}//Employee getting to work
	    //else{emp=emp+(vip.nsize*3+nonVip.nsize*3);}//emp-check->enter
	    
	    if (check->enter >= emp) {
	    emp = check->enter + 3; 
	    } else {
	    emp = emp + 3; 
	    }







	    int delta=emp - check->enter;
	    while(delta>=3 &&(!vip.isEmpty() || !nonVip.isEmpty()))
	    {
		    if (!vip.isEmpty()){ delta-=3; vip.Dequeue(); continue; }
		    else if(!nonVip.isEmpty()){delta-=3; nonVip.Dequeue(); continue;}
		    else{break;}
	    }

	    if(check->vip==1){nonVip.Enqueue(check->vip , check->enter);}
	    else{vip.Enqueue(check->vip , check->enter);}

	    if(check->vip==1)
	    {
		    if(vip.isEmpty() && nonVip.isEmpty()){ arr[i].wait=emp-check->enter; arr[i].time=check->enter+arr[i].wait; }
		    else{ arr[i].wait=emp-check->enter; arr[i].time=arr[i].wait+check->enter;}
                    
	    }else{
		    
		    if(vip.isEmpty() && nonVip.isEmpty()){ arr[i].wait=emp-check->enter; arr[i].time=check->enter+arr[i].wait; }
		    
		    else if(!vip.isEmpty() && nonVip.isEmpty()){ arr[i].wait=emp-check->enter; arr[i].time=check->enter+arr[i].wait; }
		    else{
			    if(vip.isEmpty())
			    {
				    arr[i].wait=emp-check->enter; arr[i].time=arr[i].wait + check->enter;
				    upck(arr,check->enter,count);
			    }else{
				    arr[i].wait=(emp-check->enter)-(nonVip.nsize*3); arr[i].time=arr[i].wait+ check->enter;
				    upck(arr,check->enter,count);
			    }
		    }
	    } 
	    
	
	    check=check->next;	
    }


    float avgWait=0;
    float avgWaitV=0;
    float avgWaitNv=0;
    int maxwaitTime=maxWait(arr , count);
    avgWaitNv=calcnvip(arr,count)/(count-vcount);
    avgWaitV=calcvip(arr,count)/vcount;
    avgWait=calcwaits(arr,count)/count;
    
    cout<<"\n The results are ready."<<endl;
    cout<<"Average waiting time : "<<avgWait<<endl;
    string cap;
    cout<<"Do you want to save analysis to a file? [Y/N] "; cin>>cap;
    if(cap=="y"|| cap=="Y")
    {
	    string outputName;
	    cout<<"\n Choose a filename(e.g. analysis.txt): ";cin>>outputName;
	    ofstream logFile(outputName);
	    if(!logFile.is_open()){cerr<<"ERORR!!!could not open file "<<endl; return 1;}//opening file erorr
	    logFile<<"VIP/nonVIP"<<" | "<<"entry at"<<" | "<<"TurnTime"<< " | "<<"Waiting"<<endl;
	    for(int i=0;i<count;i++)
	    {
		    string vipn;
		    if(arr[i].vi==1){vipn="nonVip";}else{vipn=" vip  ";}
		    logFile<<"  "<<vipn<<"        "<< arr[i].en<<"         "<<arr[i].time <<"        "<<arr[i].wait<<endl;
	    }
	    logFile<<"--------------------------------------------------------"<<endl;
	    logFile<<"Average waiting time : "<<avgWait<<endl;
	    logFile<<"Average waiting time for VIP members : "<<avgWaitV<<endl;
	    logFile<<"Average waiting time for non-VIP members : "<<avgWaitNv<<endl;
	    logFile<<"TotalVisitors : "<<count<<endl;
	    logFile<<"Maximum waiting time : "<<maxwaitTime <<endl;
	    logFile<<"--------------------------------------------------------"<<endl;
	    logFile.close();
	    cout<<"Report saved to file : "<<outputName<<"\n GoodLuck!"<<endl;

    }
    else{
	    cout<<"\n GoodLuck!"<<endl;
	    return 0;
    }
    














    return 0;
}



