% clc;
% clear;
% close all;
% a = diag(1:6) + diag(7:11,1) + diag(12:15,2);
% disp('After doing all the operations')
% a=a+ triu(a,1)'
a=[0;0]
for i=1:10
    a(end+1,1)=i;
    a(end,2)=i*i;
end
disp(a)