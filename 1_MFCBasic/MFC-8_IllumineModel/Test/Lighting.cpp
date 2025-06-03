// Lighting.cpp: implementation of the CLighting class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Test.h"
#include "Lighting.h"
#include "math.h"
#define  PI  3.14159265
#define  MIN(a,b)  ((a<b)?(a):(b))
#define  MAX(a,b)  ((a>b)?(a):(b))
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLighting::CLighting()
{
	LightNum=1;
	Light=new CLight[LightNum];
	Ambient=CRGB(0.3,0.3,0.3);//环境光恒定不变
}

CLighting::~CLighting()
{
	if(Light)
	{
		delete []Light;
		Light=NULL;
	}
}
void CLighting::SetLightNumber(int lnum)
{
	if(Light)
	{
		delete []Light;
	}
	LightNum=lnum;
	Light=new CLight[lnum];
}

CLighting::CLighting(int lnum)
{
	LightNum=lnum;
	Light=new CLight[lnum];
	Ambient=CRGB(0.3,0.3,0.3);
}

CRGB CLighting::Lighting(CP3 ViewPoint,CP3 Point,CVector Normal,CMaterial *pMaterial)
{	
	CRGB LastC=pMaterial->M_Emit;	
	for(int i=0;i<LightNum;i++)
	{	
		if(Light[i].L_OnOff)
		{		
			CRGB InitC;
			InitC.red=0,InitC.green=0,InitC.blue=0;
			CVector VL(Point,Light[i].L_Position);
			double d=VL.Mag();
			VL=VL.Normalize();
			CVector VN=Normal;
			VN=VN.Normalize();			
			double CosTheta=MAX(Dot(VL,VN),0);			
			InitC.red+=Light[i].L_Diffuse.red*pMaterial->M_Diffuse.red*CosTheta;
			InitC.green+=Light[i].L_Diffuse.green*pMaterial->M_Diffuse.green*CosTheta;
			InitC.blue+=Light[i].L_Diffuse.blue*pMaterial->M_Diffuse.blue*CosTheta;
			
			CVector VV(Point,ViewPoint);
			VV=VV.Normalize();
			CVector VH=(VL+VV)/(VL+VV).Mag();
			double nHN=pow(MAX(Dot(VH,VN),0),pMaterial->M_n);
			InitC.red+=Light[i].L_Specular.red*pMaterial->M_Specular.red*nHN;
			InitC.green+=Light[i].L_Specular.green*pMaterial->M_Specular.green*nHN;
			InitC.blue+=Light[i].L_Specular.blue*pMaterial->M_Specular.blue*nHN;	
			
			double c0=Light[i].L_C0;
			double c1=Light[i].L_C1;
			double c2=Light[i].L_C2;			
			double f=(1.0/(c0+c1*d+c2*d*d));
			f=MIN(1.0,f);		
			LastC+=InitC*f;		
		}
		else
			LastC+=Point.c;		
	}
	
	LastC+=Ambient*pMaterial->M_Ambient;
	LastC.Normalize();		
	return LastC;
}	
