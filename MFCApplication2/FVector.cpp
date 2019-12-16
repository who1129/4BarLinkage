
#include "stdafx.h"
#include "FVector.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

NCB_CFVector::NCB_CFVector()
{

}

NCB_CFVector::~NCB_CFVector()
{
}

void NCB_CFVector::NCB_vSetX(float x)
{
	m_fData[0] = x;
}

void NCB_CFVector::NCB_vSetY(float y)
{
	m_fData[1] = y;
}

void NCB_CFVector::NCB_vSetZ(float z)
{
	m_fData[2] = z;
}

void NCB_CFVector::NCB_vSet(float x, float y, float z)
{
	m_fData[0] = x;
	m_fData[1] = y;
	m_fData[2] = z;
}

float* NCB_CFVector::NCB_oGetDataX(void)
{
	return &(m_fData[0]);
}

float* NCB_CFVector::NCB_oGetDataY(void)
{
	return &(m_fData[1]);
}

float* NCB_CFVector::NCB_oGetDataZ(void)
{
	return &(m_fData[2]);
}

float* NCB_CFVector::NCB_oGetData(void)
{
	return m_fData;
}
float* NCB_CFVector::NCB_oGetNormal( void )
{
	float fd;
	fd = m_fData[0] * m_fData[0] + m_fData[1] * m_fData[1] + m_fData[2] * m_fData[2];
	fd = sqrt( fd );
	m_fNormal[0] = m_fData[0] / fd;
	m_fNormal[1] = m_fData[1] / fd;
	m_fNormal[2] = m_fData[2] / fd;

	return m_fNormal;

}
