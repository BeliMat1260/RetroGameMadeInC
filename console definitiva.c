#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int posnave(int n);
int tris();
int battnavale();
int forza4();
int forza4bot();
int trisbot();
int battnavalebot();

char M1[11][11],M2[11][11],B1[11][11],B2[11][11];
int i,j;

int main()
{	
	
	FILE *out;
	int punteggio1=0,punteggio2=0,s,p,pu=0,a,z,y,k=0,np=0,n;
	char h[50],x[2];
	
					
	out=fopen("punteggio.txt","w");
	
  do{	
		do{fflush(stdin);
	system("cls");
	printf("MENU\n");
	printf("Selezionare il gioco:\n");
	printf("0 ->Chiudi programma\n");
	printf("1 ->Tris\n");
	printf("2 ->Battaglia Navale\n");
	printf("3 ->Forza 4\n");
	printf("4 ->Punteggio\n");
	scanf("%d",&s);
	}
	while(s>4 || s<0 );

	if(s==1)
	{system("cls");
	n=0;
		printf("Hai selezionato TRIS\n");
		while(n>2 || n<1)
		{
		printf("1 ->Player vs Player\n");
		printf("2 ->Player vs bot\n");
		scanf("%d",&n);
		system("cls");
		}
		if(n==1)
		p=tris();
		if(n==2)
		p=trisbot();
		sleep(5);
		np++;
		if(p==0)
		{
			punteggio1++;
			pu=1;
		}
		if(p==1)
		{
			punteggio2++;
			pu=2;
		}
		
		if(pu==1)
		fprintf(out,"Tris 1-0\n");
		if(pu==2)
		fprintf(out,"Tris 0-1\n");
		if(pu!=1 && pu!=2)
		fprintf(out,"Tris 0-0\n");
		pu=0;
	}
	if(s==2)
	{system("cls");
	n=0;
		printf("Hai selezionato BATTAGLIA NAVALE\n");
		while(n>2 || n<1)
		{
		printf("1 ->Player vs Player\n");
		printf("2 ->Player vs bot\n");
		scanf("%d",&n);
		system("cls");
		}
		if(n==1)
		p=battnavale();
		if(n==2)
		p=battnavalebot();
		sleep(5);
		np++;
		if(p==0)
		{
			punteggio1++;
			pu=1;
		}
		if(p==1)
		{
			punteggio2++;
			pu=2;
		}
		
		if(pu==1)
		fprintf(out,"Battaglianavale 1-0\n");
		if(pu==2)
		fprintf(out,"Battaglianavale 0-1\n");
		if(pu!=1 && pu!=2)
		fprintf(out,"Battaglianavale 0-0\n");
		pu=0;
	}
	if(s==3)
	{system("cls");
	n=0;
		printf("Hai selezionato FORZA 4\n");
		while(n>2 || n<1)
		{
		printf("1 ->Player vs Player\n");
		printf("2 ->Player vs bot\n");
		scanf("%d",&n);
		system("cls");
		}
		if(n==1)
		p=forza4();
		if(n==2)
		p=forza4bot();
		sleep(5);
		np++;
		if(p==0)
		{
			punteggio1++;
			pu=1;
		}
		if(p==1)
		{
			punteggio2++;
			pu=2;
		}
		
		if(pu==1)
		fprintf(out,"Forza4 1-0\n");
		if(pu==2)
		fprintf(out,"Forza4 0-1\n");
		if(pu!=1 && pu!=2)
		fprintf(out,"Forza4 0-0\n");
		pu=0;
		fclose(out);
	}
	if(s==4)
	{system("cls");
		do{
			system("cls");
		printf("Hai selezionato PUNTEGGIO\n");
		printf("Vittorie giocatore 1: %d\n",punteggio1);
		printf("Vittorie giocatore 2: %d\n",punteggio2);
		printf("1 ->PUNTEGGIO Tris\n");
		printf("2 ->PUNTEGGIO Battaglia Navale\n");
		printf("3 ->PUNTEGGIO Forza 4\n");
		printf("4 ->MENU\n");
		scanf("%d",&p);
		
		}while(p>=4 || p<1 );
		fclose(out);
		out=fopen("punteggio.txt","w+");
		if(p==1)
		{k=0;
			
			do{	k++;
					a=fgetc(out);
				if(a=='T')
				{	
					
					fscanf(out,"%s %d%c%d ",&h,&z,&x[0],&y);
					printf("%d partita:Tris %d-%d\n",np,z,y);
					sleep(5);
				}
			}while(!feof(out));
		}
		if(p==2)
		{	k=0;
			
			do{	k++;
					a=fgetc(out);
				if(a=='T')
				{	
					
					fscanf(out,"%s %d%c%d ",&h,&z,&x[0],&y);
					printf("%d partita:Battaglia navale %d-%d\n",np,z,y);
					sleep(5);
				}
			}while(!feof(out));
		}
		if(p==3)
		{	k=0;
		
			do{	k++;
					a=fgetc(out);
				if(a=='F')
				{	
					
					fscanf(out,"%s %d%c%d ",&h,&z,&x[0],&y);
					printf("%d partita:Forza4 %d-%d\n",np,z,y);
					sleep(5);
				}
			}while(!feof(out));
		}
		if(p==4)
		{	
			system("cls");
		}
		fclose(out);
	}
	}while(s!=0);

	fclose(out);
	
}

int tris()
{	
	system("cls");
	char M [3][3];
	int i,j,k,h;
	int a,p,flag=0;
	srand(time(0));
	a=rand()%2;
	if(a==0)
	{
		printf("\nInizia player 1\n");
		
		
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				M[i][j]=32;
			}
		}
		
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				printf("|%c|",M[i][j]);
			}
			printf("\n");
		}
		int flag=0;
		for(p=0;p<9;p++)
		{
			if(p%2==0)
			{
				do{fflush(stdin);
				printf("Inserisci le coordinate in cui mettere la X");
				scanf("%d",&k);
				scanf("%d",&h);
				if(k<=3 && k>=1)
				flag=1;
				if(h<=3 && h>=1)
				flag=1;
				if(M[k-1][h-1]!=32)
				flag=0;
				}
				while(flag==0);
				M[k-1][h-1]=88;
				
				system("cls");
				
				for(i=0;i<3;i++)
				{
				for(j=0;j<3;j++)
					{
						printf("|%c|",M[i][j]);
					}
				printf("\n");
				}
			}
		
				
		    if ( ((M[0][0]==88) && (M[0][1]==88) && (M[0][2]==88)) || ((M[1][0]==88) && (M[1][1]==88) && (M[1][2]==88)) || ((M[2][0]==88) && (M[2][1]==88) && (M[2][2]==88)) || ((M[0][0]==88) && (M[1][1]==88) && (M[2][2]==88)) || ((M[2][0]==88) && (M[1][1]==88) && (M[0][2]==88)) || ((M[0][0]==88) && (M[1][0]==88) && (M[2][0]==88)) || ((M[0][1]==88) && (M[1][1]==88) && (M[2][1]==88)) || ((M[0][2]==88) && (M[1][2]==88) && (M[2][2]==88))  )
			{
						printf ("Player 1 vince\n\n\n\n\n");
							return 0;			
					}
				
					
			
				if(p%2==1)
				{
				do{fflush(stdin);
				printf("Inserisci le coordinate in cui mettere la O");
				scanf("%d",&k);
				scanf("%d",&h);
				if(k<=3 && k>=1)
				flag=1;
				if(h<=3 && h>=1)
				flag=1;
				if(M[k-1][h-1]!=32)
				flag=0;
				}
				while(flag==0);
				M[k-1][h-1]=79;
				
				system("cls");
				for(i=0;i<3;i++)
				{
					for(j=0;j<3;j++)
					{
						printf("|%c|",M[i][j]);
					}
					printf("\n");
				}
				
				if ( ((M[0][0]==79) && (M[0][1]==79) && (M[0][2]==79)) || ((M[1][0]==79) && (M[1][1]==79) && (M[1][2]==79)) || ((M[2][0]==79) && (M[2][1]==79) && (M[2][2]==79)) || ((M[0][0]==79) && (M[1][1]==79) && (M[2][2]==79)) || ((M[2][0]==79) && (M[1][1]==79) && (M[0][2]==79)) || (M[0][0]==79) && (M[2][0]==79) && (M[1][0]==79) || ((M[0][1]==79) && (M[1][1]==79) && (M[2][1]==79)) || ((M[0][2]==79) && (M[1][2]==79) && (M[2][2]==79)) )	
				{
					printf("Player 2 vince\n\n\n\n\n");
					return 1;	
				}	
				
				
				}
				
			
		}
		printf("Pareggio");
		return 104;
		
	}else{
		char M [3][3];
		int i,j,k,h;
		
		printf("\nInizia player 2\n");

		
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				M[i][j]=32;
			}
		}
		
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				printf("|%c|",M[i][j]);
			}
			printf("\n");
		}
		
		for(p=0;p<9;p++)
		{
			
				if(p%2==0)
				{	
					do{fflush(stdin);
					printf("Inserisci le coordinate in cui mettere la X");
					scanf("%d",&k);
					scanf("%d",&h);
					if(k<=3 && k>=1)
					flag=1;
					if(h<=3 && h>=1)
					flag=1;
					if(M[k-1][h-1]!=32)
					flag=0;
					}while(flag==0);
					
					M[k-1][h-1]=88;
					system("cls");
					for(i=0;i<3;i++)
					{
					for(j=0;j<3;j++)
						{
							printf("|%c|",M[i][j]);
						}
					printf("\n");
					}
			
			}
		    if ( ((M[0][0]==88) && (M[0][1]==88) && (M[0][2]==88)) || ((M[1][0]==88) && (M[1][1]==88) && (M[1][2]==88)) || ((M[2][0]==88) && (M[2][1]==88) && (M[2][2]==88)) || ((M[0][0]==88) && (M[1][1]==88) && (M[2][2]==88)) || ((M[2][0]==88) && (M[1][1]==88) && (M[0][2]==88)) || ((M[0][0]==88) && (M[1][0]==88) && (M[2][0]==88)) || ((M[0][1]==88) && (M[1][1]==88) && (M[2][1]==88)) || ((M[0][2]==88) && (M[1][2]==88) && (M[2][2]==88))  )
			{
						printf ("Player 2 vince\n\n\n\n\n");
							return 1;			
					}
				
			
				
					
			
				if(p%2==1)
				{  
					do{fflush(stdin);
				printf("Inserisci le coordinate in cui mettere la O");
				scanf("%d",&k);
				scanf("%d",&h);
				if(k<=3 && k>=1)
				flag=1;
				if(h<=3 && h>=1)
				flag=1;
				if(M[k-1][h-1]!=32)
				flag=0;
				}
				while(flag==0);
				M[k-1][h-1]=79;
				system("cls");
				for(i=0;i<3;i++)
				{
					for(j=0;j<3;j++)
					{
						printf("|%c|",M[i][j]);
					}
					printf("\n");
				}
				
				if ( ((M[0][0]==79) && (M[0][1]==79) && (M[0][2]==79)) || ((M[1][0]==79) && (M[1][1]==79) && (M[1][2]==79)) || ((M[2][0]==79) && (M[2][1]==79) && (M[2][2]==79)) || ((M[0][0]==79) && (M[1][1]==79) && (M[2][2]==79)) || ((M[2][0]==79) && (M[1][1]==79) && (M[0][2]==79)) || (M[0][0]==79) && (M[2][0]==79) && (M[1][0]==79) || ((M[0][1]==79) && (M[1][1]==79) && (M[2][1]==79)) || ((M[0][2]==79) && (M[1][2]==79) && (M[2][2]==79)) )	
				{
					printf("Player 1 vince\n\n\n\n\n");
					return 0;	
				}	
				
				
				}
				
			
		}
		printf("Pareggio");
		return 10;
		
	}
}

int battnavale()
{system("cls");
	char M1[11][11],M2[11][11],B1[11][11],B2[11][11];
	
	int i,j,s,h,p,flag,Flag1;
	char k;
	
				for(i=0;i<11;i++)
				{
					for(j=0;j<11;j++)
					{
						M1[i][j]=32;
					}
					
				}
				
				for(i=0;i<11;i++)
				{
					for(j=0;j<11;j++)
					{
						M2[i][j]=32;
					}
					
				}
			
				for(i=0;i<11;i++)
				{
					for(j=0;j<11;j++)
					{
						B2[i][j]=32;
					}
					
				}
				
				for(i=0;i<11;i++)
				{
					for(j=0;j<11;j++)
					{
						B1[i][j]=32;
					}
					
				}
	
	for(i=1;i<11;i++)
	{
		M2[0][i]=64+i;
	}
	
	for(i=1;i<10;i++)
	{
		M2[i][0]=48+i;
	}
	M2[10][0]='0';
	
	for(i=1;i<11;i++)
	{
		M1[0][i]=64+i;
	}
	
	for(i=1;i<10;i++)
	{
		M1[i][0]=48+i;
	}
	M1[10][0]='0';
	
	for(i=1;i<11;i++)
	{
		B1[0][i]=64+i;
	}
	
	for(i=1;i<10;i++)
	{
		B1[i][0]=48+i;
	}
	B1[10][0]='0';
	
	for(i=1;i<11;i++)
	{
		B2[0][i]=64+i;
	}
	
	for(i=1;i<10;i++)
	{
		B2[i][0]=48+i;
	}
	B2[10][0]='0';

	
	
	
	
	for(p=0;p<2;p++)
	{	
		if(p==0)
		{int po,h1,k1;
										printf("Inizia player 1\n");
										
										for(i=0;i<11;i++)
											{
												for(j=0;j<11;j++)
												{
													printf("|%c|",B1[i][j]);
												}
												printf("\n");
											}
									
									
										printf("Nave da posizionare:sottomarino\n");
										do{fflush(stdin);
										printf("Inserisci la posizione in cui vuoi inserire la nave:");
										scanf("%c",&k);
										scanf("%d",&h);
										if(k>=65 && k<=74)
										Flag1=1;
										if(h>=49 && h<=57)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										{
											printf("Casella gia' occupata");
											Flag1=0;
										}
										}while(Flag1==0);
										B1[h-4][k-20]='-';
										//int k1,h1;
										k1=k;
										h1=h;
										do{fflush(stdin);
										printf("Inserisci la posizione in cui vuoi inserire il secondo pezzo della nave:");
										scanf("%c",&k);
										scanf("%d",&h);
										if(k>=65 && k<=74)
										Flag1=1;
										if(h>=49 && h<=57)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										Flag1=0;
										if(k1-k==1)
										Flag1=1;
										if(k1-k==-1)
										Flag1=1;
										if(h1-h==1)
										Flag1=1;
										if(h1-h==-1)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										{
											printf("Casella gia'  occupata");
											Flag1=0;
										}
										}while(Flag1==0);
										B1[h-4][k-20]='-';
										k1=k;
										h1=h;
										do{fflush(stdin);
										printf("Inserisci la posizione in cui vuoi inserire il terzo pezzo della nave:");
										scanf("%c",&k);
										scanf("%d",&h);
										if(k>=65 && k<=74)
										Flag1=1;
										if(h>=49 && h<=57)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										Flag1=1;
										if(k1-k==1)
										Flag1=1;
										if(k1-k==-1)
										Flag1=1;
										if(h1-h==1)
										Flag1=1;
										if(h1-h==-1)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										{
											printf("Casella gia'  occupata");
											Flag1=0;
										}
										}while(Flag1==0);
										
										B1[h-4][k-20]='-';
										
										for(i=0;i<11;i++)
											{
												for(j=0;j<11;j++)
												{
													printf("|%c|",B1[i][j]);
												}
												printf("\n");
											}
												
									
									
									
										printf("Nave da posizionare:incrociatore\n");
										do{fflush(stdin);
										printf("Inserisci la posizione in cui vuoi inserire la nave:");
										scanf("%c",&k);
										scanf("%d",&h);
										if(k>=65 && k<=74)
										Flag1=1;
										if(h>=49 && h<=57)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										{
											printf("Casella gia'  occupata");
											Flag1=0;
										}
										}while(Flag1==0);
										B1[h-4][k-20]='-';
										k1=k;
										h1=h;
										do{fflush(stdin);
										printf("Inserisci la posizione in cui vuoi inserire il secondo pezzo della nave:");
										scanf("%c",&k);
										scanf("%d",&h);
										if(k>=65 && k<=74)
										Flag1=1;
										if(h>=49 && h<=57)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										Flag1=0;
										if(k1-k==1)
										Flag1=1;
										if(k1-k==-1)
										Flag1=1;
										if(h1-h==1)
										Flag1=1;
										if(h1-h==-1)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										{
											printf("Casella gia'  occupata");
											Flag1=0;
										}
										}while(Flag1==0);
										B1[h-4][k-20]='-';
										k1=k;
										h1=h;
										do{fflush(stdin);
										printf("Inserisci la posizione in cui vuoi inserire il terzo pezzo della nave:");
										scanf("%c",&k);
										scanf("%d",&h);
										if(k>=65 && k<=74)
										Flag1=1;
										if(h>=49 && h<=57)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										Flag1=0;
										if(k1-k==1)
										Flag1=1;
										if(k1-k==-1)
										Flag1=1;
										if(h1-h==1)
										Flag1=1;
										if(h1-h==-1)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										{
											printf("Casella gia'  occupata");
											Flag1=0;
										}
										}while(Flag1==0);
										B1[h-4][k-20]='-';
										k1=k;
										h1=h;
										do{fflush(stdin);
										printf("Inserisci la posizione in cui vuoi inserire il quarto pezzo della nave:");
										scanf("%c",&k);
										scanf("%d",&h);
										if(k>=65 && k<=74)
										Flag1=1;
										if(h>=49 && h<=57)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										Flag1=0;
										if(k1-k==1)
										Flag1=1;
										if(k1-k==-1)
										Flag1=1;
										if(h1-h==1)
										Flag1=1;
										if(h1-h==-1)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										{
											printf("Casella gia'  occupata");
											Flag1=0;
										}
										}while(Flag1==0);
										B1[h-4][k-20]='-';
											
											for(i=0;i<11;i++)
												{
													for(j=0;j<11;j++)
													{
														printf("|%c|",B1[i][j]);
													}
													printf("\n");
												}	
									
									
								
									
											printf("Nave da posizionare:cacciatorpediniere\n");
											do{fflush(stdin);
											printf("Inserisci la posizione in cui vuoi inserire la nave:");
											scanf("%c",&k);
											scanf("%d",&h);
											if(k>=65 && k<=74)
											Flag1=1;
											if(h>=49 && h<=57)
											Flag1=1;
											if(B1[h-4][k-20]!=32)
											{
												printf("Casella gia'  occupata");
												Flag1=0;
											}
											}while(Flag1==0);
											B1[h-4][k-20]='-';
											k1=k;
											h1=h;
											
											do{fflush(stdin);
											printf("Inserisci la posizione in cui vuoi inserire il secondo pezzo della nave:");
											scanf("%c",&k);
											scanf("%d",&h);
											if(k>=65 && k<=74)
											Flag1=1;
											if(h>=49 && h<=57)
											Flag1=1;
											if(B1[h-4][k-20]!=32)
											Flag1=0;
											if(k1-k==1)
											Flag1=1;
											if(k1-k==-1)
											Flag1=1;
											if(h1-h==1)
											Flag1=1;
											if(h1-h==-1)
											Flag1=1;
											if(B1[h-4][k-20]!=32)
											{
												printf("Casella gia'  occupata");
												Flag1=0;
											}
											}while(Flag1==0);
											B1[h-4][k-20]='-';
											
											for(i=0;i<11;i++)
													{
														for(j=0;j<11;j++)
														{
															printf("|%c|",B1[i][j]);
														}
														printf("\n");
													}
									
								
									printf("Nave da posizionare:portaerei\n");
									do{fflush(stdin);
									printf("Inserisci la posizione in cui vuoi inserire la nave:");
									scanf("%c",&k);
									scanf("%d",&h);
									if(k>=65 && k<=74)
									Flag1=1;
									if(h>=49 && h<=57)
									Flag1=1;
									if(B1[h-4][k-20]!=32)
										{
											printf("Casella gia'  occupata");
											Flag1=0;
										}
									}while(Flag1==0);
									B1[h-4][k-20]='-';
									k1=k;
									h1=h;
									do{fflush(stdin);
									printf("Inserisci la posizione in cui vuoi inserire il secondo pezzo della nave:");
									scanf("%c",&k);
									scanf("%d",&h);
									if(k>=65 && k<=74)
									Flag1=1;
									if(h>=49 && h<=57)
									Flag1=1;
									if(B1[h-4][k-20]!=32)
									Flag1=0;
									if(k1-k==1)
									Flag1=1;
									if(k1-k==-1)
									Flag1=1;
									if(h1-h==1)
									Flag1=1;
									if(h1-h==-1)
									Flag1=1;
									if(B1[h-4][k-20]!=32)
									{
										printf("Casella gia'  occupata");
										Flag1=0;
									}
									}while(Flag1==0);
									B1[h-4][k-20]='-';
									k1=k;
									h1=h;
									do{fflush(stdin);
									printf("Inserisci la posizione in cui vuoi inserire il terzo pezzo della nave:");
									scanf("%c",&k);
									scanf("%d",&h);
									if(k>=65 && k<=74)
									Flag1=1;
									if(h>=49 && h<=57)
									Flag1=1;
									if(B1[h-4][k-20]!=32)
									Flag1=0;
									if(k1-k==1)
									Flag1=1;
									if(k1-k==-1)
									Flag1=1;
									if(h1-h==1)
									Flag1=1;
									if(h1-h==-1)
									Flag1=1;
									if(B1[h-4][k-20]!=32)
									{
										printf("Casella gia'  occupata");
										Flag1=0;
									}
									}while(Flag1==0);
									B1[h-4][k-20]='-';
									k1=k;
									h1=h;
									do{fflush(stdin);
									printf("Inserisci la posizione in cui vuoi inserire il quarto pezzo della nave:");
									scanf("%c",&k);
									scanf("%d",&h);
									if(k>=65 && k<=74)
									Flag1=1;
									if(h>=49 && h<=57)
									Flag1=1;
									if(B1[h-4][k-20]!=32)
									Flag1=0;
									if(k1-k==1)
									Flag1=1;
									if(k1-k==-1)
									Flag1=1;
									if(h1-h==1)
									Flag1=1;
									if(h1-h==-1)
									Flag1=1;
									if(B1[h-4][k-20]!=32)
									{
										printf("Casella gia'  occupata");
										Flag1=0;
									}
									}while(Flag1==0);
									B1[h-4][k-20]='-';
									k1=k;
									h1=h;
									do{fflush(stdin);
									printf("Inserisci la posizione in cui vuoi inserire il quinto pezzo della nave:");
									scanf("%c",&k);
									scanf("%d",&h);
									if(k>=65 && k<=74)
									Flag1=1;
									if(h>=49 && h<=57)
									Flag1=1;
									if(B1[h-4][k-20]!=32)
									{
										printf("Casella gia'  occupata");
										Flag1=0;
									}
									}while(Flag1==0);
									B1[h-4][k-20]='-';
									
									for(i=0;i<11;i++)
											{
												for(j=0;j<11;j++)
												{
													printf("|%c|",B1[i][j]);
												}
												printf("\n");
											}
											system("cls");	
								}else{
		
									printf("Turno di player 2'\n");
									
									for(i=0;i<11;i++)
										{
											for(j=0;j<11;j++)
											{
												printf("|%c|",B2[i][j]);
												
											}
											printf("\n");
										}
									int k1,h1;		
												printf("Nave da posizionare:sottomarino\n");
								do{fflush(stdin);
								printf("Inserisci la posizione in cui vuoi inserire la nave:");
								scanf("%c",&k);
								scanf("%d",&h);
								if(k>=65 && k<=74)
								Flag1=1;						
								if(h>=49 && h<=57)
								Flag1=1;
								if(B2[h-4][k-20]!=32)
								{
									printf("Casella gia'  occupata");
									Flag1=0;
								}
								}while(Flag1==0);
								B2[h-4][k-20]='-';
								k1=k;
								h1=h;
								do{fflush(stdin);
								printf("Inserisci la posizione in cui vuoi inserire il secondo pezzo della nave:");
								scanf("%c",&k);
								scanf("%d",&h);
								if(k>=65 && k<=74)
								Flag1=1;
								if(h>=49 && h<=57)
								Flag1=1;
								if(B1[h-4][k-20]!=32)
								Flag1=0;
								if(k1-k==1)
								Flag1=1;
								if(k1-k==-1)
								Flag1=1;
								if(h1-h==1)
								Flag1=1;
								if(h1-h==-1)
								Flag1=1;
								if(B2[h-4][k-20]!=32)
								{
									printf("Casella gia'  occupata");
									Flag1=0;
								}
								}while(Flag1==0);
								B2[h-4][k-20]='-';
								k1=k;
								h1=h;
								do{fflush(stdin);
								printf("Inserisci la posizione in cui vuoi inserire il terzo pezzo della nave:");
								scanf("%c",&k);
								scanf("%d",&h);
								if(k>=65 && k<=74)
								Flag1=1;
								if(h>=49 && h<=57)
								Flag1=1;
								if(B1[h-4][k-20]!=32)
								Flag1=0;
								if(k1-k==1)
								Flag1=1;
								if(k1-k==-1)
								Flag1=1;
								if(h1-h==1)
								Flag1=1;
								if(h1-h==-1)
								Flag1=1;
								if(B2[h-4][k-20]!=32)
								{
									printf("Casella gia'  occupata");
									Flag1=0;
								}
								}while(Flag1==0);
								B2[h-4][k-20]='-';
								
								
								
								for(i=0;i<11;i++)
										{
											for(j=0;j<11;j++)
											{
												printf("|%c|",B2[i][j]);
											}
											printf("\n");
										}
								
							
						
								
								printf("Nave da posizionare:incrociatore\n");
								do{fflush(stdin);
								printf("Inserisci la posizione in cui vuoi inserire la nave:");
								scanf("%c",&k);
								scanf("%d",&h);
								if(k>=65 && k<=74)
								Flag1=1;
								if(h>=49 && h<=57)
								Flag1=1;
								if(B2[h-4][k-20]!=32)
								{
									printf("Casella gia'  occupata");
									Flag1=0;
								}
								}while(Flag1==0);
								B2[h-4][k-20]='-';
								k1=k;
								h1=h;
								do{fflush(stdin);
								printf("Inserisci la posizione in cui vuoi inserire il secondo pezzo della nave:");
								scanf("%c",&k);
								scanf("%d",&h);
								if(k>=65 && k<=74)
								Flag1=1;
								if(h>=49 && h<=57)
								Flag1=1;
								if(B1[h-4][k-20]!=32)
								Flag1=0;
								if(k1-k==1)
								Flag1=1;
								if(k1-k==-1)
								Flag1=1;
								if(h1-h==1)
								Flag1=1;
								if(h1-h==-1)
								Flag1=1;
								}while(Flag1==0);
								B2[h-4][k-20]='-';
								k1=k;
								h1=h;
								do{fflush(stdin);
								printf("Inserisci la posizione in cui vuoi inserire il terzo pezzo della nave:");
								scanf("%c",&k);
								scanf("%d",&h);
								if(k>=65 && k<=74)
								Flag1=1;
								if(h>=49 && h<=57)
								Flag1=1;
								if(B1[h-4][k-20]!=32)
								Flag1=0;
								if(k1-k==1)
								Flag1=1;
								if(k1-k==-1)
								Flag1=1;
								if(h1-h==1)
								Flag1=1;
								if(h1-h==-1)
								Flag1=1;
								if(B2[h-4][k-20]!=32)
								{
									printf("Casella gia'  occupata");
									Flag1=0;
								}
								}while(Flag1==0);
								k1=k;
								h1=h;
								B2[h-4][k-20]='-';
								
								do{fflush(stdin);
								printf("Inserisci la posizione in cui vuoi inserire il quarto pezzo della nave:");
								scanf("%c",&k);
								scanf("%d",&h);
								if(k>=65 && k<=74)
								Flag1=1;
								if(h>=49 && h<=57)
								Flag1=1;
								if(B1[h-4][k-20]!=32)
								Flag1=0;
								if(k1-k==1)
								Flag1=1;
								if(k1-k==-1)
								Flag1=1;
								if(h1-h==1)
								Flag1=1;
								if(h1-h==-1)
								Flag1=1;
								if(B2[h-4][k-20]!=32)
								{
									printf("Casella gia'  occupata");
									Flag1=0;
								}
								}while(Flag1==0);
								B2[h-4][k-20]='-';
									
									for(i=0;i<11;i++)
										{
											for(j=0;j<11;j++)
											{
												printf("|%c|",B2[i][j]);
											}
											printf("\n");
										}
							
						
								printf("Nave da posizionare:cacciatorpediniere\n");
								do{fflush(stdin);
								printf("Inserisci la posizione in cui vuoi inserire la nave:");
								scanf("%c",&k);
								scanf("%d",&h);
								if(k>=65 && k<=74)
								Flag1=1;
								if(h>=49 && h<=57)
								Flag1=1;
								if(B2[h-4][k-20]!=32)
								{
									printf("Casella gia'  occupata");
									Flag1=0;
								}
								}while(Flag1==0);
								B2[h-4][k-20]='-';
								k1=k;
								h1=h;
								do{fflush(stdin);
								printf("Inserisci la posizione in cui vuoi inserire il secondo pezzo della nave:");
								scanf("%c",&k);
								scanf("%d",&h);
								if(k>=65 && k<=74)
								Flag1=1;
								if(h>=49 && h<=57)
								Flag1=1;
								if(B1[h-4][k-20]!=32)
								Flag1=0;
								if(k1-k==1)
								Flag1=1;
								if(k1-k==-1)
								Flag1=1;
								if(h1-h==1)
								Flag1=1;
								if(h1-h==-1)
								Flag1=1;
								if(B2[h-4][k-20]!=32)
								{
									printf("Casella gia'  occupata");
									Flag1=0;
								}
								}while(Flag1==0);
								B2[h-4][k-20]='-';
								
								for(i=0;i<11;i++)
										{
											for(j=0;j<11;j++)
											{
												printf("|%c|",B2[i][j]);
											}
											printf("\n");
										}
							
							
								printf("Nave da posizionare:portaerei\n");
								do{fflush(stdin);
								printf("Inserisci la posizione in cui vuoi inserire la nave:");
								scanf("%c",&k);
								scanf("%d",&h);
								if(k>=65 && k<=74)
								Flag1=1;
								if(h>=49 && h<=57)
								Flag1=1;
								if(B2[h-4][k-20]!=32)
								{
									printf("Casella gia'  occupata");
									Flag1=0;
								}
								}while(Flag1==0);
								B2[h-4][k-20]='-';
								k1=k;
								h1=h;
								do{fflush(stdin);
								printf("Inserisci la posizione in cui vuoi inserire il secondo pezzo della nave:");
								scanf("%c",&k);
								scanf("%d",&h);
								if(k>=65 && k<=74)
								Flag1=1;
								if(h>=49 && h<=57)
								Flag1=1;
								if(B1[h-4][k-20]!=32)
								Flag1=0;
								if(k1-k==1)
								Flag1=1;
								if(k1-k==-1)
								Flag1=1;
								if(h1-h==1)
								Flag1=1;
								if(h1-h==-1)
								Flag1=1;
								if(B2[h-4][k-20]!=32)
								{
									printf("Casella gia'  occupata");
									Flag1=0;
								}
								}while(Flag1==0);
								B2[h-4][k-20]='-';
								k1=k;
								h1=h;
								do{fflush(stdin);
								printf("Inserisci la posizione in cui vuoi inserire il terzo pezzo della nave:");
								scanf("%c",&k);
								scanf("%d",&h);
								if(k>=65 && k<=74)
								Flag1=1;
								if(h>=49 && h<=57)
								Flag1=1;
								if(B1[h-4][k-20]!=32)
								Flag1=0;
								if(k1-k==1)
								Flag1=1;
								if(k1-k==-1)
								Flag1=1;
								if(h1-h==1)
								Flag1=1;
								if(h1-h==-1)
								Flag1=1;
								if(B2[h-4][k-20]!=32)
								{
									printf("Casella gia'  occupata");
									Flag1=0;
								}
								}while(Flag1==0);
								k1=k;
								h1=h;
								B2[h-4][k-20]='-';
								
								do{fflush(stdin);
								printf("Inserisci la posizione in cui vuoi inserire il quarto pezzo della nave:");
								scanf("%c",&k);
								scanf("%d",&h);
								if(k>=65 && k<=74)
								Flag1=1;
								if(h>=49 && h<=57)
								Flag1=1;
								if(B1[h-4][k-20]!=32)
								Flag1=0;
								if(k1-k==1)
								Flag1=1;
								if(k1-k==-1)
								Flag1=1;
								if(h1-h==1)
								Flag1=1;
								if(h1-h==-1)
								Flag1=1;
								if(B2[h-4][k-20]!=32)
								{
									printf("Casella gia'  occupata");
									Flag1=0;
								}
								}while(Flag1==0);
								B2[h-4][k-20]='-';
								k1=k;
								h1=h;
								do{fflush(stdin);
								printf("Inserisci la posizione in cui vuoi inserire il quinto pezzo della nave:");
								scanf("%c",&k);
								scanf("%d",&h);
								if(k>=65 && k<=74)
								Flag1=1;
								if(h>=49 && h<=57)
								Flag1=1;
								if(B1[h-4][k-20]!=32)
								Flag1=0;
								if(k1-k==1)
								Flag1=1;
								if(k1-k==-1)
								Flag1=1;
								if(h1-h==1)
								Flag1=1;
								if(h1-h==-1)
								Flag1=1;
								if(B2[h-4][k-20]!=32)
								{
									printf("Casella gia'  occupata");
									Flag1=0;
								}
								}while(Flag1==0);
								B2[h-4][k-20]='-';
								
								for(i=0;i<11;i++)
										{
											for(j=0;j<11;j++)
											{
												printf("|%c|",B2[i][j]);
											}
											printf("\n");
										}
											
										}
		}
	
		
		
		
			
		
	
	system("cls");	

	for(p=0;p<100;i++)
	{	
			for(i=0;i<11;i++)
				{
					for(j=0;j<11;j++)
					{
						printf("|%c|",M1[i][j]);
					}
					printf("\n");
				}
				
		
		do{fflush(stdin);
		printf("Player 1 Scegli la destinazione del missile");
		scanf("%c",&k);
		scanf("%d",&h);
		if(k>=65 && k<=74)
		Flag1=1;
		if(h>=49 && h<=57)
		Flag1=1;
		if(M1[h-4][k-20]!=32 )
		Flag1=0;
		}while(Flag1==0);
		int V1=0,V2=0;
		if(B2[h-4][k-20]=='-')
		{B2[h-4][k-20]==32;
			V1++;
			printf("Nave colpita\n");
			M1[h-4][k-20]='X';
		}else{B2[h-4][k-20]==32;
			printf("Nave non colpita\n");
			M1[h-4][k-20]='O';
		}
		
		flag=0;	
		for(i=0;i<11;i++)
				{
					for(j=0;j<11;j++)
					{
						if(M1[i][j]=='X')
						flag++;
					}
					
				}
		if(V1==14)
		{
			printf("Player 1 vince\n\n\n\n\n");
			return 0;
		}		
		
			for(i=0;i<11;i++)
				{
					for(j=0;j<11;j++)
					{
						printf("|%c|",M2[i][j]);
					}
					printf("\n");
				}
				
		
		do{
			fflush(stdin);
			printf("Player 2 Scegli la destinazione del missile");
			scanf("%c",&k);
			scanf("%d",&h);
			if(k>=65 && k<=74)
			Flag1=1;
			if(h>=49 && h<=57)
			Flag1=1;
			if(M2[h-4][k-20]!=32)
			Flag1=0;
			}while(Flag1==0);
			
			if(B1[h-4][k-20]=='-')
			{	B1[h-4][k-20]==32;
				V2++;
				printf("Nave colpita\n");
				M2[h-4][k-20]='X';
			}else{
				B1[h-4][k-20]==32;
				printf("Nave non colpita\n");
				M2[h-4][k-20]='O';
			}
			
		flag=0;	
		for(i=0;i<11;i++)
				{
					for(j=0;j<11;j++)
					{
						if(M2[i][j]=='X')
						flag++;
					}
					
				}
		if(V2==14)
		{
			printf("Player 2 vince\n\n\n\n\n");
			return 1;
		}		
		
		
	}return 2;
}	


int forza4()
{system("cls");
	int i,y,T,flag,k,F,L;
	char M[6][7],*pu;
	
	for(i=0;i<6;i++)
	{
		for(y=0;y<7;y++)
		{
			M[i][y]=32;
		}
	}
	
	printf("Simbolo giocatore 1: O\n");
	printf("Simbolo giocatore 2: X\n");
	for(k=0;k<42;k++)
	{	
		flag=1;
		
		do{
			
			printf("   1  2  3  4  5  6  7\n");
					 		for (i=0;i<6;i++)
							{fflush(stdin);
							
							printf("|");
							
					        for (y=0;y<7;y++) 
							{fflush(stdin);
							
					            printf("  %c",M[i][y]);
					        }
					        printf("  |\n");
					   		}
			   		
			printf("Giocatore 1 inserisci la colonna in cui inserire il gettone");
			scanf("%d",&T);
			system("cls");
				while(T>7 || T<0)
				{fflush(stdin);
					
				printf("  1  2  3  4  5  6  7\n");
					 		for (i=0;i<6;i++)
							{fflush(stdin);
							
							printf("|");
							
					        for (y=0;y<7;y++) 
							{fflush(stdin);
							
					            printf("  %c",M[i][y]);
					        }
					        printf("  |\n");
					   		}
			    
			    printf("Colonna non valida rinserisci:");
			 	scanf("%d",&T);
			 	system("cls");
				}
				
				if(M[0][T-1]!=32)
				{
					printf("Colonna piena\n");
					
				}else if(M[5][T-1]==32)
					{
						M[5][T-1]='O';
						flag=0;
						
					}else 	for(y=6;y>=0;y--)
							{
								if(M[y][T-1]==32)
								{
									M[y][T-1]='O';
									L=y;
									y=-1;
									flag=0;
								}
							}
				
		}while(flag==1);
		
		flag=1;
		
					T=T-1;
				
				for(i=0;i<6;i++)
				{
					for(y=0;y<4;y++)
					{
						if(M[i][y]=='O' && M[i][y+1]=='O' && M[i][y+2]=='O' && M[i][y+3]=='O')
						F=1;
					}
				}
				
				for(i=0;i<3;i++)
				{
					for(y=0;y<7;y++)
					{
						if(M[i][y]=='O' && M[i+1][y]=='O' && M[i+3][y]=='O' && M[i+2][y]=='O')
						F=1;
					}
				}
				
				for(i=0;i<=2;i++)
				{
					for(y=0;y<=3;y++)
					{
						if(M[i][y]=='O' && M[i+1][y+1]=='O' && M[i+3][y+3]=='O' && M[i+2][y+2]=='O')
						F=1;
					}
				}
				
				for(i=3;i<6;i++)
				{
					for(y=0;y<=3;y++)
					{
						if(M[i][y]=='O' && M[i-1][y+1]=='O' && M[i-3][y+3]=='O' && M[i-2][y+2]=='O')
						F=1;
					}
				}
				
					
					if(F==1)
					{	system("cls");
						
							printf("  1  2  3  4  5  6  7\n");
					 		for (i=0;i<6;i++)
							{fflush(stdin);
							
							printf("|");
							
					        for (y=0;y<7;y++) 
							{fflush(stdin);
							
					            printf("  %c",M[i][y]);
					        }
					        printf("  |\n");
					   		}
					   			printf("Vince giocatore 1\n\n\n\n\n");
		// L= riga
					 return 0;
				 }
				do{
					printf("   1  2  3  4  5  6  7\n");
					 		for (i=0;i<6;i++)
							{fflush(stdin);
							
								printf("|");
								
						        for (y=0;y<7;y++) 
								{fflush(stdin);
								
						            printf("  %c",M[i][y]);
						        }
					        printf("  |\n");
					   		}
					   		
					printf("Giocatore 2 inserisci la colonna in cui inserire il gettone");
					scanf("%d",&T);
						system("cls");
						while(T>7 || T<0)
						{fflush(stdin);
							
							printf("  1  2  3  4  5  6  7\n");
					 		for (i=0;i<6;i++)
							{fflush(stdin);
							
							printf("|");
							
					        for (y=0;y<7;y++) 
							{fflush(stdin);
							
					            printf("  %c",M[i][y]);
					        }
					        printf("  |\n");
					   		}
					    
					    printf("Colonna non valida rinserisci:");
					 	scanf("%d",&T);
					 	system("cls");
						}
						
						if(M[0][T-1]!=32)
						{
							printf("Colonna piena\n");
							
						}else if(M[5][T-1]==32)
							{
								M[5][T-1]='X';
								flag=0;
								
							}else 	for(y=6;y>=0;y--)
									{
										
										if(M[y][T-1]==32)
										{
											M[y][T-1]='X';
											y=-1;
											L=y;
											flag=0;
										}
									
									}
					
		}while(flag==1);
		
					T=T-1;
					
				for(i=0;i<6;i++)
				{
					for(y=0;y<4;y++)
					{
						if(M[i][y]=='X' && M[i][y+1]=='X' && M[i][y+2]=='X' && M[i][y+3]=='X')
						F=2;
					}
				}
				
				for(i=0;i<3;i++)
				{
					for(y=0;y<7;y++)
					{
						if(M[i][y]=='X' && M[i+1][y]=='X' && M[i+3][y]=='X' && M[i+2][y]=='X')
						F=2;
					}
				}
				
				for(i=0;i<=2;i++)
				{
					for(y=0;y<=3;y++)
					{
						if(M[i][y]=='X' && M[i+1][y+1]=='X' && M[i+3][y+3]=='X' && M[i+2][y+2]=='X')
						F=2;
					}
				}
				
				for(i=3;i<6;i++)
				{
					for(y=0;y<=3;y++)
					{
						if(M[i][y]=='X' && M[i-1][y+1]=='X' && M[i-3][y+3]=='X' && M[i-2][y+2]=='X')
						F=2;
					}
				}

		if(F==2)
		{	system("cls");
			
			printf("  1  2  3  4  5  6  7\n");
					 		for (i=0;i<6;i++)
							{fflush(stdin);
							
							printf("|");
							
					        for (y=0;y<7;y++) 
							{fflush(stdin);
							
					            printf("  %c",M[i][y]);
					        }
					        printf("  |\n");
					   		}
			printf("Vince giocatore 2\n\n\n\n\n");
			return 1;
		}	
	}
}


int forza4bot()
{
	system("cls");
	int i,y,T,flag,k,F,L,n,m,j;
	char M[6][7],M1[6][7],*pu;
	
	for(i=0;i<6;i++)
	{
		for(y=0;y<7;y++)
		{
			M[i][y]=32;
		}
	}
	srand(time(0));
	while(n>2 || n<1)
	{
		printf("Difficolta bot:\n1-Facile\n2-Difficile");
		scanf("%d",&n);
		system("cls");
	}
	
	if(n==1)
	{
		for(k=0;k<42;k++)
		{	
			flag=1;
			
			do{
				
				printf("   1  2  3  4  5  6  7\n");
						 		for (i=0;i<6;i++)
								{fflush(stdin);
								
								printf("|");
								
						        for (y=0;y<7;y++) 
								{fflush(stdin);
								
						            printf("  %c",M[i][y]);
						        }
						        printf("  |\n");
						   		}
				   		
				printf("Giocatore 1 inserisci la colonna in cui inserire il gettone");
				scanf("%d",&T);
				system("cls");
					while(T>7 || T<0)
					{fflush(stdin);
						
					printf("  1  2  3  4  5  6  7\n");
						 		for (i=0;i<6;i++)
								{fflush(stdin);
								
								printf("|");
								
						        for (y=0;y<7;y++) 
								{fflush(stdin);
								
						            printf("  %c",M[i][y]);
						        }
						        printf("  |\n");
						   		}
				    
				    printf("Colonna non valida rinserisci:");
				 	scanf("%d",&T);
				 	system("cls");
					}
					
					if(M[0][T-1]!=32)
					{
						printf("Colonna piena\n");
						
					}else if(M[5][T-1]==32)
						{
							M[5][T-1]='O';
							flag=0;
							
						}else 	for(y=6;y>=0;y--)
								{
									if(M[y][T-1]==32)
									{
										M[y][T-1]='O';
										L=y;
										y=-1;
										flag=0;
									}
								}
					
			}while(flag==1);
			
			flag=1;
			
						T=T-1;
					
					for(i=0;i<6;i++)
					{
						for(y=0;y<4;y++)
						{
							if(M[i][y]=='O' && M[i][y+1]=='O' && M[i][y+2]=='O' && M[i][y+3]=='O')
							F=1;
						}
					}
					
					for(i=0;i<3;i++)
					{
						for(y=0;y<7;y++)
						{
							if(M[i][y]=='O' && M[i+1][y]=='O' && M[i+3][y]=='O' && M[i+2][y]=='O')
							F=1;
						}
					}
					
					for(i=0;i<=2;i++)
					{
						for(y=0;y<=3;y++)
						{
							if(M[i][y]=='O' && M[i+1][y+1]=='O' && M[i+3][y+3]=='O' && M[i+2][y+2]=='O')
							F=1;
						}
					}
					
					for(i=3;i<6;i++)
					{
						for(y=0;y<=3;y++)
						{
							if(M[i][y]=='O' && M[i-1][y+1]=='O' && M[i-3][y+3]=='O' && M[i-2][y+2]=='O')
							F=1;
						}
					}
					
						
						if(F==1)
						{	system("cls");
							
								printf("  1  2  3  4  5  6  7\n");
						 		for (i=0;i<6;i++)
								{fflush(stdin);
								
								printf("|");
								
						        for (y=0;y<7;y++) 
								{fflush(stdin);
								
						            printf("  %c",M[i][y]);
						        }
						        printf("  |\n");
						   		}
						   			printf("Vince giocatore 1\n\n\n\n\n");
			// L= riga
						 return 0;
					 }
					do{
							system("cls");
						
							T=rand()%7;
							
							if(M[0][T-1]!=32)
							{
								printf("Colonna piena\n");
								
							}else if(M[5][T-1]==32)
								{
									M[5][T-1]='X';
									flag=0;
									
								}else 	for(y=6;y>=0;y--)
										{
											
											if(M[y][T-1]==32)
											{
												M[y][T-1]='X';
												y=-1;
												L=y;
												flag=0;
											}
										
										}
						
			}while(flag==1);
			
						T=T-1;
						
					for(i=0;i<6;i++)
					{
						for(y=0;y<4;y++)
						{
							if(M[i][y]=='X' && M[i][y+1]=='X' && M[i][y+2]=='X' && M[i][y+3]=='X')
							F=2;
						}
					}
					
					for(i=0;i<3;i++)
					{
						for(y=0;y<7;y++)
						{
							if(M[i][y]=='X' && M[i+1][y]=='X' && M[i+3][y]=='X' && M[i+2][y]=='X')
							F=2;
						}
					}
					
					for(i=0;i<=2;i++)
					{
						for(y=0;y<=3;y++)
						{
							if(M[i][y]=='X' && M[i+1][y+1]=='X' && M[i+3][y+3]=='X' && M[i+2][y+2]=='X')
							F=2;
						}
					}
					
					for(i=3;i<6;i++)
					{
						for(y=0;y<=3;y++)
						{
							if(M[i][y]=='X' && M[i-1][y+1]=='X' && M[i-3][y+3]=='X' && M[i-2][y+2]=='X')
							F=2;
						}
					}
	
			if(F==2)
			{	system("cls");
				
				printf("  1  2  3  4  5  6  7\n");
						 		for (i=0;i<6;i++)
								{fflush(stdin);
								
								printf("|");
								
						        for (y=0;y<7;y++) 
								{fflush(stdin);
								
						            printf("  %c",M[i][y]);
						        }
						        printf("  |\n");
						   		}
				printf("Vince giocatore 2\n\n\n\n\n");
				return 1;
		}	
	}
	}
	
	
	
	
	
	if(n==2)
	{
		for(k=0;k<42;k++)
		{	
			flag=1;
			
			do{
				
				printf("   1  2  3  4  5  6  7\n");
						 		for (i=0;i<6;i++)
								{fflush(stdin);
								
								printf("|");
								
						        for (y=0;y<7;y++) 
								{fflush(stdin);
								
						            printf("  %c",M[i][y]);
						        }
						        printf("  |\n");
						   		}
				   		
				printf("Giocatore 1 inserisci la colonna in cui inserire il gettone");
				scanf("%d",&T);
				system("cls");
					while(T>7 || T<0)
					{fflush(stdin);
						
					printf("  1  2  3  4  5  6  7\n");
						 		for (i=0;i<6;i++)
								{fflush(stdin);
								
								printf("|");
								
						        for (y=0;y<7;y++) 
								{fflush(stdin);
								
						            printf("  %c",M[i][y]);
						        }
						        printf("  |\n");
						   		}
				    
				    printf("Colonna non valida rinserisci:");
				 	scanf("%d",&T);
				 	system("cls");
					}
					
					if(M[0][T-1]!=32)
					{
						printf("Colonna piena\n");
						
					}else if(M[5][T-1]==32)
						{
							M[5][T-1]='O';
							flag=0;
							
						}else 	for(y=6;y>=0;y--)
								{
									if(M[y][T-1]==32)
									{
										M[y][T-1]='O';
										L=y;
										y=-1;
										flag=0;
									}
								}
					
			}while(flag==1);
			
			flag=1;
			
						T=T-1;
					
					for(i=0;i<6;i++)
					{
						for(y=0;y<4;y++)
						{
							if(M[i][y]=='O' && M[i][y+1]=='O' && M[i][y+2]=='O' && M[i][y+3]=='O')
							F=1;
						}
					}
					
					for(i=0;i<3;i++)
					{
						for(y=0;y<7;y++)
						{
							if(M[i][y]=='O' && M[i+1][y]=='O' && M[i+3][y]=='O' && M[i+2][y]=='O')
							F=1;
						}
					}
					
					for(i=0;i<=2;i++)
					{
						for(y=0;y<=3;y++)
						{
							if(M[i][y]=='O' && M[i+1][y+1]=='O' && M[i+3][y+3]=='O' && M[i+2][y+2]=='O')
							F=1;
						}
					}
					
					for(i=3;i<6;i++)
					{
						for(y=0;y<=3;y++)
						{
							if(M[i][y]=='O' && M[i-1][y+1]=='O' && M[i-3][y+3]=='O' && M[i-2][y+2]=='O')
							F=1;
						}
					}
					
						
						if(F==1)
						{	system("cls");
							
								printf("  1  2  3  4  5  6  7\n");
						 		for (i=0;i<6;i++)
								{fflush(stdin);
								
								printf("|");
								
						        for (y=0;y<7;y++) 
								{fflush(stdin);
								
						            printf("  %c",M[i][y]);
						        }
						        printf("  |\n");
						   		}
						   			printf("Vince giocatore 1\n\n\n\n\n");
			// L= riga
						 return 0;
					 }
	   	
 	for(m=1;m<=7;m++)
 	{	flag=1;
 		for (i=0;i<6;i++)				
		{fflush(stdin);
		 	for (y=0;y<7;y++) 
			{fflush(stdin);
				M1[i][y]=M[i][y];		           
			}		        
		}
 			
							   	while(flag==1)
							   	{
							   		if(M1[0][m-1]!=32)
									{
										m++;
									}else if(M1[5][m-1]==32)
										{
											M1[5][m-1]='X';
											flag=0;
											//m=8;
											
										}else 	for(j=6;j>=0;j--)
												{
													
													if(M1[j][m-1]==32)
													{
														M1[j][m-1]='X';
														j=-1;
														L=j;
														flag=0;
													}
												}
						   		
											
								}
								T=T-1;
						
								for(i=0;i<6;i++)
								{
									for(y=0;y<4;y++)
									{
										if(M1[i][y]=='X' && M1[i][y+1]=='X' && M1[i][y+2]=='X' && M1[i][y+3]=='X')
										{
											if(M[5][m-1]==32)
											{
												M[5][m-1]='X';
												flag=0;
												m=10;
												
											}else 	for(j=6;j>=0;j--)
													{
														
														if(M[j][m-1]==32)
														{
															M[j][m-1]='X';
															j=-1;
															L=j;
															m=10;
														}
													}
										}
									}
								}
								
								for(i=0;i<3;i++)
								{
									for(y=0;y<7;y++)
									{
										if(M1[i][y]=='X' && M1[i+1][y]=='X' && M1[i+3][y]=='X' && M1[i+2][y]=='X')
										{
											if(m!=10)
											{
												if(M[5][m-1]==32)
												{
													M[5][m-1]='X';
													flag=0;
													m=10;
													
												}else 	for(j=6;j>=0;j--)
														{
															
															if(M[j][m-1]==32)
															{
																M[j][m-1]='X';
																j=-1;
																L=j;
																m=10;
															}
														}
											}
										}
								}
								
								for(i=0;i<=2;i++)
								{
									for(y=0;y<=3;y++)
									{
										if(M1[i][y]=='X' && M1[i+1][y+1]=='X' && M1[i+3][y+3]=='X' && M1[i+2][y+2]=='X')
										{
											if(m!=10)
											{
												if(M[5][m-1]==32)
												{
													M[5][m-1]='X';
													flag=0;
													m=10;
													
												}else 	for(j=6;j>=0;j--)
														{
															
															if(M[j][m-1]==32)
															{
																M[j][m-1]='X';
																j=-1;
																L=j;
																m=10;
															}
														}
											}
										}
									}
								}
								
								for(i=3;i<6;i++)
								{
									for(y=0;y<=3;y++)
									{
										if(M1[i][y]=='X' && M1[i-1][y+1]=='X' && M1[i-3][y+3]=='X' && M1[i-2][y+2]=='X')
										{
											if(m!=10)
											{
												if(M[5][m-1]==32)
												{
													M[5][m-1]='X';
													flag=0;
													m=10;
													
												}else 	for(j=6;j>=0;j--)
														{
															
															if(M[j][m-1]==32)
															{
																M[j][m-1]='X';
																j=-1;
																L=j;
																m=10;
															}
														}
											}
										}
									}
								}

		}
		
	}	
//	printf("%d",m);
	if(m!=10)
	{
		
		for(m=1;m<=7;m++)
		{	flag=1;
			for (i=0;i<6;i++)				
			{fflush(stdin);
			 	for (y=0;y<7;y++) 
				{fflush(stdin);
					M1[i][y]=M[i][y];		           
				}		        
			}
							   	while(flag==1)
							   	{
							   		if(M1[0][m-1]!=32)
									{
										m++;
									}else if(M1[5][m-1]==32)
										{
											M1[5][m-1]='O';
											flag=0;
											
										}else 	for(j=6;j>=0;j--)
												{
													
													if(M1[j][m-1]==32)
													{
														M1[j][m-1]='O';
														j=-1;
														L=j;
														flag=0;
													}
												}
						   		
											
								}
								T=T-1;
						
								for(i=0;i<6;i++)
								{
									for(y=0;y<4;y++)
									{
										if(M1[i][y]=='O' && M1[i][y+1]=='O' && M1[i][y+2]=='O' && M1[i][y+3]=='O')
										{
											if(M[5][m-1]==32)
											{
												M[5][m-1]='X';
												flag=0;
												m=10;
												
											}else 	for(j=6;j>=0;j--)
													{
														
														if(M[j][m-1]==32)
														{
															M[j][m-1]='X';
															j=-1;
															L=j;
															m=10;
														}
													}
										}
									}
								}
								
								for(i=0;i<3;i++)
								{
									for(y=0;y<7;y++)
									{
										if(M1[i][y]=='O' && M1[i+1][y]=='O' && M1[i+3][y]=='O' && M1[i+2][y]=='O')
										{
											if(m!=10)
											{
												if(M[5][m-1]==32)
												{
													M[5][m-1]='X';
													flag=0;
													m=10;
													
												}else 	for(j=6;j>=0;j--)
														{
															
															if(M[j][m-1]==32)
															{
																M[j][m-1]='X';
																j=-1;
																L=j;
																m=10;
															}
														}
											}
										}
								}
								
								for(i=0;i<=2;i++)
								{
									for(y=0;y<=3;y++)
									{
										if(M1[i][y]=='O' && M1[i+1][y+1]=='O' && M1[i+3][y+3]=='O' && M1[i+2][y+2]=='O')
										{
											if(m!=10)
											{
												if(M[5][m-1]==32)
												{
													M[5][m-1]='X';
													flag=0;
													m=10;
													
												}else 	for(j=6;j>=0;j--)
														{
															
															if(M[j][m-1]==32)
															{
																M[j][m-1]='X';
																j=-1;
																L=j;
																m=10;
															}
														}
											}
										}
									}
								}
								
								for(i=3;i<6;i++)
								{
									for(y=0;y<=3;y++)
									{
										if(M1[i][y]=='O' && M1[i-1][y+1]=='O' && M1[i-3][y+3]=='O' && M1[i-2][y+2]=='O')
										{
											if(m!=10)
											{
												if(M[5][m-1]==32)
												{
													M[5][m-1]='X';
													flag=0;
													m=10;
													
												}else 	for(j=6;j>=0;j--)
														{
															
															if(M[j][m-1]==32)
															{
																M[j][m-1]='X';
																j=-1;
																L=j;
																m=10; 
															}
														}
											}
										}
									}
								}
							}
						}
	
	}
//	printf(" %d\n",m);
	if(m!=10)
	{
		flag=1;
		do{
						
							T=rand()%7;
							
							if(M[0][T-1]!=32)
							{
								printf("Colonna piena\n");
								
							}else if(M[5][T-1]==32)
								{
									M[5][T-1]='X';
									flag=0;
									m=10;
									
								}else 	for(y=6;y>=0;y--)
										{
											
											if(M[y][T-1]==32)
											{
												M[y][T-1]='X';
												y=-1;
												L=y;
												flag=0;
											}
										
										}
						
			}while(flag==1);
	}	
				T=T-1;
						
					for(i=0;i<6;i++)
					{
						for(y=0;y<4;y++)
						{
							if(M[i][y]=='X' && M[i][y+1]=='X' && M[i][y+2]=='X' && M[i][y+3]=='X')
							F=2;
						}
					}
					
					for(i=0;i<3;i++)
					{
						for(y=0;y<7;y++)
						{
							if(M[i][y]=='X' && M[i+1][y]=='X' && M[i+3][y]=='X' && M[i+2][y]=='X')
							F=2;
						}
					}
					
					for(i=0;i<=2;i++)
					{
						for(y=0;y<=3;y++)
						{
							if(M[i][y]=='X' && M[i+1][y+1]=='X' && M[i+3][y+3]=='X' && M[i+2][y+2]=='X')
							F=2;
						}
					}
					
					for(i=3;i<6;i++)
					{
						for(y=0;y<=3;y++)
						{
							if(M[i][y]=='X' && M[i-1][y+1]=='X' && M[i-3][y+3]=='X' && M[i-2][y+2]=='X')
							F=2;
						}
					}
	
			if(F==2)
			{	system("cls");
				
				printf("  1  2  3  4  5  6  7\n");
						 		for (i=0;i<6;i++)
								{fflush(stdin);
								
								printf("|");
								
						        for (y=0;y<7;y++) 
								{fflush(stdin);
								
						            printf("  %c",M[i][y]);
						        }
						        printf("  |\n");
						   		}
				printf("Vince bot\n\n\n\n\n");
				return 1;				
}
	
}
}
}


int trisbot()
{
	char M [3][3];
	char M1 [3][3];
	int i,j,y,k,h,n=10;
	int a,p,flag=0,flag1=0,t;
	while(n>2 || n<1)
	{
		printf("Difficolta bot:\n1-Facile\n2-Difficile");
		scanf("%d",&n);
	}
	
	if(n==1)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				M[i][j]=32;
			}
		}
	
		for(p=0;p<9;p++)
		{
				for(i=0;i<3;i++)
				{
				for(j=0;j<3;j++)
					{
						printf("|%c|",M[i][j]);
					}
				printf("\n");
				}
				do{fflush(stdin);
				printf("Inserisci le coordinate in cui mettere la X");
				scanf("%d",&k);
				scanf("%d",&h);
				if(k<=3 && k>=1)
				flag=1;
				if(h<=3 && h>=1)
				flag=1;
				if(M[k-1][h-1]!=32)
				flag=0;
				}
				while(flag==0);
				M[k-1][h-1]=88;
				
				system("cls");
	
		    if ( ((M[0][0]==88) && (M[0][1]==88) && (M[0][2]==88)) || ((M[1][0]==88) && (M[1][1]==88) && (M[1][2]==88)) || ((M[2][0]==88) && (M[2][1]==88) && (M[2][2]==88)) || ((M[0][0]==88) && (M[1][1]==88) && (M[2][2]==88)) || ((M[2][0]==88) && (M[1][1]==88) && (M[0][2]==88)) || ((M[0][0]==88) && (M[1][0]==88) && (M[2][0]==88)) || ((M[0][1]==88) && (M[1][1]==88) && (M[2][1]==88)) || ((M[0][2]==88) && (M[1][2]==88) && (M[2][2]==88))  )
			{			
							for(i=0;i<3;i++)
							{
							for(j=0;j<3;j++)
								{
									printf("|%c|",M[i][j]);
								}
							printf("\n");
							}
						printf ("Player 1 vince\n\n\n\n\n");
							return 0;			
					}
				
					
			
				
				if ( ((M[0][0]==79) && (M[0][1]==79) && (M[0][2]==79)) || ((M[1][0]==79) && (M[1][1]==79) && (M[1][2]==79)) || ((M[2][0]==79) && (M[2][1]==79) && (M[2][2]==79)) || ((M[0][0]==79) && (M[1][1]==79) && (M[2][2]==79)) || ((M[2][0]==79) && (M[1][1]==79) && (M[0][2]==79)) || (M[0][0]==79) && (M[2][0]==79) && (M[1][0]==79) || ((M[0][1]==79) && (M[1][1]==79) && (M[2][1]==79)) || ((M[0][2]==79) && (M[1][2]==79) && (M[2][2]==79)) )	
				{
						for(i=0;i<3;i++)
						{
						for(j=0;j<3;j++)
							{
								printf("|%c|",M[i][j]);
							}
						printf("\n");
						}
					printf("Bot vince\n\n\n\n\n");
					return 1;	
				}	
					fflush(stdin);
	srand(time(0));
	while(M[n][t]!=32)
	{
		fflush(stdin);
		n=rand()%3;
		t=rand()%3;
	}
	fflush(stdin);
	M[n][t]='O';
				}
		printf("Pareggio");
		return 104;
	}
	if(n==2)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				M[i][j]=32;
			}
		}
	
		for(p=0;p<9;p++)
		{
				for(i=0;i<3;i++)
				{
				for(j=0;j<3;j++)
					{
						printf("|%c|",M[i][j]);
					}
				printf("\n");
				}
				do{fflush(stdin);
				printf("Inserisci le coordinate in cui mettere la X");
				scanf("%d",&k);
				scanf("%d",&h);
				if(k<=3 && k>=1)
				flag=1;
				if(h<=3 && h>=1)
				flag=1;
				if(M[k-1][h-1]!=32)
				flag=0;
				}
				while(flag==0);
				M[k-1][h-1]=88;
				
				system("cls");
	
		    if ( ((M[0][0]==88) && (M[0][1]==88) && (M[0][2]==88)) || ((M[1][0]==88) && (M[1][1]==88) && (M[1][2]==88)) || ((M[2][0]==88) && (M[2][1]==88) && (M[2][2]==88)) || ((M[0][0]==88) && (M[1][1]==88) && (M[2][2]==88)) || ((M[2][0]==88) && (M[1][1]==88) && (M[0][2]==88)) || ((M[0][0]==88) && (M[1][0]==88) && (M[2][0]==88)) || ((M[0][1]==88) && (M[1][1]==88) && (M[2][1]==88)) || ((M[0][2]==88) && (M[1][2]==88) && (M[2][2]==88))  )
			{			
							for(i=0;i<3;i++)
							{
							for(j=0;j<3;j++)
								{
									printf("|%c|",M[i][j]);
								}
							printf("\n");
							}
						printf ("Player 1 vince\n\n\n\n\n");
							return 0;			
					}
				
					
			
				
				if ( ((M[0][0]==79) && (M[0][1]==79) && (M[0][2]==79)) || ((M[1][0]==79) && (M[1][1]==79) && (M[1][2]==79)) || ((M[2][0]==79) && (M[2][1]==79) && (M[2][2]==79)) || ((M[0][0]==79) && (M[1][1]==79) && (M[2][2]==79)) || ((M[2][0]==79) && (M[1][1]==79) && (M[0][2]==79)) || (M[0][0]==79) && (M[2][0]==79) && (M[1][0]==79) || ((M[0][1]==79) && (M[1][1]==79) && (M[2][1]==79)) || ((M[0][2]==79) && (M[1][2]==79) && (M[2][2]==79)) )	
				{
						for(i=0;i<3;i++)
						{
						for(j=0;j<3;j++)
							{
								printf("|%c|",M[i][j]);
							}
						printf("\n");
						}
					printf("Bot vince\n\n\n\n\n");
					return 1;	
				}	
					fflush(stdin);
		for(i=0;i<3;i++)
		{
			for(y=0;y<3;y++)
			{
				M1[i][y]=M[i][y];
			}
		}
		for(i=0;i<3;i++)
		{
			for(y=0;y<3;y++)
			{
				if(M1[i][y]==32)
				{
					M1[i][y]='O';
					if ( ((M1[0][0]==79) && (M1[0][1]==79) && (M1[0][2]==79)) || ((M1[1][0]==79) && (M1[1][1]==79) && (M1[1][2]==79)) || ((M1[2][0]==79) && (M1[2][1]==79) && (M1[2][2]==79)) || ((M1[0][0]==79) && (M1[1][1]==79) && (M1[2][2]==79)) || ((M1[2][0]==79) && (M1[1][1]==79) && (M1[0][2]==79)) || (M1[0][0]==79) && (M1[2][0]==79) && (M1[1][0]==79) || ((M1[0][1]==79) && (M1[1][1]==79) && (M1[2][1]==79)) || ((M1[0][2]==79) && (M1[1][2]==79) && (M1[2][2]==79)) )	
					{
						M[i][y]='O';
						y=3;
						i=3;
						n=0;
					}
				}		
			}
		}
		if(n!=0)
		{
			for(i=0;i<3;i++)
			{
				for(y=0;y<3;y++)
				{
					if(M1[i][y]==32)
					{
						M1[i][y]='X';
						if ( ((M1[0][0]=='X') && (M1[0][1]==88) && (M1[0][2]==88)) || ((M1[1][0]==88) && (M1[1][1]==88) && (M1[1][2]==88)) || ((M1[2][0]==88) && (M1[2][1]==88) && (M1[2][2]==88)) || ((M1[0][0]==88) && (M1[1][1]==88) && (M1[2][2]==88)) || ((M1[2][0]==88) && (M1[1][1]==88) && (M1[0][2]==88)) || (M1[0][0]==88) && (M1[2][0]==88) && (M1[1][0]==88) || ((M1[0][1]==88) && (M1[1][1]==88) && (M1[2][1]==88)) || ((M1[0][2]==88) && (M1[1][2]==88) && (M1[2][2]==88)) )	
						{
							M[i][y]='O';
							y=3;
							i=3;
							n=0;
						}
					}		
				}
			}
		}
		if ( ((M[0][0]==88) && (M[0][1]==88) && (M[0][2]==88)) || ((M[1][0]==88) && (M[1][1]==88) && (M[1][2]==88)) || ((M[2][0]==88) && (M[2][1]==88) && (M[2][2]==88)) || ((M[0][0]==88) && (M[1][1]==88) && (M[2][2]==88)) || ((M[2][0]==88) && (M[1][1]==88) && (M[0][2]==88)) || ((M[0][0]==88) && (M[1][0]==88) && (M[2][0]==88)) || ((M[0][1]==88) && (M[1][1]==88) && (M[2][1]==88)) || ((M[0][2]==88) && (M[1][2]==88) && (M[2][2]==88))  )
			{			
							for(i=0;i<3;i++)
							{
							for(j=0;j<3;j++)
								{
									printf("|%c|",M[i][j]);
								}
							printf("\n");
							}
						printf ("Player 1 vince\n\n\n\n\n");
							return 0;			
					}
				
					
			
				
				if ( ((M[0][0]==79) && (M[0][1]==79) && (M[0][2]==79)) || ((M[1][0]==79) && (M[1][1]==79) && (M[1][2]==79)) || ((M[2][0]==79) && (M[2][1]==79) && (M[2][2]==79)) || ((M[0][0]==79) && (M[1][1]==79) && (M[2][2]==79)) || ((M[2][0]==79) && (M[1][1]==79) && (M[0][2]==79)) || (M[0][0]==79) && (M[2][0]==79) && (M[1][0]==79) || ((M[0][1]==79) && (M[1][1]==79) && (M[2][1]==79)) || ((M[0][2]==79) && (M[1][2]==79) && (M[2][2]==79)) )	
				{
						for(i=0;i<3;i++)
						{
						for(j=0;j<3;j++)
							{
								printf("|%c|",M[i][j]);
							}
						printf("\n");
						}
					printf("Bot vince\n\n\n\n\n");
					return 1;	
				}
		/*if(n!=1)
		{
			while(M[n][t]==32)
			{
			fflush(stdin);
			n=rand()%3;
			t=rand()%3;
			}
			fflush(stdin);
			M[n][t]='O';
		}*/
	 	}
	}
}


int battnavalebot()
{
	int s,h,p,flag,Flag1,n,u=2,t,ban=0;
	char k;
	int cb=0,CP=0;
	system("cls");
	srand(time(0));
	while(n>2 || n<1)
	{
		printf("Difficolta bot:\n1-Facile\n2-Difficile");
		scanf("%d",&n);
	}
	
				for(i=0;i<11;i++)
				{
					for(j=0;j<11;j++)
					{
						M1[i][j]=32;
					}
					
				}
				
				for(i=0;i<11;i++)
				{
					for(j=0;j<11;j++)
					{
						M2[i][j]=32;
					}
					
				}
			
				for(i=0;i<11;i++)
				{
					for(j=0;j<11;j++)
					{
						B2[i][j]=32;
					}
					
				}
				
				for(i=0;i<11;i++)
				{
					for(j=0;j<11;j++)
					{
						B1[i][j]=32;
					}
					
				}
	
	for(i=1;i<11;i++)
	{
		M2[0][i]=64+i;
	}
	
	for(i=1;i<10;i++)
	{
		M2[i][0]=48+i;
	}
	M2[10][0]='0';
	
	for(i=1;i<11;i++)
	{
		M1[0][i]=64+i;
	}
	
	for(i=1;i<10;i++)
	{
		M1[i][0]=48+i;
	}
	M1[10][0]='0';
	
	for(i=1;i<11;i++)
	{
		B1[0][i]=64+i;
	}
	
	for(i=1;i<10;i++)
	{
		B1[i][0]=48+i;
	}
	B1[10][0]='0';
	
	for(i=1;i<11;i++)
	{
		B2[0][i]=64+i;
	}
	
	for(i=1;i<10;i++)
	{
		B2[i][0]=48+i;
	}
	B2[10][0]='0';

	
	
	
	
	for(p=0;p<2;p++)
	{	
		if(p==0)
		{int po,h1,k1;
		system("cls");
										printf("Inizia player 1\n");
										
										for(i=0;i<11;i++)
											{
												for(j=0;j<11;j++)
												{
													printf("|%c|",B1[i][j]);
												}
												printf("\n");
											}
								
									
										printf("Nave da posizionare:sottomarino\n");
										do{fflush(stdin);
										printf("Inserisci la posizione in cui vuoi inserire la nave:");
										scanf("%c",&k);
										scanf("%d",&h);
										if(k>=65 && k<=74)
										Flag1=1;
										if(h>=49 && h<=57)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										{
											printf("Casella gia occupata");
											Flag1=0;
										}
										}while(Flag1==0);
										B1[h-4][k-20]='-';
										
										k1=k;
										h1=h;
										do{fflush(stdin);
										printf("Inserisci la posizione in cui vuoi inserire il secondo pezzo della nave:");
										scanf("%c",&k);
										scanf("%d",&h);
										if(k>=65 && k<=74)
										Flag1=1;
										if(h>=49 && h<=57)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										Flag1=0;
										if(k1-k==1)
										Flag1=1;
										if(k1-k==-1)
										Flag1=1;
										if(h1-h==1)
										Flag1=1;
										if(h1-h==-1)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										{
											printf("Casella gia occupata");
											Flag1=0;
										}
										}while(Flag1==0);
										B1[h-4][k-20]='-';
										k1=k;
										h1=h;
										do{fflush(stdin);
										printf("Inserisci la posizione in cui vuoi inserire il terzo pezzo della nave:");
										scanf("%c",&k);
										scanf("%d",&h);
										if(k>=65 && k<=74)
										Flag1=1;
										if(h>=49 && h<=57)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										Flag1=1;
										if(k1-k==1)
										Flag1=1;
										if(k1-k==-1)
										Flag1=1;
										if(h1-h==1)
										Flag1=1;
										if(h1-h==-1)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										{
											printf("Casella gia occupata");
											Flag1=0;
										}
										}while(Flag1==0);
										
										B1[h-4][k-20]='-';
											system("cls");
										for(i=0;i<11;i++)
											{
												for(j=0;j<11;j++)
												{
													printf("|%c|",B1[i][j]);
												}
												printf("\n");
											}
											
									
									
									
										printf("Nave da posizionare:incrociatore\n");
										do{fflush(stdin);
										printf("Inserisci la posizione in cui vuoi inserire la nave:");
										scanf("%c",&k);
										scanf("%d",&h);
										if(k>=65 && k<=74)
										Flag1=1;
										if(h>=49 && h<=57)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										{
											printf("Casella gia occupata");
											Flag1=0;
										}
										}while(Flag1==0);
										B1[h-4][k-20]='-';
										k1=k;
										h1=h;
										do{fflush(stdin);
										printf("Inserisci la posizione in cui vuoi inserire il secondo pezzo della nave:");
										scanf("%c",&k);
										scanf("%d",&h);
										if(k>=65 && k<=74)
										Flag1=1;
										if(h>=49 && h<=57)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										Flag1=0;
										if(k1-k==1)
										Flag1=1;
										if(k1-k==-1)
										Flag1=1;
										if(h1-h==1)
										Flag1=1;
										if(h1-h==-1)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										{
											printf("Casella gia occupata");
											Flag1=0;
										}
										}while(Flag1==0);
										B1[h-4][k-20]='-';
										k1=k;
										h1=h;
										do{fflush(stdin);
										printf("Inserisci la posizione in cui vuoi inserire il terzo pezzo della nave:");
										scanf("%c",&k);
										scanf("%d",&h);
										if(k>=65 && k<=74)
										Flag1=1;
										if(h>=49 && h<=57)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										Flag1=0;
										if(k1-k==1)
										Flag1=1;
										if(k1-k==-1)
										Flag1=1;
										if(h1-h==1)
										Flag1=1;
										if(h1-h==-1)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										{
											printf("Casella gia occupata");
											Flag1=0;
										}
										}while(Flag1==0);
										B1[h-4][k-20]='-';
										k1=k;
										h1=h;
										do{fflush(stdin);
										printf("Inserisci la posizione in cui vuoi inserire il quarto pezzo della nave:");
										scanf("%c",&k);
										scanf("%d",&h);
										if(k>=65 && k<=74)
										Flag1=1;
										if(h>=49 && h<=57)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										Flag1=0;
										if(k1-k==1)
										Flag1=1;
										if(k1-k==-1)
										Flag1=1;
										if(h1-h==1)
										Flag1=1;
										if(h1-h==-1)
										Flag1=1;
										if(B1[h-4][k-20]!=32)
										{
											printf("Casella gia occupata");
											Flag1=0;
										}
										}while(Flag1==0);
										B1[h-4][k-20]='-';
											system("cls");
											for(i=0;i<11;i++)
												{
													for(j=0;j<11;j++)
													{
														printf("|%c|",B1[i][j]);
													}
													printf("\n");
												}	
									
									
								
											
											printf("Nave da posizionare:cacciatorpediniere\n");
											do{fflush(stdin);
											printf("Inserisci la posizione in cui vuoi inserire la nave:");
											scanf("%c",&k);
											scanf("%d",&h);
											if(k>=65 && k<=74)
											Flag1=1;
											if(h>=49 && h<=57)
											Flag1=1;
											if(B1[h-4][k-20]!=32)
											{
												printf("Casella gia occupata");
												Flag1=0;
											}
											}while(Flag1==0);
											B1[h-4][k-20]='-';
											k1=k;
											h1=h;
											
											do{fflush(stdin);
											printf("Inserisci la posizione in cui vuoi inserire il secondo pezzo della nave:");
											scanf("%c",&k);
											scanf("%d",&h);
											if(k>=65 && k<=74)
											Flag1=1;
											if(h>=49 && h<=57)
											Flag1=1;
											if(B1[h-4][k-20]!=32)
											Flag1=0;
											if(k1-k==1)
											Flag1=1;
											if(k1-k==-1)
											Flag1=1;
											if(h1-h==1)
											Flag1=1;
											if(h1-h==-1)
											Flag1=1;
											if(B1[h-4][k-20]!=32)
											{
												printf("Casella gia occupata");
												Flag1=0;
											}
											}while(Flag1==0);
											B1[h-4][k-20]='-';
											system("cls");
											for(i=0;i<11;i++)
													{
														for(j=0;j<11;j++)
														{
															printf("|%c|",B1[i][j]);
														}
														printf("\n");
													}
									
								
									printf("Nave da posizionare:portaerei\n");
									do{fflush(stdin);
									printf("Inserisci la posizione in cui vuoi inserire la nave:");
									scanf("%c",&k);
									scanf("%d",&h);
									if(k>=65 && k<=74)
									Flag1=1;
									if(h>=49 && h<=57)
									Flag1=1;
									if(B1[h-4][k-20]!=32)
										{
											printf("Casella gia occupata");
											Flag1=0;
										}
									}while(Flag1==0);
									B1[h-4][k-20]='-';
									k1=k;
									h1=h;
									do{fflush(stdin);
									printf("Inserisci la posizione in cui vuoi inserire il secondo pezzo della nave:");
									scanf("%c",&k);
									scanf("%d",&h);
									if(k>=65 && k<=74)
									Flag1=1;
									if(h>=49 && h<=57)
									Flag1=1;
									if(B1[h-4][k-20]!=32)
									Flag1=0;
									if(k1-k==1)
									Flag1=1;
									if(k1-k==-1)
									Flag1=1;
									if(h1-h==1)
									Flag1=1;
									if(h1-h==-1)
									Flag1=1;
									if(B1[h-4][k-20]!=32)
									{
										printf("Casella gia occupata");
										Flag1=0;
									}
									}while(Flag1==0);
									B1[h-4][k-20]='-';
									k1=k;
									h1=h;
									do{fflush(stdin);
									printf("Inserisci la posizione in cui vuoi inserire il terzo pezzo della nave:");
									scanf("%c",&k);
									scanf("%d",&h);
									if(k>=65 && k<=74)
									Flag1=1;
									if(h>=49 && h<=57)
									Flag1=1;
									if(B1[h-4][k-20]!=32)
									Flag1=0;
									if(k1-k==1)
									Flag1=1;
									if(k1-k==-1)
									Flag1=1;
									if(h1-h==1)
									Flag1=1;
									if(h1-h==-1)
									Flag1=1;
									if(B1[h-4][k-20]!=32)
									{
										printf("Casella gia occupata");
										Flag1=0;
									}
									}while(Flag1==0);
									B1[h-4][k-20]='-';
									k1=k;
									h1=h;
									do{fflush(stdin);
									printf("Inserisci la posizione in cui vuoi inserire il quarto pezzo della nave:");
									scanf("%c",&k);
									scanf("%d",&h);
									if(k>=65 && k<=74)
									Flag1=1;
									if(h>=49 && h<=57)
									Flag1=1;
									if(B1[h-4][k-20]!=32)
									Flag1=0;
									if(k1-k==1)
									Flag1=1;
									if(k1-k==-1)
									Flag1=1;
									if(h1-h==1)
									Flag1=1;
									if(h1-h==-1)
									Flag1=1;
									if(B1[h-4][k-20]!=32)
									{
										printf("Casella gia occupata");
										Flag1=0;
									}
									}while(Flag1==0);
									B1[h-4][k-20]='-';
									k1=k;
									h1=h;
									do{fflush(stdin);
									printf("Inserisci la posizione in cui vuoi inserire il quinto pezzo della nave:");
									scanf("%c",&k);
									scanf("%d",&h);
									if(k>=65 && k<=74)
									Flag1=1;
									if(h>=49 && h<=57)
									Flag1=1;
									if(B1[h-4][k-20]!=32)
									{
										printf("Casella gia occupata");
										Flag1=0;
									}
									}while(Flag1==0);
									B1[h-4][k-20]='-';
									
									for(i=0;i<11;i++)
											{
												for(j=0;j<11;j++)
												{
													printf("|%c|",B1[i][j]);
												}
												printf("\n");
											}
											system("cls");	
								}else{
									
									
										if(n==1)
										{
											for(i=2;i<6;i++)
											{	
												do{
													u=posnave(i);
												}while(u==1);
												
												
												
											}
												
										}
										
										
										if(n==2)
										{
											for(i=2;i<6;i++)
											{	
												do{
													u=posnave(i);
												}while(u==1);
												
												
												
											}
										}
													
									}

}
	
//	system("cls");	

	for(p=0;p<100;i++)
	{	

												for(i=0;i<11;i++)
												{
													for(j=0;j<11;j++)
													{
														printf("|%c|",M1[i][j]);
													}
													printf("\n");
												}
				
		
		do{fflush(stdin);
		printf("Player 1 Scegli la destinazione del missile");
		scanf("%c",&k);
		scanf("%d",&h);
		if(k>=65 && k<=74)
		Flag1=1;
		if(h>=49 && h<=57)
		Flag1=1;
		if(M1[h-4][k-20]!=32 )
		Flag1=0;
		}while(Flag1==0);
		
		if(B2[h-4][k-20]=='-')
		{B2[h-4][k-20]==32;
			printf("Nave colpita dal player\n");
			M1[h-4][k-20]='X';
			CP++;
		}else{B2[h-4][k-20]==32;
			printf("Nave non colpita dal player\n");
			M1[h-4][k-20]='O';
		}
		
		flag=0;	
		for(i=0;i<11;i++)
				{
					for(j=0;j<11;j++)
					{
						if(B2[i][j]==32)
						flag++;
					}
					
				}
		if(CP==14)
		{
			printf("Player 1 vince\n\n\n\n\n");
			return 0;
		}		
			int k,h;
		do{
			fflush(stdin);
			if(n==1)
			{
				h=rand()%10;
				k=rand()%10;
				h++;
				k++;
			if(M2[h][k]==32)
			Flag1=1;
			}
			
			if(n==2)
			{
				for(i=0;i<11;i++)
				{
					for(j=0;j<11;j++)
					{
						if(M2[i][j]=='X')
						{	ban=1;
							//t=controllom();
							if(M2[i][j+1]==32)
							{
								h=i;
								k=j+1;
								Flag1=1;
							}
							if(M2[i][j-1]==32)
							{
								h=i;
								k=j-1;
								Flag1=1;
							}
							if(M2[i-1][j]==32)
							{
								h=i-1;
								k=j;
								Flag1=1;
							}
							if(M2[i+1][j]==32)
							{
								h=i+1;
								k=j;
								Flag1=1;
							}
						}
					}
				}
				if(ban==0)
				{	
					h=rand()%10;
					k=rand()%10;
					h++;
					k++;
					if(M2[h][k]==32)
					Flag1=1;
				//	printf("%d %d\n",h,k);
				}
				
			}
			}while(Flag1==0);
			//printf("AAAA");
		//	printf("%d %d\n",h,k);
			if(B1[h][k]=='-')
			{
				B1[h][k]==32;
				printf("Nave colpita dal bot\n");
				
				cb++;
				M2[h][k]='X';
			}else{	
				B1[h][k]==32;
				printf("Nave non colpita dal bot\n");
				M2[h][k]='O';
			}
			
		flag=0;	
				for(i=0;i<11;i++)
				{
					for(j=0;j<11;j++)
					{
						if(B1[i][j]==32)
						flag++;
					}
					
				}
		if(cb==14)
		{
			printf("BOT vince\n\n\n\n\n");
			return 1;
		}		
		
		
	}return 2;
}

int posnave(int n)
{
	int h,k,i,y;
	n=n-1;
	if(n==1)
	{
		h=rand()%10;
		k=rand()%10;
		
		
			if(B2[h+1][k+1]==32 && B2[h+2][k+1]==32 && B2[h+3][k+1]==32 && B2[h][k+1]==32)
			{
				B2[h+1][k+1]='-';
				B2[h+1+1][k+1]='-';
				B2[h][k+1]='-';
				B2[h+3][k+1]='-';
				return 10;
			}
			if(B2[k+1][h+1]==32 && B2[k+1][h+2]==32 && B2[k+1][h+3]==32 && B2[k+1][h]==32)
			{
				B2[k+1][h+1]='-';
				B2[k+1][h+2]='-';
				B2[k+1][h+3]='-';
				B2[k+1][h]='-';
				return 10;
			}
	}
	
	if(n==2)
	{
		h=rand()%10;
		k=rand()%10;
			if(B2[h+1][k+1]==32 && B2[h+2][k+1]==32)
			{
				B2[h+1][k+1]='-';
				B2[h+1+1][k+1]='-';
				return 10;
			}
			
			if(B2[k+1][h+1]==32 && B2[k+1][h+2]==32 )
			{
				B2[k+1][h+1]='-';
				B2[k+1][h+2]='-';
				return 10;
			}	
	}
	
	if(n==3)
	{
		h=rand()%10;
		k=rand()%10;
			if(B2[h+1][k+1]==32 && B2[h+2][k+1]==32 && B2[h+3][k+1]==32)
			{
				B2[h+1][k+1]='-';
				B2[h+1+1][k+1]='-';
				B2[h+3][k+1]='-';
				return 10;
			}
			
			if(B2[k+1][h+1]==32 && B2[k+1][h+2]==32 && B2[k+1][h+3]==32)
			{
				B2[k+1][h+1]='-';
				B2[k+1][h+2]='-';
				B2[k+1][h+3]='-';
				return 10;
			}
	}
	
	if(n==4)
	{
		h=rand()%10;
		k=rand()%10;
			if(B2[k+1][h+1]==32 && B2[k+1][h+2]==32 && B2[k+1][h+3]==32 && B2[k+1][h]==32 && B2[k+1][h-1]==32)
			{
				B2[k+1][h+1]='-';
				B2[k+1][h+2]='-';
				B2[k+1][h+3]='-';
				B2[k+1][h]='-';
				B2[k+1][h-1]='-';
				return 10;
			}
			
			if(B2[h+1][k+1]==32 && B2[h+2][k+1]==32 && B2[h+3][k+1]==32 && B2[h][k+1]==32 && B2[h-1][k+1]==32)
			{
				B2[h+1][k+1]='-';
				B2[h+1+1][k+1]='-';
				B2[h][k+1]='-';
				B2[h+3][k+1]='-';
				B2[h-1][k+1]='-';
				return 10;
			}
			
			
	}
	
	return 1;
}
