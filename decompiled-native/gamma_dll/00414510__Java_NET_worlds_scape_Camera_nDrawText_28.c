// 00414510 _Java_NET_worlds_scape_Camera_nDrawText@28 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _Java_NET_worlds_scape_Camera_nDrawText_28
               (int *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
               int param_6,uint param_7)

{
  char cVar1;
  int iVar2;
  LPCSTR lpString;
  int iVar3;
  HFONT h;
  HGDIOBJ pvVar4;
  int *piVar5;
  LOGFONTA *pLVar6;
  LPCSTR pCVar7;
  HDC local_58;
  tagPOINT local_54;
  LOGFONTA local_4c;
  
                    /* 0x14510  197  _Java_NET_worlds_scape_Camera_nDrawText@28 */
  if (DAT_0048948c == 0) {
    return;
  }
  piVar5 = (int *)0x0;
  local_58 = (HDC)FUN_00418130(DAT_0048948c);
  if (local_58 == (HDC)0x0) {
    piVar5 = (int *)FUN_00418180(DAT_0048948c);
    if (piVar5 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar5 + 0x44))(piVar5,&local_58);
      if (iVar2 == 0) goto LAB_00414570;
    }
    return;
  }
LAB_00414570:
  lpString = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  SaveDC(local_58);
  SetGraphicsMode(local_58,2);
  ModifyWorldTransform(local_58,(XFORM *)0x0,1);
  SetViewportOrgEx(local_58,0,0,(LPPOINT)0x0);
  SetWindowOrgEx(local_58,0,0,(LPPOINT)0x0);
  iVar2 = GetDeviceCaps(local_58,6);
  iVar3 = GetDeviceCaps(local_58,10);
  local_54.x = 0;
  local_54.y = (LONG)ROUND((float10)(int)ROUND((((float)iVar3 * (float)_DAT_0046fca8) / (float)iVar2
                                               ) * (float)(param_6 * 10) * _DAT_0046fcb0));
  DPtoLP(local_58,&local_54,1);
  pLVar6 = &local_4c;
  for (iVar2 = 0xf; iVar2 != 0; iVar2 = iVar2 + -1) {
    pLVar6->lfHeight = 0;
    pLVar6 = (LOGFONTA *)&pLVar6->lfWidth;
  }
  local_4c.lfHeight = -(int)ROUND(ABS((double)local_54.y) * _DAT_0046fcb8 + _DAT_0046fcc0);
  local_4c.lfFaceName[0] = s__Arial_Bold_0046fcc7[1];
  local_4c.lfFaceName[1] = s__Arial_Bold_0046fcc7[2];
  local_4c.lfFaceName[2] = s__Arial_Bold_0046fcc7[3];
  local_4c.lfFaceName[3] = s__Arial_Bold_0046fcc7[4];
  local_4c.lfFaceName[4] = s__Arial_Bold_0046fcc7[5];
  local_4c.lfFaceName[5] = s__Arial_Bold_0046fcc7[6];
  local_4c.lfFaceName[6] = s__Arial_Bold_0046fcc7[7];
  local_4c.lfFaceName[7] = s__Arial_Bold_0046fcc7[8];
  local_4c.lfFaceName[8] = s__Arial_Bold_0046fcc7[9];
  local_4c.lfFaceName[9] = s__Arial_Bold_0046fcc7[10];
  local_4c.lfFaceName[10] = s__Arial_Bold_0046fcc7[0xb];
  h = CreateFontIndirectA(&local_4c);
  SetTextColor(local_58,((int)param_7 >> 8 & 0xffU) << 8 | (int)param_7 >> 0x10 & 0xffU |
                        (param_7 & 0xff) << 0x10);
  pvVar4 = SelectObject(local_58,h);
  iVar2 = -1;
  pCVar7 = lpString;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pCVar7;
    pCVar7 = pCVar7 + 1;
  } while (cVar1 != '\0');
  TextOutA(local_58,param_4,param_5,lpString,-2 - iVar2);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,lpString);
  pvVar4 = SelectObject(local_58,pvVar4);
  DeleteObject(pvVar4);
  RestoreDC(local_58,-1);
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 0x68))(piVar5,local_58);
  }
  return;
}


