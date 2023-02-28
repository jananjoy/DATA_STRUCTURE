File Name :- DLinkList.h

#ifndef DOUBLELINKLIST
#define DOUBLELINKLIST 
#include<iostream>
using namespace std;

struct DNodeStructure
{
	struct DNodeStructure *LeftAddressField;
	int    DataField;
	struct DNodeStructure *RightAddressField;

};
struct DNodeStructure *StartNodeStructure;

class DoubleLinkList
{

private:
	static int NodeCounter;
public:
	DoubleLinkList();
	~DoubleLinkList();
	struct DNodeStructure *CreateNodeStructure();
	void InitializeDoublelinkList();
	void AddNodeToDoubleLinkList();
	void InsertNodeDoubleLinkListAtFirst(DNodeStructure** ,int );
	void InsertNodeDoubleLinkListAtLast(DNodeStructure**, int);
	void InsertNodeDoubleLinkListAtAnyPlace(DNodeStructure** ,int ,int );
	void DeleteNodeFromDoubleLinkList();
	void DeleteNodeDoubleLinkListFromFirst(DNodeStructure**);
	void DeleteNodeDoubleLinkListFromLast(DNodeStructure**);
	void DeleteNodeDoubleLinkListFromAnyPlace(DNodeStructure** , int );
	void DeleteAnyNodefromDoubleLinkList(DNodeStructure** , int );
	void TraverseDoubleLinkList(DNodeStructure*);
	void FreeDeletedNode(DNodeStructure *);

};
int DoubleLinkList::NodeCounter =0;
DoubleLinkList::DoubleLinkList()
{
}
DoubleLinkList::~DoubleLinkList()
{
}
struct DNodeStructure *DoubleLinkList::CreateNodeStructure()
{
	struct DNodeStructure * TempNodeStructure ;
	TempNodeStructure = new DNodeStructure();
	return TempNodeStructure;
}
void DoubleLinkList:: FreeDeletedNode(DNodeStructure * aDeleteNodeStructure)
{
	free(aDeleteNodeStructure);
}


void DoubleLinkList::AddNodeToDoubleLinkList()
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
	 InsertNodeDoubleLinkListAtFirst(&StartNodeStructure ,aInputValue);
     NodeCounter++;
	 break;
 case  2:
	 cout<<"Enter the Value =>";
	 cin>>aInputValue;
	 InsertNodeDoubleLinkListAtLast (&StartNodeStructure ,aInputValue);
	 NodeCounter ++;
	 break;
 case  3:
	 cout<<"Enter the Value =>";
	 cin>>aInputValue;
	 cout<<"Enter the Position to Enter =>";
	 cin>>aInputPosition;

	 InsertNodeDoubleLinkListAtAnyPlace (&StartNodeStructure, aInputValue,aInputPosition);
	 NodeCounter++;
	 break;
 default:
	  cout<<"Wrong Input "<<endl;

	 break;
 }
}
void DoubleLinkList::InsertNodeDoubleLinkListAtFirst(DNodeStructure** aStartNodeStructure, int aAddItem)
{
	struct DNodeStructure * TempNodeStructure;
	TempNodeStructure = CreateNodeStructure();
	TempNodeStructure->DataField  = aAddItem;
	TempNodeStructure->LeftAddressField NULL;
	if(*aStartNodeStructure == NULL)
	{
		TempNodeStructure->RightAddressField = NULL ;
	}
	else
	{
		TempNodeStructure->RightAddressField =(*aStartNodeStructure );
		(*aStartNodeStructure)->LeftAddressField = TempNodeStructure ;
	}
    (*aStartNodeStructure ) =  TempNodeStructure ;   

}
void DoubleLinkList::InsertNodeDoubleLinkListAtLast(DNodeStructure** aStartNodeStructure, int aAddItem)
{
		struct DNodeStructure * TempNodeStructure,*CurrrentNodeStructure;
		TempNodeStructure = CreateNodeStructure();
		TempNodeStructure->DataField = aAddItem ;
        TempNodeStructure->RightAddressField = NULL;
		if((*aStartNodeStructure) == NULL)
		{
			TempNodeStructure->LeftAddressField  =NULL ;
			(*aStartNodeStructure) = TempNodeStructure;
		}
		else
		{
			CurrrentNodeStructure =(*aStartNodeStructure);
			while (CurrrentNodeStructure->RightAddressField!= NULL)
			{
				CurrrentNodeStructure = CurrrentNodeStructure->RightAddressField ;

			}
			TempNodeStructure->LeftAddressField  = CurrrentNodeStructure ;
			CurrrentNodeStructure ->RightAddressField = TempNodeStructure;
		}

}
void DoubleLinkList::InsertNodeDoubleLinkListAtAnyPlace(DNodeStructure** aStartNodeStructure, int aAddItem, int aPosition)
{
	struct DNodeStructure * TempNodeStructure ,* CurrentNodeStructure;
	int aIndex=0;
	TempNodeStructure = CreateNodeStructure ();
	TempNodeStructure ->DataField = aAddItem ;
	if(aPosition ==1)
	{
		if(*aStartNodeStructure!= NULL)
		{
			(*aStartNodeStructure)->LeftAddressField = TempNodeStructure ;
		}
		TempNodeStructure->RightAddressField = (*aStartNodeStructure);
		TempNodeStructure->LeftAddressField = NULL ;
		(*aStartNodeStructure) = TempNodeStructure;
	}
	else
	{
		aIndex =2;
		CurrentNodeStructure = (*aStartNodeStructure);
		while((aIndex < aPosition)&&(CurrentNodeStructure != NULL) )
		{
			aIndex ++;
			CurrentNodeStructure = CurrentNodeStructure->RightAddressField ;
		}
		TempNodeStructure->LeftAddressField =CurrentNodeStructure ;
		TempNodeStructure->RightAddressField = CurrentNodeStructure->RightAddressField ;
		if(CurrentNodeStructure->RightAddressField != NULL)
		{
			TempNodeStructure ->RightAddressField->LeftAddressField = TempNodeStructure ;
		}
		CurrentNodeStructure ->RightAddressField =TempNodeStructure ;
	}
}
void DoubleLinkList::DeleteNodeFromDoubleLinkList()
{
 int DeleteLocation;
 int aInputPosition;
 int aInpuItem ;
 cout<<" Delete Node To the Link List "<<endl;
 cout<<"1. Delete From the First Location "<<endl;
 cout<<"2. Delete From the Last Location "<<endl;
 cout<<"3. Delete From Any location(with position)"<<endl;
 cout<<"3. Delete From Any location(with Data Item)"<<endl;
 cout<<"Enter Your Choose =>";
 cin>>DeleteLocation;
 switch(DeleteLocation)
 {
 case 1:
	  DeleteNodeDoubleLinkListFromFirst(&StartNodeStructure);
	  NodeCounter --;
	 break;
 case  2:
	 DeleteNodeDoubleLinkListFromLast(&StartNodeStructure);
	 NodeCounter--;
	 break;
 case 3:
	 cout<<"Enter the Position to Enter =>";
	 cin>>aInputPosition;
	 DeleteNodeDoubleLinkListFromAnyPlace(&StartNodeStructure, aInputPosition);
	 NodeCounter --;
     break;
  case 4:
	 cout<<"Enter the Item To be Deleted  =>";
	 cin>>aInpuItem;
	 DeleteAnyNodefromDoubleLinkList(&StartNodeStructure ,aInpuItem );
	 break;
 default:
	  cout<<"Wrong Input "<<endl;
	 break;
 }
}
void DoubleLinkList::DeleteNodeDoubleLinkListFromFirst(DNodeStructure** aStartNodeStructure)
{
	struct DNodeStructure * CurrentNodeStructure;
	int aAddItem;
	if(*aStartNodeStructure == NULL)
	{
		cout<<"Double Link list is Empty "<<endl;
		return;
	}
	CurrentNodeStructure =(*aStartNodeStructure);
	(*aStartNodeStructure) = (*aStartNodeStructure)->RightAddressField ;
	if(*aStartNodeStructure !=NULL)
	{
		(*aStartNodeStructure)->LeftAddressField =NULL;
	}
	aAddItem =CurrentNodeStructure->DataField ;
	FreeDeletedNode(CurrentNodeStructure);
    cout<<"Delete Item from Double Link List "<<aAddItem ;
}
void DoubleLinkList::DeleteNodeDoubleLinkListFromLast(DNodeStructure** aStartNodeStructure)
{
	struct DNodeStructure * CurrentNodeStructure;
	int aAddItem;
	if(*aStartNodeStructure == NULL)
	{
		cout<<"Double Link list is Empty "<<endl;
		return;
	}
	CurrentNodeStructure =(*aStartNodeStructure);
	while(CurrentNodeStructure->RightAddressField!= NULL)
	{
		CurrentNodeStructure = CurrentNodeStructure->RightAddressField;

	}
	 if(CurrentNodeStructure->LeftAddressField != NULL)
	 {
		 CurrentNodeStructure->LeftAddressField->RightAddressField = CurrentNodeStructure->RightAddressField;
	 }
	 else
	 {
        (*aStartNodeStructure) = NULL;
	 }
	 aAddItem = CurrentNodeStructure->DataField ;
		FreeDeletedNode(CurrentNodeStructure);
	 cout<<"Deteted Data from Double Link List "<<aAddItem ;

}
void DoubleLinkList::DeleteNodeDoubleLinkListFromAnyPlace(DNodeStructure** aStartNodeStructure, int aPosition)
{
	struct DNodeStructure * CurrentNodeStructure ;//,* PreviousNodeStucture ;
	int aIndex = 1;
	int aAddItem ;
	if(*aStartNodeStructure == NULL)
	{
		cout<<"Double Link list is Empty "<<endl;
		return;
	}
	CurrentNodeStructure = (*aStartNodeStructure);
	while(CurrentNodeStructure !=NULL)
	{
		if(aIndex == aPosition )
		{
		   aAddItem = CurrentNodeStructure->DataField ;
		        if(CurrentNodeStructure->LeftAddressField  == NULL)
				{
					CurrentNodeStructure->RightAddressField ->LeftAddressField = NULL;
					(*aStartNodeStructure) = CurrentNodeStructure->RightAddressField ;
						FreeDeletedNode(CurrentNodeStructure);
				}
				else if(CurrentNodeStructure->RightAddressField ==NULL)
				{
					CurrentNodeStructure->LeftAddressField ->RightAddressField = CurrentNodeStructure->RightAddressField ;
						FreeDeletedNode(CurrentNodeStructure);

				}
				else
				{
						CurrentNodeStructure->LeftAddressField ->RightAddressField = CurrentNodeStructure->RightAddressField ;
						CurrentNodeStructure->RightAddressField ->LeftAddressField = 	CurrentNodeStructure->LeftAddressField;
							FreeDeletedNode(CurrentNodeStructure);

				}
				cout<<"Deteted Data from Double Link List "<<aAddItem ;
				return ;

		}
		   aIndex ++;
		   CurrentNodeStructure = CurrentNodeStructure->RightAddressField ;

	}
	cout<<"Search item not Found in the Link List"<<endl;

}
void DoubleLinkList::DeleteAnyNodefromDoubleLinkList(DNodeStructure** aStartNodeStructure ,int aInputItem )
{
	struct DNodeStructure * CurrentNodeStructure ;//,* PreviousNodeStucture ;
	int aIndex = 1;
	//int aAddItem ;
	if(*aStartNodeStructure == NULL)
	{
		cout<<"Double Link list is Empty "<<endl;
		return;
	}
	CurrentNodeStructure = (*aStartNodeStructure);

	while ( CurrentNodeStructure != NULL)
	{
		if(CurrentNodeStructure ->DataField ==aInputItem )
		{
			if(CurrentNodeStructure->LeftAddressField  == NULL)
			{
				CurrentNodeStructure->RightAddressField ->LeftAddressField = NULL;
				(*aStartNodeStructure ) =CurrentNodeStructure->RightAddressField ;
					FreeDeletedNode(CurrentNodeStructure);

			}
			else if(CurrentNodeStructure->RightAddressField  == NULL)
			{
				CurrentNodeStructure->RightAddressField ->LeftAddressField = CurrentNodeStructure->RightAddressField ;
				FreeDeletedNode(CurrentNodeStructure);
			}
			else
			{
				CurrentNodeStructure->LeftAddressField ->RightAddressField = CurrentNodeStructure->RightAddressField ;
				CurrentNodeStructure->RightAddressField ->LeftAddressField = CurrentNodeStructure->LeftAddressField;
				FreeDeletedNode(CurrentNodeStructure);

			}
			cout<<" Search Item Deleted Succesfully ="<<aInputItem;
			return ;
		}
		else

		{
			CurrentNodeStructure = CurrentNodeStructure->RightAddressField;

		}
	}
	cout<<" Search item Not found ="<<aInputItem;
}

void DoubleLinkList::InitializeDoublelinkList()
{
}
void DoubleLinkList::TraverseDoubleLinkList(DNodeStructure *aStartNodeStructure)
{
	if(aStartNodeStructure == NULL)
	{
		cout<<"Double Link List is Empty "<<endl;
	}
	else
	{
		while(aStartNodeStructure!=NULL)
		{
          cout<<"<->"<<aStartNodeStructure->DataField;
		  aStartNodeStructure = aStartNodeStructure->RightAddressField;

		}
	}
}


#endif

#include"DLinkList.h"
#include<iostream>
using namespace std;
void DoubleLinkListMenu();

int main()
{
	DoubleLinkListMenu();
	return 0;
}
void DoubleLinkListMenu()
{
	DoubleLinkList DLinkListInstance;
	int aUserOption;
	while(1)
	{
	cout<<"Double Link List Menu Display "<<endl;
	cout<<"================================="<<endl;
	cout<<"1.Add New Node to the Double Link List "<<endl;
	cout<<"2.Delete Node From the Double Link List "<<endl;
	cout<<"3.Display the Node from the Double Link list "<<endl;
    cout<<"4.Exit from the Application"<<endl;
	cout<<"=================================="<<endl;
	cout<<"Enter Your choice =>";
	cin>>aUserOption;
	switch(aUserOption)
	{
	case 1:
		 DLinkListInstance.AddNodeToDoubleLinkList();
			break;
	case 2:
		  DLinkListInstance.DeleteNodeFromDoubleLinkList ();

			break;
	case 3:
		  DLinkListInstance.TraverseDoubleLinkList (StartNodeStructure);

			break;
	default:
		exit(0);
			break;
	}
	}

}
