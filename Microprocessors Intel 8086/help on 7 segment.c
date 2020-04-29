#include<reg51.h>
void main(){
	unsigned char seg[4]={0x76,0x79,0x38,0x73};
	unsigned char x;
	unsigned int i;
		P1=0x00;
	while(1){
		for (x=0;x<4; x++){
				P1=~seg[x];
				for(i=0;i<60000;i++);
		}
	}
}