#define LOCAL
#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<queue>
#include<deque>
#include<vector>

using namespace std;

const int N=1000;

deque<int> current;//our main queue,deque is supported to insert front
queue<int> blocked;//the queue of the programs which is blocked.

int var[26];//every variable's value

int num;//the number of programs;
int use_time[5];//the unit execution times for each of the five statements
int quantum;//the number of time units comprising the time quantum
bool is_locked=false;//check current situation

vector<vector<string>> programs(N);
int pointer[N];

void init()
{
    //init
    is_locked=false;
    memset(var,0,sizeof(var));
    memset(pointer,0,sizeof pointer);
    scanf("%d %d %d %d %d %d %d",&num,&use_time[0],&use_time[1],&use_time[2],&use_time[3],&use_time[4],&quantum);
    string tmp="";
    for(int i=0;i<num;i++)
    {
        current.push_back(i);
        vector<string> statement;

        while(getline(cin,tmp))
        {
            if(tmp=="") continue;
            statement.push_back(tmp);
            //cout<<tmp<<endl;
            if(tmp=="end") break;
        }
        programs[i]=statement;
    }
}

void read(int cur)//the current running program's id
{
    int cnt=quantum;
    int &pos=pointer[cur];
    while(cnt>0)
    {
        //if(pos>=(int)programs[cur].size()) return;
        string statement=programs[cur][pos];
        //cout<<"cur:"<<cur<<" statement:"<<statement<<endl;
        if(statement=="lock")
        {

            if(is_locked)
            {
                blocked.push(cur);
                return;
            }
            is_locked=true;
            cnt-=use_time[2];
        }
        else if(statement=="unlock")
        {
            cnt-=use_time[3];
            is_locked=false;
            if(!blocked.empty())//check if blocked is empty,sometimes there is no program in it
            {
                current.push_front(blocked.front());
                blocked.pop();
            }
            
        }
        //Assignment
        else if(statement.find("=")!=statement.npos)
        {
            cnt-=use_time[0];
            char variable=statement[0];
            int number=0;//the number of variable
            for(int i=(int)statement.find("=");i<(int)statement.length();i++)
            {
                if(isdigit(statement[i]))
                {
                    number=number*10+statement[i]-'0';
                }
            }
            var[variable-'a']=number;
        }
        else if(statement.find("print")!=statement.npos)
        {

            cnt-=use_time[1];
            for(int i=(int)statement.length()-1;i>=0;i--)
            {
                char ch=statement[i];
                if(ch>='a'&&ch<='z')
                {
                    cout<<cur+1<<": "<<var[ch-'a']<<endl;
                    break;
                }
            }
        }
        else if(statement=="end")
        {
            return;
        }
        pos++;
    }
    
    current.push_back(cur);
}

int main()
{

    #ifdef LOCAL
    freopen("210.in", "r", stdin);
    freopen("210.out", "w",stdout);
    #endif

    int t=1;
    cin>>t;
    while(t--)
    {
        init();
        while(current.size())
        {
            int front=current.front();;
            current.pop_front();
            read(front);
        }
        if(t) cout<<endl;
    }

    return 0;
}
