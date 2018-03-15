#include <cstdio>
using namespace std;

int main()
{
        int n, a, b;
        char p[2];
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%s", p);
            scanf("%d%d", &a, &b);
            if(p[0] == '-') printf("%d\n", a-b);
            else if(p[0] == '+') printf("%d\n", a+b);
            else if(p[0] == '*') printf("%d\n", a*b);
            else{
                if(a%b) printf("%.2f\n", a*1.0/b);
                else printf("%d\n", a/b);
            }
        }
    return 0;
}
