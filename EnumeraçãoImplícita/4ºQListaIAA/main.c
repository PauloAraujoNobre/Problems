#include <stdio.h>
int main(){
    int C[3] = {8, 5, 3};
    int K[3] = {0, 0, 0};
    int n = 2;
    int i = 0;
    int Limite = 7;
    int soma = 0;
    int atual = 0;
    int flag = 0;
    while(soma != Limite || flag == 0){
        
        if(flag == 1 || Limite == 0){
            printf("Combinação não encontrada\n");
            break;
        }
        
        while(soma + C[i] <= Limite){
            K[i]++;
            soma += C[i];
            if(soma == Limite){
                flag = 1;
                printf("Combinação encontrada:\n");
                for (int j = 0; j <= n; j++){
                    printf("%d ", K[j]);    
                }
                break;
            }
        }
        //int a;
        //scanf("%d", &a);
        //printf("i: %d\nn: %d\nsoma: %d\n", i, n, soma);
        
        //for (int j = 0; j <= n; j++){
        //    printf("%d ", K[j]);    
        //}
        //printf("\n");
        
        if(soma + C[i+1] > Limite){
            K[i]--;
            soma -= C[i];   
        }
        
        if(i == n){
            int aux = 1;
            while(K[i - aux] == 0){
                aux++;
                if(i - aux < 0){
                    flag = 1;
                    printf("Combinação não encontrada\n");
                    break;
                }
            }
            K[i - aux]--;
            soma -= C[i - aux];
            i = i - aux;
        }
        i++;
    }
    return 0;
}
