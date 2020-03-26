clear all;
close all;
clc;
a=[0,1];
for i=3:10
    a(i)=a(i-2)+a(i-1);
end
disp(a)