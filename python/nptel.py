def expanding(l):
	#a=[abs(l[i+1]-l[i]) for i in range(len(l)-1)]
  a=[]
  for i in range(len(l)-1):
  	a.append(abs(l[i+1]-l[i]))
  for i in range(len(a)-1):
    if(a[i+1]>a[i]):
      continue
    else:
      return False
  return True
def accordian(l):
  a=[]
  for i in range(len(l)-1):
    a.append(abs(l[i+1]-l[i]))
  for i in range (len(a)-1):
    if(a[1]>a[0]):
      if(i%2==1 and a[i+1]>a[i]):
        continue
      elif(i%2==0 and a[i+1]<a[i]):
	      continue
      else:
        return False
	  else:
      if(i%2==1 and a[i+1]<a[i]):
        continue
      elif(i%2==0 and a[i+1]>a[i]):
        continue
      else:
        return False
  return True
          
          