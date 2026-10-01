// 10010920 RwTriangleExt [Global]
// program: RWL21.DLL

bool RwTriangleExt(int param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* 0x10920  520  RwTriangleExt */
  local_c = param_1;
  local_8 = param_2;
  local_4 = param_3;
  if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
    FUN_1000cba0(0x27);
    return false;
  }
  piVar1 = FUN_100037e0(**(uint **)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94),3,&local_c);
  if (piVar1 != (int *)0x0) {
    iVar2 = RwSetPolygonTag((int)piVar1,param_4);
    if (iVar2 == 0) {
      return false;
    }
    piVar3 = (int *)RwCurrentMaterial();
    puVar4 = RwSetPolygonMaterial(piVar1,piVar3);
    return (bool)('\x01' - (puVar4 == (undefined4 *)0x0));
  }
  return false;
}


