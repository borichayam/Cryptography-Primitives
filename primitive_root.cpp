bool is_primitive(int base, int mod) {
    int exp = 2;
    int r = base * base;

    for(; r != base; exp++) {
        r *= base;
        r %= mod;
    } 
    return exp == mod;
}

vector<int> primitive_root(int mod) {
	vector<int> v;
	for(int base=2; base<mod; base++) if(is_primitive(base, mod)) v.push_back(base);
	return v;
}


int main(void) {
    if(is_primitive(3,5)) {
        printf("good");
    }
    if(is_primitive(3,7)) {
        printf("good");
    }
}