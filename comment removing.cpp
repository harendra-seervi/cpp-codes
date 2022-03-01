// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

string removeComments (string s);
int main()
{
    int t; cin >> t;
    cin.ignore ();
    while (t--)
	{
		string s;
		getline (cin, s);
		cout << removeComments (s) << endl;
	}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


string removeComments (string s)
{
    // Your Code Here
    int f=s.find('/');
    if(f!=string::npos){
        if(s[f+1]=='*'){
            cout<<"asdlkfsd"<<endl;
            s.erase(f,1);
            int sec=s.find('/');
            if(sec!=string::npos && s[sec-1]=='*'){
                s.erase(f,(sec-f+1));
            }
        }
        else if(s[f+1]=='/'){
            // cout<<"asdfasdfasdf"<<endl;
            // cout<<f<<endl;
            int ew=s.find('\\');
            // cout<<s[ew+1]<<endl;
            if(ew!=string::npos){
                s.erase(f,ew-f+2);
            }
        }
    }
    // cout<<s<<endl;
    // cout<<s<<endl;
    return s;
    

}