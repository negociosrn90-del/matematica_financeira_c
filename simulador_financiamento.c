#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <math.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    double vl_total, vl_entrada, tx_juros, tx_juros_x, vl_finan, valor_de_parcela_fixa,total_pago, total_juros, vl_tot_com_juros_entrada;
    int prazo;

    printf ("\n-------------------------------------------");
    printf ("\nBem vindo ao seu simulador de financiamentos!");
    printf ("\n-------------------------------------------");
    
    while (1) {
        printf ("\nDigite o valor do bem a ser financiado: ");
        scanf ("%lf", &vl_total);
        if (vl_total <= 0)
        printf ("Digite um valor válido.");
        else
            break;
    }
    while (1) {
        printf ("\nDigite o valor referente a entrada: ");
        scanf ("%lf", &vl_entrada);
        if (vl_entrada > vl_total)
        printf ("O valor da entrada não pode ser maior que o valor total.");
        else
            break;
    }
    while (1) {
        printf ("\nDigite qual a taxa de juros ao mês a ser calculada: ");
        scanf ("%lf", &tx_juros);
        if (tx_juros < 0)
        printf ("Digite uma taxa de juros válida.");
        else
            break;
    }
    while (1) {
        printf ("\nQual o prazo pretendido? ");
        scanf ("%d", &prazo);
        if (prazo <= 0)
        printf ("Digite um prazo válido");
        else
            break;
    }
    vl_finan = vl_total - vl_entrada;
    tx_juros_x = tx_juros / 100;

    valor_de_parcela_fixa = vl_finan * tx_juros_x * (pow(1 + tx_juros_x, prazo)) / (pow(1 + tx_juros_x, prazo) - 1);
    total_pago = valor_de_parcela_fixa * prazo;
    total_juros = total_pago - vl_finan;
    vl_tot_com_juros_entrada = total_pago + vl_entrada;

    printf ("\n\nO valor do bem a vista é de %.2lf.", vl_total);
    printf ("\nO valor da sua entrada foi de %.2lf.", vl_entrada);
    printf ("\nA taxa ao mes a ser calculada é de %.2lf%%.", tx_juros);
    printf ("\nPrazo em %d meses.", prazo);

    printf ("\n\nO valor do bem final com juros e entrada é de %.2lf.", vl_tot_com_juros_entrada);
    printf ("\nA sua parcela ficou no valor de %.2lf em %d meses.", valor_de_parcela_fixa, prazo);
    printf ("\nTotal de juros a ser pago: %.2lf", total_juros);

    printf ("\n\n-------------------------------------------");
    printf ("\nAcesso finalizado!");
    printf ("\n-------------------------------------------");

    return 0;
}
