// 100160c0 RwRotateJointTM [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool RwRotateJointTM(float param_1,undefined4 param_2,undefined4 param_3,float param_4)

{
  undefined4 uVar1;
  float10 fVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  float local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* 0x160c0  356  RwRotateJointTM */
  local_c = param_1;
  local_8 = param_2;
  local_4 = param_3;
  fVar2 = rwLengthNormaliseVector(&local_c,&local_c);
  if ((float10)_DAT_10052110 < fVar2) {
    iVar6 = 2;
    fVar3 = local_c;
    uVar4 = local_8;
    uVar5 = local_4;
    uVar1 = FUN_1001d710(DAT_1005dfd0);
    iVar6 = FUN_1001cac0(uVar1,fVar3,uVar4,uVar5,param_4,iVar6);
    return (bool)('\x01' - (iVar6 == 0));
  }
  FUN_1000cba0(0x20);
  return false;
}


