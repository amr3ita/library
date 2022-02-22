#include <bits/stdc++.h>
using namespace std;
class library
{
private:
    map<string,string>accounts;
    map<string,int>books;
    map<pair<string,string>,string>clients;
    string name,id,Bname,tel;
    int c;
public:
    library()
    {
        books["c++"]=1;
        books["c"]=1;
        books["c#"]=1;
        books["java"]=1;
        books["oop"]=1;
    }
    bool check(string ID)
    {
        if(ID.length()==14)
            return 1;
        else
            return 0;
    }
    bool phone(string Tel)
    {
        if(Tel.length()==11)
            return 1;
        else
            return 0;
    }
    void signup()
    {
        cout<<"Name: "; cin>>name;
        do
        {
           cout<<"ID: "; cin>>id;
           if(check(id))
           {
            accounts[name]=id;
            break;
           }
           else
           {
               cout<<"id should be 14 numbers\n";
           }
        }
        while(true);
    }
    bool signin()
    {
        cout<<"Name: "; cin>>name;
        cout<<"ID: "; cin>>id;
        if(accounts[name]==id)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void Books()
    {
        map<string,int>::iterator it=books.begin();
        cout<<"Books:\n";
        for(it;it!=books.end();it++)
        {
            cout<<"'"<<it->first<<"'"<<" ==> "<<it->second<<endl;
        }
        cout<<endl;
    }
    void add_book()
    {
        map<string,int>::iterator it=books.begin();
        cout<<"book name without spacing: "; cin>>name;
        cout<<"How many books: ";cin>>c;
        it=books.find(name);
        if(it==books.end())
            books[name]+=c;
        else
            books[name]+=c;
    }
    bool buy()
    {
        map<string,int>::iterator it;
        cout<<"book name: ";
        string name; cin>>name;
        it=books.find(name);
        if(it!=books.end())
        {
            if(books[name]==1)
                books.erase(it);
            else
                books[name]--;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void borrow()
    {
       map<string,int>::iterator it;
       cout<<"book name: "; cin>>Bname;
       it=books.find(Bname);
       if(it!=books.end())
       {
           cout<<"Your name: "; cin>>name;
           //check id
        do
        {
           cout<<"ID: "; cin>>id;
           if(check(id))
           {
            break;
           }
           else
           {
               cout<<"id should be 14 numbers\n";
           }
        }
        while(true);
        do
        {
           cout<<"phone: "; cin>>tel;
           if(phone(tel))
           {
            break;
           }
           else
           {
               cout<<"phone should be 11 numbers\n";
           }
        }
        while(true);

           clients[{name,id}]=tel;
            if(books[Bname]==1)
                books.erase(it);
            else
                books[Bname]--;
       }
       else
       {
           cout<<"Book Not Found\n";
       }
    }
    void borrowed_books()
    {
        map<pair<string,string>,string>::iterator it=clients.begin();
        if(clients.size()==0)
        {
            cout<<"No borrowed books\n";
        }
        else
        {
            cout<<"Borrowed Books: \n";
            for(it;it!=clients.end();it++)
            {
                cout<<"name: "<<it->first.first<<"\nclient id: "<<it->first.second<<"\nphone: "<<it->second<<endl;
                cout<<"----\n";
            }
        }
    }
    void return_book()
    {
        map<pair<string,string>,string>::iterator it=clients.begin();
        cout<<"client name: "; cin>>name;
        cout<<"ID: "; cin>>id;
        it=clients.find({name,id});
        if(it!=clients.end())
        {
            clients.erase(it);
            add_book();
        }
        else
        {
            cout<<"Not Found\n";
        }
    }
};
int main()
{
    Go:
    library obj;
    int x;
    bool flag=false;
    do
    {
        cout<<"1-sign up\n2-sign in\n0-Exit\n";
        cin>>x;
        if(x==1)
        {
            obj.signup();
        }
        else if(x==2)
        {
            if(obj.signin())
            {
                flag=true;
                break;
            }
            else
                cout<<"name or id invalid\n";
        }
        else if(x==0)
        {
            return 0;
        }
    } while(true);
    int op;
    do
    {
        if(flag)
        {
            cout<<"--------------------\n";
            cout<<"1-books\n2-add book\n3-buy\n4-borrow\n5-borrowed books\n6-return book\n7-sign out\n0-Exit\n";
            cout<<"--------------------\n";
            cin>>op;
            if(op==1)
            {
                obj.Books();
            }
            else if(op==2)
            {
                obj.add_book();
            }
            else if(op==3)
            {
                if(!obj.buy())
                {
                    cout<<"Not Found\n";
                }
            }
            else if(op==4)
            {
                 obj.borrow();
            }
            else if(op==5)
            {
                obj.borrowed_books();
            }
            else if(op==6)
            {
                obj.return_book();
            }
            else if(op==7)
            {
                goto Go;
            }
            else if(op==0)
            {
                return 0;
            }
        }


    }while(true);
}
