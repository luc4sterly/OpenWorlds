// 10032670 RwGetClumpVertexViewportPosition [Global]
// programa: RWL21.DLL

undefined4 RwGetClumpVertexViewportPosition(float *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar3;
  undefined4 *unaff_EBP;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *unaff_retaddr;
  int iVar6;
  undefined4 auStack_5c [6];
  float afStack_44 [16];
  int *piStack_4;
  
                    /* 0x32670  171  RwGetClumpVertexViewportPosition */
  if ((param_3 == 0) || (param_1 == (float *)0x0)) {
    FUN_1000cba0(1);
  }
  else {
    if ((0 < param_2) && (param_2 < *(int *)((int)param_1[0x22] + 8) + -7)) {
      iVar1 = FUN_10041c90((int)param_1[0x22],param_2);
      FUN_100046c0((int)param_1);
      rwupdateViewMatrix(param_3);
      FUN_1001c4f0((int)afStack_44);
      uVar3 = extraout_EDX;
      if (param_1[99] != 1.4013e-45) {
        FUN_10030b50(param_1);
        FUN_10030b90(param_1,param_3);
        uVar3 = extraout_EDX_00;
      }
      FUN_1001c440(param_3 + 0xbc,uVar3,param_1,param_3 + 0xbc,afStack_44);
      iVar6 = 1;
      puVar4 = (undefined4 *)(iVar1 + 0xc);
      puVar5 = auStack_5c;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      (**(code **)(PTR_DAT_1005b69c + 0x294))(iVar1,1,afStack_44,param_3);
      if (param_1[99] != 1.4013e-45) {
        FUN_10030b70(param_1);
      }
      iVar2 = *(int *)(iVar6 + 0x18) >> 0x10;
      iVar1 = *(int *)(iVar6 + 0x1c) >> 0x10;
      if ((((iVar2 < 0) || (iVar1 < 0)) || (*(int *)(param_3 + 0x5c) <= iVar2)) ||
         (((*(int *)(param_3 + 0x60) <= iVar1 ||
           (*(float *)(iVar6 + 0x14) < *(float *)(param_3 + 0x74))) ||
          (*(float *)(param_3 + 0x78) <= *(float *)(iVar6 + 0x14))))) {
        if (param_1 != (float *)0x0) {
          *param_1 = 0.0;
        }
      }
      else {
        if (param_1 != (float *)0x0) {
          *param_1 = 1.4013e-45;
        }
        if (piStack_4 != (int *)0x0) {
          *piStack_4 = iVar2;
        }
        if (unaff_retaddr != (int *)0x0) {
          *unaff_retaddr = iVar1;
        }
      }
      puVar4 = (undefined4 *)&stack0xffffff90;
      for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
        *unaff_EBP = *puVar4;
        puVar4 = puVar4 + 1;
        unaff_EBP = unaff_EBP + 1;
      }
      return 1;
    }
    FUN_1000cba0(0x19);
  }
  return 0;
}


