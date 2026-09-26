// 004017aa FUN_004017aa [Global]
// programa: run.exe

undefined4 __cdecl FUN_004017aa(uint *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  size_t sVar4;
  uint *lpName;
  byte *pbVar5;
  void *this;
  int *piVar6;
  bool bVar7;
  undefined *this_00;
  
  if (param_1 == (uint *)0x0) {
    return 0xffffffff;
  }
  puVar1 = (uint *)FUN_00403ad1((byte *)param_1,0x3d);
  if (puVar1 == (uint *)0x0) {
    return 0xffffffff;
  }
  if (param_1 == puVar1) {
    return 0xffffffff;
  }
  bVar7 = *(byte *)((int)puVar1 + 1) == 0;
  if (DAT_0040ba60 == DAT_0040ba64) {
    DAT_0040ba60 = FUN_00401989(DAT_0040ba60);
  }
  if (DAT_0040ba60 == (int *)0x0) {
    if ((param_2 == 0) || (DAT_0040ba68 == (undefined4 *)0x0)) {
      if (bVar7) {
        return 0;
      }
      DAT_0040ba60 = _malloc(4);
      if (DAT_0040ba60 == (int *)0x0) {
        return 0xffffffff;
      }
      *DAT_0040ba60 = 0;
      if (DAT_0040ba68 == (undefined4 *)0x0) {
        DAT_0040ba68 = _malloc(4);
        if (DAT_0040ba68 == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *DAT_0040ba68 = 0;
      }
    }
    else {
      iVar2 = FUN_00403a63();
      if (iVar2 != 0) {
        return 0xffffffff;
      }
    }
  }
  piVar3 = DAT_0040ba60;
  this = (void *)((int)puVar1 - (int)param_1);
  iVar2 = FUN_00401931((uchar *)param_1,(size_t)this);
  if ((iVar2 < 0) || (*piVar3 == 0)) {
    if (bVar7) {
      return 0;
    }
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    piVar3 = FUN_004036a6(this,piVar3,(uint *)(iVar2 * 4 + 8));
    if (piVar3 == (int *)0x0) {
      return 0xffffffff;
    }
    piVar3[iVar2] = (int)param_1;
    piVar3[iVar2 + 1] = 0;
  }
  else {
    if (!bVar7) {
      piVar3[iVar2] = (int)param_1;
      goto LAB_004018de;
    }
    this_00 = (undefined *)piVar3[iVar2];
    piVar6 = piVar3 + iVar2;
    FUN_0040253a(this_00);
    for (; *piVar6 != 0; piVar6 = piVar6 + 1) {
      iVar2 = iVar2 + 1;
      *piVar6 = piVar6[1];
    }
    piVar3 = FUN_004036a6(this_00,piVar3,(uint *)(iVar2 << 2));
    if (piVar3 == (int *)0x0) goto LAB_004018de;
  }
  DAT_0040ba60 = piVar3;
LAB_004018de:
  if (param_2 != 0) {
    sVar4 = _strlen((char *)param_1);
    lpName = _malloc(sVar4 + 2);
    if (lpName != (uint *)0x0) {
      FUN_004019f0(lpName,param_1);
      pbVar5 = (byte *)(((int)lpName - (int)param_1) + (int)puVar1);
      *pbVar5 = 0;
      SetEnvironmentVariableA((LPCSTR)lpName,(LPCSTR)(~-(uint)bVar7 & (uint)(pbVar5 + 1)));
      FUN_0040253a((undefined *)lpName);
    }
  }
  return 0;
}


