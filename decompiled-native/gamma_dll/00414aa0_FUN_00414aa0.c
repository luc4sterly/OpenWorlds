// 00414aa0 FUN_00414aa0 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00414aa0(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  bool bVar8;
  int in_stack_00000024;
  int *piVar9;
  undefined8 uVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  uint local_54;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  uVar1 = FUN_00419830(param_2);
  (**(code **)(*param_1 + 400))(param_1,param_3,DAT_00489480);
  (**(code **)(*param_1 + 0x1b4))(param_1,param_3,DAT_00489480,param_4);
  uVar2 = (**(code **)(*param_1 + 400))(param_1,param_3,DAT_00489478);
  bVar8 = (uVar2 & 2) != 0;
  if (((param_4 == 0) || (!bVar8)) && ((uVar2 & 1) == 0)) {
    return;
  }
  if (!bVar8) goto LAB_00414ead;
  iVar3 = (**(code **)(*param_1 + 0x17c))(param_1,uVar1,DAT_0049fcc8);
  iVar4 = (**(code **)(*param_1 + 0x17c))();
  if ((iVar3 == 0) && (iVar4 == 0)) {
    if ((in_stack_00000024 == 0) ||
       (iVar3 = (**(code **)(*param_1 + 0x17c))(param_1,param_3,DAT_00489474), fVar11 = DAT_0046fd2c
       , fVar12 = DAT_0046fd2c, fVar13 = DAT_0046fd2c, iVar3 == 0)) goto LAB_00414ead;
  }
  else {
    uVar7 = 0;
    uVar2 = 0;
    if (iVar3 != 0) {
      iVar5 = FUN_00403120(param_1,iVar3,s_getRGB_0046fd20,&DAT_0046fd1c);
      uVar2 = FUN_00414240(param_1,iVar3,iVar5);
    }
    if (iVar4 != 0) {
      iVar3 = FUN_00403120(param_1,iVar4,s_getRGB_0046fd20,&DAT_0046fd1c);
      uVar7 = FUN_00414240(param_1,iVar4,iVar3);
    }
    local_20 = 0;
    local_24 = 0;
    local_2c = 0;
    local_28 = 0;
    FUN_004192e0(param_4,&local_2c,&local_28,&local_24,&local_20);
    local_54 = local_20;
    if (uVar2 != uVar7) {
      local_54 = FUN_00417dc0(param_4);
    }
    if ((0 < (int)local_54) && ((int)local_54 < (int)local_20)) {
      FUN_00419cb0(param_4,local_2c,local_28,local_24,local_54);
      FUN_00418eb0(param_4,(float)((uVar2 & 0xff0000) >> 0x10) * _DAT_0046fd28,
                   (float)((uVar2 & 0xff00) >> 8) * _DAT_0046fd28,
                   (float)(uVar2 & 0xff) * _DAT_0046fd28);
      FUN_00419cb0(param_4,local_2c,local_28 + local_54,local_24,local_20 - local_54);
      FUN_00418eb0(param_4,(float)((uVar7 & 0xff0000) >> 0x10) * _DAT_0046fd28,
                   (float)((uVar7 & 0xff00) >> 8) * _DAT_0046fd28,
                   (float)(uVar7 & 0xff) * _DAT_0046fd28);
      FUN_00419cb0(param_4,local_2c,local_28,local_24,local_20);
      goto LAB_00414ead;
    }
    if ((int)local_20 <= (int)local_54) {
      FUN_00418eb0(param_4,(float)((uVar2 & 0xff0000) >> 0x10) * _DAT_0046fd28,
                   (float)((uVar2 & 0xff00) >> 8) * _DAT_0046fd28,
                   (float)(uVar2 & 0xff) * _DAT_0046fd28);
      goto LAB_00414ead;
    }
    fVar11 = (float)((uVar7 & 0xff0000) >> 0x10) * _DAT_0046fd28;
    fVar12 = (float)((uVar7 & 0xff00) >> 8) * _DAT_0046fd28;
    fVar13 = (float)(uVar7 & 0xff) * _DAT_0046fd28;
  }
  FUN_00418eb0(param_4,fVar11,fVar12,fVar13);
LAB_00414ead:
  iVar3 = (**(code **)(*param_1 + 0x17c))(param_1,uVar1,DAT_0049fa68);
  if ((((iVar3 != 0) && (iVar4 = FUN_00412cf0(param_1,iVar3), iVar4 != 0)) &&
      (iVar4 = FUN_00419450(iVar4), 0 < iVar4)) && (iVar3 = FUN_00412870(param_1,iVar3), iVar3 != 0)
     ) {
    FUN_00419260(param_4,&local_1c);
    FUN_00419c50(param_4,DAT_0046fd2c,DAT_0046fd2c,DAT_0046fd2c);
    uVar2 = (**(code **)(*param_1 + 400))();
    if ((uVar2 & 2) != 0) {
      FUN_00419b90(iVar3,param_4,0);
    }
    if ((uVar2 & 1) != 0) {
      FUN_004148f0(param_1,iVar3,param_3,param_4);
    }
    FUN_00419c50(param_4,local_1c,local_18,local_14);
  }
  iVar3 = FUN_00403120(param_1,uVar1,s_prerender_0046fd54,
                       s__LNET_worlds_scape_Camera_FFFF_V_0046fd30);
  FUN_00412800(param_1,uVar1,iVar3);
  iVar3 = (**(code **)(*param_1 + 0x3c))();
  if (iVar3 == 0) {
    iVar3 = 0;
    if ((in_stack_00000024 != 0) &&
       (iVar4 = (**(code **)(*param_1 + 400))(param_1,in_stack_00000024,DAT_0049fba4),
       iVar4 - 1U < 2)) {
      iVar3 = FUN_00412cf0(param_1,in_stack_00000024);
      if (iVar3 == 0) {
        FUN_00402800(s_nCamera_0046fbd0,0x1e5);
      }
      FUN_004188d0(iVar3);
    }
    uVar6 = (**(code **)(*param_1 + 0x17c))(param_1,uVar1,DAT_0049ff54);
    uVar6 = FUN_00412870(param_1,uVar6);
    uVar10 = CONCAT44(DAT_00489478,param_3);
    piVar9 = param_1;
    uVar2 = (**(code **)(*param_1 + 400))();
    if ((uVar2 & 2) != 0) {
      FUN_00419b90(uVar6,param_4,0);
    }
    if ((uVar2 & 1) != 0) {
      FUN_004148f0(param_1,uVar6,param_3,param_4);
    }
    uVar2 = (**(code **)(*param_1 + 400))(param_1,param_3,DAT_00489478,piVar9,uVar10);
    if ((uVar2 & 2) != 0) {
      FUN_00419b90(param_2,param_4,1);
    }
    if ((uVar2 & 1) != 0) {
      FUN_004148f0(param_1,param_2,param_3,param_4);
    }
    if (((bVar8) && (iVar4 = (**(code **)(*param_1 + 0x17c))(), iVar4 != 0)) &&
       ((iVar4 = (**(code **)(*param_1 + 400))(), iVar4 != 0 &&
        (iVar4 = FUN_004196d0(iVar4), iVar4 != 0)))) {
      FUN_00417c40(iVar4,param_4);
    }
    if (iVar3 != 0) {
      FUN_004188a0(iVar3);
    }
    iVar3 = FUN_00403120(param_1,uVar1,s_postrender_0046fd60,
                         s__LNET_worlds_scape_Camera_FFFF_V_0046fd30);
    FUN_00412800(param_1,uVar1,iVar3);
    iVar3 = (**(code **)(*param_1 + 0x3c))();
    if (iVar3 == 0) {
      (**(code **)(*param_1 + 0x1b4))();
      return;
    }
    return;
  }
  return;
}


