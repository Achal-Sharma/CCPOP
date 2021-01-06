#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<math.h>

int rando(int i);

void main()
{
	int i, j, wu=1, wl=0, temp, randv;
	double rc[10], nm=10, z[10], a[10], w[10], rp[10], del1, del2, temp2;
	double delq, r, rand_mut, wc[10], wcd[10], wizi=0, cizi=0, rand_asset;

	clrscr();

	randv = rando(11);

	if(randv==0)
	{
		printf("\n\tTry Again...");
		getch();
		exit(0);
	}

	rand_mut = rando(11)/10.00;

	for (i=0;i<10;i++)             //Filling up z[i]
	{
		if (i<randv)
		{
			z[i] = 1;
		}
		else
		{
			z[i] = 0;
		}
	}

	for (i = 0; i<10; i++)         //Shuffling up z[i]
	{
		for (j = 0; j<10; j = j+2)
		{
			temp = z[i];
			z[i] = z[j];
			z[j] = temp;
		}
	}

	printf("\tCurrent Parent Vector: ");

	for(i=0;i<10;i++)              //Assigning Weights and Assests
	{
		delay(1000);
		a[i] = rando(226);
		w[i] = rando(100)/100.00;
		rp[i] = (a[i]/100000.00) + w[i];
		printf("\n\t%f",rp[i]);
	}

	for(i=0; i<10; i++)
	{
		wizi = wizi + (w[i] * z[i]);
		cizi = cizi + (0.01 * z[i]);
	}

	printf("\n\n\tNew Parent Vector: ");

	for (i = 0; i < 10; i++)
	{
		if((rand_mut<=0.20)&&(rand_mut>=0.00))
		{
			del1 = (w[i] - wl) / (wu - wl);
			del2 = (wu - w[i]) / (wu - wl);

			delay(1000);

			r = rando(11)/10.00;

			if(r<=0.5)
			{
				delq = (double)pow((1.00-del1),(nm+1.00));
				delq = delq * (1.00-(2.00*r));
				delq = delq + (2.00*r);
				delq = (double)pow(delq,(1.00/(nm+1.00)));
			}
			else
			{
				delq = (double)pow((1.00-del2),(nm+1.00));
				delq = delq * (2.00*(r-0.5));
				delq = delq + (2.00*(1.00-r));
				delq = (double)pow(delq,(1.00/(nm+1.00)));
				delq = 1.00 - delq;
			}

			wc[i] = w[i] + (delq * (wu-wl));

			wcd[i] = wc[i] * z[i];
			wcd[i] = wcd[i] / wizi;
			temp2 = 0.99 * z[i];
			temp2 = temp2 - cizi;
			wcd[i] = wcd[i] * temp2;
			temp2 = 0.01 * z[i];
			wcd[i] = wcd[i] + temp2;

			rc[i] = (a[i]/100000.00) + wcd[i];
			rp[i] = rc[i];
			printf("\n\t%f",rc[i]);

		}

		else if((rand_mut>0.20)&&(rand_mut<=1.00))
		{
			del1 = (w[i] - wl) / (wu - wl);
			del2 = (wu - w[i]) / (wu - wl);

			delay(1000);

			r = rando(11)/10.00;
			rand_asset = rando(226)/(100000.00);

			if(r<=0.5)
			{
				delq = (double)pow((1.00-del1),(nm+1.00));
				delq = delq * (1.00-(2.00*r));
				delq = delq + (2.00*r);
				delq = (double)pow(delq,(1.00/(nm+1.00)));
			}
			else
			{
				delq = (double)pow((1.00-del2),(nm+1.00));
				delq = delq * (2.00*(r-0.5));
				delq = delq + (2.00*(1.00-r));
				delq = (double)pow(delq,(1.00/(nm+1.00)));
				delq = 1.00 - delq;
			}

			wc[i] = w[i] + (delq * (wu-wl));

			wcd[i] = wc[i] * z[i];
			wcd[i] = wcd[i] / wizi;
			temp2 = 0.99 * z[i];
			temp2 = temp2 - cizi;
			wcd[i] = wcd[i] * temp2;
			temp2 = 0.01 * z[i];
			wcd[i] = wcd[i] + temp2;

			rc[i] =  rand_asset + wcd[i];
			rp[i] = rc[i];
			printf("\n\t%f",rp[i]);
		}

	}
	printf("\n\n\tDone...");
	getch();
}

int rando(int i)
{
	int m;
	srand(time(NULL));
	m = rand() % i;
	return m;
};