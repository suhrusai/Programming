%% Decleration of varibles
a=1;
b=2;
integrated=inline('x-(x^2/2)+x*log(x)');
equation=inline('2-x+log(x)');
%% Actaul value calculation and Trapzoidal Rule 
actualval=integrated(b)-integrated(a);
trapozoidalruleval=((b-a)/2)*(equation(a)+equation(b));
trapozoidalrulevalerr=abs(trapozoidalruleval-actualval)/actualval*100
disp(['Actual val    ','Got val','    Error'])
disp([actualval,trapozoidalruleval,trapozoidalrulevalerr])
%% Simsons 1/3rd rule 
h=(b-a)/2;
simpsons13rule=(h/3)*(equation(a)+4*equation(a+h)+equation(a+2*h));
simpsons13rulerr=abs(simpsons13rule-actualval)/actualval*100;
disp([actualval,simpsons13rule,simpsons13rulerr])
%% Simsons 3/8rd rule 
h=(b-a)/3;
simpsons38rule=(3*h/8)*(equation(a)+3*equation(a+h)+3*equation(a+2*h)+equation(a+3*h));
simpsons38rulerr=abs(simpsons13rule-actualval)/actualval*100;
disp([actualval,simpsons38rule,simpsons38rulerr])