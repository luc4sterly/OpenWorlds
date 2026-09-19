// 1000a840 FUN_1000a840 [Global]
// programa: RWDL6D21.DLL

undefined4 * FUN_1000a840(int *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int local_44 [9];
  undefined4 local_20;
  
  if (DAT_1007bb4c != 8) {
    puVar1 = FUN_10007a80(param_1,param_2,param_3);
    return puVar1;
  }
  if (((param_3 & 8) != 0) &&
     ((((param_1[1] != 0x18 || (param_1[5] != 0)) || (param_1[2] != 0xff0000)) ||
      ((param_1[3] != 0xff00 || (param_1[4] != 0xff)))))) {
    piVar3 = param_1;
    piVar4 = local_44;
    for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar4 = *piVar3;
      piVar3 = piVar3 + 1;
      piVar4 = piVar4 + 1;
    }
    local_44[2] = 0xff0000;
    local_44[3] = 0xff00;
    local_44[4] = 0xff;
    local_20 = 0x18;
    local_44[1] = 0x18;
    local_44[5] = 0;
    local_44[6] = 0;
    puVar1 = FUN_10007a80(param_1,local_44,param_3);
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar1 = (undefined4 *)FUN_10007160(local_44,param_2,param_3);
    if (local_44[6] != 0) {
      (**(code **)(DAT_1007bda8 + 0x358))(local_44[6]);
    }
    return puVar1;
  }
  puVar1 = (undefined4 *)FUN_10007160(param_1,param_2,param_3);
  return puVar1;
}


