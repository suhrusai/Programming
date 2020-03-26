clc;
clear;
close all;
a=[2,6;3,9];
b=[1,2;3,4];
c=[-5,5;5,3];
g=zeros([6,6]);
g(1:2,1:2)=a;
g(3:4,3:4)=b;
g(5:6,5:6)=c;
%Deleting a row and column
g=g(1:end-1,1:end-1);
disp('g after deleting a row and column')
disp(g)
%submatrix 4x4 matrix
submatrix=g(1:4,1:4);
disp('Submatrix is:')
disp(submatrix)
% Replacing g(5,5)=4
g(5,5)=4;
disp('after replacement of g(5,5)=4');
disp(g);
disp(['Output for g(13):'])
disp(['g(13)=',num2str(g(13))])
g(12,1)=1;
disp('g After g(12,1)=')
disp(g)