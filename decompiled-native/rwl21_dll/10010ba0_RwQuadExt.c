// 10010ba0 RwQuadExt [Global]
// program: RWL21.DLL

bool RwQuadExt(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined2 param_5)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* 0x10ba0  316  RwQuadExt */
  local_10 = param_1;
  local_c = param_2;
  local_8 = param_3;
  local_4 = param_4;
  if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
    FUN_1000cba0(0x27);
    return false;
  }
  piVar1 = FUN_100037e0(**(uint **)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94),4,&local_10);
  if (piVar1 != (int *)0x0) {
    iVar2 = RwSetPolygonTag((int)piVar1,param_5);
    if (iVar2 == 0) {
      return false;
    }
    piVar3 = (int *)RwCurrentMaterial();
    puVar4 = RwSetPolygonMaterial(piVar1,piVar3);
    return (bool)('\x01' - (puVar4 == (undefined4 *)0x0));
  }
  return false;
}


