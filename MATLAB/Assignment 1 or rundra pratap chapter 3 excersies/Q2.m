a=[2 6; 3 9];
b=[1 2; 3 4];
c=[-5 5; 5 3];
if (a+b)==(b+a)
    disp("matrix additon is commutative");
else
    disp("matrix addition is not commutative");
end

if ((a+b)+c) == (a+(b+c))
    disp("matrix addition is associative");
else
    disp("matrix addition is not associative");
end

if (5*(a+b) == (5*a + 5*b))
    disp("it is scalar distributive");
else
    disp("it is not scalar distributive");
end

if ((a+b)*c == (a*c + b*c))
    disp("matrix multiplication is distributive");
else
    disp("matrix multiplication is not distributive");
end

if (a*b == b*a)
    disp("matrix multiplication is commutative");
else
    disp("matrix multiplication is not commutative");
end