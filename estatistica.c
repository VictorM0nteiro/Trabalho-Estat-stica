/*
 * ============================================================
 *  Trabalho Computacional - Estatistica Aplicada
 *  Disciplina: Estatistica
 *  Curso: Sistemas de Informacao
 *  Aluno: Victor Hugo Monteiro da Silva - 12321BSI295
 *
 *  Descricao:
 *    Programa que calcula o Coeficiente de Correlacao de Pearson
 *    e a Regressao Linear Simples a partir de pares (x, y)
 *    fornecidos pelo usuario.
 *
 *    Todos os calculos sao feitos manualmente, sem uso de
 *    bibliotecas estatisticas prontas.
 * ============================================================
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h> //apenas para poder utilizar sqrt() raiz
 #include <string.h>

//   ============================================================
//    Funcao: calcular_media
//    Objetivo: calcula a media aritmetica de um vetor de doubles
//    Parametros:
//      - vetor: array de valores
//      - n    : quantidade de elementos
//    Retorno: media (double)
//   ============================================================

 double calcular_media(double *vetor, int n){
    double soma = 0;
    int i;

    for (i = 0; i < n; i++){
        soma += vetor[i];
    }
    return soma/n;
 }


//  * ============================================================
//  *  Funcao: calcular_pearson
//  *  Objetivo: calcula o coeficiente de correlacao de Pearson
//  *
//  *  Formula:
//  *       r = Sum(xi - x_bar)(yi - y_bar)
//  *           -----------------------------
//  *           sqrt[ Sum(xi - x_bar)^2 * Sum(yi - y_bar)^2 ]
//  *
//  *  Parametros:
//  *    - x, y      : vetores de dados
//  *    - n         : numero de pares
//  *    - media_x   : media de x
//  *    - media_y   : media de y
//  *  Retorno: coeficiente r (double)
//  * ============================================================

 double calcular_pearson(double *x, double *y, int n, double media_x, double media_y){
    double numerador = 0;
    double soma_quad_x = 0;
    double soma_quad_y = 0;
    double diff_x, diff_y;
    int i;

    for (i = 0; i < n; i++){
        diff_x = x[i] - media_x;
        diff_y = y[i] - media_y;
        numerador   += diff_x * diff_y;
        soma_quad_x += diff_x * diff_x;
        soma_quad_y += diff_y * diff_y;
    }

    if(soma_quad_x == 0 || soma_quad_y == 0){
        printf("\n[AVISO] Variancia nula: correlacao indefinida.\n");
        return 0.0;
    }

    return numerador/sqrt(soma_quad_x * soma_quad_y);
 }


// * ============================================================
//  *  Funcao: calcular_regressao
//  *  Objetivo: calcula os coeficientes da reta de regressao linear
//  *
//  *  Formulas:
//  *       b = Sum(xi - x_bar)(yi - y_bar)
//  *           ----------------------------
//  *              Sum(xi - x_bar)^2
//  *
//  *       a = y_bar - b * x_bar
//  *
//  *  Parametros:
//  *    - x, y      : vetores de dados
//  *    - n         : numero de pares
//  *    - media_x   : media de x
//  *    - media_y   : media de y
//  *    - a, b      : ponteiros para receber os coeficientes calculados
//  * ============================================================


void calcular_regressao(double *x, double *y, int n, double media_x, double media_y, double *a, double *b){
    double numerador   = 0;
    double denominador = 0;
    double diff_x;

    for(int i = 0; i < n; i++){
        diff_x = x[i] - media_x;
        numerador += diff_x * (y[i] - media_y);
        denominador += diff_x * diff_x;
    }

    if(denominador == 0){
        printf("\n[AVISO] Todos os valores de x sao iguais. " "Regressao indefinida.\n");
        *b = 0.0;
        *a = media_y;
        return;
    }

    *b = numerador / denominador;
    *a = media_y - (*b) * media_x;
}


void exibir_separador() {
    printf("============================================================\n");
}


int main(){
    int n;
    double *x, *y;
    double media_x, media_y;
    double r;
    double a, b;
    int i;
    char opcao;
    double x_pred, y_pred;

    exibir_separador();
    printf("   ESTATISTICA APLICADA - Correlacao e Regressao Linear\n");
    exibir_separador();

    printf("\nQuantos pares de valores (x, y) deseja inserir? ");
    scanf("%d", &n);

    if (n < 2) {
        printf("\n[ERRO] Sao necessarios pelo menos 2 pares de dados.\n");
        return 1;
    }

    // -- Alocacao dinamica dos vetores --
    x = (double *) malloc(n * sizeof(double));
    y = (double *) malloc(n * sizeof(double));

    if(x == NULL || y == NULL){
        printf("\n[ERRO] Falha ao alocar memoria.\n");
        return 1;
    }

    printf("\nDigite os %d pares de valores:\n", n);
    for (i = 0; i < n; i++) {
        printf("  Par %2d  ->  x: ", i + 1);
        scanf("%lf", &x[i]);
        printf("           y: ");
        scanf("%lf", &y[i]);
    }

    // -- 2. Calculo das medias --
    media_x = calcular_media(x, n);
    media_y = calcular_media(y, n);

    // -- 3. Coeficiente de Correlacao de Pearson --
    r = calcular_pearson(x, y, n, media_x, media_y);

    // -- 4. Regressao Linear Simples --
    calcular_regressao(x, y, n, media_x, media_y, &a, &b);

    //resultados
    printf("\n");
    exibir_separador();
    printf("RESULTADOS\n");
    exibir_separador();

    printf("\nNumero de pares analisados : %d\n", n);

    printf("\n[ Medias ]\n");
    printf("Media de x  (x_bar) = %.4f\n", media_x);
    printf("Media de y  (y_bar) = %.4f\n", media_y);

    printf("\n[ Coeficiente de Correlacao de Pearson ]\n");
    printf("r = %.4f\n", r);

    //  Interpretacao qualitativa do r
    printf("Interpretacao: ");
    double r_abs = r < 0 ? -r : r;   /* valor absoluto manual */
    if (r_abs >= 0.90) printf("correlacao muito forte\n");
    else if (r_abs >= 0.70) printf("correlacao forte\n");
    else if (r_abs >= 0.50) printf("correlacao moderada\n");
    else if (r_abs >= 0.30) printf("correlacao fraca\n");
    else printf("correlacao muito fraca ou nula\n");

    if (r > 0) printf(" Direcao: positiva (quando x aumenta, y tende a aumentar)\n");
    else if (r < 0) printf(" Direcao: negativa (quando x aumenta, y tende a diminuir)\n");

    printf("\n[ Regressao Linear Simples ]\n");
    printf("Coeficiente angular  b = %.4f\n", b);
    printf("Coeficiente linear   a = %.4f\n", a);
    printf("\nEquacao da reta: y = %.4f + %.4f * x\n", a, b);

    /* -- Opcional: previsao de y para um x fornecido -- */
    printf("\n");
    exibir_separador();
    printf("Deseja prever um valor de y para um x informado? (s/n): ");
    scanf(" %c", &opcao);

    opcao = tolower(opcao);

    while (opcao == 's') {
        printf("  Informe o valor de x: ");
        scanf("%lf", &x_pred);

        y_pred = a + b * x_pred;
        printf("-> Para x = %.4f, o valor previsto de y e: %.4f\n",
               x_pred, y_pred);

        printf("\nDeseja prever outro valor? (s/n): ");
        scanf(" %c", &opcao);
    }

    /* -- Liberacao de memoria -- */
    free(x);
    free(y);

    printf("\n");
    exibir_separador();
    printf("Programa encerrado. Ate logo!\n");
    exibir_separador();

    return 0;
}


