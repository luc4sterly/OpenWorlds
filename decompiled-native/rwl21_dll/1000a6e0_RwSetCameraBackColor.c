// 1000a6e0 RwSetCameraBackColor [Global]
// programa: RWL21.DLL

uint RwSetCameraBackColor(uint param_1,uint param_2,uint param_3,uint param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  longlong lVar4;
  uint uVar5;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  
                    /* 0xa6e0  366  RwSetCameraBackColor */
  if ((((0x80000000 < param_2) || (0x80000000 < param_3)) || (0x80000000 < param_4)) ||
     (((0x3f800000 < (int)param_2 || (0x3f800000 < (int)param_3)) || (0x3f800000 < (int)param_4))))
  {
    FUN_1000cba0(0xb);
    return 0;
  }
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  iVar2 = RwPushCurrentMaterial();
  if (iVar2 != 0) {
    lVar4 = __ftol();
    local_4 = (undefined1)lVar4;
    lVar4 = __ftol();
    local_3 = (undefined1)lVar4;
    lVar4 = __ftol();
    local_2 = (undefined1)lVar4;
    bVar1 = (**(code **)(PTR_DAT_1005b69c + 0x284))(&local_4);
    *(uint *)(param_1 + 0x9c) = (uint)bVar1;
    uVar5 = param_1;
    iVar2 = RwCurrentMaterial();
    RwSetMaterialColor(iVar2,uVar5,param_2,param_3);
    iVar2 = RwCurrentMaterial();
    *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(iVar2 + 8);
    RwPopCurrentMaterial();
    if (param_1 != 0) {
      puVar3 = (undefined4 *)(param_1 + 0x118);
      for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
      }
      if ((*(uint *)(param_1 + 0x228) & 1) != 0) {
        puVar3 = (undefined4 *)(param_1 + 0x198);
        for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
        }
      }
      RwDamageCameraViewport(param_1,0,0,*(int *)(param_1 + 0x5c),*(int *)(param_1 + 0x60));
      return param_1;
    }
    FUN_1000cba0(1);
    return 0;
  }
  return 0;
}


