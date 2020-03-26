clc;
clear;
close all;
x='t';
y='exp(-1*t./2).*sin(t)';
ezplot(x,y,[0,2*pi])
