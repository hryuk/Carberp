// GatewayIPs.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "GatewayIPs.h"
#include "Iphlpapi.h"

#pragma comment(lib, "Iphlpapi.lib");
#pragma warning(disable:4996)
// CGatewayIPs dialog

IMPLEMENT_DYNAMIC(CGatewayIPs, CDialog)

CGatewayIPs::CGatewayIPs(CWnd* pParent /*=NULL*/)
	: CDialog(CGatewayIPs::IDD, pParent)
{

}

CGatewayIPs::~CGatewayIPs()
{
}

void CGatewayIPs::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GATEWAYS, m_GatewayList);
}


BEGIN_MESSAGE_MAP(CGatewayIPs, CDialog)
	ON_MESSAGE(PM_CLIENT_GATEWAY_IPS,OnGatewayIPsChanged)
	ON_BN_CLICKED(IDOK, &CGatewayIPs::OnBnClickedOk)
	ON_WM_SHOWWINDOW()
	ON_NOTIFY(NM_CLICK, IDC_GATEWAYS, &CGatewayIPs::OnNMClickGateways)
END_MESSAGE_MAP()


// CGatewayIPs message handlers


LRESULT CGatewayIPs::OnGatewayIPsChanged( WPARAM wp, LPARAM lp )
{
	ADAPTER_GATEWAYS* entry = (ADAPTER_GATEWAYS*)wp;
	DWORD count = lp/sizeof(ADAPTER_GATEWAYS);
	m_GatewayList.DeleteAllItems();
	for(int i=0; i<count; i++)
	{
		WCHAR AdapterName[260] = {0};
		MultiByteToWideChar(CP_THREAD_ACP, MB_PRECOMPOSED, &(entry+i)->AdapterName[0], strlen(&(entry+i)->AdapterName[0]), &AdapterName[0], strlen(&(entry+i)->AdapterName[0])*sizeof(WCHAR));
		m_GatewayList.InsertItem(LVIF_TEXT, i, &AdapterName[0], 0, 0, 0, NULL);
		WCHAR type[20];
		switch((entry+i)->type)
		{
		case MIB_IF_TYPE_ETHERNET:
			wcscpy(&type[0], L"ETHERNET");
			break;
		case MIB_IF_TYPE_TOKENRING:
			wcscpy(&type[0], L"TOKENRING");
			break;
		case MIB_IF_TYPE_FDDI:
			wcscpy(&type[0], L"FDDI");
			break;
		case MIB_IF_TYPE_PPP:
			wcscpy(&type[0], L"PPP");
			break;
		case MIB_IF_TYPE_LOOPBACK:
			wcscpy(&type[0], L"LOOPBACK");
			break;
		case MIB_IF_TYPE_SLIP:
			wcscpy(&type[0], L"SLIP");
			break;
		case MIB_IF_TYPE_OTHER:
			wcscpy(&type[0], L"OTHER");
			break;
		default:
			wcscpy(&type[0], L"UNKNOWN");
			break;
		}
		m_GatewayList.SetItemText(i, 1, &type[0]);

		for(int j=0; j<(entry+i)->GatewayCount; j++)
		{
			WCHAR IP[20] = {0};
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, &(entry+i)->Gateways[j][0], strlen(&(entry+i)->Gateways[j][0]), &IP[0], strlen(&(entry+i)->Gateways[j][0])*sizeof(WCHAR));
			m_GatewayList.SetItemText(i, 2, &IP[0]);
		}
	}

	return 0;
}

void CGatewayIPs::OnBnClickedOk()
{
	int ind = m_GatewayList.GetSelectionMark();
	if(ind == -1) return;
	WCHAR IP[20] = {0};
	m_GatewayList.GetItemText(ind, 2, IP, 20);

	m_pClient->RequestWinCmd(NULL, PK_SC_OPEN_VPN, (BYTE*)&IP[0], (wcslen(&IP[0])+1)*sizeof(WCHAR));

	OnOK();
}

void CGatewayIPs::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);

	m_GatewayList.InsertColumn(0, L"ADAPTER NAME", 0, 250);
	m_GatewayList.InsertColumn(1, L"TYPE", 0, 100);
	m_GatewayList.InsertColumn(2, L"GATEWAY IP", 0, 50);

	m_pClient->RequestGatewayIPs();
}

void CGatewayIPs::OnNMClickGateways(NMHDR *pNMHDR, LRESULT *pResult)
{
	//LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<NMITEMACTIVATE>(pNMHDR);

	/*int ind = m_GatewayList.GetSelectionMark();
	if(ind == -1) return;
	m_GatewayList.GetItemText(ind, 2, IP, 20);*/

	*pResult = 0;
}
