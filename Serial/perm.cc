#include <cstdlib>
#include <cstdio>
#include <omp.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int NoPerm(int val){
    int p = 1;
    for(int i=val; i > 1; i--){
        p=p*i;
    }
    return p;
}

void ListaPerm(int val){
   vector<int> integers(val);
	int i=1;
	generate(integers.begin(),integers.end(),[&i](){return i++;});
	ostream_iterator<int> os(cout," ");

	
	while(1)
	{
	  //copy(integers.begin(),integers.end(),os);
	       
	
		auto it_k = integers.end();
		auto it_l = integers.end();

		for( auto it = integers.begin(); it+1!=integers.end(); ++it)
		{
			if ( *it < *(it+1) ) it_k = it;
		}

		if ( it_k == integers.end() )
			return;

		for( auto it = it_k+1; it!=integers.end(); ++it)
		{
			if ( *it_k < *it ) it_l = it;
		}
	
		iter_swap(it_k,it_l);
		reverse(it_k+1,integers.end());
	}
}

int main()
{
	int perm = 12;
	const double t0 = omp_get_wtime();
	printf("Numero: %d\n", NoPerm(perm));
	ListaPerm(perm);
	const double t1 = omp_get_wtime();
	printf("Time: %f\n", t1-t0);

}
