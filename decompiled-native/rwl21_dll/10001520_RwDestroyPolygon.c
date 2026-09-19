// 10001520 RwDestroyPolygon [Global]
// programa: RWL21.DLL

undefined4 RwDestroyPolygon(int *param_1)

{
  uint uVar1;
  int iVar2;
  
                    /* 0x1520  63  RwDestroyPolygon */
  if (param_1 == (int *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  iVar2 = param_1[0xd];
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0xb8) != iVar2)) {
    uVar1 = RwGetClumpHints(iVar2);
    if ((uVar1 & 4) == 0) {
      iVar2 = RwAddHintToClump(param_1[0xd],4);
      if (iVar2 == 0) {
        return 0;
      }
    }
  }
  if ((int *)param_1[0xb] == param_1) {
    FUN_100035a0((int)param_1);
    FUN_10020cf0(*(int **)(*param_1 + 0x3c),(int)param_1);
  }
  RwDestroyMaterial((undefined4 *)*param_1);
  if (*(char *)((int)param_1 + 0x3a) != '\x03') {
    if (*(char *)((int)param_1 + 0x3a) != '\x04') {
      (**(code **)(PTR_DAT_1005b69c + 0x358))();
      return 1;
    }
    FUN_10037010(DAT_10058034,param_1);
    return 1;
  }
  FUN_10037010(DAT_10058030,param_1);
  return 1;
}


