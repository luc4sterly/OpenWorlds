// 1001b200 FUN_1001b200 [Global]
// programa: RWL21.DLL

uint * FUN_1001b200(uint *param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *param_1 = 0xc;
  if (param_1 == (uint *)0x0) {
    FUN_1000cba0(1);
  }
  else {
    param_1[0xd] = 0;
    RwSetMaterialGeometrySampling(param_1,4);
    if (param_1[0xd] != 0) {
      if (*(int *)(*(int *)(param_1[0xd] + 0x18) + 0x1c) == *(int *)(PTR_DAT_1005b69c + 700)) {
        *(byte *)(param_1 + 0xc) = (byte)param_1[0xc] | 8;
      }
      else {
        *(byte *)(param_1 + 0xc) = (byte)param_1[0xc] & 0xf7;
      }
    }
  }
  if (param_1 == (uint *)0x0) {
    FUN_1000cba0(1);
    FUN_1000cba0(1);
  }
  else {
    bVar1 = (byte)param_1[0xc] & 0xe8;
    *(byte *)(param_1 + 0xc) = bVar1;
    *(byte *)(param_1 + 0xc) = bVar1 | 1;
    *(byte *)(param_1 + 0xc) = (byte)param_1[0xc] & 0x3f;
  }
  RwSetMaterialSurface((int)param_1,0,0,0);
  if (param_1 == (uint *)0x0) {
    FUN_1000cba0(1);
  }
  else {
    *(undefined1 *)(param_1 + 1) = 0xff;
    uVar3 = *param_1;
    if (uVar3 < 0x40) {
      if (uVar3 < 4) {
        iVar2 = 1;
      }
      else if (uVar3 < 8) {
        iVar2 = 2;
      }
      else {
        iVar2 = 4 - (uint)(uVar3 < 0xc);
      }
    }
    else {
      FUN_1000cba0(0x67);
      iVar2 = 0;
    }
    RwSetMaterialGeometrySampling(param_1,iVar2);
  }
  if (param_1 == (uint *)0x0) {
    FUN_1000cba0(1);
    return (uint *)0x0;
  }
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  uVar3 = (**(code **)(PTR_DAT_1005b69c + 0x260))(&local_c);
  param_1[2] = uVar3;
  return param_1;
}


