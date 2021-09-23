#include "functions.h"



int main(int argc, char ** argv){


  int i;
  information info;
  main_network * main_ntw;
  image * pic;
  image * c;
  image * formatted;

  main_ntw = malloc(sizeof(main_network));
  pic = malloc(sizeof(*pic));
  c = malloc(sizeof(*c));
  formatted = malloc(sizeof(*formatted));

  printf("Lancement du programme\n\n");

  int t[]={784,1};
  info.vect=t;
  info.n=sizeof(t)/sizeof(*t);


  build_main_network(main_ntw,10,info,24);

  printf("Chargement des bases de données training...\n");
  load_bdd(&(main_ntw->char_training[0]),"./DATA/0.txt");
  load_bdd(&(main_ntw->char_training[1]),"./DATA/1.txt");
  load_bdd(&(main_ntw->char_training[2]),"./DATA/2.txt");
  load_bdd(&(main_ntw->char_training[3]),"./DATA/3.txt");
  load_bdd(&(main_ntw->char_training[4]),"./DATA/4.txt");
  load_bdd(&(main_ntw->char_training[5]),"./DATA/5.txt");
  load_bdd(&(main_ntw->char_training[6]),"./DATA/6.txt");
  load_bdd(&(main_ntw->char_training[7]),"./DATA/7.txt");
  load_bdd(&(main_ntw->char_training[8]),"./DATA/8.txt");
  load_bdd(&(main_ntw->char_training[9]),"./DATA/9.txt");
  printf("Done\n\n");
 
  for(i=0;i<10;i++){
    printf("Training du caractere \"%d\" en cours...\n",i);
    main_ntw->ntw[i].class=i;
    training(main_ntw, i);
    printf("Done\n");
  }

  
  /*
  main_ntw->test = malloc(sizeof(bdd));
  main_ntw->test->n=0;
  load_bdd(main_ntw->test,"numbers_test.txt");
  //printf("N = %d\n",main_ntw->test->n);
  main_ntw->test->n=3000;

  prediction(main_ntw);
  */


  main_ntw->test = malloc(sizeof(bdd));
  main_ntw->test->n = 0;
  main_ntw->test->im = malloc(32 * sizeof(data_image));
  //le 32 est temporaire, il doit etre le nombre de caractere qu on doit predire
  for(i=0;i<32;i++){
    main_ntw->test->im[i].pix = malloc(784 * sizeof(float));
    main_ntw->test->im[i].n = 784;
  }


   /*
  main_ntw->test = malloc(sizeof(bdd));
  main_ntw->test->n=0;
  load_bdd(main_ntw->test,"numbers_test.txt");
  //printf("N = %d\n",main_ntw->test->n);
  main_ntw->test->n=3000;

  prediction(main_ntw);
  */

  if(argc<2){

    //Lot a predire par defaut. Vous pouvez tester un
    //autre lot en remplacant "LOT_CHIFFRES_1" par
    //"LOT_CHIFFRES_2" ci dessous.

  pic=lireExtraire(pic,"./LOT_CHIFFRES_1/0.ppm");
  c=loadChar(pic,c,delimit(pic));
  formatted=resize(c,formatted);
  conversion(main_ntw,formatted);

  pic=lireExtraire(pic,"./LOT_CHIFFRES_1/1.ppm");
  c=loadChar(pic,c,delimit(pic));
  formatted=resize(c,formatted);
  conversion(main_ntw,formatted);

  pic=lireExtraire(pic,"./LOT_CHIFFRES_1/2.ppm");
  c=loadChar(pic,c,delimit(pic));
  formatted=resize(c,formatted);
  conversion(main_ntw,formatted);
  
  pic=lireExtraire(pic,"./LOT_CHIFFRES_1/3.ppm");
  c=loadChar(pic,c,delimit(pic));
  formatted=resize(c,formatted);
  conversion(main_ntw,formatted);

  pic=lireExtraire(pic,"./LOT_CHIFFRES_1/4.ppm");
  c=loadChar(pic,c,delimit(pic));
  formatted=resize(c,formatted);
  conversion(main_ntw,formatted);

  pic=lireExtraire(pic,"./LOT_CHIFFRES_1/5.ppm");
  c=loadChar(pic,c,delimit(pic));
  formatted=resize(c,formatted);
  conversion(main_ntw,formatted);

  pic=lireExtraire(pic,"./LOT_CHIFFRES_1/6.ppm");
  c=loadChar(pic,c,delimit(pic));
  formatted=resize(c,formatted);
  conversion(main_ntw,formatted);
  
  pic=lireExtraire(pic,"./LOT_CHIFFRES_1/7.ppm");
  c=loadChar(pic,c,delimit(pic));
  formatted=resize(c,formatted);
  conversion(main_ntw,formatted);
  
  pic=lireExtraire(pic,"./LOT_CHIFFRES_1/8.ppm");
  c=loadChar(pic,c,delimit(pic));
  formatted=resize(c,formatted);
  conversion(main_ntw,formatted);
  
  pic=lireExtraire(pic,"./LOT_CHIFFRES_1/9.ppm");
  c=loadChar(pic,c,delimit(pic));
  formatted=resize(c,formatted);
  conversion(main_ntw,formatted);

  //Pour avoir un image 28*28 correspondant a une image ci dessus:
  //dupliquer(formatted,"ex9.ppm");

  }

  else{
    for(i=1 ; i<argc ; i++){
      pic=lireExtraire(pic,argv[i]);
      c=loadChar(pic,c,delimit(pic));
      formatted=resize(c,formatted);
      conversion(main_ntw,formatted);
    }
  }
  

  

  printf("\n\nPREDICTION :\n\n");

  prediction(main_ntw);

  
}
