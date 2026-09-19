// 1003e710 FUN_1003e710 [Global]
// programa: RWL21.DLL

undefined4 * FUN_1003e710(undefined4 *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = RwGetPolygonMaterial(param_1);
  piVar3 = (int *)(*param_2 + param_2[2] * 4);
  iVar4 = param_2[2];
  do {
    piVar3 = piVar3 + -1;
    if (iVar4 == 0) {
      uVar1 = param_2[1];
      if (uVar1 <= (uint)param_2[2]) {
        iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x354))(*param_2,uVar1 * 4 + 0xa0);
        if (iVar4 == 0) {
          return param_1;
        }
        *param_2 = iVar4;
        param_2[1] = uVar1 + 0x28;
      }
      *(int *)(*param_2 + param_2[2] * 4) = iVar2;
      param_2[2] = param_2[2] + 1;
      return param_1;
    }
    iVar4 = iVar4 + -1;
  } while (*piVar3 != iVar2);
  return param_1;
}


