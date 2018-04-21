#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void bolhas(int v[], int n);
int selmin(int v[], int i, int n);
void selecao(int v[], int n);
void insertionSort(int *v, int n);
void shellSort(int *v, int n);
void quicksort(int *v, int left, int right);
int getMaior(int *a, int n);
void countSort(int *a, int n, int exp);
void radixsort(int *a, int n);
void mergeSort(int *v, int left, int right);
void merge(int *v, int inicio, int meio, int fim);
void imprimir(int *vet, int n);
int* createV(int n);
int *copy(int *v, int n);
int menu();

int main() {
    clock_t t1, t2;
    int *v, *v2, *v3, *v4, *v5, *v6, *v7;
    int n=8700000;

    v=createV(n);
    v2=copy(v,n);
    v3=copy(v,n);
    v4=copy(v,n);
    v5=copy(v,n);
    v6=copy(v,n);
    v7=copy(v,n);
    printf("\ncopiando...");

    printf("\nv: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", v[0], v[n/10], v[n/9], v[n/7], v[n/6], v[n/5], v[n/4], v[n/3],  v[n/2], v[n-1]);
    printf("\nv: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", v2[0], v2[n/10], v2[n/9], v2[n/7], v2[n/6], v2[n/5], v2[n/4], v2[n/3],  v2[n/2], v2[n-1]);
    printf("\nv: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", v3[0], v3[n/10], v3[n/9], v3[n/7], v3[n/6], v3[n/5], v3[n/4], v3[n/3],  v3[n/2], v3[n-1]);
    printf("\nv: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", v4[0], v4[n/10], v4[n/9], v4[n/7], v4[n/6], v4[n/5], v4[n/4], v4[n/3],  v4[n/2], v4[n-1]);
    printf("\nv: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", v5[0], v5[n/10], v5[n/9], v5[n/7], v5[n/6], v5[n/5], v5[n/4], v5[n/3],  v5[n/2], v5[n-1]);
    printf("\nv: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", v6[0], v6[n/10], v6[n/9], v6[n/7], v6[n/6], v6[n/5], v6[n/4], v6[n/3],  v6[n/2], v6[n-1]);
    printf("\nv: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", v7[0], v7[n/10], v7[n/9], v7[n/7], v7[n/6], v7[n/5], v7[n/4], v7[n/3],  v7[n/2], v7[n-1]);

    int sair=0;
    do{
          switch(menu()){
            case 1:
                printf("\nbolha: ordenando...");
                t1 = clock();
                bolhas(v,n);
                t2 = clock();
                printf("\n\n%f\n",(((float)t2 - (float)t1) / 1000000.0F ));
                system("pause");
             //   imprimir(v,n);
            break;
            case 2:
                printf("\nselecao: ordenando...");
                t1 = clock();
                selecao(v2,n);
                t2 = clock();
                printf("\n\n%f\n",(((float)t2 - (float)t1) / 1000000.0F ));
                system("pause");
               // imprimir(v2,n);
            break;
            case 3:
                printf("\ninsercao: ordenando...");
                t1 = clock();
                insertionSort(v3,n);
                t2 = clock();
                printf("\n\n%f\n",(((float)t2 - (float)t1) / 1000000.0F ));
                system("pause");
                //imprimir(v3,n);
            break;
            case 4:
                printf("\nshellSort: ordenando...");
                t1 = clock();
                shellSort(v4,n);
                t2 = clock();
                printf("\n\n%f\n",(((float)t2 - (float)t1) / 1000000.0F ));
                system("pause");
                //imprimir(v4,n);
            break;
            case 5:
                printf("\nquickSort: ordenando...");
                t1 = clock();
                quicksort(v5,0,n-1);
                t2 = clock();
                printf("\n\n%f\n",(((float)t2 - (float)t1) / 1000000.0F ));
                system("pause");
                //imprimir(v5,n);
            break;
            case 6:
                printf("\nradixSort: ordenando...");
                t1 = clock();
                radixsort(v6, n);
                t2 = clock();
                printf("\n\n%f\n",(((float)t2 - (float)t1) / 1000000.0F ));
                system("pause");
                //imprimir(v6, n);
            break;
            case 7:
                printf("\nmergeSort: ordenando...");
                t1 = clock();
                mergeSort(v7, 0, n-1);
                t2 = clock();
                printf("\n\n%f\n",(((float)t2 - (float)t1) / 1000000.0F ));
                system("pause");
                //imprimir(v7, n);
            break;
            case 8:
                sair=1;
            break;
            default:
                printf("opcao invalida!");
        }
    }while(!sair);

	return 0;
}


void bolhas(int v[], int n) {
    int i, j;
    for(i=1; i<n; i++) {
        for(j=0; j<n-i; j++) {
            if( v[j]>v[j+1] ) {
                int x = v[j];
                v[j] = v[j+1];
                v[j+1] = x;
            }
        }
    }
}

int selmin(int v[], int i, int n) {
    int j, k=i;
    for(j=i+1; j<n; j++) {
        if( v[k]>v[j] ) {
            k=j;
        }
    }
    return k;
}
void selecao(int v[], int n) { //Ordenação por seleção
    int i, k, x;
    for(i=0; i<n-1; i++) {
        k = selmin(v,i,n);
        x = v[i];
        v[i] = v[k];
        v[k] = x;
    }
}

void insertionSort(int *v, int n) {
	int i, j, atual;

	for (i = 1; i < n; i++) {
		atual = v[i];

		for (j = i - 1; (j >= 0) && (atual < v[j]); j--) {
			v[j + 1] = v[j];
        }
		v[j+1] = atual;
	}
}

void shellSort(int *v, int n) {
	int dist;
	dist=n/2;
	while(dist > 0) {
        int i, j, atual;
		for (i=dist; i < n; i++) {
			atual = v[i];
			for (j=i; (j>=dist) && (atual < v[j-dist]); j=j-dist) {
				v[j]=v[j-dist];
			}
			v[j] = atual;
		}
		dist/=2;
	}
}

void quicksort(int *v, int left, int right) {
    int i, j;
	int pivo;
	i = left;    j = right;
	pivo = v[(left+right)/2];
	do {
		while ((v[i] < pivo) && (i < right))
			i++;
		while (v[j] > pivo && j > left)
			j--;
		if (i <= j) {
			int x = v[i];
			v[i]  = v[j];
			v[j] = x;
			i++; j--;
		}
	}while(i<=j);

	if (left < j) {
		quicksort(v, left, j);
	}
	if (right > i){
		quicksort(v, i, right);
	}
}

void radixsort(int *a, int n){
    int maior = getMaior(a, n);
    int exp;
    for (exp = 1; maior/exp > 0; exp *= 10) {  /** Faz a Contagem de classificação para cada dígito. */
        countSort(a, n, exp);
    }
}

int getMaior(int *a, int n) {
    int maior = a[0];
    int i;
    for (i = 1; i < n; i++) {
        if (a[i] > maior) {
            maior = a[i];
        }
    }
    return maior;
}

/**  Faz a classificação conforme o digito representado por exp  */
void countSort(int *a, int n, int exp) {
    int output[n];
    int count[10] = {0};

    /** Faz a frequencia  */
    int i;
    for (i = 0; i < n; i++)
        count[ (a[i]/exp)%10 ]++;

    /**  Altera count[i] para que count[i] contem a posição atual do digito da saida */
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)     {
        output[count[ (a[i]/exp)%10 ] - 1] = a[i];
        count[ (a[i]/exp)%10 ]--;
    }

    for (i = 0; i < n; i++)
        a[i] = output[i];
}

void mergeSort(int *v, int left, int right){
    if (left < right) {
        int middle = (left+right)/2;
        mergeSort(v, left, middle);
        mergeSort(v, middle+1, right);
        merge(v, left, middle, right);
    }
}

void merge(int *v, int inicio, int meio, int fim) {
    int com1, com2, tam;
	int *vAux;
	com1=inicio;
	com2=meio+1;
	tam = fim-inicio+1;
    vAux = (int*)malloc(tam * sizeof(int));

    int k = 0;
    while(com1<=meio && com2<=fim){
        if(v[com1] <= v[com2]){
            vAux[k] = v[com1];
            com1++;
        }else{
            vAux[k] = v[com2];
            com2++;
        }
        k++;
    }

    while(com1<=meio){  /**move elementos restantes da primeira metade, caso hajam*/
        vAux[k] = v[com1];
        k++;com1++;
    }
    while(com2<=fim){   /**move elementos restantes da segunda metade, caso hajam*/
        vAux[k] = v[com2];
        k++;com2++;
    }

    for(k=inicio;k<=fim;k++){    /**Move os elementos de volta para o vetor original*/
        v[k] = vAux[k-inicio];
    }
}


void imprimir(int *vet, int n) {
    printf("\n\n");
    int i;
    for(i=0;i<n;i++) {
       printf("\n%d", vet[i]);
    }
}

int* createV(int n) {
    int *vet = (int*)malloc(n*sizeof(int));
    int i;
	for (i=0; i<n; i++) {
		vet[i] = rand() % n + 1;
	}
	return vet;
}

int *copy(int *v, int n) {
    int *copyVetor = (int*)malloc(n*sizeof(int));
    int i;
    for(i=0 ; i < n ; i++)
        copyVetor[i] = v[i];

    return copyVetor;
}

int menu() {
    int op;
    printf("\n\n\n");
    printf("\n1. bubbleSort. ");
    printf("\n2. selectionSort. ");
    printf("\n3. insertionSort. ");
    printf("\n4. shellSort. ");
    printf("\n5. quickSort. ");
    printf("\n6. radixSort. ");
    printf("\n7. mergeSort. ");
    printf("\n8. Sair. ");
    printf("\nDigite a opcao desejada: ");
    scanf("%d",&op);
    return op;
}
