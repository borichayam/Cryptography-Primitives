#include <iostream>
#include <vector>

using namespace std;

bool is_primitive(int base, int mod) {
    // for(int i=0; i<mod-1; i++) {
    //     base *= base;  //-> 미친 거듭제곱을 하고 앉아있네.. 지수를 1씩 증가 시켜야지!!
    //     base %= mod;
    // }
    
    // if(base == 1) { // -> 이게 아니라 처음으로 g^k mod p=1이 되는 k=p-1인지를 봐야함!
    //     return true;
    // } else {
    //     return false;
    // }
    // 좀 틀렸다 !
//---------------교수님 답안------------------
    // mod should be prime number

    int exp = 2;
    int r = (base * base)%mod; // %mod는 내가 추가한 것.

    for (; r != base; exp++)
    {
        r *= base;
        r %= mod;
    }

    return exp == mod;
}

vector<int> primitive_root(int mod) {
    vector<int> v;
    
    // base 1부터 해도 되긴 한데, 당연히 1은 원시근이 될 수 없음.
    for(int base=2; base<mod; base++) {
        if(is_primitive(base, mod))
            v.push_back(base);
    }

    return v;
}

int main() {
    // 이건 is_primitive 테스트하느라 쓴 거
    // int p = 5;
    // cout << "p = " << p << "\n";

    // for(int g=1; g<p; g++) {
    //     if(is_primitive(g,p)) {
    //         cout << "good! -> " << g << endl;
    //     } else {
    //         cout << "bad.. -> " << g << endl;
    //     }
        
    // }

    int p = 29;

    vector<int> a = primitive_root(p);

    cout << "소수 " << p << "의 원시근: ";

    for(int i=0; i<a.size(); i++)
        if(i!=a.size()-1)
            cout << a[i] << ", ";
        else if (i == a.size()-1)
            cout << a[i] << endl;

    // 매우 간단한 방법! ㅋㅋㅋ..
    // for (int i : primitive_root(29)){
    //     cout << i << ',';
    // }
    // cout << endl;
        
}