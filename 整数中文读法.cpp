#include <iostream>
#define MAX 11
using namespace std;
long int number;
int elem[MAX]={0},i=0;
string num[10]={"零","一","二","三","四","五","六","七","八","九"};
int size(long int &number){
    while(number>0){
        elem[i]=number%10;
        number/=10;
        i++;
    }
    return i;
}
long int signal(long int &number){
    if(number<0){
        cout<<"负";
        number=-number;
    }
    return number;
}
int FirstThree(int &numsize){
    if(numsize>=9){
        for(int j=numsize;j>=9;j--){
            if(j==11 && elem[j-1] !=0) cout<<num[elem[j-1]]<<"百";
            if(j==10) {
                if(elem[j-1]==0 && elem[j-2] != 0) cout<<"零";
                else if(elem[j-1] != 0){
                    if(numsize==10 && elem[i-1]==1) cout<<"十";
                    else cout<<num[elem[j-1]]<<"十";
                }
            }
            if(j==9 && elem[j-1] !=0 ) cout<<num[elem[j-1]];
        }
        cout<<"亿";
        numsize=8;
        return 1;
   }
    return 0;
}
int CenterFour(int &numsize,int m){
    if(m==1){
        if(elem[8]==0 &&(elem[7] != 0 || elem[6] != 0 || elem[5] != 0 || elem[4] !=0)) cout<<"零";
    }
    if(numsize>=5){
        for(int i=numsize;i>=5;i--){
            if(i==8){
                if(elem[i-1]==0 && (elem[i-2] !=0 || elem[i-3] != 0 || elem[i-4] !=0)) cout<<"零";
                else if(elem[i-1] !=0) cout<<num[elem[i-1]]<<"千";
            }
            if(i==7){
                if(elem[i-1]==0 && elem[i] !=0 && (elem[i-2] !=0 || elem[i-3] !=0)) cout<<"零";
                else if(elem[i-1] != 0) cout<<num[elem[i-1]]<<"百";
            }
            if(i==6){
                if(elem[i-1]==0 && elem[i] != 0  && elem[i-2] !=0) cout<<"零";
                else if(elem[i-1] != 0) {
                    if(numsize==6 && elem[i-1]==1) cout<<"十";
                    else cout<<num[elem[i-1]]<<"十";
                }
            }
            if(i==5 && elem[i-1] !=0) cout<<num[elem[i-1]];
        }
        for(int j=numsize;j>=5;j--){
            if(elem[j-1] != 0){
                cout<<"万";
                break;
            }
        }
        numsize=4;
        return 1;
    }
    return 0;
}
void LastFour(int &numsize,int &n){
    if(n==1){
        if(elem[4]==0 &&(elem[3] != 0 || elem[2] != 0 || elem[1] != 0 || elem[0] !=0)) cout<<"零";
        else if(elem[4] != 0 && elem[3]==0 &&(elem[2] !=0 || elem[1] !=0 || elem[0] !=0)) cout<<"零";
    }
    for(int i=numsize;i>=0;i--){
        if(i==4 && elem[i-1]!=0) cout<<num[elem[i-1]]<<"千";
        if(i==3){
            if(elem[i-1]==0 && elem[i] !=0 &&(elem[i-2] !=0 || elem[i-3]!=0)) cout<<"零";
            else if(elem[i-1] != 0) cout<<num[elem[i-1]]<<"百";
        }
        if(i==2){
            if(elem[i-1]==0 && elem[i] != 0 && elem[i-2] !=0) cout<<"零";
            else if(elem[i-1] != 0){
                if(numsize==2 && elem[i-1]==1) cout<<"十";
                else cout<<num[elem[i-1]]<<"十";
            }
        }
        if(i==1 && elem[i-1] !=0) cout<<num[elem[i-1]];
    }
}
int main(int argc, const char * argv[]){
    cout<<"Please input a number:";
    cin>>number;
    cout<<"汉字输出：";
    if(number==0){
        cout<<"零"<<endl;
        return 0;
    }
    number=signal(number);
    int numsize=size(number);
    int m=FirstThree(numsize);
    int n=CenterFour(numsize,m);
    LastFour(numsize,n);
    cout<<endl;
    return 0;
}