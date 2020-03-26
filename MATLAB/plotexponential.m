clear all;
close all;
x=linspace(0,4*pi,100);
plot(x,exp(-0.5.*x).*sin(x),"bo-")
xlabel("0 to 4*pi")
ylabel("sin(x)")
title("Blue Dotted Sine Grpah")