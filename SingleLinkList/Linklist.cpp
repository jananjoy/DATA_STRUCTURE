//File Name :- TestEg.h
//-----------------------------------------------------------------------
#ifndef LINKLIST
#define LINKLIST
#include<iostream>
using namespace std;
//Define the Link list Class 

struct  NodeStructure  
{
	int DataField;
	struct NodeStructure *AddressField;
};
struct NodeStructure * StartNodeStructure;

class LinkList 
{
private:
	static int NodeCounter;
	
public:
	// Constructor of the List List 
	LinkList();
	// Destructor of the Link List 
	~LinkList();
	// Create Method to Create New Node Structure 
	struct NodeStructure * CreateNodeStructure();
	// Display Method To Display the Element of the Link List 
	void DisplayNodeStructure();
	// Method To Add New Node to the LinkList 
	//-----------------------------------------
	void AddNewNodeStructure();
	void InsertAtFrist(int);
	void InsertAtLast(int);
	void InsertAtAnyPlace(int,int);
	//------------------------------------------
	// Method To Delete  Node from  the LinkList 
	void DeleteNodeStructure();
	void DeleteFromFrist();
	void DeleteFromLast();
	void DeleteFromAnyPlace(int );
	//-----------------------------------------

};
int LinkList::NodeCounter =0;

// Method Implementation for the Link List 
// Constructor and Destructor of the Link List Class
//--------------------Start----------------------------------
LinkList::LinkList ()
{

	StartNodeStructure = NULL;
}

LinkList::~LinkList ()
{
	struct NodeStructure *CurrentNodeStructure;
	while(StartNodeStructure != NULL)
	{
      CurrentNodeStructure = StartNodeStructure->AddressField ;
	  delete StartNodeStructure;
	  StartNodeStructure = CurrentNodeStructure ;
	}
}
//--------------------End --------------------------------------
// Create Method to Create New Node Structure 
struct NodeStructure * LinkList ::CreateNodeStructure ()
{
	struct NodeStructure *TempNodeStructure;
	TempNodeStructure = new NodeStructure();
	return TempNodeStructure;
	
}
// Method to Add New Node to the Link List

void LinkList::AddNewNodeStructure ()
{
 int InsertLocation;
 int aInputValue;
 int aInputPosition;
 cout<<" Add New Node To the Link List "<<endl;
 cout<<"1. Add At the First Location "<<endl;
 cout<<"2. Add At the Last Location "<<endl;
 cout<<"3. add At Any location"<<endl;
 cout<<"Enter Your Choose =>";
 cin>>InsertLocation;
 switch(InsertLocation)
 {
 case 1:
	 cout<<"Enter the Value =>";
	 cin>>aInputValue;
	 InsertAtFrist(aInputValue);
     NodeCounter++;
	 break;
 case  2:
	 cout<<"Enter the Value =>";
	 cin>>aInputValue;
	 InsertAtLast (aInputValue);
	 NodeCounter ++;
	 break;
 case  3:
	 cout<<"Enter the Value =>";
	 cin>>aInputValue;
	 cout<<"Enter the Position to Enter =>";
	 cin>>aInputPosition;

	 InsertAtAnyPlace (aInputValue,aInputPosition);
	 NodeCounter++;
	 break;
 default:
	  cout<<"Wrong Input "<<endl;

	 break;
 }
}
void LinkList::InsertAtFrist (int aAddItem)
{
	struct  NodeStructure * TempNodeStructure = CreateNodeStructure ();
	 if(TempNodeStructure == NULL )
	 {
		 cout<<"\n Unable to Create New Node "<<endl;
		 return ;
	 }
	 TempNodeStructure->DataField = aAddItem ;
	 TempNodeStructure->AddressField = StartNodeStructure;
	 StartNodeStructure = TempNodeStructure;
}

void LinkList::InsertAtLast(int aAddItem)
{
   struct 	NodeStructure * CurrentNodeStructure ; 
	struct NodeStructure * TempNodeStructure = CreateNodeStructure ();
	if(TempNodeStructure == NULL )
	 {
		 cout<<"\n Unable to Create New Node "<<endl;
		 return ;
	 }
	TempNodeStructure->DataField =aAddItem;
	TempNodeStructure->AddressField =NULL ;
	if(StartNodeStructure == NULL )
	{
		StartNodeStructure =TempNodeStructure ;
	}

	else
	{
		CurrentNodeStructure =StartNodeStructure;
		while(CurrentNodeStructure->AddressField !=NULL )
		{
			CurrentNodeStructure = CurrentNodeStructure->AddressField ;
		}
			CurrentNodeStructure->AddressField = TempNodeStructure;
		

	}

}
void LinkList::InsertAtAnyPlace (int aAddItem , int aPosition)
{
	int aIndex= 1;
	NodeStructure * CurrentNodeStructure , * PreviousNodeStructure ;
	NodeStructure * TempNodeStructure = CreateNodeStructure ();
	if(TempNodeStructure == NULL )
	 {
		 cout<<"\n Unable to Create New Node "<<endl;
		 return ;
	 }

	if((StartNodeStructure =NULL )||( aPosition ==1))
	{
		TempNodeStructure->DataField = aAddItem; 
		TempNodeStructure->AddressField = StartNodeStructure ;
		StartNodeStructure = TempNodeStructure;
		return ;
	}
    CurrentNodeStructure =StartNodeStructure->AddressField ;
	PreviousNodeStructure =StartNodeStructure ;
	while(CurrentNodeStructure !=NULL)
	{
		if((aIndex+1)== aPosition)
			break;
		else
		{
			PreviousNodeStructure=CurrentNodeStructure ;
			CurrentNodeStructure = CurrentNodeStructure->AddressField;
			aIndex ++;
		}
	}

	TempNodeStructure->DataField =aAddItem;
	TempNodeStructure->AddressField =CurrentNodeStructure;
	PreviousNodeStructure = TempNodeStructure ;
	
}
// Method to Delete Node to the Link List

void LinkList::DeleteNodeStructure  ()
{
 int DeleteLocation;
 int aInputPosition;
 cout<<" Delete Node To the Link List "<<endl;
 cout<<"1. Delete From the First Location "<<endl;
 cout<<"2. Delete From the Last Location "<<endl;
 cout<<"3. Delete From Any location"<<endl;
 cout<<"Enter Your Choose =>";
 cin>>DeleteLocation;
 switch(DeleteLocation)
 {
 case 1:
	  DeleteFromFrist ();
	  NodeCounter --;
	 break;
 case  2:
	 DeleteFromLast ();
	 NodeCounter--;
	 break;
 case 3:
	 cout<<"Enter the Position to Enter =>";
	 cin>>aInputPosition;
	 DeleteFromAnyPlace (aInputPosition);
	 NodeCounter --;
     break;
 default:
	  cout<<"Wrong Input "<<endl;
	 break;
 }
}

void LinkList::DeleteFromFrist()
{
	struct NodeStructure * CurrentNodeStructure ;
	int aAddItem ;
	if(StartNodeStructure == NULL )
	{
		cout<<"List is Empty"<<endl;
		return ;
	}
	CurrentNodeStructure = StartNodeStructure ;
	aAddItem = CurrentNodeStructure->DataField ;
	StartNodeStructure = StartNodeStructure->AddressField ;
	cout<<"The Deleted Irem from the Link List is "<<aAddItem;
	delete CurrentNodeStructure ;
}

void LinkList::DeleteFromLast()
{
  	struct NodeStructure * CurrentNodeStructure , *PreviousNodeStructure ;
	int aAddItem;
	if(StartNodeStructure == NULL )
	{
		cout<<"List is Empty"<<endl;
		return ;
	}

	CurrentNodeStructure = StartNodeStructure ;
	PreviousNodeStructure = NULL;
	if(StartNodeStructure->AddressField  == NULL )
	{
	  StartNodeStructure = StartNodeStructure->AddressField ;
	}
	else
	{
		while(CurrentNodeStructure->AddressField != NULL )
		{
			PreviousNodeStructure = CurrentNodeStructure ;
			CurrentNodeStructure = CurrentNodeStructure->AddressField ;
		}
		   PreviousNodeStructure->AddressField = PreviousNodeStructure->AddressField ;

	}

	 aAddItem = CurrentNodeStructure->DataField ;
	 cout<<" The deleted Item for the Link List = "<<aAddItem ;
	 delete CurrentNodeStructure;


}

void LinkList::DeleteFromAnyPlace (int aPosition)
{
	struct NodeStructure * CurrentNodeStructure , *PreviousNodeStructure ;
	int aAddItem , aIndex = 2;
	if(StartNodeStructure == NULL )
	{
		cout<<"List is Empty"<<endl;
		return ;
	}
	if(aPosition == 1)
	{
		CurrentNodeStructure = StartNodeStructure;
		aAddItem = CurrentNodeStructure->DataField ;
		StartNodeStructure = StartNodeStructure->AddressField ;
		cout<<" The deleted Item for the Link List = "<<aAddItem ;
	    delete CurrentNodeStructure;
		return ;
	}
	 CurrentNodeStructure =StartNodeStructure->AddressField ;
	 PreviousNodeStructure = StartNodeStructure ;
	 while(CurrentNodeStructure)
	 {
		 if(aIndex == aPosition)
		 {
			PreviousNodeStructure->AddressField =CurrentNodeStructure->AddressField ;
			aAddItem = CurrentNodeStructure->DataField ;
			cout<<" The deleted Item for the Link List = "<<aAddItem ;
			delete CurrentNodeStructure;
			return ;
		 }
		 else
		 {
			 PreviousNodeStructure = CurrentNodeStructure;
			 CurrentNodeStructure = CurrentNodeStructure->AddressField ;

		 }

		 aIndex++;
	 }

}
// Display Method To Display the Element of the Link List 

void LinkList::DisplayNodeStructure()
{
	NodeStructure * CurrentNodeStructure;
	CurrentNodeStructure = StartNodeStructure ;
	while(CurrentNodeStructure != NULL)
	{
		cout<<CurrentNodeStructure->DataField ;
		cout<<"-->";
		CurrentNodeStructure = CurrentNodeStructure->AddressField ;
	}
	cout<< "NULL"<<endl;;

	cout<<" The Number of Node in the Link List = "<< NodeCounter << endl;
}

#endif  



#include"TestEg.h"
#include<iostream>
using namespace std;
void LinkListMenu();
int main()
{
	LinkListMenu();
	return 0;
}

void LinkListMenu()
{
	LinkList LinkListInstance;
	int aUserOption;
	while(1)
	{
	cout<<"Link List Menu Display "<<endl;
	cout<<"================================="<<endl;
	cout<<"1.Add New Node to the Link List "<<endl;
	cout<<"2.Delete Node From the Link List "<<endl;
	cout<<"3.Display the Node from the Link list "<<endl;
    cout<<"4.Exit from the Application"<<endl;
	cout<<"=================================="<<endl;
	cout<<"Enter Your choice =>";
	cin>>aUserOption;
	switch(aUserOption)
	{
	case 1:
		LinkListInstance.AddNewNodeStructure ();
			break;
	case 2:
		  LinkListInstance.DeleteNodeStructure ();

			break;
	case 3:
			LinkListInstance.DisplayNodeStructure();

			break;
	default:
		exit(0);
			break;
	}
	}
}
