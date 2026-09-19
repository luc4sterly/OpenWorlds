// 1002c940 RwRenderScene [Global]
// programa: RWL21.DLL

uint * RwRenderScene(uint *param_1)

{
  int *piVar1;
  bool bVar2;
  uint *puVar3;
  undefined3 extraout_var;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  int iVar4;
  int iVar5;
  int iStack_4;
  
                    /* 0x2c940  349  RwRenderScene */
  if (param_1[8] == 0) {
    return param_1;
  }
  rwupdateViewMatrix(*(int *)(PTR_DAT_1005b69c + 0x10));
  DAT_1005addc = *(int *)(PTR_DAT_1005b69c + 0x10);
  if (*(int *)(DAT_1005addc + 0x8c) == 2) {
    iVar4 = 0;
    puVar3 = FUN_1002be50((int)param_1,(uint *)param_1[1]);
    param_1[1] = (uint)puVar3;
    FUN_1002cf80(extraout_ECX,extraout_EDX,(int)param_1);
    if (0 < (int)param_1[7]) {
      iVar5 = 0;
      do {
        piVar1 = (int *)(param_1[3] + iVar5);
        if (*(int *)(*piVar1 + 0x44) != 1) {
          FUN_1000cba0(0x65);
          return (uint *)0x0;
        }
        iVar5 = iVar5 + 4;
        iVar4 = iVar4 + 1;
        FUN_10008000(*(float **)(*piVar1 + 0x48));
      } while (iVar4 < (int)param_1[7]);
    }
    return param_1;
  }
  bVar2 = FUN_1002d170(PTR_DAT_1005b69c,DAT_1005addc,param_1);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    return (uint *)0x0;
  }
  iVar4 = 0;
  FUN_1002cae0(extraout_ECX_00,extraout_EDX_00,(uint *)param_1[1]);
  iStack_4 = 0;
  if (param_1 != (uint *)0x0) {
    do {
      if ((int)param_1[7] <= iStack_4) break;
      puVar3 = *(uint **)(param_1[3] + iVar4);
      if ((*puVar3 & 0x20) == 0) {
        FUN_10041c20();
      }
      else {
        if ((*puVar3 & 0x40) != 0) {
          DAT_1005ade8 = (float *)(puVar3 + 1);
          FUN_10041c40((undefined4 *)puVar3[3]);
          FUN_10041b80(*(int *)(PTR_DAT_1005b69c + 0x10),DAT_1005ade8);
          FUN_1001ec00((undefined4 *)puVar3[3]);
          *puVar3 = *puVar3 & 0xffffff9f;
          FUN_10041c10();
        }
        *puVar3 = *puVar3 & 0xffffff7f;
      }
      if (puVar3[0x11] == 1) {
        FUN_10008000((float *)puVar3[0x12]);
      }
      else {
        FUN_1000cba0(0x65);
        param_1 = (uint *)0x0;
      }
      iVar4 = iVar4 + 4;
      iStack_4 = iStack_4 + 1;
    } while (param_1 != (uint *)0x0);
    if (param_1 != (uint *)0x0) {
      param_1[7] = 0;
    }
  }
  FUN_10041c20();
  return param_1;
}


