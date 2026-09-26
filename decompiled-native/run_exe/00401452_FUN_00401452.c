// 00401452 FUN_00401452 [Global]
// programa: run.exe

undefined4 __cdecl FUN_00401452(PCNZWCH param_1,int param_2)

{
  PCNZWCH pWVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  LPCWSTR lpName;
  void *pvVar5;
  int *piVar6;
  bool bVar7;
  void *this;
  undefined *this_00;
  
  if (((param_1 == (PCNZWCH)0x0) ||
      (pWVar1 = (PCNZWCH)FUN_004039ae(param_1,0x3d), pWVar1 == (PCNZWCH)0x0)) || (param_1 == pWVar1)
     ) goto LAB_004014b5;
  bVar7 = pWVar1[1] == L'\0';
  if (DAT_0040ba68 == DAT_0040ba6c) {
    DAT_0040ba68 = FUN_00401641(DAT_0040ba68);
  }
  if (DAT_0040ba68 == (int *)0x0) {
    if ((param_2 == 0) || (DAT_0040ba60 == (undefined4 *)0x0)) {
      if (bVar7) goto LAB_004015de;
      if (DAT_0040ba60 == (undefined4 *)0x0) {
        DAT_0040ba60 = _malloc(4);
        if (DAT_0040ba60 == (undefined4 *)0x0) goto LAB_004014b5;
        *DAT_0040ba60 = 0;
        if (DAT_0040ba68 != (int *)0x0) goto LAB_004014f7;
      }
      DAT_0040ba68 = _malloc(4);
      if (DAT_0040ba68 != (int *)0x0) {
        *DAT_0040ba68 = 0;
        goto LAB_004014f7;
      }
    }
    else {
      iVar2 = FUN_00403946();
      if (iVar2 == 0) goto LAB_004014f7;
    }
LAB_004014b5:
    uVar3 = 0xffffffff;
  }
  else {
LAB_004014f7:
    piVar4 = DAT_0040ba68;
    pvVar5 = (void *)((int)pWVar1 - (int)param_1 >> 1);
    this = pvVar5;
    iVar2 = FUN_004015e5(param_1,(int)pvVar5);
    if ((iVar2 < 0) || (*piVar4 == 0)) {
      if (!bVar7) {
        if (iVar2 < 0) {
          iVar2 = -iVar2;
        }
        piVar4 = FUN_004036a6(this,piVar4,(uint *)(iVar2 * 4 + 8));
        if (piVar4 != (int *)0x0) {
          piVar4[iVar2] = (int)param_1;
          piVar4[iVar2 + 1] = 0;
          goto LAB_00401589;
        }
        goto LAB_004014b5;
      }
    }
    else {
      if (bVar7) {
        this_00 = (undefined *)piVar4[iVar2];
        piVar6 = piVar4 + iVar2;
        FUN_0040253a(this_00);
        for (; *piVar6 != 0; piVar6 = piVar6 + 1) {
          iVar2 = iVar2 + 1;
          *piVar6 = piVar6[1];
        }
        piVar4 = FUN_004036a6(this_00,piVar4,(uint *)(iVar2 << 2));
        if (piVar4 != (int *)0x0) {
LAB_00401589:
          DAT_0040ba68 = piVar4;
        }
      }
      else {
        piVar4[iVar2] = (int)param_1;
      }
      if (param_2 != 0) {
        iVar2 = FUN_00403689(param_1);
        lpName = _malloc(iVar2 * 2 + 4);
        if (lpName != (LPCWSTR)0x0) {
          FUN_00403664(lpName,param_1);
          lpName[(int)pvVar5] = L'\0';
          SetEnvironmentVariableW
                    (lpName,(LPCWSTR)(~-(uint)bVar7 & (uint)(lpName + (int)pvVar5 + 1)));
          FUN_0040253a((undefined *)lpName);
        }
      }
    }
LAB_004015de:
    uVar3 = 0;
  }
  return uVar3;
}


