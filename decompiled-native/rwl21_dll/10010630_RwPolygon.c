// 10010630 RwPolygon [Global]
// programa: RWL21.DLL

bool RwPolygon(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  
                    /* 0x10630  305  RwPolygon */
  if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
    FUN_1000cba0(0x27);
    return false;
  }
  piVar1 = FUN_100037e0(**(uint **)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94),param_1,param_2);
  if (piVar1 != (int *)0x0) {
    piVar2 = (int *)RwCurrentMaterial();
    puVar3 = RwSetPolygonMaterial(piVar1,piVar2);
    return (bool)('\x01' - (puVar3 == (undefined4 *)0x0));
  }
  return false;
}


