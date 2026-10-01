// 10020fa0 RwDestroyRaster [Global]
// program: RWL21.DLL

undefined4 RwDestroyRaster(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  
                    /* 0x20fa0  64  RwDestroyRaster */
  if (param_1[0xf] != 0) {
    FUN_1000cba0(0x43);
    return 0;
  }
  if (param_1 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  if ((param_1[0xd] != 0) && (param_1[0xe] != 0)) {
    (**(code **)(PTR_DAT_1005b69c + 0x358))(param_1[0xd]);
  }
  uVar1 = param_1[0x10];
  if ((uVar1 & 2) == 0) {
    if ((uVar1 & 4) != 0) goto LAB_10021022;
    iVar2 = param_1[6];
  }
  else {
    if (*(code **)(PTR_DAT_1005b69c + 0x274) != (code *)0x0) {
      (**(code **)(PTR_DAT_1005b69c + 0x274))(param_1);
      goto LAB_10021022;
    }
    if ((uVar1 & 4) != 0) goto LAB_10021022;
    iVar2 = param_1[6];
  }
  if (iVar2 != 0) {
    (**(code **)(PTR_DAT_1005b69c + 0x358))(iVar2);
  }
LAB_10021022:
  FUN_10037010(DAT_1005acdc,param_1);
  return 1;
}


