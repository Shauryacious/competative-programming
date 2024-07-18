#include<iostream>
#include<vector>
using namespace std;
long long max_of_all(long long x , long long y , long long z , long long a , long long b , long long c)
{
    if (x%2==0 && x > 0)
    x--;
     if (y%2==0&& y > 0)
    y--;
     if (z%2==0&& z > 0)
    z--;
    
     if (a%2==0&& a > 0)
    a--;
     if (b%2==0&& b > 0)
    b--;
     if (c%2==0&& c > 0)
    c--;
    long long maxxy = max(x,y) ; 
    long long maxza= max(z,a) ; 
    long long maxbc = max(b,c) ; 
    long long maxxyza = max (maxxy , maxza) ; 
    long long maxfinal = max (maxxyza,maxbc) ; 
    return maxfinal ; 
}
int main() {
	// your code goes here
	int t ; cin >> t ; 
	while (t--) 
	{
	    long long mg , my , mr , og , oy , ore , pg , py , pr ; cin >> mg >> my >> mr >> og >> oy >> ore >> pg >> py >> pr  ; 
	    long long summ = mg + my + mr , sumo=og + oy + ore , sump = pg + py + pr  , sumg = mg + og+ pg , sumy = my+oy+py , sumr = ore+mr+pr ; 
	    
	    cout << max_of_all(summ , sumo , sump , sumg , sumy , sumr) << endl ; 
	}
	return 0;
}
