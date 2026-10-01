// 10003830 RwAddPolygonToClump [Global]
// program: RWL21.DLL

int * RwAddPolygonToClump(uint param_1,int param_2,int *param_3)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  undefined3 extraout_var;
  int iVar4;
  
                    /* 0x3830  10  RwAddPolygonToClump */
  if ((param_1 == 0) || (param_3 == (int *)0x0)) {
    FUN_1000cba0(1);
    return (int *)0x0;
  }
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else if ((*(byte *)(param_1 + 0x188) & 4) != 0) goto LAB_100038d2;
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return (int *)0x0;
  }
  uVar2 = *(uint *)(param_1 + 0x188);
  if (param_1 == 0) {
    FUN_1000cba0(1);
    uVar2 = 0;
  }
  else if ((uVar2 & 0xfffffff8) == 0) {
    if (((uVar2 & 1) == 0) || ((uVar2 & 1) != 0)) {
      if (((uVar2 & 1) == 0) && ((uVar2 & 1) != 0)) {
        iVar4 = 0;
        goto LAB_100038b9;
      }
    }
    else {
      iVar4 = 1;
LAB_100038b9:
      FUN_1002c070(param_1,iVar4);
    }
    uVar2 = FUN_10033600(param_1,uVar2 | 4);
    *(uint *)(param_1 + 0x188) = uVar2;
    uVar2 = param_1;
  }
  else {
    FUN_1000cba0(0x30);
    uVar2 = 0;
  }
  if (uVar2 == 0) {
    return (int *)0x0;
  }
LAB_100038d2:
  piVar3 = FUN_10001220(param_2,*(int *)(param_1 + 0x88),param_3);
  if ((piVar3 != (int *)0x0) &&
     (bVar1 = FUN_10003660(param_1,piVar3), CONCAT31(extraout_var,bVar1) == 0)) {
    RwDestroyPolygon(piVar3);
    return (int *)0x0;
  }
  return piVar3;
}


