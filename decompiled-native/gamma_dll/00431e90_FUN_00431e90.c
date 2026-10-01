// 00431e90 FUN_00431e90 [Global]
// program: gamma.dll

void __thiscall FUN_00431e90(undefined4 *param_1,int param_2,int param_3,int *param_4,int *param_5)

{
  float fVar1;
  char cVar2;
  undefined *puVar3;
  float10 fVar4;
  undefined **ppuStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined **appuStack_48 [4];
  undefined **appuStack_38 [4];
  undefined **ppuStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  
  ppuStack_58 = &PTR_LAB_00473390;
  uStack_54 = 0;
  uStack_4c = 0;
  uStack_50 = 0;
  FUN_00428d70(appuStack_48,param_2,(int)&ppuStack_58);
  puVar3 = FUN_0042f9f0();
  fVar4 = FUN_004295e0((int)appuStack_48,(int)puVar3);
  fVar1 = (float)fVar4;
  ppuStack_58 = &PTR_LAB_00473390;
  appuStack_48[0] = &PTR_LAB_004732e8;
  puVar3 = FUN_0042f9f0();
  FUN_004295a0(appuStack_38,fVar1,(int)puVar3);
  FUN_00428d20(&ppuStack_28,param_2,(int)appuStack_38);
  appuStack_38[0] = &PTR_LAB_004732e8;
  ppuStack_28 = &PTR_LAB_00473390;
  cVar2 = (**(code **)*param_1)();
  if (cVar2 == '\0') {
    *(undefined1 *)(param_1 + 1) = 1;
    param_1[0x16] = uStack_24;
    param_1[0x17] = uStack_20;
    param_1[0x18] = uStack_1c;
    param_1[0x25] = fVar1;
    FUN_00428e20(param_1 + 0x19,param_3);
    param_1[0x1e] = *param_4;
    param_1[0x1f] = param_4[1];
  }
  param_1[3] = uStack_24;
  param_1[4] = uStack_20;
  param_1[5] = uStack_1c;
  param_1[6] = fVar1;
  FUN_00428e20(param_1 + 7,param_3);
  param_1[0xc] = *param_4;
  param_1[0xd] = param_4[1];
  FUN_004320d0((int)param_1);
  param_1[0x23] = 0;
  param_1[0x10] = param_1[0x1e];
  param_1[0x11] = param_1[0x1f];
  FUN_00427c50(&iStack_18,param_4,param_5);
  param_1[0x12] = iStack_18;
  param_1[0x13] = uStack_14;
  param_1[0x24] = param_1[0x25];
  return;
}


