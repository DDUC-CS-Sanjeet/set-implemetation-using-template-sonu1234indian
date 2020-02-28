#include<iostream>
#include<math.h>
using namespace std;
template<typename T>

class Myset
{
	public: 
	
//	int arr[100];
	T arr[100];
		int size;
		
	Myset()
	{
		size=0; 
//		T arr=new T[size];
	}
	Myset(int s)
	{
		size=s;
		accept();
	}
    void accept()
	{
		cout<<"{ ";
		for(int i=0;i<size;i++)
		{
			cin>>arr[i];
			if(i==size-1)
				cout<<"}";
			else
				cout<<", ";
		}
	}	
	void removeduplicate(Myset<T> &s)
	{
	int t,i,i2=0;
	T temp[20];
	for(i=0;i<s.size;i++)
	{
		t=0;
		if(i==s.size-1)
			temp[i2]=s.arr[i],i2++;								//last emlement to be stored in the array 
		for(int j=i+1;j<s.size;j++)
		{
			if(s.arr[i]==s.arr[j])
				t=1,j=s.size;					//break
			if(t==0&&j==s.size-1)
				temp[i2]=s.arr[i],i2++;
		}
		cout<<endl;
	}

	s.size=i2;
	for(int i=0;i<i2;i++)
		s.arr[i]=temp[i];	
			
//	// 	return 0;		
	}  
	Myset operator +(Myset<T> &set2)
	{
		int count=0,i2=0;
		T common[20];
		for(int i=0;i<this->size;i++)
		{
			for(int j=0;j<set2.size;j++)
			{
				if(this->arr[i]==set2.arr[j])
					common[i2]=this->arr[i],i2++,count++;
			}
		}
		
		i2=0;
		Myset set3;
		int s=size+set2.size;
		set3.size=s;
		
		for(int i=0;i<this->size;i++)
		{
			set3.arr[i2]=this->arr[i];
			i2++;
		}
		
		for(int i=0;i<set2.size;i++)
		{
			for(int j=0;j<count;j++)
			{
				if((set2.arr[i]!=common[j])&&j==count-1)
				{
					set3.arr[i2]=set2.arr[i],i2++;
				}
				if(set2.arr[i]==common[j])
				 	j=count;															//to break the loop		
			}
		}
		
		set3.size=i2;
		return set3;		
	}
	Myset operator -(Myset<T> &set2)
	{
		int count=0,i2=0;
		T common[20];
		for(int i=0;i<this->size;i++)
		{
			for(int j=0;j<set2.size;j++)
			{
				if(this->arr[i]==set2.arr[j])
					common[i2]=this->arr[i],i2++,count++;
			}
		}
		
		i2=0;
		Myset set3;
		set3.size=size;
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<count;j++)
			{
				if((arr[i]!=common[j])&&j==count-1)
					set3.arr[i2]=arr[i],i2++;
				if(this->arr[i]==common[j])
					j=count;
			}
		}
		
		set3.size=i2;
		return set3;
	}
	Myset operator *(Myset<T> &set2)
	{
		int count=0,i2=0;
		T common[20];
		for(int i=0;i<this->size;i++)
		{
			for(int j=0;j<set2.size;j++)
			{
				if(this->arr[i]==set2.arr[j])
					common[i2]=this->arr[i],i2++,count++;
			}
		}
		
		Myset set3;
		i2=0;
		int f;
		
		for(int i=0;i<count;i++)
		{
			f=0;
			if(i==count-1)
				set3.arr[i2]=common[i],i2++;
			for(int j=i+1;j<count;j++)
			{
				if(common[i]==common[j])
					f=1;
				if(f==0&&j==count-1)
					set3.arr[i2]=common[i],i2++;	
			}
		}
		set3.size=i2;
		return set3;
	}
	Myset operator ^(Myset<T> &set2)																		//Symmetric difference means union of two sets without any common elements.
	{
		int count=0,i2=0;
		T common[20];
		
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<set2.size;j++)
			{
				if(arr[i]==set2.arr[j])
					common[i2]=arr[i],i2++,count++;
			}
		}
		
		int s=this->size+set2.size;
		i2=0;
		Myset set3;
	    set3.size=s;
		for(int i=0;i<this->size;i++)
		{
			for(int j=0;j<count;j++)
			{
				if(arr[i]==common[j])
					break;
				else if(j==count-1)
					set3.arr[i2]=arr[i],i2++;
			}
		}
		
		for(int i=0;i<set2.size;i++)
		{
			for(int j=0;j<count;j++)
			{
				if(set2.arr[i]==common[j])
					break;
				else if(j==count-1)
					set3.arr[i2]=set2.arr[i],i2++;
			}
		}
		
		set3.size=i2;		
		return set3;
	
	}
	bool operator ==(Myset<T> &set2)
	{
		int f=0;
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<set2.size;j++)
			{
				if(arr[i]!=set2.arr[j]&&f==0)
					f=1,j=set2.size,i=size; 
			}
		}
		return f;
	}
	Myset operator =(const Myset<T> &set2)
	{
		this->size=set2.size;
		for(int i=0;i<set2.size;i++)
		{
			this->arr[i]=set2.arr[i];
		}
		return 0;
	}
	void powerset()
	{
		int t,j;
		for(int i=0;i<pow(2,this->size);i++)
		{
			if(i>0)
				cout<<" , { ";
			else
				cout<<" { ";
			int count=0;
			for(t=i,j=0;j<this->size;j++)
			{
				if(t&1)
				{
					if(count>=1)
						cout<<" , ";
					cout<<this->arr[j]<<" ";
					count++;	
				}
				t=t>>1;
			}		
			cout<<" } ";
		}
	}
	void display()
	{
		for(int i=0;i<this->size;i++)
		{
			cout<<this->arr[i]<<", ";
		}
		cout<<"\b\b }";
	}	
};

int main()
{
	 int t,choice,size1,size2;
	 char ans='y';
	 cout<<"*****************************************DATA TYPE*****************************************"<<endl;
	 cout<<"1.Int \n2.Char \n3.float"<<endl;
	 cout<<"enter which data type you want to use : "<<endl;
	 cin>>t;
	 	 
	 cout<<endl<<endl;
  	 cout<<"Ener which operation you want to perform : ";
	 cout<<endl<<"1. Union ";
	 cout<<endl<<"2. Difference ";
	 cout<<endl<<"3. Intersction ";
	 cout<<endl<<"4. Symmetric Difference ";
	 cout<<endl<<"5. Equal to ";
	 cout<<endl<<"6. Assingment ";
	 cout<<endl<<"7. Powerset "<<endl;
	 while(ans=='y')
	 {
 		cout<<"\n  Enter your choice : "<<endl;
		cin>>choice;
	 	switch(choice)
		{
			case 1:
			{	
				cout<<"enter the size of first object : ";
				cin>>size1;
				cout<<"enter the size of second object : ";
				cin>>size2;
					
			 	if(t==1)
	 			{
					Myset<int> ob(size1),ob2(size2),ob3;
	 				cout<<endl<<"A+B= ";
			 		ob.removeduplicate(ob);
					ob2.removeduplicate(ob2);
					ob3=ob+ob2;
	 				ob3.display(); 
					break;
				}
				else if(t==2)
				{
					Myset<char> ob(size1),ob2(size2),ob3;
			  	    cout<<endl<<"A+B= ";
					ob.removeduplicate(ob);
					ob2.removeduplicate(ob2);
					ob3=ob+ob2;
					ob3.display(); 
					break;
	 			}
				else if(t==3)
				{
					Myset<float> ob(size1),ob2(size2),ob3;
	 				cout<<endl<<"A+B= ";
	 				ob.removeduplicate(ob);
					ob2.removeduplicate(ob2);
					ob3=ob+ob2;
					ob3.display(); 
					break;
				}
			}
			case 2:
			{
				cout<<"enter the size of first object : ";
				cin>>size1;
				cout<<"enter the size of second object : ";
				cin>>size2;
			 	if(t==1)
	 			{
					Myset<int> ob(size1),ob2(size2),ob3;
	 				cout<<endl<<"A-B= ";
					ob.removeduplicate(ob);
					ob2.removeduplicate(ob2);
					ob3=ob-ob2;
					ob3.display(); 
					break;
				}
				else if(t==2)
				{
					Myset<char> ob(size1),ob2(size2),ob3;
	 				cout<<endl<<"A-B= ";
					ob.removeduplicate(ob);
					ob2.removeduplicate(ob2);
					ob3=ob-ob2;
					ob3.display(); 
					break;
	 			}
				else if(t==3)
				{
					Myset<float> ob(size1),ob2(size2),ob3;
	 				cout<<endl<<"A-B= ";
					ob.removeduplicate(ob);
					ob2.removeduplicate(ob2);
					ob3=ob-ob2;
					ob3.display(); 
					break;
				}					
				}
			case 3:
			{
					cout<<"enter the size of first object : ";
					cin>>size1;
					cout<<"enter the size of second object : ";
					cin>>size2;
			 	if(t==1)
	 			{
					Myset<int> ob(size1),ob2(size2),ob3;
	 				cout<<endl<<"A*B= ";
					ob.removeduplicate(ob);
					ob2.removeduplicate(ob2);
					ob3=ob*ob2; 
					ob3.display();
					break;
				}
				else if(t==2)
				{
					Myset<char> ob(size1),ob2(size2),ob3;
	 				cout<<endl<<"A*B= ";
					ob.removeduplicate(ob);
					ob2.removeduplicate(ob2);
					ob3=ob*ob2; 
					ob3.display();
					break;
	 			}
				else if(t==3)
				{
					Myset<float> ob(size1),ob2(size2),ob3;
	 				cout<<endl<<"A*B= ";
					ob.removeduplicate(ob);
					ob2.removeduplicate(ob2);
					ob3=ob*ob2; 
					ob3.display();
					break;
				}
			}
			case 4:
			{
					cout<<"enter the size of first object : ";
					cin>>size1;
					cout<<"enter the size of second object : ";
					cin>>size2;
					
			 	if(t==1)
	 			{
					Myset<int> ob(size1),ob2(size2),ob3;
	 				cout<<endl<<"A^B= ";					
			 		ob.removeduplicate(ob);
					ob2.removeduplicate(ob2);
					ob3=ob^ob2;
					ob3.display(); 
					break;
				}
				else if(t==2)
				{
					Myset<char> ob(size1),ob2(size2),ob3;
	 				cout<<endl<<"A^B= ";					
			  	    ob.removeduplicate(ob);
					ob2.removeduplicate(ob2);
					ob3=ob^ob2;
					ob3.display(); 
					break;
	 			}
				else if(t==3)
				{
					Myset<float> ob(size1),ob2(size2),ob3;
	 				cout<<endl<<"A^B= ";	 				
					ob.removeduplicate(ob);
					ob2.removeduplicate(ob2);
					ob3=ob^ob2;
					ob3.display(); 
					break;
				}		
			}
			case 5:	
			{					
				cout<<"enter the size of first object : ";
				cin>>size1;
				cout<<"enter the size of second object : ";
				cin>>size2;
			 	if(t==1)
	 			{
					Myset<int> ob(size1),ob2(size2),ob3;
			 		ob.removeduplicate(ob);
					ob2.removeduplicate(ob2);
					if(ob==ob2)
					 	cout<<"the sets are not equal   ";
					else 
						cout<<"the sets are equal";  
					break;
				}
				else if(t==2)
				{
					Myset<char> ob(size1),ob2(size2),ob3;
			  	    ob.removeduplicate(ob);
					ob2.removeduplicate(ob2);
					if(ob==ob2)
					 	cout<<"the sets are not equal   ";
					else 
						cout<<"the sets are equal";  
					break;
	 			}
				else if(t==3)
				{
					Myset<float> ob(size1),ob2(size2),ob3;
					ob.removeduplicate(ob);
					ob2.removeduplicate(ob2);
					if(ob==ob2)
					 	cout<<"the sets are not equal   ";
					else 
						cout<<"the sets are equal";  
					break;
				}
			}
			case 6:	
			{					
				cout<<"enter the size of first object : ";
				cin>>size1;
				cout<<"enter the size of second object : ";
				cin>>size2;
			 	if(t==1)
	 			{
					Myset<int> ob(size1),ob2(size2);
					cout<<endl<<"Now the elements of the set1."<<endl;
	 				ob.removeduplicate(ob);
					ob2.removeduplicate(ob2);
					ob=ob2;
					ob.display();  
					break;	
				}
				else if(t==2)
				{
					Myset<char> ob(size1),ob2(size2);
					cout<<endl<<"Now the elements of the set1."<<endl;
	 				ob.removeduplicate(ob);
					ob2.removeduplicate(ob2);
					ob=ob2;
					ob.display();  
					break;	
	 			}
				else if(t==3)
				{
					Myset<float> ob(size1),ob2(size2);
					cout<<endl<<"Now the elements of the set1."<<endl;					
	 				ob.removeduplicate(ob);
					ob2.removeduplicate(ob2);
					ob=ob2;
					ob.display();  
					break;	
				}
			}
			case 7:
			{
				cout<<"enter the size of the object : ";
				cin>>size1;
			 	if(t==1)
	 			{
					Myset<int> ob(size1);
					ob.removeduplicate(ob);
					ob.powerset();
					break;
				}
				else if(t==2)
				{
					Myset<char> ob(size1);
					ob.removeduplicate(ob);
					ob.powerset();
					break;
	 			}
				else if(t==3)
				{
					Myset<float> ob(size1);
	 				ob.removeduplicate(ob);
					ob.powerset();
					break;
				}
			}
			default:
					cout<<"this is a invalid choice.";
		} 	
		cout<<endl<<"do you want to continue : ";
		cin>>ans; 	
	 } 
	return 0;
}	

