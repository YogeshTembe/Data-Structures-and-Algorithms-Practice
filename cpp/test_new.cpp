#include <iostream>
using namespace std;

// Custom data type
// struct cust
// {
//     int p;
//     cust(int q) : p(q) {}
//     cust() = default;
// };

class cust{
    public:
    int p;
    cust() = default;
};

int main()
{
    cust *var1 = new cust;
    cout<<var1->p<<endl;
 
    cust *var2 = new cust();
    cout<<var2->p<<endl;

    cust c={};
    cout<<c.p<<endl;
    int *p;
    cout<<sizeof(p)<<endl;
    void *p2;
    cout<<sizeof(int)<<endl;
    //cust* var3 = new cust(25);

    int x=45;
    int &ref=x;
    cout<<x<<" "<<ref<<endl;
    int y=67;
    ref=y;
    cout<<x<<" "<<y<<" "<<ref<<endl;
    return 0;
}
