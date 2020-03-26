clear all;
close all;
x=linspace(0,2*pi,200);
plot(sin(x)+1,cos(x),"r^")
plot(sin(x),cos(x),"b-")
xlabel("x axis")
ylabel("y axis")
title("Title")