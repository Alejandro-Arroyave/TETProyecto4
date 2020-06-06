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
#pragma omp parallel for reduction (*:p)
    for(int i=val; i > 1; i--){
        p=p*i;
    }
    return p;
}

void ListaPerm(int val){
   vector<int> integers(val);
	int i=1;
	generate(integers.begin(),integers.end(),[&i](){return i++;});
 
	while(1)
	{
		auto it_k = integers.end();
		auto it_l = integers.end();
		
#pragma omp parallel for 
		for( auto it = integers.begin(); it != (integers.end()-1); ++it)
		{
		  if ( *it < *(it+1) ){
		    #pragma omp critical
		    it_k = it;
		  }
		  
		}
	
		if ( it_k == integers.end() )
			return;
		#pragma omp parallel for
		for( auto it = it_k+1; it!=integers.end(); ++it)
		{
		  if ( *it_k < *it ){
		    #pragma omp critical
		    it_l = it;
		  }
		}
	
		iter_swap(it_k,it_l);
		reverse(it_k+1,integers.end());
	}
	
}

int main()
{
	int perm = 6;
	const double t0 = omp_get_wtime();
	printf("Numero: %d\n", NoPerm(perm));
	ListaPerm(perm);
	const double t1 = omp_get_wtime();
	printf("Time: %f\n", t1-t0);

}
