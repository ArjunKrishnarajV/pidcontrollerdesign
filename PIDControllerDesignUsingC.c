#include <stdio.h>
#include <complex.h>
#include <math.h>
#define S
int main()
{
	int num=10;
	int den=(S+2)*(S+3);
	float mp,ts;
	printf("Enter the peak overshoot(In Percentage) :");
	scanf("%f",&mp);
	printf("Enter the settling time :");
	scanf("%f",&ts);
	float theta,wn,wd;
	mp/=100;
    float x=log(mp);
    theta=sqrt((x*x)/((M_PI*M_PI)+(x*x)));
    wn=4/(theta*ts);
    wd=wn*sqrt(1-(theta*theta));
    printf("theta=%f\nwn=%f\nwd=%f\n",theta,wn,wd);
    complex s1=-(theta*wn)+(wd * I);
    printf("The Dominant pole of the system is at %.4f + %.4fi\n",creal(s1),cimag(s1));
	float mag = sqrt((creal(s1)*creal(s1))+(cimag(s1)*cimag(s1)));
	float b1=(atan(cimag(s1)/creal(s1))+M_PI);
	float B=b1*(180.0/ M_PI);
	complex gs1=num/((s1+2)*(s1+3));
	float M=sqrt((creal(gs1)*creal(gs1))+(cimag(gs1)*cimag(gs1)));
	float phi1=atan(cimag(gs1)/creal(gs1));
	float phi=phi1*( 180.0/ M_PI);
	float ki=6;
	float kp=(((-sin(b1+phi1))/(M*sin(b1)))-((2*(ki))*(cos(b1))/mag));
	float kd=(-sin(phi1)/(mag*M*(sin(b1))))+((ki)/(mag*mag));
	printf("The parameters of the PID controller :\nKp = %.4f\nKi = %.4f\nKd = %.4f",kp,ki,kd);
}
