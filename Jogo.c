#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

// funções benhur 
void tela_cor_letra(int r, int g, int b)
{
  printf("\e[38;2;%d;%d;%dm", r, g, b);
}
void tela_cor_fundo(int r, int g, int b)
{
  printf("\e[48;2;%d;%d;%dm", r, g, b);
}
void tela_cor_normal(void)
{
  printf("\e[m");
}
void tela_lincol(int lin, int col)
{
  printf("\e[%d;%dH", lin, col);
}
void limpa(void)
{
  printf("\e[2J");
}
//


// Desenha o quadrado da esquerda com os valores de rgb que devem ser acertados pelo jogador
void desenhaQ1(int r, int g, int b){
    tela_cor_fundo(r, g, b);
    for (int i=0; i<3000; i++) {
        int a = rand()%10+1;
        int b = rand()%20+1;
        tela_lincol(a, b);
        putchar(' ');
    }
}

// Desenha o quadrado da direita com os valores de rgb que o jogador inserir
void desenhaQ2(int r, int g, int b){
    tela_cor_fundo(r, g, b);
    for (int i=0; i<3000; i++) {
        int a = rand()%10+1;
        int b = rand()%20+1;
        tela_lincol(a, b+30);
        putchar(' ');
    }
}


//barra vermelha
void desenhaBarraVermelha(int vermelhoQ2,int au){
    int x = 60, y = 14;
    tela_lincol(y,x);
    for (int i=0; i<255/3; i++){
        tela_cor_fundo(i*3,0,0);
        printf(" ");
    }
    tela_lincol(y,((vermelhoQ2-1)/3)+x);
    tela_cor_fundo(255,255,255);
    printf(" ");
    if (au==1){
        tela_lincol(y,(x+(vermelhoQ2-1)/3)-1);
        tela_cor_fundo(vermelhoQ2,0,0);
        printf("<");
    }
    else if (au==-1){
        tela_lincol(y,(x+(vermelhoQ2-1)/3)+1);
        tela_cor_fundo(vermelhoQ2,0,0);
        printf(">");
    }
}

//barra verde
void desenhaBarraVerde(int verdeQ2,int au){
    int x = 60, y = 15;
    tela_lincol(y,x);
    for (int i=0; i<255/3; i++){
        tela_cor_fundo(0,i*3,0);
        printf(" ");
    }
    //marca em branco o lugar da barra referente à cor digitada 
    tela_lincol(y,((verdeQ2-1)/3)+x);
    tela_cor_fundo(255,255,255);
    printf(" "); 
    //
    if (au==1){
        tela_lincol(y,(x+(verdeQ2-1)/3)-1);
        tela_cor_fundo(0,verdeQ2,0);
        printf("<");
    }
    else if (au==-1){
        tela_lincol(y,(x+(verdeQ2-1)/3)+1);
        tela_cor_fundo(0,verdeQ2,0);
        printf(">");
    }
}

//barra azul
void desenhaBarraAzul(int azulQ2, int au){ 
    int x = 60, y = 16;
    tela_lincol(y,x);
    for (int i=0; i<255/3; i++){
        tela_cor_fundo(0,0,i*3);
        printf(" ");
    }
    tela_lincol(y, x + ((azulQ2-1)/3));
    tela_cor_fundo(255,255,255);
    printf(" ");
    if (au==1){
        tela_lincol(y, x + (((azulQ2-1)/3)-1));
        tela_cor_fundo(0,0,azulQ2);
        printf("<");
    }
    else if (au==-1){
        tela_lincol(y, x + (((azulQ2-1)/3)+1));
        tela_cor_fundo(0,0,azulQ2);
        printf(">");
    }
}

// verifica se o jogador deve aumentar ou diminuir o valor que foi jogado para chegar no valor da cor desejada
int aumentaOuNao(int Q1, int Q2){
    int aumenta;
    if (Q1>Q2){
        aumenta = 1;
    }
    else if(Q1<Q2){
        aumenta = -1;
    }
    else if(Q2==Q1){
        aumenta = 0;
    }
    return aumenta;
}

//pergunta se o jogo deve rodar de novo ou terminar e parar de rodar
bool jogarDeNovo(){
    char restela_lincolta;
    tela_cor_normal();
    tela_lincol(14,1);
    printf("\nDeseja jogar de novo?\n\nCaso deseje, digite 's', caso contrario, digite 'n': ");
    scanf(" %c", &restela_lincolta);
    if(restela_lincolta == 's') {
        return true;
    } else {
        return false;
    }    
}

// pega os valores RGB do usuário, chama as funções pra desenhar as barras de cada cor e altera os valores RGB do Q2 na main
void pegaCoresUsuario(int *r, int *g, int *b, int rQ1, int gQ1, int bQ1){
    int rDigitado, gDigitado, bDigitado,au;
    tela_lincol(14, 0);
    tela_cor_normal();
    printf("Digite um valor de 0 a 255 para vermelho: ");
    scanf("%d", &rDigitado);
    if (rDigitado<0){
        rDigitado = 0;
    }
    else if(rDigitado>255){
        rDigitado = 255;
    }
    *r = rDigitado;
    au = aumentaOuNao(rDigitado,rQ1);
    desenhaBarraVermelha(rDigitado, au);

    tela_lincol(15, 0);
    tela_cor_normal();
    printf("Digite um valor de 0 a 255 para verde: ");
    scanf("%d", &gDigitado);
    if (gDigitado<0){
        gDigitado = 0;
    }
    else if(gDigitado>255){
        gDigitado = 255;
    }
    *g = gDigitado;
    au = aumentaOuNao(gDigitado,gQ1);
    desenhaBarraVerde(gDigitado, au);

    tela_lincol(16, 0);
    tela_cor_normal();
    printf("Digite um valor de 0 a 255 para azul: ");
    scanf("%d", &bDigitado);
    if (bDigitado<0){
        bDigitado = 0;
    }
    else if(bDigitado>255){
        bDigitado = 255;
    }
    *b = bDigitado;
    au = aumentaOuNao(bDigitado,bQ1);
    desenhaBarraAzul(bDigitado, au);
}

// verifica se é o valor 0 ou o valor 255 que esta mais longe do valor de cor desejado, e retorna essa distancia
float calculaDistMax(int rgb){
    if (rgb<=128){
        return ((255-rgb));
    }
    else{
        return (rgb);
    }
}

// verifica a distancia do valores jogados e dos valores desejados, e calcula os pontos fazendo uma media entre as 3 distancias
int calculaPontos(int r1, int g1, int b1, int r2, int g2, int b2, float rM, int gM, int bM){
    float difR, difG, difB;
    int pontosTotal;
    if (r1>r2){
        difR = r1-r2;
    } else {
        difR = r2-r1;
    }
    if (g1>g2){
        difG = g1-g2;
    } else {
        difG = g2-g1;
    }
    if (b1>b2){
        difB = b1-b2;
    } else {
        difB = b2-b1;
    }
    int pontoR = 100 - (difR/rM)*100;
    int pontoG = 100 - (difG/gM)*100;
    int pontoB = 100 - (difB/bM)*100;
    pontosTotal = (pontoR+pontoG+pontoB)/3;
    return pontosTotal;
}

// é um getchar com outro nome, pra facilitar o entendimento de seu uso na main
void esperaEnter(){
    getchar();
}

//modifica a posição dos pontos e de seus respectivos nomes no ranking
void ranqueiaPontos(int rank[4], char rNomes[4][5]){
    int aux;
    char auxC[5] = {'-','-','-','-','-'};
    for (int i=3;i>0;i--){
        if (rank[i]>rank[i-1]){
            aux = rank[i-1];
            rank[i-1]=rank[i];
            rank[i]=aux;
            for (int j=0; j<5;j++){    
                auxC[j] = rNomes[i-1][j];
                rNomes[i-1][j] = rNomes[i][j];
                rNomes[i][j] = auxC[j];
            } 
        }
        else {
            break;
        }
    }    
}

//imprime na tela o ranking
void imprimeRanking(int rank[], char rankNomes[4][5]){
    tela_cor_letra(244,196,48);
    tela_lincol(6,52);
    printf("-RANK-");
    tela_lincol(6,62);
    printf("-SCORE-");
    tela_lincol(6,75);
    printf("-NOME-");
    for (int i=0;i<3;i++){
        tela_lincol(8+i*2,54);
        printf("%d%c:    %d pontos",i+1,167,rank[i]);
    }
    tela_lincol(6,75);
    for (int i=0; i<3; i++){
        tela_lincol(8+i*2,76);
        for(int j=0;j<5;j++){
            printf("%c",rankNomes[i][j]);
        }
    }
    tela_lincol(20,1);
}

//pede o nome do jogador e coloca ele na tela_lincolição [3][] do vetor nomes da main
void pegaNome(char rNomes[4][5]){
    tela_lincol(20,0);
    tela_cor_normal();
    printf("Voce entrou no ranking, qual seu nome? (ate 5 caracteres)\n");
    scanf("%5s",rNomes[3]);
}



int main(){
    srand(time(0));
    const int rodadas = 5; //numero de rodadas do jogo
    int ranking[4]={0,0,0,0}; // vetor que guarda as 3 primeiras tela_lincolições de pontos nas tela_lincolições 0,1 e 2 respectivamente.
    char nomes[4][5];
    for (int i=0;i<4;i++){ //for que coloca '-' no lugar dos nomes para exibir ----- quando não tiver ninguem na tela_lincolição do rank
        for(int j=0;j<5;j++){
            nomes[i][j] = '-';
        }
    }
    int pontos;
    int redQ1, greenQ1, blueQ1, redQ2, greenQ2, blueQ2;
    limpa(); //
    do{ //"do while" que roda o jogo
        redQ1 = rand()%255, greenQ1 = rand()%255, blueQ1 = rand()%255; //gera o rgb do quadrado a ser acertado
        float dMaxRed, dMaxGreen, dMaxBlue;
        dMaxRed = calculaDistMax(redQ1); 
        dMaxGreen = calculaDistMax(greenQ1);
        dMaxBlue = calculaDistMax(blueQ1);
        for(int i=0;i<rodadas;i++){ //"for" que roda cada rodada
            tela_lincol(17,0); 
            if (i>0){ //espera o jogador clicar enter para pular para a próxima rodada, com excessão do início do jogo
                esperaEnter(); 
                esperaEnter();
            }
            tela_cor_normal();
            limpa();
            desenhaQ1(redQ1,greenQ1,blueQ1); //desenha o quadrado com a cor que deve ser adivinhada na tela
            if (i>0){ //mostra na tela a jogada anterior do jogador, logicamente a partir da segunda rodada
                tela_cor_fundo(redQ2, greenQ2, blueQ2);
                tela_lincol(3,60);
                printf("Jogada anterior: R=%d, G=%d, B=%d ",redQ2,greenQ2,blueQ2);
            }
            tela_lincol(0,60);
            tela_cor_normal();
            printf(" Rodada %d ",i+1); //escreve na tela a rodada em que o jogador está
            pegaCoresUsuario(&redQ2, &greenQ2, &blueQ2,redQ1,greenQ1,blueQ1); 
            desenhaQ2(redQ2, greenQ2, blueQ2); //desenha na tela o quadrado com as cores escolhidas pelo jogador
            tela_lincol(12,60);
            printf(" Cores da tentativa %d: R=%d, G=%d, B=%d ",i+1,redQ2,greenQ2,blueQ2); // exibe na tela a cor e os valores jogados pelo jogador
            pontos = calculaPontos(redQ1,greenQ1,blueQ1,redQ2,greenQ2,blueQ2,dMaxRed,dMaxGreen,dMaxBlue);
            tela_lincol(10,60);
            printf(" Pontos da tentativa: %d",pontos);
            if (pontos==100){ //se o jogador acertar a cor, para de rodar o "for"
                break;
            }            
        }
        //esperaEnter();
        ranking[3] = pontos;
        if (pontos > ranking[2]){
            pegaNome(nomes);
            ranqueiaPontos(ranking,nomes);            
        }
        tela_cor_normal();
        tela_lincol(19, 0);
        esperaEnter();
        limpa();
        imprimeRanking(ranking,nomes);
        tela_lincol(0,0);
        if (redQ1==redQ2 && greenQ1==greenQ2 && blueQ1==blueQ2){
            tela_lincol(7,12);
            tela_cor_letra(20,160,20);
            printf("Parabens!");
            tela_lincol(9,10);
            printf("Voce acertou!");
            tela_lincol (11,11);
            printf("Pontos: %d",pontos);
        }
        else {
            tela_cor_letra(200,30,20);
            printf("\nGame Over! Boa sorte na proxima vez!\n");
            printf("\nPontos conquistados na rodada final: %d\n\n",pontos);
            tela_cor_letra(40,170,20);
            printf("O valores de RGB corretos eram:\n");
            tela_cor_letra(255,0,0);
            printf("\nVermelho: %d",redQ1);
            tela_cor_letra(0,255,0);
            printf("\nVerde: %d",greenQ1);
            tela_cor_letra(0,0,255);
            printf("\nAzul: %d\n\n",blueQ1);
            tela_cor_normal();
            tela_cor_fundo(redQ2, greenQ2, blueQ2);
            tela_lincol(12,0);
            printf("Valores da ultima tentativa: R=%d, G=%d, B=%d ",redQ2,greenQ2,blueQ2);
        }        
    } while(jogarDeNovo());

    //tela_cor_normal();
    tela_lincol(10, 10);
    esperaEnter();
    limpa();
    tela_cor_letra(200,30,200);
    printf("Obrigado por jogar!\n\n");
    imprimeRanking(ranking,nomes);
    tela_cor_normal();
}
