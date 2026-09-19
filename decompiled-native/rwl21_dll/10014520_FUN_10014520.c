// 10014520 FUN_10014520 [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_10014520(FILE *param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar1 = FUN_10020ad0(param_1,&local_14);
  if (iVar1 != 0) {
    iVar1 = FUN_10020ad0(param_1,&local_c);
    if (iVar1 != 0) {
      iVar2 = FUN_10020ad0(param_1,&local_18);
      if (iVar2 != 0) {
        if (*(int *)(DAT_1005dfcc + 0x58) != 0) {
          local_18 = (local_c + local_14 + local_18) * _DAT_10052124;
          local_14 = local_18;
          local_c = local_18;
        }
        local_10 = local_18;
        local_8 = local_c;
        local_4 = local_14;
        FUN_1001ba80();
        fVar3 = local_4;
        fVar4 = local_8;
        fVar5 = local_10;
        iVar1 = RwCurrentMaterial();
        iVar1 = RwSetMaterialDiffuseRGB(iVar1,(uint)fVar3,(uint)fVar4,(uint)fVar5);
        return (bool)('\x01' - (iVar1 == 0));
      }
      if (iVar1 != 0) goto LAB_1001460e;
    }
    local_10 = local_14;
    FUN_1001ba80();
    fVar3 = local_10;
    iVar1 = RwCurrentMaterial();
    iVar1 = RwSetMaterialDiffuse(iVar1,(uint)fVar3);
    return (bool)('\x01' - (iVar1 == 0));
  }
LAB_1001460e:
  FUN_1000cba0(5);
  return false;
}


