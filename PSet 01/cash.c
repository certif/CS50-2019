#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)

{

    float fmoney;

    do
    {
        fmoney = get_float("Vvedit reshty groshei dlia zdachi:\n");
    } 
    while(fmoney < 0);

    int ncoins = 0;

    int imoney = round(fmoney*100);

    ncoins = imoney/25;

    imoney = imoney%25;

    ncoins = ncoins + imoney/10;

    imoney = imoney%10;

    ncoins = ncoins + imoney/5;

    ncoins = ncoins + imoney%5;

    printf("Kilkist monet rivna %i\n", ncoins);

}
