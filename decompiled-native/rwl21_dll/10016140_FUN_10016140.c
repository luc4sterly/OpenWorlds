// 10016140 FUN_10016140 [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_10016140(FILE *param_1)

{
  int iVar1;
  undefined4 uVar2;
  float10 fVar3;
  float fVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  float fVar7;
  float local_20;
  undefined4 local_1c;
  undefined4 local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  iVar1 = FUN_10020800(param_1,s__f_f_f_f_1005aad8);
  if (iVar1 != 4) {
    FUN_1000cba0(5);
    return false;
  }
  local_4 = local_14;
  local_20 = local_10;
  local_1c = local_c;
  local_18 = local_8;
  fVar3 = rwLengthNormaliseVector(&local_20,&local_20);
  if ((float10)_DAT_10052110 < fVar3) {
    iVar1 = 2;
    fVar4 = local_20;
    uVar5 = local_1c;
    uVar6 = local_18;
    fVar7 = local_4;
    uVar2 = FUN_1001d710(DAT_1005dfd0);
    iVar1 = FUN_1001cac0(uVar2,fVar4,uVar5,uVar6,fVar7,iVar1);
    return (bool)('\x01' - (iVar1 == 0));
  }
  FUN_1000cba0(0x20);
  return false;
}


