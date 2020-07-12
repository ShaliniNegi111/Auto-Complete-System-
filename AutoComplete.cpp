#include <bits/stdc++.h>
using namespace std;
struct Node 
{
	bool IsEnd ; 
	Node * children [ 26 ] ; 
	
	Node ()
	{
		IsEnd = false ; 
		for ( int i = 0 ; i < 26 ; i ++ )
			children [ i ] = NULL ;
	}
};
class AutoComplete 
{
	Node * root ; 
	vector < string > Disc ; 
	
	public : 
	
	AutoComplete ( vector < string > Disc)
	{
		root = new Node() ; 
		this ->	Disc  = Disc ; 
		insert() ; 
		
	}
	void insert ()
	{
		for ( int i = 0 ; i < Disc .size() ; i ++ )
			insertUitl ( Disc [ i ] ) ;
	}
	
	
	
	void Delete () ; 
	void insertUitl ( string s )
	{
		Node * ptr = root ;
		int n = s.length() ; 
		for ( int i = 0 ; i < n ; i ++ )
		{
			if ( ptr -> children [ s [ i ] - 'a' ] == NULL )
				 ptr -> children [ s [ i ] - 'a' ] = new Node () ; 
			
			ptr =  ptr -> children [ s [ i ] - 'a' ]  ; 
		}
		
		ptr -> IsEnd = true ; 
	}
	
	void prefixUtil ( Node * root , string s )
	{
		if ( root -> IsEnd == true )
			cout << s << endl ; 
		
		for ( int i = 0 ; i < 26 ; i ++ )
		{
			if ( root -> children [ i ] )
				prefixUtil (  root -> children [ i ] , s + char ( 'a' + i ) ) ; 
		}
	}
	void prefix ( string s )
	{
		Node * ptr = root ;
		int n = s.length() ; 
		for ( int i = 0 ; i < n ; i ++ )
		{
			if ( ptr -> children [ s [ i ] - 'a' ] == NULL )
				return ; 
			ptr =  ptr -> children [ s [ i ] - 'a' ]  ; 
		}
		
		prefixUtil ( ptr ,  s ) ;  
	}
};

int main() {
	
	int n ;
	cin >> n ; 
	vector < string > Dics ; 
	for ( int i = 0 ; i < n ; i ++ )
	{
		string  s ; 
		cin >> s ; 
		Dics.push_back ( s ) ; 
	}
	AutoComplete t ( Dics ) ;

    
    	t. prefix ( "hel" ) ; 
	// your code goes here
	return 0;
}
