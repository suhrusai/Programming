clear all;
csemarks=[0,0,0;1,2,3;4,5,6;7,8,9;10,11,12;12,14,15];
daamarks=[100,100,100,100,100,99];
%csemarks=[csemarks,daamarks'];

%scaling the daamarks
%daamarks=daamarks*0.5;
%csemarks([1:6],4)=daamarks';
csemarks([1:6],8)=daamarks';
%disp(csemarks);

%extecting marjks of one student

% disp(csemarks(2,2:3));
%mean(csemarks(2,:));
sum(csemarks,1)
sum(csemarks,2)