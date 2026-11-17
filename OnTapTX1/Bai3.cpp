//Bai3
#include<bits/stdc++.h>
using namespace std;
//void change(int n,char a, char b, char c){
//	if(n==1){
//		cout<<"\nChuyen tu "<<a <<" sang "<<b<<endl;
//	}else{
//		change(n-1,a,c,b);//a sang b
//		change(1,a,b,c);//a sang c
//		change(n-1,b,a,c);//b sang c
//	}
//}
//
//int main(){
//	int n;
//	
//	cout<<"\nNhap n:";	cin>>n;
//	change(n,'A','B','C');
//	return 0;
//}


//cach 2 khu de quy


struct call{
    int n;
    char a;
    char b;
    char c;
};

struct my_stack{
    int top;
    call *e;
};

void init(my_stack &s){
    s.top = -1;
    s.e = NULL;
};

bool empty(my_stack s){
    return s.top == -1;
}

void push(my_stack &s, call call_in){
    if(empty(s)){
        s.e = (call*)malloc(sizeof(call));
    }else{
        s.e = (call*)realloc(s.e, (s.top + 2) * sizeof(call));
    }

    s.top++;
    s.e[s.top] = call_in;
}

void pop(my_stack &s, call &call_out){
    if(empty(s)) return;

    call_out = s.e[s.top];

    if(s.top == 0){
        free(s.e);
        init(s);
    }else{
        s.top--;
        s.e = (call*)realloc(s.e, (s.top + 1) * sizeof(call));
    }
}

void change(call first_call){
    call call_in, call_out;
    my_stack s;

    init(s);
    push(s, first_call);

    while(!empty(s)){
        pop(s, call_out);

        if(call_out.n == 1){
            cout << "Chuyen dia tu coc "
                 << call_out.a
                 << " sang coc "
                 << call_out.c << endl;
        }else{
            // Ð?y theo th? t? ngu?c c?a d? quy

            // change(n-1, b, a, c)
            call_in.n = call_out.n - 1;
            call_in.a = call_out.b;
            call_in.b = call_out.a;
            call_in.c = call_out.c;
            push(s, call_in);

            // Chuy?n dia l?n nh?t
            call_in = call_out;
            call_in.n = 1;
            push(s, call_in);

            // change(n-1, a, c, b)
            call_in.n = call_out.n - 1;
            call_in.a = call_out.a;
            call_in.b = call_out.c;
            call_in.c = call_out.b;
            push(s, call_in);
        }
    }
}

int main(){
    call first_call = {3,'A','B','C'};
    change(first_call);
    return 0;
}
