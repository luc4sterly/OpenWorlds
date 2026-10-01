// 10010690 RwPolygonExt [Global]
// program: RWL21.DLL

bool RwPolygonExt(int param_1,int *param_2,undefined2 param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  
                    /* 0x10690  306  RwPolygonExt */
  if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
    FUN_1000cba0(0x27);
    return false;
  }
  piVar1 = FUN_100037e0(**(uint **)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94),param_1,param_2);
  if (piVar1 != (int *)0x0) {
    iVar2 = RwSetPolygonTag((int)piVar1,param_3);
    if (iVar2 == 0) {
      return false;
    }
    piVar3 = (int *)RwCurrentMaterial();
    puVar4 = RwSetPolygonMaterial(piVar1,piVar3);
    return (bool)('\x01' - (puVar4 == (undefined4 *)0x0));
  }
  return false;
}


