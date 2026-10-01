// 004491f0 FUN_004491f0 [Global]
// program: gamma.dll

undefined4 __thiscall FUN_004491f0(int *param_1,int *param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  bool bVar6;
  
  iVar4 = (**(code **)(*param_2 + 0x14))(param_2,param_3,param_4);
  if (iVar4 < 0) {
    return 0;
  }
  uVar2 = param_4[1];
  uVar1 = param_3[1];
  bVar6 = SBORROW4(uVar2,uVar1);
  iVar4 = uVar2 - uVar1;
  uVar3 = *param_4;
  if (uVar2 == uVar1) {
    uVar1 = *param_3;
    bVar6 = SBORROW4(uVar3,uVar1);
    iVar4 = uVar3 - uVar1;
    if (uVar1 <= uVar3) goto LAB_00449240;
  }
  if (bVar6 != iVar4 < 0) {
    return 0x80040228;
  }
LAB_00449240:
  if (param_1[6] == 0) {
    return 0;
  }
  uVar5 = (**(code **)(*param_1 + 0x100))(param_2,param_3,param_4);
  return uVar5;
}


