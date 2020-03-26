clear;

%Commment: While loop to print elements till 200%

fib=[0,1];
while fib(end-1)+fib(end)<200
    fib(end+1)=fib(end-1)+fib(end);    
end
disp(fib)