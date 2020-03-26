# -*- coding: utf-8 -*-
"""
Created on Thu Feb 20 21:45:26 2020

@author: suhru
"""
def overlap(a,n):
  overlap_cnt,indexi=0,0
  for i in range(n-1):
    if(a[i][1]>=a[i+1][0]):
      indexi=i
      overlap_cnt+=1;
  return overlap_cnt,indexi
c,n,k=map(int,input().split())
a=sorted([list(map(int,(input().split()))) for i in range(n)])
total=sum([a[i][1]-a[i][0]+1 for i in range(n)])
if total>c:
  print('Bad')
else:
  overlapflag=overlap(a,len(a))
  #print(overlap,overlapflag,total,sep='\n')
  if(overlapflag[0]>2):
    print('Bad')
  elif(overlap(a,len(a))[0]==0):
    print('Good')
  else:
    if(k==0):
      print('Bad')
    else:
      flag=1
      leng=a[overlapflag[1]+1][0]-a[overlapflag[1]][1]+1
      temp=(a[overlapflag[1]][0],a[overlapflag[1]][1])
      for i in range(n):
        a[overlapflag[1]][0],a[overlapflag[1]][1]=a[overlapflag[1]][0]-leng,a[overlapflag[1]][1]-leng
        if(a[overlapflag[1]][0]<0):
          break;
        if(overlap(a,overlapflag[1]+1)[0]==0):
          print('Good')
          flag=0
          break;
      if(flag==1):
        a[overlapflag[1]][0],a[overlapflag[1]][1]=temp
        for i in range(n):
          a[overlapflag[1]][0],a[overlapflag[1]][1]=a[overlapflag[1]][0]+leng,a[overlapflag[1]][1]+leng
          if(a[overlapflag[1]][1]<c):
            break;
          if(overlap(a,len(a))[0]==0):
            print('Good')
            flag=0
            break; 
        if(flag==1):
          print('Bad')
#Didnt consider a case when there is situation where an adjustment is not possbile
