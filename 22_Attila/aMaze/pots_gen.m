clear all;
close all;
clc;

width=145;
height=145;
pots_value_max=1000;

fid = fopen(strcat('pots.c'), 'w');
fprintf(fid, '#include "pots.h"\r\n');
fprintf(fid, '\r\n');
fclose(fid);
fid = fopen(strcat('pots.h'), 'w');
fprintf(fid, '#ifndef POTS_H_INCLUDED\r\n');
fprintf(fid, '#define POTS_H_INCLUDED\r\n');
fprintf(fid, '\r\n');
fprintf(fid, '#include "aMaze.h"\r\n');
fprintf(fid, '\r\n');
fprintf(fid, '#define pots_value_max %.0f\r\n',pots_value_max);
fprintf(fid, '\r\n');
fclose(fid);

%% ones

a=ones(height,width);
a(1,1)=0;
pots_saver(a,'ones',pots_value_max);

%% 2dsin

yb=-pi/2;
ye=pi/2;

xb=-pi/2;
xe=pi/2;

y=yb:((ye-yb)/(height-1)):ye;
x=xb:((xe-xb)/(width-1)):xe;

a=sin(y'*x);
pots_saver(a,'2dsin',pots_value_max);

%% cosxsin

yb=-pi/1.5;
ye=pi/1.5;

xb=-pi/1.5;
xe=pi/1.5;

y=yb:((ye-yb)/(height-1)):ye;
x=xb:((xe-xb)/(width-1)):xe;

a=cos(y')*sin(x);
pots_saver(a,'cosxsin',pots_value_max);

%% xyramp

yb=1;
ye=1000;

xb=1;
xe=1000;

y=yb:((ye-yb)/(height-1)):ye;
x=xb:((xe-xb)/(width-1)):xe;

a=y'*x;
pots_saver(a,'xyramp',pots_value_max);

%% yramp

yb=1;
ye=1000;

y=yb:((ye-yb)/(height-1)):ye;

a=y'*ones(1,width);
pots_saver(a,'yramp',pots_value_max);

%% exyramp

yb=-2;
ye=2;
y=yb:((ye-yb)/(height-1)):ye;

xb=-2;
xe=2;
x=xb:((xe-xb)/(width-1)):xe;

a=exp(y')*exp(x);
pots_saver(a,'exyramp',pots_value_max);

%% saddle

yb=0.1;
ye=-0.1;
y=yb:((ye-yb)/(height-1)):ye;

xb=-0.3;
xe=0.3;
x=xb:((xe-xb)/(width-1)):xe;

a=exp((y').^3)*exp(x.*y);
pots_saver(a,'saddle',pots_value_max);

%% logflower

yb=1;
ye=0.0100;
hd2=height/2;
y=cat(2,yb:((ye-yb)/hd2):ye,ye:((yb-ye)/(height-1-hd2)):yb);

xb=1;
xe=0.0100;
wd2=width/2;
x=cat(2,xb:((xe-xb)/wd2):xe,xe:((xb-xe)/(width-1-wd2)):xb);

a=log(y'*x);
pots_saver(a,'logflower',pots_value_max);

%% logpeak

yb=1;
ye=0.0100;
hd2=height/2;
y=cat(2,yb:((ye-yb)/hd2):ye,ye:((yb-ye)/(height-1-hd2)):yb);

xb=1;
xe=0.0100;
wd2=width/2;
x=cat(2,xb:((xe-xb)/wd2):xe,xe:((xb-xe)/(width-1-wd2)):xb);

a=-log(y'*x);
pots_saver(a,'logpeak',pots_value_max);


%% file endings
fid = fopen(strcat('pots.h'), 'a');
fprintf(fid, '\r\n');
fprintf(fid, '#endif // POTS_H_INCLUDED\r\n');
fclose(fid);
