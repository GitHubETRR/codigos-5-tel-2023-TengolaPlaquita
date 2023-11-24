    #include <stdio.h>

    //ingredientes
    int Pionono = 2, DDL = 1, Nueces = 3, Merengues = 12, Crema = 4, Azucar = 6, AzucarImpa = 5, pionono1 = 0, pionono2 = 0;
    //herramientas
    int Bandeja=10, Bowl=20, Moldes=8, Tamiz=9;
    //LA TORTA
    int Torta;

    void cortar_pionono_nico();
    void DDL_fino_viani();
    void DDL_grueso_vasile();
    void capa_intermedia_igna();
    void batir_mica(); //hacer mientras batir mica no sea 30, osea la crema este en su mejor punto
    void poner_crema_marco();
    void poner_tapa_fran();
    void poner_moldes_nico();
    void poner_AzucarImpa_viani();
    void sacar_moldes_nico();

    int main(){
        cortar_pionono_nico();
        DDL_fino_viani();
        DDL_grueso_vasile();
        capa_intermedia_igna();
        for(int i=0;i<5;i++){
            batir_mica(4.5,1.5);
            if (i==0){
                poner_crema_marco();
            }else if (i==1){
                poner_tapa_fran();
            }else if (i==2){
                poner_moldes_nico();
            }else if (i==3){
                poner_AzucarImpa_viani();
            }else if (i==4){
                sacar_moldes_nico();
            }
        }
        return 0;
    }

    void batir_mica(int cant_crema, int cant_azucar){ //mica bate la crema hasta que este hecha
        Bowl+=cant_crema;
        Bowl+=cant_azucar; //da 30 que seria el punto donde la crema este perfecta
    }

    void cortar_pionono_nico(){ //nico corta el pionono hasta que sean dos mitades
        pionono1=Pionono/2;
        pionono2=Pionono-pionono1;
    }

    void DDL_fino_viani(){ //viani le pone dulce de leche finito a una de las partes
        pionono2=pionono2+DDL;
    }

    void DDL_grueso_vasile(){ //vasile le pone el DDL restante a la otra mitad
        Bandeja=Bandeja+pionono1;
        Bandeja=Bandeja+DDL;
    }

    void capa_intermedia_igna(){ //igna parte merengues a la mitad multiplicandolos y lo agrega junto a las nueces al pionono con mas DDL
        Merengues=Merengues*2;
        pionono2=pionono2+Nueces+Merengues;
    }

    void poner_crema_marco(){ //marco agarra la crema que preparo mica y la añade en la mitad que tiene los merengues
        pionono2=pionono2+Bowl;
    }

    void poner_tapa_fran(){ //fran pone el pionono con solo una capa en el otro formando la torta
        Torta=pionono2+pionono1;
    }

    void poner_moldes_nico(){ //nico suma los moldes que dicen TEL en la parte superior de la torta
        Torta=Torta+Moldes;
    }

    void poner_AzucarImpa_viani(){ //viani espolvorea con el tamiz azucar impalpable sobre la torta 
        Tamiz=Tamiz+AzucarImpa;
        Torta=Torta+Tamiz;
    }

    void sacar_moldes_nico(){ //nico saca los moldes de arriba de la torta 
        Torta=Torta-Moldes;
    }

