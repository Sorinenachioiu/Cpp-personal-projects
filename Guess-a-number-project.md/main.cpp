#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <queue>

using namespace std;

ifstream in ("minim.in");
int main()
{
    queue <int> q;
    srand(time(NULL));
    int c,i=1,minim=1002,nr,v[1001],a=rand()%1001;
    cout<<"What do you want to do : "<<'\n'<<" 1: Guess a random number between 0 and 1000 "<<'\n'<<" 2: Quit"<<'\n';
    cin>>c;
    if(c==1)
    {
        cout<<"Enter a number : "<<'\n';
        bool ok=1;
        while(ok)
        {
            cin>>nr;
            q.push(nr);
            if(nr>a)
                cout<<"The searched for number is lower "<<'\n';
            else if(nr<a)
                {
                    cout<<"The searched for number is higher "<<'\n';
                }
                else  if(nr==a)
                {
                    ok=0;
                    cout<<"You guessed the number ! "<<'\n';
                }
        }
        in>>minim;
        in.close();
        ofstream out ("minim.in");
        int size=q.size();
	    a=min(minim,size);
	    out<<a<<'\n';
	    out.close();

        cout<<"Your attempts have been : "<<'\n';
        for(int j=1;j<=size;j++)
        {
             cout<<q.front()<<" ";
             q.pop();
        }

    }
    else
        cout<<"<--Goodbye!-->";
    return 0;
}
