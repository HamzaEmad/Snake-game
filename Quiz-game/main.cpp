#include<bits/stdc++.h>
using namespace std;

class User
{
public:
    string firstname, lastname , UserName, password , Role ;


};

class admin : public User
{
public:

    admin( string name , string pass , string R , string fname , string lname )
    {
        UserName = name ;
        password = pass ;
        Role = R ;
        firstname=fname;
        lastname=lname;
    }
    admin(){}

    void admin_menu(){
    cout<<"Welcome user user ("<<UserName<<"), please choose from the following options:"<<endl
    <<"[1] Switch accounts"<<endl
    <<"[2] Update your name"<<endl
    <<"[3] View all users"<<endl
    <<"[4] Add new user"<<endl
    <<"[5] View all questions"<<endl
    <<"[6] Add new question"<<endl
    <<"[7] Load questions from file"<<endl
    <<"[8] Exit the program"<<endl
    <<"My choice:"<<endl;
    }


    void Update_Name(string username)
    {
        UserName=username;
    }


};


bool operator==( User user1,User user2 )
{
    if( user1.UserName == user2.UserName )
        return 1;
    else
        return 0;
}

class player : public User
{
public:

    player( string name , string pass , string R, string fname , string lname )
    {

        UserName = name ;
        password = pass ;
        Role = R ;
        firstname=fname;
        lastname=lname;
    }
    player(){}

    void player_menu(){
    cout<<"Welcome user user ("<<UserName<<"), please choose from the following options:"<<endl
    <<"[1] Switch accounts"<<endl
    <<"[2] Update your name"<<endl
    <<"[3] Start a new quiz"<<endl
    <<"[4] Display your scores statistics"<<endl
    <<"[5] Display all your scores"<<endl
    <<"[6] Display details of your last 2 quizzes"<<endl
    <<"[7] Exit the program"<<endl
    <<"My choice:"<<endl;
    }

    void Update_Name(string username)
    {
        UserName=username;
    }
};

void view_all_users( vector<admin> vector_of_admins , vector<player> vector_of_Players )
{
    for(int i=0 ; i < max( vector_of_admins.size() , vector_of_Players.size() ) ; i++)
    {
        if(i==0)
            cout<<"First name"<<"     "<<"Last name"<<"     "<<"Username Role"<<endl;
        if( i < vector_of_admins.size() )
            cout<<vector_of_admins[i].firstname<<"      "<<vector_of_admins[i].lastname<<"      "<<vector_of_admins[i].UserName<<"      "<<"admin"<<endl;
        if( i < vector_of_Players.size() )
            cout<<vector_of_Players[i].firstname<<"     "<<vector_of_Players[i].lastname<<"     "<<vector_of_Players[i].UserName<<"     "<<"player"<<endl;
    }
    cout<<"Press [n] if you want to add a new user or [b] to go back to the main menu."<<endl;
}

void add_new_user(vector<admin> &vector_of_admins , vector<player>&vector_of_players , admin admin_default , player player_default )
{
                string Role ;
                begn_addnew:
                cout<<"enter the role : "<<endl;
                cin>>Role;
                if( Role == "admin" ){
                vector_of_admins.push_back(admin_default);
                while(1){
                bool check = false ;
                cout<<"enter first name : "<<endl;
                cin>>vector_of_admins[ vector_of_admins.size()-1 ].firstname;
                cout<<"enter last name : "<<endl;
                cin>>vector_of_admins[ vector_of_admins.size()-1 ].lastname;
                cout<<"enter Username : "<<endl;
                cin>>vector_of_admins[ vector_of_admins.size()-1 ].UserName;
                cout<<"enter the password : "<<endl;
                cin>>vector_of_admins[ vector_of_admins.size()-1 ].password;
                vector_of_admins[vector_of_admins.size()-1].Role="admin";
                for(int i=0 ; i<vector_of_admins.size()-1 ; i++)
                {
                    if( vector_of_admins[vector_of_admins.size()-1] == vector_of_admins[i] )
                        {
                            cout<<" ****** Note :- this username is used ***** " <<endl;
                            check = true;
                            break;
                        }
                }

                    if(check == false)
                        break;
                }
                }

                else if( Role == "player" )
                {
                    vector_of_players.push_back(player_default);
                    while(1){
                    bool check = false ;
                    cout<<"enter first name : "<<endl;
                    cin>>vector_of_players[ vector_of_players.size()-1 ].firstname;
                    cout<<"enter last name : "<<endl;
                    cin>>vector_of_players[ vector_of_players.size()-1 ].lastname;
                    cout<<"enter Username : "<<endl;
                    cin>>vector_of_players[ vector_of_players.size()-1 ].UserName;
                    cout<<"enter the password : "<<endl;
                    cin>>vector_of_players[ vector_of_players.size()-1 ].password;
                    vector_of_players[vector_of_players.size()-1].Role="player";
                    for(int i=0 ; i<vector_of_players.size()-1 ; i++)
                    {
                        if( vector_of_players[vector_of_players.size()-1] == vector_of_players[i] )
                        {
                            cout<<" ****** Note :- this username is used ***** " <<endl;
                            check = true;
                            break;
                        }
                    }

                    if( check == false  )
                    break;
                }

                }
                else
                    goto begn_addnew;
}

int main()
{
    cout<<"***********************"<<endl
    <<"         Welcome to the Quiz game program V2.0!"<<endl
    <<"***********************"<<endl;
    admin admin_default("admin","admin","admin","admin","admin");
    vector<admin> vector_of_admins;
    vector_of_admins.push_back(admin_default);
    player player_default( "player" , "player" , "player", "player" , "player" );
    vector<player> vector_of_players;
    vector_of_players.push_back(player_default);
    char choice='1' ;
    string Username , password ;
    bool check = false ;
    string Role_check;
    int User_id=0 , num_of_admins;
    while(choice!='8'){
    while( 1 )//name and check
    {
        logn:
        check = false ;
        cout<<"enter your name :"<<endl;
        cin>>Username;
        cout<<"enter Password : "<<endl;
        cin>>password;
        for(int i=0 ; i<vector_of_admins.size() ; i++)
        {
            if( Username == vector_of_admins[i].UserName && password==vector_of_admins[i].password )
            {
                check = true;
                Role_check="admin";
                User_id=i;
                break;
            }
        }
        if( check == true )
            break;
        for(int i=0 ; i<vector_of_players.size() ; i++)
        {
            if( Username == vector_of_players[i].UserName && password == vector_of_players[i].password )
            {
                check = true ;
                Role_check="player";
                User_id=i;
                break;
            }
        }
        if( check == true )
            break;
    }
        begn:
        if (Role_check=="admin")
            vector_of_admins[User_id].admin_menu();
        else
            vector_of_players[User_id].player_menu();

        cin>>choice;
        switch(choice)
        {
        case '1' :
            goto logn;
            break;
        case '2' :

            if( Role_check == "admin" )
                {
                cout<<"enter new name "<<endl;
                cin>>Username;
                vector_of_admins[User_id].Update_Name(Username);}
                else{
                cout<<"enter new name "<<endl;
                cin>>Username;
                vector_of_players[User_id].Update_Name(Username);}
                goto begn;
                break;
        case '3':
            if( Role_check == "admin" )
                 view_all_users(vector_of_admins , vector_of_players);
                 cin>>choice;
                 if (choice == 'n')
                    goto view_all_add;
                 else
                 goto begn;
            break;
        case '4' :
            if(Role_check=="admin")
                view_all_add:
                add_new_user(vector_of_admins , vector_of_players , admin_default , player_default);
            goto begn;
            break;
        }

        break;
    }
    for(int i=0 ; i<max( vector_of_admins.size() , vector_of_players.size() ) ; i++)
    {
        cout<<vector_of_admins[i].UserName<<"      "<<vector_of_players[i].UserName<<endl;
    }
    return 0;
}
