// 100108a0 RwTriangle [Global]
// program: RWL21.DLL

bool RwTriangle(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* 0x108a0  519  RwTriangle */
  local_c = param_1;
  local_8 = param_2;
  local_4 = param_3;
  if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
    FUN_1000cba0(0x27);
    return false;
  }
  piVar1 = FUN_100037e0(**(uint **)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94),3,&local_c);
  if (piVar1 != (int *)0x0) {
    piVar2 = (int *)RwCurrentMaterial();
    puVar3 = RwSetPolygonMaterial(piVar1,piVar2);
    return (bool)('\x01' - (puVar3 == (undefined4 *)0x0));
  }
  return false;
}


