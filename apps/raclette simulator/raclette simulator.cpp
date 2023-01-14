/*
▀██▀▀█▄                   ▀██            ▄     ▄
 ██   ██   ▄▄▄▄     ▄▄▄▄   ██    ▄▄▄▄  ▄██▄  ▄██▄    ▄▄▄▄
 ██▀▀█▀   ▀▀ ▄██  ▄█   ▀▀  ██  ▄█▄▄▄██  ██    ██   ▄█▄▄▄██
 ██   █▄  ▄█▀ ██  ██       ██  ██       ██    ██   ██
▄██▄  ▀█▀ ▀█▄▄▀█▀  ▀█▄▄▄▀ ▄██▄  ▀█▄▄▄▀  ▀█▄▀  ▀█▄▀  ▀█▄▄▄▀


 ▄█▀▀▀▄█   ██                      ▀██            ▄
 ██▄▄  ▀  ▄▄▄  ▄▄ ▄▄ ▄▄   ▄▄▄ ▄▄▄   ██   ▄▄▄▄   ▄██▄    ▄▄▄   ▄▄▄ ▄▄      ██   ███   ██   ██
  ▀▀███▄   ██   ██ ██ ██   ██  ██   ██  ▀▀ ▄██   ██   ▄█  ▀█▄  ██▀ ▀▀    █  █ ██ ██ █  █ ███
▄     ▀██  ██   ██ ██ ██   ██  ██   ██  ▄█▀ ██   ██   ██   ██  ██          ██ ██ ██   ██  ██
█▀▄▄▄▄█▀  ▄██▄ ▄██ ██ ██▄  ▀█▄▄▀█▄ ▄██▄ ▀█▄▄▀█▀  ▀█▄▀  ▀█▄▄█▀ ▄██▄        ██  ██ ██  ██   ██
                                                                         ██   ██ ██ ██    ██
                                                                         █▄▄▄  ▀█▀  █▄▄▄ ▀▀▀▀



▀██▀▀█▄             ▄
 ██   ██    ▄▄▄▄  ▄██▄   ▄▄▄▄       ██        ███
 ██▀▀▀█▄  ▄█▄▄▄██  ██   ▀▀ ▄██     ███       ██ ██
 ██    ██ ██       ██   ▄█▀ ██      ██       ██ ██
▄██▄▄▄█▀   ▀█▄▄▄▀  ▀█▄▀ ▀█▄▄▀█▀     ██       ██ ██
                                    ██   ██  ██ ██
                                   ▀▀▀▀       ▀█▀

*/



#include <string.h>
#include <Grapic.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>


using namespace grapic;
using namespace std;

const int W_X=1530;
const int W_Y=810;
const long long int valeur_max=999999999999999999; //long long int compris entre −9 223 372 036 854 775 807	 et 9 223 372 036 854 775 807


/*

 ▄█▀▀▀█▄█     ██                                              ██
▄██    ▀█     ██                                              ██
▀███▄       ██████    ▀███▄███    ▀███  ▀███      ▄██▀█▄    ██████    ▀███  ▀███     ▀███▄███      ▄██▀██▄
  ▀█████▄     ██        ██▀ ▀▀      ██    ██     ██▀  ▀█      ██        ██    ██       ██▀ ▀▀     ▄█▀   ██
▄     ▀██     ██        ██          ██    ██     ██           ██        ██    ██       ██         ██▀▀▀▀▀▀
██     ██     ██        ██          ██    ██     ██▄   ▄      ██        ██    ██       ██         ██▄    ▄
█▀█████▀      ▀████   ▄████▄        ▀████▀███▄    █████▀      ▀████     ▀████▀███▄   ▄████▄        ▀█████▀


*/


struct img
{
    Image appareil[3];
    Image tranche;

    Image fond_appareil;
    Image fond_nourriture;
    Image fond_recherche;

    Image assiette_patate;
    Image assiette_charcuterie;
    Image assiette_raclette;

    Image chouchen;
    Image sauvegarde;

    Image win;
};


struct plus_un
{
    long int compteur;
    int alea_x;
    int alea_y;
    int x;
    int y;
    char b[8];

};


struct appareil
{
    long long int nombre;
    long long int production;
    long long int prix;
    double temps_de_prod;
    double compteur;
    long long int prix_min;
};


struct nouriture
{
    long long int nombre;
    long long int effet;
    long long int prix;
};


struct table
{
    char menu;      //a=appareill   n=nouriture    r=recherche
    struct appareil T[3];
    struct nouriture N[3];
    long long int multiplicateur;
    double spam;
    struct plus_un plus_un;
};


/*
                                                                ▄▄
▀███▀▀▀███                                            ██        ██
  ██    ▀█                                            ██
  ██   █       ▄██▀██▄    ▀████████▄      ▄██▀█▄    ██████    ▀███       ▄██▀██▄    ▀████████▄
  ██▀▀██      ██▀   ▀██     ██    ██     ██▀  ▀█      ██        ██      ██▀   ▀██     ██    ██
  ██   █      ██     ██     ██    ██     ██           ██        ██      ██     ██     ██    ██
  ██          ██▄   ▄██     ██    ██     ██▄          ██        ██      ██▄   ▄██     ██    ██
▄████▄         ▀█████▀    ▄████  ████▄    █████▀      ▀████   ▄████▄     ▀█████▀    ▄████  ████▄


*/


void charger_img(struct img &img)
{
    img.appareil[0]=image("data/raclette_simulator/appareil_etudiant.png");
    img.appareil[1]=image("data/raclette_simulator/appareil_familial.png");
    img.appareil[2]=image("data/raclette_simulator/appareil_traditionel.png");


    img.tranche=image("data/raclette_simulator/tranche.png");
    img.sauvegarde=image("data/raclette_simulator/sauvegarde.png");

    img.fond_appareil=image("data/raclette_simulator/fond_appareil.png");
    img.fond_nourriture=image("data/raclette_simulator/fond_nourriture.png");
    img.fond_recherche=image("data/raclette_simulator/fond_recherche.png");

    img.assiette_patate=image("data/raclette_simulator/assiette_patate.png");
    img.assiette_charcuterie=image("data/raclette_simulator/assiette_charcuterie.png");
    img.assiette_raclette=image("data/raclette_simulator/assiette_raclette.png");

    img.chouchen=image("data/raclette_simulator/chouchen.png");

    img.win=image("data/raclette_simulator/win.png");
}


void format_long(long long int nb, char prix[7])
{
    long long int use;
    int longueur=19;
    int i,j;

    do
    {
        longueur--;
        use=nb/pow(10,longueur-1);
    }while (use==0 && longueur!=1);       // longueur entre 1 et 18

    char symbole_argent[10]=" KMBTQ";

    for (i=1;i<18;i+=3)
    {
        if(i<=longueur && longueur<=i+2)
        {
            for (j=0;j<3;j++)   //on met les 3 chiffres de la grandeur
            {
                use=pow(10,i+j-1);
                prix[2-j]='0'+(nb/use)%10;
            }

            prix[3]=symbole_argent[(i-1)/3]; //on met la lettre correspodant a l'odre de grandeur du prix
        }
    }

    prix[4]=' ';
    prix[5]=' ';
    prix[6]='\0';

}


void lire_sauv(struct table &table, long long int &argent)
{
    ifstream texte;
    texte.open("sauvegarde.txt");
    if (texte.fail())
    {
        cout << "pb d'ouverture" << endl;

        argent=0;
        for(int w=0;w<3;w++)
        {
            table.T[w].nombre=0;
            table.N[w].nombre=0;
        }
    }


    texte>>argent;

    texte>>table.T[0].nombre;
    texte>>table.T[1].nombre;
    texte>>table.T[2].nombre;

    texte>>table.N[0].nombre;
    texte>>table.N[1].nombre;
    texte>>table.N[2].nombre;

    texte.close();
}


void sauvegarder(struct table &table, long long int &argent)
{
    ofstream texte;
    texte.open("sauvegarde.txt");
    if (texte.fail())
    {
        cout << "pb d'ouverture" << endl;
    }


    texte<<argent<<endl;

    texte<<table.T[0].nombre<<endl;
    texte<<table.T[1].nombre<<endl;
    texte<<table.T[2].nombre<<endl;

    texte<<table.N[0].nombre<<endl;
    texte<<table.N[1].nombre<<endl;
    texte<<table.N[2].nombre<<endl<<endl;

    texte<<"ligne 1 : argent"<<endl<<endl<<"ligne 2 : nb appareil étudiant"<<endl<<"ligne 3 : nb appareil familial"<<endl;
    texte<<"ligne 4 : nb appareil traditionel"<<endl<<endl<<"ligne 5 : nb raclette"<<endl<<"ligne 6 : nb patate"<<endl;
    texte<<"ligne 7 : nb charcuterie";

    texte.close();
}


void renitialiser_sauvegarde()
{
    ofstream texte;
    texte.open("sauvegarde.txt");
    if (texte.fail())
    {
        cout << "pb d'ouverture" << endl;
    }

    texte<<0<<endl;

    texte<<0<<endl;
    texte<<0<<endl;
    texte<<0<<endl;

    texte<<0<<endl;
    texte<<0<<endl;
    texte<<0<<endl<<endl;

    texte<<"ligne 1 : argent"<<endl<<endl<<"ligne 2 : nb appareil étudiant"<<endl<<"ligne 3 : nb appareil familial"<<endl;
    texte<<"ligne 4 : nb appareil traditionel"<<endl<<endl<<"ligne 5 : nb raclette"<<endl<<"ligne 6 : nb patate"<<endl;
    texte<<"ligne 7 : nb charcuterie";

    texte.close();
}


void ini(struct table &table, long long int &argent)
{

    table.T[0].production=5;
    table.T[0].temps_de_prod=1750;
    table.T[0].compteur=0;
    table.T[0].prix_min=10;

    table.T[1].production=50;
    table.T[1].temps_de_prod=750;
    table.T[1].compteur=0;
    table.T[1].prix_min=10000;

    table.T[2].production=50000;
    table.T[2].temps_de_prod=2500;
    table.T[2].compteur=0;
    table.T[2].prix_min=10000000;

    table.N[0].effet=25;
    table.N[0].prix=7;

    table.N[1].effet=2;
    table.N[1].prix=7;

    table.N[2].effet=3;
    table.N[2].prix=7;

    table.multiplicateur=table.N[1].effet;

    strcpy(table.plus_un.b,"+1");

    table.menu='a';
    table.spam=0;
}


void click_plus_un(struct table &table)
{
    table.plus_un.compteur=50;
    table.plus_un.alea_x=(rand()%40) -20;
    table.plus_un.alea_y=(rand()%40) -20;
    mousePos(table.plus_un.x,table.plus_un.y);
    strcpy(table.plus_un.b,"+1");
}


void afficher_plus_un(struct table &table)
{
    if (table.plus_un.compteur>=0)
    {
        color(0,0,0);
        print(table.plus_un.x+table.plus_un.alea_x,table.plus_un.y+table.plus_un.alea_y,table.plus_un.b);
    }
}


void afficher_v2 (struct img &img, struct table &table, long long int argent)
{
    char a[7];
    int i,x,y;

    switch(table.menu)      //on affiche le fond en fonction du menue selectionné
    {
        case 'a' :
            image_draw(img.fond_appareil,0,0,W_X,W_Y);

            for (i=0;i<3;i++)
            {
                format_long(table.T[i].prix,a);
                a[4]='$';
                color(0,0,0);
                print(645,610-i*240, a);
            }
            break;

        case 'n' :
            image_draw(img.fond_nourriture,0,0,W_X,W_Y);

            for (i=0;i<3;i++)
            {
                format_long(table.N[i].prix,a);
                a[4]='$';
                color(0,0,0);
                print(645,610-i*240, a);
            }
            break;

        case 'r' :
            image_draw(img.fond_recherche,0,0,W_X,W_Y);
            break;

        default:
            break;
    }



    if (table.T[0].nombre>0)                     //on affiche les appareill si ils existent
    {
        image_draw(img.appareil[0],768,52,260,220);

        color(0,0,0);
        format_long(table.T[0].nombre,a);
        print(848,83, a);

        color(240,187,0);
        rectangleFill(795,73,815,73+(150*table.T[0].compteur)/(table.T[0].temps_de_prod-(table.N[0].effet*table.N[0].nombre+1)));
        color(140,87,0);
        rectangle(795,73,815,73+150);
    }
    if (table.T[1].nombre>0)
    {
        image_draw(img.appareil[1],1086,134,450,275);

        color(0,0,0);
        format_long(table.T[1].nombre,a);
        print(1432,174, a);

        color(240,187,0);
        rectangleFill(1503,174,1523,174+(150*table.T[1].compteur)/(table.T[1].temps_de_prod-(table.N[0].effet*table.N[0].nombre+1)));
        color(140,87,0);
        rectangle(1503,174,1523,174+150);

    }
    if (table.T[2].nombre>0)
    {
        image_draw(img.appareil[2],902,412,350,255);

        image_draw(img.chouchen,1250,504,70,186);

        color(0,0,0);
        format_long(table.T[2].nombre,a);
        print(945,452, a);

        color(240,187,0);
        rectangleFill(893,442,913,442+(150*table.T[2].compteur)/(table.T[2].temps_de_prod-(table.N[0].effet*table.N[0].nombre+1)));
        color(140,87,0);
        rectangle(893,442,913,442+150);
    }



    if (table.N[0].nombre>0)                     //on affiche les asiettes si elles existent
    {
        image_draw(img.assiette_raclette,1040,50,275,110);
    }

    if (table.N[1].nombre>0)
    {
        image_draw(img.assiette_patate,850,300,220,80);
    }

    if (table.N[2].nombre>0)
    {
        image_draw(img.assiette_charcuterie,1240,420,175,70);
    }

    format_long(argent,a);      //on affiche l'argent
    a[4]='$';
    color(0,0,0);
    print(1450,760, a);

    image_draw(img.sauvegarde,804,710,220,80);

}


void click_gauche(struct table &table,long long int &argent)
{
    int x,y;
    char a[7];
    char b[8]="+";

    if (isMousePressed(SDL_BUTTON_LEFT))
    {
        mousePos(x,y);

        if(804<=x && x<=1024 && 710<=y && y<=790)   //bouton sauvegarde
        {
            sauvegarder(table,argent);
        }

        else if(x>=760)                                //click pour gagner des $
        {
            argent+=table.N[2].effet*table.N[2].nombre+1;

            format_long(table.N[2].effet*table.N[2].nombre+1,a);
            strcat(b,a);
            strcat(b," $");

            click_plus_un(table);
            strcpy(table.plus_un.b,b);
        }
        else if(23<=x && x<=256 && 712<=y && y<=786)   //bouton appareil
        {
            table.menu='a';
        }
        else if(256<=x && x<=496 && 712<=y && y<=786)   //bouton nouriture
        {
            table.menu='n';
        }
        else if(496<=x && x<=736 && 712<=y && y<=786)   //bouton recherche
        {
            table.menu='r';
        }


        switch(table.menu)      //on teste les boutons en fonction du menue selectionné
        {
            case 'a' :
                if(584<=x && x<=746 && 534<=y && y<=691 && argent>=table.T[0].prix)   //bouton d'achat appareill étudiant
                {
                    argent-=table.T[0].prix;
                    table.T[0].nombre++;

                    click_plus_un(table);
                }
                else if(584<=x && x<=746 && 291<=y && y<=441 && argent>=table.T[1].prix)   //bouton d'achat appareill familial
                {
                    argent-=table.T[1].prix;
                    table.T[1].nombre++;

                    click_plus_un(table);
                }
                else if(584<=x && x<=746 && 62<=y && y<=212 && argent>=table.T[2].prix)   //bouton d'achat appareill traditionel
                {
                    argent-=table.T[2].prix;
                    table.T[2].nombre++;

                    click_plus_un(table);
                }
                break;

            case 'n' :
                int f;
                for (f=0;f<3;f++)
                {
                    table.N[f].prix=pow(7,table.N[f].nombre+1);
                }


                if(584<=x && x<=746 && 534<=y && y<=691 && argent>=table.N[0].prix)   //bouton d'achat raclette
                {
                    argent-=table.N[0].prix;
                    table.N[0].nombre++;
                    table.N[0].prix=pow(7,table.N[0].nombre+1);

                    click_plus_un(table);
                }
                else if(584<=x && x<=746 && 291<=y && y<=441 && argent>=table.N[1].prix)   //bouton d'achat patate
                {
                    argent-=table.N[1].prix;
                    table.N[1].nombre++;
                    table.N[1].prix=pow(7,table.N[1].nombre+1);

                    click_plus_un(table);
                }
                else if(584<=x && x<=746 && 62<=y && y<=212 && argent>=table.N[2].prix)   //bouton d'achat charcuterie
                {
                    argent-=table.N[2].prix;
                    table.N[2].nombre++;
                    table.N[2].prix=pow(7,table.N[2].nombre+1);

                    click_plus_un(table);
                }

                break;

            case 'r' :
                break;

            default:
                break;
        }
    }

    table.spam=0;
}


void click_droit(struct table &table,long long int &argent)
{
    int x,y,alea,aleay;
    long long int maxi;
    char a[7];
    char b[8]="+";

    if (isMousePressed(SDL_BUTTON_RIGHT))   //click droit = acheter max possible
    {
        mousePos(x,y);

        alea=(rand()%40) -20;
        aleay=(rand()%40) -20;
        color(0,0,0);

        switch(table.menu)      //on teste les boutons en fonction du menue selectionné
        {
            case 'a' :
                if(584<=x && x<=746 && 534<=y && y<=691 && argent>=table.T[0].prix)   //bouton d'achat appareill étudiant
                {
                    maxi=argent/table.T[0].prix;
                    argent-=table.T[0].prix*maxi;
                    table.T[0].nombre+=maxi;
                    format_long(maxi,a);
                    strcat(b,a);

                    click_plus_un(table);
                    strcpy(table.plus_un.b,b);
                    table.plus_un.compteur=50;
                }
                else if(584<=x && x<=746 && 291<=y && y<=441 && argent>=table.T[1].prix)   //bouton d'achat appareill familial
                {
                    maxi=argent/table.T[1].prix;
                    argent-=table.T[1].prix*maxi;
                    table.T[1].nombre+=maxi;
                    format_long(maxi,a);
                    strcat(b,a);

                    click_plus_un(table);
                    strcpy(table.plus_un.b,b);
                    table.plus_un.compteur=50;
                }
                else if(584<=x && x<=746 && 62<=y && y<=212 && argent>=table.T[2].prix)   //bouton d'achat appareill traditionel
                {
                    maxi=argent/table.T[2].prix;
                    argent-=table.T[2].prix*maxi;
                    table.T[2].nombre+=maxi;
                    format_long(maxi,a);
                    strcat(b,a);

                    click_plus_un(table);
                    strcpy(table.plus_un.b,b);
                    table.plus_un.compteur=50;
                }
                break;

            case 'n' :
                break;

            case 'r' :
                break;

            default:
                break;
        }
    }

    table.spam=0;
}


void jeu(struct table &table,long long int &argent)
{
    table.multiplicateur=table.N[1].effet*table.N[1].nombre+1;

    int i;


    for (i=0;i<3;i++)
    {
        if(table.T[i].nombre>0)
        {
            table.T[i].compteur++;                                      //on fait fondre la raclette
            if (table.T[i].compteur>=table.T[i].temps_de_prod-(table.N[0].effet*table.N[0].nombre+1))          //si elle est fondue on la vend et on en remet à cuire
            {
                table.T[i].compteur=0;
                argent+=table.T[i].production*table.T[i].nombre*table.multiplicateur;
            }
        }
        table.T[i].prix=table.T[i].prix_min+((table.T[i].prix_min/10)*table.T[i].nombre);
    }

    table.spam++;
    if (table.spam>30)
    {
        click_gauche(table,argent);
        click_droit(table,argent);
    }

    table.plus_un.compteur--;

    /*if(isKeyPressed('r'))
    {
        renitialiser_sauvegarde();
    }
    */
}


/*
                                 ▄▄
▀███▄      ▄███▀                 ██
  ███▄    ████
  █ ██   ▄█ ██      ▄█▀██▄     ▀███     ▀████████▄
  █  ██  █▀ ██     ██   ██       ██       ██    ██
  █  ██▄█▀  ██      ▄█████       ██       ██    ██
  █  ▀██▀   ██     ██   ██       ██       ██    ██
▄███▄ ▀▀  ▄████▄   ▀████▀██▄   ▄████▄   ▄████  ████▄


*/

int main(int , char**)
{
    bool stop=false;
	winInit("Raclette simulator 2021",W_X,W_Y);
	backgroundColor(0,0,0);

    struct img img;
    charger_img(img);

    long long int argent=0;
    struct table table;
    ini(table,argent);

    lire_sauv(table,argent);

    fontSize(30);

    while(!stop)
    {

        while(argent<valeur_max && !stop)
        {
            winClear();
            afficher_v2(img,table,argent);
            afficher_plus_un(table);

            jeu(table,argent);
            stop = winDisplay();
        }

        winClear();
        if (argent>=valeur_max)
        {
            image_draw(img.win,0,0,W_X,W_Y);
        }
        stop = winDisplay();
    }
    winQuit();


	return 0;
}
