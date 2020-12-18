namespace heap_sort{
const int N=(1<<29);
template<typename heap_type> class heapsort{

struct heap{
    heap_type *h;
    int l;
    
    heap_type operator[] (int i){
        return h[i];
    }
};

heap hp;

void heap_swap(heap_type* i1,heap_type* i2){
    heap_type temp=*i2;
    *i2=*i1;
    *i1=temp;
}

void heap_print(){
/*
    for (int i=1;i<=hp.l;i++){
        printf("%s-%d ",hp.h[i].name,hp.h[i].id);
    }
    printf("\n");
*/
}

void heap_put(heap_type x){
    hp.l++;
    int i=hp.l; // i: index
    hp.h[i]=x;
    while ((i>1)&&(hp.h[i >> 1] > hp.h[i])){
        heap_swap(&hp.h[i >> 1], &hp.h[i]);
        i>>=1;
    }
}

heap_type heap_get(){
    heap_type ret=hp.h[1];
    hp.h[1]=hp.h[hp.l];
    int i=1,i1,i2,j;
    while (1){
        int i1=i<<1,i2=i1+1;
        if (i1>hp.l) break; 
        if (i2>hp.l) {
            j=i1;
        } else {
            int t;
            if (hp.h[i1]<hp.h[i2]){
                t=i1;
            } else {
                t=i2;
            }
            if (hp.h[i]<hp.h[t]){
                break;
            } else {
                j=t;
            }
        }
        heap_swap(&hp.h[j], &hp.h[i]);
        i=j;
    }
    hp.l--;
    return ret;
}
public:
void heap_sort(heap_type* a, const int l){
    hp.h=new heap_type[N];
    hp.l=0;
    for (int i=0;i<l;i++){
        heap_put(a[i]);
        heap_print();
    }
    for (int i=0;i<l;i++){
        a[i]=heap_get();
        heap_print();
    }
    delete hp.h;
    // return a;
}
};
}
