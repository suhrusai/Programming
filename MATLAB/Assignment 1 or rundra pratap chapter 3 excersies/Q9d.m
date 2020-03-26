clc;
clear all;
close all;
x= linspace(-1*pi,pi,100);
y=linspace(-2,2,100);
z = ((x.^2)./2)+1-cos(y);
surfc(x,y,((x.^2)./2)+1-cos(y'))