clc;
clear;
close all;
a=ones(20);
a(6:15,6:15)=zeros(10)
subplot(1,2,1);
spy(a);
title('First spy(a) output');
a(1:5,end-4:end)=zeros(5);
a(end-4:end,1:5)=zeros(5);
subplot(1,2,2);
spy(a);
title('Second spy(a) output');
