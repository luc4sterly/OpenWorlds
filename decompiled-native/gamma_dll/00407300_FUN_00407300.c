// 00407300 FUN_00407300 [Global]
// programa: gamma.dll

undefined4 * __thiscall
FUN_00407300(int *param_1,undefined4 *param_2,int *param_3,void *param_4,byte param_5,char param_6)

{
  void *this;
  undefined4 **ppuVar1;
  undefined4 *puVar2;
  LPCRITICAL_SECTION p_Var3;
  int *piVar4;
  bool bVar5;
  bool bStack_44;
  int *piStack_40;
  int aiStack_3c [2];
  undefined4 *puStack_34;
  undefined4 *puStack_30;
  undefined1 uStack_29;
  
  if ((*(ushort *)((int)param_4 + 0x30) & 1) != 0) {
    FUN_004049b0(param_4,aiStack_3c);
    uStack_29 = DAT_004890b6;
    this = (void *)FUN_00406190(aiStack_3c);
    FUN_00404dc0(aiStack_3c);
    bVar5 = param_6 == '\0';
    if (bVar5) {
      FUN_00407550(this,&puStack_30);
      ppuVar1 = &puStack_30;
    }
    else {
      FUN_00407530(this,&puStack_34);
      ppuVar1 = &puStack_34;
    }
    bStack_44 = !bVar5;
    FUN_00406490(&piStack_40,ppuVar1);
    if (bVar5) {
      p_Var3 = (LPCRITICAL_SECTION)(puStack_30 + 4);
      EnterCriticalSection(p_Var3);
      if (puStack_30[2] == 0) {
        puStack_30[2] = 1;
      }
      puStack_30[2] = puStack_30[2] + -1;
      puVar2 = puStack_30;
      if (puStack_30[2] != 0) {
        puVar2 = (undefined4 *)0x0;
      }
      LeaveCriticalSection(p_Var3);
      puStack_30 = puVar2;
      if (puVar2 != (undefined4 *)0x0) {
        FUN_0044e100((undefined4 *)puVar2[3]);
        DeleteCriticalSection((LPCRITICAL_SECTION)(puStack_30 + 4));
        FUN_0044e100(puStack_30);
      }
    }
    if (bStack_44) {
      p_Var3 = (LPCRITICAL_SECTION)(puStack_34 + 4);
      EnterCriticalSection(p_Var3);
      if (puStack_34[2] == 0) {
        puStack_34[2] = 1;
      }
      puStack_34[2] = puStack_34[2] + -1;
      puVar2 = puStack_34;
      if (puStack_34[2] != 0) {
        puVar2 = (undefined4 *)0x0;
      }
      LeaveCriticalSection(p_Var3);
      puStack_34 = puVar2;
      if (puVar2 != (undefined4 *)0x0) {
        FUN_0044e100((undefined4 *)puVar2[3]);
        DeleteCriticalSection((LPCRITICAL_SECTION)(puStack_34 + 4));
        FUN_0044e100(puStack_34);
      }
    }
    FUN_00403820(param_2,param_3,(int)param_4,param_5,(byte *)0x0,0,(byte *)piStack_40[3],
                 *piStack_40);
    EnterCriticalSection((LPCRITICAL_SECTION)(piStack_40 + 4));
    if (piStack_40[2] == 0) {
      piStack_40[2] = 1;
    }
    piStack_40[2] = piStack_40[2] + -1;
    piVar4 = piStack_40;
    if (piStack_40[2] != 0) {
      piVar4 = (int *)0x0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(piStack_40 + 4));
    if (piVar4 != (int *)0x0) {
      piStack_40 = piVar4;
      FUN_0044e100((undefined4 *)piVar4[3]);
      DeleteCriticalSection((LPCRITICAL_SECTION)(piVar4 + 4));
      FUN_0044e100(piStack_40);
    }
    return param_2;
  }
  (**(code **)(*param_1 + 8))(param_2,param_3,param_4,param_5,param_6);
  return param_2;
}


