// 1001a100 RwSetMaterialGeometrySampling [Global]
// programa: RWL21.DLL

/* WARNING: Removing unreachable block (ram,0x1001a127) */

uint * RwSetMaterialGeometrySampling(uint *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
                    /* 0x1a100  419  RwSetMaterialGeometrySampling */
  if (param_1 == (uint *)0x0) {
    FUN_1000cba0(1);
  }
  else {
    uVar3 = (uint)((*param_1 & 1) != 0);
    switch(param_2) {
    case 1:
      break;
    case 2:
      uVar3 = uVar3 + 4;
      break;
    case 3:
      uVar3 = uVar3 + 8;
      break;
    case 4:
      if ((char)param_1[1] != -1) {
        uVar3 = uVar3 + 2;
      }
      if (param_1[0xd] == 0) {
        uVar3 = uVar3 + 0xc;
      }
      else {
        uVar3 = uVar3 + 0x14;
      }
      break;
    default:
      FUN_1000cba0(0x1b);
      return (uint *)0x0;
    }
    piVar1 = (int *)param_1[0xf];
    iVar4 = 0;
    *param_1 = uVar3;
    if (0 < *piVar1) {
      piVar5 = piVar1 + 2;
      do {
        iVar2 = *piVar5;
        if (*(int *)(iVar2 + 0x2c) == iVar2) {
          FUN_1001a1e0(iVar2);
        }
        piVar5 = piVar5 + 1;
        iVar4 = iVar4 + 1;
      } while (iVar4 < *piVar1);
      return param_1;
    }
  }
  return param_1;
}


